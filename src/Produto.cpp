#include "Produto.h"

Produto::Produto(std::string code, std::string nome, std::string unidMedida, double preco, int qtd, int qtdVendidos)
	: Codigo{code}, NomeProduto{nome}, UnidadeMedida{unidMedida}, Preco{preco}, Quantidade{qtd}, QuantidadeVendidos {qtdVendidos} {}