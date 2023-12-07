#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>

// declaração da classe Funcionario
class Funcionario {
private:
  std::string matricula;
  float salario;
  std::string departamento;
  int cargaHoraria;
  std::string dataIngresso;
public:
  // construtores da classe Funcionários
  Funcionario(std::string matricula, float salario, std::string departamento, int cargaHoraria, std::string dataIngresso);
  Funcionario();
  
  // retorna a matricula
  std::string getMatricula();

  // retorna o salário
  float getSalario();

  // retorna o departamento
  std::string getDepartamento();

  // retorna a carga horaria
  int getCargaHoraria();

  // retorna a data de ingresso
  std::string getDataIngresso();

  // modifica o conteúdo de matricula
  void setMatricula(std::string matricula);
  
  // modifica o conteúdo de salario
  void setSalario(float salario);

  // modifica o conteúdo de departamento
  void setDepartamento(std::string departamento);

  // modifica o conteúdo de cargaHoraria
  void setCargaHoraria(int cargaHoraria);

  // modifica o conteúdo de dataIngresso
  void setDataIngresso(std::string dataIngresso);
};

#endif