//
//  Usuario.hpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#ifndef Usuario_hpp
#define Usuario_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Usuario {
    private:
        std::string nome;
        int tipo;
        std::string endereco;
        int qntColetas;
    
    public:
        Usuario(std::string nome, std::string endereco, int tipo);
        void addColeta();
        void removeColeta();
        int getQntColetas();
        void setEndereco(std::string endereco);
        void setNome(std::string nome);
        void setTipo(int tipo);
        int getTipo();
        std::string getEndereco();
        std::string getNome();
        ~Usuario();
};

#endif /* Usuario_hpp */
