# backpack_cipher
It is a toy-project for learning algorythms with public key.

#run
Program use stdout for main output and stderr for error output.
Use command promt like this:
$ backpack_cipher.exe [key] [input_filename] [public/private key] optional >log.txt 2>&1 // redirect stdout and stderr in file log.txt

#notes

key:

[-e] // encrypt file
[-d] // decrypt file
[-g] // generate public and private keys

input_filename:

any file like [name].txt // file must be in the same directory where program is called

public/private key:
format num1,num2,...,num8,N,c