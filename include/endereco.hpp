#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <iostream>

// declaração da classe Endereco
class Endereco {
private:
  std::string rua;
  int numero;
  std::string bairro;
  std::string cidade;
  std::string cep;

public:
  // construtores da classe Endereco
  Endereco(std::string rua, int numero, std::string bairro, std::string cidade, std::string cep);
  Endereco();

  // retorna a rua
  std::string getRua();

  // retorna o numero (da casa)
  int getNumero();

  // retorna o bairro
  std::string getBairro();

  // retorna a cidade
  std::string getCidade();

  // retorna o cep
  std::string getCep();

  // modifica o conteúdo de rua
  void setRua(std::string rua);

  // modifica o conteúdo de número (da casa)
  void setNumero(int numero);

  // modifica o conteúdo de bairro
  void setBairro(std::string bairro);

  // modifica o conteúdo de cidade
  void setCidade(std::string cidade);

  // modifica o conteúdo de cep
  void setCep(std::string cep);
};

#endif