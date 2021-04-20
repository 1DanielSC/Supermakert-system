# LP1 2020.5 - Atividade avaliativa 06: Supermercado - Daniel Sehn Colao

## Comandos - Selecionar Modo (início do programa)

 * **1 - Supermercado**

      Comando para selecionar o modo `Supermercado` no programa.

 * **2 - Restaurante**

      Comando para selecionar o modo `Restaurante` no programa.


## Comandos - Menu Interativo Restaurante

 * **1 - Comprar item do menu**

      Comando para acionar a função `compra()` da classe `Cliente`.

      O usuário terá que digitar o nome da comida e sua quantidade.

 * **2 - Adicionar saldo**

      Comando para chamar a função `AdicionarSaldo()` da classe `Cliente`.

        Comando para adicionar mais saldo ao cliente atual.

        O usuario terá que digitar um valor para ser adicionado ao saldo.

        Obs.: O saldo inicial do cliente vale R$ 50.00.

 * **3 - Listar itens do cardapio**

      Comando para acionar a função `ListarProdutos()` da classe `Restaurante`.

                Será feita a listagem de todos os produtos do restaurante.

 * **4 - Mostrar os produtos vendidos e o total ganho do restaurante**

      Comando para chamar a função `caixa()` da classe `Restaurante`.

        Listagem de todos os produtos vendidos e a quantidade de dinheiro recebida pelo restaurante na atual execução do programa.


 * **5 - Inicializar outro cliente**
 
      Comando para encerrar as compras do cliente atual. 

      Um arquivo cliente_Restaurante_x.txt será criado com todos os itens comprados do cliente atual.

        'x' representa o numero do cliente.

      Após isso, um novo cliente é criado.


 * **0 - Sair do programa**

      Comando para sair do programa.

      A função `registro()` será ativada para o último cliente instanciado.





## Comandos - Menu Interativo Supermercado

 * **1 - Comprar produto**
 
      Comando para chamada da função `compra` da classe `Cliente`.

        Apos digitar o comando '1', o usuario terá que digitar o nome do produto a ser comprado e seu respectivo preço.
        
 * **2 - Mostrar sacola**
      
      Comando para chamar a função `verSacola()` da classe `Cliente`.

        Será feita uma listagem de todos os itens da sacola do cliente atual.
    
 * **3 - Adicionar saldo**
 
      Comando para chamar a função `AdicionarSaldo()` da classe `Cliente`.

        Comando para adicionar mais saldo ao cliente atual.

        O usuario terá que digitar um valor para ser adicionado ao saldo.

        Obs.: O saldo inicial do cliente vale R$ 50.00.

 * **4 - Listar produtos da loja**
 
      Comando para chamar a função `ListarProdutos()` da classe `Supermercado`.

        Será feita a listagem de todos os produtos da loja.

        Serão listados: código, nome do produto, unidade de medida, preço e quantidade de cada produto no arquivo estoque.csv

        
 * **5 - Mostrar os produtos vendidos e o total ganho da loja**
 
      Comando para chamar a função `caixa()` da classe `Supermercado`.

        Listar todos os produtos vendidos e a quantidade de dinheiro recebida pela loja na atual execução do programa.

        A ordem estará de acordo com o código do produto.

        
 * **6 - Inicializar outro cliente**
 
      Comando para encerrar as compras do cliente atual. 

      Um arquivo cliente_Supermercado_x.txt será criado com todos os itens comprados do cliente atual.

        'x' representa o numero do cliente.

      Após isso, um novo cliente é criado.
         
 * **7 - Reabastecer o estoque**
 
      Comando para chamar a função `repassarProdutos()` da classe `Fornecedor`. 

      O usuário terá que inserir o nome do produto a ser reabastecido e a quantidade desejada.

        A função repassarProdutos() cria um objeto produto_reabastecimento com a quantidade do produto requerido e invoca a função reabastecer().

        A função reabastecer(), da classe Supermercado, realiza o reabastecimento.


 * **8 - Listar os produtos do fornecedor**
 
      Comando para chamar a função `listarProdutos()` da classe `Fornecedor`. 

        A função listarProdutos() irá mostrar todos os produtos disponíveis, com nome e quantidade, presentes no fornecedor.

         
        
 * **0 - Sair do programa**
 
      Comando para sair do programa.

      A função `registro()` será ativada para o último cliente instanciado.

      Os arquivos `estoque.csv` e `fornecedor.csv` serão atualizados. 


## Comandos para a linha de comando do Linux        
 * **make**
 
      Ao digitar este comando na linha de comando, o programa será compilado. Makefile presente.
  
 * **make clean**
 
      Comando para remover todos os arquivos objeto gerados durante o processo de compilação.

 * **make run**
 
      Comando para compilar e executar o programa.
