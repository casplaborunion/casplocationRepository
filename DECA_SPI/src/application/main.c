// -------------------------------------------------------------------------------------------------------------------
//
//  File: main.c -
//
//  Copyright 2011 (c) DecaWave Ltd, Dublin, Ireland.
//
//  All rights reserved.
//
//  Author: Zoran Skrba, March 2012
//
// -------------------------------------------------------------------------------------------------------------------

/* Includes */
#include "compiler.h"
#include "port.h"

#include "instance.h"

#include "deca_types.h"

#include "deca_spi.h"
uint8 acdc[6] = { 1, 9, 5, 1, 7, 204 };
uint8 acdcr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8 acdcr1[1000];
uint8 acdcr2[6] = { 45, 67, 44, 11, 22, 33 };
uint8 acdcr3[6] = { 55, 66, 77, 88, 99, 110 };
uint8 acdcr4[6];
uint8 aaa = 0;
int re = 0;
int i = 0;
int abc =0;
uint8 dd = 0;
uint8 anchaddr;
uint8 tagList; 			//Chang2014.11.25
uint8 tagaddr; 			//Chang2014.11.25
uint8 blank; 			//Chang2014.11.25

extern void usb_run(void);
extern int usb_init(void);
extern void usb_printconfig(void);
extern void send_usbmessage(uint8*, int);
static uint8 str[5];

uint8 range_result_string[6];
uint8 range_result_string_temp[6];
uint8 avg_result_string[6];

uint8 anchaddr;			//Chang2014.11.25
uint8 tagList; 			//Chang2014.11.25
uint8 tagaddr; 			//Chang2014.11.25
uint8 blank; 			//Chang2014.11.25
uint16 tagShortAdd ;	//Chang2014.12.01
uint8 sourceAddr;		//Chang2014.12.01
uint8 destAddr;			//Chang2014.12.01

#define SOFTWARE_VER_STRING    " Multi A1 " //


uint64 instance_get_addr(void); //get own address (8 bytes)
uint64 instance_get_tagaddr(void); //get tag address (8 bytes)
uint64 instance_get_anchaddr(void); //get anchor address (that sent the ToF)

//int instance_anchaddr = 0; //0 = 0xDECA020000000001; 1 = 0xDECA020000000002; 2 = 0xDECA020000000003


void itoa_range_1(unsigned int num) {
	int i;
	int strlen = 0;
	char temp;
	while (num) {
		range_result_string[strlen++] = num % 100;
		num /= 100;
		range_result_string[strlen] = 0x00;
	}
	for (i = 0; i < strlen / 2; i++) {
		temp = str[i];
		range_result_string[i] = range_result_string[strlen - i - 1];
		range_result_string[strlen - i - 1] = temp;
	}
		range_result_string[1]=range_result_string[0];
		range_result_string[0]=0;

/*
		range_result_string[2] = abc++;
		//range_result_string[2] = instance_get_tagaddr();
		range_result_string[2] = tagaddr;
		range_result_string[3] = tagList; //instance_get_addr()자신 고유주소 출력
		//range_result_string[3] = 1;			//anchaddr; //Tag 중심일때!
		range_result_string[4] = 1;
		//range_result_string[4] = instance_anchaddr;
		//range_result_string[4] = 1;
		//range_result_string[5] = 0;

		//range_result_string[5] = instance_anchaddr;
		//range_result_string[6] = abc++;
*/
		//range_result_string[2] = abc++;
		range_result_string[2] = 0;
		range_result_string[3] = tag_inst->msg.destAddr[0];
		//range_result_string[3] = instaddtagtolist;
		range_result_string[4] = 2;
		//range_result_string[4] = sourceAddr;
		//range_result_string[5] = tagShortAdd;
		range_result_string[5] = 0;

		//////////1Tag//////////////
//		range_result_string[2] = 0;
//		range_result_string[3] = 0;
//		range_result_string[4] = 1;
//		range_result_string[5] = 0;
		////////////////////////////




	/*for (i = 2; i < 6; i++) {
		range_result_string[i] = i;
	}*/
}
void itoa_range_2(unsigned int num) {
	int i;
	int strlen = 0;
	char temp;
	while (num) {
		range_result_string[strlen++] = num % 100;
		num /= 100;
		range_result_string[strlen] = 0x00;
	}
	for (i = 0; i < strlen / 2; i++) {
		temp = str[i];
		range_result_string[i] = range_result_string[strlen - i - 1];
		range_result_string[strlen - i - 1] = temp;
	}

/*
		range_result_string[2] = abc++;
		//range_result_string[2] = instance_get_tagaddr();
		//range_result_string[2] = 0;
		range_result_string[2] = tagaddr;
		range_result_string[3] = tagList;
		//range_result_string[3] = 1;
		range_result_string[4] = 1;
		//range_result_string[4] = anchaddr; //Tag 중심일때!
		//range_result_string[4] = instance_anchaddr;
		//range_result_string[4] = 1;
		//range_result_string[5] = 0;
		range_result_string[5] = blank;
		//range_result_string[5] = instance_anchaddr;
		//range_result_string[6] = abc++;
*/
		//range_result_string[2] = abc++;
		range_result_string[2] = 0;
		//range_result_string[3] = instaddtagtolist;
		range_result_string[3] = tag_inst->msg.destAddr[0];
		range_result_string[4] = 2;
		//range_result_string[4] = ;
		//range_result_string[5] = tagShortAdd;
		range_result_string[5] = 0;

		//////////1Tag//////////////
//		range_result_string[2] = 0;
//		range_result_string[3] = 0;
//		range_result_string[4] = 1;
//		range_result_string[5] = 0;
		////////////////////////////

		/*for (i = 2; i < 6; i++) {
			range_result_string[i] = i;
		}*/
}

void itoa_avg(unsigned int num) {
	int i;
	int strlen = 0;
	char temp;
	while (num) {
		avg_result_string[strlen++] = '0' + num % 10;
		num /= 10;
		avg_result_string[strlen] = 0x00;
	}
	for (i = 0; i < strlen / 2; i++) {
		temp = str[i];
		avg_result_string[i] = avg_result_string[strlen - i - 1];
		avg_result_string[strlen - i - 1] = temp;
	}
}

int instance_anchaddr = 0; //0 = 0xDECA020000000001; 1 = 0xDECA020000000002; 2 = 0xDECA020000000003
int dr_mode = 0;
//if instance_mode = TAG_TDOA then the device cannot be selected as anchor
int instance_mode = ANCHOR;
//int instance_mode = TAG;
//int instance_mode = TAG_TDOA;
//int instance_mode = LISTENER;
int paused = 0;

double antennaDelay; // This is system effect on RTD subtracted from local calculation.

char reset_request;

typedef struct {
	uint8 channel;
	uint8 prf;
	uint8 datarate;
	uint8 preambleCode;
	uint8 preambleLength;
	uint8 pacSize;
	uint8 nsSFD;
	uint16 sfdTO;
} chConfig_t;

typedef struct {
	uint8 Header;
	uint8 Packet_Type;
	uint32 Sequence_Number;
	uint16 Cell_ID;
	uint32 Anchor_ID;
	uint32 Tag_ID;
	uint32 Ranging_Data;
} packet;

packet deca_packet;

chConfig_t chConfig[8] = {
//mode 1 - S1: 7 off, 6 off, 5 off
		{ 2,              // channel
				DWT_PRF_16M,    // prf
				DWT_BR_110K,    // datarate
				3,             // preambleCode
				DWT_PLEN_1024,  // preambleLength
				DWT_PAC32,      // pacSize
				1,       // non-standard SFD
				(1025 + 64 - 32) //SFD timeout
		},
		//mode 2
		{ 2,              // channel
				DWT_PRF_16M,    // prf
				DWT_BR_6M8,    // datarate
				3,             // preambleCode
				DWT_PLEN_128,   // preambleLength
				DWT_PAC8,       // pacSize
				0,       // non-standard SFD
				(129 + 8 - 8) //SFD timeout
		},
		//mode 3
		{ 2,              // channel
				DWT_PRF_64M,    // prf
				DWT_BR_110K,    // datarate
				9,             // preambleCode
				DWT_PLEN_1024,  // preambleLength
				DWT_PAC32,      // pacSize
				1,       // non-standard SFD
				(1025 + 64 - 32) //SFD timeout
		},
		//mode 4
		{ 2,              // channel
				DWT_PRF_64M,    // prf
				DWT_BR_6M8,    // datarate
				9,             // preambleCode
				DWT_PLEN_128,   // preambleLength
				DWT_PAC8,       // pacSize
				0,       // non-standard SFD
				(129 + 8 - 8) //SFD timeout
		},
		//mode 5
		{ 5,              // channel
				DWT_PRF_16M,    // prf
				DWT_BR_110K,    // datarate
				3,             // preambleCode
				DWT_PLEN_1024,  // preambleLength
				DWT_PAC32,      // pacSize
				1,       // non-standard SFD
				(1025 + 64 - 32) //SFD timeout
		},
		//mode 6
		{ 5,              // channel
				DWT_PRF_16M,    // prf
				DWT_BR_6M8,    // datarate
				3,             // preambleCode
				DWT_PLEN_128,   // preambleLength
				DWT_PAC8,       // pacSize
				0,       // non-standard SFD
				(129 + 8 - 8) //SFD timeout
		},
		//mode 7
		{ 5,              // channel
				DWT_PRF_64M,    // prf
				DWT_BR_110K,    // datarate
				9,             // preambleCode
				DWT_PLEN_1024,  // preambleLength
				DWT_PAC32,      // pacSize
				1,       // non-standard SFD
				(1025 + 64 - 32) //SFD timeout
		},
		//mode 8
		{ 5,              // channel
				DWT_PRF_64M,    // prf
				DWT_BR_6M8,    // datarate
				9,             // preambleCode
				DWT_PLEN_128,   // preambleLength
				DWT_PAC8,       // pacSize
				0,       // non-standard SFD
				(129 + 8 - 8) //SFD timeout
		} };

#if (DR_DISCOVERY == 0)
//Tag address list
uint64 tagAddressList[TAG_LIST_SIZE] = {
		0xDECA010000000001,         // First tag
		0xDECA010000000002,         // Second tag
		0xDECA010000000003         	// Third tag
		};

//Anchor address list
uint64 anchorAddressList[ANCHOR_LIST_SIZE] = {
		0xDECA020000000001, 		// First anchor
		0xDECA020000000002,       	// Second anchor
		0xDECA020000000003,       	// Third anchor
		0xDECA020000000004,       	// Fourth anchor
		0xDECA020000000005,
		0xDECA020000000006,
		0xDECA020000000007,
		0xDECA020000000008

};

//ToF Report Forwarding Address
uint64 forwardingAddress[1] = {
		0xDECA030000000001
		};

// ======================================================
//
//  Configure instance tag/anchor/etc... addresses
//
void addressconfigure(void) {
	instanceAddressConfig_t ipc;

	ipc.forwardToFRAddress = forwardingAddress[0];
	ipc.anchorAddress = anchorAddressList[instance_anchaddr];
	ipc.anchorAddressList = anchorAddressList;
	ipc.anchorListSize = ANCHOR_LIST_SIZE;
	ipc.anchorPollMask =0x1; //0x1;              // anchor poll mask

	ipc.sendReport = 1; //1 => anchor sends TOF report to tag
	//ipc.sendReport = 2 ;  //2 => anchor sends TOF report to listener

	instancesetaddresses(&ipc);
}
#endif

uint32 inittestapplication(void);

// Restart and re-configure
void restartinstance(void) {
	instance_close();                 //shut down instance, PHY, SPI close, etc.

	spi_peripheral_init();                      //re initialise SPI...

	inittestapplication();                     //re-initialise instance/device
} // end restartinstance()

int decarangingmode(void) {
	int mode = 0;

	if (is_switch_on(TA_SW1_5)) {
		mode = 1;
	}

	if (is_switch_on(TA_SW1_6)) {
		mode = mode + 2;
	}

	if (is_switch_on(TA_SW1_7)) {
		mode = mode + 4;
	}

	return mode;
}

uint32 inittestapplication(void) {
	uint32 devID;
	instanceConfig_t instConfig;
	int i, result;

	SPI_ConfigFastRate(SPI_BaudRatePrescaler_16); //max SPI before PLLs configured is ~4M

	i = 10;

	//this is called here to wake up the device (i.e. if it was in sleep mode before the restart)
	devID = instancereaddeviceid();
	if (DWT_DEVICE_ID != devID) //if the read of devide ID fails, the DW1000 could be asleep
			{
		port_SPIx_clear_chip_select();  //CS low
		Sleep(1); //200 us to wake up then waits 5ms for DW1000 XTAL to stabilise
		port_SPIx_set_chip_select();  //CS high
		Sleep(7);
		devID = instancereaddeviceid();
		// SPI not working or Unsupported Device ID
		if (DWT_DEVICE_ID != devID)
			return (-1);
		//clear the sleep bit - so that after the hard reset below the DW does not go into sleep
		dwt_softreset();
	}

	//reset the DW1000 by driving the RSTn line low
	reset_DW1000();

	result = instance_init();
	if (0 > result)
		return (-1); // Some failure has occurred

	SPI_ConfigFastRate(SPI_BaudRatePrescaler_4); //increase SPI to max
	devID = instancereaddeviceid();

	if (DWT_DEVICE_ID != devID)   // Means it is NOT MP device
			{
		// SPI not working or Unsupported Device ID
		return (-1);
	}

	if (port_IS_TAG_pressed() == 0) {
		instance_mode = TAG;
		led_on(LED_PC7);
	} else {
		instance_mode = ANCHOR;
#if (DR_DISCOVERY == 1)
		led_on(LED_PC6);
#else
		if (instance_anchaddr & 0x1)
			led_on(LED_PC6);

		if (instance_anchaddr & 0x2)
			led_on(LED_PC8);
#endif
	}

	instancesetrole(instance_mode);     // Set this instance role

	if (is_fastrng_on(0) == S1_SWITCH_ON) //if fast ranging then initialise instance for fast ranging application
	{
		instance_init_f(instance_mode); //initialise Fast 2WR specific data
		//when using fast ranging the channel config is either mode 2 or mode 6
		//default is mode 2
		dr_mode = decarangingmode();

		if ((dr_mode & 0x1) == 0)
			dr_mode = 1;
	} else {
		instance_init_s(instance_mode);
		dr_mode = decarangingmode();
	}

	instConfig.channelNumber = chConfig[dr_mode].channel;
	instConfig.preambleCode = chConfig[dr_mode].preambleCode;
	instConfig.pulseRepFreq = chConfig[dr_mode].prf;
	instConfig.pacSize = chConfig[dr_mode].pacSize;
	instConfig.nsSFD = chConfig[dr_mode].nsSFD;
	instConfig.sfdTO = chConfig[dr_mode].sfdTO;
	instConfig.dataRate = chConfig[dr_mode].datarate;
	instConfig.preambleLen = chConfig[dr_mode].preambleLength;

	instance_config(&instConfig);                  // Set operating channel etc

#if (DR_DISCOVERY == 0)
	addressconfigure();                  // set up initial payload configuration
#endif
	instancesettagsleepdelay(POLL_SLEEP_DELAY, BLINK_SLEEP_DELAY); //set the Tag sleep time //Tag anchor1,2,3 읽은휴 딜레이

	//if TA_SW1_2 is on use fast ranging (fast 2wr)
	if (is_fastrng_on(0) == S1_SWITCH_ON) {
		//Fast 2WR specific config
		//configure the delays/timeouts
		instance_config_f();
	} else //use default ranging modes
	{
		// NOTE: this is the delay between receiving the blink and sending the ranging init message
		// The anchor ranging init response delay has to match the delay the tag expects
		// the tag will then use the ranging response delay as specified in the ranging init message
		// use this to set the long blink response delay (e.g. when ranging with a PC anchor that wants to use the long response times != 150ms)
		if (is_switch_on(TA_SW1_8) == S1_SWITCH_ON) {
			instancesetblinkreplydelay(FIXED_LONG_BLINK_RESPONSE_DELAY);
		} else //this is for ARM to ARM tag/anchor (using normal response times 150ms)
		{
			instancesetblinkreplydelay(FIXED_REPLY_DELAY);
		}

		//set the default response delays
		instancesetreplydelay(FIXED_REPLY_DELAY, 0);
	}

	return devID;
}
/**
 **===========================================================================
 **
 **  Abstract: main program
 **
 **===========================================================================
 */

void process_deca_irq(void) {
	do {

		instance_process_irq(0);

	} while (port_CheckEXT_IRQ() == 1); //while IRS line active (ARM can only do edge sensitive interrupts)

}

void initLCD(void) {
	uint8 initseq[9] = { 0x39, 0x14, 0x55, 0x6D, 0x78, 0x38 /*0x3C*/, 0x0C,
			0x01, 0x06 };
	uint8 command = 0x0;
	int j = 100000;

	//writetoLCD( 9, 0,  initseq); //init seq
	while (j--)
		;

	command = 0x2;  //return cursor home
	//writetoLCD( 1, 0,  &command);
	command = 0x1;  //clear screen
	//writetoLCD( 1, 0,  &command);
}

/*
 * @brief switch_mask  - bitmask of testing switches (currently 7 switches)
 * 		  switchbuff[] - switch name to test
 * 		  *switch_fn[]() - corresponded to switch test function
 **/
#define switch_mask   (0x7F)

const uint8 switchbuf[] = { 0, TA_SW1_3, TA_SW1_4, TA_SW1_5, TA_SW1_6, TA_SW1_7, TA_SW1_8 };
const int (*switch_fn[])(uint16)= {&is_button_low,
	&is_switch_on, &is_switch_on, &is_switch_on,
	&is_switch_on, &is_switch_on, &is_switch_on };

/*
 * @fn test_application_run
 * @brief	test application for production pre-test procedure
 **/
void test_application_run(void) {
	char dataseq[2][40];
	uint8 j, switchStateOn, switchStateOff;

	switchStateOn = 0;
	switchStateOff = 0;

	led_on(LED_ALL);	// show all LED OK
	Sleep(1000);

	dataseq[0][0] = 0x1;  //clear screen
	//writetoLCD( 1, 0, (const uint8 *) &dataseq);
	dataseq[0][0] = 0x2;  //return cursor home
	//writetoLCD( 1, 0, (const uint8 *) &dataseq);

	/* testing SPI to DW1000*/
	//writetoLCD( 40, 1, (const uint8 *) "TESTING         ");
	//writetoLCD( 40, 1, (const uint8 *) "SPI, U2, S2, S3 ");
	Sleep(1000);

	if (inittestapplication() == (uint32) -1) {
		//writetoLCD( 40, 1, (const uint8 *) "SPI, U2, S2, S3 ");
		//writetoLCD( 40, 1, (const uint8 *) "-- TEST FAILS --");
		while (1)
			; //stop
	}

	//writetoLCD( 40, 1, (const uint8 *) "SPI, U2, S2, S3 ");
	//writetoLCD( 40, 1, (const uint8 *) "    TEST OK     ");
	Sleep(1000);

	/* testing of switch S2 */
	dataseq[0][0] = 0x1;  //clear screen
	//writetoLCD( 1, 0, (const uint8 *) &dataseq);

	while ((switchStateOn & switchStateOff) != switch_mask) {
		memset(&dataseq, ' ', sizeof(dataseq));
		strcpy(&dataseq[0][0], (const char *) "SWITCH");
		strcpy(&dataseq[1][0], (const char *) "toggle");
//switch 7-1
		for (j = 0; j < sizeof(switchbuf); j++) {
			if (switch_fn[j](switchbuf[j])) //execute current switch switch_fn
					{
				dataseq[0][8 + j] = 'O';
				switchStateOn |= 0x01 << j;
				switchStateOff &= ~(0x01 << j); //all switches finaly should be in off state
			} else {
				dataseq[1][8 + j] = 'O';
				switchStateOff |= 0x01 << j;
			}
		}

		//writetoLCD(40, 1, (const uint8 *) &dataseq[0][0]);
		//writetoLCD(40, 1, (const uint8 *) &dataseq[1][0]);
		Sleep(100);
	}

	led_off(LED_ALL);

	//writetoLCD( 40, 1, (const uint8 *) "  Preliminary   ");
	//writetoLCD( 40, 1, (const uint8 *) "   TEST OKAY    ");

	while (1)
		;
}

void SPI_Slave_Init() {
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	// Enable SPIy
	SPI_Cmd(SPIy, DISABLE);

	SPI_I2S_ITConfig(SPIy, SPI_I2S_IT_RXNE, ENABLE);

	/* Enable and set EXTI Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 14;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);
	SPI_Cmd(SPIy, ENABLE);
}

void SPI2_IRQHandler(void) {
	while (SPI_I2S_GetITStatus(SPIy, SPI_I2S_IT_TXE) != RESET)
		;

	SPI_I2S_ClearITPendingBit(SPIy, SPI_I2S_IT_RXNE);

	//receive[re]=SPI_I2S_ReceiveData(SPIy);
	re++;

	if (re > 20) {
		re = 0;
	}
}

void writetoZigbee2(uint32 bodylength, const uint8 *bodyBuffer) {

	int i = 0;
	uint8 addr;

	port_SPIy_clear_chip_select();  //CS low
	Sleep(10);
	for (i = 0; i < bodylength; i++)
	{

		while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);

		port_SPIx_send_data(bodyBuffer[i]); //send data on the SPI
		//Sleep(20);
		//    while(SPI_I2S_GetFlagStatus(SPIy, SPI_I2S_FLAG_RXNE)==RESET);
		//   acdcr[i] = port_SPIy_receive_data();

		while (port_SPIx_no_data()); //wait for rx buffer to fill
		//		port_SPIy_receive_data(); //this clears RXNE bit
//for(k=0;k<20;k++);

	}

//    for(i=0;i<3;i++)
//   {
//    while(SPI_I2S_GetFlagStatus(SPIy,SPI_I2S_FLAG_TXE)==RESET);
//    port_SPIy_send_data(addr+i+2); //send data on the SPI

//    //while (port_SPIy_no_data()); //wait for rx buffer to fill
//       		port_SPIy_receive_data(); //this clears RXNE bit
//    }
//
	Sleep(10);
	port_SPIy_set_chip_select();  //CS high

}

void writetoZigbee3() {


	    port_SPIy_clear_chip_select();  //CS low


		while (SPI_I2S_GetFlagStatus(SPIy, SPI_I2S_FLAG_TXE) == RESET);

		port_SPIy_send_data(dd++); //send data on the SPI

		while (port_SPIy_no_data());


	    Sleep(100);
	    port_SPIy_set_chip_select();  //CS high

}

void change_and_send(unsigned int range_result_int) {
	if (range_result_int < 10000) {
		itoa_range_1(range_result_int);
	}

	else {
		itoa_range_2(range_result_int);
	}
	//itoa_avg(avg_result_int);
//	make_8bit();

//	writetoZigbee2(6,acdcr1);
//	writetoZigbee2(6,acdcr2);
//	writetoZigbee2(6,acdcr3);
	writetoZigbee2(6, range_result_string);
//	Sleep(1000);
}

void EXTI2_IRQHandler() {
	EXTI_ClearITPendingBit(EXTI_Line2);

	abc=0;
}
/*
void EXTI2_IRQHandler() {
	EXTI_ClearITPendingBit(EXTI_Line2);

	int i = 0;
	int bodylength = 6;

	port_SPIy_clear_chip_select();  //CS low

	for (i = 0; i < bodylength; i++) {

		while (SPI_I2S_GetFlagStatus(SPIy, SPI_I2S_FLAG_TXE) == RESET)
			;

		port_SPIy_send_data(acdc[i]);  //send data on the SPI 쓰래기값

		while (SPI_I2S_GetFlagStatus(SPIy, SPI_I2S_FLAG_RXNE) == RESET)
			;

		acdcr1[i] = port_SPIy_receive_data();

	}
	port_SPIy_set_chip_select();  //CS high

	if (sleep)
		Sleep(1);

	for (i = 0; i < 20; i++) {
		acdcr1[i] = i;
	}
}*/
void make_8bit(void) {
	acdcr1[0] = deca_packet.Header;
	acdcr1[1] = deca_packet.Packet_Type;
	acdcr1[2] = (uint8) ((deca_packet.Sequence_Number >> 8) & 0xff);
	acdcr1[3] = (uint8) ((deca_packet.Sequence_Number) & 0xff);
	acdcr1[4] = (uint8) ((deca_packet.Cell_ID >> 8) & 0xff);
	acdcr1[5] = (uint8) ((deca_packet.Cell_ID) & 0xff);

	acdcr2[0] = (uint8) ((deca_packet.Anchor_ID >> 24) & 0xff);
	acdcr2[1] = (uint8) ((deca_packet.Anchor_ID >> 16) & 0xff);
	acdcr2[2] = (uint8) ((deca_packet.Anchor_ID >> 8) & 0xff);
	acdcr2[3] = (uint8) ((deca_packet.Anchor_ID) & 0xff);
	acdcr2[4] = (uint8) ((deca_packet.Tag_ID >> 24) & 0xff);
	acdcr2[5] = (uint8) ((deca_packet.Tag_ID >> 16) & 0xff);

	acdcr3[0] = (uint8) ((deca_packet.Tag_ID >> 8) & 0xff);
	acdcr3[1] = (uint8) ((deca_packet.Tag_ID) & 0xff);
	acdcr3[2] = (uint8) ((deca_packet.Ranging_Data >> 24) & 0xff);
	acdcr3[3] = (uint8) ((deca_packet.Ranging_Data >> 16) & 0xff);
	acdcr3[4] = (uint8) ((deca_packet.Ranging_Data >> 8) & 0xff);
	acdcr3[5] = (uint8) ((deca_packet.Ranging_Data) & 0xff);
}
void spi2_prescaler_reset1(void)
{

		SPI_InitTypeDef SPI_InitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;

		SPI_I2S_DeInit(SPIx);

		// SPIx Mode setup
		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;	 //
		//SPI_InitStructure.SPI_CPOL = SPI_CPOL_High; //
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
		//SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; //
		//SPI_InitStructure.SPI_NSS = SPI_NSS_Hard;
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
		//SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4; //sets BR[2:0] bits - baudrate in SPI_CR1 reg bits 4-6
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
		SPI_InitStructure.SPI_CRCPolynomial = 7;

		SPI_Init(SPIx, &SPI_InitStructure);

		// SPIx SCK and MOSI pin setup
		GPIO_InitStructure.GPIO_Pin = SPIx_SCK | SPIx_MOSI;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(SPIx_GPIO, &GPIO_InitStructure);

		// SPIx MISO pin setup
		GPIO_InitStructure.GPIO_Pin = SPIx_MISO;
		//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

		GPIO_Init(SPIx_GPIO, &GPIO_InitStructure);

		// SPIx CS pin setup
		GPIO_InitStructure.GPIO_Pin = SPIx_CS;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(SPIx_CS_GPIO, &GPIO_InitStructure);

		// Disable SPIx SS Output
		SPI_SSOutputCmd(SPIx, DISABLE);

		// Enable SPIx
		SPI_Cmd(SPIx, ENABLE);



}
void spi2_prescaler_reset2(void)
{

		SPI_InitTypeDef SPI_InitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;

		SPI_I2S_DeInit(SPIx);

		// SPIx Mode setup
		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;	 //
		//SPI_InitStructure.SPI_CPOL = SPI_CPOL_High; //
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
		//SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; //
		//SPI_InitStructure.SPI_NSS = SPI_NSS_Hard;
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
		//SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4; //sets BR[2:0] bits - baudrate in SPI_CR1 reg bits 4-6
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
		SPI_InitStructure.SPI_CRCPolynomial = 7;

		SPI_Init(SPIx, &SPI_InitStructure);

		// SPIx SCK and MOSI pin setup
		GPIO_InitStructure.GPIO_Pin = SPIx_SCK | SPIx_MOSI;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(SPIx_GPIO, &GPIO_InitStructure);

		// SPIx MISO pin setup
		GPIO_InitStructure.GPIO_Pin = SPIx_MISO;
		//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

		GPIO_Init(SPIx_GPIO, &GPIO_InitStructure);

		// SPIx CS pin setup
		GPIO_InitStructure.GPIO_Pin = SPIx_CS;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(SPIx_CS_GPIO, &GPIO_InitStructure);

		// Disable SPIx SS Output
		SPI_SSOutputCmd(SPIx, DISABLE);

		// Enable SPIx
		SPI_Cmd(SPIx, ENABLE);

}
/*
 * @fn 		main()
 * @brief	main entry point
 **/
int main(void) {
 	int a = 0;
	int i = 0;
	int toggle = 1;
	int ranging = 0;
	uint8 dataseq[40];
	double range_result = 0;
	double avg_result = 0;
	unsigned int range_result_int = 0;
	unsigned int avg_result_int = 0;
	uint8 dataseq1[40];

	led_off(LED_ALL); //turn off all the LEDs

	peripherals_init();

	spi_peripheral_init();

	Sleep(1000); //wait for LCD to power on

	//  SPI_Slave_Init();

	deca_packet.Header = 111;
	deca_packet.Packet_Type = 222;
	deca_packet.Sequence_Number = 0xaabbccdd;
	deca_packet.Cell_ID = 32111;
	deca_packet.Anchor_ID = 101010;
	deca_packet.Tag_ID = 2233333;

	for (; a<6; a++) {
		range_result_string_temp[a] = a+2;
	}
	a = 0;
/*	while(1){
	writetoZigbee2(6, range_result_string_temp);
	}
*/
	//make_8bit();
/*while(1)
{
	for(a=0;a<166;a++)
	{
		writetoZigbee2(6,range_result_string_temp);
	Sleep(100);
	}
	a=0;
}
*/
	//LCD 안쓰는 버전
	initLCD(); // 주석 제거 CHANG 2014_11_27
	memset(dataseq, 40, 0);
	memcpy(dataseq, (const uint8 *) "DECAWAVE        ", 16);
	writetoLCD( 40, 1, dataseq); 								//send some data   주석 제거 CHANG 2014_11_27
	memcpy(dataseq, (const uint8 *) SOFTWARE_VER_STRING, 16); // Also set at line #26 (Should make this from single value !!!)
	writetoLCD( 16, 1, dataseq); 								//send some data   주석 제거 CHANG 2014_11_27

	Sleep(1000);
#ifdef USB_SUPPORT
	// enable the USB functionality
	usb_init();
	Sleep(1000);

#endif

	port_DisableEXT_IRQ(); //disable ScenSor IRQ until we configure the device

	//test EVB1000 - used in EVK1000 production
#if 1
	if ((is_button_low(0) == S1_SWITCH_ON)
			&& (is_switch_on(TA_SW1_8) == S1_SWITCH_ON)) //using BOOT1 switch for test
			{
		test_application_run(); //does not return....
	} else
#endif
	if (is_switch_on(TA_SW1_3) == S1_SWITCH_OFF) {
		int j = 1000000;
		uint8 command;

		memset(dataseq, 0, 40);

		while (j--)
			;
		//command = 0x1 ;  //clear screen
		////writetoLCD( 1, 0,  &command);
		command = 0x2;  //return cursor home
		//writetoLCD( 1, 0,  &command);

		memcpy(dataseq, (const uint8 *) "DECAWAVE   ", 12);
		//writetoLCD( 40, 1, dataseq); //send some data
#ifdef USB_SUPPORT //this is set in the port.h file
		memcpy(dataseq, (const uint8 *) "USB to SPI ", 12);

#else
#endif
		//writetoLCD( 16, 1, dataseq); //send some data

		j = 1000000;

		while (j--)
			;

		command = 0x2;  //return cursor home
		//writetoLCD( 1, 0,  &command);
#ifdef USB_SUPPORT //this is set in the port.h file
		// enable the USB functionality
		//usb_init();
		NVIC_DisableDECAIRQ();

		// Do nothing in foreground -- allow USB application to run, I guess on the basis of USB interrupts?
		while (1)       // loop forever
		{
			usb_run();
		}
#endif
		return 1;
	}

	else //run DecaRanging application
	{
		uint8 dataseq[40];
		uint8 command = 0x0;

		command = 0x2;  //return cursor home
		//writetoLCD( 1, 0,  &command);
		memset(dataseq, ' ', 40);
		memcpy(dataseq, (const uint8 *) "DECAWAVE  RANGE", 15);
		//writetoLCD( 15, 1, dataseq); //send some data

		led_off(LED_ALL);

#ifdef USB_SUPPORT //this is set in the port.h file
		usb_printconfig();
#endif
		if (inittestapplication() == (uint32) -1) {
			led_on(LED_ALL); //to display error....
			dataseq[0] = 0x2;  //return cursor home
			//writetoLCD( 1, 0,  &dataseq[0]);
			memset(dataseq, ' ', 40);
			memcpy(dataseq, (const uint8 *) "ERROR   ", 12);
			//writetoLCD( 40, 1, dataseq); //send some data
			memcpy(dataseq, (const uint8 *) "  INIT FAIL ", 12);
			//writetoLCD( 40, 1, dataseq); //send some data
			return 0; //error
		}

		//sleep for 5 seconds displaying "Decawave"
		i = 30;
		while (i--) {
			if (i & 1)
				led_off(LED_ALL);
			else
				led_on(LED_ALL);

			Sleep(200);
		}
		i = 0;
		led_off(LED_ALL);
		command = 0x2;  //return cursor home
		//writetoLCD( 1, 0,  &command);

		memset(dataseq, ' ', 40);

		if (port_IS_TAG_pressed() == 0) //tag, anchor 나누는 곳
				{
			instance_mode = TAG;
			led_on(LED_PC7);
		} else {
			instance_mode = ANCHOR;
#if (DR_DISCOVERY == 1)
			led_on(LED_PC6);
#else
			if (instance_anchaddr & 0x1)
				led_on(LED_PC6);

			if (instance_anchaddr & 0x2)
				led_on(LED_PC8);
#endif
		}

		if (instance_mode == TAG) {
			//if TA_SW1_2 is on use fast ranging (fast 2wr)
			if (is_button_low(0) == S1_SWITCH_ON) {
				memcpy(&dataseq[2], (const uint8 *) " Fast Tag   ", 12);
				//writetoLCD( 40, 1, dataseq); //send some data
				memcpy(&dataseq[2], (const uint8 *) "   Ranging  ", 12);
				//writetoLCD( 16, 1, dataseq); //send some data
			} else {
				memcpy(&dataseq[2], (const uint8 *) " TAG BLINK  ", 12);
				//writetoLCD( 40, 1, dataseq); //send some data
				sprintf((char*) &dataseq[0], "%llX", instance_get_addr());
				//writetoLCD( 16, 1, dataseq); //send some data
			}
		} else {
			memcpy(&dataseq[2], (const uint8 *) "  AWAITING  ", 12);
			//writetoLCD( 40, 1, dataseq); //send some data
			memcpy(&dataseq[2], (const uint8 *) "    POLL    ", 12);
			//writetoLCD( 16, 1, dataseq); //send some data
		}

		command = 0x2;  //return cursor home
		//writetoLCD( 1, 0,  &command);
	}

	port_EnableEXT_IRQ(); //enable ScenSor IRQ before starting

	memset(dataseq, ' ', 40);
	memset(dataseq1, ' ', 40);

	// main loop
	while (1) {
		instance_run();

		if (instancenewrange()) // have we got range details?
		{
			ranging = 1;
			//send the new range information to LCD and/or USB
			range_result = instance_get_idist();
//이박사님께 질문
#if (DR_DISCOVERY == 0)
			if (instance_mode == ANCHOR)
#endif
				avg_result = instance_get_adist();
			//set_rangeresult(range_result);
			dataseq[0] = 0x2;  //return cursor home
			//writetoLCD( 1, 0,  dataseq);

			memset(dataseq, ' ', 40);
			memset(dataseq1, ' ', 40);
			sprintf((char*) &dataseq[1], "LAST: %4.2f m", range_result);

			//writetoLCD( 40, 1, dataseq); //send some data

#if (DR_DISCOVERY == 0)
			if (instance_mode == ANCHOR)
				sprintf((char*) &dataseq1[1], "AVG8: %4.2f m", avg_result);
			else
				sprintf((char*) &dataseq1[0], "%llx", instance_get_anchaddr());
#else
			sprintf((char*) &dataseq1[1], "AVG8: %4.2f m", avg_result);
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			port_SPIx_set_chip_select();
			spi2_prescaler_reset1();


			range_result *= 10000;
			range_result_int = (uint32) range_result;

			//avg_result *= 10000;
			//avg_result_int = (uint32) avg_result;

			deca_packet.Ranging_Data = range_result_int;
			anchaddr=(uint8)instance_get_anchaddr();
			change_and_send(range_result_int);


			spi2_prescaler_reset2();
			port_SPIx_clear_chip_select();


			//writetoLCD( 16, 1, dataseq1); //send some data
#ifdef USB_SUPPORT //this is set in the port.h file
			if (instance_mode == TAG) {
sprintf			((char*) &dataseq[0], "t %4.2f %4d %4d %04d %d %d",
					range_result, instance_get_lcount()/*감지횟수*/,
					instance_get_dly(), instance_get_respPSC(),
					instance_get_txl(), instance_get_rxl());
			//sprintf((char*)&dataseq[20], " %08x", dwt_read32bitoffsetreg(0xa, 1));
		} else {

			//sprintf((char*) &dataseq[0], "a %4.2f %4d %4d %04d %d %d", range_result, instance_get_lcount(), instance_get_dly(), (dwt_read16bitoffsetreg(0x10, 2) >> 4), instance_get_txl(), instance_get_rxl());
			sprintf((char*)&dataseq[0], "a %4.2f %4d %4d %04d %d %d %x", range_result, instance_get_lcount(), instance_get_dly(), (dwt_read16bitoffsetreg(0x10, 2) >> 4), instance_get_txl(), instance_get_rxl(),tag_inst->msg.destAddr[0]); // 2014.12.03 LJH
		}
			send_usbmessage(&dataseq[0], 35);
#endif
		}

		if (ranging == 0) {
			if (instance_mode != ANCHOR) {
				if (instancesleeping()) {
					dataseq[0] = 0x2;  //return cursor home
					//writetoLCD( 1, 0,  dataseq);
					if (toggle) {
						toggle = 0;
						memcpy(&dataseq[0], (const uint8 *) "    AWAITING    ",
								16);
						//writetoLCD( 40, 1, dataseq); //send some data
						memcpy(&dataseq[0], (const uint8 *) "    RESPONSE    ",
								16);
						//writetoLCD( 16, 1, dataseq); //send some data
					} else {
						toggle = 1;
						memcpy(&dataseq[0], (const uint8 *) "   TAG BLINK    ",
								16);
						//writetoLCD( 40, 1, dataseq); //send some data
						sprintf((char*) &dataseq[0], "%llX",
								instance_get_addr());
						//writetoLCD( 16, 1, dataseq); //send some data
					}

				}

				if (instanceanchorwaiting() == 2) {
					ranging = 1;
					dataseq[0] = 0x2;  //return cursor home
					//writetoLCD( 1, 0,  dataseq);
					memcpy(&dataseq[0], (const uint8 *) "    RANGING WITH", 16);
					//writetoLCD( 40, 1, dataseq); //send some data
					sprintf((char*) &dataseq[0], "%016llX", instance_get_anchaddr());
					//writetoLCD( 16, 1, dataseq); //send some data
				}
			} else {
				if (instanceanchorwaiting()) {
					toggle += 2;

					if (toggle > 300000) {
						dataseq[0] = 0x2;  //return cursor home
						//writetoLCD( 1, 0,  dataseq);
						if (toggle & 0x1) {
							toggle = 0;
							memcpy(&dataseq[0],
									(const uint8 *) "    AWAITING    ", 16);
							//writetoLCD( 40, 1, dataseq); //send some data
							memcpy(&dataseq[0],
									(const uint8 *) "      POLL      ", 16);
							//writetoLCD( 16, 1, dataseq); //send some data
						} else {
							toggle = 1;
#if (DR_DISCOVERY == 1)
							memcpy(&dataseq[0],
									(const uint8 *) " DISCOVERY MODE ", 16);
#else
							memcpy(&dataseq[0],
									(const uint8 *) " NON DISCOVERY  ", 16);
#endif
							//writetoLCD( 40, 1, dataseq); //send some data
							sprintf((char*) &dataseq[0], "%llX", instance_get_addr());
							//writetoLCD( 16, 1, dataseq); //send some data
						}
					}

				} else if (instanceanchorwaiting() == 2) {
					dataseq[0] = 0x2;  //return cursor home
					//writetoLCD( 1, 0,  dataseq);
					memcpy(&dataseq[0], (const uint8 *) "    RANGING WITH", 16);
					//writetoLCD( 40, 1, dataseq); //send some data
					sprintf((char*) &dataseq[0], "%llX", instance_get_tagaddr());
					//writetoLCD( 16, 1, dataseq); //send some data
				}
			}
		}
#ifdef USB_SUPPORT //this is set in the port.h file
		usb_run();
#endif
	}

	return 0;
}

