#include "VectorSupermercado.h"
#include "Estabelecimento.h"
#include "Fornecedor.h"
#include "Produto.h"
#include "Supermercado.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Fornecedor::Fornecedor(int size): ProdutosFornecedor{size} 
{
	try{
		this->carregarProdutos();
	}
	catch(bool &exception){
		std::cerr << "Erro ao carregar os produtos do fornecedor" << std::endl;
	}
}

bool Fornecedor::carregarProdutos()
{
	std::ifstream file;
	file.open("fornecedor.csv");

	if (file.is_open())
	{
		std::string line;
		Produto produto;

		getline(file, line); //Evitar a primeira linha

		while(!file.eof())
		{
			getline(file, line, ',');

			if (line.size() == 0) 
			{
				break; //Evitar linha sem o nome do produto
			}

			produto.NomeProduto = line;

			getline(file, line, '\n');
			std::stringstream buffer(line);
			buffer >> produto.Quantidade;

			this->ProdutosFornecedor.push_back(produto);
		}

		std::cout << "Produtos de fornecedor.csv carregados" << std::endl;
		return true;
	}


	std::cerr << "Nao foi possivel abrir o arquivo fornecedor.csv" << std::endl;
	throw(false);
}

void Fornecedor::listarProdutos()
{
	std::cout << "Produtos do fornecedor disponiveis: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < this->ProdutosFornecedor.size(); i++)
	{
		if (this->ProdutosFornecedor.elements[i].Quantidade > 0)
		{
			std::cout << "Nome: " << this->ProdutosFornecedor.elements[i].NomeProduto << " - Quantidade: " << this->ProdutosFornecedor.elements[i].Quantidade << std::endl;
		}
	}


}




bool Fornecedor::repassarProdutos(Supermercado& supermercado, std::string nomeProduto, int quantidadeProduto)
{
	Produto produto_reabastecimento;

	if (quantidadeProduto < 0){
		std::cerr << "Erro: Quantidade negativa de produtos" << std::endl;
		throw(false);
	}

	if (quantidadeProduto == 0){
		std::cerr << "Erro: Quantidade nula de produtos" << std::endl;
		throw(false);
	}


	for (int i = 0; i < this->ProdutosFornecedor.size(); i++)	
	{
		if (this->ProdutosFornecedor.elements[i].NomeProduto == nomeProduto)
		{
			if (this->ProdutosFornecedor.elements[i].Quantidade >= quantidadeProduto)
			{
				produto_reabastecimento.NomeProduto = nomeProduto;
				produto_reabastecimento.Quantidade = quantidadeProduto;

				this->ProdutosFornecedor.elements[i].Quantidade -= quantidadeProduto;


				return supermercado.reabastecer(produto_reabastecimento);

			}else{
				std::cerr << "Quantidade de produtos insuficiente para o abastecimento" << std::endl;
				throw(false);
			}
		}
	}

	std::cerr << "Produto nao encontrado" << std::endl;
	throw(false);

}





//Funcao que atualizar o arquivo fornecedor.csv
bool Fornecedor::atualizarFornecedor()
{
	std::ofstream file;
	file.open("fornecedor.csv");

	if (file.is_open())
	{
		file << "PRODUTO,QUANTIDADE" << std::endl;


		for (int i = 0; i < this->ProdutosFornecedor.size(); i++)
		{
			file << this->ProdutosFornecedor.elements[i].NomeProduto << "," << this->ProdutosFornecedor.elements[i].Quantidade << std::endl;
		}


		std::cout << "Arquivo fornecedor.csv atualizado com sucesso" << std::endl;
		return true;
	}

	std::cerr << "Erro ao atualizar o arquivo fornecedor.csv" << std::endl;
	throw(false);
}