#include "Estabelecimento.h"
#include "VectorSupermercado.h"
#include "Cardapio.h"
#include "Restaurante.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>


Restaurante::Restaurante(int totalVendas, double receitaTotal, int size)
	:Estabelecimento{totalVendas, receitaTotal}, cardapio{size}
	{
		try{
			this->CarregarCardapio();
		}
		catch(bool &exception){
			std::cerr << "Erro ao carregar o cardapio do restaurante" << std::endl;
		}

	}	

bool Restaurante::CarregarCardapio()
{
	std::ifstream file;
	file.open("menu.csv");

	if (file.is_open())
	{
		Cardapio item;

		double preco;
		std::string line;
		char discard;

		getline(file, line); //Ignorar a primeira linha

		while(!file.eof())
		{
			getline(file, line, ',');

			if (line.size() == 0){ //Evitar linhas em que nao haja o nome do produto
				continue;
			}

			item.setNomeProduto(line);


			getline(file, line, '\n');
			std::stringstream buffer_preco(line);
			buffer_preco >> discard;
			buffer_preco >> discard;
			buffer_preco >> preco;

			item.setPreco(preco);

			this->cardapio.push_back(item);
		}

		std::cout << "Itens do cardapio carregados!" << std::endl;
		return true;
	}

	throw(false);
}


void Restaurante::ListarProdutos()
{
	std::cout << "Produtos do cardapio: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < this->cardapio.size(); i++)
	{
		std::cout << "Produto: " << this->cardapio.elements[i].getNomeProduto() << std::endl;
		std::cout << "Preco: R$ " << this->cardapio.elements[i].getPreco() << std::endl;
		std::cout << std::endl;
	}
}

bool Restaurante::SalvarVendas()
{
	std::ofstream file;
	file.open("CaixaRestaurante.csv");

	if (file.is_open())
	{

		file << "Receita total: " << this->getReceitaTotal() << std::endl;
		file << "Total de vendas: " << this->getTotalVendas() << std::endl;
		file << "PRODUTO,PRECO,QUANTIDADE VENDIDA" << std::endl;

		for (int i = 0; i < this->cardapio.size(); i++)
		{
			file << this->cardapio.elements[i].getNomeProduto() <<  "," << this->cardapio.elements[i].getPreco() << "," << this->cardapio.elements[i].getQuantidadeVendidos() << std::endl;
		}


		return true;
	}

	std::cerr << "Erro ao salvar a venda no arquivo CaixaRestaurante.csv" <<  std::endl;
	throw(false);
}

bool Restaurante::venda(std::string nomeProduto, int quantidade, Cliente& cliente)
{

	if (quantidade < 0){
		std::cerr << "Erro: Quantidade negativa de produtos" << std::endl;
		throw(false);
	}

	if (quantidade == 0){
		std::cerr << "Erro: Quantidade nula de produtos" << std::endl;
		throw(false);
	}

	for (int i = 0; i < this->cardapio.size(); i++)
	{
		if (this->cardapio.elements[i].getNomeProduto() == nomeProduto)
		{
			cliente.Saldo -= this->cardapio.elements[i].getPreco() * quantidade; //Diminuir o saldo do cliente de acordo com a quantidade
			this->cardapio.elements[i].setQuantidadeVendidos(quantidade); //Atualizar a quantidade vendida do produto

			this->setTotalVendas(quantidade);
			this->setReceitaTotal(this->cardapio.elements[i].getPreco() * quantidade);


			for (int i = 0; i < quantidade; i++){
				cliente.Sacola.push_back(nomeProduto);
			}

			std::cout << "Venda efetuada!" << std::endl;

			try{
				this->SalvarVendas();
			}
			catch(bool &exception){
				std::cerr << "Erro ao salvar a venda no arquivo CaixaRestaurante.csv" << std::endl;
			}

			return true;
		}

	}

	std::cerr << "Produto nao encontrado!" << std::endl;
	throw(false);
}




bool Restaurante::caixa() //Listar os produtos vendidos, lê o arquivo CaixaRestaurante.csv
{
	std::ifstream file;
	file.open("CaixaRestaurante.csv");

	if (file.is_open())
	{
		std::string line;
		std::string ProdutoVendido;
		int qtdVendidaProduto;

		getline(file, line); //Armazenar a primeira linha (contem a receita total)
		std::cout << line << " reais"<< std::endl;

		getline(file,line);//Armazenar a segunda linha (contem o total de vendas)
		std::cout << line << std::endl;

		std::cout << "Produto(s) vendido(s) pelo restaurante:" << std::endl;
		std::cout << std::endl;

		while(!file.eof())
		{
			getline(file, line, ','); //Armazenar o nome do produto em "line"
			ProdutoVendido = line;

			if (ProdutoVendido.size() == 0) //Evitar linhas que nao contenham o nome do produto
			{
				break;
			}


			getline(file, line, ','); //Evitar o PRECO do produto

			getline(file, line, '\n'); //Armazenar a quantidade vendida em "line"
			std::stringstream buffer_quantidadeVendida (line);
			buffer_quantidadeVendida >> qtdVendidaProduto;

			if (qtdVendidaProduto > 0)
			{
				std::cout << ProdutoVendido << " - Quantidade: " << qtdVendidaProduto << std::endl;
			}

		}

		return true;
	}

	std::cerr << "Nao foi possivel abrir o arquivo CaixaRestaurante.csv" << std::endl;
	throw(false);
}