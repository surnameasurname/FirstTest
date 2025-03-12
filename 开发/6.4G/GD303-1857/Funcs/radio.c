#include "radio.h"
#include "communication1.h"
#include "timer.h"
//uint16_t lora_preamble_len = 12;
/*!
* FSK bandwidth definition
*/
typedef struct
{
    uint32_t bandwidth;
    uint8_t  RegValue;
} FskBandwidth_t;

void OrderSend(uint8_t mode)
{
    if (mode == 2)
    {
        DataNum++;
        if (DataNum == 1)
        {
            ReceiveBuff[3] = Address1;
            RadioSend(ReceiveBuff, 5, 0);
        }
        if (DataNum == 2)
        {
            ReceiveBuff[3] = Address2;
            RadioSend(ReceiveBuff, 5, 0);
            DataNum = 0;
        }
        if (DataNum > 2)
        {
            DataNum = 0;
        }
    }
    else
    {
        ReceiveBuff[3] = Address1;
        RadioSend(ReceiveBuff, 5, 0);
    }
}




/*!
 * Precomputed FSK bandwidth registers values
 */
//const FskBandwidth_t FskBandwidths[] =
//{
//    { 4800  , 0x1F },
//    { 5800  , 0x17 },
//    { 7300  , 0x0F },
//    { 9700  , 0x1E },
//    { 11700 , 0x16 },
//    { 14600 , 0x0E },
//    { 19500 , 0x1D },
//    { 23400 , 0x15 },
//    { 29300 , 0x0D },
//    { 39000 , 0x1C },
//    { 46900 , 0x14 },
//    { 58600 , 0x0C },
//    { 78200 , 0x1B },
//    { 93800 , 0x13 },
//    { 117300, 0x0B },
//    { 156200, 0x1A },
//    { 187200, 0x12 },
//    { 234300, 0x0A },
//    { 312000, 0x19 },
//    { 373600, 0x11 },
//    { 467000, 0x09 },
//    { 500000, 0x00 }, // Invalid Bandwidth
//};

const RadioLoRaBandwidths_t Bandwidths[] = { LORA_BW_125, LORA_BW_250, LORA_BW_500 };

//                                          SF12    SF11    SF10    SF9    SF8    SF7   sf6     sf5
const double RadioLoRaSymbTime[3][8] = {{ 32.768, 16.384, 8.192, 4.096, 2.048, 1.024, 0.512, 0.256}, // 125 KHz
    { 16.384, 8.192,  4.096, 2.048, 1.024, 0.512, 0.256, 0.128 },  // 250 KHz
    { 8.192,  4.096,  2.048, 1.024, 0.512, 0.256, 0.128, 0.064}
}; // 500 KHz

typedef struct
{
    uint8_t Previous;
    uint8_t Current;
} RadioPublicNetwork_t;

static RadioPublicNetwork_t RadioPublicNetwork = { FALSE };

SX126x_t SX126x;

uint8_t RxContinuous = FALSE;

uint8_t radio_irq = 0;

uint8_t MaxPayloadLength = 0xFF;

uint32_t TxTimeout = 0;
uint32_t RxTimeout = 0;

//static uint8_t RadioGetFskBandwidthRegValue( uint32_t bandwidth )
//{
//    uint8_t i;
//
//    if( bandwidth == 0 )
//    {
//        return( 0x1F );
//    }
//
//    for( i = 0; i < ( sizeof( FskBandwidths ) / sizeof( FskBandwidth_t ) ) - 1; i++ )
//    {
//        if( ( bandwidth >= FskBandwidths[i].bandwidth ) && ( bandwidth < FskBandwidths[i + 1].bandwidth ) )
//        {
//            return FskBandwidths[i+1].RegValue;
//        }
//    }
// ERROR: Value not found
//    while( 1 );
//}

void RadioIoDeInit(void)
{
    SX126xIoDeInit();
}

void RadioRecoverIoInit(void)
{
    SX126xRecoverIoInit();
}

void RadioInit(void)
{
    SX126xInit();
    SX126xSetStandby(STDBY_RC);
    SX126xSetRegulatorMode(USE_DCDC);
    //SX126xSetRegulatorMode( USE_LDO );

    SX126xSetBufferBaseAddress(0x00, 0x00);
    SX126xSetTxParams(0, RADIO_RAMP_200_US);
    SX126xSetDioIrqParams(IRQ_RADIO_ALL, IRQ_RADIO_ALL, IRQ_RADIO_NONE, IRQ_RADIO_NONE);
}

RadioState_t RadioGetStatus(void)
{
    switch (SX126xGetOperatingMode())
    {
    case MODE_TX:
        return RF_TX_RUNNING;
    case MODE_RX:
        return RF_RX_RUNNING;
    case RF_CAD:
        return RF_CAD;
    default:
        return RF_IDLE;
    }
}

void RadioSetModem(RadioModems_t modem)
{
    switch (modem)
    {
    default:
    case MODEM_FSK:
//        SX126xSetPacketType( PACKET_TYPE_GFSK );
//        // When switching to GFSK mode the LoRa SyncWord register value is reset
//        // Thus, we also reset the RadioPublicNetwork variable
//        RadioPublicNetwork.Current = FALSE;
        break;
    case MODEM_LORA:
        SX126xSetPacketType(PACKET_TYPE_LORA);
        // Public/Private network register is reset when switching modems
        if (RadioPublicNetwork.Current != RadioPublicNetwork.Previous)
        {
            RadioPublicNetwork.Current = RadioPublicNetwork.Previous;
            RadioSetPublicNetwork(RadioPublicNetwork.Current);
        }
        break;
    }
}

void RadioSetTxPower(uint8_t power)
{
    SX126xSetTxParams(power, RADIO_RAMP_40_US);
}

void RadioSetChannel(uint32_t freq)
{
    SX126xSetRfFrequency(freq);
}

///////////////////////////////////////////////////////////////////////////
uint8_t RadioIsChannelFree(RadioPacketTypes_t modem, uint32_t freq, int16_t rssiThresh, uint32_t maxCarrierSenseTime)
{

    uint8_t status = TRUE;
    /*  uint32_t carrierSenseTime = 0;

        RadioSetModem( modem );

        RadioSetChannel( freq );

        RadioRx( 0 );

        drv_delay_ms( 1 );

        carrierSenseTime = TimerGetCurrentTime( );

        // Perform carrier sense for maxCarrierSenseTime
        while( TimerGetElapsedTime( carrierSenseTime ) < maxCarrierSenseTime )
        {
            rssi = RadioRssi( modem );

            if( rssi > rssiThresh )
            {
                status = FALSE;
                break;
            }
        }
        RadioSleep( );*/
    return status;
}

///////////////////////////////////////////////////////////////////////////
//ÑéÖ¤¹ý
uint32_t RadioRandom(void)
{
    uint8_t i;
    uint32_t rnd = 0;

    /*
     * Radio setup for random number generation
     */
    // Set LoRa modem ON
    SX126xSetPacketType(PACKET_TYPE_LORA);

    // Set radio in continuous reception
    SX126xSetRx(0);

    for (i = 0; i < 32; i++)
    {
        delay_1ms(1);
        // Unfiltered RSSI value reading. Only takes the LSB value
        rnd |= ((uint32_t)SX126xGetRssiInst() & 0x01) << i;
    }

    RadioSleep();

    return rnd;
}

void RadioSetRxConfig(RadioModems_t modem, uint32_t bandwidth,
                      uint32_t datarate, uint8_t coderate,
                      uint32_t bandwidthAfc, uint16_t preambleLen,
                      uint16_t symbTimeout, uint8_t fixLen,
                      uint8_t payloadLen,
                      uint8_t crcOn, uint8_t freqHopOn, uint8_t hopPeriod,
                      uint8_t iqInverted, uint8_t rxContinuous)
{

//    RxContinuous = rxContinuous;
//
//    if( fixLen == TRUE )
//    {
//        MaxPayloadLength = payloadLen;
//    }
//    else
//    {
//        MaxPayloadLength = 0xFF;
//    }
//
//    switch( modem )
//    {
//        case MODEM_FSK:
////            SX126xSetStopRxTimerOnPreambleDetect( FALSE );
////            SX126x.ModulationParams.PacketType = PACKET_TYPE_GFSK;
////
////            SX126x.ModulationParams.Params.Gfsk.BitRate = datarate;
////            SX126x.ModulationParams.Params.Gfsk.ModulationShaping = MOD_SHAPING_G_BT_1;
////            SX126x.ModulationParams.Params.Gfsk.Bandwidth = RadioGetFskBandwidthRegValue( bandwidth );
////
////            SX126x.PacketParams.PacketType = PACKET_TYPE_GFSK;
////            SX126x.PacketParams.Params.Gfsk.PreambleLength = ( preambleLen << 3 ); // convert byte into bit
////            SX126x.PacketParams.Params.Gfsk.PreambleMinDetect = RADIO_PREAMBLE_DETECTOR_08_BITS;
////            SX126x.PacketParams.Params.Gfsk.SyncWordLength = 3 << 3; // convert byte into bit
////            SX126x.PacketParams.Params.Gfsk.AddrComp = RADIO_ADDRESSCOMP_FILT_OFF;
////            SX126x.PacketParams.Params.Gfsk.HeaderType = ( fixLen == TRUE ) ? RADIO_PACKET_FIXED_LENGTH : RADIO_PACKET_VARIABLE_LENGTH;
////            SX126x.PacketParams.Params.Gfsk.PayloadLength = MaxPayloadLength;
////            if( crcOn == TRUE )
////            {
////                SX126x.PacketParams.Params.Gfsk.CrcLength = RADIO_CRC_2_BYTES_CCIT;
////            }
////            else
////            {
////                SX126x.PacketParams.Params.Gfsk.CrcLength = RADIO_CRC_OFF;
////            }
////            SX126x.PacketParams.Params.Gfsk.DcFree = RADIO_DC_FREEWHITENING;
////
////            RadioStandby( );
////            RadioSetModem( ( SX126x.ModulationParams.PacketType == PACKET_TYPE_GFSK ) ? MODEM_FSK : MODEM_LORA );
////            SX126xSetModulationParams( &SX126x.ModulationParams );
////            SX126xSetPacketParams( &SX126x.PacketParams );
////            SX126xSetSyncWord( ( uint8_t[] ){ 0xC1, 0x94, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00 } );
////            SX126xSetWhiteningSeed( 0x01FF );
////
////            RxTimeout = ( uint32_t )( symbTimeout * ( ( 1.0 / ( double )datarate ) * 8.0 ) * 1000 );
//            break;
//
//        case MODEM_LORA:
//            SX126xSetStopRxTimerOnPreambleDetect( FALSE );
//            SX126xSetLoRaSymbNumTimeout( symbTimeout );
//            SX126x.ModulationParams.PacketType = PACKET_TYPE_LORA;
//            SX126x.ModulationParams.Params.LoRa.SpreadingFactor = ( RadioLoRaSpreadingFactors_t )datarate;
//            SX126x.ModulationParams.Params.LoRa.Bandwidth = Bandwidths[bandwidth];
//            SX126x.ModulationParams.Params.LoRa.CodingRate = ( RadioLoRaCodingRates_t )coderate;
//
//            if( ( ( bandwidth == 0 ) && ( ( datarate == 11 ) || ( datarate == 12 ) ) ) ||
//            ( ( bandwidth == 1 ) && ( datarate == 12 ) ) )
//            {
//                SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x01;
//            }
//            else
//            {
//                SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x00;
//            }
//
//            SX126x.PacketParams.PacketType = PACKET_TYPE_LORA;
//
//            if( ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF5 ) ||
//                ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF6 ) )
//            {
//                if( preambleLen < 12 )
//                {
//                    SX126x.PacketParams.Params.LoRa.PreambleLength = 12;
//                }
//                else
//                {
//                    SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//                }
//            }
//            else
//            {
//                SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//            }
//
//            SX126x.PacketParams.Params.LoRa.HeaderType = ( RadioLoRaPacketLengthsMode_t )fixLen;
//
//            SX126x.PacketParams.Params.LoRa.PayloadLength = MaxPayloadLength;
//            SX126x.PacketParams.Params.LoRa.CrcMode = ( RadioLoRaCrcModes_t )crcOn;
//            SX126x.PacketParams.Params.LoRa.InvertIQ = ( RadioLoRaIQModes_t )iqInverted;
//
//            RadioSetModem( ( SX126x.ModulationParams.PacketType == PACKET_TYPE_GFSK ) ? MODEM_FSK : MODEM_LORA );
//            SX126xSetModulationParams( &SX126x.ModulationParams );
//            SX126xSetPacketParams( &SX126x.PacketParams );
//
//            // Timeout Max, Timeout handled directly in SetRx function
//            RxTimeout = 0xFFFF;
//
//            break;
//    }



    RxContinuous = rxContinuous;

//    if( fixLen == TRUE )
//    {
//        MaxPayloadLength = payloadLen;
//    }
//    else
//    {
    MaxPayloadLength = 0xFF;
//    }

    SX126xSetStopRxTimerOnPreambleDetect(FALSE);
    SX126xSetLoRaSymbNumTimeout(symbTimeout);
    SX126x.ModulationParams.PacketType = PACKET_TYPE_LORA;
    SX126x.ModulationParams.Params.LoRa.SpreadingFactor = (RadioLoRaSpreadingFactors_t)datarate;
    SX126x.ModulationParams.Params.LoRa.Bandwidth = Bandwidths[bandwidth];
    SX126x.ModulationParams.Params.LoRa.CodingRate = (RadioLoRaCodingRates_t)coderate;

    if (((bandwidth == 0) && ((datarate == 11) || (datarate == 12))) ||
            ((bandwidth == 1) && (datarate == 12)))
    {
        SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x01;
    }
    else
    {
        SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x00;
    }

    SX126x.PacketParams.PacketType = PACKET_TYPE_LORA;

//  if( ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF5 ) ||
//      ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF6 ) )
//  {
//      if( preambleLen < 12 )
//      {
//          SX126x.PacketParams.Params.LoRa.PreambleLength = 12;
//      }
//      else
//      {
//          SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//      }
//  }
//  else
//  {
    SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//  }

    SX126x.PacketParams.Params.LoRa.HeaderType = (RadioLoRaPacketLengthsMode_t)fixLen;

    SX126x.PacketParams.Params.LoRa.PayloadLength = MaxPayloadLength;
    SX126x.PacketParams.Params.LoRa.CrcMode = (RadioLoRaCrcModes_t)crcOn;
    SX126x.PacketParams.Params.LoRa.InvertIQ = (RadioLoRaIQModes_t)iqInverted;

    RadioSetModem(MODEM_LORA);
    SX126xSetModulationParams(&SX126x.ModulationParams);
    SX126xSetPacketParams(&SX126x.PacketParams);

    // Timeout Max, Timeout handled directly in SetRx function
//  RxTimeout = 0xFFFF;
}

void RadioSetTxConfig(RadioModems_t modem, int8_t power, uint32_t fdev,
                      uint32_t bandwidth, uint32_t datarate,
                      uint8_t coderate, uint16_t preambleLen,
                      uint8_t fixLen, uint8_t crcOn, uint8_t freqHopOn,
                      uint8_t hopPeriod, uint8_t iqInverted, uint32_t timeout)
{

//    switch( modem )
//    {
//        case MODEM_FSK:
////            SX126x.ModulationParams.PacketType = PACKET_TYPE_GFSK;
////            SX126x.ModulationParams.Params.Gfsk.BitRate = datarate;
////
////            SX126x.ModulationParams.Params.Gfsk.ModulationShaping = MOD_SHAPING_G_BT_1;
////            SX126x.ModulationParams.Params.Gfsk.Bandwidth = RadioGetFskBandwidthRegValue( bandwidth );
////            SX126x.ModulationParams.Params.Gfsk.Fdev = fdev;
////
////            SX126x.PacketParams.PacketType = PACKET_TYPE_GFSK;
////            SX126x.PacketParams.Params.Gfsk.PreambleLength = ( preambleLen << 3 ); // convert byte into bit
////            SX126x.PacketParams.Params.Gfsk.PreambleMinDetect = RADIO_PREAMBLE_DETECTOR_08_BITS;
////            SX126x.PacketParams.Params.Gfsk.SyncWordLength = 3 << 3 ; // convert byte into bit
////            SX126x.PacketParams.Params.Gfsk.AddrComp = RADIO_ADDRESSCOMP_FILT_OFF;
////            SX126x.PacketParams.Params.Gfsk.HeaderType = ( fixLen == TRUE ) ? RADIO_PACKET_FIXED_LENGTH : RADIO_PACKET_VARIABLE_LENGTH;
////
////            if( crcOn == TRUE )
////            {
////                SX126x.PacketParams.Params.Gfsk.CrcLength = RADIO_CRC_2_BYTES_CCIT;
////            }
////            else
////            {
////                SX126x.PacketParams.Params.Gfsk.CrcLength = RADIO_CRC_OFF;
////            }
////            SX126x.PacketParams.Params.Gfsk.DcFree = RADIO_DC_FREEWHITENING;
////
////            RadioStandby( );
////            RadioSetModem( ( SX126x.ModulationParams.PacketType == PACKET_TYPE_GFSK ) ? MODEM_FSK : MODEM_LORA );
////            SX126xSetModulationParams( &SX126x.ModulationParams );
////            SX126xSetPacketParams( &SX126x.PacketParams );
////            SX126xSetSyncWord( ( uint8_t[] ){ 0xC1, 0x94, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00 } );
////            SX126xSetWhiteningSeed( 0x01FF );
//            break;
//
//        case MODEM_LORA:
//            SX126x.ModulationParams.PacketType = PACKET_TYPE_LORA;
//            SX126x.ModulationParams.Params.LoRa.SpreadingFactor = ( RadioLoRaSpreadingFactors_t ) datarate;
//            SX126x.ModulationParams.Params.LoRa.Bandwidth =  Bandwidths[bandwidth];
//            SX126x.ModulationParams.Params.LoRa.CodingRate= ( RadioLoRaCodingRates_t )coderate;
//
//            if( ( ( bandwidth == 0 ) && ( ( datarate == 11 ) || ( datarate == 12 ) ) ) ||
//            ( ( bandwidth == 1 ) && ( datarate == 12 ) ) )
//            {
//                SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x01;
//            }
//            else
//            {
//                SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x00;
//            }
//
//            SX126x.PacketParams.PacketType = PACKET_TYPE_LORA;
//
//            if( ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF5 ) ||
//                ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF6 ) )
//            {
//                if( preambleLen < 12 )
//                {
//                    SX126x.PacketParams.Params.LoRa.PreambleLength = 12;
//                }
//                else
//                {
//                    SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//                }
//            }
//            else
//            {
//                SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//            }
//
//            SX126x.PacketParams.Params.LoRa.HeaderType = ( RadioLoRaPacketLengthsMode_t )fixLen;
//            SX126x.PacketParams.Params.LoRa.PayloadLength = MaxPayloadLength;
//            SX126x.PacketParams.Params.LoRa.CrcMode = ( RadioLoRaCrcModes_t )crcOn;
//            SX126x.PacketParams.Params.LoRa.InvertIQ = ( RadioLoRaIQModes_t )iqInverted;
//
//            RadioStandby( );
//            RadioSetModem( ( SX126x.ModulationParams.PacketType == PACKET_TYPE_GFSK ) ? MODEM_FSK : MODEM_LORA );
//            SX126xSetModulationParams( &SX126x.ModulationParams );
//            SX126xSetPacketParams( &SX126x.PacketParams );
//            break;
//    }
//    SX126xSetTxParams(power,RADIO_RAMP_40_US);
//    TxTimeout = timeout;


    SX126xSetStopRxTimerOnPreambleDetect(FALSE);
    SX126xSetLoRaSymbNumTimeout(0);


    SX126x.ModulationParams.PacketType = PACKET_TYPE_LORA;
    SX126x.ModulationParams.Params.LoRa.SpreadingFactor = (RadioLoRaSpreadingFactors_t) datarate;
    SX126x.ModulationParams.Params.LoRa.Bandwidth =  Bandwidths[bandwidth];
    SX126x.ModulationParams.Params.LoRa.CodingRate = (RadioLoRaCodingRates_t)coderate;

    if (((bandwidth == 0) && ((datarate == 11) || (datarate == 12))) ||
            ((bandwidth == 1) && (datarate == 12)))
    {
        SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x01;
    }
    else
    {
        SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize = 0x00;
    }

    SX126x.PacketParams.PacketType = PACKET_TYPE_LORA;

//  if( ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF5 ) ||
//      ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor == LORA_SF6 ) )
//  {
//      if( preambleLen < 12 )
//      {
//          SX126x.PacketParams.Params.LoRa.PreambleLength = 12;
//      }
//      else
//      {
//          SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//      }
//  }
//  else
//  {
    SX126x.PacketParams.Params.LoRa.PreambleLength = preambleLen;
//  }

    SX126x.PacketParams.Params.LoRa.HeaderType = (RadioLoRaPacketLengthsMode_t)fixLen;
    SX126x.PacketParams.Params.LoRa.PayloadLength = MaxPayloadLength;
    SX126x.PacketParams.Params.LoRa.CrcMode = (RadioLoRaCrcModes_t)crcOn;
    SX126x.PacketParams.Params.LoRa.InvertIQ = (RadioLoRaIQModes_t)iqInverted;

    RadioStandby();
    RadioSetModem(MODEM_LORA);
    SX126xSetModulationParams(&SX126x.ModulationParams);
    SX126xSetPacketParams(&SX126x.PacketParams);

    SX126xSetTxParams(power, RADIO_RAMP_40_US);
}

///////////////////////////////////////////////////////////////////////////////////////////////
uint32_t RadioTimeOnAir(RadioModems_t modem, uint8_t pktLen)
{
    uint32_t airTime = 0;

//    switch( modem )
//    {
//    case MODEM_FSK:
//        {
//           airTime = (uint32_t)rint( ( 8 * ( SX126x.PacketParams.Params.Gfsk.PreambleLength +
//                                     ( SX126x.PacketParams.Params.Gfsk.SyncWordLength >> 3 ) +
//                                     ( ( SX126x.PacketParams.Params.Gfsk.HeaderType == RADIO_PACKET_FIXED_LENGTH ) ? 0.0 : 1.0 ) +
//                                     pktLen +
//                                     ( ( SX126x.PacketParams.Params.Gfsk.CrcLength == RADIO_CRC_2_BYTES ) ? 2.0 : 0 ) ) /
//                                     SX126x.ModulationParams.Params.Gfsk.BitRate ) * 1e3 );
//        }
//        break;
//    case MODEM_LORA:
//        {
//            double ts = RadioLoRaSymbTime[SX126x.ModulationParams.Params.LoRa.Bandwidth - 4][12 - SX126x.ModulationParams.Params.LoRa.SpreadingFactor];
//            // time of preamble
//            double tPreamble = ( SX126x.PacketParams.Params.LoRa.PreambleLength + 4.25 ) * ts;
//            // Symbol length of payload and time
//            double tmp = ceil( ( 8 * pktLen - 4 * SX126x.ModulationParams.Params.LoRa.SpreadingFactor +
//                                 28 + 16 * SX126x.PacketParams.Params.LoRa.CrcMode -
//                                 ( ( SX126x.PacketParams.Params.LoRa.HeaderType == LORA_PACKET_FIXED_LENGTH ) ? 20 : 0 ) ) /
//                                 ( double )( 4 * ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor -
//                                 ( ( SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize > 0 ) ? 2 : 0 ) ) ) ) *
//                                 ( ( SX126x.ModulationParams.Params.LoRa.CodingRate % 4 ) + 4 );
//            double nPayload = 8 + ( ( tmp > 0 ) ? tmp : 0 );
//            double tPayload = nPayload * ts;
//            // Time on air
//            double tOnAir = tPreamble + tPayload;
//            // return milli seconds
//            airTime = (uint32_t )floor( tOnAir + 0.999 );
//        }
//        break;
//    }
    return airTime;
}

void RadioSend(uint8_t *buffer, uint8_t size, uint32_t time_out)
{
    radio_tx_on();
    radio_rx_off();
    Delay_nms(400);
    SX126xSetDioIrqParams(IRQ_TX_DONE | IRQ_RX_TX_TIMEOUT,
                          IRQ_TX_DONE | IRQ_RX_TX_TIMEOUT,
                          IRQ_RADIO_NONE,
                          IRQ_RADIO_NONE);

//    if( SX126xGetPacketType( ) == PACKET_TYPE_LORA )
//    {
//        SX126x.PacketParams.Params.LoRa.PayloadLength = size;
//    }
//    else
//    {
//        SX126x.PacketParams.Params.Gfsk.PayloadLength = size;
//    }
//    SX126xSetPacketParams( &SX126x.PacketParams );
//
//    SX126xSendPayload( buffer, size, time_out );

    SX126x.PacketParams.Params.LoRa.PayloadLength = size;

    SX126xSetPacketParams(&SX126x.PacketParams);

    SX126xSendPayload(buffer, size, time_out);

    //radio_rx_on();
    Delay_nms(400);

}

void RadioGetBuffer(uint8_t *buffer, uint8_t *size,  uint8_t maxSize)
{
    SX126xGetPayload(buffer, size, maxSize);
}

void RadioSleep(void)
{
    SleepParams_t params = { 0 };

    params.Fields.WarmStart = 1;
    SX126xSetSleep(params);

    delay_1ms(2);
}

void RadioStandby(void)
{
    SX126xSetStandby(STDBY_RC);
}

void RadioRx(uint32_t timeout)
{
    radio_tx_off();
    radio_rx_on();

    SX126xSetDioIrqParams(IRQ_RX_DONE | IRQ_RX_TX_TIMEOUT,
                          IRQ_RX_DONE | IRQ_RX_TX_TIMEOUT,
                          IRQ_RADIO_NONE,
                          IRQ_RADIO_NONE);
//    if( timeout != 0 )
//    {
//
//    }

//    if( RxContinuous == TRUE )
//    {
//        SX126xSetRx( 0xFFFFFF ); // Rx Continuous
//    }
//    else
//    {
//        SX126xSetRx( timeout << 6 );
//    }
//    RxTimeout = timeout;
    SX126xSetRx(0);
}


void RadioRxBoosted(uint32_t timeout)
{
    if (timeout != 0)
    {

    }

    if (RxContinuous == TRUE)
    {
        SX126xSetRxBoosted(0xFFFFFF);   // Rx Continuous
    }
    else
    {
        SX126xSetRxBoosted(timeout << 6);
    }
    RxTimeout = timeout;
}


void RadioSetRxDutyCycle(uint32_t rxTime, uint32_t sleepTime)
{
    SX126xSetRxDutyCycle(rxTime, sleepTime);
}

void RadioStartCad(void)
{
    radio_tx_off();
    radio_rx_on();

    SX126xSetDioIrqParams(IRQ_CAD_DONE | IRQ_CAD_ACTIVITY_DETECTED,//IRQ_RADIO_ALL,
                          IRQ_CAD_DONE | IRQ_CAD_ACTIVITY_DETECTED, //IRQ_RADIO_ALL,
                          IRQ_RADIO_NONE,
                          IRQ_RADIO_NONE);
    SX126xSetCad();
}

void RadioSetCadParams(RadioLoRaCadSymbols_t cadSymbolNum, uint8_t cadDetPeak, uint8_t cadDetMin, RadioCadExitModes_t cadExitMode, uint32_t cadTimeout)
{
    SX126xSetCadParams(cadSymbolNum, cadDetPeak, cadDetMin, cadExitMode, cadTimeout);
}

void RadioTx(uint32_t timeout)
{
    SX126xSetTx(timeout << 6);
    TxTimeout = timeout;
}

////////////////////////////////////////////////////////////////////////////
void RadioSetTxContinuousWave(uint32_t freq, int8_t power, uint16_t time)
{
    SX126xSetRfFrequency(freq);
    SX126xSetTxParams(power, RADIO_RAMP_40_US);
    SX126xSetTxContinuousWave();
}

int8_t RadioRssi(void)
{
    return SX126xGetRssiInst();
}

///////////////////////////////////////////////////////////////////////////////////////////////
void RadioSetMaxPayloadLength(RadioModems_t modem, uint8_t max)
{
    if (modem == MODEM_LORA)
    {
        SX126x.PacketParams.Params.LoRa.PayloadLength = MaxPayloadLength = max;
        SX126xSetPacketParams(&SX126x.PacketParams);
    }
    else
    {
        if (SX126x.PacketParams.Params.Gfsk.HeaderType == RADIO_PACKET_VARIABLE_LENGTH)
        {
            SX126x.PacketParams.Params.Gfsk.PayloadLength = MaxPayloadLength = max;
            SX126xSetPacketParams(&SX126x.PacketParams);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
void RadioSetPublicNetwork(uint8_t enable)
{
    SX126xSetPacketType(PACKET_TYPE_LORA);
    if (enable == TRUE)
    {
        // Change LoRa modem SyncWord
        SX126xWriteRegister(REG_LR_SYNCWORD, (LORA_MAC_PUBLIC_SYNCWORD >> 8) & 0xFF);
        SX126xWriteRegister(REG_LR_SYNCWORD + 1, LORA_MAC_PUBLIC_SYNCWORD & 0xFF);
    }
    else
    {
        // Change LoRa modem SyncWord
        SX126xWriteRegister(REG_LR_SYNCWORD, (LORA_MAC_PRIVATE_SYNCWORD >> 8) & 0xFF);
        SX126xWriteRegister(REG_LR_SYNCWORD + 1, LORA_MAC_PRIVATE_SYNCWORD & 0xFF);
    }
}

uint16_t RadioGetIrqStatus(void)
{
    return SX126xGetIrqStatus();
}

void RadioGetPacketStatus(PacketStatus_t *pktStatus)
{
    SX126xGetPacketStatus(pktStatus);
}

RadioError_t RadioGetDeviceErrors(void)
{
    return SX126xGetDeviceErrors();
}

void RadioClearDeviceErrors(void)
{
    SX126xClearDeviceErrors();
}

void RadioClearIrqStatus(uint16_t irq)
{
    SX126xClearIrqStatus(irq);
}


void RadioOnDioIrq(void)
{
    radio_irq = 1;
}

void RadioSetPreamble(uint16_t preamble_len)
{
    SX126x.PacketParams.Params.LoRa.PreambleLength = preamble_len;
    SX126xSetStandby(STDBY_RC);
    SX126xSetPacketParams(&SX126x.PacketParams);
}


uint32_t RadioTimeOnAirAndPreamble(RadioModems_t modem, uint8_t pktLen, uint16_t preLen)
{
    uint32_t airTime = 0;
//
//    switch( modem )
//    {
//    case MODEM_FSK:
//        break;
//    case MODEM_LORA:
//        {
//            double ts = RadioLoRaSymbTime[SX126x.ModulationParams.Params.LoRa.Bandwidth - 4][12 - SX126x.ModulationParams.Params.LoRa.SpreadingFactor];
//            // time of preamble
//            double tPreamble = ( preLen + 4.25 ) * ts;
//            // Symbol length of payload and time
//            double tmp = ceil( ( 8 * pktLen - 4 * SX126x.ModulationParams.Params.LoRa.SpreadingFactor +
//                                 28 + 16 * SX126x.PacketParams.Params.LoRa.CrcMode -
//                                 ( ( SX126x.PacketParams.Params.LoRa.HeaderType == LORA_PACKET_FIXED_LENGTH ) ? 20 : 0 ) ) /
//                                 ( double )( 4 * ( SX126x.ModulationParams.Params.LoRa.SpreadingFactor -
//                                 ( ( SX126x.ModulationParams.Params.LoRa.LowDatarateOptimize > 0 ) ? 2 : 0 ) ) ) ) *
//                                 ( ( SX126x.ModulationParams.Params.LoRa.CodingRate % 4 ) + 4 );
//            double nPayload = 8 + ( ( tmp > 0 ) ? tmp : 0 );
//            double tPayload = nPayload * ts;
//            // Time on air
//            double tOnAir = tPreamble + tPayload;
//            // return milli seconds
//            airTime = (uint32_t )floor( tOnAir + 0.999 );
//        }
//        break;
//    }
    return airTime;
}

//void RadioIrqProcess( void )
//{
//    if( IrqFired == TRUE )
//    {
//        BoardDisableIrq( );
//        IrqFired = FALSE;
//        BoardEnableIrq( );
//
//        uint16_t irqRegs = SX126xGetIrqStatus( );
//        SX126xClearIrqStatus( IRQ_RADIO_ALL );
//
//        if( ( irqRegs & IRQ_TX_DONE ) == IRQ_TX_DONE )
//        {
//
//        }
//
//        if( ( irqRegs & IRQ_RX_DONE ) == IRQ_RX_DONE )
//        {
//
//        }
//
//        if( ( irqRegs & IRQ_CRC_ERROR ) == IRQ_CRC_ERROR )
//        {
//
//        }
//
//        if( ( irqRegs & IRQ_CAD_DONE ) == IRQ_CAD_DONE )
//        {
//            if( ( irqRegs & IRQ_CAD_ACTIVITY_DETECTED ) == IRQ_CAD_ACTIVITY_DETECTED )
//            {
//
//            }
//        }
//
//        if( ( irqRegs & IRQ_RX_TX_TIMEOUT ) == IRQ_RX_TX_TIMEOUT )
//        {
//            if( SX126xGetOperatingMode( ) == MODE_TX )
//            {
//
//            }
//            else if( SX126xGetOperatingMode( ) == MODE_RX )
//            {
//
//            }
//        }
//
//        if( ( irqRegs & IRQ_PREAMBLE_DETECTED ) == IRQ_PREAMBLE_DETECTED )
//        {
//            //__NOP( );
//        }
//
//        if( ( irqRegs & IRQ_SYNCWORD_VALID ) == IRQ_SYNCWORD_VALID )
//        {
//            //__NOP( );
//        }
//
//        if( ( irqRegs & IRQ_HEADER_VALID ) == IRQ_HEADER_VALID )
//        {
//            //__NOP( );
//        }
//
//        if( ( irqRegs & IRQ_HEADER_ERROR ) == IRQ_HEADER_ERROR )
//        {
//
//        }
//    }
//}
//
//
//
