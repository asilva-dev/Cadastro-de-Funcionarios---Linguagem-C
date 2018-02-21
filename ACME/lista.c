#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#include "lista.h"
#include "cargo.h"

struct elemento{
    FUNC dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(){
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL)
    {
        *li = NULL;
    }
    return li;
}


destroi_lista(Lista *li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox)
            {
                aux = no;
                no = no->prox;
                free(aux);
            }
            free(no);
            free(li);
    }
}

tamanho_lista(Lista *li){
    if(li == NULL || (*li) == NULL)
    {
        return 0;
    }
    int acum = 0;
    Elem *no = *li;
    do
    {
        acum++;
        no = no->prox;
    }while(no != (*li));
    return acum;
}

lista_cheia(Lista * li){
    return 0;
}

lista_vazia(Lista *li){
    if(li == NULL || (*li) == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

int insere_lista_inicio(Lista *li,FUNC fun){
    if(li == NULL)
    {
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
    {
        return 0;
    }
    no->dados = fun;
    if((*li) == NULL)
    {
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li))
        {
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int insere_lista_final(Lista *li, FUNC fun){
    if(li == NULL)
    {
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof (Elem));
    if(no == NULL)
    {
        return 0;
    }
    no->dados = fun;
    if((*li) == NULL)
    {
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while (aux->prox != (*li))
            {
                aux->prox = no;
                no->prox = *li;
            }
            return 1;
        }
}

int insere_lista(Lista *li,FUNC fun){
    if(li == NULL)
        {
            return 0;
        }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
    {
        return 0;
    }
    no->dados = fun;
    if((*li) == NULL)
    {
        *li = no;
        no->prox = no;
        return 1;
    }else{
        if((*li)->dados.id > fun.id)
        {
            Elem *atual = *li;
            while(atual->prox != (*li))
            {
                atual = atual->prox;
            }
            no->prox = *li;
            atual->prox = no;
            *li = no;
            return 1;
        }

        Elem *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dados.id < fun.id)
        {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
    }
    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li == NULL)
    {
        return 0;
    }
    if((*li) == NULL)
    {
        return 0;
    }
    if((*li) == (*li)->prox)
    {
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while(atual->prox != (*li))
    {
        atual =atual->prox;
    }
    Elem *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista *li){
    if (li == NULL)
    {
        return 0;
    }
    if((*li) == NULL)
    {
        return 0;
    }
    if((*li) == (*li)->prox)
    {
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *no = *li;
    while(no->prox != (*li))
    {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista(Lista *li, int id){
    if(li == NULL)
    {
        return 0;
    }
    if((*li) == NULL)
    {
        return 0;
    }
    Elem *no = *li;
    if(no->dados.id == id)
    {
        if(no == no->prox)
        {
            free(no);
            *li = NULL;
            return 1;
        }else{
        Elem *ult = *li;
        while (ult->prox != (*li))
        {
            ult = ult->prox;
        }
        ult->prox = (*li)->prox;
        *li = (*li)->prox;
        free(no);
        return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    while(no !=(*li) && no->dados.id != id)
    {
        ant = no;
        no = no->prox;
    }
    if(no == *li)
    {
        return 0;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int consulta_lista_posicao(Lista *li,int posicao, FUNC *fun){
    if(li == NULL || (*li) == NULL || posicao <= 0)
    {
        return 0;
    }
    Elem * no = *li;
    int i = 1;
    while(no->prox != (*li) && i < posicao)
    {
        no = no->prox;
        i++;
    }
    if(i != posicao)
    {
        return 0;
    }else{
        *fun = no->dados;
        return 1;
    }
}

int consulta_lista_matricula(Lista *li, int id, FUNC *fun){
    if(li == NULL || (*li) == NULL)
    {
        return 0;
    }
    Elem *no = *li;


    while(no->prox != (*li) && no->dados.id != id)
    {
        no = no->prox;

    }
    if(no->dados.id != id)
    {
        return 0;
    }else{
        *fun = no->dados;
        return 1;
    }
}

FUNC armazenar(lista_cargo *cboc){

    int cargo;

    FUNC fun;


     printf("Digite o ID do funcionário: ");
            scanf("%d",&fun.id);

        printf("\nDigite o nome:");
            getchar();
            fgets(fun.nome,29,stdin);

        printf("\nDigite o endereço: ");
            fgets(fun.endereco,59,stdin);

        printf("\nDigite a idade: ");
            scanf("%d",&fun.idade);

        printf("\nDigite o Salário: ");
            scanf("%f",&fun.salario);
         imprimir_cbo(cboc);
        printf("\nDigite o cargo do funcionario: ");
        scanf("%d", &cargo);
       fun.cargo = consulta_lista_cargo_gravacbo(cboc,cargo);

        return fun;
}

int gravar(Lista *li,FUNC fun){
    int opcao;
    FILE *arq = fopen("func.txt","wb");

	if(arq == NULL)
    {
		printf("Erro na Abertura\n");
		system("pause");
	}

        int tamanho,contador;
        tamanho = tamanho_lista(li);
        contador=1;
    printf("Salvar modificações ao fechar o programa \n\n[1]-Sim.\n\n[2]-Não.\n\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                     while(contador <= tamanho)
                     {
                          consulta_lista_posicao(li,contador,&fun);
                          fwrite(&fun,sizeof(FUNC),1,arq);
                          contador =  contador+1;
                     }
                     printf("\nPrograma Finalizado com sucesso\n");
                     break;
            case 2:
                    printf("\nO programa sera encerrado sem gravar altercações\n");
                    break;
        }
	fclose(arq);
	system("pause");

}


int ler(Lista *li, FUNC fun){
    int x;
    FILE *arq = fopen("func.txt","rb");

	if(arq == NULL)
    {
		printf("Erro, na abertura do arquivo!!!\n\n");
		system("pause");
	}
    else
    {
        while(fread(&fun,sizeof(FUNC),1,arq) != NULL)
        {
            imprimir(fun);
           x = insere_lista(li,fun);
        }
    }
	fclose(arq);
    system("cls");
}

void imprimir(FUNC fun){

        printf("\n\nID: %d",fun.id);
        printf("\nNome: %s",fun.nome);
        printf("Endereço: %s",fun.endereco);
        printf("Idade: %d",fun.idade);
        printf("\nSalário: %.2f",fun.salario);
        printf("\nCodigo do cargo: %d",fun.cargo);
        /* (fun.cargo){
           printf("\nCargo: Dirigentes gerais da administração pública\n");
        } else if (fun.cargo = '1113'){
           printf("\nCargo: Magistrados\n");
        } */

}
void editarFuncionario(Lista *li){

    int cod = NULL, resposta,x;
    float dissidio;
    FUNC fun;
    FUNC aux;
    FUNC mudados;

int tamanho,contador;
    if(lista_vazia(li))
    {
        printf("Nao existem funcionarios cadastrados\n\n");
    }
    else
    {
        tamanho = tamanho_lista(li);
        contador=1;

         printf("\n***** Dados do funcionário *****\n");

        while(contador <= tamanho)
        {
            consulta_lista_posicao(li,contador,&fun);
            imprimir(fun);
            contador =  contador +1;
        }
    }
        do
        {
             printf("\nInforme o ID do funcionario que deseja editado: ");
                scanf("%d", &cod);

        system("cls");

        x = consulta_lista_matricula(li,cod,&fun);

        if(x)
        {
            printf("***** Dados do funcionário *****n");
            imprimir(fun);
            do
            {
                printf("\nEscolha a opção desejada:\n\n[1]- Alterar dissidio salarial.\n\n[2]- Editar informações do funcionario.\n");
                    scanf("%d", &resposta);
                    system("cls");
            }while(resposta != 1 && 2);

            switch(resposta)
            {
                case 1:
                    printf("\nQual a porcentagem do dissidio a ser aplicada?\nEX:5 = 5%%\n\n");
                    scanf("%f", &dissidio);

                    fun.salario = (1+(dissidio/100)) * fun.salario;
                    printf("\nNovo salario: %.2f\n\n", fun.salario);
                     aux = fun;
                    if(fun.id != cod)
                    {
                        return 0;
                    }
                    else
                    {
                        remove_lista(li,cod);
                        insere_lista(li,aux);
                        return 1;
                    }
                    break;
                    system("cls");

                case 2:

                    printf("\nDigite o nome:");
                    getchar();
                    fgets(fun.nome,29,stdin);

                    printf("\nDigite o endereço: ");
                        fgets(fun.endereco,59,stdin);

                    printf("\nDigite a idade: ");
                        scanf("%d",&fun.idade);

                    printf("\nDigite o Salário: ");
                        scanf("%f",&fun.salario);

                        mudados = fun;

                    if(fun.id != cod)
                    {
                        return 0;
                    }
                    else
                    {
                        remove_lista(li,cod);
                        insere_lista(li,mudados);
                        return 1;
                    }
                    break;
            }
        }
        exibeFuncionarioOrdemID(li);
        printf("\nNao existe funcionario com o ID informado!\n\n");
        }while(cod != x);

}

void excluir_funcionario(Lista *li){
    FUNC fun;
    int tamanho, contador, id, x, excluir;

    tamanho = tamanho_lista(li);
    contador=1;

    printf("\nQuantidade de funcionários cadastrados: %d\n",tamanho);

     do
     {
         exibeFuncionarioOrdemID(li);
         printf("\n\nDigite O ID que deseja remover: ");
            scanf("%d",&id);

         system("cls");

         x = consulta_lista_matricula(li,id,&fun);
         if(x)
         {
             printf("***** Dados do funcionário *****n");
             imprimir(fun);

             printf("\nDeseja remover o funcionário?\n1-Sim\n2-Não\n");
                scanf("%d",&excluir);

                 switch(excluir)
                 {
                     case 1:
                            x = remove_lista(li,id);
                            printf("\nFuncionario removido na posicao especifica com sucesso!\n\n");
                      break;

                     case 2:
                            printf("\nO Programa voltara ao menu inicial \n\n");
                            return 0;
                      break;

                     default:
                            printf("Essa opção não existe!!!\n");
                        break;
                }

        }
        else
        {
            printf("Esse ID não existe!\n");
        }
     }while(id != x);
}

void exibir_funcionario(Lista *li){
    FUNC fun;
    int id, x;

    printf("Digite O ID que deseja procurar: ");
        scanf("%d",&id);

    x = consulta_lista_matricula(li,id,&fun);
    if(fun.id == id)
    {
        imprimir(fun);
    }
    else
    {
        printf("\nErro,Consulta nao realizada!\n");
    }
}

void exibeFuncionarioOrdemID(Lista *li){
    FUNC fun;
    int tamanho, contador;

    tamanho = tamanho_lista(li);
    contador=1;


    printf("\n\n***** Dados do funcionário *****n");
    while(contador <= tamanho)
    {
        consulta_lista_posicao(li,contador,&fun);
        imprimir(fun);
        contador =  contador +1;
    }
}
