#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <graphics.h>

#define TRUE 1
#define FALSE 0
#define quantidadeDePerguntas 20
#define alturaTela 700
#define larguraTela 1340


typedef struct {
    char pergunta[20];
    int respostacerta;
    char respostas[3][30];
} pergunta;

typedef struct {
    char nomeJogador[20];
    int pontuacao;

} pontosJogador;

//Fila..............................................................
struct no //Fila
{
    pergunta dado;
    struct no *prox;
};

typedef struct //Fila
{
    struct no *inicio;
    struct no *fim;
} fila;



void create(fila *q)
{
    q->inicio=NULL;
    q->fim=NULL;
}


int insert (fila *q, pergunta d)
{
    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    if (aux==NULL)
        return (FALSE);
    aux->dado=d;
    aux->prox=NULL;
    if (q->inicio==NULL)
        q->inicio=aux;
    if (q->fim!=NULL)
        q->fim->prox=aux;
    q->fim=aux;
    return(TRUE);
}


int remove (fila *q, pergunta *d)
{
    struct no *aux;
    if (q->inicio==NULL)
        return (FALSE);
    aux=q->inicio;
    q->inicio=aux->prox;
    if (q->inicio == NULL)
        q->fim = NULL;
    *d=aux->dado;
    free(aux);
    return(TRUE);
}

//Imprime Fila
void imprimefila(fila q)
{
    struct no *aux;
    aux = q.inicio;

    if (aux != NULL)
    {
        while (aux != NULL)
        {
            printf("\nPergunta:%s Resposta:%d Opcoes: %s, %s, %s",
                   aux->dado.pergunta,
                   aux->dado.respostacerta,
                   aux->dado.respostas[0],
                   aux->dado.respostas[1],
                   aux->dado.respostas[2]);
            aux = aux->prox;
        }
    }
    else
    {
        printf("\nFila vazia...");
    }
}


int isEmpty(fila q)
{

    if (q.inicio==NULL)
        return (true);
    else
        return(false);
}

//Lista...........................................
struct nolista //lista
{
    struct nolista *ant;
    pontosJogador dado;
    struct nolista *prox;
};

typedef struct //lista
{
    struct nolista *inicio;
    struct nolista *fim;
} lista;


void createlist(lista *q)
{
    q->inicio=NULL;
    q->fim=NULL;
}

int insertlist(lista *q, pontosJogador d)
{
    struct nolista *aux;
    if(q->inicio == NULL)
    {
        aux=(struct nolista*)malloc(sizeof(struct nolista));
        if (aux==NULL)
            return (FALSE);
        aux->dado = d;
        q->inicio = aux;
        q->fim = aux;
        aux->prox = NULL;
        aux-> ant = NULL;
        return (TRUE);
    }
    aux=(struct nolista*)malloc(sizeof(struct nolista));
    if (aux==NULL)
        return (FALSE);
    aux->dado = d;
    aux->prox = NULL;
    aux->ant = q->fim;
    q->fim->prox = aux;
    q->fim = aux;
    return (TRUE);
}
//verifica lista vazia
int isEmptylist(lista q)
{
    if (q.inicio == NULL)
        return (TRUE);
    else
        return (FALSE);
}
//imprime lista
void imprimelist(lista q)
{
    struct nolista *aux;
    if (!isEmptylist(q))
    {
        aux = q.inicio;
        printf("\nMostrando Lista\n");
        while (aux != NULL)
        {
            printf("\nNOME: %s - pontuacao: %d  ",aux->dado.nomeJogador,aux->dado.pontuacao);
            aux = aux->prox;

        }
        printf("\n\n");
    }
}


//Botao ...........................................................
typedef struct
{
    int x;
    int y;
    int altura;
    int comprimento;
} botao;

//Botao
void drawButton(char label[], int x, int y, int subli)
{
        setfillstyle(1,7);
        setlinestyle(0,1,1);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);

        bar(x,y,x+textwidth(label)+22,y+30);
        setcolor(0);
        setbkcolor(7);
        outtextxy(x+6,y+2,label);
        setcolor(15);
        line(x,y,x,y+30);
        line(x,y,x+textwidth(label)+22,y);
        setcolor(8);
        line(x+textwidth(label)+22,y,x+textwidth(label)+22,y+30);
        line(x+textwidth(label)+22,y+30,x,y+30);

}

void criaBotao(botao *bot,char texto[],int x,int y)
{
    bot->x = x;
    bot->y = y;
    drawButton(texto,x,y,0);
    bot->comprimento = x+ textwidth(texto)+22;
    bot->altura = y+ 30;
}

int IdentificaBotao(botao bot)
{
    if (mousex() >= bot.x && mousex() <= bot.comprimento &&
            mousey() >= bot.y && mousey() <= bot.altura &&
            ismouseclick(WM_LBUTTONDOWN) )
    {
            clearmouseclick(WM_LBUTTONDOWN);
            return(true);
    }
    return(false);
}





void GeraPerguntas(fila *perguntas)
{
    pergunta criaperguntas[quantidadeDePerguntas];

    strcpy(criaperguntas[0].pergunta,"imagens/1.jpg");
    criaperguntas[0].respostacerta=0;
    strcpy(criaperguntas[0].respostas[0],"use");
    strcpy(criaperguntas[0].respostas[1],"using");
    strcpy(criaperguntas[0].respostas[2],"uze");

    strcpy(criaperguntas[1].pergunta,"imagens/2.jpg");
    criaperguntas[1].respostacerta=2;
    strcpy(criaperguntas[1].respostas[0],"drink");
    strcpy(criaperguntas[1].respostas[1],"drunk");
    strcpy(criaperguntas[1].respostas[2],"drinks");

    strcpy(criaperguntas[2].pergunta,"imagens/3.jpg");
    criaperguntas[2].respostacerta=1;
    strcpy(criaperguntas[2].respostas[0],"Eu leio os papeis");
    strcpy(criaperguntas[2].respostas[1],"Eu leio o jornal");
    strcpy(criaperguntas[2].respostas[2],"Eu leio as noticias");

    strcpy(criaperguntas[3].pergunta,"imagens/4.jpg");
    criaperguntas[3].respostacerta=1;
    strcpy(criaperguntas[3].respostas[0],"Onion");
    strcpy(criaperguntas[3].respostas[1],"Ice cream");
    strcpy(criaperguntas[3].respostas[2],"Tomato");

    strcpy(criaperguntas[4].pergunta,"imagens/5.jpg");
    criaperguntas[4].respostacerta=1;
    strcpy(criaperguntas[4].respostas[0],"Spider");
    strcpy(criaperguntas[4].respostas[1],"Whale");
    strcpy(criaperguntas[4].respostas[2],"Owl");

    strcpy(criaperguntas[5].pergunta,"imagens/6.jpg");
    criaperguntas[5].respostacerta=0;
    strcpy(criaperguntas[5].respostas[0],"Eu acordei tarde");
    strcpy(criaperguntas[5].respostas[1],"Eu acordo tarde");
    strcpy(criaperguntas[5].respostas[2],"Eu acordo depois");

    strcpy(criaperguntas[6].pergunta,"imagens/7.jpg");
    criaperguntas[6].respostacerta=0;
    strcpy(criaperguntas[6].respostas[0],"Estamos avançando ");
    strcpy(criaperguntas[6].respostas[1],"Somos avançados");
    strcpy(criaperguntas[6].respostas[2],"Nós avançamos ");

    strcpy(criaperguntas[7].pergunta,"imagens/8.jpg");
    criaperguntas[7].respostacerta=0;
    strcpy(criaperguntas[7].respostas[0],"O suco de uva");
    strcpy(criaperguntas[7].respostas[1],"A ameixa suculenta");
    strcpy(criaperguntas[7].respostas[2],"A uva suculenta");

    strcpy(criaperguntas[8].pergunta,"imagens/9.jpg");
    criaperguntas[8].respostacerta=1;
    strcpy(criaperguntas[8].respostas[0],"is");
    strcpy(criaperguntas[8].respostas[1],"are");
    strcpy(criaperguntas[8].respostas[2],"had");

    strcpy(criaperguntas[9].pergunta,"imagens/10.jpg");
    criaperguntas[9].respostacerta=2;
    strcpy(criaperguntas[9].respostas[0],"Está legal hoje");
    strcpy(criaperguntas[9].respostas[1],"Posso isso hoje");
    strcpy(criaperguntas[9].respostas[2],"Está frio hoje");

    strcpy(criaperguntas[10].pergunta,"imagens/11.jpg");
    criaperguntas[10].respostacerta=1;
    strcpy(criaperguntas[10].respostas[0],"Eu sempre erro");
    strcpy(criaperguntas[10].respostas[1],"Eu sempre escrevi");
    strcpy(criaperguntas[10].respostas[2],"Eu nunca errei");

    strcpy(criaperguntas[11].pergunta,"imagens/12.jpg");
    criaperguntas[11].respostacerta=2;
    strcpy(criaperguntas[11].respostas[0],"Somos elegantes");
    strcpy(criaperguntas[11].respostas[1],"Nós somos espertos ");
    strcpy(criaperguntas[11].respostas[2],"Nós estamos bem ");

    strcpy(criaperguntas[12].pergunta,"imagens/13.jpg");
    criaperguntas[12].respostacerta=0;
    strcpy(criaperguntas[12].respostas[0],"Eu ensino um idioma");
    strcpy(criaperguntas[12].respostas[1],"Eu aprendo um idioma");
    strcpy(criaperguntas[12].respostas[2],"Eu trago um idioma");

    strcpy(criaperguntas[13].pergunta,"imagens/14.jpg");
    criaperguntas[13].respostacerta=2;
    strcpy(criaperguntas[13].respostas[0],"don't");
    strcpy(criaperguntas[13].respostas[1],"doing");
    strcpy(criaperguntas[13].respostas[2],"do");

    strcpy(criaperguntas[14].pergunta,"imagens/15.jpg");
    criaperguntas[14].respostacerta=1;
    strcpy(criaperguntas[14].respostas[0],"Tiger");
    strcpy(criaperguntas[14].respostas[1],"Cat");
    strcpy(criaperguntas[14].respostas[2],"Crab");

    strcpy(criaperguntas[15].pergunta,"imagens/16.jpg");
    criaperguntas[15].respostacerta=1;
    strcpy(criaperguntas[15].respostas[0],"one");
    strcpy(criaperguntas[15].respostas[1],"a");
    strcpy(criaperguntas[15].respostas[2],"of");

    strcpy(criaperguntas[16].pergunta,"imagens/17.jpg");
    criaperguntas[16].respostacerta=0;
    strcpy(criaperguntas[16].respostas[0],"did");
    strcpy(criaperguntas[16].respostas[1],"do");
    strcpy(criaperguntas[16].respostas[2],"doing");

    strcpy(criaperguntas[17].pergunta,"imagens/18.jpg");
    criaperguntas[17].respostacerta=1;
    strcpy(criaperguntas[17].respostas[0],"Pode parar!");
    strcpy(criaperguntas[17].respostas[1],"Voce nao pode parar!");
    strcpy(criaperguntas[17].respostas[2],"Voce nao vai parar!");

    strcpy(criaperguntas[18].pergunta,"imagens/19.jpg");
    criaperguntas[18].respostacerta=1;
    strcpy(criaperguntas[18].respostas[0],"Que valor é esse?");
    strcpy(criaperguntas[18].respostas[1],"Qual o novo valor?");
    strcpy(criaperguntas[18].respostas[2],"Qual é o valor?");

    strcpy(criaperguntas[19].pergunta,"imagens/20.jpg");
    criaperguntas[19].respostacerta=0;
    strcpy(criaperguntas[19].respostas[0],"but,also");
    strcpy(criaperguntas[19].respostas[1],"more,too");
    strcpy(criaperguntas[19].respostas[2],"but,too");






    int i;
    for(i=0;i<quantidadeDePerguntas;i++)
        insert(perguntas,criaperguntas[i]);


}


void proximaPergunta(fila *perguntas,pergunta *perguntaatual, botao *op0, botao *op1, botao *op2){
        remove(perguntas,perguntaatual);
        readimagefile(perguntaatual->pergunta,0,0,larguraTela,alturaTela);

        criaBotao(op0,perguntaatual->respostas[0],410,520);
        criaBotao(op1,perguntaatual->respostas[1],610,520);
        criaBotao(op2,perguntaatual->respostas[2],810,520);

}


