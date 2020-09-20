#pragma once
#include <string>
#include "Enumeradores.h"

void MostraOpcoes();

void CadastraHotel();
void ListaHoteis();
void ListaHoteisPorEstrela();
void AlteraTemPiscinaHotel();

void CadastraTime();
std::string GetDescricaoTimeDivisao(EDivisao eDivisao);
std::string GetNomeHotelPorIdx(const long& lIndexHotel);
void ListaTimes();
void ListaTimesPorDivisao();
void RemoveTime();

void ReservaTimeNoHotel();
