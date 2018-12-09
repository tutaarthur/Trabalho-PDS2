//
//  Residuo.cpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#include "Residuo.hpp"

Usuario* Residuo::getDono() {
    return this->dono;
}
int Residuo::getTipo() {
    return this->tipo;
}
int Residuo::getQntColeta() {
    return this->qntColeta;
}
void Residuo::addColeta() {
    this->qntColeta++;
}
void Residuo::removeColeta() {
    if (this->qntColeta > 0)
        this->qntColeta--;
}
void Residuo::setTipo(int tipo) {
    this->tipo = tipo;
}
std::string Residuo::getNome() {
    return this->nome;
}
void Residuo::setNome(std::string nome) {
    this->nome = nome;
}
void Residuo::setDono(Usuario* dono) {
    this->dono = dono;
}
Residuo::Residuo(std::string nome, int tipo, Usuario* dono) {
    this->tipo = tipo;
    this->nome = nome;
    this->dono = dono;
    this->qntColeta = 0;
}

