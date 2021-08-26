#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAMANHO 10


typedef struct
{
    int CODIGO;
    char NOME[16];
    int DISCIPLINA[10];
    int q_disciplina;
    char c;
}PESSOA;

typedef struct
{
    int RD;
    char NOME[16];
    int alunos[10];
    int q_aluno;
    int professor[10];
    int q_professor;
}DISCIPLINA;

void CadastroPessoa(PESSOA pessoa[],int * p,char c){

       // printf("%i",*n);
       char r;
       int i = 1;
       int vra = 0;



        for (; (*p) < (TAMANHO*i); (*p)++)
        {

            printf("Digite os dados : \n");
            printf("\nNome:");
            scanf("%s",&pessoa[(*p)].NOME);
            pessoa[(*p)].q_disciplina = 0;
            pessoa[(*p)].c = c;
            fflush(stdin);

            do{
                printf("\nCodigo:");
                vra = 0;
                scanf("%d",&pessoa[(*p)].CODIGO);
                for(int k = 0; k < *p; k++)
                    {


                        if((pessoa[k].CODIGO == pessoa[(*p)].CODIGO))
                        {
                            printf("Codigo ja utilizado \n");

                            vra = 1;
                            break;

                        }

                    }
            }while(vra != 0);






            printf("\nDeseja cadastrar mais alguma pessoa ? :(S/N)");
            do{

                    scanf("%c",&r);
                    fflush(stdin);
                    r = tolower(r);
            }while(r != 's' && r != 'n');
            if(r == 'n')
            {

                system("cls");
                i = 0;
            }
            }

}

void CadastroDisciplina(DISCIPLINA disciplina[],int * s){

       // printf("%i",*n);
       char c;
       int i = 1;
       int vrd = 0;



        for (; (*s) < (TAMANHO*i); (*s)++)
        {

            printf("Digite os dados da disciplina : \n");
            printf("\nNome da disciplina :");
            scanf("%s",&disciplina[(*s)].NOME);
            disciplina[(*s)].q_professor = 0;
            disciplina[(*s)].q_aluno = 0;
            fflush(stdin);


             do{
                 printf("\nRegistro de disciplina:");
                  vrd = 0;
                scanf("%d",&disciplina[(*s)].RD);
                for(int k = 0; k < *s; k++)
                    {
                        if(disciplina[k].RD == disciplina[(*s)].RD)
                        {
                            printf("Codigo ja utilizado \n");

                            vrd = 1;
                            break;

                        }


                    }
            }while(vrd != 0);




            printf("\nDeseja cadastrar mais alguma materia:(S/N)");
            do{

                    scanf("%c",&c);
                    fflush(stdin);
                    c = tolower(c);
            }while(c != 's' && c != 'n');
            if(c == 'n')
            {

                system("cls");
                i = 0;
            }
            }


}



void MenuCadastro(PESSOA PROFESSOR[],PESSOA ALUNO[],DISCIPLINA disciplina[],int *p, int *s,int *a){

    int i;
   // char aluno[10] = "aluno";


    printf(" 1 - Aluno \n");
    printf(" 2 - Professor \n");
    printf(" 3 - Disciplina \n");
    printf(" 0 - Voltar ao menu anterior \n");
    printf(" Qual deseja escolher : ");
    scanf("%i", &i);

    switch (i)
    {

    case 1:
        system("cls");
        CadastroPessoa(ALUNO,a,'a');
        break;

    case 2:
        system("cls");
        CadastroPessoa(PROFESSOR,p,'b');
        break;
    case 3:
        system("cls");
        CadastroDisciplina(disciplina,s);
        break;


    case 0:
        Menu(PROFESSOR,ALUNO,disciplina,p,s,a);

    default:
    printf("Digite um valor possivel\n");
    MenuCadastro(PROFESSOR,ALUNO,disciplina,p,s,a);

    }



}
void DesmatricularPessoa(PESSOA pessoa[],int *p,DISCIPLINA disciplina[],int *s,char c)
{

    int RA;
    int RD;
    int Matrizdepessoas[TAMANHO];
    int Matrizdedisciplinas[TAMANHO];
    int i = 0;
    int j = 0;
    int varR = 0;

    char r;

    printf("SUGESTOES DE CADASTRADOS: ");


    for( i = 0; i < *p ; i++)
    {


        printf("NOME:");printf(" %s \n",pessoa[i].NOME);
        printf("RA:");printf(" %d \n",pessoa[i].CODIGO);


    }
     i = 0;

            do{
                printf("Digite o Codigo para Matricula: \n");
                scanf("%i",&RA);

                for (int j = 0;  j < *p ; j++)
                {
                    if((pessoa[j].CODIGO == RA))
                    {
                        Matrizdepessoas[i] = j;
                        i++;
                    }

                }
                    if(i == 0)
                    {
                        printf("Pessoa nao encontrado");
                    }

                fflush(stdin);
                printf("\nDeseja matricular mais algum aluno:(S/N)");
                scanf("%c",&r);
                fflush(stdin);
                r = tolower(r);
                if(r == 'n' || i == *p) break;
        }while(r == 's' && r != 'n');
        system("cls");

        printf("SELECIONADOS:  \n");

        for(j = 0;  j < i ; j++)
        {
            printf("%i \n",pessoa[Matrizdepessoas[j]].CODIGO);
        }


        r = NULL;


         printf("DISCIPLINAS CADASTRADOS: ");


    for( int k = 0; k < *s ; k++)
    {
        printf("NOME:");printf(" %s \n",disciplina[k].NOME);
        printf("RD:");printf(" %d \n",disciplina[k].RD);
    }
     j = 0;

            do{
                printf("Digite o RD da materia a ser matriculado: \n");
                scanf("%i",&RD);

                for (int k = 0;  k < *s ; k++)
                {
                    if(disciplina[k].RD == RD)
                    {
                        Matrizdedisciplinas[j] = k;
                        j++;
                    }

                }
                    if(j == 0)
                    {
                        printf("Disciplina nao encontrado");
                    }

                fflush(stdin);
                printf("\nDeseja matricular mais alguma disciplina:(S/N)");
                scanf("%c",&r);
                fflush(stdin);
                r = tolower(r);
                if(r == 'n') break;
        }while(r == 's' && r != 'n');
        system("cls");

        printf("Disciplinas selecionados :");
        for(int k=0;k<j;k++){

            printf("%i \n",disciplina[Matrizdedisciplinas[k]].RD);

        }


           if (verificaDuplaN(disciplina,pessoa,j,i,Matrizdepessoas))
           {
               printf("Desmatriculando: \n");

        for(int k=0;k<i;k++){
            
            //printf("%s ->", pessoa[Matrizdepessoas[k]].NOME);
                for(int l=0;l<j;l++){

                       // printf(" -> %i \n", pessoa[Matrizdepessoas[k]].DISCIPLINA[Matrizdedisciplinas[l]]);
                        pessoa[Matrizdepessoas[k]].DISCIPLINA[Matrizdedisciplinas[l]] = 0;
                       // printf("%i", pessoa[Matrizdepessoas[k]].DISCIPLINA[Matrizdedisciplinas[l]]);





            }

        }
        
        
        

           for(int k=0;k<j;k++){

                for(int l=0;l<i;l++){
                    if(pessoa[Matrizdepessoas[l]].c =='a')
                    {

                    disciplina[Matrizdedisciplinas[k]].alunos[Matrizdepessoas[l]] = 0;
                   // printf("%i",disciplina[Matrizdedisciplinas[k]].professor[l]);


                    }
                    else
                    {

                        disciplina[Matrizdedisciplinas[k]].professor[Matrizdepessoas[l]] = 0;

                    }
                       
                        

                    


                }
                }
           }
           else{
               return 0;
           }
            

        //Verificando se da pra desmatricula

        

}
void Desmatricular(PESSOA PROFESSOR[],PESSOA ALUNO[],DISCIPLINA disciplina[],int *p,int *s,int *a){

    int i;

    printf(" 1 - Aluno -> Disciplina \n");
    printf(" 2 - Professor -> Disciplina \n");
    printf(" 0 - Voltar ao menu anterior \n");
    printf(" Qual deseja escolher : ");
    scanf("%i", &i);

    switch (i)
    {   case 1:
        if((*a == 0) || (*s == 0)){
                system("cls");
                printf("Nao ha materias ou alunos cadastrados ! \n");
                Menu(PROFESSOR,ALUNO,disciplina,p,s,a);
        }
        else
        {
                system("cls");
                DesmatricularPessoa(ALUNO,a,disciplina,s,'a');
        }
        break;
        case 2:
        if((*p == 0) || (*s == 0)){
                system("cls");
                printf("Nao ha materias ou alunos cadastrados ! \n");
                Menu(PROFESSOR,ALUNO,disciplina,p,s,a);
        }
        else
        {
                 system("cls");
                 DesmatricularPessoa(PROFESSOR,p,disciplina,s,'p');
        }
        break;
        case 0:
        system("cls");
        MenuMatricula(PROFESSOR,ALUNO,disciplina,p,s,a);
        break;
    default:
    printf("Digite um valor possivel\n");
    Desmatricular(PROFESSOR,ALUNO,disciplina,p,s,a);
    break;

    }



}

void MatriculaPessoaDisciplina(PESSOA pessoa[],int *p,DISCIPLINA disciplina[],int *s,char c){

    int RA;
    int RD;
    int Matrizdepessoas[TAMANHO];
    int Matrizdedisciplinas[TAMANHO];
    int i = 0;
    int j = 0;
    int verifcr=0;
    char r;

    printf("SUGESTOES DE CADASTRADOS: ");


    for( i = 0; i < *p ; i++)
    {


        printf("NOME:");printf(" %s \n",pessoa[i].NOME);
        printf("RA:");printf(" %d \n",pessoa[i].CODIGO);


    }
     i = 0;

            do{
                printf("Digite o Codigo para Matricula: \n");
                scanf("%i",&RA);

                for (int j = 0;  j < *p ; j++)
                {
                    if((pessoa[j].CODIGO == RA))
                    {
                        Matrizdepessoas[i] = j;
                        i++;
                    }

                }
                    if(i == 0)
                    {
                        printf("Pessoa nao encontrado");
                    }

                fflush(stdin);
                printf("\nDeseja matricular mais alguem:(S/N)");
                scanf("%c",&r);
                fflush(stdin);
                r = tolower(r);
                if(r == 'n' || i == *p) break;
        }while(r == 's' && r != 'n');
        system("cls");

        printf("SELECIONADOS:  \n");

        for(j = 0;  j < i ; j++)
        {
            printf("%i \n",pessoa[Matrizdepessoas[j]].CODIGO);
        }


        r = NULL;


         printf("DISCIPLINAS CADASTRADOS: ");


    for( int k = 0; k < *s ; k++)
    {
        printf("NOME:");printf(" %s \n",disciplina[k].NOME);
        printf("RD:");printf(" %d \n",disciplina[k].RD);
    }
     j = 0;

            do{
                printf("Digite o RD da materia a ser matriculado: \n");
                scanf("%i",&RD);

                for (int k = 0;  k < *s ; k++)
                {
                    if(disciplina[k].RD == RD)
                    {
                        Matrizdedisciplinas[j] = k;
                        j++;
                    }

                }
                    if(j == 0)
                    {
                        printf("Disciplina nao encontrado");
                    }

                fflush(stdin);
                printf("\nDeseja matricular mais alguma disciplina:(S/N)");
                scanf("%c",&r);
                fflush(stdin);
                r = tolower(r);
                if(r == 'n') break;
        }while(r == 's' && r != 'n');
        system("cls");

        printf("Disciplinas selecionados :");
        for(int k=0;k<j;k++){

            printf("%i \n",disciplina[Matrizdedisciplinas[k]].RD);

        }
        //Verificando se a pessoas para matricular em cima


        if(verificaDupla(disciplina,pessoa,j,i,Matrizdepessoas))
        {
            
         printf("Matriculando...: \n");


            for(int k=0;k<i;k++){



                     printf("%s",pessoa[Matrizdepessoas[k]].NOME);

                for(int l =0; l<j ;l++){

                    pessoa[Matrizdepessoas[k]].DISCIPLINA[pessoa[Matrizdepessoas[k]].q_disciplina] = disciplina[Matrizdedisciplinas[l]].RD;
                    printf("  ->%i\n",pessoa[Matrizdepessoas[k]].DISCIPLINA[pessoa[Matrizdepessoas[k]].q_disciplina]);
                    pessoa[Matrizdepessoas[k]].DISCIPLINA[(pessoa[Matrizdepessoas[k]].q_disciplina)+1] = -1;
                    pessoa[Matrizdepessoas[k]].q_disciplina ++;

            }

        }


        for(int k=0;k<j;k++){


                printf("%s",disciplina[Matrizdedisciplinas[k]].NOME);

                for(int l=0;l<i;l++){
                    if (pessoa[Matrizdepessoas[l]].c == 'a')
                {

                    disciplina[Matrizdedisciplinas[k]].alunos[disciplina[Matrizdedisciplinas[k]].q_aluno] =  pessoa[Matrizdepessoas[l]].CODIGO;
                    printf(" ->%i\n",disciplina[Matrizdedisciplinas[k]].alunos[disciplina[Matrizdedisciplinas[k]].q_aluno]);
                    disciplina[Matrizdedisciplinas[k]].alunos[(disciplina[Matrizdedisciplinas[k]].q_aluno)+1] = -1;
                    disciplina[Matrizdedisciplinas[k]].q_aluno ++;
                }
                else
                {

                    disciplina[Matrizdedisciplinas[k]].professor[disciplina[Matrizdedisciplinas[k]].q_professor] =  pessoa[Matrizdepessoas[l]].CODIGO;
                    printf(" ->%i\n",disciplina[Matrizdedisciplinas[k]].professor[disciplina[Matrizdedisciplinas[k]].q_professor]);
                    disciplina[Matrizdedisciplinas[k]].professor[(disciplina[Matrizdedisciplinas[k]].q_professor)+1] = -1;
                    disciplina[Matrizdedisciplinas[k]].q_professor ++;


                 }


                }
    }


        }
        else
        {
            return 0;
        }



        // Vinculando Aluno Materia j=1








}
int verificaDupla(DISCIPLINA disciplina[],PESSOA pessoa[],int j, int i,int Matrizdepessoas[])
                {
                    for(int k=0;k<i;k++){
                        for(int l = 0 ; l < (pessoa[Matrizdepessoas[k]].q_disciplina);l++){
                    if(disciplina[k].RD == pessoa[Matrizdepessoas[k]].DISCIPLINA[l])
                    {   
                        printf("ERRO\nPessoas ja matriculadas em materias\n");
                        return 0;
                    }
                }
                }
                  return 1;
            }
    int verificaDuplaN(DISCIPLINA disciplina[],PESSOA pessoa[],int j, int i,int Matrizdepessoas[])
                {
                    for(int k=0;k<i;k++){
                        for(int l = 0 ; l < (pessoa[Matrizdepessoas[k]].q_disciplina);l++){
                    if(disciplina[k].RD == pessoa[Matrizdepessoas[k]].DISCIPLINA[l])
                    {
                       
                        return 1;
                    }
                }
                }
                 printf("ERRO\nPessoas nao matriculada em materia\n");
                 return 0;
            }



void MenuMatricula(PESSOA PROFESSOR[],PESSOA pessoa[],DISCIPLINA disciplina[],int *p,int *s,int *a){

    int i;

    printf(" 1 - Aluno -> Disciplina \n");
    printf(" 2 - Professor -> Disciplina \n");
    printf(" 3 - Desvincular \n");
    printf(" 0 - Voltar ao menu anterior \n");
    printf(" Qual deseja escolher : ");
    scanf("%i", &i);

    switch (i)
    {   case 1:

        if((*a == 0 ) || (*s == 0)){
                system("cls");
                printf("Nao ha materias ou alunos cadastrados ! \n");
                Menu(PROFESSOR,pessoa,disciplina,p,s,a);
        }
        else
        {
                system("cls");
                MatriculaPessoaDisciplina(pessoa,a,disciplina,s,'a');
        }
        break;
        case 2:
        if((*p) ==0 || (*s == 0)){
                system("cls");
                printf("Nao ha professoras ou alunos cadastrados ! \n ");
               Menu(PROFESSOR,pessoa,disciplina,p,s,a);
        }
        else
        {
                system("cls");
                MatriculaPessoaDisciplina(PROFESSOR,p,disciplina,s,'p');
        }
        break;
        case 3:
                system("cls");
                Desmatricular(PROFESSOR,pessoa,disciplina,p,s,a);
                break;
        case 0:
        system("cls");
        Menu(PROFESSOR,pessoa,disciplina,p,s,a);
        break;
    default:
    printf("Digite um valor possivel\n");
    MenuMatricula(PROFESSOR,pessoa,disciplina,p,s,a);
    break;

    }



}



void ListarPessoa(PESSOA pessoa[],int *p){
    for (int i = 0;  i < *p ; i++)
    {


            printf("Nome: "); printf("%s \n",pessoa[i].NOME);
            printf("RA: ");  printf("%d \n",pessoa[i].CODIGO);




       }
    }
void ListarDisciplinas(DISCIPLINA disciplina[],int *s){
    printf("Disciplinas:\n");
    for (int i = 0;  i < *s ; i++)
    {
       printf("Nome: "); printf("%s\n",disciplina[i].NOME);
       printf("RD: ");  printf("%i\n",disciplina[i].RD);

    }




}
void ListarDisciplinasPessoas(PESSOA pessoa[],int *p,DISCIPLINA disciplina[],int *s)
{
    int RA;
    int indiceDoAluno;

    int j = 0;

     printf("Digite o CODIGO: PESSOAS->DISCIPLINA OK \n");
     scanf("%i",&RA);

                for(int k = 0;  k < *p ; k++)
                {
                    if((pessoa[k].CODIGO == RA))
                    {
                        indiceDoAluno = k;
                        j++;
                    }
                }
                    if(j != 0)
                    {
                        printf("RD DAS MATERIAS : \n");
                    for(int i = 0 ; i < pessoa[indiceDoAluno].q_disciplina ; i++)
                    {
                    if(pessoa[indiceDoAluno].DISCIPLINA[i] != -1 )
                    {
                        if(pessoa[indiceDoAluno].DISCIPLINA[i] != 0){
                            printf("%i \n",pessoa[indiceDoAluno].DISCIPLINA[i]);
                        }

                    }
                    else
                    {
                        break;
                    }
                    }
                    }else{
                    system("cls");
                    printf("Aluno nao encontrado \n");}

}
void ListarProfessorDisciplinas(PESSOA ALUNO[],int *p,DISCIPLINA disciplina[],int *s)
{
    int RD;
    int indiceDeDisciplina;

    int j = 0;

     printf("Digite o RD da disciplina :DISCIPLINA -> PROFESSORES OK \n");
     scanf("%i",&RD);

                for(int k = 0;  k < (*s) ; k++)
                {
                    if(disciplina[k].RD == RD)
                    {
                        indiceDeDisciplina = k;
                        j++;
                    }
                }
                    if(j != 0)
                    {

                    printf("RA : \n");
                        for(int i = 0 ; i < *p ; i++)
                    {
                    if(disciplina[indiceDeDisciplina].professor[i] != -1 )
                    {
                        if(disciplina[indiceDeDisciplina].professor[i] != 0){
                            printf("%i \n",disciplina[indiceDeDisciplina].professor[i]);
                        }

                    }
                    else
                    {
                        break;
                    }


                }
                }
                    else{system("cls");
                    printf("Disciplina nao encontrada \n");}




}
void ListarAlunosDisciplinas(PESSOA ALUNO[],int *p,DISCIPLINA disciplina[],int *s)
{
    int RD;
    int indiceDeDisciplina;

    int j = 0;

     printf("Digite o RD da disciplina :DISCIPLINA >ALUNOS \n");
     scanf("%i",&RD);

                for(int k = 0;  k < (*s) ; k++)
                {
                    if(disciplina[k].RD == RD)
                    {
                        indiceDeDisciplina = k;
                        j++;
                    }
                }
                    if(j != 0)
                    {

                    printf("RA : \n");
                        for(int i = 0 ; i < *p ; i++)
                    {
                    if(disciplina[indiceDeDisciplina].alunos[i] != -1 )
                    {
                        if(disciplina[indiceDeDisciplina].alunos[i] != 0){
                            printf("%i \n",disciplina[indiceDeDisciplina].alunos[i]);
                        }

                    }
                    else
                    {
                        break;
                    }


                }
                }
                    else{system("cls");
                    printf("Disciplina nao encontrada \n");}




}
void ListarDisciplinasProfessor(PESSOA ALUNO[],int *p,DISCIPLINA disciplina[],int *s)
{
    int RD;
    int indiceDeDisciplina;

    int j = 0;

     printf("Digite CODIGO (PROFESSOR)  : PROFESSOR - > DISCIPLINA \n");
     scanf("%i",&RD);

                for(int k = 0;  k < (*s) ; k++)
                {
                    if(ALUNO[k].CODIGO == RD)
                    {
                        indiceDeDisciplina = k;
                        j++;
                    }
                }
                    if(j != 0)
                    {

                    printf("RD : \n");
                        for(int i = 0 ; i < ALUNO[indiceDeDisciplina].q_disciplina ; i++)
                    {
                    if(ALUNO[indiceDeDisciplina].DISCIPLINA[i] != -1 )
                    {
                        if(ALUNO[indiceDeDisciplina].DISCIPLINA[i] != 0){
                            printf("%i \n",ALUNO[indiceDeDisciplina].DISCIPLINA[i]);
                        }

                    }
                    else
                    {
                        break;
                    }


                }
                }
                    else{system("cls");
                    printf("Disciplina nao encontrada \n");}




}
void MenuImpressao(PESSOA PROFESSOR[],PESSOA pessoa[],DISCIPLINA disciplina[],int *p,int *s,int *a){

    int i;

    printf(" 1 - Listar professores \n");
    printf(" 2 - Listar alunos \n");
    printf(" 3 - Listar Disciplinas \n");
    printf(" 4 - Alunos de disciplinas  \n");
    printf(" 5 - Disciplinas de alunos \n");
    printf(" 6 - Disciplinas de Professores \n");
    printf(" 7 - Professores de disciplinas \n");
    printf(" 0 - Voltar ao menu anterior \n");
    printf(" Qual deseja escolher : ");
    scanf("%i", &i);

    switch (i)
    {
    case 1:
        system("cls");
        ListarPessoa(PROFESSOR,p);
        break;
    case 2:
        system("cls");
        ListarPessoa(pessoa,a);
        break;
    case 3:
        system("cls");
        ListarDisciplinas(disciplina,s);
        break;
    case 4:
        system("cls");
        ListarAlunosDisciplinas(pessoa,a,disciplina,s);
        break;
    case 5:
        system("cls");
        ListarDisciplinasPessoas(pessoa,a,disciplina,s);
        break;
    case 6:
        system("cls");
        ListarDisciplinasProfessor(PROFESSOR,p,disciplina,s);
        break;
    case 7:
        system("cls");
        ListarProfessorDisciplinas(PROFESSOR,p,disciplina,s);
        break;
    case 0:
        system("cls");
        Menu(PROFESSOR,pessoa,disciplina,p,s,a);
        break;
    default:
    printf("Digite um valor possivel\n");
    MenuImpressao(PROFESSOR,pessoa,disciplina,p,s,a);
    break;

    }



}


void Menu(PESSOA PROFESSOR[],PESSOA ALUNO[],DISCIPLINA disciplina[],int *p, int *s,int *a){
    int i;

    printf(" 1 - Cadastro \n");
    printf(" 2 - Matricula / Desmatricula \n");
    printf(" 3 - Impressao \n");
    printf(" 0 - Sair \n");
    printf(" Qual deseja escolher : ");
    scanf("%i", &i);

    switch (i)
    {
    case 1:
        system("cls");
        MenuCadastro(PROFESSOR,ALUNO,disciplina,p,s,a);
        break;
    case 2:
        system("cls");
        MenuMatricula(PROFESSOR,ALUNO,disciplina,p,s,a);
        break;
    case 3:
        system("cls");
        MenuImpressao(PROFESSOR,ALUNO,disciplina,p,s,a);
        break;
    case 0:
        exit(0);
        break;
    default:
    printf("Digite um valor possivel\n");
    Menu(PROFESSOR,ALUNO,disciplina,p,s,a);
    break;

    }




}



int main(){
     PESSOA ALUNO[TAMANHO];
     PESSOA PROFESSOR[TAMANHO];
     DISCIPLINA disciplina[TAMANHO][TAMANHO];

      int *p;
      p = (int*) malloc(10*sizeof(int));
      *p = 0;

      int *a;
      a = (int*) malloc(10*sizeof(int));
      *a = 0;

      int *s;
      s = (int*) malloc(10*sizeof(int));
      *s = 0;


    for (;;)
    {
        Menu(PROFESSOR,ALUNO,disciplina,p,s,a);
    }




return 0;

}
