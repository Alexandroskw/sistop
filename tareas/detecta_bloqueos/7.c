/*Sistemas Operativos
Objetivo: Detecci�n de bloqueos */

/*A pesar de que brind� una prorroga de entrega no pude hacer funcionar correctamente el programa,
sin embargo presento aqu� un intento, alguna vez escuch� durante un examen<<ustedes no se estresen
cualquier n�mero natural es mejor que cero, contesten lo que puedan>>, suena mal pero igual tomar�
la filosof�a. Tendr� que dedicarle m�s a la siguiente tarea.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo *APNODO;

    struct nodo{
            char recursoAsignado[20];
            char recursoSolicitado[20];
            APNODO sigte;
     };


void implista(APNODO lista);
/*Con esta funci�n creo nuevos proceso en forma de lista*/
APNODO nuevo(char recAsig[], char recSol[]);
/*La siguiente funci�n busca los bloqueos. Sus limitantes son:
   1. Todos los recursos deben ser asignados pero no es necesario que un proceso
   requiera recursos adicionales. 
   2. No se verifica duplicidad de asignaciones
   3. Solo verifica situaciones en que se presenta un ciclo
   
La funci�n pregunta si requiere m�s recursos para terminar, como se
supone que todos los recursos han sido asignados si el n�mero de procesos que esperan
recursos para terminar, es igual al n�mero total de procesos activos existir� un bloqueo.*/
void buscarBloqueo(APNODO proceso, int numDeProcesos);



int main(void)
{
   char respuesta='s',escape,asignado[20],solicitado[20];
   int i=0, numDeProcesos=0;
   struct nodo *p,*t,*s,*temporal;
/****************************************/ /****************************************/
                /*Crear primer proceso*/
/***************************************/ /****************************************/
   
   while(respuesta== 's')
   {
      printf("\nIngrese la lista de recursos asignados\n\n");
      i=0;
      while (escape!='n')
      {
         
         printf("\n\nIngrese recurso %d ",i+1);
         asignado[i]=getch();
         printf("\n\nRecurso asignado: %c\n",asignado[i]);
         i++;
         printf("\n\nDesea asignar otro recurso? s/n \n");
         escape= getch();
         if (escape=='n')asignado[i]='\0';
      }
      escape= 's';
      while(escape== 's')
      {
         printf("\n\nDesea ingresar solicitud? s/n \n");
         escape= getch();
         if(escape=='n')
         {
            asignado[i]='\0';break;
         }
         i=0;
         printf("\n\nIngrese la lista de recursos solicitados\n\n");
         while (escape!='n')
         {
            printf("\n\nIngrese el recurso solicitado %d \n",i+1);
            solicitado[i]=getch();
            i++;
            printf("\n\nDesea solicitar otro recurso? s/n \n");
            escape= getch();
            
         }
         
         i=0;
      }
       /*en P es una apuntador al primer proceso*/
       p=nuevo(asignado,solicitado);
       t=p;/*Crear una copia del primer proceso para pasar la direcci�n al siguiente */
       printf("\n\n\tDesea crear otro proceso s/n \n\n\t");
       respuesta=getch();
       numDeProcesos++;
       if(respuesta=='s')break;
   }
    /****************************************/
    //Aqu� se crean los siguientes procesos de ser el caso.
    /***************************************/
   
    while(respuesta== 's')
   {
      printf("\nIngrese la lista de recursos asignados\n\n");
      escape='o';
      i=0;
      while (escape!='n')
      {
         
         printf("\n\nIngrese recurso %d ",i+1);
         asignado[i]=getch();
         printf("\n\nRecurso asignado: %c\n",asignado[i]);
         i++;
         printf("\n\nDesea asignar otro recurso? s/n \n");
         escape= getch();
         if (escape=='n')asignado[i]='\0';
      }
      escape= 's';
      while(escape== 's')
      {
         printf("\n\nDesea ingresar solicitud? s/n \n");
         escape= getch();
         if(escape=='n')
         {
            asignado[i]='\0';break;
         }
         i=0;
         printf("\n\nIngrese la lista de recursos solicitados\n\n");
         while (escape!='n')
         {
            printf("\n\nIngrese el recurso solicitado %d \n",i+1);
            solicitado[i]=getch();
            i++;
            printf("\n\nDesea solicitar otro recurso? s/n \n");
            escape= getch();
         }
         
         i=0;
      }
/********************//********************//********************//********************/
//En esta parte del c�digo se ligan los procesos <<s>> recibir� el proceso de recien creaci�n
// <<t>> tomar� la direcci�n del proceso en su campo <<sigte>>, as� apunta hacia el sig proceso
//cuando <<t>> se transforma en <<s>>, <<s>> en su campo sigte apuntara al s+1.
/********************//********************//********************//********************/
       s=nuevo(asignado,solicitado);
       numDeProcesos++;
       t->sigte=s;
       t=s;
       printf("\n\n\tDesea crear otro proceso s/n \n\n\t");
       respuesta=getch();
       
       
   }
    printf("\n\nProcesos creados.\n\n");
    implista(p);
    printf("\n\tNumero de proceso crados%d",numDeProcesos);

    getch();
    return 0;
    
}
/******************************************************/
/*Definici�n de funciones*/

void implista(APNODO lista)
{
     int i=0;
     for(;lista->sigte!=NULL; lista=lista->sigte)
     {   
         for (lista->recursoAsignado[0];lista->recursoAsignado[i]!='\0';i++)
         {
            printf("\nRecurso [%d]: \n %c\n\n",i,lista->recursoAsignado[i]);
         }
     }
     
     
}

APNODO nuevo(char recAsig[],char recSol[])
{
       APNODO aprnvo;
       int i=0;
       aprnvo=(APNODO)malloc(sizeof(struct nodo));
       while(recAsig[i]!='\0')
       {
         aprnvo->recursoAsignado[i]=recAsig[i];
         
         i++;
      }
      i=0;
      while(recSol[i]!='\0')
       {
         aprnvo->recursoSolicitado[i]=recSol[i];
         i++;
      }
       aprnvo->sigte=NULL;
       return aprnvo;
}

void buscarBloqueo(APNODO proceso, int numDeProcesos)
{
    int bloqueo=0;
    for(;proceso->sigte!=NULL; proceso=proceso->sigte)
     {   
         if(proceso->recursoSolicitado[0]!='\0')
         {
            bloqueo++;   
         }
     }
     if (bloqueo==numDeProcesos)printf("\n\n\tExiste bloqueo");
}


/* Evaluaci�n */

/* Haces un buen uso de estructuras, al usar una lista ligada, puedes
   tener una cantidad arbitraria de procesos en el sistema - �Bien!
   Podr�as haber (si fuera para el empleo en una situaci�n real)
   manejado tambi�n listas ligadas para los recursos, dado que podr�an
   ser m�s de 20 (y para no ocupar de fijo 20+20 caracteres que
   podr�an ahorrarse), pero es v�lido como lo presentas.

   No me queda del todo clara la l�gica de tu funci�n
   "buscarBloqueo(APNODO, int)". Si bien al crear un nuevo proceso (
   APNODO nuevo(char, char) ) s� registras recursos asignados y
   solicitados, en esta funci�n s�lo eval�as los solicitados. Recuerda
   que un bloqueo se produce cuando tienes un ciclo inescapable, en el
   que hay recursos asignados a un proceso que est�n siendo
   solicitados por otro, y recursos asignados al otro que est�n siendo
   solicitados por el primero (o un ciclo m�s ampliado). Un ciclo de
   recursos solicitados *puede llevar a* un bloqueo, pero no lo
   implica necesariamente.
*/ 
