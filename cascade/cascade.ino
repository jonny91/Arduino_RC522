//整理者：极客工坊bg1lsy (lsy@sogou.com)
//整理时间：2013.05.25
#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 5);  //D10--读卡器MOSI引脚、D5--读卡器RST引脚
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();

  pinMode(2,OUTPUT);
  pinMode(3,INPUT);

  digitalWrite(3,LOW)
  digitalWrite(2,LOW)
}

void loop()
{
  //找卡
  if (rfid.isCard()) {
    //读取卡序列号
    if (rfid.readCardSerial()) {
      Serial.print("The card's number is  : "); //最后烧录的时候 把注释都去掉

      if ((rfid.serNum[0] == 0x90)
          && (rfid.serNum[2] == 0x00)
          && (rfid.serNum[3] == 0x00)
          && (rfid.serNum[4] == 0x00)
          && (rfid.serNum[5] == 0x00)
          && (digitalRead(3) == HIGH) //3号口变成高电平
          )
      {
        Serial.println("pass");
        digitalWrite(2,HIGH)
      }
    }
    //选卡，可返回卡容量（锁定卡片，防止多数读取），去掉本行将连续读卡
    //    rfid.selectTag(rfid.serNum);
  }
  else
  {
    Serial.println("error");
  }

  // rfid.halt();
}
