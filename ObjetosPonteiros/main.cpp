// Funcao: main - arquivo principal do programa, inicializa e executa a demonstracao do projeto.
// Projeto: ObjetosPonteiros
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "no.h"
#include <iostream>

using namespace std;

int main()
{
    //Manipulando utilizando a classe (Diretamente)

    hil::No no1("Manoel Gomes", 20);
    hil::No *p1 = 0;
    p1 = &no1;
    cout <<"  Dados do NO \n" << no1.toString();
    no1.setNome("Ednaldo Pereira");
    no1.setElemento(30);
    cout <<"\n  Dados do NO \n" << no1.toString();

    //Manipulando usando p1 como ponteiro de no1 (Indiretamente com ponteiro seta)

    p1->setNome("Nal");
    p1->setElemento(40);
    cout <<"\n  Dados do NO \n" << p1->toString();

    //Outra forma de ser manipulado usando p1 (Indiretamente com ponteiro ponto)

    (*p1).setNome("Cleitão Bom de Guerra");
    (*p1).setElemento(50);
    cout <<"\n  Dados do NO \n" << (*p1).toString();

    //Manipulando usando referencia de no1 OBS: refNo1 NÂO É UM PONTEIRO

    hil::No &refNo1 = no1;
    refNo1.setNome("Orochinho");
    refNo1.setElemento(60);
    cout <<"\n  Dados do NO \n" << refNo1.toString();


    hil::No *p2 = 0;
    //SEMPRE USAR TRY CATCH EM NEW E DELETE
    p2 = new hil::No("Mcqueen",80);
    p2 = new hil::No("Shazzam",100);
    //^^^ Nisso o primeiro p2 ficaria pra sempre na memoria, Sempre deletar o primeiro new para criar outro.

    //Outras formas para mudar o nome no p2.

    p2->setNome("Shazzam");
    (*p2).setNome("Light");

    //para mudar o escopo e necessario fazer uma variavel com * antes do nome para mostrar o endereço do objeto.

    //
    hil::No *p1 = new hil::No ("Tazmania",120);
    hil::No *p2 = new hil::No ("Scorpion",200);
    p1->setProximo(p2);
    p1->getProximo();





}
