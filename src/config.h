/**
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <sys/types.h>

/**
 * Struttura dati che contiene tutti i parametri di configurazione
 */
struct config {
    int k;  //numero di thread attivi come cassieri
    int c;  //numero di thread attivi come clienti all'interno del supermercato
    int e;  //quanto è grande il gruppo di clienti che entra nel supermercato.
    int t;  //massimo tempo per gli acquisti per un cliente. Deve essere > 10
    int p;  //massimo numero di prodotti che acquisterà un cliente. Deve essere > 0
    int s;  //ogni quanti millisecondi il cliente decide se spostarsi o meno
    int s1; //valore soglia per chiusura di una cassa
    int s2; //valore soglia per apertura di una cassa
};

typedef struct config Config;

/**
 * Legge dati di configurazione dal path passato per argomento e setta la struttura di configurazione specificata.
 *
 * @param filepath da quale file bisogna leggere la configurazione
 * @param config struttura di configurazione che viene settata con i parametri presenti nel file di configurazione
 * @return struttura con la configurazione contenuta nel file
 */
int loadConfig(char *filepath, Config *config);

/**
 * Ritorna 1 se la struttura di configurazione è valida, 0 altrimenti. Una struttura di configurazione è
 * definita valida se e soltanto se tutti i parametri non sono negativi o pari a zero e vale che t > MIN_T
 * ma anche la disuguaglianza 0 < E < C.
 *
 * @param config
 * @return
 */
int isValidConfig(Config *config);

/**
 * Stampa sulla console la struttura di configurazione.
 *
 * @param config la struttura di configurazione da stampare
 */
void printConfig(Config *config);

#endif //CONFIG_H