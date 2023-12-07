#include "../include/menu.hpp"
#include <iostream>

using namespace std;

// exibe o menu com as opções do sistema e retorna a opção (o inteiro) selecionado
int menuPrincipal() {
  int opcao;
  cout
    << "╔═══════════════════════════════════════════════════════════╗" << endl
    << "║ Sistema de gerenciamento de empregados da empresa IMDCorp ║" << endl
    << "╠═══════════════════════════════════════════════════════════╣" << endl
    << "║                           Menu                            ║" << endl
    << "╠═══════════════════════════════════════════════════════════╣" << endl
    << "║ 1. Cadastrar professor(a)                                 ║" << endl
    << "║ 2. Cadastrar técnico(a) administrativo                    ║" << endl
    << "║ 3. Listar os professores                                  ║" << endl
    << "║ 4. Listar os técnicos administrativo                      ║" << endl
    << "║ 5. Deletar professor(a)                                   ║" << endl
    << "║ 6. Deletar técnico(a) administrativo                      ║" << endl
    << "║ 7. Buscar professor(a)                                    ║" << endl
    << "║ 8. Buscar técnico(a) administrativo                       ║" << endl
    << "║ 0. Sair                                                   ║" << endl
    << "╠═══════════════════════════════════════════════════════════╝" << endl
    << "║ Selecione a opção desejada: ";
  cin >> opcao;
  // verifica se opção passada é válida
  if (opcao >= 0 && opcao <= 8) return opcao;

  return -1;
}
