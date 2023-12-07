#ifndef ERROS_HPP
#define ERROS_HPP

#include <exception>
#include <string>

class ErroQualificacao : public std::exception {
private:
    std::string mensagem;
public:
    ErroQualificacao(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

class ErroNivel : public std::exception {
private:
    std::string mensagem;
public:
    ErroNivel(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const throw() {
        return mensagem.c_str();
    }
};

#endif // ERROS_HPP
