#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct disciplinas{
    float POO,AOC,MATDISC;
}Disc;
typedef struct aluno{
    char nome[30];
    char matri[30];
    Disc med;
}alunos;
void preencheV(alunos v[],int tam){
    printf("#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=#");
    printf("\n|\t\tColetando Dados\t\t       |\n");
    printf("#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=#\n");
    int i;
    for(i=0;i<tam;i++){
        printf("Aluno %d",i+1);
        printf("\nNome: ");
        fflush(stdin);
        gets(v[i].nome);
        fflush(stdin);
        printf("\nMatrícula: ");
        gets(v[i].matri);
        fflush(stdin);
        printf("\nMédia em POO: ");
        scanf("%f",&v[i].med.POO);
        printf("\nMédia em AOC: ");
        scanf("%f",&v[i].med.AOC);
        printf("\nMédia em MATDISC: ");
        scanf("%f",&v[i].med.MATDISC);
        printf("\n");
        system("pause");
        system("cls");
    }
}
float media(float med1, float med2, float med3){
    float soma = med1+med2+med3;
    return soma/3;
}
void exibir(alunos v[],int tam){
    printf("#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=#");
    printf("\n|\t\tExibir Dados\t\t       |\n");
    printf("#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=#\n");
    int i,pos;
    float maior = media(v[0].med.POO,v[0].med.AOC,v[0].med.MATDISC);
    for(i=0;i<tam;i++){
        printf("Aluno %d",i+1);
        printf("\nNome: %s",v[i].nome);
        printf("\nMatrícula: %s",v[i].matri);
        printf("\nMédia em POO: %.2f",v[i].med.POO);
        printf("\nMédia em AOC: %.2f",v[i].med.AOC);
        printf("\nMédia em MATDISC: %.2f",v[i].med.MATDISC);
        printf("\nMédia total das Disciplinas: %.2f",media(v[i].med.POO,v[i].med.AOC,v[i].med.MATDISC));
        if(media(v[i].med.POO,v[i].med.AOC,v[i].med.MATDISC) > maior){
            maior = media(v[i].med.POO,v[i].med.AOC,v[i].med.MATDISC);
            pos = i;
        }
        printf("\n=============================\n");
        }
        printf("O aluno: %s\nMatrícula: %s\nObteve a maior média total! %.2f\n",v[pos].nome,v[pos].matri,maior);
}
int main(void){
    setlocale(LC_ALL,"portuguese");
    char sair;
    do{
    system("cls");
    alunos *v;
    v = (alunos*)malloc(30*sizeof(alunos));
    preencheV(v,30);
    exibir(v,30);
    free(v);
    printf("\nDeseja Sair[S \ N]: ");
    fflush(stdin);
    sair = getchar();
    }while(sair != toupper('S'));
}
