#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cargo.h"

typedef struct lista_cargo{
    int qtd;
    struct cbo_cargo dados[MAX];

}lista_cargo;

lista_cargo *cria_lista_cargo(){
    lista_cargo *li;
    li = (lista_cargo*) malloc(sizeof(struct lista_cargo));
    if (li != NULL){
        li->qtd=0;
    }
    return li;
}

void libera_listac(lista_cargo *li){
    free(li);
}

int tamanho_lista_cargo(lista_cargo *li){
   if (li == NULL){
        return -1;
    }else{
        return li ->qtd;
    }
}

int lista_cargo_cheia(lista_cargo *li){
   if (li == NULL){
        return -1;
    }else{
        return (li->qtd == MAX);
    }
}

int lista_cargo_vazia(lista_cargo *li){
   if (li == NULL){
        return -1;
    }else{
        return (li->qtd == 0);
    }
}

int insere_lista_cargo_inicio(lista_cargo *li,cboc al){
   if (li == NULL){
        return 0;
    }
    if(lista_cargo_cheia(li)){

        return 0;
    }
    int i;
    for(i=li->qtd - 1;i>=0;i--){
    	li->dados[i+1] = li->dados[i];
	}
    li->dados[0] = al;
    li->qtd++;
    return 1;
}
int insere_lista_cargo_final(lista_cargo *li, cboc al){
   if (li == NULL){
        return 0;
    }
    if(lista_cargo_cheia(li)){

        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}
int insere_lista_cargo_ordenada(lista_cargo *li, cboc al){
   if (li == NULL){
        return 0;
    }
    if(lista_cargo_cheia(li)){

        return 0;
    }
    int k,i=0;
    while(i<li->qtd && li->dados[i].id<al.id){
    	i++;
	}
    for(k=li->qtd - 1;k>=i;k--){
    	li->dados[k+1] = li->dados[k];
	}
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_cargo_final(lista_cargo *li){
	if (li == NULL){
        return 0;
    }
    if (li->qtd == 0){
    	return 0;
	}
	li->qtd--;
	return 1;
}


int remove_lista_cargo_inicio(lista_cargo *li){
	if (li == NULL){
        return 0;
    }
    if (li->qtd == 0){
    	return 0;
	}
	 int k=0;

    for(k=0;k<li->qtd-1;k++){
    	li->dados[k] = li->dados[k+1];
	}
	li->qtd--;
	return 1;
}

int remove_lista_cargo(lista_cargo *li,int id){
   if (li == NULL){
        return 0;
    }
   if (li->qtd == 0){
    	return 0;
	}
    int k,i=0;
    while(i<li->qtd && li->dados[i].id != id){
    	i++;
	}

    if (i == li->qtd){
    	return 0;
	}
    for(k=i;k<li->qtd-1;k++){
    	li->dados[k] = li->dados[k+1];
	}
    li->qtd--;
    return 1;
}

int consulta_listac_pos(lista_cargo * li, int pos, cboc *al){
	if(li == NULL || pos<=0 || pos>=li->qtd){
		return 0;
	}
	*al = li->dados[pos-1];
	return 1 ;
}
int consulta_lista_cargo_gravacbo(lista_cargo *li, int pos){

    printf("\nFuncionario cadastrado");

    if(li == NULL || pos <= 0 || pos >= li->qtd+1){

        return 0;

          printf("Não localizado");
    }

    return li->dados[pos-1].id;


}

int consulta_lista_cargo_mat(lista_cargo * li, int id, cboc *al){
	 if (li == NULL){
        return 0;
    }
      int k,i=0;
    while(i<li->qtd && li->dados[i].id != id){
    	i++;
	}
	if (i == li->qtd){
    	return 0;
	}
	*al = li->dados[i];
	return 1 ;
}

void ler_cbo(lista_cargo *li){
    FILE *f;
    struct cbo_cargo cfun;
    char idcbo[4],p[100],c[500];
    f=fopen("cargosCBO.txt","r");
    while(fgets(c,100,f)){

    strtok(c,";");
    strcpy(idcbo,c);

    strcpy(p,strtok(NULL,"\n"));
    printf("");

    cfun.id=atoi(idcbo);
    strcpy(cfun.nome,p);
    insere_lista_cargo_final(li,cfun);

    }

}
void imprimir_cbo(lista_cargo *li){
    int c;
    int i=li->qtd;
    struct cbo_cargo q;
    for(c=1; c<i+1; c++){
        consulta_listac_pos(li,c,&q);
        printf("%d - %s\n",c,q.nome);
    }
}





