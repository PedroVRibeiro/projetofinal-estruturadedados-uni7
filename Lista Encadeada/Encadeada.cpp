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

//PROCEDIMENTO INSERÇÃO
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
        cout << "\nValor já existente na lista. Não foi possível inserir! \n";
        cout << "******************************************************\n";
    }
}

//PROCEDIMENTO REMOÇÃO
void Remover (int x){
    Buscar(x);
    if ((*ptLista).proximo == NULL)
    {
        cout << "\nA lista está vazia. Não é possível remover. \n";
        cout << "******************************************************\n";
    }
    else
    {
        if (ponteiro == NULL)
        {
            cout << "\nValor NÃO ENCONTRADO na lista. Não foi possível remover. \n";
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
        cout << "\n| Nó " << i << "      |\n";
        cout << "| Chave: " << (*noAux).chave << "  |\n";
        cout << "| Valor: " << (*noAux).dado << " |\n";
        cout << "\n";
        noAux = (*noAux).proximo;
        i++;
    }
}

//PROCEDIMENTO EDIÇÃO
void Editar(int x){
    int novo_valor;
    int opc = 0;
    Buscar(x);
    if ((*ptLista).proximo == NULL)
    {
        cout << "\nA lista está vazia. Não é possível editar. \n";
        cout << "******************************************************\n";
    }
    else
    {
        if (ponteiro == NULL)
        {
            cout << "\nValor NÃO ENCONTRADO na lista. Não foi possível editar. \n";
            cout << "******************************************************\n";
        }
        else
        {
        cout << "Você gostaria mesmo de editar? \n";
        cout << "1 - SIM\n";
        cout << "2 - NÃO\n";
        cout << "\nEscolha uma opção: \n";

        cin >> opc;
        if (opc == 1)
        {
                cout << "\nValor digitado encontrado, a informação nele armazenada é " << (*ponteiro).dado << "\n";
                cout << "Digite a nova informação: \n";
                cin >> novo_valor;
                (*ponteiro).dado = novo_valor;
                cout << "Valor editado com sucesso! \n";
        }
        else
        {
        system("cls");
        cout << "Opção inválida. Tente novamente. \n";

        }
        }
    }
}

int main(){
int valor,vChave,escolha;
bool sair = false;

(*ptLista).proximo = NULL;

    setlocale(LC_CTYPE, "Portuguese");
    cout << "Este algoritmo gerencia os valores de uma lista ENCADEADA, COM CHAVE, NÓ CABEÇA e ORDENADA!\n";

while (sair != true){
    cout << "Por favor, escolha uma opção no menu abaixo: \n\n";
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
            cout << "\nA lista está vazia ou o valor não foi encontrado! \n";
            cout << "******************************************************\n";
        }
        else {
            cout << "\nValor digitado encontrado, a informação nele armazenada é " << (*ponteiro).dado << "\n";
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
        cout << "Listando todos os nós: \n";
        Listar();
        cout << "\n";
        break;
    case 6:
    //SAIR;
        sair = true;
        cout << "\nExecução finalizada!";
        break;
    default:
    //EXCEÇÕES
        cout << "\nOpção inválida. Por favor, escolha novamente: ";
        cin >> escolha;
        break;
    }

    }
}
