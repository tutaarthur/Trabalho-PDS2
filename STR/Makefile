CC=g++
CFLAGS=-I.

build: STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o executable STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp

test: STR/test.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o testes -Weverything -std=c++11 STR/test.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	./testes

run: STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o executable STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	./executable

all:STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
	$(CC) -o executable STR/main.cpp STR/Usuario.cpp STR/Residuo.cpp STR/PontoDeColeta.cpp STR/Sistema.cpp STR/Coleta.cpp
