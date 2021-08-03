#include"funcoes.h"



main(){
    char tecla;
    int t;
    pergunta perguntaatual;
    char nome[100]="";
    int pontos=0,perguntasFeitas=0;
    int posicao=0;
    char resposta[100];
    struct nolista *aux;
    struct nolista *inicio;



  fila perguntas;


  lista ranking;
  createlist(&ranking);

   botao inicia,rank,op0,op1,op2,voltar;


    initwindow (larguraTela,alturaTela,"English Test Quiz",0,0);

    readimagefile("imagens/Cenario1.jpg",0,0,larguraTela,alturaTela);
    criaBotao(&inicia,"Start Game",210,470);
    criaBotao(&rank,"Ranking",210,570);


    setfillstyle(1,0);
    setcolor(15);
    setbkcolor(0);
    outtextxy(100,105, "Digite seu nome: ");

    setfillstyle(1,0);
    setcolor(15);
    setbkcolor(0);
    outtextxy(100,150, "Logo após tecle enter e inicie o jogo!");




    setfillstyle(1,0);
    setcolor(0);
    bar(250,100,500,130);
    setcolor(15);
    rectangle(250,100,500,130);
    tecla = 0;
    t=0;
    setfillstyle(1,0);
    setcolor(15);
    setbkcolor(0);
    while (tecla != 13)
    {
        tecla = getch();

        if (tecla== 8){//backspace
            bar(250,100,500,130);
            setcolor(15);
            rectangle(250,100,500,130);
            if(t>0){
                t--;
                nome[t] = ' ';
                outtextxy(280,105, nome);
            }
        }
        else{
            nome[t] = tecla;
            t++;
            outtextxy(280,105, nome);
        }


    }

    do{

        if(perguntasFeitas == quantidadeDePerguntas){
            perguntasFeitas=0;

            if(pontos>0){


                  setfillstyle(1,0);
                  setcolor(15);
                  setbkcolor(0);
                  outtextxy(100,180,"Confira o Ranking para ver seus pontos!");
                  Sleep(2500);



                pontosJogador jogador;
                strcpy(jogador.nomeJogador,nome);
                jogador.pontuacao=pontos;

                insertlist(&ranking,jogador);
            }



            readimagefile("imagens/Cenario2.jpg",0,0,larguraTela,alturaTela);
            criaBotao(&inicia,"Restart Game",210,470);
            criaBotao(&rank,"Ranking",210,570);
        }
        if(IdentificaBotao(inicia)){
            pontos=0;
            perguntasFeitas=0;

            create(&perguntas);
            GeraPerguntas(&perguntas);

            proximaPergunta(&perguntas,&perguntaatual,&op0,&op1,&op2);
        }
        else if (IdentificaBotao(op0)){
              if(0 == perguntaatual.respostacerta){
                  setfillstyle(1,2);
                  setcolor(15);
                  setbkcolor(2);
                  outtextxy(100,180,"Acertou");
                  pontos++;
              }
              else{
                  sprintf(resposta,"A resposta era :%s",
                          perguntaatual.respostas[perguntaatual.respostacerta]);
                  setfillstyle(1,4);
                  setcolor(15);
                  setbkcolor(4);
                  outtextxy(100,180,resposta);
              }
              Sleep(2000);
              perguntasFeitas++;
              proximaPergunta(&perguntas,&perguntaatual,&op0,&op1,&op2);
        }
        else if (IdentificaBotao(op1)){
              if(1 == perguntaatual.respostacerta){
                  setfillstyle(1,2);
                  setcolor(15);
                  setbkcolor(2);
                  outtextxy(100,180,"Acertou");
                  pontos++;
              }
              else{
                  sprintf(resposta,"A resposta era :%s",
                          perguntaatual.respostas[perguntaatual.respostacerta]);
                  setfillstyle(1,4);
                  setcolor(15);
                  setbkcolor(4);
                  outtextxy(100,180,resposta);
              }
              Sleep(2000);
              perguntasFeitas++;
              proximaPergunta(&perguntas,&perguntaatual,&op0,&op1,&op2);
        }
        else if (IdentificaBotao(op2)){
              if(2 == perguntaatual.respostacerta){
                  setfillstyle(1,2);
                  setcolor(15);
                  setbkcolor(2);
                  outtextxy(100,180,"Acertou");
                  pontos++;
              }
              else{
                  sprintf(resposta,"A resposta era :%s",
                          perguntaatual.respostas[perguntaatual.respostacerta]);
                  setfillstyle(1,4);
                  setcolor(15);
                  setbkcolor(4);
                  outtextxy(100,180,resposta);
              }
              Sleep(2000);
              perguntasFeitas++;
              proximaPergunta(&perguntas,&perguntaatual,&op0,&op1,&op2);
        }
        else if (IdentificaBotao(rank)){
            setcolor(15);
            bar(15,15,larguraTela,alturaTela);
            criaBotao(&voltar,"Voltar",600,100);

            if (!isEmptylist(ranking))
            {
                aux = ranking.inicio;
                setfillstyle(1,0);
                setcolor(15);
                setbkcolor(0);
                posicao=40;
                outtextxy(100,posicao,"Ranking");
                while (aux != NULL)
                {
                    posicao = posicao + 50;
                    char jogadorTemp[100];
                    sprintf(jogadorTemp,"\nNOME: %s - pontuacao: %d  ",aux->dado.nomeJogador,aux->dado.pontuacao);
                    setfillstyle(1,0);
                    setcolor(15);
                    setbkcolor(0);
                    outtextxy(100,posicao,jogadorTemp);
                    aux = aux->prox;


                }
            }


        }
        else if (IdentificaBotao(voltar)){
            pontos =0;
            perguntasFeitas = quantidadeDePerguntas;
        }

    }while(!kbhit());



closegraph;
}
