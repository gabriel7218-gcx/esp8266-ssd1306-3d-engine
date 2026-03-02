#include "payloads.h"
#include "dualcube.h"
#include "sierpinski.h"
#include "sphere.h"
#include "torus.h"

void runPayload(int id){
  switch(id){
    case 0: drawDualCube(); break;
    case 1: drawSierpinski(); break;
    case 2: drawSpherePoints(); break;
    case 3: drawTorus(); break;
  }
}
