#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Estabelecimento.h"
#include "Cliente.h"
#include "Produto.h"
#include "VectorSupermercado.h"
#include "Restaurante.h"
#include "Supermercado.h"


Cliente::Cliente(double saldo_inicial, int sizeSacola)
	:Saldo(saldo_inicial), Sacola(sizeSacola)
	{quantidadeClientes++;}

Cliente::~Cliente() {quantidadeClientes--;}	

int Cliente::quantidadeClientes = 0;


void Cliente::verSacola()
{
	
	if (this->Sacola.size() == 0)
	{
		std::cout << "Sacola vazia" << std::endl;
		return;
	}

	std::cout << "Produtos na sacola: " <<std::endl;
	std::cout << std::endl;

	for (int i = 0; i < this->Sacola.size(); i++){
		std::cout << Sacola.elements[i] << std::endl;
	}

}

bool Cliente::compra(std::string nome_produto, double preco, Supermercado& supermercado)
{
	std::string codigo_produto;

	if (this->Saldo < preco)
	{
		std::cerr << "Saldo insuficiente" << std::endl;
		throw(false);
	}
	

	for (int i = 0; i < supermercado.ProdutosSupermercado.size(); i++)
	{
		if (supermercado.ProdutosSupermercado.elements[i].NomeProduto == nome_produto)
		{
			codigo_produto = supermercado.ProdutosSupermercado.elements[i].Codigo;
			return supermercado.venda(codigo_produto, *this);

		}
	}

	std::cerr << "Produto nao encontrado" << std::endl;
	throw(false);

}



bool Cliente::compra(std::string nomeProduto, int quantidade, Restaurante& restaurante)
{
	for (int i = 0; i < restaurante.cardapio.size(); i++)
	{
		if (restaurante.cardapio.elements[i].getNomeProduto() == nomeProduto)
		{
			if (this->Saldo >= restaurante.cardapio.elements[i].getPreco() * quantidade){
				return restaurante.venda(nomeProduto, quantidade, *this);
			}

			else{
				std::cerr << "Saldo insuficiente" << std::endl;
				throw(false);
			}
		}
	}
	std::cerr << "Produto nao encontrado" << std::endl;
	throw(false);
}



void Cliente::AdicionarSaldo(double valor)
{
	std::cout << std::endl;

	std::cout << "Saldo anterior: " << this->Saldo << std::endl;
	this->Saldo += valor;
	
	std::cout << "Saldo adicionado!" << std::endl;
	std::cout << "Novo saldo: " << this->Saldo << std::endl;
}



bool Cliente::registro(std::string loja)
{
	std::stringstream buffer;
	buffer << this->quantidadeClientes;

	std::string filename;
	filename = "cliente_" + loja + "_" + buffer.str() + ".txt";

	std::ofstream file;
	file.open(filename);

	if (file.is_open())
	{
		
		for (int i = 0; i < this->Sacola.size(); i++)
		{
			file << this->Sacola.elements[i] << std::endl;
		}

		return true;
	}

	throw(false);
}