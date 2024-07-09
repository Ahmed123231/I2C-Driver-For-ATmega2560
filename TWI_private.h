/*
 * TWI_private.h
 *
 * Created: 7/6/2024 8:45:38 AM
 *  Author: ahmed
 */ 


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_



/*** TWI STATUS Register Codes ***/

#define START_ACK                             0x08   /* start has been send */
#define REP_START                             0x10   /* repeated start*/
#define SLAVE_ADD_AND_WR_ACK                  0x18   /* MASTER transmit (slave address + write request  */
#define SLAVE_ADD_AND_RR_ACK                  0x40   /* MASTER transmit (slave address + write request  */
#define MASTER_WR_BYTE_ACK                    0x28   /* MASTER transmit Data acknowledge  */
#define MASTER_RD_BYTE_WITH_ACK               0x50   /* MASTER  receive data with acknowledge  */
#define MASTER_RD_BYTE_WITH_NACK              0x58   /* MASTER  receive data with no acknowledge  */
#define SLAVE_ADD_RCVD_RD_REQ                 0xA8   /* MEANS that slave address is received with Read request  */
#define SLAVE_ADD_RCVD_WD_REQ                 0x60   /* MEANS that slave address is received with Write request  */
#define SLAVE_DATA_RECEIVED                   0x80   /* MEANS that data byte is received */
#define SLAVE_BYTE_TRANSMITTIED               0xB8   /* MEANS that data byte  are transmitted  */



#endif /* TWI_PRIVATE_H_ */