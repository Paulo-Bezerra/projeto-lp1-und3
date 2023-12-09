#include "../include/cadastro.hpp"
#include <iostream>
#include <algorithm>
#include "../include/erros.hpp"

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

  do {
    cout
      << "╠══════════════╗" << endl
      << "║ Qualificação ║" << endl
      << "╠══════════════╝" << endl
      << "║ Legenda: {GRADUACAO = 1, ESPECIALIZACAO = 2, MESTRADO = 3, DOUTORADO = 4}" << endl
      << "║ Formação do(a) professor(a): ";
    cin >> formacaoProfessor;

    try {
      if (formacaoProfessor < 1 || formacaoProfessor > 4) {
          throw ErroQualificacao("Qualificação incorreta. Digite a qualificação de acordo com a legenda, de 1 a 4\n");
      }
    } catch (ErroQualificacao& e) {
      std::cout << e.what() << std::endl;
      continue;
    }
    break;
  } while (true);

  do {
    cout 
      << "╟——————————" << endl
      << "║ Legenda: {I = 1, II = 2, III = 3, IV = 4, V = 5, VI = 6, VII = 7, VIII = 8}" << endl
      << "║ Nível do(a) professor(a): ";
    cin >> nivelProfessor;

    try {
      if (nivelProfessor < 1 || nivelProfessor > 8) {
          throw ErroNivel("Nível incorreto. Digite o nível de acordo com a legenda, de 1 a 8\n");
      }
    } catch (ErroNivel& e) {
      std::cout << e.what() << std::endl;
      continue;
    }
    break;
  } while (true);

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

  do {
    cout 
      << "╟——————————" << endl
      << "║ CPF: ";
    cin >> bufferString;
    try {
      if (bufferString.length() != 11 || !std::all_of(bufferString.begin(), bufferString.end(), ::isdigit)) {
        throw ErroCPF("\nCPF incorreto. Digite um CPF válido com 11 dígitos numéricos\n");
      }
      break;
    } catch (ErroCPF& e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  p.setCpf(bufferString);

  do {
    cout 
      << "╟——————————" << endl
      << "║ Data de nascimento: ";
    cin >> bufferString;
    try {
      int dia, mes, ano;
      if (sscanf(bufferString.c_str(), "%d/%d/%d", &dia, &mes, &ano) != 3 || dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2005) {
        throw ErroDataNascimento("\nData de nascimento incorreta. Digite a data de nascimento no formato DD/MM/AAAA, onde DD é o dia (01-31), MM é o mês (01-12) e AAAA é o ano (1900-2005)\n");
      }
      break;
    } catch (ErroDataNascimento& e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  p.setDataNascimento(bufferString);

  do {
    cout 
      << "╟——————————" << endl
      << "║ Gênero: ";
    cin >> bufferString;
    try {
      if (bufferString != "masculino" && bufferString != "feminino" && bufferString != "outros") {
        throw ErroGenero("\nGênero incorreto. Digite 'masculino', 'feminino' ou 'outros'\n");
      }
      break;
    } catch (ErroGenero& e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
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

        do {
          cout 
            << "╟——————————" << endl
            << "║ Número: ";
          cin >> bufferInt;
          try {
            if (bufferInt < 1 || bufferInt > 99999) {
              throw ErroNumero("\nNúmero incorreto. Digite um número válido entre 1 e 99999\n");
            }
            break;
          } catch (ErroNumero& e) {
            std::cout << e.what() << std::endl;
          }
        } while (true);
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

        do {
          cout 
            << "╟——————————" << endl
            << "║ CEP: ";
          cin >> bufferString;
          try {
            if (bufferString.length() != 8 || !std::all_of(bufferString.begin(), bufferString.end(), ::isdigit)) {
              throw ErroCEP("\nCEP incorreto. Digite um CEP válido com 8 dígitos numéricos\n");
            }
            break;
          } catch (ErroCEP& e) {
            std::cout << e.what() << std::endl;
          }
        } while (true);
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
        << "╠══════════════════╝" << endl;

      do {
        cout << "║ Matrícula: ";
        cin >> bufferString;
        try {
          if (bufferString.length() != 10 || !std::all_of(bufferString.begin(), bufferString.end(), ::isdigit)) {
            throw ErroMatricula("\nMatrícula incorreta. Digite uma matrícula válida com 10 dígitos numéricos\n");
          }
          break;
        } catch (ErroMatricula& e) {
          std::cout << e.what() << std::endl;
        }
      } while (true);
      f.setMatricula(bufferString);

      do {
        cout 
          << "╟——————————" << endl
          << "║ Salário: ";
        cin >> bufferFloat;
        try {
          if (bufferFloat < 1320.0 || bufferFloat > 44008.52) {
            throw ErroSalario("\nSalário incorreto. Digite um salário válido entre 1320,00 e 44.008,52\n");
          }
          break;
        } catch (ErroSalario& e) {
          std::cout << e.what() << std::endl;
        }
      } while (true);
      f.setSalario(bufferFloat);

      cout 
        << "╟——————————" << endl
        << "║ Departamento: ";
      cin.ignore();
      getline(cin, bufferString);
      f.setDepartamento(bufferString);

      do {
        cout 
          << "╟——————————" << endl
          << "║ Carga horária: ";
        cin >> bufferInt;
        try {
          if (bufferInt < 20 || bufferInt > 44) {
            throw ErroCargaHoraria("\nCarga horária incorreta. Digite uma carga horária válida entre 20h e 44h\n");
          }
          break;
        } catch (ErroCargaHoraria& e) {
          std::cout << e.what() << std::endl;
        }
      } while (true);
      f.setCargaHoraria(bufferInt);

      do {
        cout 
          << "╟——————————" << endl
          << "║ Data de ingresso: ";
        cin >> bufferString;
        try {
          int dia, mes, ano;
          if (sscanf(bufferString.c_str(), "%d/%d/%d", &dia, &mes, &ano) != 3 || dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1990 || ano > 2023) {
            throw ErroDataIngresso("\nData de ingresso incorreta. Digite a data de ingresso no formato DD/MM/AAAA, onde DD é o dia (01-31), MM é o mês (01-12) e AAAA é o ano (1990-2023)\n");
          }
          break;
        } catch (ErroDataIngresso& e) {
          std::cout << e.what() << std::endl;
        }
      } while (true);
      f.setDataIngresso(bufferString);

      return f;
    }