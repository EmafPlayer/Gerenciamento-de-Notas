#include <stdio.h>

#define QTD_ALUNOS 1  // Escolher a quantidade de alunos
#define QTD_DISCIPLINA 2 // Escolher a quantidade de disciplinas que um aluno terá
#define QTD_NOTAS 3 // Escolher a quantidade de notas que as disciplinas terão
#define QTD_TAMANHO_NOME 50

struct Notas{ // Notas separadas de cada disciplina
  float avaliacoes[QTD_NOTAS];
};

struct Aluno{ // Características do aluno
  char nome[QTD_TAMANHO_NOME]; // 
  char disciplinas[QTD_DISCIPLINA][QTD_TAMANHO_NOME];
  struct Notas notas[QTD_DISCIPLINA];
};

int main() {

  struct Aluno alunos[QTD_ALUNOS];
  float media;
  media = QTD_NOTAS * 1.0;
  for(int i = 0; i < QTD_ALUNOS; i++){ // Laço de repetição do programa de acordo com a quantidade de alunos que terão cadastrados
    printf("\n============== %dº Aluno ==============\n", i+1);
    printf("Nome do %dº Aluno: ", i+1);  
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    for(int j = 0; j < QTD_DISCIPLINA; j++){ // Cadastrar as disciplinas que cada aluno terá
      printf("\n");
      printf("Disciplina: ");
      fgets(alunos[i].disciplinas[j], sizeof(alunos[i].disciplinas[j]), stdin);
      printf("\n");
      for(int k = 0; k < QTD_NOTAS; k++){ // Cadastras as notas que o aluno tirou dentro das disciplinas
        printf("Nota da %dª Avaliação: ", k+1);
        scanf("%f", &alunos[i].notas[j].avaliacoes[k]);
        getchar();
      }   
    }  
  }

  for(int i = 0; i < QTD_ALUNOS; i++){ 
    printf("\n====================================================");
    printf("\nAluno: %s", alunos[i].nome);
    for(int j = 0; j < QTD_DISCIPLINA; j++){
      float media_final = 0.0;
      printf("\n\nDisciplina: %s\n", alunos[i].disciplinas[j]);
      for(int k = 0; k < QTD_NOTAS; k++){
        media_final += alunos[i].notas[j].avaliacoes[k]; // Somar todas as notas de uma disciplina de cada aluno
      }
      media_final = media_final/media; // Fazer a média aritmética de cada disciplina de um aluno
      printf("Media Final: %.1f\n", media_final);
    }
  }


  return 0;
}

