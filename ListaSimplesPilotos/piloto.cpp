// Funcao: piloto - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: ListaSimplesPilotos
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "piloto.h"

namespace  hil {

int Piloto::getCodigo() const
{
    return codigo;
}

void Piloto::setCodigo(int newCodigo)
{
    codigo = newCodigo;
}

const QString &Piloto::getNome() const
{
    return nome;
}

void Piloto::setNome(const QString &newNome)
{
    nome = newNome;
}

const QString &Piloto::getPais() const
{
    return pais;
}

void Piloto::setPais(const QString &newPais)
{
    pais = newPais;
}

int Piloto::getIdade() const
{
    return idade;
}

void Piloto::setIdade(int newIdade)
{
    idade = newIdade;
}

const QString &Piloto::getEquipe() const
{
    return equipe;
}

void Piloto::setEquipe(const QString &newEquipe)
{
    equipe = newEquipe;
}

const QString &Piloto::getMotor() const
{
    return motor;
}

void Piloto::setMotor(const QString &newMotor)
{
    motor = newMotor;
}

Piloto::Piloto():
    codigo(0),
    nome(""),
    pais(""),
    idade(0),
    equipe(""),
    motor("")
{
}

Piloto::Piloto(int codigo,QString nome, QString pais, int idade, QString equipe,
               QString motor):
    codigo(codigo),
    nome(nome),
    pais(pais),
    idade(idade),
    equipe(equipe),
    motor(motor)
{
}

QString Piloto::toString()const{
    QString saida = "{ ";
    saida += "Codigo: " + QString::number(codigo) +  "\n";
    saida += " Nome: " + nome + "\n";
    saida += "Pais: " + pais + "\n";
    saida += "Idade: " + QString::number(idade) + "\n";
    saida += "Equipe: " + equipe + "\n";
    saida += "Motor: " + motor + " } \n";
    return saida;
}
}
