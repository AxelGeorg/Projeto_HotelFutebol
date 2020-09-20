#pragma once

enum EOpcoesLista
{
    eSair = 0,

    eCriaHotel = 1,
    eListarTodosHoteis = 2,
    eListarHoteisPorEstrela = 3,

    eCriaTime = 4,
    eListarTodosTimes = 5,
    eListarTimesPorDivisao = 6,

    eReservaTimeNoHotel = 7,

    eRemoveTime = 8,

    eAlteraTemPiscinaHotel = 9,
};

enum EEstrela
{
    eInvalido = 0,

    eUma      = 1,
    eDois     = 2,
    eTres     = 3,
    eQuatro   = 4,
    eCinco    = 5,
};

enum EDivisao
{
    eA = 'A',
    eB = 'B',
    eC = 'C',
    eD = 'D',
    eAm = 'a',
    eBm = 'b',
    eCm = 'c',
    eDm = 'd',
};
