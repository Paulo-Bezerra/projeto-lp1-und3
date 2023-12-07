#include "../include/funcionario.hpp"

using namespace std;

// modifica o conteúdo de cep
Funcionario::Funcionario(string matricula, float salario, string departamento, int cargaHoraria, string dataIngresso) {
  this->matricula = matricula;
  this->salario = salario;
  this->departamento = departamento;
  this->cargaHoraria = cargaHoraria;
  this->dataIngresso = dataIngresso;
}
Funcionario::Funcionario(){}

// retorna a matricula
string Funcionario::getMatricula() {
  return this->matricula;
}

// retorna o salário
float Funcionario::getSalario() {
  return this->salario;
}

// retorna o departamento
string Funcionario::getDepartamento() {
  return this->departamento;
}

// retorna a carga horaria
int Funcionario::getCargaHoraria() {
  return this->cargaHoraria;
}

// retorna a data de ingresso
string Funcionario::getDataIngresso() {
  return this->dataIngresso;
}

// modifica o conteúdo de matricula
void Funcionario::setMatricula(string matricula) {
  this->matricula = matricula;
}

// modifica o conteúdo de salario
void Funcionario::setSalario(float salario) {
  this->salario = salario;
}

// modifica o conteúdo de rua salario
void Funcionario::setDepartamento(string departamento) {
  this->departamento = departamento;
}

// modifica o conteúdo de cargaHoraria
void Funcionario::setCargaHoraria(int cargaHoraria) {
  this->cargaHoraria = cargaHoraria;
}

// modifica o conteúdo de dataIngresso
void Funcionario::setDataIngresso(string dataIngresso) {
  this->dataIngresso = dataIngresso;
}
