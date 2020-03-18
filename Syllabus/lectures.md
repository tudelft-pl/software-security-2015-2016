
# Lecture Plan

Many security problems in software systems are due to careless use of unsafe programming techniques. Preventing security problems should be an integral part of the software development process.

The course studies the nature of security vulnerabilities in software systems, techniques to detect and prevent these problems, and the embedding of these techniques in a security-aware software development process. 

## Objectives

The student will acquire:

* A good understanding of the nature of security vulnerabilities in software systems
* A good understanding of principles for secure software development
* A basic understanding of security testing and dynamic analysis techniques
* A good understanding of static analysis techniques and language-based security

## Lecture 1: Software Security Vulnerabilities

* buffer overflows
	- 
	- http://web.cecs.pdx.edu/~apt/cs491/proj1.pdf
* integer overflows

* SQL injection
* cross-site scripting (XSS)

* race conditions
* bad randomness
* information exposure

## Lecture 2: Principles of Secure Programming

* threat modeling
* defense in depth
* least privilege
* small/simple trusted computing base
* secure failures
* secure defaults
* attack surface and reducing it

* check lists and coding standards
* code reviews

* security middleware

## Lecture 3: Input Validation

* preventing injection attacks, XSS

## Lecture 4: Language-Based Security

* memory safety
* type safety
* access control

## Lecture 5: Modeling Language-Based Security

* static semantics
	* types
	* type checking
* dynamic semantics
* type soundness
* program verification
* proof-carrying code

## Lecture 6: Static Analysis

* static analysis techniques
* data flow analysis
* control flow analysis

## Lecture 7: Information Flow / Access Control

* least privilege

## Lecture 8: Security Testing

* security testing vs functional testing
* fuzz testing and other penetration techniques
* dynamic analysis techniques
* runtime monitoring


## Resources

* [https://www.owasp.org/index.php/Main\_Page][1]

[1]:	https://www.owasp.org/index.php/Main_Page