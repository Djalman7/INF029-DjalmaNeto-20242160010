#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void inicializar_tabuleiro(char tabuleiro[TAM][TAM]);
void imprimir_tabuleiro(char tabuleiro[TAM][TAM], int jogador_atual);
int verificar_vitoria(char tabuleiro[TAM][TAM]);
int fazer_jogada(char tabuleiro[TAM][TAM], int jogador_atual);

int main(){

    char tabuleiro[TAM][TAM];
    int jogador_atual =1;
    int jogada_res = TAM * TAM;
    int estado_jogo =0;


    inicializar_tabuleiro(tabuleiro);

    while (estado_jogo == 0){
        imprimir_tabuleiro(tabuleiro, jogador_atual);

        if(fazer_jogada(tabuleiro, jogador_atual)){
            jogada_res --;
            if(verificar_vitoria(tabuleiro)){
                estado_jogo = 1;
            }else if(jogada_res == 0){
                estado_jogo =2;
            }else{
                jogador_atual =(jogador_atual == 1) ? 2 : 1;
            } 
        }
    }
    
    imprimir_tabuleiro(tabuleiro, jogador_atual);

    if(estado_jogo == 1){
        printf("Parabéns ao jogador %d ('%c') venceu!\n", jogador_atual, (jogador_atual == 1 ? 'x' : '0' ));
    }else{
        printf("EMPATE!\n");
    }

return 0;
}


void inicializar_tabuleiro(char tabuleiro[TAM][TAM]){

    int i, j;
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimir_tabuleiro(char tabuleiro[TAM][TAM], int jogador_atual){

    int i, j;

    printf("\n JOGO DA VELHA\n\n");
    printf("    1   2   3\n");
    for(i = 0; i < TAM; i++){
        printf("%c", 'A' + i);

        for(j = 0; j <TAM; j++){
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|\n");
        if(i < TAM - 1){
            printf("  -------------\n");
        }      
    }
    printf("\n");

    printf("jogador %d ('%c'), é a sua vez\n", jogador_atual,(jogador_atual == 1 ? 'X' : 'O'));
    printf("informe sua jogada (EX: A1, B3)");

}

int verificar_vitoria(char tabuleiro[TAM][TAM]){
    char marca;

    for(int jogador = 1; jogador <= 2; jogador ++){
        marca = (jogador == 1) ? 'X' : '0';

        for(int i = 0; i < TAM; i++){
            if(tabuleiro[i][0] == marca && tabuleiro[i][1] == marca && tabuleiro[i][2] == marca){
                return 1;
            }

            if(tabuleiro[0][i]== marca && tabuleiro[1][i] == marca && tabuleiro[2][i] == marca){
                return 1;
            }

        }

        if(tabuleiro[0][0] == marca && tabuleiro[1][1]== marca && tabuleiro[2][2]==marca){
            return 1;
        }
        if(tabuleiro[0][2] == marca && tabuleiro[1][1] == marca && tabuleiro[2][0] == marca){
            return 1;
        }
        
    }

    return 0;

}


int fazer_jogada(char tabuleiro[TAM][TAM], int jogador_atual){
    char jogada[3];
    int linha, coluna;
    char marca = (jogador_atual ==1) ? 'X' : '0';
    char linha_char;

    if(scanf("%2s", jogada) !=1){
        while (getchar() != '\n');
        printf("Entrada invalida!");
        return 0;
    }
    
    while (getchar() != '\n');

    linha_char = to_upper_manual(jogada[0]);

    linha = linha_char - 'A';
    coluna = jogada[1] - '1';

    if(linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM){
        printf("\njogada invalida!\n");
            return 0;
    }
    if(tabuleiro[linha][coluna] != ' '){
        printf("\njogada invalida! local ja ocupado! ('c%')", tabuleiro[linha][coluna]);
            return 0;
    }
     
    tabuleiro[linha][coluna] = marca;
    return 1;

}