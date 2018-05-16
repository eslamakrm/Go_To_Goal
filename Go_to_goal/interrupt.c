
 #include "interrupt.h"

void interrupt_configuration()
{
CLEAR_BIT(DDRD,PIND2);//set as input
CLEAR_BIT(DDRD,PIND3);//set as input
     /*
	 falling edge INT1
	 */
	 SET_BIT(MCUCR,ISC11);
	 CLEAR_BIT(MCUCR,ISC10);
	 /*
	 falling edge INT1
	 */
	 SET_BIT(MCUCR,ISC01);
	 CLEAR_BIT(MCUCR,ISC00);
	 sei(); //enable global interrupt bit
	 SET_BIT(GICR,INT0);
	 SET_BIT(GICR,INT1);
	 CLEAR_BIT(GICR,INT2);
}
ISR(INT0_vect)
{
	++N_L_ticks;
}
ISR(INT1_vect)
{
	++N_R_ticks;
}
 