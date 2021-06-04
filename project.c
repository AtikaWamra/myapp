#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* contrat_out = ("%f %d %d %d / %d / %d  %d / %d / %d  %d \n");
const char* contrat_in = ("%0.2f %d %d %d / %d / %d  %d / %d / %d  %d \n");
const char* Client_in = ("%d %s %s %d  %s  %d \n");
const char* Client_out = ("%d %s %s %d  %s  %d");
const char* car_out = (" %d  %s  %s  %s  %d   %d  %s ");
const char* car_in = (" %d  %s  %s  %s  %d   %d  %s \n");

typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int cin;
 char adresse[15];
 int telephone;
}client;

typedef struct Voiture
{
 int idVoiture;
 char marque[15];
 char nomVoiture[15];
 char couleur[7];
 int nbplaces;
 int prixJour;
 char EnLocation[4];
} voiture;


typedef struct date {
int jours ;
int mois;
int annes;
}date;

typedef struct contratLocation
{
 float numContrat;
 int idVoiture;
 int idClient;
 date debut;
 date fin;
 int cout;
} contrat;

void modifier_contract()
{
	int ctr_num;
  printf("Donnez le numero de contrat que vous voulez modifier \n");
  scanf("%d",&ctr_num);
  contrat ctr;
  FILE *dlt_file,*fl;
  int status;
dlt_file = fopen("dlt.txt","w");
fl         = fopen("contratlocation.txt","r");

  do{

     status = fscanf_s(fl,contrat_out,&ctr.numContrat,&ctr.idVoiture,&ctr.idClient,&ctr.debut.jours,&ctr.debut.mois,&ctr.debut.annes,&ctr.fin.jours,&ctr.fin.mois,&ctr.fin.annes,&ctr.cout);

     if(status > 0){
            if(ctr.numContrat != ctr_num){
            fprintf(dlt_file,contrat_in,ctr.numContrat,ctr.idVoiture,ctr.idClient,ctr.debut.jours,ctr.debut.mois,ctr.debut.annes,ctr.fin.jours,ctr.fin.mois,ctr.fin.annes,ctr.cout);
                                        }
            else{
      printf("entrez :numContrat ");
	  scanf("%f",&ctr.numContrat);
 	  printf("entrez :idVoiture ");
	  scanf("%d",&ctr.idVoiture);
 	  printf("entrez :idClient ");
	  scanf("%d",&ctr.idClient);
 	  printf("entrez :date debut");
	  scanf("%d",&ctr.debut.jours);scanf("%d",&ctr.debut.mois);scanf("%d",&ctr.debut.annes);
 	  printf("entrez :date fin");
	  scanf("%d",&ctr.fin.jours);scanf("%d",&ctr.fin.mois);scanf("%d",&ctr.fin.annes);
 	  printf("entrez :cout ");
	  scanf("%d",&ctr.cout);

	  fprintf_s(dlt_file,contrat_in,ctr.numContrat,ctr.idVoiture,ctr.idClient,ctr.debut.jours,ctr.debut.mois,ctr.debut.annes,ctr.fin.jours,ctr.fin.mois,ctr.fin.annes,ctr.cout);
      }
     }

     }while(status > 0);

fclose(dlt_file);
fclose(fl);
dlt_file = fopen("dlt.txt","r");
fl         = fopen("contratlocation.txt","w");
   do{
     status = fscanf_s(dlt_file,contrat_out,&ctr.numContrat,&ctr.idVoiture,&ctr.idClient,&ctr.debut.jours,&ctr.debut.mois,&ctr.debut.annes,&ctr.fin.jours,&ctr.fin.mois,&ctr.fin.annes,&ctr.cout);
    if(status > 0){
        fprintf_s(fl,contrat_in,ctr.numContrat,ctr.idVoiture,ctr.idClient,ctr.debut.jours,ctr.debut.mois,ctr.debut.annes,ctr.fin.jours,ctr.fin.mois,ctr.fin.annes,ctr.cout);
     }
     }while(status > 0);

fclose(dlt_file);
fclose(fl);



}



void visualiser_contrat()/// verified//
{
FILE *contrat_file;
contrat s_contrat ;
int status;
float numContrat;
          printf("Donnez le numéro du contrat : \n");
          scanf("%f",&numContrat);
 contrat_file = fopen("contratlocation.txt","r");
 do{
    status = fscanf_s(contrat_file,contrat_out,&s_contrat.numContrat,&s_contrat.idVoiture,&s_contrat.idClient,&s_contrat.debut.jours,&s_contrat.debut.mois,&s_contrat.debut.annes,&s_contrat.fin.jours,&s_contrat.fin.mois,&s_contrat.fin.annes,&s_contrat.cout);
   if(status > 0 ){
   if(numContrat == s_contrat.numContrat ){
      printf("%0.2f %d %d %d / %d / %d  %d / %d / %d  %d \n",s_contrat.numContrat,s_contrat.idVoiture,s_contrat.idClient,s_contrat.debut.jours,s_contrat.debut.mois,s_contrat.debut.annes,s_contrat.fin.jours,s_contrat.fin.mois,s_contrat.fin.annes,s_contrat.cout);
      }
      }
 }while(status > 0 );
  fclose(contrat_file);
}

void Change_F(int Car_id)/// verified//
{
  voiture car;
  FILE *delet_file,*fp;
  int status;
delet_file = fopen("delet.txt","w");
fp         = fopen("voiture.txt","r");

  do{

     status = fscanf_s(fp,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);

     if(status > 0){
            if(car.idVoiture != Car_id){
            fprintf(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
                                        }
            else{
       strcpy(car.EnLocation,"oui");
	  fprintf_s(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
      }
     }

     }while(status > 0);

fclose(delet_file);
fclose(fp);
delet_file = fopen("delet.txt","r");
fp         = fopen("voiture.txt","w");
   do{
     status = fscanf_s(delet_file,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
    if(status > 0){
        fprintf_s(fp,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
     }
     }while(status > 0);

fclose(delet_file);
fclose(fp);

}




void Change_F2(int Car_id)/// verified//
{
  voiture car;
  FILE *delet_file,*fp;
  int status;
delet_file = fopen("delet.txt","w");
fp         = fopen("voiture.txt","r");

  do{

     status = fscanf_s(fp,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);

     if(status > 0){
            if(car.idVoiture != Car_id){
            fprintf(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
                                        }
            else{
       strcpy(car.EnLocation,"non");
	  fprintf_s(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
      }
     }

     }while(status > 0);

fclose(delet_file);
fclose(fp);
delet_file = fopen("delet.txt","r");
fp         = fopen("voiture.txt","w");
   do{
     status = fscanf_s(delet_file,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
    if(status > 0){
        fprintf_s(fp,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
     }
     }while(status > 0);

fclose(delet_file);
fclose(fp);

}



void Delet_contrat1(float numcontrat)/// verified//
{

  contrat s_contrat;
  FILE *delet_file,*fp;
  int status ;

delet_file = fopen("delet_contrat.txt","w");
fp         = fopen("contratlocation.txt","r");
  do{
      status = fscanf_s(fp,contrat_out,&s_contrat.numContrat,&s_contrat.idVoiture,&s_contrat.idClient,&s_contrat.debut.jours,&s_contrat.debut.mois,&s_contrat.debut.annes,&s_contrat.fin.jours,&s_contrat.fin.mois,&s_contrat.fin.annes,&s_contrat.cout);
   if(status > 0){
        if(s_contrat.numContrat != numcontrat ){

       fprintf_s(delet_file,contrat_in,s_contrat.numContrat,s_contrat.idVoiture,s_contrat.idClient,s_contrat.debut.jours,s_contrat.debut.mois,s_contrat.debut.annes,s_contrat.fin.jours,s_contrat.fin.mois,s_contrat.fin.annes,s_contrat.cout);

        }
        }


     }while(status > 0);

fclose(delet_file);
fclose(fp);
delet_file = fopen("delet_contrat.txt","r");
fp         = fopen("contratlocation.txt","w");
   do{
      status = fscanf_s(delet_file,contrat_out,&s_contrat.numContrat,&s_contrat.idVoiture,&s_contrat.idClient,&s_contrat.debut.jours,&s_contrat.debut.mois,&s_contrat.debut.annes,&s_contrat.fin.jours,&s_contrat.fin.mois,&s_contrat.fin.annes,&s_contrat.cout);
    if(status > 0 ){
       fprintf_s(fp,contrat_in,s_contrat.numContrat,s_contrat.idVoiture,s_contrat.idClient,s_contrat.debut.jours,s_contrat.debut.mois,s_contrat.debut.annes,s_contrat.fin.jours,s_contrat.fin.mois,s_contrat.fin.annes,s_contrat.cout);
       }
     }while(status > 0);

fclose(delet_file);
fclose(fp);

}
void Delete_contrat()/// verified//
{ float numcontrat;int id;
  printf("donnez numero du contrat");
  scanf("%f",&numcontrat);
  printf("donnez l'id de voiture concernée");
  scanf("%d",&id);
  contrat s_contrat;
  FILE *delet_file,*fp;
  int status ;

delet_file = fopen("delet_contrat.txt","w");
fp         = fopen("contratlocation.txt","r");
  do{
      status = fscanf_s(fp,contrat_out,&s_contrat.numContrat,&s_contrat.idVoiture,&s_contrat.idClient,&s_contrat.debut.jours,&s_contrat.debut.mois,&s_contrat.debut.annes,&s_contrat.fin.jours,&s_contrat.fin.mois,&s_contrat.fin.annes,&s_contrat.cout);
   if(status > 0){
        if(s_contrat.numContrat != numcontrat ){

       fprintf_s(delet_file,contrat_in,s_contrat.numContrat,s_contrat.idVoiture,s_contrat.idClient,s_contrat.debut.jours,s_contrat.debut.mois,s_contrat.debut.annes,s_contrat.fin.jours,s_contrat.fin.mois,s_contrat.fin.annes,s_contrat.cout);
        }
        }
     }while(status > 0);

fclose(delet_file);
fclose(fp);
delet_file = fopen("delet_contrat.txt","r");
fp         = fopen("contratlocation.txt","w");
   do{
      status = fscanf_s(delet_file,contrat_out,&s_contrat.numContrat,&s_contrat.idVoiture,&s_contrat.idClient,&s_contrat.debut.jours,&s_contrat.debut.mois,&s_contrat.debut.annes,&s_contrat.fin.jours,&s_contrat.fin.mois,&s_contrat.fin.annes,&s_contrat.cout);
    if(status > 0 ){
       fprintf_s(fp,contrat_in,s_contrat.numContrat,s_contrat.idVoiture,s_contrat.idClient,s_contrat.debut.jours,s_contrat.debut.mois,s_contrat.debut.annes,s_contrat.fin.jours,s_contrat.fin.mois,s_contrat.fin.annes,s_contrat.cout);
       }
     }while(status > 0);

fclose(delet_file);
fclose(fp);
Change_F2( id );
}


void retourner_voiture() ///verified///
{
  int id , numcontrat;
  printf("------- Donnez l ID de la voiture retournee et le num du contrat -------------\n");
  scanf("%d %d",&id,&numcontrat);
  Delet_contrat1(numcontrat);
  Change_F2( id );

}

void ajoutercontrat()
  {
    contrat s_contrat ;

 	FILE *fc;
    fc = fopen("contratlocation.txt","a");
      printf("entrez :numContrat ");
	  scanf("%f",&s_contrat.numContrat);
 	  printf("entrez :idVoiture ");
	  scanf("%d",&s_contrat.idVoiture);
 	  printf("entrez :idClient ");
	  scanf("%d",&s_contrat.idClient);
 	  printf("entrez :date debut");
	  scanf("%d",&s_contrat.debut.jours);scanf("%d",&s_contrat.debut.mois);scanf("%d",&s_contrat.debut.annes);
 	  printf("entrez :date fin");
	  scanf("%d",&s_contrat.fin.jours);scanf("%d",&s_contrat.fin.mois);scanf("%d",&s_contrat.fin.annes);
 	  printf("entrez :cout ");
	  scanf("%d",&s_contrat.cout);
     fprintf_s(fc,contrat_in,s_contrat.numContrat,s_contrat.idVoiture,s_contrat.idClient,s_contrat.debut.jours,s_contrat.debut.mois,s_contrat.debut.annes,s_contrat.fin.jours,s_contrat.fin.mois,s_contrat.fin.annes,s_contrat.cout);

  fclose(fc);
 }



int louer()/// !!!! ////
{
int id;
int cin,status;
voiture car;
client s_client;
int trouvee = 0,trouvee_voiture = 0;
FILE *Client_file,*fp;
 printf("Entrez votre CIN et l ID de la voiture voulu : \n");
 scanf("%d %d",&cin,&id);
 Client_file = fopen("Clients.txt","r");
 do{

  status = fscanf_s(Client_file,Client_out,&s_client.idClient,&s_client.nom,20,&s_client.prenom,20,&s_client.cin,&s_client.adresse,15,&s_client.telephone);
      if(status > 0)  {  if( cin == s_client.cin ){
            printf("--------- Client touvee ------------- \n");
            trouvee = 1 ;
            break;
         }}
}while(status > 0 );
  fclose(Client_file);
    if(!trouvee){
        printf("------ Enregistrez vous dans Gestion client , ajouter client -------- \n");

        return 0 ;
    }
 fp = fopen("voiture.txt","r");
do{

  status = fscanf_s(fp,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
      if( status > 0 ){
            if(id == car.idVoiture ){

            if(strcmp(car.EnLocation,"oui") == 0 ){
            printf("-------- La voiture deja louee vous pouver choisir une autre ----------- \n");

            return 0 ;
         }else{
            trouvee_voiture = 1 ;
            printf("--------- Voiture touvee ------------- \n");
            ajoutercontrat();
         }
         }
      }
}while(status > 0 );
 fclose(fp);
   if( trouvee_voiture == 1 ){
    Change_F(id);
   }
 return 0 ;
}





void Listedesvoitures()//afficher la liste des voiture !!! vous fallez ouvrir le fichier fp en mode lecture avant de le passer comme argument
{
    FILE *fp;
    fp = fopen("voiture.txt","r");
   int status;
   voiture car;
    do
        {
      status = fscanf_s(fp,car_in,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
      if(!(status > 0)){break;}
      printf("%d  %s  %s  %s  %d   %d  %s \n",car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
      }while(status > 0);
   	fclose(fp);
}




void supprimervoiture()// supprimer une voiture elle prend id du voiture
{
  int id;

  voiture car;
  FILE *delet_file,*fp;
  int status ;
  printf("Donnez l ID de la voiture que voulez vous la supprimer \n");
  scanf("%d",&id);
delet_file = fopen("delet.txt","w");
fp         = fopen("voiture.txt","r");
  do{
     status = fscanf_s(fp,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
    if(status > 0){
        if(car.idVoiture != id){
         fprintf_s(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
         }
    }

     }while(status > 0);

fclose(delet_file);
fclose(fp);
delet_file = fopen("delet.txt","r");
fp         = fopen("voiture.txt","w");
   do{
     status = fscanf_s(delet_file,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
     if(status > 0){
        fprintf_s(fp,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
      }
     }while(status > 0);

fclose(delet_file);
fclose(fp);

}





void modifiervoiture()//elle prend id du voiture pour modifier les infos de la voiture
{
  int Car_id;
  printf("Donnez l ID de la voiture que voulez vous la modifier \n");
  scanf("%d",&Car_id);
  voiture car;
  FILE *delet_file,*fp;
  int status;
delet_file = fopen("delet.txt","w");
fp         = fopen("voiture.txt","r");

  do{

     status = fscanf_s(fp,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);

     if(status > 0){
            if(car.idVoiture != Car_id){
            fprintf(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
                                        }
            else{
      printf("entrez :idVoiture ");
	  scanf("%d",&car.idVoiture);
 	  printf("entrez :marque ");
	  scanf("%s",&car.marque);
 	  printf("entrez :nomVoiture ");
	  scanf("%s",&car.nomVoiture);
 	  printf("entrez :couleur ");
	  scanf("%s",&car.couleur);
 	  printf("entrez :nbplaces ");
	  scanf("%d",&car.nbplaces);
 	  printf("entrez :prixJour ");
	  scanf("%d",&car.prixJour);
 	  printf("entrez :EnLocation ");
	  scanf("%s",&car.EnLocation);
	  fprintf_s(delet_file,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
      }
     }

     }while(status > 0);

fclose(delet_file);
fclose(fp);
delet_file = fopen("delet.txt","r");
fp         = fopen("voiture.txt","w");
   do{
     status = fscanf_s(delet_file,car_out,&car.idVoiture,&car.marque,15,&car.nomVoiture,15,&car.couleur,7,&car.nbplaces,&car.prixJour,&car.EnLocation,4);
    if(status > 0){
        fprintf_s(fp,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);
     }
     }while(status > 0);

fclose(delet_file);
fclose(fp);

}





void ajoutervoiture() //ajouter une voiture a la liste des voitures
 {
    voiture car;
 	int nbr_car,i;
 	FILE *fp;
    fp = fopen("voiture.txt","a");

 	printf("combien de voiture voulez vous ajouter ! \n");
	scanf("%d",&nbr_car);
	for( i = 0 ; i < nbr_car ; i++ ){
 	printf("entrez :idVoiture ");
	scanf("%d",&car.idVoiture);
 	printf("entrez :marque ");
	scanf("%s",&car.marque);
 	printf("entrez :nomVoiture ");
	scanf("%s",&car.nomVoiture);
 	printf("entrez :couleur ");
	scanf("%s",&car.couleur);
 	printf("entrez :nbplaces");
	scanf("%d",&car.nbplaces);
 	printf("entrez :prixJour");
	scanf("%d",&car.prixJour);
 	printf("entrez :EnLocation");
    scanf("%s",&car.EnLocation);



      	 fprintf_s(fp,car_in,car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbplaces,car.prixJour,car.EnLocation);

	  }
  fclose(fp);
 }


 //fct client
 void Listedesclients()
{
    FILE *fc;
    fc = fopen("Clients.txt","r");
   int status=0;
   client clt;
    do
        {
      status = fscanf_s(fc,Client_out,&clt.idClient,&clt.nom,20,&clt.prenom,20,&clt.cin,&clt.adresse,15,&clt.telephone);
      if(!(status > 0)){break;}
      printf("%d  %s  %s   %d  %s  %d \n",clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
      }while(status > 0);
   	fclose(fc);
}


void supprimerclient()
{
  int id;

  client clt;
  FILE *delete_file,*fc;
  int status ;
  printf("Donnez l ID du client que voulez vous supprimer \n");
  scanf("%d",&id);
delete_file = fopen("delete.txt","w");
fc         = fopen("Clients.txt","r");
  do{
     status = fscanf_s(fc,Client_out,&clt.idClient,&clt.nom,20,&clt.prenom,20,&clt.cin,&clt.adresse,15,&clt.telephone);
    if(status > 0){
        if(clt.idClient != id){
         fprintf_s(delete_file,Client_in,clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
         }
    } }while(status > 0);

fclose(delete_file);
fclose(fc);
delete_file = fopen("delete.txt","r");
fc         = fopen("Clients.txt","w");
   do{
     status = fscanf_s(delete_file,Client_out,&clt.idClient,&clt.nom,20,&clt.prenom,20,&clt.cin,&clt.adresse,15,&clt.telephone);
     if(status > 0){
        fprintf_s(fc,Client_in,clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
      }
     }while(status > 0);

fclose(delete_file);
fclose(fc);

}


void modifierclient()
{
  int Clt_id;
  printf("Donnez l ID du client que vous voulez modifier \n");
  scanf("%d",&Clt_id);
  client clt;
  FILE *delete_file,*fc;
  int status;
delete_file = fopen("delete.txt","w");
fc         = fopen("Clients.txt","r");

  do{

     status = fscanf_s(fc,Client_out,&clt.idClient,&clt.nom,20,&clt.prenom,20,&clt.cin,&clt.adresse,15,&clt.telephone);

     if(status > 0){
            if(clt.idClient != Clt_id){
            fprintf_s(delete_file,Client_in,clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
                                        }
            else{
      printf("entrez :idClient ");
	  scanf("%d",&clt.idClient);
 	  printf("entrez :nom ");
	  scanf("%s",&clt.nom);
 	  printf("entrez :prenom ");
	  scanf("%s",&clt.prenom);
 	  printf("entrez :cin ");
	  scanf("%d",&clt.cin);
 	  printf("entrez :adresse ");
	  scanf("%s",&clt.adresse);
 	  printf("entrez :telephone ");
	  scanf("%d",&clt.telephone);

	  fprintf_s(delete_file,Client_in,clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
      }
     }

     }while(status > 0);

fclose(delete_file);
fclose(fc);
delete_file = fopen("delete.txt","r");
fc          = fopen("Clients.txt","w");
   do{
     status = fscanf_s(delete_file,Client_out,&clt.idClient,&clt.nom,20,&clt.prenom,20,&clt.cin,&clt.adresse,15,&clt.telephone);
    if(status > 0){
        fprintf_s(fc,Client_in,clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
     }
     }while(status > 0);

fclose(delete_file);
fclose(fc);
}
void ajouterclient()
  {
    client clt;
 	int nbr_clt,i;
 	FILE *fc;
    fc = fopen("Clients.txt","a");

 	printf("combien de clients voulez vous ajouter ! \n");
	scanf("%d",&nbr_clt);
	for( i = 0 ; i < nbr_clt ; i++ ){
      printf("entrez :idClient ");
	  scanf("%d",&clt.idClient);
 	  printf("entrez :nom ");
	  scanf("%s",&clt.nom);
 	  printf("entrez :prenom ");
	  scanf("%s",&clt.prenom);
 	  printf("entrez :cin ");
	  scanf("%d",&clt.cin);
 	  printf("entrez :adresse ");
	  scanf("%s",&clt.adresse);
 	  printf("entrez :telephone ");
	  scanf("%d",&clt.telephone);


      	 fprintf_s(fc,Client_in,clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);

	  }
  fclose(fc);
 }





void MenuGestiondesClients()
{

int choix;

   	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion Clients \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n\n");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Liste des clients.....................1   \xba");
    printf("\n               \xba    Ajouter clients.......................2   \xba");
    printf("\n               \xba    Modifier clients......................3   \xba");
    printf("\n               \xba    Suprimer clients......................4   \xba");
    printf("\n               \xba    Retour................................5   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");


	scanf("%d",&choix);

	switch(choix)
	{
    case 1:  Listedesclients();
	break;
 	case 2:  ajouterclient();
	break;
	case 3:	 modifierclient();
	break;
	case 4:  supprimerclient();
	break;
	case 5:  MenuPrincipal();
	break;
	}
    }


















void MenuLocation(){

int choix;
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Location   \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n\n");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Visualiser contract...................1   \xba");
    printf("\n               \xba    Louer voitures........................2   \xba");
    printf("\n               \xba    Retourner voitures....................3   \xba");
    printf("\n               \xba    Modifier contract.....................4   \xba");
    printf("\n               \xba    Supprimer contract....................5   \xba");
    printf("\n               \xba    Retour................................6   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

	scanf("%d",&choix);

	switch(choix)
	{
    case 1:  visualiser_contrat();break;
	case 2:  louer();break;
	case 3:	 retourner_voiture();break;
	case 4:  modifier_contract();break;
	case 5:  Delete_contrat();break;
	case 6:  MenuPrincipal();break;
	}
    }



  void MenuGestiondesVoitures()
{

int choix;

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3Gestion voitures \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n\n");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Liste des voitures....................1   \xba");
    printf("\n               \xba    Ajouter voiture.......................2   \xba");
    printf("\n               \xba    Modifier voiture......................3   \xba");
    printf("\n               \xba    Suprimer voiture......................4   \xba");
    printf("\n               \xba    Retour...............................5    \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");



	scanf("%d",&choix);

	switch(choix)
	{
    case 1:  Listedesvoitures();
	break;
 	case 2:  ajoutervoiture();
	break;
	case 3:	 modifiervoiture();
	break;
	case 4:  supprimervoiture();
	break;
	case 5:  MenuPrincipal();
	break;
	}
    }


void  MenuPrincipal()
{
int choix;
do{
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principal  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
    printf("\n\n");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Location..............................1   \xba");
    printf("\n               \xba    Gestion voitures......................2   \xba");
    printf("\n               \xba    Gestion clients.......................3   \xba");
    printf("\n               \xba    Quitter...............................4   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix);

	switch(choix)
	{
  case 1:  MenuLocation();
	break;
    case 2:  MenuGestiondesVoitures();
    break;
    case 3:	 MenuGestiondesClients();
 	break;
	}
    }while(choix!=4);
}
int main()
{
 MenuPrincipal();
}     
