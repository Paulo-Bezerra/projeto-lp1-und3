#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include "../include/endereco.hpp"

// declaração da classe Pessoa
class Pessoa {
private:
  std::string nome;
  std::string cpf;
  std::string dataNascimento;
  std::string genero;
  Endereco endereco;

public:
  // construtores da classe Pessoa
  Pessoa(std::string nome, std::string cpf, std::string dataNascimento, std::string genero, Endereco endereco);
  Pessoa();

  // retorna o nome
  std::string getNome();

  // retorna o cpf
  std::string getCpf();

  // retorna a data de nascimento
  std::string getDataNascimento();

  // retorna o genero
  std::string getGenero();

  // retorna um objeto endereco com os dados do endereço de pessoa
  Endereco getEndereco();

  // modifica o conteúdo de nome
  void setNome(std::string nome);

  // modifica o conteúdo de cpf
  void setCpf(std::string cpf);

  // modifica o conteúdo de dataNascimento
  void setDataNascimento(std::string dataNascimento);

  // modifica o conteúdo de genero
  void setGenero(std::string genero);

  // modifica o conteúdo de endereço, passando valor por valor
  void setEndereco(std::string rua, int numero, std::string bairro, std::string cidade, std::string cep);

  // modifica o conteúdo de endereço, passando um objeto da classe Endereco
  void setEndereco(Endereco endereco);
};

#endif