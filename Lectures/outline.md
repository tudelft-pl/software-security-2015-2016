
# Software Security 2015-2016

## Lecture 1: What is Software Security? (Nov 11)

* Motivation: Many security problems in software systems are due to careless use of unsafe programming techniques. Preventing security problems should be an integral part of the software development process. The course studies the nature of security vulnerabilities in software systems, techniques to detect and prevent these problems, and the embedding of these techniques in a security-aware software development process. 

* What properties do we want to achieve?
- Confidentiality
- Integrity
- Availability

* How are these properties threatened?
- STRIDE
- vulnerabilities

* Principles of secure software design
- threat modeling
- defense in depth
- least privilege
- small/simple trusted computing base
- secure failures
- secure defaults
- attack surface and reducing it

* Prevention and detection techniques
- check lists and coding standards
- static analysis tools
- static analysis

- code reviews
- typing
- language-based security (or platform-based security)

- security middleware
- runtime monitoring
- program verification
- proof-carrying code

* Course objectives
- the nature of security vulnerabilities in software systems
- principles for secure software development
- security testing and dynamic analysis techniques
- static analysis techniques and language-based security

* Overview of the course
- lectures
- assignments
- exam

## Lecture 2: Memory-Based Attacks (Nov 18)

* Smashing The Stack For Fun And Profit
- http://phrack.org/issues/49/14.html#article

* Memory vulnerabilities and counter measures
- buffer overflows
	- http://web.cecs.pdx.edu/~apt/cs491/proj1.pdf
- integer overflows
- race conditions
- bad randomness
- information exposure


* Literature
- Chapter 7 in Building Secure Software by Viega & McGraw

## Lecture 3: Language-Based Security (Nov 25)

* Preventing memory-based attacks
- memory safety
- type safety
- static analysis

* Modeling Language-Based Security
- static semantics: types, type checking
- dynamic semantics
- type soundness
- program verification
- proof-carrying code

* Unsafe languages
- C/C++

* Safe languages
- Java: array bounds checking
- Rust
- Haskell
- …

* Java Security

* Static Analysis
- static analysis techniques
- data flow analysis
- control flow analysis

## Lecture 4: Vulnerabilities in Web Applications (Dec 2; Danny)

* Vulnerabilities of web applications
- SQL injection
- other injection attacks
- session hijacking
- cross-site request forgery
- cross-site scripting (XSS)

* Literature 
- Defining Injection Attacks
http://link.springer.com/chapter/10.1007/978-3-319-13257-0_26

## Lecture 5: Language-based Security for the Web (Dec 9; Danny & Mark)

* Danny Groenewegen
- security measures in WebDSL
* Mark Jansen
- access control 

## Lecture 6: (Information Flow and) Access Control (Dec 16)

* least privilege

- Define the basic access control concepts of subject, object, and access mode; give examples.
- Define the concept of mediation, and describe different ways of achieving it. 
- Define the concept of reference monitor.
- Explain hardware approaches to access control, including segments, paging, and tagging.
- Explain the concept of an access control matrix (ACM), show how ACMs can be used to model security policies, and how to use an ACM to determine whether an access is secure relative to a policy. 
- Explain the idea of an access control list (ACL) and its relationship to an ACM.
- Explain the concept of capabilities, and their relationship to an ACM. 
- Explain in detail what access control mechanisms are available in Unix. 
- Explain what Java stack inspection is used for, and how it works. Discuss its limitations.
- Explain and apply the Bell-LaPadula confidentiality model in the context of a multilevel security policy. 
- Explain the concept of covert channels, and give examples. 


It is also easy to find unprotected copies elsewhere on the web.
- Read: Yee, et al. “Native Client: a sandbox for portable untrusted x86 native code”, CACM 53(1), January 2010.
- Read: Li Gong, “Java Security architecture revisited”, CACM 54(11), Nov. 2011.
- Read: Enck, et al., “Understanding Android Security”, IEEE Security and Privacy, 7(1), Jan-Feg. 2009.
- Steve Zdancewic’s slides on access control. I covered slides 2-9 and 11-27. 


## Lecture 7: Security Testing (Jan 6)

* security testing vs functional testing
* symbolic execution
* fuzz testing and other penetration techniques
* dynamic analysis techniques
* runtime monitoring

## Resources

* [https://www.owasp.org/index.php/Main\_Page][1]

[1]:	https://www.owasp.org/index.php/Main_Page