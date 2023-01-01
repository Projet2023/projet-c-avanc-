#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct produit
{
	int co;
	char des[20];
	float pr;
	int qt;
};

void ajout();
void affiche();
void suppression(int);
void modification(int);
int recherche(int);
void consultation(int);
void main()
{
	int choix;
	char rep;
	int co_cons;
	int co_modif;
	int co_supp;
	do
    {
	printf("1: ajout d'un produit\n");
	printf("2: affichage de la liste des produits\n");
	printf("3: suppression d'un produit\n");
	printf("4: modification d'un produit\n ");
	printf("5: consultation d'un produit\n");
	printf("7: quitter\n");

	printf("Entrer votre choix \n");
	scanf("%d", &choix);
	system("cls");
	switch(choix)
	{
		case 1:
			ajout();
			break;
		case 2:
			affiche();
			break;
		case 3:
		    printf("donner le code du produit à supprimer\n");
            scanf("%d",&co_supp);
            suppression(co_supp);
			break;
		case 4:
		    printf("donner le code du produit à modifier\n");
            scanf("%d",&co_modif);
            modification(co_modif);
			break;
		case 5:
			printf("donner le code du produit à consulter\n");
            scanf("%d",&co_cons);
            consultation(co_cons);
            break;
        case 7:
            exit(0);
			break;
	    default:
            printf("Choix incorrect\n");
	}
	fflush(stdin);
	//printf("autre opération");
	//scanf("%c",&rep);
    }while (choix !=7); //(rep=='o');
}
void ajout()
{

	FILE *f;
	struct produit p,q;
    f=fopen("prod.txt","a+");

    if (f ==NULL)
        printf("erreur d'ouverture");
    else
    {
        if(fscanf(f,"%d %s %f %d", &q.co, q.des, &q.pr, &q.qt)==EOF)
        p.co=1;
        else
        {
            while(!feof(f))
                fscanf(f,"%d %s %f %d", &q.co, q.des, &q.pr, &q.qt);
            p.co=q.co+1;
        }
        fflush(stdin);
        printf("Donner la désignation");
        gets(p.des);
        do
        {
            printf("Donner le prix en dinar");
            scanf("%f",&p.pr);
        }while(p.pr<100 || p.pr>10000);
        do
        {
            printf("Donner la quantité");
            scanf("%d",&p.qt);
        }while(p.qt<1);
        fprintf(f,"%d %s %f %d\n",p.co,p.des,p.pr,p.qt );
        fclose(f);
    }
}
void affiche()
{
    FILE *f;
    struct produit p;
    int res;
    f=fopen("prod.txt","r");
    if(f==NULL)
         printf("erreur d'ouverture");
    else
    {
        while (!feof(f))
            {
                res=fscanf(f,"%d %s %f %d", &p.co, p.des, &p.pr, &p.qt);
                if (res != -1)//moin 1: valeur de   EOF
                    printf("%d %s %f %d\n", p.co, p.des, p.pr, p.qt);
            }
        fclose(f);
    }

}
int recherche(int co_rech)
{

	FILE *f;
	int existe;
	struct produit p;
	existe=0;
	f=fopen("prod.txt","r");
	if(f==NULL)
        printf("erreur d'ouverture");
    else
    {
        while (!feof(f) && existe==0)
        {
            fscanf(f,"%d %s %f %d", &p.co, p.des, &p.pr, &p.qt);
                if(p.c==c_rech)
                    existe=1;
        }
        fclose(f);
    }
	if(existe==0)
        return 0;
	else
        return 1;
}
void suppression(int co_supp)
{
    int rep;
    int res;
    FILE *f;
    FILE *ft;
    struct produit p;
    if(recherche(co_supp)==1)
    {
        printf("voule vous vraiment supprimer ce produit 1: oui et 0: non");
        scanf("%d",&rep);
        if(rep==1)
        {
            f=fopen("prod.txt","r");
            if(f==NULL)
                printf("erreur d'ouverture du fichier prod");
            else
            {
                ft=fopen("temp_prod.txt","w");
                if(ft==NULL)
                    printf("erreur d'ouverture du fichier temporaire");
                else
                {
                    while (!feof(f))
                    {
                        res=fscanf(f,"%d %s %f %d", &p.co, p.des, &p.pr, &p.qt);
                        if(p.c!=c_supp && res!=-1)
                            fprintf(ft,"%d %s %f %d\n", p.co, p.des, p.pr, p.qt);
                    }
                    fclose(f);
                    fclose(ft);
                }
			}
			remove("prod.txt");
            rename("temp_prod.txt","prod.txt");
        }
    }
    else
        printf("produit inexistant");

}
void modification(int co_modif)
{
	FILE *f;
	FILE *ft;
	int rep;
	int res;
	struct produit p;
	char n_des[20];
	float n_pr;
	int n_qt;

	if(recherche(co_modif)==1)
    {
        printf("voule vous vraiment modifier ce produit 1: oui et 0: non");
        scanf("%d",&rep);
        if(rep==1)
        {
            f=fopen("prod.txt","r");
            if(f==NULL)
                printf("erreur d'ouverture du fichier prod");
            else
            {
                ft=fopen("temp_prod.txt","w");
                if(ft==NULL)
                    printf("erreur d'ouverture du fichier temporaire");
                else
                {
                    while (!feof(f))
                    {
                        res = fscanf(f,"%d %s %f %d", &p.co, p.des, &p.pr, &p.qt);
                        if (res!=-1)
                        {if(p.co!=co_modif )
                            fprintf(ft,"%d %s %f %d\n", p.co, p.des, p.pr, p.qt);
                        else
                        {
                            fflush(stdin);
                            printf("donner la nouvelle désignation svp");
                            gets(n_des);
                            printf("donner le nouveau prix");
                            scanf("%f",&n_pr);
                            printf("donner la nouvelle quantité");
                            scanf("%d",&n_qt);
                            fprintf(ft,"%d %s %f %d\n",co_modif,n_des,n_prix,n_qt);
                        }}
                    }
                }
			fclose(f);
			fclose(ft);
			remove("prod.txt");
			rename("temp_prod.txt","prod.txt");
            }
        }
    }
    else
        printf("produit inexistant");

}
void consultation(int co_cons)
{
	FILE *f;
	int existe;
	struct produit p;
	existe=0;
	f=fopen("prod.txt","r");
    if(f==NULL)
        printf("erreur d'ouverture du fichier prod");
    else
    {
        while (!feof(f) && existe==0)
        {
            fscanf(f,"%d %s %f %d", &p.co, p.des, &p.pr, &p.qt);
            if(p.co==co_cons)
                existe=1;
        }
    }
	if(existe==0)
        printf("produit inexistant\n");
	else
        printf("voici les informations du produit recherché: code=%d designation =%s prix=%f quantité=%d",p.co,p.des,p.pr
        ,p.qt);

    fclose(f);

}
    return 0;
