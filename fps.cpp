#include <Arduino.h>
#include "fps.h"

static unsigned long lastFpsUpdate = 0;
static int frameCount = 0;
int currentFPS = 0;

void updateFPS() {
  frameCount++;
  unsigned long now = millis();
  if (now - lastFpsUpdate >= 1000) {
    currentFPS = frameCount;
    frameCount = 0;
    lastFpsUpdate = now;
  }
}
