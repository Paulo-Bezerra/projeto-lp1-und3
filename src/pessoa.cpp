#include "../include/pessoa.hpp"

using namespace std;

// construtores da classe Pessoa
Pessoa::Pessoa(string nome, string cpf, string dataNascimento, string genero, Endereco endereco) {
  this->nome = nome;
  this->cpf = cpf;
  this->dataNascimento = dataNascimento;
  this->genero = genero;
  this->endereco.setRua(endereco.getRua());
  this->endereco.setNumero(endereco.getNumero());
  this->endereco.setBairro(endereco.getBairro());
  this->endereco.setCidade(endereco.getCidade());
  this->endereco.setCep(endereco.getCep());
}
Pessoa::Pessoa(){}

// retorna o nome
string Pessoa::getNome() {
  return this->nome;
}

// retorna o cpf
string Pessoa::getCpf() {
  return this->cpf;
}

// retorna a data de nascimento
string Pessoa::getDataNascimento() {
  return this->dataNascimento;
}

// retorna o genero
string Pessoa::getGenero() {
  return this->genero;
}

// retorna um objeto endereco com os dados do endereço de pessoa
Endereco Pessoa::getEndereco() {
  return this->endereco;
}

// modifica o conteúdo de nome
void Pessoa::setNome(string nome) {
  this->nome = nome;
}

// modifica o conteúdo de cpf
void Pessoa::setCpf(string cpf) {
  this->cpf = cpf;
}

// modifica o conteúdo de dataNascimento
void Pessoa::setDataNascimento(string dataNacimento) {
  this->dataNascimento = dataNacimento;
}

// modifica o conteúdo de genero
void Pessoa::setGenero(string genero) {
  this->genero = genero;
}

// modifica o conteúdo de endereço, passando valor por valor
void Pessoa::setEndereco(string rua, int numero, string bairro, string cidade, string cep) {
  this->endereco.setRua(rua);
  this->endereco.setNumero(numero);
  this->endereco.setBairro(bairro);
  this->endereco.setCidade(cidade);
  this->endereco.setCep(cep);
}

// modifica o conteúdo de endereço, passando um objeto da classe Endereco
void Pessoa::setEndereco(Endereco endereco) {
  this->endereco.setRua(endereco.getRua());
  this->endereco.setNumero(endereco.getNumero());
  this->endereco.setBairro(endereco.getBairro());
  this->endereco.setCidade(endereco.getCidade());
  this->endereco.setCep(endereco.getCep());
}