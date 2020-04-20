#include <ESP8266WiFi.h> //引入ESP8266Wifi库

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP ... ");

  //就只需要下面这一句就可以建立一个网络了
  //输入参数分别了网络名称和密码
  boolean result = WiFi.softAP("ESPsoftAP_01", "pass-to-soft-AP"); 
  if(result == true) //如果建立成功就打印输出“Ready”
  {
    Serial.println("Ready");
  }
  else
  {
    Serial.println("Failed!");
  }
}

void loop()
{
  //打印输出当前有多少设备连接到ESP8266建立的网络中
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(3000);
}
