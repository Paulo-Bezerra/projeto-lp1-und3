#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "../include/professor.hpp"
#include "../include/tecnico_adm.hpp"

// Exibe o formulário para cadastra o professor e gera o objeto, o qual é retornado
Professor formularioCadastrarProfessor();

// Exibe o formulário para cadastra o tecnico e gera o objeto, o qual é retornado
TecnicoAdm formularioCadastrarTecnicoAdm();

// Exibe o formulário para cadastra a pessoa e gera o objeto, o qual é retornado
Pessoa formularioCadastrarPessoa() ;

// Exibe o formulário para cadastra o endereço e gera o objeto, o qual é retornado
Endereco formularioCadastrarEndereco();

// Exibe o formulário para cadastra o funcinário e gera o objeto, o qual é retornado
Funcionario formularioCadastrarFuncionario();

#endif