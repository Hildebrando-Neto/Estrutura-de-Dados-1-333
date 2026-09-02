#include <iostream>
#include "ArvoreBinaria.h"

// Funcao: arquivo principal de teste da arvore binaria.
// Ele cria a estrutura, insere valores, imprime a ordem e remove um elemento para validar a logica.

int main()
{
    try {
        ED1::ArvoreBinaria teste;

        std::cout << std::endl << "Incluindo dados na arvore criada" << std::endl;
        std::cout << "Incluindo valor 50" << std::endl; teste.inserir(50);
        std::cout << "Incluindo valor 40" << std::endl; teste.inserir(40);
        std::cout << "Incluindo valor 60" << std::endl; teste.inserir(60);
        std::cout << "Incluindo valor 35" << std::endl; teste.inserir(35);
        std::cout << "Incluindo valor 45" << std::endl; teste.inserir(45);
        std::cout << "Incluindo valor 70" << std::endl; teste.inserir(70);
        std::cout << "Incluindo valor 56" << std::endl; teste.inserir(56);
        // std::cout << "Incluindo valor 60 repetido" << std::endl; teste.inserir(60);

        std::cout << std::endl << "Mostrando os dados da arvore criada" << std::endl;
        std::cout << "Encaminhamento Central a Esquerda";
        teste.imprimir();
        std::cout << std::endl;

        std::cout << std::endl << "Removendo o valor 60 da arvore" << std::endl;
        teste.remover(60);
        std::cout << std::endl << "Mostrando os dados da arvore apos remover o valor";
        teste.imprimir();

        std::cout << std::endl;
        std::cout << std::endl << "Mostrando a arvore sendo destruida" << std::endl;
        return 0;

    } catch (const std::string &erro) {
        std::cout << std::endl << "Erro: " << erro << std::endl;
        return 1;
    }
}
