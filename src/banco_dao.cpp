#include "../include/banco_dao.hpp"
#include <iostream>
#include <fstream>

using namespace std;

BancoDAO::BancoDAO() {}

// função para cadastrar professores no BancoDAO
void BancoDAO::cadastrarProfessor(Professor professor) {
  this->professores.push_back(professor);

  cout
    << "╠═════════════════════════════════════════╗" << endl
    << "║ Professor(a) cadastrado(a) com sucesso! ║" << endl
    << "╚═════════════════════════════════════════╝" << endl;
}

// função para cadastrar técnicos no BancoDAO
void BancoDAO::cadastrarTecnicoAdm(TecnicoAdm tecnicoAdm) {
  this->tecnicosAdm.push_back(tecnicoAdm);

  cout
    << "╠══════════════════════════════════════════════════════╗" << endl
    << "║ Técnico(a) administrativo cadastrado(a) com sucesso! ║" << endl
    << "╚══════════════════════════════════════════════════════╝" << endl;
}

// função para listar professores no BancoDAO
void BancoDAO::listarProfessores() {
  cout
    << "╔═════════════════════════╗" << endl
    << "║ Professores cadastrados ║" << endl
    << "╠═════════════════════════╝" << endl;
  // copia cada um e imprime os dados
  for (Professor p : this->professores) {
    cout
      << "║ Nome: " << p.getNome() << ", CPF: " << p.getCpf() << ", data de nascimento: " << p.getDataNascimento() << ", genero: " << p.getGenero() << endl
      << "║ Rua: " << p.getEndereco().getRua() << ", endereço: " << p.getEndereco().getNumero() << ", bairro: " << p.getEndereco().getBairro() << ", cidade: " << p.getEndereco().getCidade() << ", CEP: " << p.getEndereco().getCep() << endl
      << "║ Matrícula: " << p.getMatricula() << ", salário: R$  " << p.getSalario() << ", departamento: " << p.getDepartamento() << ", carga horaria: " << p.getCargaHoraria() << ", data de ingresso: " << p.getDataIngresso() << endl
      << "║ Formação: " << p.getFormacaoProfessor() << ", nível: " << p.getNivelProfessor() << endl
      << "╙——————————" << endl;
  }
}

// função para listar técnicos no BancoDAO
void BancoDAO::listarTecnicosAdm() {
  cout
    << "╔═════════════════════════════════════════╗" << endl
    << "║ Técnicos(as) administrativo cadastrados ║" << endl
    << "╠═════════════════════════════════════════╝" << endl;
  // copia cada um e imprime os dados
  for (TecnicoAdm t : this->tecnicosAdm) {
    cout
      << "║ Nome: " << t.getNome() << ", CPF: " << t.getCpf() << ", data de nascimento: " << t.getDataNascimento() << ", genero: " << t.getGenero() << endl
      << "║ Rua: " << t.getEndereco().getRua() << ", endereço: " << t.getEndereco().getNumero() << ", bairro: " << t.getEndereco().getBairro() << ", cidade: " << t.getEndereco().getCidade() << ", CEP: " << t.getEndereco().getCep() << endl
      << "║ Matrícula: " << t.getMatricula() << ", salário: R$  " << t.getSalario() << ", departamento: " << t.getDepartamento() << ", carga horaria: " << t.getCargaHoraria() << ", data de ingresso: " << t.getDataIngresso() << endl
      << "║ Função desempenhada: " << t.getFuncaoDesempenhada() << ", adcional de profutividade: " << t.getAdicionalProdutividade() << endl
      << "╙——————————" << endl;
  }
}

// função para deletar professores no BancoDAO
void BancoDAO::deletarProfessor(string matricula) {
  // recebendo o indice correspondente a matricula
  int posDelete = indiceProfessor(matricula);
  if (posDelete == -1) {
    cout
      << "╠══════════════════════════════════════════════╗" << endl
      << "║ Matrícula não encotrada. Operação cancelada! ║" << endl
      << "╚══════════════════════════════════════════════╝" << endl;
  } else {
    // excluindo do vector
    this->professores.erase(this->professores.begin() + posDelete);
    cout
      << "╠═══════════════════════╗" << endl
      << "║ Excluído com sucesso! ║" << endl
      << "╚═══════════════════════╝" << endl;
  }
}
// função para deletar técnicos no BancoDAO
void BancoDAO::deletarTecnicoAdm(string matricula) {
  // recebendo o indice correspondente a matricula
  int posDelete = indiceTecnicoAdm(matricula);
  if (posDelete == -1) {
    cout
      << "╠══════════════════════════════════════════════╗" << endl
      << "║ Matrícula não encotrada. Operação cancelada! ║" << endl
      << "╚══════════════════════════════════════════════╝" << endl;
  } else {
    // excluindo do vector
    this->tecnicosAdm.erase(this->tecnicosAdm.begin() + posDelete);
    cout
      << "╠═══════════════════════╗" << endl
      << "║ Excluído com sucesso! ║" << endl
      << "╚═══════════════════════╝" << endl;
  }
}

// função que busca o índice no vector correspondente ao professor cadastrado
int BancoDAO::indiceProfessor(string matricula) {
  for (int i = 0; i < this->professores.size(); i++) {
    if (this->professores[i].getMatricula() == matricula) {
      return i;
    }
  }
  return -1;
}

// função que busca o índice no vector correspondente ao técnico cadastrado
int BancoDAO::indiceTecnicoAdm(string matricula) {
  for (int i = 0; i < this->tecnicosAdm.size(); i++) {
    if (this->tecnicosAdm[i].getMatricula() == matricula) {
      return i;
    }
  }
  return -1;
}

// função que retorna um objeto professor com os dados de resultado da busca
Professor BancoDAO::buscarProfessor(string matricula) {
  for (int i = 0; i < this->professores.size(); i++) {
    if (this->professores[i].getMatricula() == matricula) {
      return this->professores[i];
    }
  }

  // caso o prodessor não seja encotrado
  Professor p;
  p.setMatricula("invalida");
  return p;
}


TecnicoAdm BancoDAO::buscarTecnicoAdm(string matricula) {
  for (int i = 0; i < this->tecnicosAdm.size(); i++) {
    if (this->tecnicosAdm[i].getMatricula() == matricula) {
      return this->tecnicosAdm[i];
    }
  }

  // caso o técnico não seja encontrado 
  TecnicoAdm t;
  t.setMatricula("invalida");
  return t;
}

// função que deve ser chamada para inicialzar os vectors da classe com os dados dos arquivos
void BancoDAO::carregarBanco() {
  // chama a função para ler do arquivo professores.txt
  carregarProfessores();

  // chama a função para ler do arquivo tecnicos_adm.txt
  carregarTecnicos();
}

// função que ler os dados de professores.txt e salva em no atributo professores
void BancoDAO::carregarProfessores() {
  Professor p;
  Endereco e;

  // abrindo o aquivo em modo leitura
  fstream arq_prof;
  string buffer, path = "db/professores.txt";
  arq_prof.open(path, ios::in);

  // ler até não existe um próximo nome cadastrado
  while (getline(arq_prof, buffer)) {
    // lendo dados pessoais
    p.setNome(buffer);
    getline(arq_prof, buffer);
    p.setCpf(buffer);
    getline(arq_prof, buffer);
    p.setDataNascimento(buffer);
    getline(arq_prof, buffer);
    p.setGenero(buffer);

    // lendo o endereco
    getline(arq_prof, buffer);
    e.setRua(buffer);
    getline(arq_prof, buffer);
    e.setNumero(stoi(buffer));
    getline(arq_prof, buffer);
    e.setBairro(buffer);
    getline(arq_prof, buffer);
    e.setCidade(buffer);
    getline(arq_prof, buffer);
    e.setCep(buffer);
    p.setEndereco(e);

    // lendo os dados funcionais
    getline(arq_prof, buffer);
    p.setMatricula(buffer);
    getline(arq_prof, buffer);
    p.setSalario(stoi(buffer));
    getline(arq_prof, buffer);
    p.setDepartamento(buffer);
    getline(arq_prof, buffer);
    p.setCargaHoraria(stoi(buffer));
    getline(arq_prof, buffer);
    p.setDataIngresso(buffer);

    // lendo as qualificações
    getline(arq_prof, buffer);
    p.setFormacaoProfessor(stoi(buffer));
    getline(arq_prof, buffer);
    p.setNivelProfessor(stoi(buffer));

    // adicionando a professores do BancoDAO
    this->professores.push_back(p);
  }
  arq_prof.close();
}

void BancoDAO::carregarTecnicos() {
  TecnicoAdm t;
  Endereco e;

  // abrindo o aquivo em modo leitura
  fstream arq_tecn;
  string buffer, path = "db/tecnicos_adm.txt";
  arq_tecn.open(path, ios::in);

  // ler até não existe um próximo nome cadastrado
  while (getline(arq_tecn, buffer)) {
    // lendo dados pessoais
    t.setNome(buffer);
    getline(arq_tecn, buffer);
    t.setCpf(buffer);
    getline(arq_tecn, buffer);
    t.setDataNascimento(buffer);
    getline(arq_tecn, buffer);
    t.setGenero(buffer);

    // lendo o endereco
    getline(arq_tecn, buffer);
    e.setRua(buffer);
    getline(arq_tecn, buffer);
    e.setNumero(stoi(buffer));
    getline(arq_tecn, buffer);
    e.setBairro(buffer);
    getline(arq_tecn, buffer);
    e.setCidade(buffer);
    getline(arq_tecn, buffer);
    e.setCep(buffer);
    t.setEndereco(e);

    // lendo os dados funcionais
    getline(arq_tecn, buffer);
    t.setMatricula(buffer);
    getline(arq_tecn, buffer);
    t.setSalario(stoi(buffer));
    getline(arq_tecn, buffer);
    t.setDepartamento(buffer);
    getline(arq_tecn, buffer);
    t.setCargaHoraria(stoi(buffer));
    getline(arq_tecn, buffer);
    t.setDataIngresso(buffer);
    getline(arq_tecn, buffer);
    t.setFuncaoDesempenhada(buffer);
    // adicionando a professores do BancoDAO
    this->tecnicosAdm.push_back(t);
  }
  arq_tecn.close();
}

// função que deve ser chamada para gravar os dados dos vectors da classe nos arquivos
void BancoDAO::salvarBanco() {
  // chama a função para gravar os dados de professores no arquivo professores.txt
  salvarProfessores();

  // chama a função para gravar os dados de tecnicosAdm no arquivo tecnicos_adm.txt
  salvarTecnicos();
}

// função que salva os dados do atributo professores em professores.txt
void BancoDAO::salvarProfessores() {
  // abrindo o aquivo em modo de escrita
  fstream arq_prof;
  string path = "db/professores.txt";
  arq_prof.open(path, ios::out);

  // imprimi professor por professor no arquivo (um atributo por linha)
  for (Professor p : this->professores) {
    arq_prof
      << p.getNome() << endl
      << p.getCpf() << endl
      << p.getDataNascimento() << endl
      << p.getGenero() << endl
      << p.getEndereco().getRua() << endl
      << p.getEndereco().getNumero() << endl
      << p.getEndereco().getBairro() << endl
      << p.getEndereco().getCidade() << endl
      << p.getEndereco().getCep() << endl
      << p.getMatricula() << endl
      << p.getSalario() << endl
      << p.getDepartamento() << endl
      << p.getCargaHoraria() << endl
      << p.getDataIngresso() << endl
      << p.getFormacaoProfessor() << endl
      << p.getNivelProfessor() << endl;
  }
  arq_prof.close();
}

void BancoDAO::salvarTecnicos() {
// abrindo o aquivo em modo de escrita
  fstream arq_tecn;
  string path = "db/tecnicos_adm.txt";
  arq_tecn.open(path, ios::out);

  // imprimi técnico por técnico no arquivo (um atributo por linha)
  for (TecnicoAdm t : this->tecnicosAdm) {
    arq_tecn
      << t.getNome() << endl
      << t.getCpf() << endl
      << t.getDataNascimento() << endl
      << t.getGenero() << endl
      << t.getEndereco().getRua() << endl
      << t.getEndereco().getNumero() << endl
      << t.getEndereco().getBairro() << endl
      << t.getEndereco().getCidade() << endl
      << t.getEndereco().getCep() << endl
      << t.getMatricula() << endl
      << t.getSalario() << endl
      << t.getDepartamento() << endl
      << t.getCargaHoraria() << endl
      << t.getDataIngresso() << endl
      << t.getFuncaoDesempenhada() << endl;
  }
  arq_tecn.close();
}
