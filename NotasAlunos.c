#include <stdio.h>

#define QTD_ALUNOS 1
#define QTD_CADEIRAS 3
#define QTD_TAMANHO_NOME 20

struct Notas{
  float avaliacoes[qtd_notas[QTD_CADEIRAS]];
};

struct Aluno{
  char nome[QTD_TAMANHO_NOME];
  char cadeiras[QTD_CADEIRAS][QTD_TAMANHO_NOME];
  int qtd_notas[QTD_CADEIRAS];
  struct Notas notas[QTD_CADEIRAS];
  float nota_final[QTD_CADEIRAS];
};

int main() {

  static
  struct Aluno alunos[QTD_ALUNOS];
  float media;
  media = QTD_NOTAS * 1.0;
  for(int i = 0; i < QTD_ALUNOS; i++){
    printf("\n============== %dº Aluno ==============\n", i+1);
    printf("Nome do %dº Aluno: ", i+1);   
    scanf("%s", alunos[i].nome);
    for(int j = 0; j < QTD_CADEIRAS; j++){
      printf("\n");
      printf("Cadeira: ");
      scanf("%s", alunos[i].cadeiras[j]);
      printf("Quantas atividades avaliativas tem em %s\n", alunos[i].cadeiras[j]);
      scanf("%d", &alunos[i].qtd_notas[j]);
      printf("\n");
      for(int k = 0; k < alunos[i].qtd_notas[j]; k++){
        printf("Nota da %dª Avaliação: ", k+1);
        scanf("%f", &alunos[i].notas[j].avaliacoes[k]);
        alunos[i].media_final += alunos[i].notas[j].avaliacoes[k];
      }   
    }  
  }

  for(int i = 0; i < QTD_ALUNOS; i++){
    printf("\n====================================================");
    printf("\nAluno: %s\n", alunos[i].nome);
    for(int j = 0; j < QTD_CADEIRAS; j++){
      printf("\nCadeira: %s\n", alunos[i].cadeiras[j]);
      alunos[i].media_final[j] = (alunos[i].media_final)/(float)qtd_notas;
      printf("Media Final: %.1f\n", alunos[i].media_final);
    }
  }


  return 0;
}

