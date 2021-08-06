/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

//使用するライブラリを宣言する　Wire.hはIDEに同梱されているので、ライブラリをインストールする必要はない
//LEDマトリクスのライブラリとかボードのセットアップとかはarduinoインストール.txtみて
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

//起動後一度だけ実行されるセットアッププログラム
void setup() {
  //シリアル通信の速度設定
  Serial.begin(9600);
  //シリアルモニタに接続されている場合、"8x8 LED Matrix Test"をシリアルモニタに表示する
  Serial.println("8x8 LED Matrix Test");
  //LEDマトリクスのアドレス
  matrix.begin(0x70);  // pass in the address
}

//---------①この部分に変換したドット絵PNGファイルのコードをコピーして貼りつける------------
// 'kao1', 8x8px
const unsigned char kao1 [] PROGMEM = {
  0x00, 0x66, 0x66, 0x00, 0x7e, 0x3c, 0x18, 0x00
};
// 'kao2', 8x8px
const unsigned char kao2 [] PROGMEM = {
  0x00, 0x66, 0x66, 0x00, 0x42, 0x42, 0x3c, 0x00
};
// 'kao3', 8x8px
const unsigned char kao3 [] PROGMEM = {
  0x00, 0x66, 0x66, 0x00, 0x7e, 0x3c, 0x18, 0x00
};

//---------①ドット絵PNGファイルコード貼り付け位置終わり----------------------

//電源が入っている間繰り返し行われる
void loop() {

//---------画像を表示するためのコード---------
  matrix.clear();
  //matrix.drawBitmap(0, 0, ②namaeの部分に自分の作った画像の名前を入れる, 8, 8, LED_ON);
  matrix.drawBitmap(0, 0, kao1, 8, 8, LED_ON);
  matrix.writeDisplay();
  //delay(時間)にてどのくらいの長さの時間表示するかを設定。単位はミリ秒(1,000ミリ秒=1秒)
  delay(500);
  matrix.clear();
  //matrix.drawBitmap(0, 0, ②namaeの部分に自分の作った画像の名前を入れる, 8, 8, LED_ON);
  matrix.drawBitmap(0, 0, kao2, 8, 8, LED_ON);
  matrix.writeDisplay();
  //delay(時間)にてどのくらいの長さの時間表示するかを設定。単位はミリ秒(1,000ミリ秒=1秒)
  delay(500);
  matrix.clear();
  //matrix.drawBitmap(0, 0, ②namaeの部分に自分の作った画像の名前を入れる, 8, 8, LED_ON);
  matrix.drawBitmap(0, 0, kao3, 8, 8, LED_ON);
  matrix.writeDisplay();
  //delay(時間)にてどのくらいの長さの時間表示するかを設定。単位はミリ秒(1,000ミリ秒=1秒)
  delay(500);
    //三角形を表示する（塗りつぶし）
  matrix.clear();
  //三角形（塗りつぶし）の表示 matrix.fillTriangle(三角形頂点１X,Y, 頂点２X,Y,頂点３X,Y, LED_ON);
  matrix.fillTriangle(0,7, 4,0,7,7, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  //delay(時間)にてどのくらいの長さの時間表示するかを設定。単位はミリ秒(1,000ミリ秒=1秒)
  delay(500);
  //テキストの表示横スクロール
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    //matrix.print("表示したい文字（アルファベット）");
    matrix.print("Gyaru");
    matrix.writeDisplay();
    //delay(時間)にてどのくらいの長さの時間表示するかを設定。単位はミリ秒(1,000ミリ秒=1秒)
    delay(100);
  }
}
