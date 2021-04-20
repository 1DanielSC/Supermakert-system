#ifndef CARDAPIO_H
#define CARDAPIO_H

#include <string>

class Cardapio
{
private:
	std::string NomeProduto;
	double Preco;
	int QuantidadeVendidos;

public:
	Cardapio(std::string nomeProduto = "None", double preco = 0.0, int quantidadeVendidos = 0);

	void setNomeProduto(std::string nomeProduto);
	void setPreco(double preco);
	void setQuantidadeVendidos(int quantidadeVendidos);

	std::string getNomeProduto();
	double getPreco();
	int getQuantidadeVendidos();
	
};

#endif