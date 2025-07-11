#include <string>

class Pessoa {
  private:
    std::string nome;
  
  public:
    std::string getNome();
    void setNome(std::string nome);
};

std::string Pessoa::getNome() {
  return this->nome;
}

void Pessoa::setNome(std::string nome) {
  this->nome = nome;
}

/*
private members are accessible only from within other members of the same class.
protected members are accessible from other members of the same class, but also from members of their derived classes.
public members are accessible from anywhere where the object is visible.
*/
