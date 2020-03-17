## Lecture 1: What is Software Security? (Nov 11)

# Course Motivation

Many security problems in software systems are due to careless use of unsafe programming techniques. Preventing security problems should be an integral part of the software development process. The course studies the nature of security vulnerabilities in software systems, techniques to detect and prevent these problems, and the embedding of these techniques in a security-aware software development process. 

integrate design into this motivation

# Course objectives

- security requirements

- the nature of security vulnerabilities in software systems
- principles for secure software development
- security testing and dynamic analysis techniques
- static analysis techniques and language-based security

# Overview of the course

* Lectures
- Lecture 1: What is Software Security? (Nov 11)
- Lecture 2: Memory-Based Attacks (Nov 18)
- Lecture 3: Language-Based Security (Nov 25)
- Lecture 4: Vulnerabilities in Web Applications (Dec 2)
- Lecture 5: Language-based Security for the Web (Dec 9)
- Lecture 6: Information Flow and Access Control (Dec 16)
- Lecture 7: Security Testing (Jan 6)

* Assignments
- applying software security understanding in practice
- A1: threat model: describe the functional design of a software system and its security risks (threat model) 
- A2: buffer overflows: 
- A3: web security techniques: examine security vulnerabilities _and_ counter measures in web programming
- A4: safety by construction: implement a translation from a high-level language to a low-level language that ensures safety properties
- A5: security policies: formulate a security design, including authentication, authorization, and audit policies, and argue why your design is safe

* Exam
- January 27, 2016
- understanding: what is what in software security
- grading scheme

* WebLab Learning Management System
- also running example
- learning management system

# Literature

Recommended books for this course

#### Analyzing Computer Security: A Threat / Vulnerability / Countermeasure Approach
* by Charles P. Pfleeger & Shari Lawrence Pfleeger 
* Prentice-Hall, 2012
* http://www.amazon.com/Analyzing-Computer-Security-Vulnerability-Countermeasure-ebook/dp/B005HXABSG/ref=mt_kindle?_encoding=UTF8&me=

#### Thread Modeling: Designing for Security
* by Adam Shostack
* Wiley, 2014
* http://eu.wiley.com/WileyCDA/WileyTitle/productCd-1118809998.html

#### Building Secure Software 
* Viega & McGraw 
* 2001

# Reading

#### Security Blanket or Security Theater?
* Chapter 1 of Pfleeger & Pfleeger
* general terminology

#### Knock, Knock. Who’s There?
* Chapter 2 of Pfleeger & Pfleeger
* on authentication

#### The Protection of Information in Computer Systems 
* by Jerome H. Saltzer & Michael D. Schroeder 
* http://web.mit.edu/Saltzer/www/publications/protection/

# What is Software Security?

* Ask class

* Software security discourse is often about when it goes wrong
- famous attacks or vulnerabilities
- Heart bleed, Shell shock, Sony breach, etc.
- but why are these a problem?

* Software engineering
- Software engineering is the study and an application of engineering to the design, development and maintenance of software.
building software that correctly implements requirements
- functional requirements
	- correct according to specification
	- what it should do
	- what it should store
- non-functional requirements
	- performance
	- resource usage
	- reliability
	- scalability
	- robustness
- process: to ensure requirements are met
	- requirements elicitation
	- design
	- implementation
	- testing
	- deployment

* WebLab
- domain model
- functional requirements (flow diagram)
	- view, edit assignments
	- compute grades
	- execute student programs
	- design course
	- navigate course
- non-functional requirements
	- response time

* What role does security play in the design of WebLab?

# Software Security Engineering

* Software security is subset of reliability
- problem: security is invisible
- security is not a feature
- security is preventing bad things from happening (= reliability)
- cannot observe security
- we don’t want certain things to happen; security is the absence of certain behavior
- that can be a problem to motivate spending money on security before anything has happened
- “The objective of a secure system is to prevent all unauthorized use of information, a negative kind of requirement. It is hard to prove that this negative requirement has been achieved, for one must demonstrate that every possible threat has been anticipated.” Saltzer & Schroeder

* Understanding software security
- what is the goal of software security?
- how can we ensure software security?
- how can we integrate security in the software engineering process?

# Security Requirements

* What is software security about?

* Assets
- “The term “security” describes techniques that control who may use or modify the computer or the information contained in it.“ Saltzer & Schroeder
- “Computer security is the protection of items you value, called the assets of a computer or computer system” Pfleeger & Pfleeger
- To determine what to protect, we must first identify what has value and to whom
- WebLab assets (write down a list):
	- assignments: lab assignments, exam assignments
	- reference solutions to assignments (model answers)
	- student submissions to assignments
	- student grades
	- account data, especially passwords

* What security properties should a software system have?
- Confidentiality
- Integrity
- Availability

* Confidentiality 
- the ability of a system to ensure that an asset is viewed only by authorized parties
- sensitive information is not leaked to unauthorized parties
- privacy for individuals, confidentiality for data
- examples
	- confidentiality: exam assignments should not be be published (at least until the exam is over)
 	- privacy: grades should only be visible to instructor and student involved

* Anonymity
- specific kind of privacy
- example
	- find out what kind of courses are available without being tracked by job advertisers 

* Integrity
- the ability of a system to ensure that an asset is modified only by authorized parties 
- sensitive information is not damaged by unauthorized parties
- examples:
	- submissions are not edited by anyone other than student
	- submissions are not edited by anyone after the deadline
	- grades are determined only by instructor or auto-grader
	- assignments, submissions, grades are not removed / only by instructor

* Availability
- the ability of a system to ensure that an asset can be used by any authorized parties
- a system is responsive to requests
- denial of service (DoS) attack: make system unavailable by keeping it busy or removing it from network
- example:
	- should respond to each request in reasonable time

* Nonrepudiation or accountability
- the ability of a system to confirm that a sender cannot convincingly deny having sent something
- note: opposite of privacy/anonymity; requires a balance

# Security Mechanisms

* Security Mechanisms
- provided by a system to enforce its requirements
- Authentication
- Authorization
- Audit
- Leslie Lamport’s ‘gold’ standard (au prefix)

* Authentication
- “verify the identity of a person (or other external agent) making a request of a computer system”
- the ability of a system to confirm the identity of a sender
- determine subject of security policy
- principal: an entity that can be authenticated
- authentication factors:
	- something the user knows; password
	- something the user has; smart phone, card
	- something the user is; fingerprint 
- multi-factor authentication uses several of these

* Authorization
- defines when a principal may perform an action
- examples
	- WebLab roles
	- manager may edit assignments
	- grader can view and grade submissions
	- student can edit own submissions
	- student can view exam assignments when signed into the exam and the exam has started (and not ended)


* Auditing
- the ability of a system to trace all actions related to a given asset
- retain enough information to be able to determine the circumstances of a breach or misbehavior (or establish one did not occur)
- such information, often stored in log files, must be protected from tampering, and from access that might violate other policies

# Threat Modeling / Architectural Risk Analysis

* Threats
- How are these security properties / requirements threatened?
- what can attackers do that violate these properties?
- how do these threats violate security requirements

* Trust boundaries
- who controls what?
- data-flow diagram
- boxes around components indicate trust boundaries
- example: trust boundaries for WebLab

* Abuse Cases 
- opposite of use cases
- illustrate security requirements
- identify things system should _not_ do
- example use case
	- student logs in and edits submission before the deadline
- example abuse case
	- student can edit submission after the deadline
	- student can change own grade
	- student can execute program that modifies/destroys database

* Finding threats
- how to identify threats for you system?
- STRIDE
	- Kohnfelder & Garg (1999)
	- taxonomy of threats
- Attack trees
- Attack libraries
- STRIDE
	- Spoofing
	- Tampering
	- Repudiation
	- Information disclosure
	- Denial of service
	- Elevation of privilege 

* Spoofing
- violates: authentication
- definition: pretending to be something or someone other than yourself
- victims: processes, external entities, people
- abuse case: pretending to be course manager

* Tampering
- violates: integrity
- definition: modifying something on disk, on a network, or in memory
- victims: data stores, data flows, processes
- example: changing grade for a submission

* Repudiation
- violates: non-repudiation
- definition: claiming that you didn’t do something, or were not responsible
- victims: process
- example: student claiming that they did not copy solution

* Information disclosure
- violates: confidentiality
- definition: providing information to someone not authorized to see it
- victims: processes, data stores, data flows
- example: publishing answer to assignment

* Denial of service
- violates: availability
- absorbing resources needed to provide service
- targets: processes, data stores, data flows
- example: 

* Elevation of privilege 
- Allowing someone to do something they’re not authorized to do


* Harm
- Interception
- Interruption
- Modification
- Fabrication

* Manifestation in software
- implementation bugs: vulnerabilities 
- design flaws: holes in application logic

# Principles of Secure Software Design

* Literature
- Saltzer & Schroeder
http://emergentchaos.com/the-security-principles-of-saltzer-and-schroeder
- Chapter 5 in Viega & McGraw: Guiding Principles for Software Security

* Categories
- Prevention: eliminate software defects entirely
- Mitigation: reduce harm from exploitation of unknown defects
- Detection and recovery: identify and understand an attack and undo damage

* Design Principles (Saltzer & Schroeder)
- Economy of mechanism
- Fail-safe defaults
- Complete mediation
- Open design
- Separation of privilege
- Least privilege
- Least common mechanism
- Psychological acceptability
- Work factor
- Compromise recording

- Defense in depth

* Economy of mechanism 
- category: prevention
- small and simple design is easier to review

* Fail-safe defaults
- category: prevention
- the default situation is lack of access 
- protection scheme identifies conditions under which access is permitted
- alternative: mechanisms attempt to identify conditions under which access should be refused => easy to miss cases
- example
	- whitelisting vs blacklisting
	- no default access to course
	- new assignment is unpublished
	- grades are hidden
	- etc.

* Complete mediation

* Open design

* Separation of privilege
- separated keys apply to any situation in which two or more conditions must be met before access should be permitted

* Least common mechanism

* Psychological acceptability
- human interface be designed for ease of use
- do not expect expert users

* Work factor
- make it expensive (a lot of work) to circumvent mechanism
- example: guessing password

* Compromise recording 
- monitor and trace

- Defense in depth

# Prevention and Detection Techniques

- threat modeling

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

