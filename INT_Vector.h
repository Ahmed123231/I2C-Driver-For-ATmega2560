#ifndef _INT_VECTOR_H_
#define _INT_VECTOR_H_

#define ISR(__vector_NUM) void __vector_NUM(void)__attribute__((signal));\
						  void __vector_NUM(void)
						  
						  
						  
#define _INT_0   			__vector_1
#define _INT_1   			__vector_2
#define _INT_2   			__vector_3
#define _TIMER2_COMP  		__vector_4
#define _TIMER2_OVF         __vector_5
#define _TIMER1_CAPT        __vector_6
#define _TIMER1_COMPA       __vector_7
#define _TIMER1_COMPB       __vector_8
#define _TIMER1_OVF         __vector_9
#define _TIMER0_COMP        __vector_10
#define _TIMER0_OVF         __vector_11
#define _STC                __vector_12
#define _RXC                __vector_13
#define _UDRE               __vector_14
#define _TXC                __vector_15    
#define _ADC        		__vector_16
#define _EE_RDY     		__vector_18
#define _ANA_COMP     		__vector_19
#define _TWI_T        		__vector_20
#define _SPM_RDY    		__vector_21



#endif 