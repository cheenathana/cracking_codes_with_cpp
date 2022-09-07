# -*- MakeFile -*-

# Below is the rule
# target: dependencies
# 	action

GC = g++
RM = rm

all: bin

bin: build/main.o build/affine_cipher.o
	$(GC) -o $@ $^

build/main.o: main.cpp ciphers/cipher.h
	$(GC) -c $< -o $@

build/affine_cipher.o: ciphers/affine_cipher.cpp ciphers/cipher.h
	$(GC) -c $< -o $@

build/ctransposition_cipher.o: ciphers/ctransposition_cipher.cpp ciphers/cipher.h
	$(GC) -c $< -o $@

build/caesar_cipher.o: ciphers/caesar_cipher.cpp ciphers/cipher.h
	$(GC) -c $< -o $@

build/reverse_cipher.o: ciphers/reverse_cipher.cpp ciphers/cipher.h
	$(GC) -c $< -o $@

clean:
	$(RM) -f build/*.o
	$(RM) -f bin
