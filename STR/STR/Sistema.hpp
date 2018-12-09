//
//  Sistema.hpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#ifndef Sistema_hpp
#define Sistema_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Coleta.hpp"
#include "Residuo.hpp"
#include "PontoDeColeta.hpp"
#include "Usuario.hpp"

void iniciaSistema();
void adicionaUsuario(std::string nome, std::string endereco, int tipo);
void listarUsuarios();
void atualizaUsuario(int index, std::string nome, std::string endereco, int tipo);
void deletaUsuario(int index);
void adicionaPontoColeta(std::string endereco);
void listaPontoColeta();
void atualizaPontoColeta(int index, std::string endereco);
void deletaPontoColeta(int index);
void adicionaResiduo(std::string nome, int tipo, std::string descricao);
void listaResiduo();
void atualizaResiduo(int index, std::string nome, int tipo, std::string descricao);
void deletaResiduo(int index);
void adicionaColeta(std::string data, int indexReceptor, int indexDoador, int indexPonto, std::vector<Residuo**> residuos);
void listaColetas();
void informaColetaEfetuada(int index);

Usuario* getUserByIndex(int index);
PontoDeColeta* getPontoColetaByIndex(int index);
Residuo* getResiduoByIndex(int index);
Coleta* getColetaByIndex(int index);

#endif /* Sistema_hpp */
