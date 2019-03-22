# CMS: Cryptographic Message System
For this project I have been tasked with creating a Cryptographic Messaging System that is capable of encrypting and decrypting messages from a set of parameters contained within a file.

## Getting Started
Cryptographic Message System has been writen in C++ using Visual Studio 2017.

The CMS.exe uses the Users directory two test account are provided credentials are bellow

* jblogs
* password
* test
* qwerty123

## Current Known Bugs
* **If user types an incorrect Username or Password application will not log in.**
* Some XOR Encrypted messages cause first character of next line in console to be deleted.
* User can type in age value that includes character in some cinarios.
* Time input incorrect order of asking user (Currently SS, MM then HH should be HH first).
* Time input validation in some cinarios prints twice.

## License
This project is licensed under the MIT License - see the [LICENSE.md](docs/LICENSE.md) file for details

## Acknowledgments
* Sanya Tayal's answer on [Stack Overflow](https://stackoverflow.com/a/52168041).
* Roland Illig's post on [Stack Overflow: Code Review](https://codereview.stackexchange.com/questions/140341/simple-xor-file-encryption?fbclid=IwAR0iuulaGrBD-aOSc0o5eQsivvQsyt23xUN3U0bcQhpGJXbj-y-3sajcaME/).
* Toksinho repositery on [GitHub](https://github.com/toksinho/ROT13-ROT47_encoder_decoder/).
