/*
 * TWI_prog.c
 *
 * Created: 7/5/2024 3:30:36 PM
 *  Author: ahmed
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "TWI_private.h"
#include "TWI_reg.h"
#include "TWI_interface.h"



void TWI_voidMasterInit(u8 copy_u8address){
	
	/********* Prescaler Selection == 1 ******/
	
	CLR_BIT(TWSR_REG,0);
	CLR_BIT(TWSR_REG,1);
	
	/********* Bit Rate Selection FCPU=16MHZ && Prescaler == 1 *******/
	/********* FSCL = FCPU / (16+2(TWBR*4^TWPS)) ********/
	
	TWBR_REG = 12;
	
	/******** Checking If master has an Address ***/
	
	if(copy_u8address != 0){
		
		/******** Setting Master Address ****/
		TWAR_REG=copy_u8address<<1;
		
	}
	
	/********** Enable Acknowledge ***********/
	
	SET_BIT(TWCR_REG,6);
	
	/********** Enable TWI ********************/
	
	SET_BIT(TWCR_REG,2);
	 
	
	
	
	
	
	
	
}
void TWI_VoidSlaveInit(u8 copy_u8address){
	
	/******** Setting Slave Address ****/
	
	TWAR_REG=copy_u8address<<1;
	
	/********** Enable Acknowledge ***********/
	
	SET_BIT(TWCR_REG,6);
	
	/********** Enable TWI ********************/
	
	SET_BIT(TWCR_REG,2);
	
	
}
TWI_Err_satus TWI_SendStartCondition(void){
	
	TWI_Err_satus LOC_Err=NOErr;
	
	/******** Send Start Condition *********/
	
	SET_BIT(TWCR_REG,5);
	
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	SET_BIT(TWCR_REG,7);
	
	/******* Waiting for TWINT Flag to be set by hardware ******/
	/******* Indicating that TWI has finished its current job ******/
	while(GET_BIT(TWCR_REG,7)==0);
	
	/****** Checking for status regrister operation succes codes ******/
	
	if((TWSR_REG & 0xF8)!= START_ACK){
		
		LOC_Err=StartConditionErr;
	}
	else{
		
		// Do Nothing 
		
	}
	
	
	return LOC_Err ;
	
	
}
TWI_Err_satus TWI_SendRepeatedStart(void){
	
	TWI_Err_satus LOC_Err=NOErr;
	
	/******** Send Start Condition *********/
	
	SET_BIT(TWCR_REG,5);
	
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	SET_BIT(TWCR_REG,7);
	
	/******* Waiting for TWINT Flag to be set by hardware ******/
	/******* Indicating that TWI has finished its current job ******/
	while(GET_BIT(TWCR_REG,7)==0);
	
	/****** Checking for status regrister operation succes codes ******/
	
	if((TWSR_REG & 0xF8)!= REP_START){
		
		LOC_Err=RepeatedStartErr;
	}
	else{
		
		// Do Nothing
		
	}
	
	
	return LOC_Err ;
	
	
	
}
TWI_Err_satus TWI_sendSlaveAddressWithWrite(u8 copy_u8SlaveAddress){
	
	TWI_Err_satus LOC_Err=NOErr;
	
	/****** Load Slave Address With write operation in TWDR Register ****/
	
	TWDR_REG=copy_u8SlaveAddress<<1;
	
	/****** Clear TWDR BIT_0 To Write ****/
	
	CLR_BIT(TWDR_REG,0);
	
	/****** Clear TWI START Condition Bit ********/
	
	CLR_BIT(TWCR_REG,5);
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	SET_BIT(TWCR_REG,7);
	
	/******* Waiting for TWINT Flag to be set by hardware ******/
	/******* Indicating that TWI has finished its current job ******/
	while(GET_BIT(TWCR_REG,7)==0);
	
	/****** Checking for status regrister operation succes codes ******/
	
	if((TWSR_REG & 0xF8)!= SLAVE_ADD_AND_WR_ACK){
		
		LOC_Err=SlaveAddressWithWriteErr;
	}
	else{
		
		// Do Nothing
		
	}
	
	
	return LOC_Err ;
	 
	
	
	
	
	
}
TWI_Err_satus TWI_sendSlaveAddressWithRead(u8 copy_u8SlaveAddress){
	
	TWI_Err_satus LOC_Err=NOErr;
	
	/****** Load Slave Address With write operation in TWDR Register ****/
	
	TWDR_REG=copy_u8SlaveAddress<<1;
	
	/****** SET TWDR BIT_0 To Write ****/
	
	SET_BIT(TWDR_REG,0);
	
	/****** Clear TWI START Condition Bit ********/
	
	CLR_BIT(TWCR_REG,5);
	
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	
	SET_BIT(TWCR_REG,7);
	
	/******* Waiting for TWINT Flag to be set by hardware ******/
	/******* Indicating that TWI has finished its current job ******/
	
	while(GET_BIT(TWCR_REG,7)==0);
	
	/****** Checking for status regrister operation succes codes ******/
	
	if((TWSR_REG & 0xF8)!= SLAVE_ADD_AND_RR_ACK){
		
		LOC_Err=SlaveAddressWithReadErr;
	}
	else{
		
		// Do Nothing
		
	}
	
	
	return LOC_Err ;
	
	
	
	
	
}
TWI_Err_satus TWI_MasterSendData(u8 copy_u8data){
	
	TWI_Err_satus LOC_Err=NOErr;
	
	/****** Load Data in TWDR Register ****/
	
	TWDR_REG=copy_u8data;
	
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	
	SET_BIT(TWCR_REG,7);
	
	/******* Waiting for TWINT Flag to be set by hardware ******/
	/******* Indicating that TWI has finished its current job ******/
	
	while(GET_BIT(TWCR_REG,7)==0);
	
	/****** Checking for status regrister operation succes codes ******/
	
	if((TWSR_REG & 0xF8)!= MASTER_WR_BYTE_ACK){
		
		LOC_Err=MasterSendDataErr;
	}
	else{
		
		// Do Nothing
		
	}
	
	
	return LOC_Err ;
	
}
TWI_Err_satus TWI_MasterReceiveData(u8 *copy_u8data){
	
	TWI_Err_satus LOC_Err=NOErr;
	
	
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	
	SET_BIT(TWCR_REG,7);
	
	/******* Waiting for TWINT Flag to be set by hardware ******/
	/******* Indicating that TWI has finished its current job ******/
	
	while(GET_BIT(TWCR_REG,7)==0);
	
	/****** Checking for status regrister operation succes codes ******/
	
	if((TWSR_REG & 0xF8)!= MASTER_RD_BYTE_WITH_ACK){
		
		LOC_Err=MasterSendDataErr;
	}
	else{
		
		*copy_u8data=TWDR_REG;
		
	}
	
	return LOC_Err ;
	
}
void TWI_SendStopCondition(void){
	
	/***** Send Stop Condition **********/
	
	SET_BIT(TWCR_REG,4);
	
	
	
	
	/******** Clear TWI Interrupt Flag **********/
	/******** Writing Logic One *************/
	
	SET_BIT(TWCR_REG,7);
	
	
	
	
	
}