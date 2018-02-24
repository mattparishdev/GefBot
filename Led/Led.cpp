#include "Led.h"

Led::Led(const uint8_t pin)
	: _ui8LedPin{ pin }
	, _ui8State{ HIGH }
	, _ulPrevMillis{ millis() }
{
	pinMode(_ui8LedPin, OUTPUT);
	enable();
}

void Led::enable(const bool bEnabled /*= true*/)
{
	_ui8State = bEnabled ? HIGH : LOW;

	digitalWrite(_ui8LedPin, _ui8State);
}

bool Led::isLit() const
{
	return _ui8State == HIGH;
}


void Led::blink(const unsigned long ulMillis)
{
	blink(ulMillis, ulMillis);
}


void Led::blink(const unsigned long ulOnMillis, const unsigned long ulOffMillis)
{
	enable();
	delay(ulOnMillis);
	enable(false);
	delay(ulOffMillis);
}

void Led::blinkAsync(const unsigned long ulMillis)
{
	blinkAsync(ulMillis, ulMillis);
}


void Led::blinkAsync(const unsigned long ulOnMillis, const unsigned long ulOffMillis)
{
	const auto currentMillis = millis();

	switch (_ui8State)
	{
	case HIGH:
		if (currentMillis - _ulPrevMillis >= ulOnMillis)
		{
			enable(false);
			_ulPrevMillis = currentMillis;
		}
		break;
	case LOW:
		if (currentMillis - _ulPrevMillis >= ulOffMillis)
		{
			enable();
			_ulPrevMillis = currentMillis;
		}
		break;
	default: break;
	}
}
