//
//  Residuo.hpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#ifndef Residuo_hpp
#define Residuo_hpp

#include <stdio.h>
#include "Usuario.hpp"
class Residuo {
    private:
        int tipo;
        std::string nome, descricao;
        int qntColeta;
    public:
        int getTipo();
        void setTipo(int tipo);
        std::string getNome();
        std::string getDescricao();
        void setDescricao(std::string descricao);
        void setNome(std::string nome);
        int getQntColeta();
        void addColeta();
        void removeColeta();
        Residuo(std::string nome, int tipo, std::string descricao);
};
#endif /* Residuo_hpp */
