/**********************************
 * Ejemplo 1 Andres
 ***********************************/
#include "LightCube.h"
#define num 100
#define v 6


LightCube lightCube(8, 9, 10);
  
void setup(){
  lightCube.clc();
}

void loop(){
 
lightCube.dot (v);   // antihorario en sentido antihorario   
  
   
}
