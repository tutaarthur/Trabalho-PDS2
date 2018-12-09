//
//  test.cpp
//  STR
//
//  Created by Arthur Faria on 10/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdio.h>
#include "doctest.h"
#include "Sistema.hpp"
#include <vector>




TEST_CASE("Testando Adicao De Usuarios") {
    CHECK_NOTHROW(adicionaUsuario("", "", 1));
    CHECK_NOTHROW(adicionaUsuario("", "", 2));
    CHECK_THROWS(adicionaUsuario("", "", 3));
    CHECK_THROWS(adicionaUsuario("", "", -1));
}

TEST_CASE("Testando Alteracao De Usuarios") {
    CHECK_NOTHROW(atualizaUsuario(0, "Pedro", "Endereco", 1));
    CHECK_NOTHROW(atualizaUsuario(0, "Pedro", "Endereco", 2));
    
    // Verificando valor antes de alteração
    CHECK_EQ(getUserByIndex(1)->getNome(), "");
    // Fazendo alteração
    CHECK_NOTHROW(atualizaUsuario(1, "Pedro2", "Endereco", 2));
    
    // Verificando alterações
    CHECK_EQ(getUserByIndex(0)->getNome(), "Pedro");
    CHECK_EQ(getUserByIndex(0)->getTipo(), 2);
    CHECK_EQ(getUserByIndex(1)->getNome(), "Pedro2");

    CHECK_THROWS(atualizaUsuario(10, "Pedro", "Endreco", 1));
    CHECK_THROWS(atualizaUsuario(0, "Pedro", "Endereco", -1));
}

TEST_CASE("Testando Remocao De Usuarios") {
    // Primeiro deleta os dois usuários adicionados, depois tenta deletar usuários inexistentes
    CHECK_NOTHROW(deletaUsuario(0));
    CHECK_NOTHROW(deletaUsuario(0));
    CHECK_THROWS(deletaUsuario(0));
    CHECK_THROWS(deletaUsuario(34));
    CHECK_THROWS(deletaUsuario(-4));
}



TEST_CASE("Testando Adicao De Ponto de Coleta") {
    CHECK_NOTHROW(adicionaPontoColeta("Teste1"));
    CHECK_NOTHROW(adicionaPontoColeta("Teste2"));
    CHECK_NOTHROW(adicionaPontoColeta("Teste3"));
    CHECK_NOTHROW(adicionaPontoColeta("Teste4"));
}

TEST_CASE("Testando Alteracao De Ponto de Coleta") {
    CHECK_NOTHROW(atualizaPontoColeta(0, "Teste1Novo"));
    CHECK_NOTHROW(atualizaPontoColeta(1, "Teste2Novo"));
    
    // Verificando alterações
    CHECK_EQ(getPontoColetaByIndex(0)->getEndereco(), "Teste1Novo");
    CHECK_EQ(getPontoColetaByIndex(1)->getEndereco(), "Teste2Novo");
    
    // Verificando se inicializados anteriormente não foram alterados
    CHECK_EQ(getPontoColetaByIndex(2)->getEndereco(), "Teste3");
    CHECK_EQ(getPontoColetaByIndex(3)->getEndereco(), "Teste4");
    
    CHECK_THROWS(atualizaPontoColeta(-3, "Index Inexistente"));
    CHECK_THROWS(atualizaPontoColeta(10, "Index Inexistente"));
}



TEST_CASE("Testando Remocao De Pontos de Coleta") {
    CHECK_NOTHROW(deletaPontoColeta(0));
    CHECK_NOTHROW(deletaPontoColeta(0));
    CHECK_NOTHROW(deletaPontoColeta(0));
    CHECK_NOTHROW(deletaPontoColeta(0));
    CHECK_THROWS(deletaPontoColeta(0));
    CHECK_THROWS(deletaPontoColeta(34));
    CHECK_THROWS(deletaPontoColeta(-45));

}



TEST_CASE("Testando Adicao De Residuos") {
    CHECK_NOTHROW(adicionaResiduo("Sacola Plastica", 2, "Caixa"));
    CHECK_NOTHROW(adicionaResiduo("Oleo de cozinha", 3, "Garrafa plastica"));
    CHECK_NOTHROW(adicionaResiduo("Oleo de motor", 4, "Embalagem Original"));
    CHECK_NOTHROW(adicionaResiduo("Garrafa de vidro", 4, "Envolta em jornal"));
}

TEST_CASE("Testando Alteracao De Residuos") {
    CHECK_NOTHROW(atualizaResiduo(0, "Sacola de papelao", 1, "Em local seco"));
    CHECK_NOTHROW(atualizaResiduo(1, "Oleo de granola", 5, "Em garrafa plastica transparente"));
    
    // Verificando alterações
    CHECK_EQ(getResiduoByIndex(0)->getNome(), "Sacola de papelao");
    CHECK_EQ(getResiduoByIndex(1)->getNome(), "Oleo de granola");
    
    // Verificando se inicializados anteriormente não foram alterados
    CHECK_EQ(getResiduoByIndex(2)->getNome(), "Oleo de motor");
    CHECK_EQ(getResiduoByIndex(3)->getNome(), "Garrafa de vidro");
    
    CHECK_THROWS(atualizaResiduo(-3, "Index Inexistente", 1, "Em local seco"));
    CHECK_THROWS(atualizaResiduo(10, "Index Inexistente", 1, "Em local seco"));
}

TEST_CASE("Testando Remocao De Residuos") {
    CHECK_NOTHROW(deletaResiduo(0));
    CHECK_NOTHROW(deletaResiduo(0));
    CHECK_NOTHROW(deletaResiduo(0));
    CHECK_NOTHROW(deletaResiduo(0));
    CHECK_THROWS(deletaResiduo(0));
    CHECK_THROWS(deletaResiduo(34));
    CHECK_THROWS(deletaResiduo(-45));
    
}



TEST_CASE("Testando Adicao De Usuarios, Pontos e Residuos") {
    
    CHECK_NOTHROW(adicionaResiduo("Sacola Plastica", 2, "Caixa"));
    CHECK_NOTHROW(adicionaResiduo("Oleo de cozinha", 3, "Garrafa plastica"));
    CHECK_NOTHROW(adicionaResiduo("Oleo de motor", 4, "Embalagem Original"));
    CHECK_NOTHROW(adicionaResiduo("Garrafa de vidro", 4, "Envolta em jornal"));
    
    CHECK_NOTHROW(adicionaPontoColeta("Casa"));
    CHECK_NOTHROW(adicionaPontoColeta("Apartamento"));
    CHECK_NOTHROW(adicionaPontoColeta("Escola"));
    CHECK_NOTHROW(adicionaPontoColeta("Trabalho"));
    
    CHECK_NOTHROW(adicionaUsuario("Pedro", "Teste1", 1));
    CHECK_NOTHROW(adicionaUsuario("Joao", "Teste2", 2));
}

TEST_CASE("Testando Criacao de Coletas com dados do sistema") {
    std::vector<Residuo**> residuosNulos;
    std::vector<Residuo**> residous;
    Residuo* res = getResiduoByIndex(0);
    
    residous.push_back(&res);
    //residous.push_back(getResiduoByIndex(1));
    //residous.push_back(getResiduoByIndex(2));

    // Testando casos de sucesso
    CHECK_NOTHROW(adicionaColeta("Amanha", 0, 1, 0, residous));
    CHECK_NOTHROW(adicionaColeta("Hoje", 1, 0, 1, residous));
    CHECK_NOTHROW(adicionaColeta("24 de Dezembro de 2019", 0, 1, 2, residous));
    CHECK_NOTHROW(adicionaColeta("Sabado", 1, 0, 3, residous));
    
    // Testando casos de erro
    CHECK_THROWS(adicionaColeta("Amanha", -1, 3, 0, residous));
    CHECK_THROWS(adicionaColeta("Hoje", 1, -1, 1, residous));
    CHECK_THROWS(adicionaColeta("24 de Dezembro de 2019", 2, 1, -1, residous));
    CHECK_THROWS(adicionaColeta("Sabado", 3, 0, 3, residuosNulos));
}


TEST_CASE("Marcando coletas como feitas") {
    
    CHECK_NOTHROW(informaColetaEfetuada(0));
    CHECK_NOTHROW(informaColetaEfetuada(1));
    CHECK_NOTHROW(informaColetaEfetuada(2));
    CHECK_NOTHROW(informaColetaEfetuada(3));
        
    CHECK_THROWS(informaColetaEfetuada(-10));
    CHECK_THROWS(informaColetaEfetuada(28));
}
