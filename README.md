# myapp
                                                      Application de gestion de location de voitures

 


Tables de matières......1 

Introduction............2

Etude des besoins.......3

Analyse et Réalisation..4

Conclusion..............5

Equipe de travail.......6




                                      
                                                         
   ********************************************************************************************************************************************************************                                     

I.INTRODUCTION
La gestion traditionnelle d'une agence de location de voiture nécessite un grand effort de la part du personnel , il faut utiliser des formulaires en papier pour
clients ,pour les contrats , des archives pour stocker toute ancienne opération ou transaction , ce qui rend le travail désagréable , la nouvelle technologie
informatique présente une solution a ces problèmes avec l'utilisation des applications developpés avec de different languages de programmation ,qui consiste 
a automatiser et informatiser la gestion . Notre travail consiste donc à la conception et l’étude d’une application de gestion de location de voitures . 
A travers notre application, il est possible de réaliser toutes les opérations nécessaires pour la gestion des clients (locataires), la gestion des voitures 
et la gestion des locations.
 Nous espérons que vous prendrez autant de plaisir à lire ce rapport que nous en avons pris durant tout le déroulement de ce projet.
 
 ************************************************************************************************************************************************************************
 
II. Etude de Besoins


Le système comportera différentes fonctionnalités nécessaires pour une meilleure gestion. L’application doit accomplir les traitements suivants : L’affichage, l’ajout,
la modification et la suppression d’un client, ou d’une voiture d’où il est nécessaire d’avoir tous les renseignements dont on a besoin des voitures et des clients pour
ces traitements . La gestion des locations : ajout, annulation, modification, suppression, affichage des contrats. Ces informations seront stockées dans des fichiers
bien stucturés ,et qui peuvent être mis à jour au fur et à mesure des besoins.

                                                                                                                                                                                                                                                                                                                                      
**************************************************************************************************************************************************************************

III. Analyse et Réalisation
Le langage utilisé pour développer cette application est le langage c ,les données manipulées sont enregistrées dans des fichiers « Voitures », « Clients » et 
« ContratsLocations » et sont structurées de la manière suivante :
 typedef struct Voiture { int idVoiture; char marque[15]; char nomVoiture[15]; char couleur[7]; int nbplaces; int prixJour; char EnLocation[4]; } voiture;
 typedef struct contratLocation { float numContrat; int idVoiture; int idClient; date debut; date fin; int cout; } contrat; 
typedef struct Client { int idClient; char nom[20]; char prenom[20]; int cin; char adresse[15]; int telephone; }client;
A  l’ouverture de l’application on trouve un menu principal qui permet de faire le choix entre : 1).accéder au menu de gestion des locations , 2. accéder au menu de 
gestion de la liste des voitures enregistrées , 3.accéder au menu de gestion des clients , ou 4. quitter l’application.


Chaque choix (à l’exception du dernier) nous ramène à un autre menu , réalisé à l’aide d’une boucle do{}while :
Le choix 1 :  Menu de location de voiture
Permet de faire le choix entre :
1)	afficher les informations d’un contrat à partir de son numéro (l’attribut numContrat) , 2) louer une nouvelle voiture, ce qui permettra de demander au client de 
saisir ses informations (nom, prénom) et les informations sur la voiture qu’il souhaite louer. Deux vérifications seront ensuite effectuées : La première est la
vérification du client et de la voiture, la deuxième vérification concerne la disponibilité de la voiture demandée .Apres la voiture sera louée, ce qui implique 
d’abord de modifier la valeur de l’attribut « EnLocation » dans la structure « Voiture », et aussi de créer un nouveau contrat de location en demandant au client
de saisir les 

informations nécessaires selon la structure « contartLocation », 3) retourner une voiture déjà louée, ce qui implique de modifer la valeur de l’attribut « EnLocation » 
dans la structure « Voiture et de supprimer le contrat de location , 4) modifier le contrat de location si le client souhaite modifier les informations sur le contrat
tel que la date de retour ; 4) supprimer un contrat si la voiture louée est rendue et 5) retourner au menu principal.
       Les données dans ce menu sont manipulés enregistrés dans le fichier « contratlocation.txt » .

Le choix 2 :Menu des gestion de voitures
Permet de faire le choix entre : 1) afficher la liste des voitures déjà enregistrées dans le fichier « Voitures » ; 2) ajouter une nouvelle voiture dans le fichier
« Voitures »; 3) modifier les informations concernant une voiture déjà enregistrée ; 4) de supprimer une voiture du fichier « Voitures » et 5) retourner au menu principal.
Les données dans ce menu sont manipulés enregistrés dans le fichier « voitures » .      
                                                                                              
Le choix 3 : Menu des gestion de Clients
Permet de faire le choix entre : 
1)	afficher la liste des clients déjà enregistrées dans le fichier « Clients » ; 2) ajouter un nouveau client dans le fichier « Clients »; 3) modifier les informations
concernant un client déjà enregistré ; 4) de supprimer un client du fichier « Clients » et 5) retourner au menu principal.  Les données dans ce menu sont aussi manipulés
et enregistrés dans le fichier Clients, et à l’aide des fonctions fscanf_s et  fprintf_s.

A ce qui concerne l’interface graphique ,on a malheureusement trouvé beaucoup de difficultés  en essayant de la réaliser avec GTK+ , alors on l’a pas utilisé .
REMARQUE : Prière de créer les trois fichiers sur votre pc pour assurer le bon fonctionnement de l’application( voiture.txt  Clients.txt  contratlocation.txt ). 
                                                                   
**********************************************************************************************************************************************************************

Conclusion :

Au final, nous avons beaucoup travaillé pendant les séances et hors des séances. Nous avons compris qu’il est important d’évaluer les connaissances de chacun, et de faire
un point sur nos tâches régulièrement. Nous avons appris à gérer un projet et à faire face aux difficultés ensemble.  


 *********************************************************************************************************************************************************************

Equipe de travail :   (smi4 g3b)

Mohammed Rmioui 

Atika Wamra

                                                                                     
