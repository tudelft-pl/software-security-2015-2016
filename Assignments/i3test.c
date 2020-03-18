#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
#define true 1;
#define false 0;


// note: not using a null terminator because we know the length and only use length-limited printf of standard functions
typedef struct{
    char *ptr;
    int bufsize;
    int refcount;
} buffer;

buffer *create(int size){
    buffer *buf = (buffer *)malloc(sizeof(buffer));
    buf->bufsize = size;
    buf->ptr = (char *)malloc(buf->bufsize);
    buf->refcount = 0;
    return buf;
}

char *get_text(buffer *buf){
    return buf->ptr;
}

buffer *set_text(buffer *buf, char *text){
    for(int i = 0; i < buf->bufsize; i++){
        buf->ptr[i] = text[i];
    }
    return buf;
}


// implement in language and generate


buffer *copy(buffer *src){
    buffer *dst = create(src->bufsize);
    for(int i = 0; i < dst->bufsize; i++){
        dst->ptr[i] = src->ptr[i];
    }
    return dst;
}

int equal(buffer *first, buffer *second){
    if(first->bufsize != second->bufsize){
        return false;
    }
    for(int i = 0; i < first->bufsize; i++){
        if(first->ptr[i] != second->ptr[i]){
            return false;
        }
    }
    return true;
}

buffer *add(buffer *first, buffer *second){
    int newsize = first->bufsize + second->bufsize;
    buffer *dst = create(newsize);
    int count = 0;
    for(int i = 0; i < first->bufsize; i++){
        dst->ptr[i] = first->ptr[i];
        count = i + 1;
    }
    for(int i = 0; i < newsize; i++){
        dst->ptr[i + count] = second->ptr[i];
    }
    return dst;
}



// library functions defined in C


// note: not using a null terminator so need to limit the length for printf
void print(buffer *buf){
    printf("%.*s", buf->bufsize, buf->ptr);
}

// print function for string constants with a null terminator
void print_text(char* text){
    printf("%s", text);
}

// array access function with dynamic check
char get_char(buffer *buf, int i){
    if(i < 0 || i >= buf-> bufsize){
        printf("ERROR index out of bounds, requested %i of size %i",i,buf->bufsize);
        exit(1);
    }
    return buf->ptr[i];
}

// reference counting and free-ing, requires keeping track of aliases and scopes
buffer *add_ref(buffer *buf){
    buf->refcount++;
    return buf;
}

void remove_ref(buffer *buf){
    buf->refcount--;
    if(buf->refcount == 0){
        free(buf->ptr);
        free(buf);
    }
    if(buf->refcount < 0){
        printf("ERROR refcount was already 0");
        exit(1);
    }
}


int main(int argc, const char * argv[]) {
    buffer *b1 = set_text(create(4),"123434524"); // everything after length 4 ignored
    buffer *b2 = copy(b1);
    set_text(b2, "qwerty");
    print_text("b1 value: ");
    print(b1);
    print_text("\nb2 value: ");
    print(b2);
    print_text("\nb1+b2: ");
    print(add(b1,b2));
    print_text("\n");
    if(equal(b1,b2)){ print_text("equal(b1,b2)\n"); } else { print_text("not equal(b1,b2)\n"); }
    if(equal(b1,b1)){ print_text("equal(b1,b1)\n"); } else { print_text("not equal(b1,b1)\n"); }
    if(equal(b1,add(b1,b1))){ print_text("equal(b1,add(b1,b1))\n"); } else { print_text("not equal(b1,add(b1,b1))\n"); }
    buffer *b3 = set_text(create(4),"1234");
    if(equal(b1,b3)){ print_text("equal(b1,b3)\n"); } else { print_text("not equal(b1,b3)\n"); }
    printf("%c", get_char(b1,3));
    //printf("%c", get_char(b1,4));
    remove_ref(add_ref(add_ref(b1)));
    print(b1);
    return 0;
}
