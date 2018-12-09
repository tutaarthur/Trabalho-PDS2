//
//  Residuo.cpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#include "Residuo.hpp"

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
void Residuo::setDescricao(std::string descricao) {
    this->descricao = descricao;
}
std::string Residuo::getDescricao() {
    return this->descricao;
}
std::string Residuo::getNome() {
    return this->nome;
}
void Residuo::setNome(std::string nome) {
    this->nome = nome;
}
Residuo::Residuo(std::string nome, int tipo, std::string descricao) {
    this->tipo = tipo;
    this->nome = nome;
    this->qntColeta = 0;
    this->descricao = descricao;
}
