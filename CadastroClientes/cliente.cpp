// Funcao: cliente - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: CadastroClientes
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#include "cliente.h"

namespace hil {

int Cliente::getCodigo() const
{
    return codigo;
}

void Cliente::setCodigo(int newCodigo)
{
    codigo = newCodigo;
}

const QString &Cliente::getNome() const
{
    return nome;
}

void Cliente::setNome(const QString &newNome)
{
    nome = newNome;
}

const QString &Cliente::getEmail() const
{
    return email;
}

void Cliente::setEmail(const QString &newEmail)
{
    email = newEmail;
}

Cliente::Cliente()
{

}

Cliente::Cliente(int codigo, QString nome, QString email):
    codigo(codigo),
    nome(nome),
    email(email)
{

}
}
