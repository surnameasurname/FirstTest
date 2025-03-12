#include "sx126x_driver.h"
#include "utilities.h"
#include "delay.h"
static RadioOperatingModes_t OperatingMode;

static RadioPacketTypes_t PacketType;

volatile uint32_t FrequencyError = 0;

static uint8_t ImageCalibrated = FALSE;



void radio_rx_on(void){
	gpio_bit_set(GPIOB,GPIO_PIN_13);
}
void radio_rx_off(void){
	gpio_bit_reset(GPIOB,GPIO_PIN_13);
}
	
void radio_tx_on(void)
{
	gpio_bit_set(GPIOB,GPIO_PIN_12);
}
void radio_tx_off(void)
{
	gpio_bit_reset(GPIOB,GPIO_PIN_12);
}

void NRST_on(void){
	gpio_bit_set(GPIOB,GPIO_PIN_10);
}
void NRST_off(void){
	gpio_bit_reset(GPIOB,GPIO_PIN_10);
}

void SX126xIoInit( void )
{

    //NSS
		/* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_15);
		//NRST  TXEN RXEN
		/* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOB);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_13);
		//BUSY
		/* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOB);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ,GPIO_PIN_11);
		
		//gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ,GPIO_PIN_11);
		
//		gpio_bit_set(GPIOA, GPIO_PIN_15);
//		gpio_bit_set(GPIOB, GPIO_PIN_10);
//		gpio_bit_set(GPIOB, GPIO_PIN_12);
//		gpio_bit_set(GPIOB, GPIO_PIN_13);
		
    SPI_GPIO_Init();
		
		
		
}

void SX126xIoIrqInit(void )
{  
//	EXTI_SetExtIntSensitivity(RADIO_DIO1_EXTI_PORT,EXTI_SENSITIVITY_RISE_FALL);   
//	ITC_SetSoftwarePriority(RADIO_DIO1_ITC, ITC_PRIORITYLEVEL_1);
}

void radio_nss_low(void)
{
	gpio_bit_reset(GPIOA,GPIO_PIN_15);
}
void radio_nss_high(void)
{
	gpio_bit_set(GPIOA,GPIO_PIN_15);
}

void SX126xIoDeInit( void )  
{
//	GPIO_InitTypeDef GPIO_InitStructure;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Pin = RADIO_DIO1_PIN;
//    GPIO_Init( RADIO_DIO1_PORT , &GPIO_InitStructure );
    
	radio_tx_off();
	radio_rx_off();
}

void SX126xRecoverIoInit(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;    
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
//    GPIO_InitStructure.GPIO_Pin = RADIO_DIO1_PIN;
//    GPIO_Init( RADIO_DIO1_PORT , &GPIO_InitStructure );    

	SX126xIoIrqInit();
}

void SX126xReset( void ) //至少50us，典型值100us
{
    delay_1ms( 10 );
    NRST_off ();
    delay_1ms( 20 );
    NRST_on ();
    delay_1ms( 10 );
}
FlagStatus  BUSY_READ(void)
{
	return gpio_input_bit_get(GPIOB,GPIO_PIN_11);
}


void SX126xWaitOnBusy( void ) //高电平表示忙
{
    while( BUSY_READ() != 0 );
}

void SX126xWakeup( void )
{
//    disableInterrupts( );
    radio_nss_low();

    drv_spi_read_write_byte(RADIO_GET_STATUS );
    drv_spi_read_write_byte( 0x00 );
		
    radio_nss_high();

    // Wait for chip to be ready.
     SX126xWaitOnBusy( );
    
//    enableInterrupts( );
}

//Once sending the command SetSleep(...), the device will become unresponsive for around 500 us
void SX126xWriteCommand( RadioCommands_t command, uint8_t *buffer, uint16_t size )
{
    SX126xCheckDeviceReady( );
    radio_nss_low();

    drv_spi_read_write_byte(( uint8_t )command );

    for( uint16_t i = 0; i < size; i++ )
    {
        drv_spi_read_write_byte( buffer[i] );
    }

    radio_nss_high();

    if( command != RADIO_SET_SLEEP )
    {
        SX126xWaitOnBusy( );
    }
}

void SX126xReadCommand( RadioCommands_t command, uint8_t *buffer, uint16_t size )
{
    SX126xCheckDeviceReady( );
    
    radio_nss_low();

    drv_spi_read_write_byte( ( uint8_t )command );
    drv_spi_read_write_byte( 0x00 ); 
    for( uint16_t i = 0; i < size; i++ )
    {
        buffer[i] = drv_spi_read_write_byte(0);
    }

    radio_nss_high();

    SX126xWaitOnBusy( );
}

void SX126xWriteRegisters( uint16_t address, uint8_t *buffer, uint16_t size )
{
    SX126xCheckDeviceReady( );

    radio_nss_low();
    
    drv_spi_read_write_byte(RADIO_WRITE_REGISTER );
    drv_spi_read_write_byte(( address & 0xFF00 ) >> 8 );
    drv_spi_read_write_byte(address & 0x00FF );
    
    for( uint16_t i = 0; i < size; i++ )
    {
        drv_spi_read_write_byte( buffer[i] );
    }

    radio_nss_high();

    SX126xWaitOnBusy( );
}

void SX126xWriteRegister( uint16_t address, uint8_t value )
{
    SX126xWriteRegisters( address, &value, 1 );
}

void SX126xReadRegisters( uint16_t address, uint8_t *buffer, uint16_t size )
{
    SX126xCheckDeviceReady( );

    radio_nss_low();

    drv_spi_read_write_byte(RADIO_READ_REGISTER );
    drv_spi_read_write_byte(( address & 0xFF00 ) >> 8 );
    drv_spi_read_write_byte(address & 0x00FF );
    drv_spi_read_write_byte(0 );
    for( uint16_t i = 0; i < size; i++ )
    {
        buffer[i] = drv_spi_read_write_byte(  0 );
    }
    radio_nss_high();

    SX126xWaitOnBusy( );
}

uint8_t SX126xReadRegister( uint16_t address )
{
    uint8_t data;
    SX126xReadRegisters( address, &data, 1 );
    return data;
}

void SX126xWriteBuffer( uint8_t offset, uint8_t *buffer, uint8_t size )
{
    SX126xCheckDeviceReady( );

    radio_nss_low();

    drv_spi_read_write_byte(RADIO_WRITE_BUFFER );
    drv_spi_read_write_byte(offset );
    for( uint16_t i = 0; i < size; i++ )
    {
        drv_spi_read_write_byte( buffer[i] );
    }
    radio_nss_high();

    SX126xWaitOnBusy( );
}

void SX126xReadBuffer( uint8_t offset, uint8_t *buffer, uint8_t size )
{
    SX126xCheckDeviceReady( );

    radio_nss_low();

    drv_spi_read_write_byte( RADIO_READ_BUFFER );
    drv_spi_read_write_byte( offset );
    drv_spi_read_write_byte( 0 );
    for( uint16_t i = 0; i < size; i++ )
    {
        buffer[i] = drv_spi_read_write_byte(  0 );
    }
    radio_nss_high();

    SX126xWaitOnBusy( );
}

uint8_t SX126xGetPaSelect(void)
{
    if( RADIO_SX126X == 1 )
    {
        return SX1261;
    }
    else if(RADIO_SX126X == 2)
    {
        return SX1262;
    }
    else //0表示不是1262也不是1261
    {
        return 2;
    }
}

   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
void SX126xInit( void )
{
    SX126xIoInit();
    SX126xReset( );
    SX126xIoIrqInit();

    SX126xWakeup( );
    SX126xSetStandby( STDBY_RC );
#ifdef USE_TCXO 
    CalibrationParams_t calibParam;
    
    SX126xSetDio3AsTcxoCtrl( TCXO_CTRL_1_7V, RADIO_TCXO_SETUP_TIME << 6 ); // convert from ms to SX126x time base
    calibParam.Value = 0x7f;
    SX126xCalibrate( calibParam );
#endif

#ifdef USE_DIO2 //
    SX126xSetDio2AsRfSwitchCtrl( TRUE );
#endif
}

RadioOperatingModes_t SX126xGetOperatingMode( void )
{
    return OperatingMode;
}


void SX126xCheckDeviceReady( void )
{
    if( ( SX126xGetOperatingMode( ) == MODE_SLEEP ) || ( SX126xGetOperatingMode( ) == MODE_RX_DC ) )
    {
        SX126xWakeup( );
        // Switch is turned off when device is in sleep mode and turned on is all other modes
      //  SX126xAntSwOn( );
    }
    SX126xWaitOnBusy( );
}

void SX126xSetPayload( uint8_t *payload, uint8_t size )
{
    SX126xWriteBuffer( 0x00, payload, size );
}

uint8_t SX126xGetPayload( uint8_t *buffer, uint8_t *size,  uint8_t maxSize )
{
    uint8_t offset = 0;

    SX126xGetRxBufferStatus( size, &offset );
    if( *size > maxSize )
    {
        return 1;
    }
    SX126xReadBuffer( offset, buffer, *size );
    return 0;
}

void SX126xSendPayload( uint8_t *payload, uint8_t size, uint32_t timeout )
{
    SX126xSetPayload( payload, size );
    SX126xSetTx( timeout );
}
 
//FSK MODE
uint8_t SX126xSetSyncWord( uint8_t *syncWord )
{
    SX126xWriteRegisters( REG_LR_SYNCWORDBASEADDRESS, syncWord, 8 );
    return 0;
}

//FSK MODE  
void SX126xSetCrcSeed( uint16_t seed )
{
    uint8_t buf[2];

    buf[0] = ( uint8_t )( ( seed >> 8 ) & 0xFF );
    buf[1] = ( uint8_t )( seed & 0xFF );

    switch( SX126xGetPacketType( ) )
    {
        case PACKET_TYPE_GFSK:
            SX126xWriteRegisters( REG_LR_CRCSEEDBASEADDR, buf, 2 );
            break;

        default:
            break;
    }
}

//FSK MODE 
void SX126xSetCrcPolynomial( uint16_t polynomial )
{
    uint8_t buf[2];

    buf[0] = ( uint8_t )( ( polynomial >> 8 ) & 0xFF );
    buf[1] = ( uint8_t )( polynomial & 0xFF );

    switch( SX126xGetPacketType( ) )
    {
        case PACKET_TYPE_GFSK:
            SX126xWriteRegisters( REG_LR_CRCPOLYBASEADDR, buf, 2 );
            break;

        default:
            break;
    }
}

//FSK MODE 
void SX126xSetWhiteningSeed( uint16_t seed )
{
    uint8_t regValue = 0;
    
    switch( SX126xGetPacketType( ) )
    {
        case PACKET_TYPE_GFSK:
            regValue = SX126xReadRegister( REG_LR_WHITSEEDBASEADDR_MSB ) & 0xFE;
            regValue = ( ( seed >> 8 ) & 0x01 ) | regValue;
            SX126xWriteRegister( REG_LR_WHITSEEDBASEADDR_MSB, regValue ); // only 1 bit.
            SX126xWriteRegister( REG_LR_WHITSEEDBASEADDR_LSB, ( uint8_t )seed );
            break;

        default:
            break;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
uint32_t SX126xGetRandom( void )
{
    uint8_t buf[] = { 0, 0, 0, 0 };

    // Set radio in continuous reception
    SX126xSetRx( 0 );
  
    delay_1ms( 1 );

    SX126xReadRegisters( RANDOM_NUMBER_GENERATORBASEADDR, buf, 4 );

    SX126xSetStandby( STDBY_RC );

    return ( (uint32_t)buf[0] << 24 ) | ( (uint32_t)buf[1] << 16 ) | ( (uint32_t)buf[2] << 8 ) | buf[3];
}

void SX126xSetSleep( SleepParams_t sleepConfig ) 
{	
    radio_rx_off();
    radio_tx_off();
    
    SX126xWriteCommand( RADIO_SET_SLEEP, &sleepConfig.Value, 1 );
    OperatingMode = MODE_SLEEP;
}

void SX126xSetStandby( RadioStandbyModes_t standbyConfig )
{
    SX126xWriteCommand( RADIO_SET_STANDBY, ( uint8_t* )&standbyConfig, 1 );
    if( standbyConfig == STDBY_RC )
    {
        OperatingMode = MODE_STDBY_RC;
    }
    else
    {
        OperatingMode = MODE_STDBY_XOSC;
    }
}

void SX126xSetFs( void )
{
    SX126xWriteCommand( RADIO_SET_FS, 0, 0 );
    OperatingMode = MODE_FS;
}

void SX126xSetTx( uint32_t timeout )
{
    uint8_t buf[3];

    OperatingMode = MODE_TX;

    buf[0] = ( uint8_t )( ( timeout >> 16 ) & 0xFF );
    buf[1] = ( uint8_t )( ( timeout >> 8 ) & 0xFF );
    buf[2] = ( uint8_t )( timeout & 0xFF );
    SX126xWriteCommand( RADIO_SET_TX, buf, 3 );
}

void SX126xSetRx( uint32_t timeout )
{
    uint8_t buf[3];

    OperatingMode = MODE_RX;

    buf[0] = ( uint8_t )( ( timeout >> 16 ) & 0xFF );
    buf[1] = ( uint8_t )( ( timeout >> 8 ) & 0xFF );
    buf[2] = ( uint8_t )( timeout & 0xFF );
    SX126xWriteCommand( RADIO_SET_RX, buf, 3 );
}

void SX126xSetRxBoosted( uint32_t timeout )
{
    uint8_t buf[3];

    OperatingMode = MODE_RX;

    SX126xWriteRegister( REG_RX_GAIN, 0x96 ); // max LNA gain, increase current by ~2mA for around ~3dB in sensivity

    buf[0] = ( uint8_t )( ( timeout >> 16 ) & 0xFF );
    buf[1] = ( uint8_t )( ( timeout >> 8 ) & 0xFF );
    buf[2] = ( uint8_t )( timeout & 0xFF );
    SX126xWriteCommand( RADIO_SET_RX, buf, 3 );
}

void SX126xSetRxDutyCycle( uint32_t rxTime, uint32_t sleepTime )
{
    uint8_t buf[6];

    buf[0] = ( uint8_t )( ( rxTime >> 16 ) & 0xFF );
    buf[1] = ( uint8_t )( ( rxTime >> 8 ) & 0xFF );
    buf[2] = ( uint8_t )( rxTime & 0xFF );
    buf[3] = ( uint8_t )( ( sleepTime >> 16 ) & 0xFF );
    buf[4] = ( uint8_t )( ( sleepTime >> 8 ) & 0xFF );
    buf[5] = ( uint8_t )( sleepTime & 0xFF );
    SX126xWriteCommand( RADIO_SET_RXDUTYCYCLE, buf, 6 );
    OperatingMode = MODE_RX_DC;
}

void SX126xSetCad( void )
{
    SX126xWriteCommand( RADIO_SET_CAD, 0, 0 );
    OperatingMode = MODE_CAD;
}

void SX126xSetTxContinuousWave( void )
{
    SX126xWriteCommand( RADIO_SET_TXCONTINUOUSWAVE, 0, 0 );
}

void SX126xSetTxInfinitePreamble( void )
{
    SX126xWriteCommand( RADIO_SET_TXCONTINUOUSPREAMBLE, 0, 0 );
}

void SX126xSetStopRxTimerOnPreambleDetect( uint8_t enable )
{
    SX126xWriteCommand( RADIO_SET_STOPRXTIMERONPREAMBLE, ( uint8_t* )&enable, 1 );
}

void SX126xSetLoRaSymbNumTimeout( uint8_t SymbNum )
{
    SX126xWriteCommand( RADIO_SET_LORASYMBTIMEOUT, &SymbNum, 1 );
}

void SX126xSetRegulatorMode( RadioRegulatorMode_t mode )
{
    SX126xWriteCommand( RADIO_SET_REGULATORMODE, ( uint8_t* )&mode, 1 );
}

void SX126xCalibrate( CalibrationParams_t calibParam )
{
    SX126xWriteCommand( RADIO_CALIBRATE, ( uint8_t* )&calibParam, 1 );
}

void SX126xCalibrateImage( uint32_t freq )
{
    uint8_t calFreq[2];

    if( freq > 900000000 )
    {
        calFreq[0] = 0xE1;
        calFreq[1] = 0xE9;
    }
    else if( freq > 850000000 )
    {
        calFreq[0] = 0xD7;
        calFreq[1] = 0xD8;
    }
    else if( freq > 770000000 )
    {
        calFreq[0] = 0xC1;
        calFreq[1] = 0xC5;
    }
    else if( freq > 460000000 )
    {
        calFreq[0] = 0x75;
        calFreq[1] = 0x81;
    }
    else if( freq > 425000000 )
    {
        calFreq[0] = 0x6B;
        calFreq[1] = 0x6F;
    }
	else if( freq >= 210000000)
	{
        calFreq[0] = 0x37;
        calFreq[1] = 0x41;
	}

    SX126xWriteCommand( RADIO_CALIBRATEIMAGE, calFreq, 2 );
}

void SX126xSetPaConfig( uint8_t paDutyCycle, uint8_t hpMax, uint8_t deviceSel, uint8_t paLut )
{
    uint8_t buf[4];

    buf[0] = paDutyCycle;
    buf[1] = hpMax;
    buf[2] = deviceSel;
    buf[3] = paLut;
    SX126xWriteCommand( RADIO_SET_PACONFIG, buf, 4 );
}

void SX126xSetRxTxFallbackMode( uint8_t fallbackMode )
{
    SX126xWriteCommand( RADIO_SET_TXFALLBACKMODE, &fallbackMode, 1 );
}

void SX126xSetDioIrqParams( uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask, uint16_t dio3Mask )
{
	uint8_t buf[8] = {0x02,0x01,0x02,0x01,0x00,0x00,0x00,0x00};
	
	//
	
	buf[1] = irqMask;
	buf[3] = irqMask;	
		
//    buf[0] = ( uint8_t )( ( irqMask >> 8 ) & 0x00FF );
//    buf[1] = ( uint8_t )( irqMask & 0x00FF );
//    buf[2] = ( uint8_t )( ( dio1Mask >> 8 ) & 0x00FF );
//    buf[3] = ( uint8_t )( dio1Mask & 0x00FF );
//    buf[4] = ( uint8_t )( ( dio2Mask >> 8 ) & 0x00FF );
//    buf[5] = ( uint8_t )( dio2Mask & 0x00FF );
//    buf[6] = ( uint8_t )( ( dio3Mask >> 8 ) & 0x00FF );
//    buf[7] = ( uint8_t )( dio3Mask & 0x00FF );
    SX126xWriteCommand( RADIO_CFG_DIOIRQ, buf, 8 );
}

uint16_t SX126xGetIrqStatus( void )
{
    uint8_t irqStatus[2];

    SX126xReadCommand( RADIO_GET_IRQSTATUS, irqStatus, 2 );
    return ( irqStatus[0] << 8 ) | irqStatus[1];
}

void SX126xSetDio2AsRfSwitchCtrl( uint8_t enable )
{
    SX126xWriteCommand( RADIO_SET_RFSWITCHMODE, &enable, 1 );
}

void SX126xSetDio3AsTcxoCtrl( RadioTcxoCtrlVoltage_t tcxoVoltage, uint32_t timeout )
{
    uint8_t buf[4];

    buf[0] = tcxoVoltage & 0x07;
    buf[1] = ( uint8_t )( ( timeout >> 16 ) & 0xFF );
    buf[2] = ( uint8_t )( ( timeout >> 8 ) & 0xFF );
    buf[3] = ( uint8_t )( timeout & 0xFF );

    SX126xWriteCommand( RADIO_SET_TCXOMODE, buf, 4 );
}


//101////////////////////////////////////////////////////////////////////
void SX126xSetRfFrequency( uint32_t frequency )
{
    uint8_t buf[4];
    uint32_t freq = 0;

    if( ImageCalibrated == FALSE )
    {
        SX126xCalibrateImage( frequency );
        ImageCalibrated = TRUE;
    }

    freq = ( uint32_t )( ( double )frequency / ( double )FREQ_STEP );
//	switch(frequency)
//	{
//		case 410000000: freq = 429916160; break;
//		case 411000000: freq = 430964736; break;
//		default: break;
//	}

    buf[0] = ( uint8_t )( ( freq >> 24 ) & 0xFF );
    buf[1] = ( uint8_t )( ( freq >> 16 ) & 0xFF );
    buf[2] = ( uint8_t )( ( freq >> 8 ) & 0xFF );
    buf[3] = ( uint8_t )( freq & 0xFF );
    SX126xWriteCommand( RADIO_SET_RFFREQUENCY, buf, 4 );
}

void SX126xSetPacketType( RadioPacketTypes_t packetType )
{
    // Save packet type internally to avoid questioning the radio
    PacketType = packetType;
    SX126xWriteCommand( RADIO_SET_PACKETTYPE, ( uint8_t* )&packetType, 1 );
}

RadioPacketTypes_t SX126xGetPacketType( void )
{
    return PacketType;
}

void SX126xSetTxParams( int8_t power, RadioRampTimes_t rampTime )
{
//    uint8_t buf[2];
//
//    if( SX126xGetPaSelect() == SX1261 )
//    {
//        if( power == 15 )
//        {
//            SX126xSetPaConfig( 0x06, 0x00, 0x01, 0x01 );
//        }
//        else
//        {
//            SX126xSetPaConfig( 0x04, 0x00, 0x01, 0x01 );
//        }
//        if( power >= 14 )
//        {
//            power = 14;
//        }
//        else if( power < -3 )
//        {
//            power = -3;
//        }
//        SX126xWriteRegister( REG_OCP, 0x18 ); // current max is 80 mA for the whole device
//    }
//    else // sx1262
//    {
//        SX126xSetPaConfig( 0x04, 0x07, 0x00, 0x01 );
//        if( power > 22 )
//        {
//            power = 22;
//        }
//        else if( power < -3 )
//        {
//            power = -3;
//        }
//        SX126xWriteRegister( REG_OCP, 0x38 ); // current max 160mA for the whole device
//    }
//    buf[0] = power;
//    buf[1] = ( uint8_t )rampTime;
//    SX126xWriteCommand( RADIO_SET_TXPARAMS, buf, 2 );
	uint8_t buf[2];

	SX126xSetPaConfig( 0x04, 0x07, 0x00, 0x01 );

	SX126xWriteRegister( REG_OCP, 0x38 ); // current max 160mA for the whole device

	buf[0] = power;
	buf[1] = ( uint8_t )rampTime;
	SX126xWriteCommand( RADIO_SET_TXPARAMS, buf, 2 );
}


//101////////////////////////////////////////////////////////////////////
void SX126xSetModulationParams( ModulationParams_t *modulationParams )
{
//    uint8_t n;
//    uint32_t tempVal = 0;
//    uint8_t buf[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
//
//    // Check if required configuration corresponds to the stored packet type
//    // If not, silently update radio packet type
//    if( PacketType != modulationParams->PacketType )
//    {
//        SX126xSetPacketType( modulationParams->PacketType );
//    }
//
//    switch( modulationParams->PacketType )
//    {
//        case PACKET_TYPE_GFSK:
//            n = 8;
//            tempVal = ( uint32_t )( 32 * ( ( double )XTAL_FREQ / ( double )modulationParams->Params.Gfsk.BitRate ) );
//            buf[0] = ( tempVal >> 16 ) & 0xFF;
//            buf[1] = ( tempVal >> 8 ) & 0xFF;
//            buf[2] = tempVal & 0xFF;
//            buf[3] = modulationParams->Params.Gfsk.ModulationShaping;
//            buf[4] = modulationParams->Params.Gfsk.Bandwidth;
//            tempVal = ( uint32_t )( ( double )modulationParams->Params.Gfsk.Fdev / ( double )FREQ_STEP );
//            buf[5] = ( tempVal >> 16 ) & 0xFF;
//            buf[6] = ( tempVal >> 8 ) & 0xFF;
//            buf[7] = ( tempVal& 0xFF );
//            SX126xWriteCommand( RADIO_SET_MODULATIONPARAMS, buf, n );
//            break;
//        case PACKET_TYPE_LORA:
//            n = 4;
//            buf[0] = modulationParams->Params.LoRa.SpreadingFactor;
//            buf[1] = modulationParams->Params.LoRa.Bandwidth;
//            buf[2] = modulationParams->Params.LoRa.CodingRate;
//            buf[3] = modulationParams->Params.LoRa.LowDatarateOptimize;
//
//            SX126xWriteCommand( RADIO_SET_MODULATIONPARAMS, buf, n );
//
//            break;
//        default:
//            return;
//    }
	uint8_t n = 4;
    uint8_t buf[4] = { 0x00 };

	buf[0] = modulationParams->Params.LoRa.SpreadingFactor;
	buf[1] = modulationParams->Params.LoRa.Bandwidth;
	buf[2] = modulationParams->Params.LoRa.CodingRate;
	buf[3] = modulationParams->Params.LoRa.LowDatarateOptimize;

	SX126xWriteCommand( RADIO_SET_MODULATIONPARAMS, buf, n );

}

void SX126xSetPacketParams( PacketParams_t *packetParams )
{
//    uint8_t n;
//    uint8_t crcVal = 0;
//    uint8_t buf[9] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
//
//    // Check if required configuration corresponds to the stored packet type
//    // If not, silently update radio packet type
//    if( PacketType != packetParams->PacketType )
//    {
//        SX126xSetPacketType( packetParams->PacketType );
//    }
//
//    switch( packetParams->PacketType )
//    {
//    case PACKET_TYPE_GFSK:
//        if( packetParams->Params.Gfsk.CrcLength == RADIO_CRC_2_BYTES_IBM )
//        {
//            SX126xSetCrcSeed( CRC_IBM_SEED );
//            SX126xSetCrcPolynomial( CRC_POLYNOMIAL_IBM );
//            crcVal = RADIO_CRC_2_BYTES;
//        }
//        else if( packetParams->Params.Gfsk.CrcLength == RADIO_CRC_2_BYTES_CCIT )
//        {
//            SX126xSetCrcSeed( CRC_CCITT_SEED );
//            SX126xSetCrcPolynomial( CRC_POLYNOMIAL_CCITT );
//            crcVal = RADIO_CRC_2_BYTES_INV;
//        }
//        else
//        {
//            crcVal = packetParams->Params.Gfsk.CrcLength;
//        }
//        n = 9;
//        buf[0] = ( packetParams->Params.Gfsk.PreambleLength >> 8 ) & 0xFF;
//        buf[1] = packetParams->Params.Gfsk.PreambleLength;
//        buf[2] = packetParams->Params.Gfsk.PreambleMinDetect;
//        buf[3] = ( packetParams->Params.Gfsk.SyncWordLength /*<< 3*/ ); // convert from byte to bit
//        buf[4] = packetParams->Params.Gfsk.AddrComp;
//        buf[5] = packetParams->Params.Gfsk.HeaderType;
//        buf[6] = packetParams->Params.Gfsk.PayloadLength;
//        buf[7] = crcVal;
//        buf[8] = packetParams->Params.Gfsk.DcFree;
//        break;
//    case PACKET_TYPE_LORA:
//        n = 6;
//        buf[0] = ( packetParams->Params.LoRa.PreambleLength >> 8 ) & 0xFF;
//        buf[1] = packetParams->Params.LoRa.PreambleLength;
//        buf[2] = packetParams->Params.LoRa.HeaderType;
//        buf[3] = packetParams->Params.LoRa.PayloadLength;
//        buf[4] = packetParams->Params.LoRa.CrcMode;
//        buf[5] = packetParams->Params.LoRa.InvertIQ;
//        break;
//    default:
//    case PACKET_TYPE_NONE:
//        return;
//    }
//    SX126xWriteCommand( RADIO_SET_PACKETPARAMS, buf, n );
	uint8_t n = 6;
    uint8_t buf[6] = { 0x00 };

	buf[0] = ( packetParams->Params.LoRa.PreambleLength >> 8 ) & 0xFF;
	buf[1] = packetParams->Params.LoRa.PreambleLength;
	buf[2] = packetParams->Params.LoRa.HeaderType;
	buf[3] = packetParams->Params.LoRa.PayloadLength;
	buf[4] = packetParams->Params.LoRa.CrcMode;
	buf[5] = packetParams->Params.LoRa.InvertIQ;

    SX126xWriteCommand( RADIO_SET_PACKETPARAMS, buf, n );
}

void SX126xSetCadParams( RadioLoRaCadSymbols_t cadSymbolNum, uint8_t cadDetPeak, uint8_t cadDetMin, RadioCadExitModes_t cadExitMode, uint32_t cadTimeout )
{
    uint8_t buf[7];

    buf[0] = ( uint8_t )cadSymbolNum;
    buf[1] = cadDetPeak;
    buf[2] = cadDetMin;
    buf[3] = ( uint8_t )cadExitMode;
    buf[4] = ( uint8_t )( ( cadTimeout >> 16 ) & 0xFF );
    buf[5] = ( uint8_t )( ( cadTimeout >> 8 ) & 0xFF );
    buf[6] = ( uint8_t )( cadTimeout & 0xFF );
    SX126xWriteCommand( RADIO_SET_CADPARAMS, buf, 5 );
    OperatingMode = MODE_CAD;
}

void SX126xSetBufferBaseAddress( uint8_t txBaseAddress, uint8_t rxBaseAddress )
{
    uint8_t buf[2];

    buf[0] = txBaseAddress;
    buf[1] = rxBaseAddress;
    SX126xWriteCommand( RADIO_SET_BUFFERBASEADDRESS, buf, 2 );
}

RadioStatus_t SX126xGetStatus( void )
{
    uint8_t stat = 0;
    RadioStatus_t status;

    SX126xReadCommand( RADIO_GET_STATUS, ( uint8_t * )&stat, 1 );
    status.Value = stat;
    return status;
}

int8_t SX126xGetRssiInst( void )
{
    uint8_t buf[1] = {0};
    int8_t rssi = -1;

    SX126xReadCommand( RADIO_GET_RSSIINST, buf, 1 );
    rssi = -buf[0] >> 1;
    return rssi;
}

void SX126xGetRxBufferStatus( uint8_t *payloadLength, uint8_t *rxStartBufferPointer )
{
    uint8_t status[2];

    SX126xReadCommand( RADIO_GET_RXBUFFERSTATUS, status, 2 );

    // In case of LORA fixed header, the payloadLength is obtained by reading
    // the register REG_LR_PAYLOADLENGTH
    if( ( SX126xGetPacketType( ) == PACKET_TYPE_LORA ) && ( SX126xReadRegister( REG_LR_PACKETPARAMS ) >> 7 == 1 ) )
    {
        *payloadLength = SX126xReadRegister( REG_LR_PAYLOADLENGTH );
    }
    else
    {
        *payloadLength = status[0];
    }
    *rxStartBufferPointer = status[1];
}

void SX126xGetPacketStatus( PacketStatus_t *pktStatus )
{
    uint8_t status[3];

    SX126xReadCommand( RADIO_GET_PACKETSTATUS, status, 3 );

    pktStatus->packetType = SX126xGetPacketType( );
    switch( pktStatus->packetType )
    {
        case PACKET_TYPE_GFSK:
//            pktStatus->Params.Gfsk.RxStatus = status[0];
//            pktStatus->Params.Gfsk.RssiSync = -status[1] >> 1;
//            pktStatus->Params.Gfsk.RssiAvg = -status[2] >> 1;
//            pktStatus->Params.Gfsk.FreqError = 0;
            break;

        case PACKET_TYPE_LORA:
            pktStatus->Params.LoRa.RssiPkt = -status[0] >> 1;
            ( status[1] < 128 ) ? ( pktStatus->Params.LoRa.SnrPkt = status[1] >> 2 ) : ( pktStatus->Params.LoRa.SnrPkt = ( ( status[1] - 256 ) >> 2 ) );
            pktStatus->Params.LoRa.SignalRssiPkt = -status[2] >> 1;
            pktStatus->Params.LoRa.FreqError = FrequencyError;
            break;

        default:
        case PACKET_TYPE_NONE:            
			memset1( (uint8_t*)pktStatus, 0, sizeof( PacketStatus_t ) );
            pktStatus->packetType = PACKET_TYPE_NONE;
            break;
    }
}

RadioError_t SX126xGetDeviceErrors( void )
{
    RadioError_t error;

    SX126xReadCommand( RADIO_GET_ERROR, ( uint8_t * )&error, 2 );
    return error;
}

void SX126xClearDeviceErrors( void )
{
    uint8_t buf[2] = { 0x00, 0x00 };
    SX126xWriteCommand( RADIO_CLR_ERROR, buf, 2 );
}

void SX126xClearIrqStatus( uint16_t irq )
{
    uint8_t buf[2];

    buf[0] = ( uint8_t )( ( ( uint16_t )irq >> 8 ) & 0x00FF );
    buf[1] = ( uint8_t )( ( uint16_t )irq & 0x00FF );
    SX126xWriteCommand( RADIO_CLR_IRQSTATUS, buf, 2 );
}





