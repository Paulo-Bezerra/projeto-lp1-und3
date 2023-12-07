#include "../include/professor.hpp"

// construtores da classe Professor
Professor::Professor(Pessoa pessoa, Funcionario funcionario, int formacaoProfessor, int nivelProfessor) {
  // herança de pessoa
  this->setNome(pessoa.getNome());
  this->setCpf(pessoa.getCpf());
  this->setDataNascimento(pessoa.getDataNascimento());
  this->setGenero(pessoa.getGenero());
  // endereço
  this->setEndereco(pessoa.getEndereco().getRua(), pessoa.getEndereco().getNumero(), pessoa.getEndereco().getBairro(),
                    pessoa.getEndereco().getCidade(), pessoa.getEndereco().getCep());
  // herança de funcionario
  this->setMatricula(funcionario.getMatricula());
  this->setSalario(funcionario.getSalario());
  this->setDepartamento(funcionario.getDepartamento());
  this->setCargaHoraria(funcionario.getCargaHoraria());
  this->setDataIngresso(funcionario.getDataIngresso());
  
  // atribuição ao professor(a)
  // realixando a conversão para enum Formacao
  if (formacaoProfessor == 1) {
    this->formacaoProfessor = GRADUACAO;
  } else if (formacaoProfessor == 2) {
    this->formacaoProfessor = ESPECIALIZACAO;
  } else if (formacaoProfessor == 3) {
    this->formacaoProfessor = MESTRADO;
  } else if (formacaoProfessor == 4) {
    this->formacaoProfessor = DOUTORADO;
  }

  // realixando a conversão para enum Formacao
  if (nivelProfessor == 1) {
    this->nivelProfessor = I;
  } else if (nivelProfessor == 2) {
    this->nivelProfessor = II;
  } else if (nivelProfessor == 3) {
    this->nivelProfessor = III;
  } else if (nivelProfessor == 4) {
    this->nivelProfessor = IV;
  } else if (nivelProfessor == 5) {
    this->nivelProfessor = V;
  } else if (nivelProfessor == 6) {
    this->nivelProfessor = VI;
  } else if (nivelProfessor == 7) {
    this->nivelProfessor = VII;
  } else if (nivelProfessor == 8) {
    this->nivelProfessor = VIII;
  }
}
Professor::Professor() {}

// retorna o inteiro correspondente à formação do professor
int Professor::getFormacaoProfessor() {
  return this->formacaoProfessor;
}

// retorna o inteiro correspondente ao nível do professor
int Professor::getNivelProfessor() {
  return this->nivelProfessor;
}

// retorna o inteiro correspondente ao nível do professor
void Professor::setFormacaoProfessor(int formacaoProfessor) {
  // realixando a conversão para enum Formacao
  if (formacaoProfessor == 1) {
    this->formacaoProfessor = GRADUACAO;
  } else if (formacaoProfessor == 2) {
    this->formacaoProfessor = ESPECIALIZACAO;
  } else if (formacaoProfessor == 3) {
    this->formacaoProfessor = MESTRADO;
  } else if (formacaoProfessor == 4) {
    this->formacaoProfessor = DOUTORADO;
  }
}

// modifica o nível do professor de acordo com o inteiro passado
void Professor::setNivelProfessor(int nivelProfessor) {
  // realixando a conversão para enum Nivel
  if (nivelProfessor == 1) {
    this->nivelProfessor = I;
  } else if (nivelProfessor == 2) {
    this->nivelProfessor = II;
  } else if (nivelProfessor == 3) {
    this->nivelProfessor = III;
  } else if (nivelProfessor == 4) {
    this->nivelProfessor = IV;
  } else if (nivelProfessor == 5) {
    this->nivelProfessor = V;
  } else if (nivelProfessor == 6) {
    this->nivelProfessor = VI;
  } else if (nivelProfessor == 7) {
    this->nivelProfessor = VII;
  } else if (nivelProfessor == 8) {
    this->nivelProfessor = VIII;
  }
}