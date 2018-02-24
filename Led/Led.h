#ifndef _LED_H
#define _LED_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Led
{
public:
	explicit Led(uint8_t);
	
	void enable(bool enabled = true);

	bool isLit() const;

	void blink(unsigned long);
	void blink(unsigned long, unsigned long);

	void blinkAsync(unsigned long);
	void blinkAsync(unsigned long, unsigned long);
	
private:
	uint8_t _ui8LedPin;
	uint8_t _ui8State;

	unsigned long _ulPrevMillis;
};

#endif

