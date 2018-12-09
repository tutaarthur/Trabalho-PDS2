//
//  Coleta.cpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#include "Coleta.hpp"
#include "Usuario.hpp"
#include <string>
#include <iostream>

Coleta::Coleta(std::string data, Usuario *receptor, Usuario *doador, PontoDeColeta *ponto, std::vector<Residuo**> residuos){
    this->data = data;
    this->receptor = receptor;
    this->doador = doador;
    this->ponto = ponto;
    for (int i=0; i<residuos.size(); i++) {
        (*residuos[i])->addColeta();
        this->residuos.push_back(residuos[i]);
    }
}
bool Coleta::getColetado() {
    return this->coletado;
}
void Coleta::setColeta(bool coletado) {
    this->coletado = coletado;
}
void Coleta::setDoador(Usuario *doador) {
    this->doador = doador;
}
void Coleta::setReceptor(Usuario *receptor) {
    this->receptor = receptor;
}
void Coleta::setData(std::string data) {
    this->data = data;
}
std::string Coleta::getData() {
    return this->data;
}
Usuario* Coleta::getRecetor() {
    return this->receptor;
}
Usuario* Coleta::getDoador() {
    return this->doador;
}
PontoDeColeta* Coleta::getPonto() {
    return this->ponto;
}
Coleta::~Coleta(){
    this->residuos.clear();
}
