# To add program to /etc/pkg?
Create a folder in /etc/pkg with the name of your package.
Then create file foo(replace name with name of you package).config
Look at the example of .config:

pkgname: foo
author: foobardev
url: https://github.com/foobar/foo
version: 1.0.0
tarballurl: https://github.com/Anatoliy6463/ande-repo/raw/main/foo.tar.xz
license: Foobar free license
year: 2024
wheretoextract: /usr/local/bin/
dependencies: bar
requiredby: foobar

tarball(.tar.xz archive) must contain binaries of your program, url mist be a link for a github repo(or a website of program).
You must fork Anatoliy6463/ande-repo and add tarball of your program, if your program is proprietary, pull request will be declined.
If there is no dependencies, type 'none'
If there is no programs which has your program in dependencies(requiredby section), type 'none'

List of licenses, which we will 100% accept:
GNU GPL v3
GNU GPL v2
GNU LGPL v2.1
GNU LGPL v3.0
GNU AGPL v3.0
GNU FDL 1.3(Documentation, like man pages)
MPL 2.0
All BSD Licenses
Apache License 2.0
X11 License(which is oftenly called MIT License)
Expat License(also MIT License)
Extralib Free License
Unlicense, CC0, BSD0 License, WTFPL and other public domain license

List of licenses, that we might not accept:
MPL 1.1
CDDL
LaTeX License
BSD 4-Clause

List of licenses, that we will 100% NOT accept:
No License
JSON License
NASA Open Source License
Microsoft Licenses
And other proprietary licenses...

How to check if license is free?
Free License give you 4 freedoms:
The freedom to run the program as you wish, for any purpose (freedom 0).
The freedom to study how the program works, and change it so it does your computing as you wish (freedom 1). Access to the source code is a precondition for this.
The freedom to redistribute copies so you can help others (freedom 2).
The freedom to distribute copies of your modified versions to others (freedom 3). By doing this you can give the whole community a chance to benefit from your changes. Access to the source code is a precondition for this.
## !!!THINK ABOUT FREE AS IN 'FREE SPEECH', NOT AS IN 'FREE BEER'!!!
