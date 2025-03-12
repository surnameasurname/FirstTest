#ifndef __RADIO_H
#define __RADIO_H

#include "sx126x_driver.h"


extern const double RadioLoRaSymbTime[3][8];
/*!
 * Radio driver supported modems
 */
typedef enum
{
    MODEM_FSK = 0,
    MODEM_LORA,
}RadioModems_t;

/*!
 * Radio driver internal state machine states definition
 */
typedef enum
{
    RF_IDLE = 0,   //!< The radio is idle
    RF_RX_RUNNING, //!< The radio is in reception state
    RF_TX_RUNNING, //!< The radio is in transmission state
    RF_CAD,        //!< The radio is doing channel activity detection
}RadioState_t;

void RadioIoDeInit(void);
void RadioRecoverIoInit(void);
void RadioInit(void);
RadioState_t RadioGetStatus( void );
void RadioSetModem( RadioModems_t modem );
void RadioSetTxPower(uint8_t power);
void RadioSetChannel( uint32_t freq );
uint8_t RadioIsChannelFree( RadioPacketTypes_t modem, uint32_t freq, int16_t rssiThresh, uint32_t maxCarrierSenseTime );
uint32_t RadioRandom( void );
void RadioSetRxConfig( RadioModems_t modem, uint32_t bandwidth,
                         uint32_t datarate, uint8_t coderate,
                         uint32_t bandwidthAfc, uint16_t preambleLen,
                         uint16_t symbTimeout, uint8_t fixLen,
                         uint8_t payloadLen,
                         uint8_t crcOn, uint8_t freqHopOn, uint8_t hopPeriod,
                         uint8_t iqInverted, uint8_t rxContinuous );
void RadioSetTxConfig( RadioModems_t modem, int8_t power, uint32_t fdev,
                        uint32_t bandwidth, uint32_t datarate,
                        uint8_t coderate, uint16_t preambleLen,
                        uint8_t fixLen, uint8_t crcOn, uint8_t freqHopOn,
                        uint8_t hopPeriod, uint8_t iqInverted, uint32_t timeout );
uint32_t RadioTimeOnAir( RadioModems_t modem, uint8_t pktLen );
void RadioSend( uint8_t *buffer, uint8_t size,uint32_t time_out );
void RadioGetBuffer( uint8_t *buffer, uint8_t *size,  uint8_t maxSize );
void RadioSleep( void );
void RadioStandby( void );
void RadioRx( uint32_t timeout );
void RadioRxBoosted( uint32_t timeout );
void RadioSetRxDutyCycle( uint32_t rxTime, uint32_t sleepTime );
void RadioStartCad( void );
void RadioSetCadParams( RadioLoRaCadSymbols_t cadSymbolNum, uint8_t cadDetPeak, uint8_t cadDetMin, RadioCadExitModes_t cadExitMode, uint32_t cadTimeout );
void RadioTx( uint32_t timeout );
void RadioSetTxContinuousWave( uint32_t freq, int8_t power, uint16_t time );
int8_t RadioRssi(void );
void RadioSetMaxPayloadLength( RadioModems_t modem, uint8_t max );
void RadioSetPublicNetwork( uint8_t enable );
uint16_t RadioGetIrqStatus(void);
void RadioGetPacketStatus( PacketStatus_t *pktStatus );
RadioError_t RadioGetDeviceErrors( void );
void RadioClearDeviceErrors( void );
void RadioClearIrqStatus( uint16_t irq );
void RadioOnDioIrq( void );
void RadioIrqProcess( void );
void RadioSetPreamble(uint16_t preamble_len);
uint32_t RadioTimeOnAirAndPreamble( RadioModems_t modem, uint8_t pktLen,uint16_t preLen );

extern SX126x_t SX126x;
extern uint16_t lora_preamble_len;


#endif
