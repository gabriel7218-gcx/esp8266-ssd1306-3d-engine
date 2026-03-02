#include <Arduino.h>
#include "config.h"
#include "dualcube.h"

static float outerA=0;
static float innerA=0;

static float cube[8][3]={
{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},
{-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1}
};

static int edges[12][2]={
{0,1},{1,2},{2,3},{3,0},
{4,5},{5,6},{6,7},{7,4},
{0,4},{1,5},{2,6},{3,7}
};

void drawDualCube(){
  int16_t o[8][2];
  int16_t i[8][2];

  float co=cos(outerA),so=sin(outerA);
  float ci=cos(innerA),si=sin(innerA);

  for(int k=0;k<8;k++){
    float x=cube[k][0];
    float y=cube[k][1];
    float z=cube[k][2];

    float xo=x*co - z*so;
    float zo=x*so + z*co;
    float yo=y*co - zo*so;
    float zo2=y*so + zo*co;
    float so2=28/(zo2+3);
    o[k][0]=xo*so2 + SCREEN_WIDTH/2;
    o[k][1]=yo*so2 + SCREEN_HEIGHT/2;

    float xi=x*ci - z*si;
    float zi=x*si + z*ci;
    float yi=y*ci - zi*si;
    float zi2=y*si + zi*ci;
    float si2=14/(zi2+3);
    i[k][0]=xi*si2 + SCREEN_WIDTH/2;
    i[k][1]=yi*si2 + SCREEN_HEIGHT/2;
  }

  for(int e=0;e<12;e++){
    int a=edges[e][0],b=edges[e][1];
    display.drawLine(o[a][0],o[a][1],o[b][0],o[b][1],SSD1306_WHITE);
    display.drawLine(i[a][0],i[a][1],i[b][0],i[b][1],SSD1306_WHITE);
  }

  outerA+=0.05;
  innerA+=0.05;
}
