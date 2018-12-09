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
#include <string.h>

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
    std::cout<<"----- Usuarios -----\n1 - Adicionar Usuario\n2 - Listar Usuarios\n3 - Atualizar Usuario\n4 - Remover Usuario\n\n----- Pontos de Coleta -----\n5 - Adicionar Ponto\n6 - Listar Pontos\n7 - Atualizar Ponto\n8 - Remover Ponto\n\n----- Residuos -----\n9 - Listar Tipos de Residuos do Sistema\n10 - Adicionar Residuo\n11 - Listar Residuos\n12 - Atualizar Residuos\n13 - Remover Residuos\n\n----- Coletar -----\n14 - Agendar Coleta\n15 - Listar Coletas\n16 - Informar coleta efetuada\n\n0 - Sair do sistema";
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
void sairDoSistema(){
    unsigned i = 0;
    for (i=0; i < coletas.size();i++) {
        delete coletas[i];
    }
    for (i=0; i < users.size();i++) {
        delete users[i];
    }
    for (i=0; i < pontosDeColeta.size();i++) {
        delete pontosDeColeta[i];
    }
    for (i=0; i < residuos.size();i++) {
        delete residuos[i];
     }
}

/* Funções repsonsáveis por criar as funcionalidades e relações com as outras classes.  Utilizadas também pelos testes */

Usuario* getUserByIndex(int index){
    if (users.size() < index || index < 0 || users.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    return users[index];
}
PontoDeColeta* getPontoColetaByIndex(int index){
    if (pontosDeColeta.size() < index || index < 0 || pontosDeColeta.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    return pontosDeColeta[index];
}
Residuo* getResiduoByIndex(int index){
    if (residuos.size() < index || index < 0 || residuos.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    return residuos[index];
}
Coleta* getColetaByIndex(int index){
    if (coletas.size() < index || index < 0 || coletas.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    return coletas[index];
}


// Funções responsáveis por manipular usuários.
void adicionaUsuario(std::string nome, std::string endereco, int tipo) {
    Usuario *user = new Usuario(nome, endereco, tipo);
    users.push_back(user);
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
    if (users.size() < index || index < 0 || users.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    users[index]->setNome(nome);
    users[index]->setEndereco(endereco);
    users[index]->setTipo(tipo);
}

void deletaUsuario(int index) {
    if (users.size() < index || index < 0 || users.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    if (users[index]->getQntColetas() == 0) {
        delete users[index];
        users.erase(users.begin() + index);
    }
    else {
       std::logic_error("Impossivel deletar usuario com Coletas Agendadas");
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
    if (pontosDeColeta.size() < index || index < 0 || pontosDeColeta.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    pontosDeColeta[index]->setEndereco(endereco);
}
void deletaPontoColeta(int index){
    if (pontosDeColeta.size() < index || index < 0 || pontosDeColeta.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    
    if (pontosDeColeta[index]->getQntColetas() == 0) {
        delete pontosDeColeta[index];
        pontosDeColeta.erase(pontosDeColeta.begin() + index);
    }
    else {
        std::logic_error("Impossivel deletar ponto com Coletas");
    }
}



// Funções responsáveis por manipular Residuos
void adicionaResiduo(std::string nome, int tipo, std::string descricao){
    Residuo *residuo = new Residuo(nome, tipo, descricao);
    residuos.push_back(residuo);
}
void listaResiduo(){
    limpaTela();
    std::cout<<residuos.size()<<" residuos(s)\n";
    std::cout<<"Index\tNome\tTipo\tDescricao";
    for (unsigned int i=0; i < residuos.size();i++) {
        std::cout << i << "\t" << residuos[i]->getNome() << "\t" << residuos[i]->getTipo() << "\t" << residuos[i]->getDescricao();
    }
    pressioneParaContinuar();
}
void atualizaResiduo(int index, std::string nome, int tipo, std::string descricao){
    if (residuos.size() < index || index < 0 || residuos.size() == 0)
        throw std::invalid_argument("Index de Residuo Inexistente");
    
    residuos[index]->setNome(nome);
    residuos[index]->setTipo(tipo);
    residuos[index]->setDescricao(descricao);
    
}
void deletaResiduo(int index){
    if (residuos.size() < index || index < 0 || residuos.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    
    if (residuos[index]->getQntColeta() == 0) {
        delete residuos[index];
        residuos.erase(residuos.begin() + index);
    }
    else {
        std::logic_error("Impossivel deletar residuo com Coleta");
    }
}

// Funções responsáveis por manipular Coletas
void adicionaColeta(std::string data, int indexReceptor, int indexDoador, int indexPonto, std::vector<Residuo**> vetorResiduos){
    // Coleta(std::string data, Usuario *receptor, Usuario *doador, PontoDeColeta *ponto);
    
    if (users.size() < indexReceptor || indexReceptor < 0 || users.size() == 0)
        throw std::invalid_argument("Index de Receptor Inexistente");
    
    if (users.size() < indexDoador || indexDoador < 0 || users.size() == 0)
        throw std::invalid_argument("Index de Doador Inexistente");
    
    if (pontosDeColeta.size() < indexPonto || indexPonto < 0 || pontosDeColeta.size() == 0)
        throw std::invalid_argument("Index de Ponto de Coleta Inexistente");
    
    if (vetorResiduos.size() == 0)
        throw std::invalid_argument("Nenhum residuo passado para recolhimento");
    
    Coleta *coleta = new Coleta(data, users[indexReceptor], users[indexDoador], pontosDeColeta[indexPonto], vetorResiduos);
    for (int i=0; i<vetorResiduos.size(); i++) {
        std::cout<<"Instrucoes de armazenamento de " << (*vetorResiduos[i])->getNome() << ": " << (*vetorResiduos[i])->getDescricao();
    }
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
    if (coletas.size() < index || index < 0 || coletas.size() == 0)
        throw std::invalid_argument("Index Inexistente");
    coletas[index]->setColeta(true);
}

// Função responsável pela interação com o usuário
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
                int tipo;
                std::string nome, descricao;
                std::cout<<"Digite o nome do residuo: ";
                std::cin>>nome;
                std::cout<<"Digite o tipo do residuo: ";
                std::cin>>tipo;
                std::cout<<"Digite o melhor meio de armazenamento do residuo: ";
                std::cin>>descricao;
                adicionaResiduo(nome, tipo, descricao);
                break;
            }
            case 11:
                // Lista Resíduos cadastrados
                listaResiduo();
                break;
                
            case 12: {
                // Atualiza Resíduo
                int tipo, residuoIndex;
                std::string nome, descricao;
                std::cout<<"Digite o indice do Residuo: ";
                std::cin>>residuoIndex;
                std::cout<<"Digite o nome do residuo: ";
                std::cin>>nome;
                printTipoResiduos();
                std::cout<<"Digite o tipo do residuo: ";
                std::cin>>tipo;
                std::cout<<"Digite o melhor meio de armazenamento do residuo: ";
                std::cin>>descricao;
                atualizaResiduo(residuoIndex, nome, tipo, descricao);
                std::cout<<"";
                break;
            }
            case 13:{
                // Remove Resíduo
                int residuoIndex;
                std::cout<<"Digite o indice do Residuo: ";
                std::cin>>residuoIndex;
                deletaResiduo(residuoIndex);
                break;
            }
            case 14: {
                // Agenda Coleta
                int recpIndex, doadorIndex, pontoIndex, qntRes, residuosDaColeta;
                std::vector<Residuo**> res;
                std::string data;
                std::cout<<"Digite quantos residuos serao coletados: ";
                std::cin>>qntRes;
                for(int i = 0; i < qntRes; i ++){
                    std::cout<<"Digite o Index do residuo de n "<<i<<":";
                    std::cin>>residuosDaColeta;
                    Residuo* resid = getResiduoByIndex(residuosDaColeta);
                    res.push_back(&resid);
                }
                std::cout<<"Digite o indice do Receptor: ";
                std::cin>>recpIndex;
                std::cout<<"Digite o indice do Doador: ";
                std::cin>>doadorIndex;
                std::cout<<"Digite o indice do Ponto da Coleta: ";
                std::cin>>pontoIndex;
                std::cout<<"Digite a data da Coleta: ";
                std::cin>>data;
                std::cout<<"";
                try{
                    adicionaColeta(data, recpIndex, doadorIndex, pontoIndex, res);
                } catch (std::exception e){
                    std::cout << e.what();
                }
                break;
            }
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
            case 0: {
                sairDoSistema();
            }
            default:
                std::cout << "\n\nEntrada Invalida!\n\n";
                entrada = -1;
        }
    }
    while(entrada != 0);
}
