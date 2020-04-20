#include <Arduino.h>
#include <Wire.h>

#define N 100//列
#define M 8//行

int temp;//温度
int humi;//湿度
int tol;//校对码
int j;
unsigned int loopCnt;
int chr[40] = {0};//创建数字数组，用来存放40个bit
unsigned long time;
#define pin 12

int map2[N];
int Temp_char[7]={0x80,0xFF,0xFF,0x80,0x00,0x24,0x00};
int Humi_char[7]={0xFF,0x10,0x10,0xFF,0x00,0x24,0x00};
int Digits_char[10][5]={{0xFF,0x81,0x81,0xFF,0x00},
                        {0x00,0xFF,0x00,0x00,0x00},
                        {0x9F,0x91,0x91,0xF1,0x00},
                        {0x91,0x91,0x91,0xFF,0x00},
                        {0xF8,0x08,0xFF,0x08,0x00},
                        {0xF1,0x91,0x91,0x9F,0x00},
                        {0xFF,0x91,0x91,0x9F,0x00},
                        {0xE0,0x80,0x80,0xFF,0x00},
                        {0xFF,0x91,0x91,0xFF,0x00},
                        {0xF1,0x91,0x91,0xFF,0x00}};

void setup()
{
  DDRD = 0xFF;
}

void loop()
{
  bgn:
  delay(2000);
//设置2号接口模式为：输出
//输出低电平20ms（>18ms）
//输出高电平40μs
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  delay(20);
  digitalWrite(pin,HIGH);
  delayMicroseconds(40);
  digitalWrite(pin,LOW);
//设置2号接口模式：输入
  pinMode(pin,INPUT);
  //高电平响应信号 
  loopCnt=10000;
  while(digitalRead(pin) != HIGH)
  {
    if(loopCnt-- == 0)
    {
//如果长时间不返回高电平，输出个提示，重头开始。
      Serial.println("HIGH");
      goto bgn;
    }
  }
  //低电平响应信号
  loopCnt=30000;
  while(digitalRead(pin) != LOW)
  {
    if(loopCnt-- == 0)
    {
//如果长时间不返回低电平，输出个提示，重头开始。
      Serial.println("LOW");
      goto bgn;
    }
  }
//开始读取bit1-40的数值  
    for(int i=0;i<40;i++)
  {
    while(digitalRead(pin) == LOW)
    {}
//当出现高电平时，记下时间“time”
    time = micros();
    while(digitalRead(pin) == HIGH)
    {}
//当出现低电平，记下时间，再减去刚才储存的time
//得出的值若大于50μs，则为‘1’，否则为‘0’
//并储存到数组里去
    if (micros() - time >50)
    {
      chr[i]=1;
    }else{
      chr[i]=0;
    }
  }
   
//湿度，8位的bit，转换为数值
humi=chr[0]*128+chr[1]*64+chr[2]*32+chr[3]*16+chr[4]*8+chr[5]*4+chr[6]*2+chr[7];
   
//温度，8位的bit，转换为数值
temp=chr[16]*128+chr[17]*64+chr[18]*32+chr[19]*16+chr[20]*8+chr[21]*4+chr[22]*2+chr[23];
  //校对码，8位的bit，转换为数值
tol=chr[32]*128+chr[33]*64+chr[34]*32+chr[35]*16+chr[36]*8+chr[37]*4+chr[38]*2+chr[39];
//输出：温度、湿度、校对码

  int a,b,i;

  for (i=0;i<7;i++) map2[i]=Temp_char[i];
  a=temp/10;
  b=temp%10;
  for (i=0;i<5;i++) map2[7+i]=Digits_char[a][i];
  for (i=0;i<5;i++) map2[12+i]=Digits_char[b][i];

  for (i=17;i<24;i++) map2[i]=Humi_char[i-17];
  a=humi/10;
  b=humi%10;
  for (i=0;i<5;i++) map2[24+i]=Digits_char[a][i];
  for (i=0;i<5;i++) map2[29+i]=Digits_char[b][i];

  DDRD=0xFF;
  for (int i = 0; i <= 100; i++)
  {
    for (int j = 0; j < N; j++)
    {
      PORTD = 0xFF-map2[j];
      delay(2);
    }
  }

  //for (int i=0;i<N;i++) Serial.println(map1[i]);

   Serial.print("temp:");
   Serial.println(temp);
   Serial.print("humi:");
   Serial.println(humi);
}
