#ifndef APP_H
#define APP_H

#include <vector>

#include "Cliente.h"
#include "Fornecedor.h"
#include "Restaurante.h"
#include "Supermercado.h"

struct App
{
    int run();

    void SelecionarModo();
    void MenuInterativo_Supermercado(std::vector<Cliente*>& clientes, Supermercado& supermercado, Fornecedor& fornecedor);
    void MenuInterativo_Restaurante(std::vector<Cliente*>& clientes, Restaurante& restaurante);
};
#endif
