#include <IRremote.h>
int RECV_PIN = 11;

long on1  = 0x00FFA25D;
long off1 = 0x00FFE01F;
long on2 = 0x00FF629D;
long off2 = 0x00FFA857;
long on3 = 0x00FFE21D;
long off3 = 0x00FF906F;
long on4 = 0x00FF22DD;
long off4 = 0x00FF6897;
long on5 = 0x00FF02FD;
long off5 = 0x00FF9867;
long on6 = 0x00FFC23D;
long off6 = 0x00FFB04F;
long on7 = 0x00FF30CF;
long off7 = 0x00FF7A85;
long on8 = 0x00FF42BD;
long off8 = 0x00FF52AD;
IRrecv irrecv(RECV_PIN);
decode_results results;


void dump(decode_results *results)
{
  int count = results->rawlen;
}

const unsigned char delayTimeMs = 2;

unsigned char pattern1[] =
{
  0x82, 0xFE, 0xFE, 0x82, 0x00, 0x30, 0x78, 0x7C,
  0x3E, 0x7C, 0x78, 0x30, 0x00, 0xFC, 0xFE, 0x02,
  0x02, 0xFE, 0xFC, 0x00, 0x00, 0x00 //原
};
unsigned char pattern2[] =
{
  0x39, 0x39, 0x39, 0x01, 0x01, 0x39, 0x39, 0x39, 0x80, 0x80, 0x9F, 0x80, 0x80, 0x9F, 0x80, 0x80,
  0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0xC0, 0xC0, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0x60, 0x60,
  0xF0, 0xF0, 0xF3, 0xF3, 0xF3, 0xF3, 0x30, 0x30, 0x1F, 0x1F, 0x9F, 0x9F, 0x9F, 0x9F, 0x1F, 0x1F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  //hello
};
unsigned char pattern3[] =
{
  0xF9, 0xF9, 0xF9, 0xF9, 0xF9, 0xF9, 0xF8, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F,
  0x79, 0x33, 0x87, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0xE3, 0xE3, 0xE1, 0xE4, 0xE6, 0xE7, 0xE7, 0xE7,
  0xCF, 0xCF, 0xCF, 0xCF, 0x4F, 0x0F, 0x8F, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  //lyn
};
unsigned char pattern4[] =
{
  0x07, 0x07, 0x3F, 0x07, 0x07, 0xE7, 0x07, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF0, 0xF0, 0xFE, 0xF0, 0xF0, 0xF3, 0xF0, 0xF0, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0x7F, 0x7F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x07,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  //520
};
unsigned char pattern5[] =
{
  0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0xFC, 0xFC, 0xF8, 0x70, 0x20, 0x00,
  0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0xFC, 0xFC, 0xF8, 0x70, 0x20, 0x00,
  0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0xFC, 0xFC, 0xF8, 0x70, 0x20, 0x00,
  0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F
  //三个爱心
};
unsigned char pattern6[] =
{
  0x06, 0x06, 0x3E, 0x07, 0x07, 0xE7, 0x07, 0x07, 0xE7, 0xE7, 0x66, 0x66, 0x24, 0xA5, 0x81, 0xDB,
  0x60, 0x60, 0x67, 0xE0, 0xE0, 0xE7, 0xE0, 0xE0, 0x60, 0x60, 0xE7, 0x60, 0x60, 0xE7, 0x60, 0x60,
  0x60, 0x60, 0xF8, 0x78, 0x78, 0xF8, 0x78, 0x78, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF //sweeet
};
unsigned char pattern7[] =
{
  0xFF, 0x8C, 0x80, 0x80, 0xC0, 0xE1, 0xF3, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF //y一个心
};
unsigned char pattern8[] =
{
  0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
  0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
  0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
  0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF, 0x3F, 0xFF //线
};




unsigned char cols1 = (sizeof(pattern1) / sizeof(pattern1[0]));
unsigned char cols2 = (sizeof(pattern2) / sizeof(pattern2[0]));
unsigned char cols3 = (sizeof(pattern3) / sizeof(pattern3[0]));
unsigned char cols4 = (sizeof(pattern4) / sizeof(pattern4[0]));
unsigned char cols5 = (sizeof(pattern5) / sizeof(pattern5[0]));
unsigned char cols6 = (sizeof(pattern6) / sizeof(pattern6[0]));
unsigned char cols7 = (sizeof(pattern7) / sizeof(pattern7[0]));
unsigned char cols8 = (sizeof(pattern8) / sizeof(pattern8[0]));


void setup()
{
  pinMode(RECV_PIN, INPUT);
  irrecv.enableIRIn(); // Start the receiver

  DDRD = 0xFF;           //熟悉的十六进制

}

int on = 0;
unsigned long last = millis();
int i = 0, j;

void loop()
{
  if (irrecv.decode(&results))
  {
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    if (millis() - last > 250)
    {
      dump(&results);
    }
    if (results.value == on1 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols1; ++i)
        {
          PORTD = pattern1[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off1 )
      PORTD = 0x00;
    if (results.value == on2 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols2; ++i)
        {
          PORTD = pattern2[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off2 )
      PORTD = 0x00;
    if (results.value == on3 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols3; ++i)
        {
          PORTD = pattern3[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off3 )
      PORTD = 0x00;
    if (results.value == on4 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols4; ++i)
        {
          PORTD = pattern4[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off4 )
      PORTD = 0x00;
    if (results.value == on5 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols5; ++i)
        {
          PORTD = pattern5[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off5 )
      PORTD = 0x00;
    if (results.value == on6 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols6; ++i)
        {
          PORTD = pattern6[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off6 )
      PORTD = 0x00;
    if (results.value == on7 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols7; ++i)
        {
          PORTD = pattern7[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off7 )
      PORTD = 0x00;
    if (results.value == on8 )
    {
      for (j = 0; j <= 300; j++)
      {
        for (i = 0; i < cols8; ++i)
        {
          PORTD = pattern8[i];
          delay(delayTimeMs);
        }
      }
    }
    if (results.value == off8 )
      PORTD = 0x00;
    last = millis();
    irrecv.resume();
  }
}
