#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct lista{
     char nome[40];
     char endereco[40];
     char email[40];
     char linguagem[40];
     float salario;
     unsigned long int codigo;
     struct lista* prox;   
   }Lista;
   
   //Declaração de funções.
   Lista* inserir_candidatos(Lista* primeiro);
   void listar_candidatos(Lista* primeiro);
   Lista* procurar_vagas(Lista* primeiro);
   Lista* excluir_restaurantes(Lista* primeiro);
   void alterar_restaurantes(Lista* primeiro);

main() 
{ 
   //Declaração de variáveis
   Lista *primeiro= NULL;
   char opcao;
     
   //Artifício para repetir o programa.
   while(opcao!='s')   
   {  
     //Menu de opcoes 

      printf("CADASTRO DE CANDIDATOS \n \n");
      printf(" MENU \n \n ");
      printf("   | <1>  Novo cadastro                \n");
      printf("   |-----------------------------------\n");
      printf("   | <2>  Vagas de Emprego             \n");
      printf("   |-----------------------------------\n");
      printf("   | <3>  Listar                       \n");      
      printf("   |-----------------------------------\n");
      printf("   | <C>  Excluir cadastro             \n");      
      printf("   |-----------------------------------\n");
      printf("   | <D>  Alterar cadastro             \n"); 
      printf("   |-----------------------------------\n");
      printf("   | <S>  Sair                         \n");
 
      
      //Lendo a opcao do menu   
      fflush(stdin);
      opcao= getch(); 
      
      //Menu de opcoes
      switch(opcao)
      {
         case '1':      
              //Inserindo os restaurantes.
              fflush(stdin);
              system("cls");
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");   
              primeiro= inserir_candidatos(primeiro);
         getch();
         system("cls"); 
         break;
         
          case '2':      
              //Inserindo os restaurantes.
              fflush(stdin);
              system("cls");
              printf(" | ");printf("\t\t\t          VAGAS DE EMPREGO     ");printf("\t\t\t      |\n");   
              primeiro= procurar_vagas(primeiro);
         getch();
         system("cls"); 
         break;
         
         
         case '3':         
              //Listando os restaurantes.
              system ("cls");
              printf(" | ");printf("\t\t\t     CANDIDATOS CADASTRADOS");printf("\t\t\t      |\n");
              listar_candidatos(primeiro);
         getch();
         system("cls");
         break;
         
         case 'C':   
         case 'c':   
              //Excluindo restaurantes da lista.
              system ("cls");
              printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
              primeiro= excluir_restaurantes(primeiro);
         getch();
         system("cls");
         break;

         case 'D':   
         case 'd':   
              //Alterando restaurantes da lista. 
              system ("cls");
              printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
              alterar_candidatos(primeiro);
         getch();
         system("cls");
         break;
         
         case 'S':   
         case 's':       
              //Artifício para sair do programa.
              opcao='s';
         break;
         
         default:     
              //Artifício que previne a situação de um usuário qualquer, digitar uma opcão inexistente no menu.
              system("cls");        
         break; 
      } 
   }  
}

Lista* inserir_candidatos (Lista *primeiro){ 
     Lista candidato;
     Lista *atual= primeiro;
     char identificador= 'F';
     
     //Lendo as informações do restaurante.
     printf("  Nome: ");
     fflush (stdin); fgets(candidato.nome, 40, stdin); printf ("\n");
     printf("  Endere%co: ",135);
     fflush (stdin); fgets(candidato.endereco, 40, stdin); printf ("\n");
      printf("  Email: ");
     fflush (stdin); fgets(candidato.email, 40, stdin); printf ("\n");
     printf("  C%cdigo: ",162);
     scanf("%u",&candidato.codigo);printf ("\n");
     
     //Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==candidato.codigo){
            identificador= 'V'; 
            break;
        }    
     }

     if(identificador!='V' && (strlen(candidato.nome)!=1 && strlen(candidato.endereco)!=1)){
         //Alocando os espaços e guardando as informações do restaurante.
         Lista* NovoCandidato=(Lista*) malloc (sizeof(Lista));       
         strcpy(NovoCandidato->nome, candidato.nome);
         strcpy(NovoCandidato->endereco, candidato.endereco);
         NovoCandidato->codigo= candidato.codigo;
         NovoCandidato->prox= primeiro;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return NovoCandidato;    
     }else{
         printf("  Cadastro inv%clido.",160);
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return primeiro;
     }
}




void listar_candidatos (Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.
     
     //Imprimindo os restaurantes da lista, e suas repectivas informações.
     if(atual->linguagem=java && atual->salario<2000){
     	for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nome: ");
        printf("%s", atual->nome);
        printf("\n  Endere%co: ",135);
        printf("%s", atual->endereco);
        printf("\n  C%cdigo: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum Candidato cadastrado.");
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
	 }
	 else{
	 	printf("");
	 }
     
}

Lista* excluir_candidatos(Lista *primeiro){
     
     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     unsigned long int codigo=0;
     
     //Requisitando e lendo o código do restaurante a ser excluído.
     printf("  C%cdigo do Candidato a ser exclu%cdo: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }
     
     //Mensagem caso o restaurante não seja encontrado.
     if(atual==NULL){
        printf("\n  Restaurante n%co encontrado.", 198); 
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
     }
     
     //Excluindo o primeiro restaurante da lista.   
     if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161); 
        primeiro= atual->prox;
     //Excluindo um restaurante do meio da lista.
     }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= atual->prox;
     }
     
     //Desalocando o espaço da memória.
     free(atual);
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     return primeiro;     
}

//Função para alterar restaurantes.
void alterar_candidatos(Lista* primeiro){     
     char nome_substituto[40], endereco_substituto[40];
     unsigned long int codigo;  
     Lista* atual=primeiro;
     
     //Requisitando e lendo o código do restaurante a ser alterado.
     printf("  C%cdigo do Candidato a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }
     
     //Alterando os dados do restaurante.
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin); 
        strcpy(atual->nome,nome_substituto);
        printf("\n  Novo endere%co: ",135);
        fflush (stdin); fgets(endereco_substituto, 40, stdin); printf ("\n");
        strcpy(atual->endereco,endereco_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  Candidato n%co encontrado.",198);
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
