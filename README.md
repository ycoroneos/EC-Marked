EC-Marked
=========

"Basement breakers are fed from sorrow to those who share your hall" ~ec-discuss

This is a markov chain generator coupled with a python script that
retrieves messages from ec-discuss and stores them in a file. That file
is read by the generator

Alternatively, you can use your own text

The C++ runs fast but it bugs me that I used stl all over the place
(it's not ethical) so in the future I may improve it to adhere more
closely to pure C/C++ (leaning towards C) standards.

The python script uses imaplib and the structure/style is based off some
example I found on the internet that I basically gutted.

USAGE:
-run the python script and do what it says
-compile the C++ (I recommend with scons since there's already a build script there) and run it


<insert the correct information about licenses here because I don't want
to be sued>
