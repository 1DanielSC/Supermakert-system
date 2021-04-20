#include "Estabelecimento.h"
#include "VectorSupermercado.h"
#include "Produto.h"
#include "Supermercado.h"
#include "Cliente.h"
#include "Fornecedor.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



Supermercado::Supermercado(int totalVendas, double receitaTotal, int size)
	:Estabelecimento{totalVendas, receitaTotal},  ProdutosSupermercado{size}
	{
		try{
			this->CarregarProdutos();
		}	
		catch(bool &exception){
			std::cerr << "Erro ao carregar os produtos do supermercado" << std::endl;
		}

	}



void Supermercado::ListarProdutos()
{

	std::cout << "Produtos disponiveis: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < this->ProdutosSupermercado.size(); i++)
	{
		if (this->ProdutosSupermercado.elements[i].Quantidade > 0)
		{
			std::cout << "Codigo: " << this->ProdutosSupermercado.elements[i].Codigo << std::endl;
			std::cout << "Produto: " << this->ProdutosSupermercado.elements[i].NomeProduto << std::endl;
			std::cout << "Unidade de Medida: " << this->ProdutosSupermercado.elements[i].UnidadeMedida << std::endl;
			std::cout << "Preco: " << this->ProdutosSupermercado.elements[i].Preco << std::endl;
			std::cout << "Quantidade: " << this->ProdutosSupermercado.elements[i].Quantidade << std::endl;
			std::cout << std::endl;
		}
	}
}



bool Supermercado::venda(std::string codigo_produto, Cliente& cliente)
{
	for (int i = 0; i < this->ProdutosSupermercado.size(); i++)
	{
		if (this->ProdutosSupermercado.elements[i].Codigo == codigo_produto && this->ProdutosSupermercado.elements[i].Quantidade > 0)
		{
			this->ProdutosSupermercado.elements[i].Quantidade--;
			this->ProdutosSupermercado.elements[i].QuantidadeVendidos++;

			cliente.Saldo -= this->ProdutosSupermercado.elements[i].Preco;

			this->setTotalVendas(1);
			this->setReceitaTotal(this->ProdutosSupermercado.elements[i].Preco);

			cliente.Sacola.push_back(this->ProdutosSupermercado.elements[i].NomeProduto);

			std::cout << "Venda efetuada!" << std::endl;
			
			try{
				this->SalvarVendas();
			}
			catch(bool &exception){
				std::cerr << "Erro ocorrido ao salvar a venda" << std::endl;
			}
			
			return true;
			
		}

		if (this->ProdutosSupermercado.elements[i].Codigo == codigo_produto && this->ProdutosSupermercado.elements[i].Quantidade <= 0)
		{
			std::cerr << "Nao ha mais este produto!" << std::endl;
			throw(false);
		}
	}

	std::cerr << "Produto nao encontrado!" << std::endl;
	throw(false);
}






bool Supermercado::CarregarProdutos()
{
	std::ifstream file;
	file.open("estoque.csv");

	if (file.is_open())
	{
		Produto extracao;

		std::string line;
		std::stringstream buffer;
		char discard;

		getline(file, line); //Evitar a primeira linha

		while(!file.eof())
		{
			getline(file, line, ',');

			if (line.size() == 0) //Evitar linhas em branco
			{
				continue;
			}

			extracao.Codigo = line;

			getline(file, line, ',');
			extracao.NomeProduto = line;


			getline(file, line, ',');
			extracao.UnidadeMedida = line;

			getline(file, line, ',');
			
			std::stringstream buffer_preco(line);
			buffer_preco >> discard;
			buffer_preco >> discard;
			
			buffer_preco >> extracao.Preco;

		
			getline(file, line, '\n');
			std::stringstream buffer_qtd(line);
			buffer_qtd >> extracao.Quantidade;

			this->ProdutosSupermercado.push_back(extracao);

		}

		std::cout << "Produtos do estoque.csv carregados com sucesso!" << std::endl;
		return true;
	}

	std::cerr << "Nao foi possivel carregar os produtos do estoque.csv" << std::endl;
	throw(false);
}


bool Supermercado::SalvarVendas()
{
	std::ofstream file;
	file.open("CaixaSupermercado.csv");


	if (file.is_open())
	{
		file << "Receita total: " << this->getReceitaTotal() << std::endl;
		file << "Total de vendas: " << this->getTotalVendas() << std::endl;
		file << "COD,PRODUTO,PRECO,QUANTIDADE VENDIDA" << std::endl;

		for (int i = 0; i < this->ProdutosSupermercado.size(); i++)
		{
			file << this->ProdutosSupermercado.elements[i].Codigo << "," << this->ProdutosSupermercado.elements[i].NomeProduto <<  "," << this->ProdutosSupermercado.elements[i].Preco << "," << this->ProdutosSupermercado.elements[i].QuantidadeVendidos << std::endl;
		}


		return true;
	}

	std::cerr << "Erro ao salvar a venda no arquivo CaixaSupermercado.csv" <<  std::endl;
	throw(false);
}




bool Supermercado::AtualizarEstoque()
{
	std::ofstream file;
	file.open("estoque.csv");

	if (file.is_open())
	{
		file << "COD,PRODUTO,UNIDADE DE MEDIDA,PRECO,QUANTIDADE" << std::endl;

		for (int i = 0; i < this->ProdutosSupermercado.size(); i++)
		{
			file << this->ProdutosSupermercado.elements[i].Codigo << "," << this->ProdutosSupermercado.elements[i].NomeProduto << "," << this->ProdutosSupermercado.elements[i].UnidadeMedida << ",R$ " << this->ProdutosSupermercado.elements[i].Preco << "," << this->ProdutosSupermercado.elements[i].Quantidade << std::endl;
		}

		std::cout << "Arquivo estoque.csv atualizado com sucesso" << std::endl;
		return true;
	}


	std::cerr << "Falha ao atualizar o arquivo do estoque" << std::endl;
	throw(false);
}

bool Supermercado::caixa()
{
	std::ifstream file;
	file.open("CaixaSupermercado.csv");

	if (file.is_open())
	{
		std::string line;
		std::string ProdutoVendido;
		int qtdVendidaProduto;

		getline(file, line); //Armazenar a primeira linha (contem a receita total)
		std::cout << line << " reais"<< std::endl;

		getline(file,line);//Armazenar a segunda linha (contem o total de vendas)
		std::cout << line << std::endl;


		while(!file.eof()){
			
			getline(file, line, ','); //Evitar o CODIGO do produto

			if (line.size() == 0) //Evitar linhas vazias
			{
				break;
			}

			getline(file, line, ','); //Armazenar o nome do produto em "line"
			ProdutoVendido = line;
			getline(file, line, ','); //Evitar o PRECO do produto

			getline(file, line, '\n'); //Armazenar a quantidade vendida em "line"
			std::stringstream buffer_quantidadeVendida (line);
			buffer_quantidadeVendida >> qtdVendidaProduto;

			if (qtdVendidaProduto > 0){
				std::cout << ProdutoVendido << " - Quantidade: " << qtdVendidaProduto << std::endl;
			}
		}

		return true;
	}
	std::cerr << "O arquivo CaixaSupermercado.csv nao existe" << std::endl;
	throw(false);
}


bool Supermercado::reabastecer(Produto& produto_reabastecimento)
{

	for (int i = 0; i < this->ProdutosSupermercado.size(); i++)
	{
		if (this->ProdutosSupermercado.elements[i].NomeProduto == produto_reabastecimento.NomeProduto)
		{
			this->ProdutosSupermercado.elements[i].Quantidade += produto_reabastecimento.Quantidade;
			std::cout << "Produto " << this->ProdutosSupermercado.elements[i].NomeProduto << " reabastecido com mais " << produto_reabastecimento.Quantidade << " unidade(s)" << std::endl;
			return true;
		}
	}

	std::cerr << "Nao foi possivel abastecer o produto" << std::endl;
	throw(false);
}