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
        std::string nome;
        Usuario *dono;
        int qntColeta;
    public:
        Usuario* getDono();
        int getTipo();
        void setTipo(int tipo);
        void setDono(Usuario* dono);
        std::string getNome();
        void setNome(std::string nome);
        int getQntColeta();
        void addColeta();
        void removeColeta();
        Residuo(std::string nome, int tipo, Usuario* dono);
};
#endif /* Residuo_hpp */
