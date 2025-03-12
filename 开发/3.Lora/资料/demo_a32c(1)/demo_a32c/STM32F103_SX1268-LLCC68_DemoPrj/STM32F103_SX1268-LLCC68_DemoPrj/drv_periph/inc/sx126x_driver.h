#ifndef __SX126X_DRIVER_H
#define __SX126X_DRIVER_H

#include "sys.h"
#include "sx126x_reg.h"
#include "drv_spi.h"
//#include <math.h>

/*!
 * \brief Provides the frequency of the chip running on the radio and the frequency step
 *
 * \remark These defines are used for computing the frequency divider to set the RF frequency
 */
//#define XTAL_FREQ                                   ( double )32000000
//#define FREQ_DIV                                    ( double )pow( 2.0, 25.0 )
//#define FREQ_STEP                                   ( double )( XTAL_FREQ / FREQ_DIV )
#define FREQ_STEP                                   ( double )( 0.95367431640625 )
	 
#define FALSE   0
#define TRUE    1

#define RADIO_SX126X                                2 //1:SX1261  2:SX1262          
#define SX1261                                      1
#define SX1262                                      2
/*!
 * Board MCU pins definitions
 */
#ifdef USE_TCXO
    #define RADIO_TCXO_SETUP_TIME                       5 // [ms]
#else
    #define RADIO_TCXO_SETUP_TIME                       0 // No Used
#endif
     
#define RADIO_NSS_GPIO_PORT			                GPIOA
#define RADIO_NSS_GPIO_PIN			                GPIO_Pin_4

#define radio_nss_low()                             PAout(4) = 0
#define radio_nss_high()                            PAout(4) = 1

    NRST        PA3     --复位			PB10
    BUSY        PA2     --忙				PB11
    TXEN        PA1     --发送使能		PB12
    RXEN        PA0     --接收使能		PB13



//#define RADIO_NRESET_PORT                           GPIOA
//#define RADIO_NRESET_PIN                            GPIO_Pin_3    
#define RADIO_NRESET_PORT                           GPIOB
#define RADIO_NRESET_PIN                            GPIO_Pin_10  

//#define RADIO_BUSY_PORT                             GPIOA
//#define RADIO_BUSY_PIN                              GPIO_Pin_2
#define RADIO_BUSY_PORT                             GPIOB
#define RADIO_BUSY_PIN                              GPIO_Pin_11

#define RADIO_DIO1_PORT                             GPIOC
#define RADIO_DIO1_PIN                              GPIO_Pin_0

#define RADIO_DIO1_EXTI_PORT						EXTI_PORT_GPIOA
#define RADIO_DIO1_ITC								ITC_IRQ_PORTA	 

#define RADIO_SWITCH_TX_PORT                    	GPIOA
#define RADIO_SWITCH_TX_PIN                     	GPIO_Pin_1

#define RADIO_SWITCH_RX_PORT                        GPIOA
#define RADIO_SWITCH_RX_PIN                         GPIO_Pin_0

#define radio_rx_on()                               PAout(0) = 1
#define radio_rx_off()                              PAout(0) = 0

#ifndef USE_DIO2
	#define radio_tx_on()                           PAout(1) = 1
	#define radio_tx_off()                          PAout(1) = 0
#else
	#define radio_tx_on()                           	
	#define radio_tx_off()                          	
#endif          

void SX126xIoDeInit( void );  
void SX126xRecoverIoInit(void);
void SX126xReset( void ); //至少50us，典型值100us
void SX126xWakeup( void );
void SX126xWriteRegisters( uint16_t address, uint8_t *buffer, uint16_t size );
void SX126xWriteRegister( uint16_t address, uint8_t value );
void SX126xReadRegisters( uint16_t address, uint8_t *buffer, uint16_t size );
uint8_t SX126xReadRegister( uint16_t address );
void SX126xWriteBuffer( uint8_t offset, uint8_t *buffer, uint8_t size );
void SX126xReadBuffer( uint8_t offset, uint8_t *buffer, uint8_t size );
uint8_t SX126xGetPaSelect(void);
void SX126xInit( void );
RadioOperatingModes_t SX126xGetOperatingMode( void );
void SX126xCheckDeviceReady( void );
uint8_t SX126xGetPayload( uint8_t *buffer, uint8_t *size,  uint8_t maxSize );
void SX126xSendPayload( uint8_t *payload, uint8_t size, uint32_t timeout );
uint8_t SX126xSetSyncWord( uint8_t *syncWord );
void SX126xSetCrcSeed( uint16_t seed );
void SX126xSetCrcPolynomial( uint16_t polynomial );
void SX126xSetWhiteningSeed( uint16_t seed );
uint32_t SX126xGetRandom( void );
void SX126xSetSleep( SleepParams_t sleepConfig ); 
void SX126xSetStandby( RadioStandbyModes_t standbyConfig );
void SX126xSetFs( void );
void SX126xSetTx( uint32_t timeout );
void SX126xSetRx( uint32_t timeout );
void SX126xSetRxBoosted( uint32_t timeout );
void SX126xSetRxDutyCycle( uint32_t rxTime, uint32_t sleepTime );
void SX126xSetCad( void );
void SX126xSetTxContinuousWave( void );
void SX126xSetTxInfinitePreamble( void );
void SX126xSetStopRxTimerOnPreambleDetect( uint8_t enable );
void SX126xSetLoRaSymbNumTimeout( uint8_t SymbNum );
void SX126xSetRegulatorMode( RadioRegulatorMode_t mode );
void SX126xCalibrate( CalibrationParams_t calibParam );
void SX126xCalibrateImage( uint32_t freq );
void SX126xSetPaConfig( uint8_t paDutyCycle, uint8_t hpMax, uint8_t deviceSel, uint8_t paLut );
void SX126xSetRxTxFallbackMode( uint8_t fallbackMode );
void SX126xSetDioIrqParams( uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask, uint16_t dio3Mask );
uint16_t SX126xGetIrqStatus( void );
void SX126xSetDio2AsRfSwitchCtrl( uint8_t enable );
void SX126xSetDio3AsTcxoCtrl( RadioTcxoCtrlVoltage_t tcxoVoltage, uint32_t timeout );
void SX126xSetRfFrequency( uint32_t frequency );
void SX126xSetPacketType( RadioPacketTypes_t packetType );
RadioPacketTypes_t SX126xGetPacketType( void );
void SX126xSetTxParams( int8_t power, RadioRampTimes_t rampTime );
void SX126xSetModulationParams( ModulationParams_t *modulationParams );
void SX126xSetPacketParams( PacketParams_t *packetParams );
void SX126xSetCadParams( RadioLoRaCadSymbols_t cadSymbolNum, uint8_t cadDetPeak, uint8_t cadDetMin, RadioCadExitModes_t cadExitMode, uint32_t cadTimeout );
void SX126xSetBufferBaseAddress( uint8_t txBaseAddress, uint8_t rxBaseAddress );
RadioStatus_t SX126xGetStatus( void );
int8_t SX126xGetRssiInst( void );
void SX126xGetRxBufferStatus( uint8_t *payloadLength, uint8_t *rxStartBufferPointer );
void SX126xGetPacketStatus( PacketStatus_t *pktStatus );
RadioError_t SX126xGetDeviceErrors( void );
void SX126xClearDeviceErrors( void );
void SX126xClearIrqStatus( uint16_t irq );

#endif
