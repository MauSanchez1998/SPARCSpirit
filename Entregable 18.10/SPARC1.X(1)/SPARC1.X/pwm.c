#include "pwm.h"
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "GPIO.h"

unsigned char ons=0;
uint8_t cnt=0; 


//PWM period=[(PR2)+1]*4*TOSC*TMR2
//1/250 Hz= (PR2+1)*4*(1/4MHz)*16
//PR2= 249

//PWM Duty Cycle =(CCPRxL:CCPxCON<5:4>)*TOSC*(TMR2)
//CCPRL=DC/TOSC*TMR2
//CPRL= (1/250 Hz)/(1/4Mhz)*16 = 1000

//1000 -> 100%
//500 -> 50% 

void pwm_init(void) {
    /*Asignación de valores para PWM con periodo de 4ms y 50% DC*/
    OSCCON=0x62;
    PR2 = 249; //Periodo PWM
    CCPR1L= (500>>2 & (0x3FF)); //6 bits para tu PWM
    CCPR2L= (500>>2 & (0x3FF));
    TRISCbits.RC1=0;
    TRISCbits.RC2=0;       
    T2CON = 0x03; //Prescaler 16 Timer 2 OFF
    CCP1CON = 0x0C; //Control (2LSB PWM y Modo PWM)
    CCP2CON=0x0C;
    TMR2=0; //Inicia en 0
    T2CONbits.TMR2ON =1; //Timer 2 on
}

/*One shot para contar subidas en el pwm*/
void contador_pulsosD(uint16_t pulsoD){ 
        if (PORTCbits.CCP1==1){ //Si el registro es 1
            if(ons==1){} //Checa si la bandera ons está prendida
            if(PORTCbits.CCP1==1){ //Si ons está apagada
                Enable_D = ON; //Habilita el driver
                cnt++; //Cuenta +1
                if(cnt==pulsoD){ //Si cuenta ya llegó a donde quieres
                    Enable_D = OFF; //Deshabilita el driver
                    cnt=0; //Resetea cuenta
                    return;
                }
                ons=1; //si la cuenta aún no llega, prende la bandera ons
            }
        }
        if (ons==1){ //si ons ya está en uno 
          if(PORTCbits.CCP1==0){
              ons=0; //resetea la bandera ons si ya no está en cero el registro
            }  
        }
}
    