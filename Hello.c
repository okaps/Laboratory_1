//# Laboratory_1 
//1st practice 
//Pondre un poco de codigo por aqui, aun faltan los pragmas para el oscilador. include

int main(void){ 
	while(1){}; 
}

void init_port(void){ 
	TRISAbits.TRISA0=0; 	//A0 As Output 
}

void init_Oscillator (void){ 
PLLFBD=63; 			//PLL config 
CLKDIVbits.PLLPOST=0; 		//PLL config 
CLKDIVbits.PLLPRE=1; 		//PLL config

__builtin_write_OSCCONH(0x01);
__builtin_write_OSCCONL(OSCCON | 0x01);

while (OSCCONbits.COSC!= 0b001);

while (OSCCONbits.LOCK!= 1);
}

void init_Timer2 (void){ 
T2CONbits.TON=0; 	//Stop Timer 
T2CONbits.T32=0; 	//Select 16-bit Timer 
T2CONbits.TGATE=0; 	//Acumulation 
T2CONbits.TCKPS=0b00; 	//Prescaler 1:1 
T2CONbits.TCS=0; 	//Internal clock (Fosc/2) 
TMR2=0x00; 		//Clear Timer Register 
PR2=39921; 		//Period 1KHz

IFS0bits.T2IF=0;                //Clear Interrupt Flag
IEC0bits.T2IE=1;                //Enable Interrupt
T2CONbits.TON=1;                //Start Timer 
}

void attribute((interrupt, no_auto_psv)) _T2Interrupt(void){ LATAbits.LATA0=LATAbits.LATA0; //Blink IFS0bits.T2IF = 0; //Clear Timer1 interrupt flag }