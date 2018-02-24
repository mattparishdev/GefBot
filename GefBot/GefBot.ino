#include <Led.h>

Led g_warningLed(13);

void setup()
{
}

void loop()
{
	g_warningLed.blinkAsync(3000);
}
