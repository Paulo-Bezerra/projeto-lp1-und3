#ifndef ERROS_HPP
#define ERROS_HPP

#include <exception>
#include <string>

// Define a classe ErroQualificacao que herda de std::exception
class ErroQualificacao : public std::exception {
private:
    std::string mensagem;  // Variável privada para armazenar a mensagem de erro
public:
    // Construtor que inicializa a mensagem de erro
    ErroQualificacao(const std::string& msg) : mensagem(msg) {}
    // Sobrescreve o método what() da classe base
    virtual const char* what() const throw() {
        return mensagem.c_str();  // Retorna a mensagem de erro como um array de caracteres
    }
};

// As classes abaixo seguem a mesma estrutura da classe ErroQualificacao

class ErroNivel : public std::exception {
private:
    std::string mensagem;
public:
    ErroNivel(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroCPF : public std::exception {
private:
    std::string mensagem;
public:
    ErroCPF(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroDataNascimento : public std::exception {
private:
    std::string mensagem;
public:
    ErroDataNascimento(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroGenero : public std::exception {
private:
    std::string mensagem;
public:
    ErroGenero(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroNumero : public std::exception {
private:
    std::string mensagem;
public:
    ErroNumero(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroCEP : public std::exception {
private:
    std::string mensagem;
public:
    ErroCEP(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroMatricula : public std::exception {
private:
    std::string mensagem;
public:
    ErroMatricula(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroSalario : public std::exception {
private:
    std::string mensagem;
public:
    ErroSalario(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroCargaHoraria : public std::exception {
private:
    std::string mensagem;
public:
    ErroCargaHoraria(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroDataIngresso : public std::exception {
private:
    std::string mensagem;
public:
    ErroDataIngresso(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

#endif // ERROS_HPP