// Funcao: cliente - modulo de manipulacao e persistencia dos dados do projeto.
// Projeto: CadastroClientes
// Descricao: este arquivo faz parte da implementacao do projeto e desempenha a funcao acima no conjunto de codigo.

#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>

namespace hil{

class Cliente
{
private:
    int codigo;
    QString nome;
    QString email;
public:
    Cliente();
    Cliente(int codigo, QString nome, QString email);
    int getCodigo() const;
    void setCodigo(int newCodigo);
    const QString &getNome() const;
    void setNome(const QString &newNome);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
};
}
#endif // CLIENTE_H
