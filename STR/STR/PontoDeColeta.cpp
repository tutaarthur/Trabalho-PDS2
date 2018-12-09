//
//  PontoDeColeta.cpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#include "PontoDeColeta.hpp"


void PontoDeColeta::addColeta() {
    this->qntColetas++;
}
void PontoDeColeta::removeColeta() {
    if(this->qntColetas > 0)
        this->qntColetas--;
}
int PontoDeColeta::getQntColetas() {
    return this->qntColetas;
}
std::string PontoDeColeta::getEndereco() {
    return this->endereco;
}
void PontoDeColeta::setEndereco(std::string endereco){
    this->endereco = endereco;
}
PontoDeColeta::PontoDeColeta(std::string endereco) {
    this->qntColetas = 0;
    this->endereco = endereco;
}
PontoDeColeta::~PontoDeColeta() {
    
}
