#include "../include/cadastro.hpp"
#include <iostream>

using namespace std;

// Exibe o formulário para cadastra o professor e gera o objeto, o qual é retornado
Professor formularioCadastrarProfessor() {
  Pessoa pessoa;
  Funcionario funcionario;
  int formacaoProfessor, nivelProfessor;

  cout
    << "╔════════════════════════╗" << endl
    << "║ Cadastrar professor(a) ║" << endl
    << "╠════════════════════════╝" << endl;
  pessoa = formularioCadastrarPessoa();
  funcionario = formularioCadastrarFuncionario();
  cout
    << "╠══════════════╗" << endl
    << "║ Qualificação ║" << endl
    << "╠══════════════╝" << endl
    << "║ Legenda: {GRADUACAO = 1, ESPECIALIZACAO = 2, MESTRADO = 3, DOUTORADO = 4}" << endl
    << "║ Formação do(a) professor(a): ";
  cin >> formacaoProfessor;
  cout 
    << "╟——————————" << endl
    << "║ Legenda: {I = 1, II = 2, III = 3, IV = 4, V = 5, VI = 6, VII = 7, VIII = 8}" << endl
    << "║ Nível do(a) professor(a): ";
  cin >> nivelProfessor;

  Professor professor(pessoa, funcionario, formacaoProfessor, nivelProfessor);

  return professor;
}

// Exibe o formulário para cadastra o tecnico e gera o objeto, o qual é retornado
TecnicoAdm formularioCadastrarTecnicoAdm() {
  Pessoa pessoa;
  Funcionario funcionario;
  string funcaoDesempenhada;

  cout
    << "╔════════════════════════════════════════╗" << endl
    << "║ Cadastrar de técnico(a) administrativo ║" << endl
    << "╠════════════════════════════════════════╝" << endl;
  pessoa = formularioCadastrarPessoa();
  funcionario = formularioCadastrarFuncionario();
  cout 
    << "╟——————————" << endl
    << "║ Função desempenhada: ";
  cin.ignore();
  getline(cin, funcaoDesempenhada);

  TecnicoAdm tecnicoAdm(pessoa, funcionario, funcaoDesempenhada);

  return tecnicoAdm;
}

// Exibe o formulário para cadastra a pessoa e gera o objeto, o qual é retornado
Pessoa formularioCadastrarPessoa() {
  Pessoa p;
  Endereco e;
  int bufferInt = 0;
  string bufferString = "";

  cout
    << "╠════════════════╗" << endl
    << "║ Dados possoais ║" << endl
    << "╠════════════════╝" << endl
    << "║ Nome: ";
  cin.ignore();
  getline(cin, bufferString);
  p.setNome(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ CPF: ";
  cin >> bufferString;
  p.setCpf(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ Data de nascimento: ";
  cin >> bufferString;
  p.setDataNascimento(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ Gênero: ";
  cin >> bufferString;
  p.setGenero(bufferString);
  e = formularioCadastrarEndereco();
  p.setEndereco(e.getRua(), e.getNumero(), e.getBairro(), e.getCidade(), e.getCep());

  return p;
}

// Exibe o formulário para cadastra a pessoa e gera o objeto, o qual é retornado
Endereco formularioCadastrarEndereco() {
  Endereco e;
  int bufferInt = 0;
  string bufferString = "";

  cout
    << "╠══════════╗" << endl
    << "║ Endereço ║" << endl
    << "╠══════════╝" << endl
    << "║ Rua: ";
  cin.ignore();
  getline(cin, bufferString);;
  e.setRua(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ Número: ";
  cin >> bufferInt;
  e.setNumero(bufferInt);
  cout 
    << "╟——————————" << endl
    << "║ Bairro: ";
  cin.ignore();
  getline(cin, bufferString);
  e.setBairro(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ Cidade: ";
  cin.ignore();
  getline(cin, bufferString);
  e.setCidade(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ CEP: ";
  cin >> bufferString;
  e.setCep(bufferString);

  return e;
}

// Exibe o formulário para cadastra o funcinário e gera o objeto, o qual é retornado
Funcionario formularioCadastrarFuncionario() {
  Funcionario f;
  int bufferInt = 0;
  float bufferFloat = 0.0;
  string bufferString = "";

  cout
    << "╠══════════════════╗" << endl
    << "║ Dados funcionais ║" << endl
    << "╠══════════════════╝" << endl
    << "║ Matrícula: ";
  cin >> bufferString;
  f.setMatricula(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ Salário: ";
  cin >> bufferFloat;
  f.setSalario(bufferFloat);
 cout 
    << "╟——————————" << endl
    << "║ Departamento: ";
  cin.ignore();
  getline(cin, bufferString);
  f.setDepartamento(bufferString);
  cout 
    << "╟——————————" << endl
    << "║ Carga horária: ";
  cin >> bufferInt;
  f.setCargaHoraria(bufferInt);
  cout 
    << "╟——————————" << endl
    << "║ Data de ingresso: ";
  cin >> bufferString;
  f.setDataIngresso(bufferString);

  return f;
}
