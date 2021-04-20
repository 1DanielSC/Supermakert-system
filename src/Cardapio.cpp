#include "Cardapio.h"
#include <string>

Cardapio::Cardapio(std::string nomeProduto, double preco, int quantidadeVendidos)
	:NomeProduto{nomeProduto}, Preco{preco}, QuantidadeVendidos{quantidadeVendidos} {}

void Cardapio::setNomeProduto(std::string nomeProduto) {this->NomeProduto = nomeProduto;}
void Cardapio::setPreco(double preco) {this->Preco = preco;}
void Cardapio::setQuantidadeVendidos(int quantidadeVendidos) {this->QuantidadeVendidos += quantidadeVendidos;}

std::string Cardapio::getNomeProduto() {return this->NomeProduto;}
double Cardapio::getPreco() {return this->Preco;}
int Cardapio::getQuantidadeVendidos() {return this->QuantidadeVendidos;}