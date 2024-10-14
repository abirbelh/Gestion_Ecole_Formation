#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "Formateur.h"




int saisieNbFormateur()
{
    int nbF;
do{
printf("entrer le nombre des formateurs ");
scanf("%d",&nbF);
}while(nbF<=0);
    return nbF;

}
FORMATEUR* allocationForm(FORMATEUR* f,int n)
{
if(f != NULL){
    f = (FORMATEUR*) realloc(f,n * sizeof(FORMATEUR));
  }else{
    f=(FORMATEUR*) malloc (n*sizeof(FORMATEUR));}
    if(!f) exit(-1);
    return f;
}

void saisieSpecialite(int n,SPECIALITE* spF){
for(int i=0;i<n;i++){
    printf("\n Entrer Specialite %d \n",i+1);
   printf("\n saisir le code Specialite ");
   scanf("%d",&(spF+i)->codeSp);
   do{
   printf("\n saisir le nom ");
   scanf("%s",&(spF+i)->nomSp);}
   while(!verifName((spF+i)->nomSp));
}

}
 bool existeCode(FORMATEUR* f,int n,int c){
     for(int i=0;i<n;i++){
        if((f+i)->ceF == c){
            return true ;
        }
     }
     return false ;
 }
void saisieFormateur(FORMATEUR* f,int n,int deb){

  for(int i=deb;i<n;i++){
   printf("\n saisir les informations du formateur ** %d ** \n",i+1);
   do{
   printf("\n saisir le code ");
   scanf("%d",&(f+i)->ceF);
   if(existeCode(f,i,(f+i)->ceF))
    printf("\n Attention ! le code du formateur doit etre unique\n");
   }while(existeCode(f,i,(f+i)->ceF));
   do{
   printf("\n saisir le nom ");
   scanf("%s",&(f+i)->nomF);
   }while(!verifName(f->nomF));
   do{
   printf("\n saisir le prenom ");
   scanf("%s",&(f+i)->prenomF);
   }while(!verifName((f+i)->nomF));
   do{
    printf("\n saisir la date de naissance (JJ MM AAAA) \n");
    scanf("%d/%d/%d",&(f+i)->dateNaissF.jour,&(f+i)->dateNaissF.mois,&(f+i)->dateNaissF.annee);}
    while(!verifDate((f+i)->dateNaissF.jour,(f+i)->dateNaissF.mois,(f+i)->dateNaissF.annee));
      do{
    printf("\n saisir le numero de telephone ");
    scanf("%d",&(f+i)->numTel);
    if(((f+i)->numTel < 10000000) || ((f+i)->numTel > 99999999))
        printf("\n le numero doit contenir 8 chiffres \n");
   }while(((f+i)->numTel < 10000000) || ((f+i)->numTel > 99999999));

do{
   printf("\n saisir l' email ");
   scanf("%s",&(f+i)->emailF);
}while(!verifEmail((f+i)->emailF));

    printf("entrer le nombre des specialit� qu'il possede");
        scanf("%d",&(f+i)->nbSpecialite);
(f+i)->spF=(SPECIALITE*) malloc ( (f+i)->nbSpecialite * sizeof(SPECIALITE));
saisieSpecialite((f+i)->nbSpecialite,(f+i)->spF);
  }

}

void afficherFormateur(FORMATEUR* f,int n){
    if(f == NULL){
        printf("tableau formateur est VIDE");
    }else
for(int i=0;i<n;i++){
   printf("\n*********************\n");
   printf("\n informations sur le formateur ** %d ** \n",i+1);
   printf("\n\t- code : %d ",(f+i)->ceF) ;
   printf("\n\t- nom: %s ",(f+i)->nomF);
   printf("\n\t- prenom : %s ",(f+i)->prenomF);
   printf("\n\t- date de naissance : %d/%d/%d",(f+i)->dateNaissF.jour,(f+i)->dateNaissF.mois,(f+i)->dateNaissF.annee);
   printf("\n\t- numero de telephone : %d",(f+i)->numTel);
   printf("\n\t- adresse mail : %s",(f+i)->emailF);
   printf("\n\t- numero de nbSpecialit�s : %d",(f+i)->nbSpecialite);
   for(int j=0;j<(f+i)->nbSpecialite;j++){
   printf("\n\t- code Specialite : %d ",((f+i)->spF+j)->codeSp);
   printf("\n\t- nom Specialite %s",((f+i)->spF+j)->nomSp);

}
}
}
void modifierFormateur(FORMATEUR *f,int n){

      int i=0,ceF1;

      char choix[3] ;
  if(f==NULL){
    printf("tableau formateur est VIDE");
  }else{
  printf("entrer le code du formateur � modifier ");
  scanf("%d",&ceF1);

  while((i<n) && ( (f+i)->ceF != ceF1 )){
        i++;
  }

  if(i==n){
      printf("\n !!!! Ce code n'existe pas !!!!");
  }
    else{
     printf(" *** Les informations du formateur � modifier : \n");
     printf("\n nom : %s",(f+i)->nomF);
     printf("\n prenom : %s",(f+i)->prenomF);
     printf("\n date de naissance : %d/%d/%d",(f+i)->dateNaissF.jour,(f+i)->dateNaissF.mois,(f+i)->dateNaissF.annee);
     printf("\n numero de telephone : %d",(f+i)->numTel);
     printf("\n adresse mail : %s",(f+i)->emailF);
     printf("\n numero de nbSpecialit�s : %d",(f+i)->nbSpecialite);
     for(int u=0;u<(f+i)->nbSpecialite;u++){
        printf("\n code Specialite : %d ",((f+i)->spF+u)->codeSp);
        printf("\n nom Specialite %s",((f+i)->spF+u)->nomSp);
     }
      printf("\n saisir les nouvelles donn�es du formateur %d\n",i+1);

         do
     {printf("\n saisir le nom ");
      scanf("%s",&(f+i)->nomF);}
    while(!verifName((f+i)->nomF));
    do
     {printf("\n saisir le prenom ");
      scanf("%s",&(f+i)->prenomF);}
    while(!verifName((f+i)->prenomF));
    do
     {printf("\n saisir la date de naissance (JJ MM AAAA) \n");
      scanf("%d/%d/%d",&(f+i)->dateNaissF.jour,&(f+i)->dateNaissF.mois,&(f+i)->dateNaissF.annee);}
     while(!verifDate((f+i)->dateNaissF.jour,(f+i)->dateNaissF.mois,(f+i)->dateNaissF.annee));
   do{
    printf("\n saisir le numero de telephone ");
    scanf("%d",&(f+i)->numTel);
    if(((f+i)->numTel < 10000000) || ((f+i)->numTel > 99999999))
        printf("\n le numero doit contenir 8 chiffres \n");
   }while(((f+i)->numTel < 10000000) || ((f+i)->numTel > 99999999));
    do
    {printf("\n saisir l'adresse mail ");
      scanf("%s",&(f+i)->emailF);}
    while(!verifEmail((f+i)->emailF));

     printf("entrer le nombre des specialit� qu'il possede");
         scanf("%d",&(f+i)->nbSpecialite);
     (f+i)->spF=(SPECIALITE*) malloc ( (f+i)->nbSpecialite * sizeof(SPECIALITE));
      saisieSpecialite((f+i)->nbSpecialite,(f+i)->spF);
  }

}}


void supprimerFormateur(FORMATEUR *f,int* n){

  int i=0,ceF1;
  char choix[3] ;
  if(f==NULL){
    printf("tableau VIDE");
    }
  else{
    printf("entrer le code du formateur � supprimer ");
    scanf("%d",&ceF1);

    while((i<*n) && ( (f+i)->ceF != ceF1 )){
         i++;
         }

    }
  if(i==*n){
      printf("\n !!!! Ce code n'existe pas !!!!");
  }
   else{

     printf(" *** Les informations du formateur � supprimer : \n");
     printf("\n nom: %s",(f+i)->nomF);
     printf("\n prenom : %s",(f+i)->prenomF);
     printf("\n date de naissance : %d/%d/%d",(f+i)->dateNaissF.jour,(f+i)->dateNaissF.mois,(f+i)->dateNaissF.annee);
     printf("\n numero de telephone : %d",(f+i)->numTel);
     printf("\n adresse mail : %s",(f+i)->emailF);
     printf("\n numero de nbSpecialit�s : %d",(f+i)->nbSpecialite);
     for(int u=0;u<(f+i)->nbSpecialite;u++){
        printf("\n code Specialite : %d ",((f+i)->spF+u)->codeSp);
        printf("\n nom Specialite %s",((f+i)->spF+u)->nomSp);
        }

     printf(" \n---- Confirmation -------- : \n");
     do{
       printf("\n Voulez-vous supprimer definitivement ce formateur ? (tapez O ou N)");
       scanf("%s",&choix);
       if( (strcmp(choix,"O")) && (strcmp(choix,"N")) ){
         printf("\n !!! Pri�re de taper O pour Confirmer ou N pour annuler la suppression");
         }
       }while((strcmp(choix,"O")) && ( strcmp(choix,"N")));
     if(strcmp(choix,"O") == 0){
       *n = *n - 1 ;
       for(int j=i;j<(*n);j++){
          (f+j)->ceF = (f+(j+1))->ceF ;
          strcpy((f+j)->nomF , (f+(j+1))->nomF);
          strcpy((f+j)->prenomF , (f+(j+1))->prenomF);
          (f+j)->dateNaissF = (f+(j+1))->dateNaissF ;
          strcpy((f+j)->emailF , (f+(j+1))->emailF );
          (f+j)->numTel = (f+(j+1))->numTel  ;
          (f+j)->nbSpecialite = (f+(j+1))->nbSpecialite ;
          (f+j)->spF = (f+(j+1))->spF;
        }
       if((*n) == 0){
         free(f);
         f=NULL;
         printf("tableau videeee");
         }
       else
         f = (FORMATEUR*) realloc(f,(*n) * sizeof(FORMATEUR));
       printf("suppression effectuer avec succees ");
       }
     else
       printf("suppression annuler ");
  }

}
