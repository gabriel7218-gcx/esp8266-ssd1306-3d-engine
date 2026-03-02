#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "display.h"
#include "fps.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static unsigned long lastTextMove = 0;
static const unsigned long TEXT_MOVE_INTERVAL = 30000;
static int textCorner = 0;

void initDisplay() {
  Wire.begin(D5, D7);
  Wire.setClock(100000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void drawStats() {
  display.setTextSize(1);
  if (millis() - lastTextMove > TEXT_MOVE_INTERVAL) {
    textCorner = (textCorner + 1) % 4;
    lastTextMove = millis();
  }

  int x=0,y=0;
  switch(textCorner){
    case 0: x=0;y=0;break;
    case 1: x=SCREEN_WIDTH-66;y=0;break;
    case 2: x=0;y=SCREEN_HEIGHT-8;break;
    case 3: x=SCREEN_WIDTH-66;y=SCREEN_HEIGHT-8;break;
  }

  display.setCursor(x,y);
  display.print(ESP.getCpuFreqMHz());
  display.print("MHz ");
  display.print(currentFPS);
  display.print("FPS");
}
