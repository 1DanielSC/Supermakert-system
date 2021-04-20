#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H 

#include <string>


#include "VectorSupermercado.h"
#include "Cliente.h"
#include "Produto.h"
#include "Estabelecimento.h"

class Cliente;
class Estabelecimento;

class Supermercado: public Estabelecimento{

public:
	Vector_Supermercado <Produto> ProdutosSupermercado;

	Supermercado(int totalVendas = 0, double receitaTotal = 0.0, int size = 5);

	bool CarregarProdutos();
	void ListarProdutos();

	bool venda(std::string codigo_produto, Cliente& cliente);
	bool caixa();

	bool SalvarVendas();
	bool AtualizarEstoque();

	bool reabastecer(Produto& produto_reabastecimento);	

};

#endif