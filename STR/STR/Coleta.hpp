//
//  Coleta.hpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#ifndef Coleta_hpp
#define Coleta_hpp

#include <stdio.h>
#include "Usuario.hpp"
#include "PontoDeColeta.hpp"
#include "Residuo.hpp"
#include <string>
#include <iostream>
#include <vector>

class Coleta {
    private:
        std::string data;
        bool coletado;
        Usuario *receptor;
        Usuario *doador;
        PontoDeColeta *ponto;
        std::vector<Residuo**> residuos;
    public:
        Coleta(std::string data, Usuario *receptor, Usuario *doador, PontoDeColeta *ponto, std::vector<Residuo**> residuos);
        ~Coleta();
        bool getColetado();
        void setColeta(bool coletado);
        void setDoador(Usuario *doador);
        void setReceptor(Usuario *receptor);
        void setData(std::string data);
    
        std::string getData();
        Usuario* getRecetor();
        Usuario* getDoador();
        PontoDeColeta *getPonto();
    
};
#endif /* Coleta_hpp */
