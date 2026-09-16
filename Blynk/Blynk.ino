#define BLYNK_TEMPLATE_ID "TMPL3Tw4i93NY"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "lit9L_c9cyG5Yhl7aemyRpmr1LQriNed"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define LED_PIN 2

bool blinkEnable = false;
unsigned long previousMillis = 0;

const long interval = 500;
bool ledState = LOW;

// Blynk Switch is connected to Virtual Pin V0
BLYNK_WRITE(V0)
{
  blinkEnable = param.asInt();

  if (!blinkEnable)
  {
    digitalWrite(LED_PIN, LOW);
    ledState = LOW;
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  if (blinkEnable)
  {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;

      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }
}