#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <string>

#include "Estabelecimento.h"
#include "VectorSupermercado.h"
#include "Cardapio.h"
#include "Cliente.h"

class Cliente;

class Restaurante: public Estabelecimento{

public:

	Vector_Supermercado <Cardapio> cardapio;

 	Restaurante(int totalVendas = 0, double receitaTotal = 0.0, int size = 5);


 	void ListarProdutos();

 	bool venda(std::string nomeProduto, int quantidade, Cliente& cliente);
 	bool caixa();
 	bool SalvarVendas();
 	bool CarregarCardapio();
 	

};

#endif