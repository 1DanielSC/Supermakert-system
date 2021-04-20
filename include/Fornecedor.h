#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "VectorSupermercado.h"
#include "Estabelecimento.h"
#include "Produto.h"
#include "Supermercado.h"
#include <string>

class Fornecedor
{
public:

	Vector_Supermercado<Produto> ProdutosFornecedor;

	Fornecedor(int size = 5);
	
	bool carregarProdutos();
	void listarProdutos();
	bool repassarProdutos(Supermercado& supermercado, std::string nomeProduto, int quantidadeProduto);
	bool atualizarFornecedor();
};

#endif