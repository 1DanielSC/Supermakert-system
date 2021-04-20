#ifndef VECTORSUPERMERCADO_H
#define VECTORSUPERMERCADO_H

#include <string>
#include <iostream>
#include <new>

template <class T>
class Vector_Supermercado
{

public:

	T* elements;
	int vectorSize;
	int vectorCapacity;

	


Vector_Supermercado(int size): elements{nullptr}, vectorSize{0}, vectorCapacity{size}
{
	this->elements = new T[size];
}

~Vector_Supermercado()
{
	delete[] this->elements;
	this->vectorSize = 0;
	this->vectorCapacity = 0;

}




bool reallocate()
{
	T* buff = new T[this->vectorCapacity*2];

	this->vectorCapacity *= 2;

	for (int i = 0; i < this->vectorSize; i++){
		buff[i] = this->elements[i];
	}

	delete[] this->elements;
	this->elements = buff;
	buff = nullptr;
	
	return true;
}


void push_back(T& element)
{
	if (this->vectorSize == this->vectorCapacity){

		try{
			this->reallocate();
		}
		catch(std::bad_alloc &bad_alloc){
			std::cerr << "Erro: Memoria indisponivel para realocacao" << std::endl;
			return;
		}
	}

	this->elements[this->vectorSize] = element;
	this->vectorSize++;
}



void changeQuantity(std::string nomeProduto, int quantidadeAdicionada)
{
	for (int i = 0; i < this->vectorSize; i++)
	{
		if (elements[i].NomeProduto == nomeProduto)
		{
			elements[i].Quantidade += quantidadeAdicionada;
			return;
		}
	}
}


int size() {return this->vectorSize;}



};

#endif