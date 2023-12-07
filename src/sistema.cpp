#include "../include/sistema.hpp"
#include <iostream>

using namespace std;

// função que concentra o funcionamento da parte interativa e controle do fluxo do algoritmo
void execucao() {
  // objeto do BancoDAO usado para gerenciar os funcionáios no programa
  BancoDAO dados;
  Professor p;
  TecnicoAdm t;
  int opcao = -1, indice = -1;
  string matricula;

  // carregando dados dos arquivos
  dados.carregarBanco();

  // laço que controla a repetição no fluxo
  do {
    // recebe a opção selecionada pelo usuário
    opcao = menuPrincipal();

    switch (opcao) {
      // caso escolha sair
    case 0:
      cout
        << "╠═══════════════╗" << endl
        << "║ Encerrando... ║" << endl
        << "╚═══════════════╝" << endl;
      break;
      // caso escolha cadastrar um professor
    case 1:
      dados.cadastrarProfessor(formularioCadastrarProfessor());
      break;
// caso escolha cadatrar um técnico
    case 2:
      dados.cadastrarTecnicoAdm(formularioCadastrarTecnicoAdm());
      break;
      // caso escolha listar os professores
    case 3:
      dados.listarProfessores();
      break;
      // caso escolha listar os técnicos
    case 4:
      dados.listarTecnicosAdm();
      break;
      // caso escolhaca excluir um professor
    case 5:
      cout
        << "╔══════════════════════╗" << endl
        << "║ Deletar professor(a) ║" << endl
        << "╠══════════════════════╝" << endl
        << "║ Informe a matrícula do(a) professor(a) a ser deletado(a): ";
      cin >> matricula;
      dados.deletarProfessor(matricula);
      break;
      // caso escolha excluir técnico
    case 6:
      cout
        << "╔═══════════════════════════════════╗" << endl
        << "║ Deletar técnico(a) administrativo ║" << endl
        << "╠═══════════════════════════════════╝" << endl
        << "║ Informe a matrícula do(a) técnico(a) a ser deletado(a): ";
      cin >> matricula;
      dados.deletarTecnicoAdm(matricula);
      break;
      // caso escolha buscar um professor
    case 7:
      cout
        << "╔═════════════════════╗" << endl
        << "║ Buscar professor(a) ║" << endl
        << "╠═════════════════════╝" << endl
        << "║ Informe a matrícula do(a) professor(a) que deseja buscar: ";
      cin >> matricula;
      p = dados.buscarProfessor(matricula);
      //verificandpo se a matrícula consta no BancoDAO
      if (t.getMatricula() == "invalida") {
        cout
          << "╠═════════════════════╗" << endl
          << "║ Matrícula inválida! ║" << endl
          << "╚═════════════════════╝" << endl;
        break;
      }
      cout
        << "╔══════════════════════════╗" << endl
        << "║ Dados do(a) professor(a) ║" << endl
        << "╠══════════════════════════╝" << endl
        << "║ Nome: " << p.getNome() << ", CPF: " << p.getCpf() << ", data de nascimento: " << p.getDataNascimento() << ", genero: " << p.getGenero() << endl
        << "║ Rua: " << p.getEndereco().getRua() << ", endereço: " << p.getEndereco().getNumero() << ", bairro: " << p.getEndereco().getBairro() << ", cidade: " << p.getEndereco().getCidade() << ", CEP: " << p.getEndereco().getCep() << endl
        << "║ Matrícula: " << p.getMatricula() << ", salário: R$ " << p.getSalario() << ", departamento: " << p.getDepartamento() << ", carga horaria: " << p.getCargaHoraria() << ", data de ingresso: " << p.getDataIngresso() << endl
        << "║ Formação: " << p.getFormacaoProfessor() << ", nível: " << p.getNivelProfessor() << endl
        << "╙——————————" << endl;
      break;
    // caso escolha buscar técnico
    case 8:
      cout
        << "╔══════════════════════════════════╗" << endl
        << "║ Buscar técnico(a) administrativo ║" << endl
        << "╠══════════════════════════════════╝" << endl
        << "║ Informe a matrícula do(a) técnico(a) que deseja buscar: ";
      cin >> matricula;
      t = dados.buscarTecnicoAdm(matricula);
      //verificandpo se a matrícula consta no BancoDAO
      if (t.getMatricula() == "invalida") {
        cout
          << "╠═════════════════════╗" << endl
          << "║ Matrícula inválida! ║" << endl
          << "╚═════════════════════╝" << endl;
        break;
      }
      cout
        << "╔═══════════════════════════════════════╗" << endl
        << "║ Dados do(a) técnico(a) administrativo ║" << endl
        << "╠═══════════════════════════════════════╝" << endl
        << "║ Nome: " << t.getNome() << ", CPF: " << t.getCpf() << ", data de nascimento: " << t.getDataNascimento() << ", genero: " << t.getGenero() << endl
        << "║ Rua: " << t.getEndereco().getRua() << ", endereço: " << t.getEndereco().getNumero() << ", bairro: " << t.getEndereco().getBairro() << ", cidade: " << t.getEndereco().getCidade() << ", CEP: " << t.getEndereco().getCep() << endl
        << "║ Matrícula: " << t.getMatricula() << ", salário: R$ " << t.getSalario() << ", departamento: " << t.getDepartamento() << ", carga horaria: " << t.getCargaHoraria() << ", data de ingresso: " << t.getDataIngresso() << endl
        << "║ Função desempenhada: " << t.getFuncaoDesempenhada() << ", adcional de profutividade: " << t.getAdicionalProdutividade() << endl
        << "╙——————————" << endl;
      break;
      // caso seja digitado um número que não conste no menu
    default:
      cout
        << "╠═════════════════╗" << endl
        << "║ Opção inválida! ║" << endl
        << "╚═════════════════╝" << endl;
      break;
    }
  } while (opcao != 0);

  dados.salvarBanco();
}