#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void);

//Salva os dados em arquivo txt criando ou dando append se for um gasto em um mes que ja houve gasto
void salvaDados(){
  int categoria, dia, mes, ano, i=0, cont=0, rg;
  float valor;
  char descricao[200], file[100], conteudo[100];


  printf("Será adicionado uma receita ou um gasto?\n");
  printf("\t1-Receita 2-Gasto\n");
  scanf("%d",&rg);
  if(rg!=1 && rg!=2){
    while(1){
      int r=0;
      printf("Número Inválido!\n");
      printf("1 - Voltar ao Menu\n");
      printf("2 - Adicionar um gasto ou receita\n");
      scanf("%d",&r);
      if(r==1){
        main();
      }
      else if(r==2){
        salvaDados();
      }
    }
  }

  //Input da categoria
  if(rg==1){
    printf("Como que o dinheiro foi recebido?\n");
  }
  if(rg==2){
    printf("Para que o dinheiro foi usado?\n");
  }
  printf("\t1-Moradia 2-Estudos 3-Transporte 4-Alimentação 5-Trabalho 6-Extra(algo não essencial)\n");
  scanf("%d",&categoria);
  if(categoria!=1 && categoria!=2 && categoria!=3 && categoria!=4 && categoria!=5 && categoria!=6){
    while(1){
      int r=0;
      printf("Número Inválido!\n");
      printf("1 - Voltar ao Menu\n");
      printf("2 - Adicionar um gasto ou receita\n");
      scanf("%d",&r);
      if(r==1){
        main();
      }
      else if(r==2){
        salvaDados();
      }
    }
  }
  
  //Input do valor gasto
  if(rg==1){
    printf("Quanto foi recebido em reais?\n");
    scanf("%f",&valor);
  }
  if(rg==2){
    printf("Quanto foi gasto em reais?\n");
    scanf("%f",&valor);
  }
  
  

  printf("Descrição sobre a movimentação:\n");
   /* limpa stdin */
    int ch;
    do {
        ch = getchar();
        if (ch == '\n') break;
        if (ch == EOF) break; // erro?
    }while (1);
    
  fgets(descricao,200,stdin);

  
  //Input do dia quando foi gasto
  printf("Data do gasto:\n");
  printf("\tDia:\n");
  scanf("%d",&dia);
  printf("\tMês:\n");
  scanf("%d",&mes);
  printf("\tAno:\n");
  scanf("%d",&ano);
  if(dia>31 || mes>12 || mes<1 || dia<1){
    while(1){
      int r=0;
      printf("Data Inválida!\n");
      printf("1 - Voltar ao Menu\n");
      printf("2 - Adicionar um gasto ou receita\n");
      scanf("%d",&r);
      if(r==1){
        main();
      }
      else if(r==2){
        salvaDados();
      }
    }
  }
  int b=0;
  while(b!=1){
    int res=0;
    printf("Confirmar Dados:\n");
    printf("1 - Tudo Certo\n");
    printf("2 - Cancelar e colocar os dados novamente\n");
    printf("3 - Cancelar e voltar para o Menu\n");
    scanf("%d",&res);
    if(res==1){
      b=1;
    }
    else if(res==2){
      salvaDados();
    }
    else if(res==3){
      main();
    }
    else{
      printf("Resposta Inválida!\n");
    }
  }

  //Criando o nome do arquivo txt q sera aberto ou ira dar append
  sprintf(file,"%d %d .txt",mes, ano);
  //Criando o que sera salvo dentro do txt
  sprintf(conteudo,"%d %d %.2f %d %d %d %s\n", rg,categoria ,valor, dia, mes, ano, descricao);
  //Contando o tamanho da str
  while (conteudo[i]!=0){
    i++;
    cont++;
  }
  //Mexendo no txt
  FILE* fr = fopen(file,"a+");
  fwrite(conteudo , 1 , cont , fr );
  fclose(fr);
}

void relHtml12M(){
  int mes, ano, mc, ac, exit=1, cont=0, i=0, cont1=0;
  char file[100], file2[100], conteudo[100];
  printf("Digite a data (Mês/Ano) para gerar o relatório dos 12 meses anteriores:\n");
  printf("\tMês:\n");
  scanf("%d",&mes);
  printf("\tAno:\n");
  scanf("%d",&ano);
  if(mes>12 || mes<1){
    while(1){
      int r=0;
      printf("Data Inválida!\n");
      printf("1 - Voltar ao Menu\n");
      printf("2 - Gerar um relatório de movimentação dos 12 meses anteriores a algum mês\n");
      scanf("%d",&r);
      if(r==1){
        main();
      }
      else if(r==2){
        relHtml12M();
      }
    }
  }
  int b=0;
  while(b!=1){
    int res=0;
    printf("Confirmar Dados:\n");
    printf("1 - Tudo Certo\n");
    printf("2 - Cancelar e colocar os dados novamente\n");
    printf("3 - Cancelar e voltar para o Menu\n");
    scanf("%d",&res);
    if(res==1){
      b=1;
    }
    else if(res==2){
      relHtml12M();
    }
    else if(res==3){
      main();
    }
    else{
      printf("Resposta Inválida!\n");
    }
  }
  mc=mes;
  ac=ano;

  while(exit!=0){
    //Criando o nome do arquivo txt q sera aberto ou ira dar append
    sprintf(file,"%d %d .txt",mes, ano);

    int rg, c, d, m, a, y=1, ex=1, i=0, cont=0;
    float v;
    char des[200];
    FILE *fp;
    fp = fopen(file,"r");
      if( fp == NULL ){
        y=0;
      }
      else{
        while((fscanf(fp,"%d %d %f %d %d %d %[^\n]s \n", &rg, &c, &v, &d, &m, &a, des)) != EOF){
          sprintf(conteudo,"%d %d %.2f %d %d %d %s \n", rg, c, v, d, m, a, des);
        
          //Contando o tamanho da str
          ex=1;
          i=0;
          cont=0;
          while (ex!=0){
            i++;
            cont++;
            if(conteudo[i]==10){
              cont++;
              ex=0;
            }
          }
        
         
          sprintf(file2,"Rel 12 meses de: %d %d .txt", mc, ac);
          FILE* fr = fopen(file2,"a+");
          fwrite(conteudo , 1 , cont , fr );
          fclose(fr);
          
        }
        fclose(fp);
      }

    if(mes==1){
      mes=12;
      ano--;
      cont1++;
    }
    else{
      mes--;
      cont1++;
    }
    if(cont1==12){
      exit=0;
    }
  }

  if(conteudo[0]!='1' && conteudo[0]!='2'){
    printf("Não há nenhum dado sobre esse mês ou os doze meses anteriores a ele\n");
    while(1){
      int r=0;
      printf("1 - Voltar ao Menu\n");
      printf("2 - Gerar um relatório de movimentação dos 12 meses anteriores a algum mês\n");
      scanf("%d",&r);
      if(r==1){
        main();
      }
      else if(r==2){
        relHtml12M();
      }
      else{
        printf("Resposta Inválida!");
      }
    }
  }

  char html[100], des[200];
  int rg, c, d, m, a;
  float v, soma=0, gastos=0, ganhos=0, poupanca=0, banco=0, ganhos50=0;


  sprintf(html,"Rel 12 meses de: %d %d .html", mc, ac);


  FILE *ptrFile = fopen( html, "w"); 
  i=0; 

  fprintf( ptrFile, "<HTML>\n "); 
  fprintf( ptrFile, "<HEAD> <TITLE> Relatorio 12 Meses </TITLE> </HEAD>\n" ); 
  fprintf( ptrFile, "<BODY BGCOLOR=\"#110022\" TEXT=\"#FFBBAA\"> \n"); 
  fprintf( ptrFile, "<h1 align=center>Relatório de movimentação dos 12 meses anteriores a %d/%d</h1>\n",mc,ac);
 
  FILE *fp;
  fp = fopen(file2,"r");

  fprintf( ptrFile, "<div align=center>\n");
  while((fscanf(fp,"%d %d %f %d %d %d %[^\n]s \n", &rg, &c, &v, &d, &m, &a, des)) != EOF){
    if(rg==1){
      fprintf( ptrFile, "<li><h2>Receita:</h2></li>\n");
      soma+=v;
      ganhos+=v;
    }
    else if(rg==2){
      fprintf( ptrFile, "<li><h2>Gasto:</h2></li>\n");
      soma-=v;
      gastos+=v;
    }
    
    if(c==1){
      fprintf( ptrFile, "<h3>Categoria: Moradia</h3>\n");
    }
    else if(c==2){
      fprintf( ptrFile, "<h3>Categoria: Estudos</h3>\n");
    }
    else if(c==3){
      fprintf( ptrFile, "<h3>Categoria: Transporte</h3>\n");
    }
    else if(c==4){
      fprintf( ptrFile, "<h3>Categoria: Alimentação</h3>\n");
    }
    else if(c==5){
      fprintf( ptrFile, "<h3>Categoria: Trabalho</h3>\n");
    }
    else if(c==6){
      fprintf( ptrFile, "<h3>Categoria: Extra(algo não essencial)</h3>\n");
    }
    fprintf( ptrFile, "<p>Data:%d/%d/%d</p>\n",d,m,a);
    fprintf(ptrFile,"<h3>Descrição: %s</h3>\n", des);
    if(rg==1){
      fprintf( ptrFile, "<p>Valor da Receita: R$%.2f</p>\n\n",v);
    }
    else if(rg==2){
      fprintf( ptrFile, "<p>Valor Gasto: R$%.2f</p>\n\n",v);
    }
  }
  ganhos50 = ganhos/2;
  poupanca=ganhos50*0.054;
  banco=ganhos50*0.074;

  fprintf( ptrFile, "<li><h2>Diferença entre os ganhos e os gastos nos 12 meses: R$%.2f</h2></li>\n",soma);
  fprintf( ptrFile, "<li><h3>Total ganho nos 12 meses: R$%.2f</h3></li>\n",ganhos);
  fprintf( ptrFile, "<li><h3>Total gasto nos 12 meses: R$%.2f</h3></li>\n",gastos);

  fprintf( ptrFile, "<li><h2>Investimento:</h2></li>\n");
  fprintf( ptrFile, "<h2>Se pelo menos 50%% dos ganhos tivessem sido investidos em uma poupança com uma média de 5.4%% de lucro ao ano:</h2>\n");
  fprintf( ptrFile, "<h3>O lucro seria de: R$%.2f</h3>\n",poupanca);
  fprintf( ptrFile, "<h3>Dando um total de: R$%.2f</h3>\n",poupanca+ganhos50);

  fprintf( ptrFile, "<h2>Se pelo menos 50%% dos ganhos tivessem sido investidos em um banco que chega a ter 7.4%% de lucro ao ano:</h2>\n");
  fprintf( ptrFile, "<h3>O lucro seria de: R$%.2f</h3>\n",banco);
  fprintf( ptrFile, "<h3>Dando um total de: R$%.2f</h3>\n",banco+ganhos50);
  
  fprintf( ptrFile, "<h1>Media por mês gasta: R$%.2f</h1>\n\n",gastos/12);
  fprintf( ptrFile, "</div>\n");
  fclose(fp);

  fprintf( ptrFile, "</BODY>\n"); 
  fprintf( ptrFile, "</HTML>"); 
  fclose( ptrFile );

  FILE *fr;
  fr = fopen(file2,"w");
  fclose(fr);

}

void catMes(){
  int mes, ano, rg, c, d, m, a, i;
  float  v, s1=0, s2=0, s3=0, s4=0, s5=0, s6=0;
  char file[100], html[100], des[200];
  printf("Digite a data (Mês/Ano) para gerar o relatório dos gastos de cada categoria nesse mês:\n");
  printf("\tMês:\n");
  scanf("%d",&mes);
  printf("\tAno:\n");
  scanf("%d",&ano);
  if(mes>12 || mes<1){
    while(1){
      int r=0;
      printf("Data Inválida!\n");
      printf("1 - Voltar ao Menu\n");
      printf("2 - Gerar um relatório de movimentação das categorias de algum mês\n");
      scanf("%d",&r);
      if(r==1){
        main();
      }
      else if(r==2){
        catMes();
      }
    }
  }
  int b=0;
  while(b!=1){
    int res=0;
    printf("Confirmar Dados:\n");
    printf("1 - Tudo Certo\n");
    printf("2 - Cancelar e colocar os dados novamente\n");
    printf("3 - Cancelar e voltar para o Menu\n");
    scanf("%d",&res);
    if(res==1){
      b=1;
    }
    else if(res==2){
      catMes();
    }
    else if(res==3){
      main();
    }
    else{
      printf("Resposta Inválida!\n");
    }
  }

  sprintf(file,"%d %d .txt",mes, ano);
  FILE *fp;
  fp = fopen(file,"r");
  if(fp==NULL){
    printf("Não existe arquivo para esta data!\n");
  }
  else{
    while((fscanf(fp,"%d %d %f %d %d %d %[^\n]s \n", &rg, &c, &v, &d, &m, &a, des)) != EOF){
      if(rg==1){
        if(c==1){
          s1+=v;
        }
        else if(c==2){
          s2+=v;
        }
        else if(c==3){
          s3+=v;
        }
        else if(c==4){
          s4+=v;
        }
        else if(c==5){
          s5+=v;
        }
        else if(c==6){
          s6+=v;
        }
      }
      else if(rg==2){
        if(c==1){
          s1-=v;
        }
        else if(c==2){
          s2-=v;
        }
        else if(c==3){
          s3-=v;
        }
        else if(c==4){
          s4-=v;
        }
        else if(c==5){
          s5-=v;
        }
        else if(c==6){
          s6-=v;
        }
      }
    }
    fclose(fp);

    sprintf(html,"Movimentacao por categoria de: %d %d .html", mes, ano);


    FILE *ptrFile = fopen( html, "w"); 
    i=0; 

    fprintf( ptrFile, "<HTML>\n "); 
    fprintf( ptrFile, "<HEAD> <TITLE> Movimentacao por Categoria em %d/%d </TITLE> </HEAD>\n",mes,ano); 
    fprintf( ptrFile, "<BODY BGCOLOR=\"#110022\" TEXT=\"#FFBBAA\"> \n"); 
    fprintf( ptrFile, "<h1 align=center>Movimentação de cada categoria individualmente:</h1>\n");

    fprintf( ptrFile, "<div align=center>\n");

    if(s1>0){
      fprintf( ptrFile, "<li><h3>Valor recebido com Moradia: R$%.2f</h3></li>\n",s1);
    }
    else{
      fprintf( ptrFile, "<li><h3>Valor gasto para Moradia: R$%.2f</h3></li>\n",s1);
    }

    if(s2>0){
      fprintf( ptrFile, "<li><h3>Valor recebido com Estudos: R$%.2f</h3></li>\n",s2);
    }
    else{
      fprintf( ptrFile, "<li><h3>Valor gasto para Estudos: R$%.2f</h3></li>\n",s2);
    }
    
    if(s3>0){
      fprintf( ptrFile, "<li><h3>Valor recebido com Transporte: R$%.2f</h3></li>\n",s3);
    }
    else{
      fprintf( ptrFile, "<li><h3>Valor gasto para Transporte: R$%.2f</h3></li>\n",s3);
    }

    if(s4>0){
      fprintf( ptrFile, "<li><h3>Valor recebido com Alimentação: R$%.2f</h3></li>\n",s4);
    }
    else{
      fprintf( ptrFile, "<li><h3>Valor gasto para Alimentação: R$%.2f</h3></li>\n",s4);
    }

    if(s5>0){
      fprintf( ptrFile, "<li><h3>Valor recebido com Trabalho: R$%.2f</h3></li>\n",s5);
    }
    else{
      fprintf( ptrFile, "<li><h3>Valor gasto para Trabalho: R$%.2f</h3></li>\n",s5);
    }

    if(s6>0){
      fprintf( ptrFile, "<li><h3>Valor recebido com Extra(algo não essencial): R$%.2f</h3></li>\n",s6);
    }
    else{
      fprintf( ptrFile, "<li><h3>Valor gasto para Extra(algo não essencial): R$%.2f</h3></li>\n",s6);
    }
    
    fprintf( ptrFile, "<li><h2>Movimentação total no mês: R$%.2f</h2></li>\n",s1+s2+s3+s4+s5+s6);
    fprintf( ptrFile, "</div>\n");

    fprintf( ptrFile, "</BODY>\n"); 
    fprintf( ptrFile, "</HTML>"); 
    fclose( ptrFile );
  }
}


int main ()
{
  while(1){
    int a=0;
    printf("=================================Menu=================================\n");
    printf("1 - Adicionar um gasto ou receita\n");
    printf("2 - Gerar um relatório de movimentação dos 12 meses anteriores a algum mês\n");
    printf("3 - Gerar um relatório de movimentação de categoria de algum mês\n");
    printf("4 - Sair do programa\n");
    printf("Escolha uma das opções digitando o número respectivo: ");
    scanf("%d",&a);

    if(a==1){
      salvaDados();
    }
    else if(a==2){
      relHtml12M();
    }
    else if(a==3){
      catMes();
    }
    else if(a==4){
      exit(1);
    }
    else{
      printf("Este número não é uma opção!\n");
    }
  }
}