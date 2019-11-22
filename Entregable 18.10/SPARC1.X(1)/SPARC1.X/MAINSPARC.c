/*
 * File:   MAINSPARC.c
 * Author: mausa
 *
 * Created on 22 de noviembre de 2019, 10:30 AM
 */

#include <pic18f4550.h>
#include <xc.h>
#include "Comandos.h"
#include "GPIO.h"
#include "config.h"
#include "pwm.h"
#include "USARTLIBRERIA.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



void main(void) {
    OSCCON= 0x62;
    USART_Init(9600);
    
    while(1){
        RCSTAbits.CREN=1;
        for(uint8_t contador=0; contador<=8; contador++){
            instruccion[i]=USART_Rx();
        }
        
        
    }
    
    return;
}
