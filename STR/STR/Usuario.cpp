//
//  Usuario.cpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#include "Usuario.hpp"

std::string Usuario::getNome() {
    return this->nome;
}

std::string Usuario::getEndereco() {
    return this->endereco;
}
void Usuario::addColeta() {
    this->qntColetas++;
}
void Usuario::removeColeta() {
    if(this->qntColetas > 0)
        this->qntColetas --;
}
int Usuario::getQntColetas() {
    return this->qntColetas;
}
int Usuario::getTipo(){
    return this->tipo;
}

void Usuario::setNome(std::string nome) {
    this->nome = nome;
}
void Usuario::setEndereco(std::string endereco) {
    this->endereco = endereco;
}

void Usuario::setTipo(int tipo){
    if (tipo == 1 || tipo == 2)
        this->tipo = tipo;
    else
        throw std::invalid_argument("Tipo Invalido");
}
Usuario::~Usuario(){
    
}
Usuario::Usuario(std::string nome, std::string endereco, int tipo){
    this->nome = nome;
    this->endereco = endereco;
    this->qntColetas = 0;
    if (tipo == 1 || tipo == 2)
        this->tipo = tipo;
    else
        throw std::invalid_argument("Tipo Invalido");
}
