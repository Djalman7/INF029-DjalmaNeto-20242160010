// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Djalma da silva neto
//  email:ndjalma7@gamil.com
//  Matrícula:20242160010
//  Semestre:2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "DjalmaNeto20242160010.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int bissexto(int ano){
    if((ano% 4== 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return 1;
    }

    return 0;
}


int q1(char data[]){

DataQuebrada DQ = quebraData(data);


    if(DQ.valido == 0) return 0;
    if(DQ.iDia == 0 || DQ. iMes == 0) return 0;

    if(DQ.iAno < 100){
        DQ.iAno += 2000;
    }


    if(DQ.iMes < 1 || DQ.iMes > 12)return 0;
    if(DQ.iDia < 1 || DQ.iDia > 31)return 0;

    int dias_no_mes[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max_dias = dias_no_mes[DQ.iMes];


    if(DQ.iMes == 2 && bissexto(DQ.iAno)){
        max_dias = 29;
    }

    if(DQ.iDia > max_dias){
        return 0;
    }
    DQ.valido = 1;

    return DQ.valido;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;
    dma.retorno = 0;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
    DataQuebrada dIni = quebraData(datainicial);
    DataQuebrada dFim = quebraData(datafinal);

    if(dIni.iAno < 100) dIni.iAno += 2000;
    if(dFim.iAno < 100) dFim.iAno += 2000;

    if(dIni.iAno > dFim.iAno || (dIni.iAno == dFim.iAno && dIni.iMes > dFim.iMes) || (dIni.iAno == dFim.iAno && dIni.iMes == dFim.iMes && dIni.iDia > dFim.iDia)){
        dma.retorno =4;
        return dma;
    }

    int diaI = dIni.iDia;
    int mesI = dIni.iMes;
    int anoI = dIni.iAno;

    int diaF = dFim.iDia;
    int mesF = dFim.iMes;
    int anoF = dFim.iAno;

    int dias_no_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diasMes;

    if(diaF < diaI){
        mesF--;
        if(mesF == 0){
            mesF = 12;
            anoF--;
        }

        diasMes = dias_no_mes[mesF];
        if(mesF ==2 && bissexto(anoF)){
            diasMes = 29;
        }

        diaF += diasMes;
    }

    dma.qtdDias = diaF - diaI;

    if(mesF < mesI ){
        mesF += 12;
        anoF--;
    }
    dma.qtdMeses = mesF - mesI;

    dma.qtdAnos = anoF -anoI;


      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    char cBusca = c;
    char atual;

    if(isCaseSensitive != 1){
        if(cBusca >= 'A' && cBusca <= 'Z'){
            cBusca = cBusca - 'A' + 'a';
        }
    }

    for(int i = 0; texto[i] != '\0'; i++){
            atual = texto[i];
            if(isCaseSensitive != 1){
                if(atual >= 'A' && atual <= 'Z'){
                    atual = atual -'A' + 'a';
                }
            }
            if(atual == cBusca){
                qtdOcorrencias ++;
            }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int i, j;
    int qtdOcorrencias = 0;
    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);
    int qtd =0;

    if(tamBusca == 0 || tamTexto == 0){
        return 0;
    }

    for(i =0; i <= tamTexto - tamBusca; i++){
        int achou = 1;
        for(j = 0; j< tamBusca; j++){
            if(strTexto[i+j] != strBusca[j]){
                achou = 0;
                break;
            }
        }
        if( achou == 1){
            posicoes[qtdOcorrencias*2] = i+1;
            posicoes[qtdOcorrencias*2+1] = i + tamBusca;
            qtdOcorrencias ++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int invertido = 0;
    int digito;

    while (num > 0){
        digito = num %10;
        invertido = invertido * 10 + digito;
        num = num / 10;
    }
    

    return invertido;
}

/*
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int Nbase, nbCopia, p, Rbusca;

    if(numerobusca == 0){
        if (numerobase){
            return 1;
        }else{
            Nbase = numerobase;
            while(Nbase > 0){
                if(Nbase % 10 == 0)qtdOcorrencias++;
                Nbase /= 10;
            }
            return qtdOcorrencias;
            
        }
        
    }

    Nbase = numerobase;
    while(Nbase > 0){
        nbCopia = Nbase;
        p = 1;
        Rbusca = 0;

        while(p<=nbCopia && Rbusca < numerobusca){
            Rbusca = nbCopia % (p * 10);
            if(Rbusca == numerobusca){
                qtdOcorrencias++;
                break;
            }
            p *= 10;
        }
        Nbase /= 10;
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5]){
    int achou =0;
    int i, j, k;
    int direcaoX[8] ={-1,-1,-1, 0, 0, 1, 1, 1};//dirções para percorrer dentro da matriz.
    int direcaoY[8] ={-1, 0, 1,-1, 1,-1, 0, 1};
    int tam = 0;

    while(palavra[tam] != '\0'){
        tam++;
    }
    if(tam == 0) return 0;

    for(i = 0; i<8 && !achou; i++){
        for(j = 0; j<10 &&! achou; j++){
            if(matriz[i][j] != palavra[0])continue;

            int dir;
            for(dir = 0; dir < 8 && !achou; dir++){
                int x = i;
                int y = j;
                int ok = 1;

                for(k = 1; k < tam; k++){
                    x += direcaoX[dir];
                    y += direcaoY[dir];
                    if(x < 0 || x >= 8 || y < 0 || y>= 10){
                        ok = 0;
                        break;
                    }
                    if(matriz[x][y] != palavra[k]){
                        ok =0;
                        break;
                    }
                }

                if(ok){
                    achou = 1;
                }


            }
        }
    }


    return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
