# -*- MakeFile -*-

# target: dependencies
# 	action


affine_cipher: main.o affine_cipher.o
	g++ build/main.o build/affine_cipher.o -o build/main

main.o: main.cpp
	g++ -c main.cpp -o build/main.o

# Affine cipher
affine_cipher.o: ciphers/affine_cipher.cpp
	g++ -c ciphers/affine_cipher.cpp -o build/affine_cipher.o

