#include "Estabelecimento.h"


Estabelecimento::Estabelecimento(int numVendas, double receita)
	:TotalVendas{numVendas}, ReceitaTotal{receita}
	{}

void Estabelecimento::setTotalVendas(int totalVendas) {this->TotalVendas += totalVendas;}
void Estabelecimento::setReceitaTotal(double receitaTotal) {this->ReceitaTotal += receitaTotal;}


int Estabelecimento::getTotalVendas() {return this->TotalVendas;}
double Estabelecimento::getReceitaTotal() {return this->ReceitaTotal;}