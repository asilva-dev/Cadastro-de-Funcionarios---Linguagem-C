#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<string.h>
#include"lista.h"
#include"cargo.h"

int main(){

    setlocale(LC_ALL, "Portuguese");

    int opcao, n = 6, x,tamanho,contador;
    int op,id,c;
    int excluir;
    FUNC fun;


    Lista *li;
    lista_cargo *lic;


    li = cria_lista();
    lic = cria_lista_cargo();

    x = ler(li,fun);
    ler_cbo(lic);

    tamanho = tamanho_lista(li);

    x = lista_vazia(li);
    if(x)
    {
        printf("\nLista esta vazia\n");
    }
    else
    {
      printf("\nLista nao esta vazia\n\n");
    }
    system("cls");

    while(opcao !=n)
    {
        printf("\t\t************* ACME S.A. ************");
        printf("\n");
        printf("\n1 - Adicionar funcionario");
        printf("\n2 - Excluir funcionario");
        printf("\n3 - Editar funcionario");
        printf("\n4 - Buscar funcionario");
        printf("\n5 - Exibir funcionario com todos os dados");
        printf("\n6 - Sair da aplicacao");
        printf("\nSelecione uma opção para continuar:");
        scanf("%d",&opcao);
        system("cls");

    switch(opcao)
    {
        case 1:


             x=insere_lista(li,armazenar(lic));
             if(x)
             {
                 printf("\nUsuario cadastrado com sucesso!!!\n\n");
             }
             else
             {
                 printf("Erro no cadastro\n");
             }
             x = tamanho_lista(li);

             printf("\nQuantidade de funcionários cadastrados: %d\n\n",x);

             system("pause");
            break;
            system("cls");


        case 2:
               excluir_funcionario(li);
               system("pause");
               break;

        case 3:
                editarFuncionario(li);
                system("pause");
                break;


        case 4:
                exibir_funcionario(li);
                system("pause");
                break;

        case 5:
                printf("Quantidade de funcionários cadastrados: %d",tamanho);
                exibeFuncionarioOrdemID(li);
                system("pause");
                break;
                system("cls");

        case 6:
                x = gravar(li,fun);
                break;
                system("cls");

        default:
            break;
    }

            system("cls");
    }
}
