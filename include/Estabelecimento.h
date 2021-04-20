#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <string>


class Estabelecimento
{
private:
	int TotalVendas;
	double ReceitaTotal;

public:
	Estabelecimento(int numVendas = 0, double receita = 0.0);

	void setTotalVendas(int totalVendas);
	void setReceitaTotal(double receitaTotal);

	int getTotalVendas();
	double getReceitaTotal();

};

#endif