#include "Comandos.h"
#include <stdlib.h>
#include <string.h>

#include <xc.h>

/*La función imprime el mensaje de error por UART*/
void Error(){
    for(int i=0; i< strlen(msgwrong); i++){ //para imprimir todas las letras del mensaje
    USART_Tx(msgwrong[i]); //Imprime caracter por caracter
    } 

}

/*La función imprime el mensaje de ejecutandose por UART*/
void Ejecutandose(){
    for(int i=0; i < strlen(msgeje); i++){
    USART_Tx(msgeje[i]);
    } 
}

/*La función imprime el mensaje de completo por UART*/
void Completo(){
    for(int i=0; i < strlen(msgcomp); i++){
    USART_Tx(msgcomp[i]);
    } 
}

/*Función para saber cómo moverse en X de acuerdo al valor nuevo y anterior*/
void coordinateRefreshX(int newX){
    if(newX<x){ //Si el valor nuevo es menor al anterior
        Left(x-newX); //función de ir a la izquierda
    }
    if(newX>x){ //Si el valor nuevo es mayor al anterior
        Right(newX-x); //función de ir a la derecha
    }
    x=newX;  //Se asigna el nuevo valor al registro del anterior
}

/*Función para saber cómo moverse en Y de acuerdo al valor nuevo y anterior*/
void coordinateRefreshY(int newY){
    if(newY<y){ //si el nuevo valor es menor al anterior
    Down(y-newY); //función de ir hacia abajo
    }
    if(newY>y){ //si el nuevo valor es mayor al anterior
    Up(newY-y); //función de ir hacia arriba
    }
    y=newY; //Se asigna el nuevo valor al registro del anterior
}

/*Función que reconocer los comandos de entrada, 
 el arreglo "comando" será el que entre desde el UART*/
int comandos (char comando[7]){ 
    if(comando[0]=='C'){
        if (comando[1]>='0' && comando[1]>='3'){
            if (comando[2]>='0' && comando[2]<='9'){
                if (comando[3]>='0' && comando[3]<='9'){
                    if (comando[4]==','){
                        if (comando[5]>='0' && comando[5]<='3'){
                            if (comando[6]>='0' && comando[6]<='9'){
                                if (comando[7]>='0' && comando[7]<='9'){ /*ej: C024,234 (X=024 Y=234*/
                                    Ejecutandose();//Muestra mensaje de ejecutandose
                                    nvalorx= ((comando[1]-48)*100)+((comando[2]-48)*10)+(comando[3]-48); //Se asigna el nuevo valor de x
                                    nvalory= ((comando[5]-48)*100)+((comando[6]-48)*10)+(comando[7]-48); //Se asigna el nuevo valor de y
                                    coordinateRefreshX(nvalorx); //La función se ejecuta con el nuevo valor
                                    coordinateRefreshY(nvalory); //La función se ejecuta con el nuevo valor
                                }
                                else{
                                    Error(); //Muestra mensaje de error
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
    
    else if(comando[0]=='G'){
        if (comando[1]=='O'){
            if (comando[2]=='T'){
                if (comando[3]=='O'){
                    if (comando[4]=='H'){
                        if (comando[5]=='O'){
                            if (comando[6]=='M'){
                                if (comando[7]=='E'){ /*ej GOTOHOME*/
                                    Ejecutandose();//Mensaje de ejecutandose
                                    
                                }
                                else{
                                    Error(); //mensaje de error
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
    
    else if(comando[0]=='S'){
        if (comando[1]=='T'){
            if (comando[2]=='C'){
                if (comando[3]=='T'){
                    if (comando[4]=='O'){
                        if (comando[5]=='U'){
                            if (comando[6]=='C'){
                                if (comando[7]=='H'){ /*ej STCTOUCH*/
                                    Ejecutandose(); //mensaje de ejecutandose
                                    
                                }
                                else{
                                    Error();
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
    
    
    
    else if(comando[0]=='M'){
        if (comando[1]=='A'){
            if (comando[2]=='K'){
                if (comando[3]=='E'){
                    if (comando[4]=='A'){
                        if (comando[5]=='T'){
                            if (comando[6]=='A'){
                                if (comando[7]=='P'){ (/*ej MAKEATAP*/)
                                    Ejecutandose(); //Mensaje de ejecutandose
                                }
                                else{
                                    Error();
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
       
   
    else if(comando[0]=='M'){
        if (comando[1]=='A'){
            if (comando[2]=='K'){
                if (comando[3]=='E'){
                    if (comando[4]=='L'){
                        if (comando[5]=='I'){
                            if (comando[6]=='F'){
                                if (comando[7]=='T'){ /*ej MAKELIFT*/
                                    Ejecutandose(); //mensaje ejecutandose
                                    
                                }
                                else{
                                    Error();
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    } 
}

