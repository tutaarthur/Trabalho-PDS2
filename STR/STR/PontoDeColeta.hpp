//
//  PontoDeColeta.hpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//

#ifndef PontoDeColeta_hpp
#define PontoDeColeta_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class PontoDeColeta {
    private:
        std::string endereco;
        int qntColetas;
    public:
        void addColeta();
        void removeColeta();
        int getQntColetas();
        std::string getEndereco();
        void setEndereco(std::string endereco);
        PontoDeColeta(std::string endereco);
        ~PontoDeColeta();
};
#endif /* PontoDeColeta_hpp */
