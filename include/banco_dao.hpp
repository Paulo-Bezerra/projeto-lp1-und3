#ifndef BANCO_DAO_HPP
#define BANCO_DAO_HPP

#include "professor.hpp"
#include "tecnico_adm.hpp"
#include <vector>

// declaração da classe BancoDAO
class BancoDAO {
private:
  std::vector<Professor> professores;
  std::vector<TecnicoAdm> tecnicosAdm;

public:
  // construtor da classe BancoDAO
  BancoDAO();

  // função para cadastrar professores no BancoDAO
  void cadastrarProfessor(Professor professor);

  // função para cadastrar técnicos no BancoDAO
  void cadastrarTecnicoAdm(TecnicoAdm tecnicoAdm);

  // função para listar professores no BancoDAO
  void listarProfessores();

  // função para listar técnicos no BancoDAO
  void listarTecnicosAdm();

  // função para deletar professores no BancoDAO
  void deletarProfessor(std::string matricula);

  // função para deletar técnicos no BancoDAO
  void deletarTecnicoAdm(std::string matricula);

  // função que retorna um objeto professor com os dados de resultado da busca
  Professor buscarProfessor(std::string matricula);

  // função que retorna um objeto tecnico com os dados de resultado da busca
  TecnicoAdm buscarTecnicoAdm(std::string matricula);

  // função que deve ser chamada para inicialzar os vectors da classe com os dados dos arquivos
  void carregarBanco();

  // função que deve ser chamada para gravar os dados dos vectors da classe nos arquivos
  void salvarBanco();

protected:
  // função que busca o índice no vector correspondente ao professor cadastrado
  int indiceProfessor(std::string matricula);
  
  // função que busca o índice no vector correspondente ao técnico cadastrado
  int indiceTecnicoAdm(std::string matricula);

  // função que ler os dados de professores.txt e salva em no atributo professores 
  void carregarProfessores();

  // função que ler os dados de tecnicos_adm.txt e salva em no atributo tecnicosAdm
  void carregarTecnicos();

  // função que salva os dados do atributo professores em professores.txt
  void salvarProfessores();

  // função que salva os dados do atributo tecnicosAdm em tecnicos_adm.txt
  void salvarTecnicos();
};

#endif


