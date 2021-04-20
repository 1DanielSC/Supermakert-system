#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

#include "VectorSupermercado.h"
#include "Restaurante.h"
#include "Supermercado.h"

class Restaurante;
class Supermercado;

class Cliente
{
public:
	
	double Saldo;
	Vector_Supermercado<std::string> Sacola;
	static int quantidadeClientes;

	
	Cliente(double saldo_inicial = 50.0, int sizeSacola = 5);
	~Cliente();

	void AdicionarSaldo(double valor);

	void verSacola();
	bool compra(std::string nome_produto, double preco, Supermercado& supermercado);
	bool compra(std::string nomeProduto, int quantidade, Restaurante& restaurante);
	bool registro(std::string loja);

};

#endif