### Assignment Description

In this assignment you are going to review the security features of a web programming language and framework of your choice. How hard is it to construct a safe application in the chosen platform? The method we are going to use is comparing two versions of a simple application that is written in a correct way and an incorrect way. The correct way uses the recommendations for writing secure applications, and the incorrect way tries to intentionally introduce security vulnerabilities.

For this assignment you will need to create 2 versions of a simple chat application in a web programming language and framework of your choice. The 2 versions are a safe version and an unsafe version with vulnerabilities. The minimal functional requirements for the application are:

- user creation form with name and password, password must be hashed
- user login form
- post message form, the message can use Markdown
- show messages in a list, include the author username, messages render the Markdown
- an admin page that can remove all current messages or make them invisible, the first user that signs up is the admin

### Example Application

An example of this application will be discussed in the lecture on December 9. You do not have to make an exact copy of the example.

### Unsafe Application Vulnerabilities

The second version is the unsafe version with security vulnerabilities. If a certain vulnerability is hard to introduce because your chosen web framework has good automatic protection, then explain that in your report.

The intentional bugs and design flaws of the unsafe version are:

General:

* Store password plaintext.

Request Tampering:

* Make the user creation form vulnerable to request tampering, that allows a user to be created with admin privileges by changing the submitted form data.

SQL Injection:

* Don't escape special characters in the username in a query used for login check.
* Reflect result of SQL query in the login error message.

XSS:

* Make the display of usernames vulnerable to cross-site scripting.
* Make the Markdown output used in messages vulnerable to cross-site scripting.

CSRF:

* Make the post message form submission vulnerable to cross-site request forgery.

### Assignment Report

The assignment report needs to include the following:

An overview of the implemented application:

* What language and framework did you choose?
* Did you already have experience with the chosen platform?
* Did you need any additional libraries?
* Give an estimate of the needed time for implementation of the two versions (including reading instructions and manuals)
* Host the safe version on a public URL, or provide another easy way to try it out (e.g. a Vagrant script that sets up a VM).

Framework and Vulnerability Analysis:

* What countermeasures does the framework use to prevent the vulnerabilities.
* For each vulnerability in the list, explain how it was created in the unsafe version.
* How can these vulnerabilities be exploited?
* Compare the safe and unsafe version, judge for each vulnerability whether the framework sufficiently assists in creating a safe application. For example, is it easy to accidentally introduce a vulnerability because it's close to writing it in the correct way.

Source Code:

* Add a link to the source code of the 2 versions of the application (can be a github/bitbucket repo, but also a private link to a zipfile on Dropbox or Google Docs is ok).
