#include <Arduino.h>
#include "Application.h"

std::unique_ptr<Application> pApp;

void setup()
{
	Serial.begin(115200);
	while (!Serial)
		delay(10);

	pinMode(D0, INPUT_PULLUP);
	digitalWrite(D0, LOW);

	pApp = std::make_unique<Application>();
	pApp->Create();
}

void loop()
{
	pApp->Update();
}