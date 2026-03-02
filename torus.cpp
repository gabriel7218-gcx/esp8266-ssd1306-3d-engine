#include <Arduino.h>
#include "config.h"
#include "torus.h"

#define A_STEPS 14
#define B_STEPS 8

static float sinA[A_STEPS], cosA[A_STEPS];
static float sinB[B_STEPS], cosB[B_STEPS];
static float torusBase[A_STEPS][B_STEPS][3];
static int16_t torusPts[A_STEPS][B_STEPS][2];
static float torusAngle = 0;

void initTorus() {
  for(int i=0;i<A_STEPS;i++){
    float a=i*2*PI/A_STEPS;
    sinA[i]=sin(a);
    cosA[i]=cos(a);
  }
  for(int j=0;j<B_STEPS;j++){
    float b=j*2*PI/B_STEPS;
    sinB[j]=sin(b);
    cosB[j]=cos(b);
  }

  const float R=1.0;
  const float r=0.4;

  for(int i=0;i<A_STEPS;i++)
  for(int j=0;j<B_STEPS;j++){
    float x=(R+r*cosB[j])*cosA[i];
    float y=(R+r*cosB[j])*sinA[i];
    float z=r*sinB[j];
    torusBase[i][j][0]=x;
    torusBase[i][j][1]=y;
    torusBase[i][j][2]=z;
  }
}

void drawTorus() {
  float ca=cos(torusAngle);
  float sa=sin(torusAngle);

  for(int i=0;i<A_STEPS;i++)
  for(int j=0;j<B_STEPS;j++){
    float x=torusBase[i][j][0];
    float y=torusBase[i][j][1];
    float z=torusBase[i][j][2];

    float y1=y*ca - z*sa;
    float z1=y*sa + z*ca;

    float scale=34/(z1+3);
    torusPts[i][j][0]=x*scale + SCREEN_WIDTH/2;
    torusPts[i][j][1]=y1*scale + SCREEN_HEIGHT/2;
  }

  for(int i=0;i<A_STEPS;i++){
    int ni=(i+1)%A_STEPS;
    for(int j=0;j<B_STEPS;j++)
      display.drawLine(torusPts[i][j][0],torusPts[i][j][1],
                       torusPts[ni][j][0],torusPts[ni][j][1],SSD1306_WHITE);
  }

  for(int i=0;i<A_STEPS;i++)
  for(int j=0;j<B_STEPS;j++){
    int nj=(j+1)%B_STEPS;
    display.drawLine(torusPts[i][j][0],torusPts[i][j][1],
                     torusPts[i][nj][0],torusPts[i][nj][1],SSD1306_WHITE);
  }

  torusAngle += 0.04;
}
