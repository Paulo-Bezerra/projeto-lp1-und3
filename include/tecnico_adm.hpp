#ifndef TECNICO_ADM_HPP
#define TECNICO_ADM_HPP

#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

// declaração da classe TecnicoAdm que herda de Pessoa e Funcionario
class TecnicoAdm : public Pessoa, public Funcionario {
private:
  float adicionalProdutividade = 0.25;
  std::string funcaoDesempenhada;
public:
  // construtores da classe TecnicoAdm
  TecnicoAdm(Pessoa pessoa, Funcionario funcionario, std::string funcaoDesempenhada);
  TecnicoAdm();

  // retorna o adcional de produtividade
  float getAdicionalProdutividade();

  // retorna a função desempenhada
  std::string getFuncaoDesempenhada();

  // modifica o adiconal de produtividade de acordo com o float passado 
  void setAdicionalProdutividade(float adicionalProdutividade);

  // modifica a função desempenhada de acordo com a string passada
  void setFuncaoDesempenhada(std::string funcaoDesempenhada);
};

#endif