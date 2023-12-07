#include "../include/tecnico_adm.hpp"

using namespace std;

// construtores da classe TecnicoAdm
TecnicoAdm::TecnicoAdm(Pessoa pessoa, Funcionario funcionario, std::string funcaoDesempenhada) {
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
  // atribuição ao tecnico(a) administrativo
  this->funcaoDesempenhada = funcaoDesempenhada;
}
TecnicoAdm::TecnicoAdm(){}

// retorna o adcional de produtividade
float TecnicoAdm::getAdicionalProdutividade() {
  return this->adicionalProdutividade;
}

// retorna o adcional de produtividade
std::string TecnicoAdm::getFuncaoDesempenhada() {
  return this->funcaoDesempenhada;
}

// modifica o adiconal de produtividade de acordo com o float passado
void TecnicoAdm::setAdicionalProdutividade(float adicionalProdutividade) {
  this->adicionalProdutividade = adicionalProdutividade;
}

// modifica a função desempenhada de acordo com a string passada
void TecnicoAdm::setFuncaoDesempenhada(string funcaoDesempenhada) {
  this->funcaoDesempenhada = funcaoDesempenhada;
}