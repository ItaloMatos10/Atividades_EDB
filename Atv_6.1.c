#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE *file;
typedef struct notas{
    float p1, p2, p3;
}Note;
struct aluno{
    char matricula[20];
    char nome[20];
    Note provas;
}alunos;
char sair;
float media(int p1,int p2,int p3){
    float soma = p1+p2+p3;
return soma/3;
}
float MediMais(){
    file = fopen("Alunos.txt","rb+");
    if(file == NULL){
        printf("ERRO 404!! ARQUIVO NÃO ENCONTRADO!!");
        getchar();
        exit(1);
    }
    float maior = 0;
    fseek(file,0,SEEK_SET);
    fread(&alunos,sizeof(alunos),1,file);
    maior = media(alunos.provas.p1,alunos.provas.p2,alunos.provas.p3);
    float mais;
    while(!feof(file)){
        mais = 0;
        mais = media(alunos.provas.p1,alunos.provas.p2,alunos.provas.p3);
        if (mais > maior){
            maior = mais;
        }
    fread(&alunos,sizeof(alunos),1,file);
    }
    fclose(file);
    return maior;
}

void exibir(){
    file = fopen("Alunos.txt","rb+");
    if(file == NULL){
        printf("ERRO 404!! ARQUIVO NÃO ENCONTRADO!!");
        getchar();
        exit(1);
    }
    fseek(file,0,SEEK_SET);
    fread(&alunos,sizeof(alunos),1,file);
    int i = 0;
    while(!feof(file)){
            printf("\nAluno %d",i+1);
            printf("\n>Matrícula: %s",alunos.matricula);
            printf("\n>Nome: %s",alunos.nome);
            printf("\n>Nota 1: %.2f",alunos.provas.p1);
            printf("\n>Nota 2: %.2f",alunos.provas.p2);
            printf("\n>Nota 3: %.2f",alunos.provas.p3);
            printf("\n>Média: %.2f",media(alunos.provas.p1,alunos.provas.p2,alunos.provas.p3));
    printf("\n-----------------");
    i++;
    fread(&alunos,sizeof(alunos),1,file);
    }
    fclose(file);
}
void exibiMax(){
    printf("\n\n=-=-=-=-=-=-=-=-=-ALUNO COM MAIOR MÉDIA=-=-=-=-=-=-=-=-=-\n");
    file = fopen("Alunos.txt","rb+");
    if(file == NULL){
        printf("ERRO 404!! ARQUIVO NÃO ENCONTRADO!!");
        getchar();
        exit(1);
    }
    fseek(file,0,SEEK_SET);
    fread(&alunos,sizeof(alunos),1,file);
    int i = 0;
    while(!feof(file)){
        if(media(alunos.provas.p1,alunos.provas.p2,alunos.provas.p3) == MediMais()){
            printf("\nAluno %d",i+1);
            printf("\n>Matrícula: %s",alunos.matricula);
            printf("\n>Nome: %s",alunos.nome);
            printf("\n>Nota 1: %.2f",alunos.provas.p1);
            printf("\n>Nota 2: %.2f",alunos.provas.p2);
            printf("\n>Nota 3: %.2f",alunos.provas.p3);
            printf("\n>Média: %.2f",MediMais());
            printf("\n-----------------");
        }
        i++;
    fread(&alunos,sizeof(alunos),1,file);
    }
    fclose(file);
}
void lerdados(){
do{
    static int i;
    printf("\nAluno %d",i+1);
    printf("\nQual a matrícula do aluno: ");
    gets(alunos.matricula);
    fflush(stdin);
    printf("\nNome do aluno: ");
    gets(alunos.nome);
    fflush(stdin);
    printf("\nNota 1: ");
    scanf("%f",&alunos.provas.p1);
    printf("\nNota 2: ");
    scanf("%f",&alunos.provas.p2);
    printf("\nNota 3: ");
    scanf("%f",&alunos.provas.p3);
    file = fopen("Alunos.txt","ab+");
    if(file == NULL){
        printf("ERRO 404!! ARQUIVO NÃO ENCONTRADO!!");
        getchar();
        exit(1);
    }
    fseek(file,0,SEEK_END);
    fwrite(&alunos,sizeof(alunos),1,file);
    fclose(file);
    fflush(stdin);
    printf("\nDeseja sair(Digite '0')? ");
    scanf("%c",&sair);
}while(sair != '0');
}

int main(void){
    setlocale(LC_ALL,"portuguese");
    lerdados();
    exibir();
    exibiMax();
}

