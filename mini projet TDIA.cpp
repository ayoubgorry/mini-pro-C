#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct date {
  int jj, mm, aaaa;
};
struct emp {
  char nom[40]; 
  char prenom[40]; 
  char CIN[10];
  char email[50];
  struct date d;
  char tele[11]; 
  float salaire; 
  char proffession[40]; 
};
struct emp e;
long double g = sizeof(e);
FILE * fp, * ft;
char another;
int champ;
char CINc[9], proff[40], empnom[40], empprenom[40];
int login() {
   char code[10];
   int v = 0, i;
    for (i = 0; i < 3; i++) {
      printf("\tdonner le code :\t");
      scanf("%s", code);
      if (strcmp(code, "TDIA") != 0 ){
        if(i!=2)
         printf("\nerreur ressayer encore une fois , il reste encore %d tentative.",2-i);
        else
         printf("vous avez echouez dans les trois tentatives.");}
      else{
       v = 1;
       break;}
     }
   return v;
 }
void ajoutemp() {
  system("cls");
  struct emp e1;
  fseek(fp, 0, SEEK_END); 
  another = 'y';
  while (another == 'y' || another == 'Y') 
  {

    printf("\nEntrer le nom: ");
    
    fflush(stdin);
    gets(e.nom);
    printf("\nEntrer le  prenom: ");
    
    gets(e.prenom);
    printf("\nEntrer le  CIN: ");
    
    gets(e.CIN);
    printf("\nEntrer  E-MAIL: ");
     gets(e.email);
    printf("\nentrer la date de naissance: jj/mm/aaaa \n respectez la structure svp noubliez pas de tapper /\t");
    scanf("%d/%d/%d", & e.d.jj, & e.d.mm, & e.d.aaaa);
    do {
      printf("\nEntrer le telephone: ");
    
      fflush(stdin);
      gets(e.tele);
    } while (strlen(e.tele) > 10);
    printf("\nEnter le  salaire: ");
    scanf("%f", & e.salaire);
    do {
      printf("\nEntrer la proffession: directeur / professeur / securite/ officier / secretaire:\t");
      scanf("%s", e.proffession);
      if (strcmp(e.proffession, "directeur") == 0) {
        rewind(fp);
        while (fread( & e1, sizeof(e1), 1, fp) == 1) {
          if (strcmp(e.proffession, e1.proffession) == 0) {
            puts("il existe deja un directeur !!");
            break;
          }
        }
      }
    } while ((strcmp(e.proffession, "professeur") != 0) && (strcmp(e.proffession, "directeur") != 0) && (strcmp(e.proffession, "securite") != 0) && (strcmp(e.proffession, "officier") != 0 && (strcmp(e.proffession, "secretaire") != 0)));
    fwrite( & e, sizeof(e), 1, fp); 
    printf("\najouter un nouveau employee(y/n) ");
    fflush(stdin);
    another = getche();
  }
}
void afficheemp(){
	        system("cls");
			rewind(fp); 
			while(fread(&e,sizeof(e),1,fp)==1) 
            {
			    printf("\nnom:%10s  prenom:%10s  CIN:%8s  EMAIL:%25s   DN:%d/%d/%d   tele:%10s    SALAIRE:%.2f    PROFESSION:%10s",e.nom,e.prenom,e.CIN,e.email,e.d.jj,e.d.mm,e.d.aaaa,e.tele,e.salaire,e.proffession);
            }
            getch();
}
void modifier() {
	struct emp e1;
	int champ;
	int LA;
  system("cls");
  another = 'y';
  while (another == 'y' || another == 'Y') {
  	LA=0;
    printf("\nMODIFIER\n");
    printf("ENTRER LE CIN DE L'EMPLOYEE': ");
    scanf("%s", CINc);
    rewind(fp);
    while (fread( & e, sizeof(e), 1, fp) == 1)
    {
      if (strcmp(e.CIN, CINc) == 0)
      {  LA=1;
        do {
          printf("\n entrer le champ que vous voulez modifier: \n1-nom\n2-prenom\n3-cin\n4-email \n5-date de naissance(dn)\n 6-telephone \n 7-salaire \n 8-proffession \t");
          scanf("%d", & champ);
        } while (champ < 1 && champ > 8);
        switch (champ){
		case 1:{
		  printf("\n ancienne nom est %s", e.nom);
          printf("\n entrer le nouveau nom\t");
          fflush(stdin);
          gets(e.nom);
			break;
		}
		case 2:{
		  printf("\n ancienne prenom est %s", e.prenom);
          printf("\n entrer le nouveau prenom \t");
          fflush(stdin);
         gets(e.prenom);
			break;
		}
		case 3 :{
		  printf("\n ancienne CIN est %s", e.CIN);
          printf("\n entrer le nouveau CIN\t");
          fflush(stdin);
          gets(e.CIN);
			break;
		}
		case 4 :{
		  printf("\n ancienne mail est %s", e.email);
          printf("\n entrer le nouveau email\t");
          fflush(stdin);
          gets(e.email);
			break;
		}
		case 5 :{
		  printf("\n ancienne date de naissance est %d/%d/%d", e.d.jj, e.d.mm, e.d.aaaa);
          printf("\n entrer le nouveau date de naissance jj/mm/aaaa\t");
          scanf("%d/%d/%d", &e.d.jj, &e.d.mm, &e.d.aaaa);
			break;
		}
		case 6 :{
		  printf("\n ancienne telephone est %s", e.tele);
          printf("\n entrer le nouveau telephone");
          fflush(stdin);
          gets(e.tele);
			break;
		}
		case 7 :{
		  printf("\n ancienne salaire est %f", e.salaire);
          printf("\n entrer le nouveau salaire");
          fflush(stdin);
          scanf("%f", e.salaire);
			break;
		}
		case 8 :{
		  printf("\n ancienne profession est %s", e.proffession);
          printf("\n entrer le nouveau profession :directeur / professeur/ securite/ officier / secretaire ?\t");

          fflush(stdin);
          gets(e.proffession);
          if (strcmp(e.proffession, "directeur") == 0) {
        rewind(fp);
        while (fread( & e1, sizeof(e1), 1, fp) == 1) {
          if (strcmp(e.proffession, e1.proffession) == 0) {
            puts("il existe deja un directeur !!");
            break;
          }
        }
		}
		break;
		}
		}
        fseek(fp, -g, SEEK_CUR); 
        fwrite( & e, sizeof(e), 1, fp); 
        break;
      }
      
      
    }
    if(LA==0) printf("\n n'existe pas");
    printf("\nModifier un autre employee(y/n)");
    fflush(stdin);
    another = getche();
  }

}
void supprimer() {

  system("cls");
  int j=0;
  another = 'y';
  while (another == 'y' || another == 'Y') {
    printf("\nEntrer le CIN de l'employee que vous voulez supprimer: ");
    scanf("%s", CINc);
    ft = fopen("TEMPL.DAT", "wb+");
    rewind(fp); 
    while (fread( & e, sizeof(e), 1, fp) == 1) 
    {
      if (strcmp(e.CIN, CINc) != 0) 
      {
        fwrite( & e, sizeof(e), 1, ft); 
      } else {
        j++;
      }
    }
    
    fclose(fp);
    fclose(ft);
    remove("EMPL.DAT"); 
    rename("TEMPL.DAT", "EMPL.DAT"); 
    fp = fopen("EMPL.DAT", "rb+");
    if (j == 0) {
      puts("Ce CIN n'existe pas .");
      }
      else {
      	printf("\n enregistrement supprim?e\n");
	  }
    printf("supprimer un autre employee(y/n)");
    fflush(stdin);
    another = getche();
  }

}
void consulterprof() {
  int m=0;
  system("cls");
  do {
    printf("\nEntrer la profession: directeur /  professeur / securite/ officier / secretaire:\t");
    fflush(stdin);
	gets(proff);
  } while ((strcmp(proff, "professeur") != 0) && (strcmp(proff, "directeur") != 0) && (strcmp(proff, "securite") != 0) && (strcmp(proff, "officier") != 0) && (strcmp(e.proffession, "secretaire") != 0));
  rewind(fp);
  while (fread( & e, sizeof(e), 1, fp) == 1) 
  {
    if (strcmp(e.proffession, proff) == 0) {
    	m=1;
      printf("\nnom:%10s    prenom:%10s    CIN:%8s     EMAIL:%25s    DN:%d/%d/%d    tele:%10s     SALAIRE:%.2f     PROFESSION:%10s", e.nom, e.prenom, e.CIN, e.email, e.d.jj, e.d.mm, e.d.aaaa, e.tele, e.salaire, e.proffession); 
    }
  }
  if(m==0) printf("\nauccun employee dans la profession %s\n",proff);
  getch();

}

void cherchernomprenom() {
  int j = 0;
  system("cls");
  printf("\nEnter le nom de l'employee que vous voulez chercher':\t");
  scanf("%s", empnom);
  printf("\nEnter le prenom de l'employee que vous voulez chercher':\t");
  scanf("%s", empprenom);

  rewind(fp);
  while (fread( & e, sizeof(e), 1, fp) == 1)
  {
    if (strcmp(e.nom, empnom) == 0 && strcmp(e.prenom, empprenom) == 0) {
      j = 1;
      printf("\nnom:%6s  ?prenom:%6s CIN:%8s EMAIL:%20s DN:%d/%d/%d tele:%10s SALAIRE:%.2f PROFESSION:%10s", e.nom, e.prenom, e.CIN, e.email, e.d.jj, e.d.mm, e.d.aaaa, e.tele, e.salaire, e.proffession); 
    }

  }
  if (j == 0) printf("l'employee n'existe pas dans la liste ");
  getch();
}
void cherchernom() {
  int a = 0;

  system("cls");
  printf("\nEnter le nom ?de l'employee que vous voulez chercher':\t");
  scanf("%s", empnom);
  rewind(fp);
  while (fread( & e, sizeof(e), 1, fp) == 1) 
  {
    if (strcmp(e.nom, empnom) == 0) {
      a = 1;
      printf("\nnom:%6s  prenom:%6s CIN:%8s EMAIL:%20s DN:%d/%d/%d tele:%10s SALAIRE:%.2f PROFESSION:%10s", e.nom, e.prenom, e.CIN, e.email, e.d.jj, e.d.mm, e.d.aaaa, e.tele, e.salaire, e.proffession); 
    }

  }
  if (a == 0) printf("l'employee n'existe pas dans la liste ");
  getch();
}
void cherchecin() {
  int b = 0;
  system("cls");
  printf("\nEnter le CIN ?de l'employee que vous voulez chercher':\t");
  scanf("%s", CINc);
  rewind(fp);
  while (fread( & e, sizeof(e), 1, fp) == 1) 
  {
    if (strcmp(e.CIN, CINc) == 0) {
      b = 1;
      printf("\nnom:%6s ?prenom:%6s CIN:%8s EMAIL:%20s DN:%d/%d/%d tele:%10s SALAIRE:%.2f PROFESSION:%10s", e.nom, e.prenom, e.CIN, e.email, e.d.jj, e.d.mm, e.d.aaaa, e.tele, e.salaire, e.proffession); 
    }

  }
  if (b == 0) printf("l'employee n'existe pas dans la liste ");
  getch();

}
void chercher(){
     system("cls");
	char choix;
	printf("\ndonner votre choix : \n1-chercher par nom\n2-chercher  par nom et prenom\n3-chercher par CIN\n ");
	choix=getche();
	switch (choix){
		case '1':{
           cherchernom();
			break;
		}
		case '2':{
			cherchernomprenom();
			break;
		}
		case '3':{
			cherchecin();
			break;
		}
	}
}
int main() {
  int V = 0;
  int j = 0;
  int a = 0;
  system("color 80");
  system("cls");
  system("color 80");
   system("cls");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
   printf("\n\t\t\t\t\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t\t\t\t############           gestion de personnels ENSA-H            ############");
    printf("\n\t\t\t\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t\t\t\t\t\t---------------------------------------------------------------------------\n");
  printf("\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------------------------\n");
   printf("\n\n\n\n\n\n");
  char choix;
  V = login();
  if (V != 1) {

    exit(0);
  }
  fp = fopen("EMPL.DAT", "rb+");
  if (fp == NULL) {
    fp = fopen("EMPL.DAT", "wb+");
    if (fp == NULL) {
      printf("Connot open file");
      exit(1);
    }
  }
system("color 80");
  while (1) {
  	system("cls");
      printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
 printf("\n\t\t\t\t\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t\t\t\t############                  -BIENVENUE-                      ############");
    printf("\n\t\t\t\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t\t\t\t\t\t---------------------------------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t\t\t\t     MENU PRINCIPAL:\n");
    printf("\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n");
    // printf("\n\t\t\t\t\t\t\t\t\t\t\t\tMENU PRINCIPAL:\n");
    printf("\t1. ajouter un employee\n"); 
    printf("\t2. la liste des employees\n");
    printf("\t3. Modifier un employee par CIN\n"); 
    printf("\t4. supprimer un employee \n");
    printf("\t5. consulter les membres d'une profession \n"); 
    printf("\t6. chercher\n");
     printf("\t7. quitter\n");
    printf("\tvotre choix: ");
    fflush(stdin);
    choix = getchar();
    switch (choix) {
    case '1':
      ajoutemp();
      break;
    case '2':
      afficheemp();
      break;

    case '3':
      modifier();
      break;
    case '4':
      supprimer();
      break;
    case '5':
      consulterprof();
      break;
    case '6':
      chercher();
      break;
    case '7':
      fclose(fp);
      exit(0);
    }
  }
  return 0;
}