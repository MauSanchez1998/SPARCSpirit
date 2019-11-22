#include <stdint.h>
#include <xc.h>
#include "USARTLIBRERIA.h"

int comandos(char comando[7]); //Declaración de función 
char msgwrong []="COMANDO INCORRECTO";
char msgeje []="COMANDO EJECUTANDOSE";
char msgcomp []="COMANDO EJECUTADO";
void Error(void); //Declaración de función
void Ejecutandose(void); //Declaración de función
void Completo(void); //Declaración de funcion
char reconocer_comando(void); //declaración de función
uint16_t nvalorx =0; //declaración de nuevo valor
uint16_t nvalory =0; //declaración de nuevo valor

void coordinateRefreshY (int newY);
void coordinateRefreshX (int newX);
uint16_t x=0;
uint16_t y=0;