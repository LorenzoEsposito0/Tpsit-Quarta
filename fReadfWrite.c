#include <stdio.h>
#include <stdlib.h>
#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;//creo due puntatori di tipo FILE
    int n;//dichiaro una variabile intera
    unsigned char buffer[BUFFER_DIM];//dichiaro un'array di byte buffer con la dimensione di BUFFER
    if(argc!=3)//se gli argomenti passati sono diversi da 3 darà errore
    {
        printf("inserire correttamente il numero di parametri");//visualizza a video il seguente messaggio
        exit(1);//termina il programma con un numero in uscita 
    }
    origine = fopen(argv[1],"r");//assegno al puntatore origine l'apertura del file passato come primo argomento in modalità read 
    if(origine == NULL)//se l'apertura del file darà errore quindi == NULL
    {
        printf("errore apertura del file origine");//stampa a video il seguente messaggio
        exit(1);//termina il programma con un numero in uscita 
    }
    destinazione = fopen(argv[2],"w");//come secondo argomento gli passo il file in modalità di scrittura e lo apre
    if(destinazione == NULL)//se l'apertura del file darà errore quindi == NULL
    {
        printf("errore apertura del file destinazione");//stampa a video il seguente messaggio
        exit(1);//termina il programma con un numero in uscita 
    }
    while(!feof(origine))//itera finchè non ho finito la fine del file di origine
    {
        n = fread(buffer,1,BUFFER_DIM,origine);//
        if(n>0)
        {
            fwrite(buffer,1,n,destinazione);
        }
    }

    fclose(origine);
    fclose(destinazione);


    return 0;
}
