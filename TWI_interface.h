/*
 * TWI_interface.h
 *
 * Created: 7/5/2024 3:30:20 PM
 *  Author: ahmed
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum{
	NOErr ,
	StartConditionErr ,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterSendDataErr,
	MasterReciveDataErr,
	
}TWI_Err_satus;


void TWI_voidMasterInit(u8 copy_u8address);
void TWI_VoidSlaveInit(u8 copy_u8address);
TWI_Err_satus TWI_SendStartCondition(void);
TWI_Err_satus TWI_SendRepeatedStart(void);
TWI_Err_satus TWI_sendSlaveAddressWithWrite(u8 copy_u8SlaveAddress);
TWI_Err_satus TWI_sendSlaveAddressWithRead(u8 copy_u8SlaveAddress);
TWI_Err_satus TWI_MasterSendData(u8 copy_u8data);
TWI_Err_satus TWI_MasterReceiveData(u8 *copy_u8data);
void TWI_SendStopCondition(void);

#endif /* TWI_INTERFACE_H_ */