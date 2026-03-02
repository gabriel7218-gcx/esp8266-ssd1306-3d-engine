#include <Arduino.h>
#include "config.h"
#include "sierpinski.h"

static float angle = 0;

static void tri(float x1,float y1,float x2,float y2,float x3,float y3,int d){
  if(d==0){
    display.drawLine(x1,y1,x2,y2,SSD1306_WHITE);
    display.drawLine(x2,y2,x3,y3,SSD1306_WHITE);
    display.drawLine(x3,y3,x1,y1,SSD1306_WHITE);
    return;
  }
  float mx12=(x1+x2)/2,my12=(y1+y2)/2;
  float mx23=(x2+x3)/2,my23=(y2+y3)/2;
  float mx31=(x3+x1)/2,my31=(y3+y1)/2;
  tri(x1,y1,mx12,my12,mx31,my31,d-1);
  tri(x2,y2,mx23,my23,mx12,my12,d-1);
  tri(x3,y3,mx31,my31,mx23,my23,d-1);
}

void drawSierpinski(){
  float cx=SCREEN_WIDTH/2;
  float cy=SCREEN_HEIGHT/2;
  float s=20;
  float ca=cos(angle);
  float sa=sin(angle);

  float ax=0,ay=-s;
  float bx=-s,by=s;
  float cx2=s,cy2=s;

  tri(ax*ca-ay*sa+cx,ax*sa+ay*ca+cy,
      bx*ca-by*sa+cx,bx*sa+by*ca+cy,
      cx2*ca-cy2*sa+cx,cx2*sa+cy2*ca+cy,3);

  angle+=0.04;
}
