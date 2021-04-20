#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
public:
	Produto(std::string code = "None", std::string nome = "None", std::string unidMedida = "None", double preco = 0.0, int qtd = 0, int qtdVendidos = 0);
	
	
	std::string Codigo;
	std::string NomeProduto;
	std::string UnidadeMedida;
	double Preco;
	int Quantidade;

	int QuantidadeVendidos;
};

#endif