FILES = main.o App.o Cliente.o Estabelecimento.o Restaurante.o Supermercado.o Produto.o Fornecedor.o Cardapio.o
COMPILER = g++
PROGRAM = Supermercado
GCC_FLAGS = -I include -std=c++11 -Wall

all: $(PROGRAM)

$(PROGRAM): main.o App.o Cliente.o Estabelecimento.o Restaurante.o Supermercado.o Produto.o Fornecedor.o Cardapio.o
	$(COMPILER) $(GCC_FLAGS) $(FILES) -o $(PROGRAM)

main.o: src/main.cpp include/App.h
	$(COMPILER) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h 
	$(COMPILER) $(GCC_FLAGS) -c src/App.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(COMPILER) $(GCC_FLAGS) -c src/Cliente.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(COMPILER) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Restaurante.o: src/Restaurante.cpp include/Restaurante.h
	$(COMPILER) $(GCC_FLAGS) -c src/Restaurante.cpp

Supermercado.o: src/Supermercado.cpp include/Supermercado.h
	$(COMPILER) $(GCC_FLAGS) -c src/Supermercado.cpp

Produto.o: src/Produto.cpp include/Produto.h
	$(COMPILER) $(GCC_FLAGS) -c src/Produto.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.h include/VectorSupermercado.h include/Estabelecimento.h
	$(COMPILER) $(GCC_FLAGS) -c src/Fornecedor.cpp

Cardapio.o: src/Cardapio.cpp include/Cardapio.h
	$(COMPILER) $(GCC_FLAGS) -c src/Cardapio.cpp

.PHONY: clean run

clean:
	rm *.o

run: Supermercado
	./$(PROGRAM)
