typedef struct funcionario{
    int id;
    char nome[30];
    char endereco[60];
    int idade;
    float salario;
    int cargo;

}FUNC;

typedef struct elemento *Lista;

Lista *cria_lista();

int destroi_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_lista_inicio(Lista *li, FUNC fun);

int insere_lista_final(Lista *li, FUNC fun);

int insere_lista(Lista *li, FUNC fun);

int remove_lista_inicio(Lista *li);

int remove_lista_final(Lista *li);

int remove_lista(Lista *li, int id);

int consulta_lista_posicao(Lista *li, int posicao, FUNC *fun);

int consulta_lista_matricula(Lista *li, int id, FUNC *fun);

FUNC armazenar();

void imprimir(FUNC fun);

void exibeFuncionarioOrdemID(Lista *li);

int gravar(Lista *li,FUNC fun);

int ler(Lista *li, FUNC fun);

void editarFuncionario(Lista *li);

void excluir_funcionario(Lista *li);

void exibir_funcionario(Lista *li);




