#include <ESP8266WiFi.h>
extern "C" { 
  #include "user_interface.h" 
}

#include "config.h"
#include "display.h"
#include "fps.h"
#include "torus.h"
#include "payloads.h"

const unsigned long PAYLOAD_TIME = 10000;
int currentPayload = 0;
unsigned long payloadStart = 0;

void setup(){
  system_update_cpu_freq(80);
  initDisplay();
  initTorus();
  payloadStart = millis();
}

void loop(){
  display.clearDisplay();

  if (millis() - payloadStart > PAYLOAD_TIME){
    currentPayload = (currentPayload+1)%4;
    payloadStart = millis();
  }

  runPayload(currentPayload);
  drawStats();
  display.display();
  updateFPS();
  yield();
}
