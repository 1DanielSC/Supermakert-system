#include "App.h"
#include "Cliente.h"
#include "Fornecedor.h"
#include "Restaurante.h"
#include "Supermercado.h"
#include "Estabelecimento.h"

#include <iostream>
#include <string>
#include <vector>


int App::run()
{
	SelecionarModo();
	return 0;
}


void App::SelecionarModo()
{
	std::cout << std::endl;
	std::cout << "Opcoes do programa: " <<  std::endl;
	std::cout << std::endl;
	std::cout << "1 - Supermercado" << std::endl;
	std::cout << "2 - Restaurante" << std::endl;
	std::cout << std::endl;

	int opcao;
	std::cout << "Digite a opcao: ";
	std::cin >> opcao;
	std::cin.ignore();

	switch(opcao)
	{
		case 1:
		{
			Supermercado supermercado;
			Fornecedor fornecedor;

			std::vector<Cliente*> clientes;
			clientes.push_back(new Cliente());

			return MenuInterativo_Supermercado(clientes, supermercado, fornecedor);
		}

		case 2:
		{
			Restaurante restaurante;

			std::vector<Cliente*> clientes;
			clientes.push_back(new Cliente());

			return MenuInterativo_Restaurante(clientes, restaurante);
		}

		default:
			std::cout << "Opcao invalida!" << std::endl;
			break;
	}
}


void App::MenuInterativo_Supermercado(std::vector<Cliente*>& clientes, Supermercado& supermercado, Fornecedor& fornecedor)
{
	while(true)
	{
		std::cout << std::endl;
		std::cout << "Escolha a opcao: " << std::endl;
		std::cout << std::endl;
		std::cout << "1 - Comprar produto" << std::endl;
		std::cout << "2 - Mostrar sacola" << std::endl;
		std::cout << "3 - Adicionar saldo" << std::endl;
		std::cout << "4 - Listar produtos da loja" << std::endl;
		std::cout << "5 - Mostrar os produtos vendidos e o total ganho da loja" << std::endl;
		std::cout << "6 - Inicializar outro cliente" << std::endl;
		std::cout << "7 - Reabastecer o estoque" << std::endl;
		std::cout << "8 - Listar os produtos do fornecedor" << std::endl;
		std::cout << "0 - Sair do programa" << std::endl;
		std::cout << std::endl;


		int opcao;
		std::cout << "Digite a sua opcao: ";
		std::cin >> opcao;
		std::cin.ignore();

		switch(opcao)
		{
			case 1:
    		{
				std::string codigo_produto;
				std::cout << "Digite o nome do produto: ";
				getline(std::cin, codigo_produto);

				double preco;
				std::cout << "Digite o preco do produto: ";
				std::cin >> preco;
				std::cin.ignore();

				try{
					clientes.back()->compra(codigo_produto, preco, supermercado);
				}
				catch(bool &exception){
					std::cerr << "Nao foi possivel realizar a compra" << std::endl;
				}

				break;
    		}

			case 2: clientes.back()->verSacola(); break;

			case 3:
    		{
				double valor;
				std::cout << "Digite o saldo a ser acrescentado: ";
				std::cin >> valor;
				std::cin.ignore();

				clientes.back()->AdicionarSaldo(valor);
				break;
    		}
			case 4:	
    			
    			supermercado.ListarProdutos();
				break;
    		
    		case 5:

    			try{
    				supermercado.caixa();
    			}
    			catch(bool &exception){
    				std::cerr << "Nao foi possivel abrir o arquivo CaixaSupermercado.csv" << std::endl;
    			}

    			break;

			case 6:
    		{
    			try{
    				clientes.back()->registro("Supermercado");
    			}

    			catch(bool &exception){
    				std::cerr << "Erro ao criar o arquivo de registro do cliente" << std::endl;
    			}
				

				clientes.push_back(new Cliente());
				break;
    		}

    		case 7:
    		{
    			std::string nomeProduto;
    			std::cout << "Digite o nome do produto a ser reabastecido: ";
    			getline(std::cin, nomeProduto);

    			int quantidadeProduto;
    			std::cout << "Digite a quantidade: ";
    			std::cin >> quantidadeProduto;
    			std::cin.ignore();

    			try{
    				fornecedor.repassarProdutos(supermercado, nomeProduto, quantidadeProduto);
    			}
    			catch(bool &exception){
    				std::cerr << "Nao foi possivel repassar o produto" << std::endl;
    			}

    			break;
    		}

    		case 8:
    			fornecedor.listarProdutos();
    			break;
			
			case 0:
    		{
    			try{
    				clientes.back()->registro("Supermercado");
    			}
    			catch(bool &exception){
    				std::cerr << "Nao foi possivel criar o arquivo regristro do cliente" <<std::endl;
    			}
			
				for(auto& cliente: clientes){
					delete cliente;
				}
				
				clientes.clear();

				try{
					supermercado.AtualizarEstoque();
				}
				catch(bool &exception){
					std::cerr << "Erro ao atualizar o estoque do supermercado" <<std::endl;
				}

				try{
					fornecedor.atualizarFornecedor();
				}
				catch(bool &exception){
					std::cerr << "Erro ao atualizar o estoque do fornecedor" <<std::endl;
				}
				

				return;
    		}

    		default:
    			std::cout << "Opcao invalida!" <<std::endl;
    			break;
		}

	}
}



void App::MenuInterativo_Restaurante(std::vector<Cliente*>& clientes, Restaurante& restaurante)
{
	while(true)
	{
		std::cout << std::endl;
		std::cout << "Escolha a opcao: " << std::endl;
		std::cout << std::endl;
		std::cout << "1 - Comprar item do menu" << std::endl;
		std::cout << "2 - Adicionar saldo" << std::endl;
		std::cout << "3 - Listar itens do cardapio" << std::endl;
		std::cout << "4 - Mostrar os produtos vendidos e o total ganho do restaurante" << std::endl;
		std::cout << "5 - Inicializar outro cliente" << std::endl;
		std::cout << "0 - Sair do programa" << std::endl;
		std::cout << std::endl;


		int opcao;
		std::cout << "Digite a sua opcao: ";
		std::cin >> opcao;
		std::cin.ignore();

		switch(opcao)
		{
			case 1:
    		{
				std::string nomeProduto;
				std::cout << "Digite o nome do produto: ";
				getline(std::cin, nomeProduto);

				int quantidade;
				std::cout << "Digite a quantidade do produto: ";
				std::cin >> quantidade;

				std::cin.ignore();

				try{
					clientes.back()->compra(nomeProduto, quantidade, restaurante);
				}
				catch(bool &exception){
					std::cerr << "Nao foi possivel realizar a compra do produto" << std::endl;
				}
				
				break;
    		}

			case 2:
    		{
				double valor;
				std::cout << "Digite o saldo a ser acrescentado: ";
				std::cin >> valor;
				std::cin.ignore();

				clientes.back()->AdicionarSaldo(valor);
				break;
    		}
			case 3:	
				restaurante.ListarProdutos();
				break;
    		
    		case 4:

    			try{
    				restaurante.caixa();
    			}
    			catch(bool &exception){
    				std::cerr << "Nao foi possivel abrir o arquivo CaixaRestaurante.csv" << std::endl;
    			}

    			break;

			case 5:
    		{
				try{
    				clientes.back()->registro("Restaurante");
    			}
				catch(bool &exception){
					std::cerr << "Nao foi possivel criar o arquivo regristro do cliente" <<std::endl;
				}

				clientes.push_back(new Cliente());
				break;
    		}

			
			case 0:
    		{
    			try{
    				clientes.back()->registro("Restaurante");
    			}
				catch(bool &exception){
					std::cerr << "Nao foi possivel criar o arquivo regristro do cliente" <<std::endl;
				}

			
				for(auto& cliente: clientes){
					delete cliente;
				}

				clientes.clear();
				return;
    		}

    		default:
    			std::cout << "Opcao invalida!" <<std::endl;
    			break;
		}

	}
}
