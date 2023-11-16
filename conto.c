/*Esercizio n°1
conta.c
Scrivi il codice
sorgente di un programma che permette al processo padre di generare un processo
figlio.
Sia il processo padre
e sia il processo figlio visualizzano ciascuno il proprio PID e il PID del
proprio parente.
Padre conta da 0 a
19.
Figlio conta da 0 a
9.
Manda in esecuzione
più volte e osserva il comportamento del programma in esecuzione.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int padre;
int padre_conta;
int main()
{
    padre = fork();
    if(padre < 0)
    {
        printf("ERRORE: il processo figlio non è stato creato \n");
        exit(1);
    }
    if(padre != 0)
    {
        printf("sono il padre: il mio PID=%d \n", getpid());
        printf("mio figlio ha PID=%d \n",padre);
        printf("questi sono i numeri che devo stampare \n\n");
        for(padre_conta = 0; padre_conta < 20; padre_conta++)
        {
            printf("%d\n",padre_conta);
        }
        printf("\n \n");
    }
    else 
    {
        printf("sono il figlio: il mio PID=%d \n", getpid());
        printf("mio padre ha PID=%d \n",getppid());//getppid ritorna il PID del padre
        printf("questi sono i numeri che devo stampare \n\n");
        for(padre_conta = 0; padre_conta < 10; padre_conta++)
        {
            printf("%d\n",padre_conta);
        }
         printf("\n \n");
    }

    return 0;
}