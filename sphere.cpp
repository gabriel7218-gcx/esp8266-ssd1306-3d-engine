#include <Arduino.h>
#include "config.h"
#include "sphere.h"

#define LAT 8
#define LON 12

static float angle=0;

void drawSpherePoints(){
  float ca=cos(angle);
  float sa=sin(angle);

  for(int i=0;i<LAT;i++){
    float lat = PI * (i/(float)(LAT-1) - 0.5);
    float cl = cos(lat);
    float sl = sin(lat);

    for(int j=0;j<LON;j++){
      float lon = j * 2*PI/LON;

      float x = cl*cos(lon);
      float y = cl*sin(lon);
      float z = sl;

      float xr = x*ca - z*sa;
      float zr = x*sa + z*ca;

      float scale = 46/(zr+3);

      int px = xr*scale + SCREEN_WIDTH/2;
      int py = y*scale + SCREEN_HEIGHT/2;
      int r = max(1,(int)(3/(zr+3)));

      display.fillCircle(px,py,r,SSD1306_WHITE);
    }
  }

  angle += 0.04;
}
