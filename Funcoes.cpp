#include "Funcoes.h"
#include "Enumeradores.h"
#include "Constantes.h"
#include "Estruturas.h"
#include <iostream>
using namespace std;

REG_HOTEL aHotel[QTD_MAX_HOTEIS] = {0};
long lQtdHoteisCriados           = 0;

REG_TIME aTime[QTD_MAX_TIMES]    = {0};
long lQtdTimesCriados            = 0;

void MostraOpcoes()
{
    std::cout << std::endl;
    std::cout << "Gerenciador"                    << std::endl  << std::endl;
    std::cout << "1 - Cadastrar Hotel"            << std::endl;
    std::cout << "2 - Listar todos os hoteis"     << std::endl;
    std::cout << "3 - Listar Hoteis por estrelas" << std::endl;
    std::cout << "4 - Cadastrar Time de Futebol"  << std::endl;
    std::cout << "5 - Listar todos os Times"      << std::endl;
    std::cout << "6 - Listar Times por divisao"   << std::endl;
    std::cout << "7 - Reservar Time em Hotel"     << std::endl;
    std::cout << "8 - Remove Time"                << std::endl;
    std::cout << "9 - Altera Hotel"               << std::endl;
    std::cout << "0 - Sair"                       << std::endl  << std::endl;
    std::cout << "Digite a opcao desejada: ";
}

void CadastraHotel()
{
    std::cout << std::endl ;

    if (lQtdHoteisCriados >= QTD_MAX_HOTEIS)
    {
        std::cout << "Nao e mais possivel criar hoteis, quantidade maxima ja atingida!!" << std::endl ;
        return;
    }

    REG_HOTEL& regHotel = aHotel[lQtdHoteisCriados];

    std::cout << "- Para cadastrar o hotel preenchal as seguintes caracteristicas:" << std::endl  << std::endl ;

    std::cout << "Nome: ";
    std::cin  >> regHotel.sNome;
    std::cout << "Cidade: ";
    std::cin  >> regHotel.sCidade;
    std::cout << "Numero: ";
    std::cin  >> regHotel.lNumero;
    std::cout << "Telefone: ";
    std::cin  >> regHotel.lTelefone;
    std::cout << "Quantidade de Estrelas[1-5]: ";

    long lQtdEstrelas = 0;
    std::cin  >> lQtdEstrelas;

    switch (lQtdEstrelas)
    {
        case EEstrela::eUma   : regHotel.eEstrela = EEstrela::eUma   ; break;
        case EEstrela::eDois  : regHotel.eEstrela = EEstrela::eDois  ; break;
        case EEstrela::eTres  : regHotel.eEstrela = EEstrela::eTres  ; break;
        case EEstrela::eQuatro: regHotel.eEstrela = EEstrela::eQuatro; break;
        case EEstrela::eCinco : regHotel.eEstrela = EEstrela::eCinco ; break;
    }

    std::cout << "No hotel ha piscina? Digite sim ou nao!" << std::endl ;

    std::string sTemPiscina;
    std::cin >> sTemPiscina;

    aHotel[lQtdHoteisCriados].bPiscina = ((sTemPiscina == "1") || (sTemPiscina == "sim") || (sTemPiscina == "SIM"));

    ++lQtdHoteisCriados;

    std::cout << "-------------------------------------------------" << std::endl ;
}

void ListaHoteis()
{
    std::cout << std::endl ;
    std::cout << "--- Quadro de Hoteis ---" << std::endl ;
    std::cout << std::endl ;

    //valida se a quant de times é zero

    for (long lIndex = 0; lIndex < lQtdHoteisCriados; ++lIndex)
    {
        const REG_HOTEL& regHotel = aHotel[lIndex];

        std::cout << lIndex + 1         << " - ";
        std::cout << "Nome: "           << regHotel.sNome                      << " | ";
        std::cout << "Cidade: "         << regHotel.sCidade                    << " | ";
        std::cout << "Numero: "         << regHotel.lNumero                    << " | ";
        std::cout << "Telefone: "       << regHotel.lTelefone                  << " | ";
        std::cout << "Tem piscina: "    << (regHotel.bPiscina ? "Sim" : "Nao") << " | ";
        std::cout << "Nr de Estrelas: " << regHotel.eEstrela                   << std::endl ;
    }
}

void ListaHoteisPorEstrela()
{
    std::cout << std::endl ;
    std::cout << "Qual a quantidade de estrelas que deseja filtrar a lista de hoteis? " << std::endl ;

    long lQtdEstrelas = 0;
    std::cin >> lQtdEstrelas;
    std::cout << std::endl ;

    //valida se qtd d estrelas existe

    long lContadorHoteis = 0;

    for (long lIndex = 0; lIndex < lQtdHoteisCriados; ++lIndex)
    {
        const REG_HOTEL& regHotel = aHotel[lIndex];

        if (regHotel.eEstrela != lQtdEstrelas)
            continue;

        std::cout << lIndex + 1 << " - ";
        std::cout << "Nome: "           << regHotel.sNome                      << " | ";
        std::cout << "Cidade: "         << regHotel.sCidade                    << " | ";
        std::cout << "Numero: "         << regHotel.lNumero                    << " | ";
        std::cout << "Telefone: "       << regHotel.lTelefone                  << " | ";
        std::cout << "Tem piscina: "    << (regHotel.bPiscina ? "Sim" : "Nao") << " | ";
        std::cout << "Nr de Estrelas: " << regHotel.eEstrela                   << std::endl;

        ++lContadorHoteis;
    }

    if (lContadorHoteis == 0)
        std::cout << "Nao ha hoteis com essa quantidade de estrelas!!" << std::endl  << std::endl ;
}


void CadastraTime()
{
    std::cout << std::endl ;

    if (lQtdTimesCriados >= QTD_MAX_TIMES)
    {
        std::cout << "Nao e mais possivel criar times, quantidade maxima ja atingida!!" << std::endl ;
        return;
    }

    REG_TIME& regTime = aTime[lQtdTimesCriados];

    std::cout << "- Para cadastrar o time preenchal as seguintes caracteristicas:" << std::endl  << std::endl ;

    std::cout << "Nome: ";
    std::cin  >> regTime.sNome;
    std::cout << "Quantidade de Jogadores: ";
    std::cin  >> regTime.lQtdJogadores;
    std::cout << "Divisao[A-D]: ";

    char cDivisao = 0;
    std::cin  >> cDivisao;

    switch (cDivisao)
    {
        case EDivisao::eAm:
        case EDivisao::eA: regTime.eDivisao = EDivisao::eA; break;

        case EDivisao::eBm:
        case EDivisao::eB: regTime.eDivisao = EDivisao::eB; break;

        case EDivisao::eCm:
        case EDivisao::eC: regTime.eDivisao = EDivisao::eC; break;

        case EDivisao::eDm:
        case EDivisao::eD: regTime.eDivisao = EDivisao::eD; break;
    }

    std::cout << "Quantidade de Titulos: ";
    std::cin  >> regTime.lTitulos;
    std::cout << "Tecnico: ";
    std::cin  >> regTime.sTecnico;
    std::cout << "Valor Estimado: ";
    std::cin  >> regTime.dValorEstimado;

    regTime.lIdxHotel = 0;

    ++lQtdTimesCriados;

    std::cout << "-------------------------------------------------" << std::endl ;
}

std::string GetDescricaoTimeDivisao(EDivisao eDivisao)
{
    switch (eDivisao)
    {
        case EDivisao::eAm:
        case EDivisao::eA: return "A";

        case EDivisao::eBm:
        case EDivisao::eB: return "B";

        case EDivisao::eCm:
        case EDivisao::eC: return "C";

        case EDivisao::eDm:
        case EDivisao::eD: return "D";
    }
    return "";
}

std::string GetNomeHotelPorIdx(const long& lIndexHotel)
{
    if (lIndexHotel == 0)
        return "Sem Local";

    const REG_HOTEL& regHotel = aHotel[lIndexHotel-1];
    return regHotel.sNome;
}

void ListaTimes()
{
    std::cout << std::endl ;
    std::cout << "--- Quadro de Times ---" << std::endl ;
    std::cout << std::endl ;

    //valida se a quant de times é zero

    for (long lIndex = 0; lIndex < lQtdTimesCriados; ++lIndex)
    {
        const REG_TIME& regTime = aTime[lIndex];

        std::cout << lIndex + 1          << " - ";
        std::cout << "Nome: "            << regTime.sNome                             << " | ";
        std::cout << "Qtd Jogadores: "   << regTime.lQtdJogadores                     << " | ";
        std::cout << "Divisao: "         << GetDescricaoTimeDivisao(regTime.eDivisao) << " | ";
        std::cout << "Qtd de Titulos: "  << regTime.lTitulos                          << " | ";
        std::cout << "Tecnico: "         << regTime.sTecnico                          << " | ";
        std::cout << "Hotel Hospedado: " << GetNomeHotelPorIdx(regTime.lIdxHotel)     << " | ";
        std::cout << "Valor estimado: "  << regTime.dValorEstimado                    << std::endl  ;
    }
}

void ListaTimesPorDivisao()
{
    std::cout << std::endl  ;
    std::cout << "Qual a divisao que deseja filtrar a lista de times? " << std::endl ;

    char cDivisao = 0;
    std::cin >> cDivisao;
    std::cout << std::endl ;

    long lContadorTimes = 0;

    //valida se divisao existe

    for (long lIndex = 0; lIndex < lQtdHoteisCriados; ++lIndex)
    {
        const REG_TIME& regTime = aTime[lIndex];

        if (regTime.eDivisao != cDivisao)
            continue;
        
            std::cout << lIndex + 1         << " - ";
            std::cout << "Nome: "           << regTime.sNome                             << " | ";
            std::cout << "Qtd Jogadores: "  << regTime.lQtdJogadores                     << " | ";
            std::cout << "Divisao: "        << GetDescricaoTimeDivisao(regTime.eDivisao) << " | ";
            std::cout << "Qtd de Titulos: " << regTime.lTitulos                          << " | ";
            std::cout << "Tecnico: "        << regTime.sTecnico                          << " | ";
            std::cout << "Hospedado: "      << GetNomeHotelPorIdx(regTime.lIdxHotel)     << " | ";
            std::cout << "Valor estimado: " << regTime.dValorEstimado                    << std::endl ;

            ++lContadorTimes;
    }

    if (lContadorTimes == 0)
        std::cout << "Nao ha times nessa Divisao!!" << std::endl  << std::endl ;
}

void ReservaTimeNoHotel()
{
    if (lQtdHoteisCriados == 0)
    {
        std::cout << "Hotel deve ser cadastrado!!" << std::endl << std::endl;
        return;
    }

    if (lQtdTimesCriados == 0)
    {
        std::cout << "Time deve ser cadastrado!!" << std::endl << std::endl;
        return;
    }

    std::cout << std::endl ;
    std::cout << "- Para Reservar o time  em um hotel escolha um dos times a seguir:" << std::endl  << std::endl ;

    ListaTimes();

    std::cout << std::endl ;
    std::cout << "Digite o numero referente ao time desejado:" << std::endl ;

    long lTimeEscolhido = 0;
    std::cin >> lTimeEscolhido;

    if ((lTimeEscolhido > lQtdHoteisCriados) || (lTimeEscolhido  <= 0))
    {
        std::cout << "Time nao esta disponivel!!" << std::endl;
        return;
    }

    REG_TIME& regTime = aTime[lTimeEscolhido-1];

    std::cout << std::endl ;
    std::cout << "- Agora, após escolher o time, escolha o hotel o qual esse time ficará:" << std::endl  << std::endl ;

    ListaHoteis();

    std::cout << std::endl ;
    std::cout << "Digite o numero referente ao hotel desejado:" << std::endl ;

    long lHotelEscolhido = 0;
    std::cin >> lHotelEscolhido;

    if ((lHotelEscolhido > lQtdHoteisCriados) || (lHotelEscolhido  <= 0))
    {
        std::cout << "Hotel nao esta disponivel!!" << std::endl ;
        return;
    }

    regTime.lIdxHotel = lHotelEscolhido;
    std::cout << "- Time reservado no hotel com sucesso!!" << std::endl  << std::endl ;
}

void RemoveTime()
{
    if (lQtdTimesCriados <= 0)
    {
        std::cout << "Nao ha Times!!" << std::endl;
        return;
    }

    ListaTimes();

    std::cout << std::endl;
    std::cout << "Digite o numero referente ao time que deseja remover: ";

    long lTimeEscolhido = 0;
    std::cin >> lTimeEscolhido;

    if ((lTimeEscolhido > lQtdTimesCriados) || (lTimeEscolhido  <= 0))
    {
        std::cout << "Time nao esta disponivel!!" << std::endl;
        return;
    }

    for (long lIdx = lTimeEscolhido; lIdx < lQtdTimesCriados; ++lIdx)
        aTime[lIdx - 1] = aTime[lIdx];

    --lQtdTimesCriados;

    std::cout << "- Time Removido com sucesso!!" << std::endl;
}

void AlteraTemPiscinaHotel()
{
    if (lQtdHoteisCriados <= 0)
    {
        std::cout << "Nao ha Hoteis!!" << std::endl;
        return;
    }

    ListaHoteis();

    std::cout << std::endl;
    std::cout << "Digite o numero referente ao hotel que deseja alterar: ";

    long lHotelEscolhido = 0;
    std::cin >> lHotelEscolhido;

    if ((lHotelEscolhido > lQtdHoteisCriados) || (lHotelEscolhido  <= 0))
    {
        std::cout << "Hotel nao esta disponivel!!" << std::endl;
        return;
    }

    aHotel[lHotelEscolhido - 1].bPiscina = !aHotel[lHotelEscolhido - 1].bPiscina;

    std::cout << "- Hotel alterado com sucesso!!" << std::endl;
}