#pragma once
#include <string>
#include "Enumeradores.h"

struct REG_HOTEL
{
    long lNumero;
    long lTelefone;

    bool bPiscina;

    std::string sCidade;
    std::string sNome;

    EEstrela eEstrela;
};

struct REG_TIME
{
    double dValorEstimado;

    long lIdxHotel;
    long lTitulos;
    long lQtdJogadores;

    std::string sTecnico;
    std::string sNome;

    EDivisao eDivisao;
};
