CC=g++
CFLAGS=-I.

build: STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o executable STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp

test: STR/test.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o testes STR/test.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	./testes

run: STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o executable STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	./executable
