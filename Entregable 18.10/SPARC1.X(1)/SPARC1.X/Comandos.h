#include <stdint.h>
#include <xc.h>
#include "USARTLIBRERIA.h"

int comandos(char comando[7]); //Declaraci�n de funci�n 
char msgwrong []="COMANDO INCORRECTO";
char msgeje []="COMANDO EJECUTANDOSE";
char msgcomp []="COMANDO EJECUTADO";
void Error(void); //Declaraci�n de funci�n
void Ejecutandose(void); //Declaraci�n de funci�n
void Completo(void); //Declaraci�n de funcion
char reconocer_comando(void); //declaraci�n de funci�n
uint16_t nvalorx =0; //declaraci�n de nuevo valor
uint16_t nvalory =0; //declaraci�n de nuevo valor

void coordinateRefreshY (int newY);
void coordinateRefreshX (int newX);
uint16_t x=0;
uint16_t y=0;