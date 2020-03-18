Assignment Description
----

For this assignment we are using the Buffer-Overflow Vulnerability Lab from the SEED Project:

http://www.cis.syr.edu/~wedu/seed/Labs_12.04/Software/Buffer_Overflow/

Assignment text:

http://www.cis.syr.edu/~wedu/seed/Labs_12.04/Software/Buffer_Overflow/Buffer_Overflow.pdf

The assignment will be performed in a virtual machine running Ubuntu, using VirtualBox. The disk image (SEEDUbuntu12.04.zip) can be downloaded from:

http://www.cis.syr.edu/~wedu/seed/lab_env.html

Extract the disk image, start VirtualBox, click New, 

name: cs4105 (or something else)
type: Linux
Version: Ubuntu (32-bit)

Memory Size: 1024 MB

Use an existing virtual hard disk file, choose SEEDUbuntu12.04.vmdk (don't choose the vmdk files ending with a number)

After starting the VM, log in with username "seed" and password "dees". The password for the root user is "seedubuntu".

Additional installation notes:

http://www.cis.syr.edu/~wedu/seed/Documentation/VirtualBox/UseVirtualBox.pdf
http://www.cis.syr.edu/~wedu/seed/Documentation/Ubuntu12_04_VM/Ubuntu12_04_VM_Manual.pdf

Debugging Tips
----

Compile with -g option if you want to debug an executable with gdb, ddd (apt-get install ddd), or other debugger.

Example gdb usage:
gdb myprogram
break 5         (breakpoint on line 5, assuming a single source file)
run
print varname   (print value of varname)
print &varname  (print address of varname)

Submission
----

The report PDF needs to include the following:

Task 1: Exploiting the Vulnerability

- The code added to exploit.c with an explanation of what it is doing and most importantly, why.

Task 2: Address Randomization

- Describe your observation and explain what happens when address randomization is enabled. Describe any modifications you make to the exploit program.

Task 3: Stack Guard

- Describe your observation and explain what happens when stack guard is enabled.

Task 4 is not required for this assignment.

Deadline
----

The assignment report must be uploaded as PDF in Weblab for submission. Deadline for this assignment is tba.
