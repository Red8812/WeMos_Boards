#include <Arduino.h>
#include <util/delay.h>
void lgt8fx8x_init()
{
#if defined(__LGT8F88ES__)
	TKCSR = 0x00;
	PCMSK0 |= 0x40;
#endif

// enable 1KB E2PROM 
#if defined(__LGT8FX8E__)
	ECCR = 0x80;
	ECCR = 0x40;
#endif

	// // 16MHz system clock
	// CLKPR = 0x80;
	// CLKPR = 0x01;

//使用外部晶振
	PMCR|=(1<<PMCE);
	PMCR|=(1<<SCMEN);

	//int i=0xff;
	//while(i--);
	_delay_us(5);

	PMCR|=(1<<PMCE);
	PMCR|=(1<<EXTEN); 

	 CLKPR=0x80;//分频
	 CLKPR=0x00;//000

}

int main(void)
{

#if defined(__LGT8F88A__) || defined(__LGT8F88ES__) || defined(__LGT8FX8E__)
	lgt8fx8x_init();
#endif	

	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

