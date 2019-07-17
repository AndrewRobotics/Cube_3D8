/**********************************
 * Rutinas Cube Light
 * 
 * by YFROBOT
 ***********************************/
#include "LightCube.h"

LightCube lightCube(8, 9, 10);
  
void setup(){
  lightCube.clc();
}

void loop(){
  lightCube.All(10);

  lightCube.UtoD_scan(1);

  lightCube.dot(5);

  lightCube.LtoR_scan (10); // iluminado de izquierda a derecha

  lightCube.RtoL_scan (10); // se encendió de derecha a izquierda

  lightCube.FtoB_scan (10); // se encendió desde la parte delantera a la parte trasera

  lightCube.BtoF_scan (10); // se encendió de atrás hacia el frente

  lightCube.Acw (3,10); // antihorario en sentido antihorario, num; el número de rotaciones, v, la velocidad

  lightCube.Cw (3,10); // agujas del reloj hacia la derecha, num; el número de rotaciones, v, la velocidad

  lightCube.RCw (3,10); // lado derecho del reloj hacia la derecha

  lightCube.cube (0,0,6); // vacío = 0, 1 sólido vacío; esquina superior izquierda tipo = 0, la esquina superior derecha, 2 abajo a la izquierda, tres pies derechos.
  lightCube.cube (1,3,10);
  lightCube.cube (0,2,10);

  lightCube.rain (0,5,6); // menu = 0, abajo; menu = 1, arriba; ciclos num
  lightCube.rain (1,5,6);
   

  lightCube.up (1,10);               // Mueva
  lightCube.DtoU_scan (20);          // se ilumina desde abajo hacia arriba
  lightCube.xuanzhuantiao (0,1,4,8); // giratorio hueco, tipo = 1 sólido o hueco; cw es delantero
  lightCube.qumianxuanzhuan (1,4,5); // rotación superficie; cw = 1 en sentido antihorario, de lo contrario las agujas del reloj;
  lightCube.qumianxuanzhuan (0,4,5); // superficie de rotación; cw = 1 hacia la izquierda o hacia la derecha

  lightCube.sandglass (10); // reloj de arena
}
