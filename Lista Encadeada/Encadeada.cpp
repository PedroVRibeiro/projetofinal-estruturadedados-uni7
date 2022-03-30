#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

struct noLista{
    int chave;
    int dado;
    struct noLista * proximo;
};

struct noLista * anterior = NULL;
struct noLista * ponteiro = NULL;

struct noLista * ptLista = new struct noLista;

//PROCEDIMENTO BUSCA
void Buscar(int x){
    struct noLista * ptr;
    anterior = ptLista;
    ponteiro = NULL;
    ptr = (*ptLista).proximo;

    while(ptr != NULL)
    {
        if((*ptr).chave < x)
        {
            anterior = ptr;
            ptr = (*ptr).proximo;
        }
        else
        {
            if ((*ptr).chave == x)
        {
            ponteiro = ptr;

        }
        ptr = NULL;
        }
    }
}

//PROCEDIMENTO INSER��O
void Inserir (int x,int y){
    Buscar(x);
    if (ponteiro == NULL)
    {
        struct noLista * pt = new struct noLista;
        (*pt).proximo = (*anterior).proximo;
        (*anterior).proximo = pt;
        (*pt).chave = x;
        (*pt).dado = y;
        cout << "\nValor inserido com sucesso! \n";
        cout << "******************************************************\n";
    }
    else
    {
        cout << "\nValor j� existente na lista. N�o foi poss�vel inserir! \n";
        cout << "******************************************************\n";
    }
}

//PROCEDIMENTO REMO��O
void Remover (int x){
    Buscar(x);
    if ((*ptLista).proximo == NULL)
    {
        cout << "\nA lista est� vazia. N�o � poss�vel remover. \n";
        cout << "******************************************************\n";
    }
    else
    {
        if (ponteiro == NULL)
        {
            cout << "\nValor N�O ENCONTRADO na lista. N�o foi poss�vel remover. \n";
            cout << "******************************************************\n";
        }
        else
        {
            (*anterior).proximo = (*ponteiro).proximo;
            ponteiro = NULL;
            cout << "\nValor removido com sucesso! \n";
            cout << "******************************************************\n";
        }
    }
}

//PROCEDIMENTO LISTAGEM
void Listar(){
    int i=1;
    struct noLista * noAux;
    noAux = (*ptLista).proximo;

    while(noAux != NULL)
    {
        cout << "\n| N� " << i << "      |\n";
        cout << "| Chave: " << (*noAux).chave << "  |\n";
        cout << "| Valor: " << (*noAux).dado << " |\n";
        cout << "\n";
        noAux = (*noAux).proximo;
        i++;
    }
}

//PROCEDIMENTO EDI��O
void Editar(int x){
    int novo_valor;
    int opc = 0;
    Buscar(x);
    if ((*ptLista).proximo == NULL)
    {
        cout << "\nA lista est� vazia. N�o � poss�vel editar. \n";
        cout << "******************************************************\n";
    }
    else
    {
        if (ponteiro == NULL)
        {
            cout << "\nValor N�O ENCONTRADO na lista. N�o foi poss�vel editar. \n";
            cout << "******************************************************\n";
        }
        else
        {
        cout << "Voc� gostaria mesmo de editar? \n";
        cout << "1 - SIM\n";
        cout << "2 - N�O\n";
        cout << "\nEscolha uma op��o: \n";

        cin >> opc;
        if (opc == 1)
        {
                cout << "\nValor digitado encontrado, a informa��o nele armazenada � " << (*ponteiro).dado << "\n";
                cout << "Digite a nova informa��o: \n";
                cin >> novo_valor;
                (*ponteiro).dado = novo_valor;
                cout << "Valor editado com sucesso! \n";
        }
        else
        {
        system("cls");
        cout << "Op��o inv�lida. Tente novamente. \n";

        }
        }
    }
}

int main(){
int valor,vChave,escolha;
bool sair = false;

(*ptLista).proximo = NULL;

    setlocale(LC_CTYPE, "Portuguese");
    cout << "Este algoritmo gerencia os valores de uma lista ENCADEADA, COM CHAVE, N� CABE�A e ORDENADA!\n";

while (sair != true){
    cout << "Por favor, escolha uma op��o no menu abaixo: \n\n";
    cout << "1 - Buscar valor \n";
    cout << "2 - Inserir \n";
    cout << "3 - Remover \n";
    cout << "4 - Editar \n";
    cout << "5 - Listar valores \n";
    cout << "6 - SAIR \n\n";

    cin >> escolha;

    switch(escolha){
    //BUSCAR
    case 1:
        system("cls");
        cout << "\nDigite o valor a ser buscado: \n";
        cin >> valor;
        Buscar(valor);

        if (ponteiro == NULL){
            cout << "\nA lista est� vazia ou o valor n�o foi encontrado! \n";
            cout << "******************************************************\n";
        }
        else {
            cout << "\nValor digitado encontrado, a informa��o nele armazenada � " << (*ponteiro).dado << "\n";
            cout << "******************************************************\n";
        }
        break;
    //INSERIR
    case 2:
        system("cls");
        cout << "Digite a chave e o valor a serem inseridos: \n";
        cout << "Chave: ";
        cin >> vChave;
        cout << "Valor: ";
        cin >> valor;
        Inserir(vChave,valor);
        cout << "\n";
        break;
    //REMOVER
    case 3:
        system("cls");
        cout << "Digite o valor a ser removido: \n";
        cin >> valor;
        Remover(valor);
        cout << "\n";
        break;
    //EDITAR
    case 4:
        system("cls");
        cout << "Digite o valor a ser editado: \n";
        cin >> valor;
        Editar(valor);
        cout << "\n";
        break;
    //LISTAGEM
    case 5:
        system("cls");
        cout << "Listando todos os n�s: \n";
        Listar();
        cout << "\n";
        break;
    case 6:
    //SAIR;
        sair = true;
        cout << "\nExecu��o finalizada!";
        break;
    default:
    //EXCE��ES
        cout << "\nOp��o inv�lida. Por favor, escolha novamente: ";
        cin >> escolha;
        break;
    }

    }
}
