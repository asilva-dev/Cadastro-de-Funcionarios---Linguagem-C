#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct cbo_cargo{
    int id;
    char nome[70];

}cboc;

typedef struct lista_cargo lista_cargo;

lista_cargo *cria_lista_cargo();

int tamanho_lista_cargo(lista_cargo *li);
int lista_cargo_cheia(lista_cargo *li);
int lista_cargo_vazia(lista_cargo *li);
int insere_lista_cargo_final(lista_cargo *li,cboc al);
int insere_lista_cargo_inicio(lista_cargo *li,cboc al);
int insere_lista_cargo_ordenada(lista_cargo *li, cboc al);
int remove_lista_cargo_final(lista_cargo *li);
int remove_lista_cargo_inicio(lista_cargo *li);
int remove_lista_cargo(lista_cargo *li,int id);
int consulta_lista_cargo_pos(lista_cargo * li, int pos,cboc *al);
int consulta_lista_cargo_mat(lista_cargo * li, int mat,cboc *al);
int consulta_lista_cargo_gravacbo(lista_cargo *li, int pos);
void libera_lista_cargo(lista_cargo *li);





