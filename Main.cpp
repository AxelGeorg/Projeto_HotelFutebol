#include <iostream>
#include "Funcoes.h"
#include "Enumeradores.h"

int main()
{
    long lOpcao = 0;

    do
    {
        MostraOpcoes();
        std::cin >> lOpcao;

        switch (lOpcao)
        {
            case EOpcoesLista::eCriaHotel             : CadastraHotel         (); break;
            case EOpcoesLista::eListarTodosHoteis     : ListaHoteis           (); break;
            case EOpcoesLista::eListarHoteisPorEstrela: ListaHoteisPorEstrela (); break;
            case EOpcoesLista::eCriaTime              : CadastraTime          (); break;
            case EOpcoesLista::eListarTodosTimes      : ListaTimes            (); break;
            case EOpcoesLista::eListarTimesPorDivisao : ListaTimesPorDivisao  (); break;
            case EOpcoesLista::eReservaTimeNoHotel    : ReservaTimeNoHotel    (); break;
            case EOpcoesLista::eRemoveTime            : RemoveTime            (); break;
            case EOpcoesLista::eAlteraTemPiscinaHotel : AlteraTemPiscinaHotel (); break;
            default: 
            {
                if (lOpcao != 0)
                    std::cout << std::endl << "Essa opcao nao esta disponivel!!" << std::endl;
            }
            break;
        }
    } while (lOpcao != EOpcoesLista::eSair);

    std::cout << std::endl << "Saiu" << std::endl;

    return 0;
}
