//
//  Sistema.cpp
//  STR
//
//  Created by Arthur Faria on 07/11/18.
//  Copyright © 2018 Arthur Faria. All rights reserved.
//
/*

 Esse arquivo é responsável por fazer a ponte de interação entre o usuário e as Classes. Nele são estabelecidos vários parâmetros de funcionamento, como tipos de resíduos e informações de armazenamento.
 
*/

#include "Sistema.hpp"
#include <term.h>
#include <vector>

std::vector<Usuario*> users;
std::vector<PontoDeColeta*> pontosDeColeta;
std::vector<Residuo*> residuos;
std::vector<Coleta*> coletas;





/* Funções repsonsáveis pelo feedback e demonstração ao usuário que utiliza o sistema */

void limpaTela() {
    system("clear");
}
void pressioneParaContinuar() {
    std::cout<<"Pressione qualquer tecla para continuar...\n\n";
    system("read");
}
void printMenu() {
    limpaTela();
    std::cout<<"----- Usuarios -----\n1 - Adicionar Usuario\n2 - Listar Usuarios\n3 - Atualizar Usuario\n4 - Remover Usuario\n\n----- Pontos de Coleta -----\n5 - Adicionar Ponto\n6 - Listar Pontos\n7 - Atualizar Ponto\n8 - Remover Ponto\n\n----- Residuos -----\n9 - Listar Tipos de Residuos do Sistema\n10 - Adicionar Residuo\n11 - Listar Residuos\n12 - Atualizar Residuos\n13 - Remover Residuos\n\n----- Coletar -----\n14 - Agendar Coleta\n15 - Listar Coletas\n16 - Informar coleta efetuada";
    std::cout<<"\n\nDigite a opcao:";
}
void printTipoResiduos() {
    limpaTela();
    std::cout<<"----- Solidos -----\n1 - Metais\n2 - Plasticos\n3 - Vidros\n----- Liquidos -----\n4 - Organicos\n5 - Nao Organicos\n\n";
    pressioneParaContinuar();
}
void printDicaArmazenamento(int tipoResiduo) {
    std::cout<<"Os resíduos não devem ser armazenados juntamente com resíduos tóxicos, inflamáveis e corrosivos. O armazenamento pode ser realizado em contêineres e/ou tambores, em tanques e a granel. Evitar o contato com o solo e deixar em ambientes fechados.";
}




/* Funções repsonsáveis por criar as funcionalidades e relações com as outras classes.  Utilizadas também pelos testes */

// Funções responsáveis por manipular usuários.
void adicionaUsuario(std::string nome, std::string endereco, int tipo) {
    try {
        Usuario *user = new Usuario(nome, endereco, tipo);
        users.push_back(user);
    } catch (std::invalid_argument e) {
        std::cout << e.what();
    }
}
void listarUsuarios() {
    limpaTela();
    std::cout<<users.size()<<" usuario(s)\n";
    std::cout<<"Index\tNome\tEndereco\tTipo\n";
    for (unsigned int i=0; i < users.size();i++) {
        std::cout << i << "\t" << users[i]->getNome() << "\t" << users[i]->getEndereco()<< "\t" << users[i]->getTipo()<<"\n";
    }
    pressioneParaContinuar();
}

void atualizaUsuario(int index, std::string nome, std::string endereco, int tipo) {
    if (pontosDeColeta.size() < index)
        throw std::invalid_argument("Index Inexistente");
    users[index]->setNome(nome);
    users[index]->setEndereco(endereco);
    try {
        users[index]->setTipo(tipo);
    } catch (std::invalid_argument e){
        std::cout << e.what();
    }
}

void deletaUsuario(int index) {
    if (pontosDeColeta.size() < index)
        throw std::invalid_argument("Index Inexistente");
    if (users[index]->getQntResiduos() == 0 && users[index]->getQntColetas() == 0) {
        users.erase(users.begin() + index);
    }
    else {
       std::logic_error("Impossivel deletar usuario com Coletas e Residuos");
    }
}


// Funções responsáveis por manipular Pontos De Coletas
void adicionaPontoColeta(std::string endereco){
    PontoDeColeta *ponto = new PontoDeColeta(endereco);
    pontosDeColeta.push_back(ponto);
}
void listaPontoColeta(){
    limpaTela();
    std::cout<<pontosDeColeta.size()<<" pontos(s)\n";
    std::cout<<"Index\tEndereco\n";
    for (unsigned int i=0; i < pontosDeColeta.size();i++) {
        std::cout << i << "\t" << pontosDeColeta[i]->getEndereco();
    }
    pressioneParaContinuar();
}
void atualizaPontoColeta(int index, std::string endereco){
    if (pontosDeColeta.size() < index)
        throw std::invalid_argument("Index Inexistente");
    pontosDeColeta[index]->setEndereco(endereco);
}
void deletaPontoColeta(int index){
    if (pontosDeColeta.size() < index)
        throw std::invalid_argument("Index Inexistente");
    
    if (pontosDeColeta[index]->getQntColetas() == 0) {
        pontosDeColeta.erase(pontosDeColeta.begin() + index);
    }
    else {
        std::logic_error("Impossivel deletar ponto com Coletas");
    }
}



// Funções responsáveis por manipular Residuos
void adicionaResiduo(std::string nome, int tipo, int donoIndex){
    Residuo *residuo = new Residuo(nome, tipo, users[donoIndex]);
    residuos.push_back(residuo);
}
void listaResiduo(){
    limpaTela();
    std::cout<<residuos.size()<<" residuos(s)\n";
    std::cout<<"Index\tNome\tTipo\tUsuario";
    for (unsigned int i=0; i < residuos.size();i++) {
        std::cout << i << "\t" << residuos[i]->getNome() << "\t" << residuos[i]->getTipo() << "\t" << residuos[i]->getDono()->getNome();
    }
    pressioneParaContinuar();
}
void atualizaResiduo(int index, std::string nome, int tipo, int indexUser){
    if (residuos.size() < index)
        throw std::invalid_argument("Index Inexistente");
    residuos[index]->setNome(nome);
    residuos[index]->setTipo(tipo);
    // Reduzindo um residuo de usuario antigo
    residuos[index]->getDono()->removeResiduo();
    
    residuos[index]->setDono(users[indexUser]);
    // Adicionando Residuo a novo usuario
    residuos[index]->getDono()->addResiduo();
}
void deletaResiduo(int index){
    if (residuos.size() < index)
        throw std::invalid_argument("Index Inexistente");
    
    if (residuos[index]->getQntColeta() == 0) {
        residuos.erase(residuos.begin() + index);
    }
    else {
        std::logic_error("Impossivel deletar residuo com Coleta");
    }
}



// Funções responsáveis por manipular Coletas
void adicionaColeta(std::string data, int indexReceptor, int indexDoador, int indexPonto, std::vector<Residuo**> residuos){
    // Coleta(std::string data, Usuario *receptor, Usuario *doador, PontoDeColeta *ponto);
    Coleta *coleta = new Coleta(data, users[indexReceptor], users[indexDoador], pontosDeColeta[indexPonto], residuos);
    coletas.push_back(coleta);
}
void listaColetas(){
    limpaTela();
    std::cout<<coletas.size()<<" residuos(s)\n";
    std::cout<<"Index\tLocal\tDoador\tReceptor\tColetado?";
    for (unsigned int i=0; i < coletas.size();i++) {
        std::cout << i << "\t" << coletas[i]->getPonto()->getEndereco() << "\t" << coletas[i]->getDoador()->getNome() << "\t" << coletas[i]->getRecetor()->getNome() << "\t" << coletas[i]->getColetado();
    }
    pressioneParaContinuar();
}

void informaColetaEfetuada(int index){
    if (residuos.size() < index)
        throw std::invalid_argument("Index Inexistente");
    coletas[index]->setColeta(true);
}

void iniciaSistema(){
    int entrada = -1;
    do {
        printMenu();
        std::cin>>entrada;
        switch (entrada) {
            case 1: {
                // Adiciona Usuário
                std::string nome, endereco;
                int tipo;
                limpaTela();
                std::cout<<"Digite o nome do usuario: ";
                std::cin>>nome;
                std::cout<<"Digite o endereco do usuario: ";
                std::cin>>endereco;
                std::cout<<"Tipo (1) - Pessoa Fisica ou (2) - Pessoa Juridica? ";
                std::cin>>tipo;
                adicionaUsuario(nome, endereco, tipo);
                break;
            }
                
            case 2:
                // Listar usuários
                listarUsuarios();
                break;
                
            case 3: {
                // Atualiza Usuário
                std::string nome, endereco;
                int tipo, indice;
                limpaTela();
                std::cout<<"Digite o indice do usuario a ser atualizado: ";
                std::cin>>indice;
                std::cout<<"Digite o nome do usuario: ";
                std::cin>>nome;
                std::cout<<"Digite o endereco do usuario: ";
                std::cin>>endereco;
                std::cout<<"Tipo (1) - Pessoa Fisica ou (2) - Pessoa Juridica? ";
                std::cin>>tipo;
                atualizaUsuario(indice, nome, endereco, tipo);
                break;
            }
                
            case 4: {
                // Remove usuário
                int indice;
                limpaTela();
                std::cout<<"Digite o indice do usuario a ser removido: ";
                std::cin>>indice;
                try {
                    deletaUsuario(indice);
                } catch (std::invalid_argument e) {
                    std::cout<<e.what();
                }
                break;
            }
               
            case 5: {
                // Adiciona Ponto de Coleta
                std::string endereco;
                std::cout<<"Digite o endereco do ponto: ";
                std::cin>>endereco;
                adicionaPontoColeta(endereco);
                break;
            }
                
            case 6: {
                // Lista Pontos de Coleta
                listaPontoColeta();
                break;
            }
            case 7: {
                // Atualiza Pontos de Coleta
                std::string endereco;
                int indice;
                limpaTela();
                std::cout<<"Digite o indice do ponto a ser atualizado: ";
                std::cin>>indice;
                std::cout<<"Digite o endereco do ponto: ";
                std::cin>>endereco;
                try {
                    atualizaPontoColeta(indice, endereco);
                } catch (std::invalid_argument e) {
                    std::cout<<e.what();
                }
                break;
            }
                
            case 8: {
                // Remove Ponto de Coleta
                int indice;
                std::cout<<"Digite o indice do ponto a ser removido: ";
                std::cin>>indice;
                try {
                    deletaPontoColeta(indice);
                } catch (std::invalid_argument e) {
                    std::cout<<e.what();
                }
                break;
            }
            case 9:
                // Imprime tipos de resíduos disponíveis
                printTipoResiduos();
                break;
                
            case 10: {
                // Adicionar Residuo
                int userIndex, tipo;
                std::string nome;
                std::cout<<"Digite o indice do Usuario responsavel: ";
                std::cin>>userIndex;
                std::cout<<"Digite o nome do residuo: ";
                std::cin>>nome;
                printTipoResiduos();
                std::cout<<"Digite o tipo do residuo: ";
                std::cin>>tipo;
                adicionaResiduo(nome, tipo, userIndex);
                break;
            }
            case 11:
                // Lista Resíduos cadastrados
                listaResiduo();
                break;
                
            case 12: {
                // Atualiza Resíduo
                int userIndex, tipo, residuoIndex;
                std::string nome;
                std::cout<<"Digite o indice do Residuo: ";
                std::cin>>residuoIndex;
                std::cout<<"Digite o indice do Usuario responsavel: ";
                std::cin>>userIndex;
                std::cout<<"Digite o nome do residuo: ";
                std::cin>>nome;
                printTipoResiduos();
                std::cout<<"Digite o tipo do residuo: ";
                std::cin>>tipo;
                atualizaResiduo(residuoIndex, nome, tipo, userIndex);
                std::cout<<"";
                break;
            }
            case 13:
                // Remove Resíduo
                int residuoIndex;
                std::cout<<"Digite o indice do Residuo: ";
                std::cin>>residuoIndex;
                deletaResiduo(residuoIndex);
                break;
                
            case 14:
                // Agenda Coleta
                std::cout<<"";
                break;
                
            case 15:
                // Lista Coletas Cadastradas
                listaColetas();
                break;
                
            case 16:{
                // Informa coleta efetuada
                int indice;
                std::cout<<"Digite o indice da coleta a ser marcada como coletada: ";
                std::cin>>indice;
                try {
                    informaColetaEfetuada(indice);
                } catch (std::invalid_argument e) {
                    std::cout<<e.what();
                }
                break;
            }
            default:
                std::cout << "\n\nEntrada Invalida!\n\n";
                entrada = -1;
        }
    }
    while(entrada != 0);
}
