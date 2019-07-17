/**************************************************************
 **红外遥控光立方
 * 
 * 每个按键我们都设置了不同的效果
 * 
 * BY YFRobot
 ***************************************************************/
#include <IRremote.h>
#include "LightCube.h"

int RECV_PIN = 11;   //红外线接收器OUTPUT端接在pin 11
LightCube lightCube(8, 9, 10);

IRrecv irrecv(RECV_PIN);   // 定义IRrecv 对象来接收红外线信号
decode_results results;   //解码结果放在decode_results构造的对象results里

void irdisplay(unsigned long value)  //  按下按键后，显示本遥控对应的按键
{
  switch(value){         //判定按下的是哪个按键，串口显示按钮名称
  case 0xFFA25D:
    lightCube.clc();
    break;
  case 0xFFE21D:
    lightCube.All(10);
    break;
  case 0xFF22DD:
    lightCube.dot(5);
    break;
  case 0xFF02FD:
    lightCube.LtoR_scan(10);//侧面从左向右依次点亮 
    break;
  case 0XFFC23D:
    lightCube.RtoL_scan(10); //侧面从右向左依次点亮
    break;
  case 0xFFE01F:
    lightCube.FtoB_scan(10); //从前排向后排依次点亮
    break;
  case 0xFFA857:
    lightCube.BtoF_scan(10); //从后排向前排依次点亮
    break;
  case 0xFF906F:
    lightCube.Acw(3,10);//anticlockwise逆时针,num；旋转周数，v；速度
    break;
  case 0xFF6897:
    lightCube.Cw(3,10);//clockwise顺时针，num；旋转周数，v；速度
    break;
  case 0xFF9867:
    lightCube.RCw(3,10);//右侧看顺时针
    break;
  case 0xFFB04F:
    lightCube.cube(1,2,5);	//empty=0,实1空; kind=0左上角,1右上角,2左下角,3右下脚.
    break;
  case 0xFF30CF:
    lightCube.cube(0,5,6);	//empty=0,实1空; kind=0左上角,1右上角,2左下角,3右下脚.	
    lightCube.cube(1,3,10);
    lightCube.cube(0,2,10);
    break;
  case 0xFF18E7:
    lightCube.rain(0,5,6);//menu=0,down;menu=1,up；num循环次数
    break;
  case 0xFF7A85:
    lightCube.rain(1,5,6);
    break;
  case 0xFF10EF:
    lightCube.up(1,10); //上移
    break;
  case 0xFF38C7:
    lightCube.DtoU_scan(20);  //从下向上依次点亮
    break;
  case 0xFF5AA5:
    lightCube.xuanzhuantiao(0,1,4,8);//空心旋转,kind=1实心,否则空心；cw是否正转
    break;
  case 0xFF42BD:
    lightCube.qumianxuanzhuan(1,4,5);//曲面旋转;cw=1逆时针,否则顺时针;
    break;
  case 0xFF4AB5:
    lightCube.qumianxuanzhuan(0,4,5);//曲面旋转;cw=1逆时针,否则顺时针
    break;
  case 0xFF52AD:
    lightCube.sandglass(10);//沙漏
    break;
  }
}

void setup()
{
  pinMode(RECV_PIN,INPUT);
  irrecv.enableIRIn();          //启动红外解码
  lightCube.clc();
}

void loop() {
  if (irrecv.decode(&results))  
  {
    //解码成功，收到一组红外线信号  
    irdisplay(results.value);    
    irrecv.resume(); 
  }
}


