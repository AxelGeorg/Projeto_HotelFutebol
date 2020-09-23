#include "Funcoes.h"
#include "Enumeradores.h"
#include "Constantes.h"
#include "Estruturas.h"
#include <iostream>

REG_MATERIA aMateria[QTD_MAX_MATERIAS] = { 0 };
long lQtdMateriasCriadas = 0;

REG_FORMACAO aFormacao[QTD_MAX_FORMACOES] = { 0 };
long lQtdFormacoesCriadas = 0;

REG_PROFESSOR aProfessor[QTD_MAX_PROFESSORES] = { 0 };
long lQtdProfessoresCriados = 0;

void MostraOpcoes()
{
    std::cout << std::endl;
    std::cout << "Gerenciador Escola" << std::endl << std::endl;
    std::cout << "1 - Cadastrar Materia" << std::endl;
    std::cout << "2 - Listar todas as materias" << std::endl;
    std::cout << "3 - Cadastrar Formacao" << std::endl;
    std::cout << "4 - Listar todas as formacoes" << std::endl;
    std::cout << "5 - Cadastrar Professor" << std::endl;
    std::cout << "6 - Listar todos os Professor" << std::endl;
    std::cout << "7 - Alterar Avaliacao da Formacao" << std::endl;
    std::cout << "8 - Listar Materias sem Professor" << std::endl;
    std::cout << "9 - Listar Professores Concursados" << std::endl;
    std::cout << "0 - Sair" << std::endl << std::endl;
    std::cout << "Digite a opcao desejada: ";
}

void CadastraMateria()
{
    std::cout << std::endl;

    if (lQtdMateriasCriadas >= QTD_MAX_MATERIAS)
    {
        std::cout << "Nao e mais possivel criar Materias, quantidade maxima ja atingida!!" << std::endl;
        return;
    }

    REG_MATERIA& regMateria = aMateria[lQtdMateriasCriadas];

    std::cout << "- Para cadastrar o Material preenchal as seguintes informacoes:" << std::endl << std::endl;

    std::cout << "Nome: ";
    std::cin >> regMateria.sNome;
    std::cout << "Quantidade de Capitulos: ";
    std::cin >> regMateria.lCapitulos;
    std::cout << "Quantidade de horas: ";
    std::cin >> regMateria.lHoras;

    ++lQtdMateriasCriadas;

    std::cout << "-------------------------------------------------" << std::endl;
}

void ListaMaterias()
{
    std::cout << std::endl;
    std::cout << "--- Quadro de Materias ---" << std::endl;
    std::cout << std::endl;

    if (lQtdMateriasCriadas == 0)
    {
        std::cout << "Nao ha Materias!!" << std::endl << std::endl;
        return;
    }

    for (long lIndex = 0; lIndex < lQtdMateriasCriadas; ++lIndex)
    {
        const REG_MATERIA& regMateria = aMateria[lIndex];

        std::cout << lIndex + 1 << " - ";
        std::cout << "Nome: " << regMateria.sNome << " | ";
        std::cout << "Capitulos: " << regMateria.lCapitulos << " | ";
        std::cout << "Horas: " << regMateria.lHoras << std::endl;
    }
}

void CadastraFormacao()
{
    std::cout << std::endl;

    if (lQtdFormacoesCriadas >= QTD_MAX_FORMACOES)
    {
        std::cout << "Nao e mais possivel criar Formacoes, quantidade maxima ja atingida!!" << std::endl;
        return;
    }

    REG_FORMACAO& regFormacao = aFormacao[lQtdFormacoesCriadas];

    std::cout << "- Para cadastrar a Formacao preenchal as seguintes informacoes:" << std::endl << std::endl;

    std::cout << "Descricao: ";
    std::cin >> regFormacao.sDescritivo;
    std::cout << "Avaliacao[A-F]: ";
    char cRating = 0;
    std::cin >> cRating;

    switch (cRating)
    {
    case ERating::eA: regFormacao.cRating = ERating::eA; break;
    case ERating::eB: regFormacao.cRating = ERating::eB; break;
    case ERating::eC: regFormacao.cRating = ERating::eC; break;
    case ERating::eD: regFormacao.cRating = ERating::eD; break;
    case ERating::eF: regFormacao.cRating = ERating::eF; break;
    case ERating::eE: regFormacao.cRating = ERating::eE; break;
    default:
    {
        std::cout << "Opcao de avaliacao invalida, caractere digitado nao corresponde as opcoes!!" << std::endl;
        return;
    }
    }

    ++lQtdFormacoesCriadas;

    std::cout << "-------------------------------------------------" << std::endl;
}

void ListaFormacoes()
{
    std::cout << std::endl;
    std::cout << "--- Quadro de Formacoes ---" << std::endl;
    std::cout << std::endl;

    if (lQtdFormacoesCriadas == 0)
    {
        std::cout << "Nao ha Formacoes!!" << std::endl << std::endl;
        return;
    }

    for (long lIndex = 0; lIndex < lQtdFormacoesCriadas; ++lIndex)
    {
        const REG_FORMACAO& regFormacao = aFormacao[lIndex];

        std::cout << lIndex + 1 << " - ";
        std::cout << "Descricao: " << regFormacao.sDescritivo << " | ";
        std::cout << "Rating: " << regFormacao.cRating << std::endl;
    }
}

void CadastraProfessor()
{
    std::cout << std::endl;

    if (lQtdProfessoresCriados >= QTD_MAX_PROFESSORES)
    {
        std::cout << "Nao e mais possivel criar Professores, quantidade maxima ja atingida!!" << std::endl;
        return;
    }

    if (lQtdMateriasCriadas == 0)
    {
        std::cout << "Nao pode-se criar Professor pois, nao ha Materias!!" << std::endl << std::endl;
        return;
    }

    if (lQtdFormacoesCriadas == 0)
    {
        std::cout << "Nao pode-se criar Professor pois, nao ha Formacoes!!" << std::endl << std::endl;
        return;
    }

    REG_PROFESSOR& regProfessor = aProfessor[lQtdProfessoresCriados];

    std::cout << "- Para cadastrar a Formacao preenchal as seguintes informacoes:" << std::endl << std::endl;

    std::cout << "Nome: ";
    std::cin >> regProfessor.sNome;
    std::cout << "Salario: ";
    std::cin >> regProfessor.dSalario;
    std::cout << "Concursado: ";

    std::string sConcursado;
    std::cin >> sConcursado;

    regProfessor.bConcursado = ((sConcursado == "1") || (sConcursado == "sim") || (sConcursado == "SIM"));

    ListaMaterias();

    std::cout << std::endl;
    std::cout << "Digite o numero referente a Materia desejada:" << std::endl;

    long lMateriaEscolhida = 0;
    std::cin >> lMateriaEscolhida;

    if ((lMateriaEscolhida > lQtdMateriasCriadas) || (lMateriaEscolhida <= 0))
    {
        std::cout << "Materia nao esta disponivel!!" << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "- Agora, após escolher a Materia, escolha a Formacao:" << std::endl << std::endl;

    ListaFormacoes();

    std::cout << std::endl;
    std::cout << "Digite o numero referente a Formacao desejada:" << std::endl;

    long lFormacaoEscolhido = 0;
    std::cin >> lFormacaoEscolhido;

    if ((lFormacaoEscolhido > lQtdFormacoesCriadas) || (lFormacaoEscolhido <= 0))
    {
        std::cout << "Formacao nao esta disponivel!!" << std::endl;
        return;
    }

    regProfessor.lIndexMateria = lMateriaEscolhida - 1;
    regProfessor.lIndexFormacao = lFormacaoEscolhido - 1;

    ++lQtdProfessoresCriados;

    std::cout << "-------------------------------------------------" << std::endl;
}

void ListaProfessor()
{
    std::cout << std::endl;
    std::cout << "--- Quadro de Professores ---" << std::endl;
    std::cout << std::endl;

    if (lQtdProfessoresCriados == 0)
    {
        std::cout << "Nao ha Professores!!" << std::endl << std::endl;
        return;
    }

    for (long lIndex = 0; lIndex < lQtdProfessoresCriados; ++lIndex)
    {
        const REG_PROFESSOR& regProfessor = aProfessor[lIndex];

        std::cout << lIndex + 1 << " - ";
        std::cout << "Nome: " << regProfessor.sNome << " | ";
        std::cout << "Salario: " << regProfessor.dSalario << " | ";
        std::cout << "Concursado: " << (regProfessor.bConcursado ? "Sim" : "Nao") << " | ";
        std::cout << "Materia: " << aMateria[regProfessor.lIndexMateria].sNome << " | ";
        std::cout << "Formacao: " << aFormacao[regProfessor.lIndexFormacao].sDescritivo << std::endl;
    }
}

void AlteraRating()
{
    if (lQtdFormacoesCriadas <= 0)
    {
        std::cout << "Nao ha Formacoes!!" << std::endl;
        return;
    }

    ListaFormacoes();

    std::cout << std::endl;
    std::cout << "Digite o numero referente a Formacao que deseja alterar: ";

    long lFormacaoEscolhida = 0;
    std::cin >> lFormacaoEscolhida;

    if ((lFormacaoEscolhida > lQtdFormacoesCriadas) || (lFormacaoEscolhida <= 0))
    {
        std::cout << "Essa Formacao nao esta disponivel!!" << std::endl;
        return;
    }

    REG_FORMACAO& regFormacao = aFormacao[lFormacaoEscolhida - 1];

    std::cout << " - Digite a Avaliacao[A-F] o qual deseja substituir a atual: ";
    char cRating = 0;
    std::cin >> cRating;

    switch (cRating)
    {
    case ERating::eA: regFormacao.cRating = ERating::eA; break;
    case ERating::eB: regFormacao.cRating = ERating::eB; break;
    case ERating::eC: regFormacao.cRating = ERating::eC; break;
    case ERating::eD: regFormacao.cRating = ERating::eD; break;
    case ERating::eF: regFormacao.cRating = ERating::eF; break;
    case ERating::eE: regFormacao.cRating = ERating::eE; break;
    default:
    {
        std::cout << "Opcao de avaliacao invalida, caractere digitado nao corresponde as opcoes!!" << std::endl;
        return;
    }
    }

    std::cout << "-------------------------------------------------" << std::endl;
}

bool VerificaSeMateriaTemProf(const long& lIndexMateria)
{
    for (long lIndex = 0; lIndex < lQtdProfessoresCriados; ++lIndex)
    {
        const REG_PROFESSOR& regProfessor = aProfessor[lIndex];

        if (regProfessor.lIndexMateria == lIndexMateria)
            return true;
    }

    return false;
}

void ListaMateriasSemProf()
{
    std::cout << std::endl;
    std::cout << "--- Quadro de Materias sem Professor ---" << std::endl;
    std::cout << std::endl;

    if (lQtdMateriasCriadas == 0)
    {
        std::cout << "Nao ha Materias!!" << std::endl << std::endl;
        return;
    }

    long lContadorMaterias = 0;

    for (long lIndex = 0; lIndex < lQtdMateriasCriadas; ++lIndex)
    {
        const REG_MATERIA& regMateria = aMateria[lIndex];

        if (VerificaSeMateriaTemProf(lIndex))
            continue;

        std::cout << lIndex + 1 << " - ";
        std::cout << "Nome: " << regMateria.sNome << " | ";
        std::cout << "Capitulos: " << regMateria.lCapitulos << " | ";
        std::cout << "Horas: " << regMateria.lHoras << std::endl;

        ++lContadorMaterias;
    }

    if (lContadorMaterias == 0)
        std::cout << "Nao ha Materias sem Professor!!" << std::endl << std::endl;
}

void ListaProfsConcursados()
{
    std::cout << std::endl;
    std::cout << "--- Quadro de Professores Concursados---" << std::endl;
    std::cout << std::endl;

    if (lQtdProfessoresCriados == 0)
    {
        std::cout << "Nao ha Professores!!" << std::endl << std::endl;
        return;
    }

    for (long lIndex = 0; lIndex < lQtdProfessoresCriados; ++lIndex)
    {
        const REG_PROFESSOR& regProfessor = aProfessor[lIndex];

        if (!regProfessor.bConcursado)
            continue;

        std::cout << lIndex + 1 << " - ";
        std::cout << "Nome: " << regProfessor.sNome << " | ";
        std::cout << "Salario: " << regProfessor.dSalario << " | ";
        std::cout << "Concursado: " << (regProfessor.bConcursado ? "Sim" : "Nao") << " | ";
        std::cout << "Materia: " << aMateria[regProfessor.lIndexMateria].sNome << " | ";
        std::cout << "Formacao: " << aFormacao[regProfessor.lIndexFormacao].sDescritivo << std::endl;
    }
}

void ListaSeTemProfComEsseRating(const char& cRatingEscolhido)
{
    REG_MATERIA aMateriasRelacionadas[QTD_MAX_MATERIAS] = { 0 };
    long lQtdMateriasRelacionadas = 0;
    long lTemIgual = 0;

    std::cout << std::endl;

    for (long lIndex = 0; lIndex < lQtdProfessoresCriados; ++lIndex)
    {
        const REG_PROFESSOR& regProfessor = aProfessor[lIndex];

        if (aFormacao[regProfessor.lIndexFormacao].cRating != cRatingEscolhido)
            continue;

        for (long lIdxMateriasRelacionadas = 0; lIdxMateriasRelacionadas < lQtdMateriasRelacionadas; ++lIdxMateriasRelacionadas)
        {
            if (aMateriasRelacionadas[lIdxMateriasRelacionadas].sNome == aMateria[regProfessor.lIndexMateria].sNome)
                ++lTemIgual;
        }

        if (lTemIgual != 0)
            continue;

        aMateriasRelacionadas[lQtdMateriasRelacionadas].sNome = aMateria[regProfessor.lIndexMateria].sNome;
        ++lQtdMateriasRelacionadas;

    }

    if (lQtdMateriasRelacionadas == 0)
        std::cout << "Nao ha professores com essa avaliacao na formacao!!" << std::endl;
    else
    {
        for (long lIndex = 0; lIndex < lQtdMateriasRelacionadas; ++lIndex)
            std::cout << "- Materia: " << aMateriasRelacionadas[lIndex].sNome << std::endl;
    }
}

void ListaMateriasPorRating()
{
    if (lQtdFormacoesCriadas <= 0)
    {
        std::cout << "Nao ha Formacoes!!" << std::endl;
        return;
    }

    if (lQtdProfessoresCriados == 0)
    {
        std::cout << "Nao ha Professores!!" << std::endl << std::endl;
        return;
    }

    std::cout << "Digite a Avaliacao[A-F] o qual deseja listar as materias relacionadas: ";
    char cRating = 0;
    std::cin >> cRating;

    switch (cRating)
    {
    case ERating::eA:
    case ERating::eB:
    case ERating::eC:
    case ERating::eD:
    case ERating::eF:
    case ERating::eE: ListaSeTemProfComEsseRating(cRating); break;
    default:
    {
        std::cout << "Opcao de avaliacao invalida, caractere digitado nao corresponde as opcoes!!" << std::endl;
        return;
    }
    }
}

void ListaSalarioHoraDoProf()
{
    std::cout << std::endl;
    std::cout << "--- Quadro de Professores Salario/Hora ---" << std::endl;
    std::cout << std::endl;

    if (lQtdProfessoresCriados == 0)
    {
        std::cout << "Nao ha Professores!!" << std::endl << std::endl;
        return;
    }

    for (long lIndex = 0; lIndex < lQtdProfessoresCriados; ++lIndex)
    {
        const REG_PROFESSOR& regProfessor = aProfessor[lIndex];

        std::cout << lIndex + 1 << " - ";
        std::cout << "Nome: " << regProfessor.sNome << " | ";
        std::cout << "Salario: " << regProfessor.dSalario << " | ";
        std::cout << "Concursado: " << (regProfessor.bConcursado ? "Sim" : "Nao") << " | ";
        std::cout << "Materia: " << aMateria[regProfessor.lIndexMateria].sNome << " | ";
        std::cout << "Qtd Horas: " << aMateria[regProfessor.lIndexMateria].lHoras << " | ";
        std::cout << "Formacao: " << aFormacao[regProfessor.lIndexFormacao].sDescritivo << " | ";
        std::cout << "Salario/Hora: " << regProfessor.dSalario / aMateria[regProfessor.lIndexMateria].lHoras << std::endl;
    }
}

void RemoverProf()
{
    if (lQtdProfessoresCriados <= 0)
    {
        std::cout << "Nao ha Professores!!" << std::endl;
        return;
    }

    ListaProfessor();

    std::cout << std::endl;
    std::cout << "Digite o numero referente ao Professor que deseja remover: ";

    long lProfEscolhido = 0;
    std::cin >> lProfEscolhido;

    if ((lProfEscolhido > lQtdProfessoresCriados) || (lProfEscolhido <= 0))
    {
        std::cout << "Professor nao esta disponivel!!" << std::endl;
        return;
    }

    for (long lIdx = lProfEscolhido; lIdx < lQtdProfessoresCriados; ++lIdx)
        aProfessor[lIdx - 1] = aProfessor[lIdx];

    --lQtdProfessoresCriados;

    std::cout << "Professor removido com sucesso!!" << std::endl;
}