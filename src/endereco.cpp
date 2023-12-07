#include "../include/endereco.hpp"

using namespace std;

// construtores de endereco
Endereco::Endereco(string rua, int numero, string bairro, string cidade, string cep) {
  this->rua = rua;
  this->numero = numero;
  this->bairro = bairro;
  this->cidade = cidade;
  this->cep = cep;
}
Endereco::Endereco(){}

// retorna a rua
string Endereco::getRua() {
  return this->rua;
}

// retorna o numero (da casa)
int Endereco::getNumero() {
  return this->numero;
}

// retorna o bairro
string Endereco::getBairro() {
  return this->bairro;
}

// retorna a cidade
string Endereco::getCidade() {
  return this->cidade;
}

// retorna o cep
string Endereco::getCep() {
  return this->cep;
}

// modifica o conteúdo de rua
void Endereco::setRua(string rua) {
  this->rua = rua;
}

// modifica o conteúdo de número (da casa)
void Endereco::setNumero(int numero) {
  this->numero = numero;
}

// modifica o conteúdo de bairro
void Endereco::setBairro(string bairro) {
  this->bairro = bairro;
}

// modifica o conteúdo de cidade
void Endereco::setCidade(string cidade) {
  this->cidade = cidade;
}

// modifica o conteúdo de cep
void Endereco::setCep(string cep) {
  this->cep = cep;
}

