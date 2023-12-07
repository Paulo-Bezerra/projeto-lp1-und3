#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "pessoa.hpp"
#include "funcionario.hpp"

// declaração da classe Professor que herda de Pessoa e Funcionario
class Professor : public Pessoa, public Funcionario {
private:
  // enumeração correspondente à formação do professor
  enum Formacao {
    GRADUACAO = 1, ESPECIALIZACAO = 2, MESTRADO = 3, DOUTORADO = 4
  };
  // enumeração correspondente ao nível do professor
  enum Nivel {
    I = 1, II = 2, III = 3, IV = 4, V = 5, VI = 6, VII = 7, VIII = 8
  };
  Formacao formacaoProfessor = GRADUACAO;
  Nivel nivelProfessor = I;

public:
  // construtores da classe Professor
  Professor(Pessoa pessoa, Funcionario funcionario, int formacaoProfessor, int nivelProfessor);
  Professor();

  // retorna o inteiro correspondente à formação do professor
  int getFormacaoProfessor();

  // retorna o inteiro correspondente ao nível do professor
  int getNivelProfessor();

  // modifica a formação do professor de acordo com o inteiro passado
  void setFormacaoProfessor(int formacaoProfessor);

  // modifica o nível do professor de acordo com o inteiro passado
  void setNivelProfessor(int nivelProfessor);
};


#endif
