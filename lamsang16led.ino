/*
shiftOut với 8 LED bằng 1 IC HC595
*/
//chân ST_CP của 74HC595
int latchPin = 8;
//chân SH_CP của 74HC595
int clockPin = 12;
//Chân DS của 74HC595
int dataPin = 11;
 
//Trạng thái của LED, hay chính là byte mà ta sẽ gửi qua shiftOut
const int HC595_COUNT = 2;//Nếu bạn dùng nhiều hơn thì thay bằng một số lớn hơn 2.
byte ledStatus[HC595_COUNT]= {0}; 
void setup() {
  //Bạn BUỘC PHẢI pinMode các chân này là OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
void fillValueToArray(byte value) {
  for (int i = 0;i < HC595_COUNT; i += 1) {
    ledStatus[i] = value;
  }
}
 
void shiftOutHC595(int dataPin, int clockPin, byte ledStatus[]) {
  digitalWrite(latchPin, LOW);
  
  for (int i = 0; i < HC595_COUNT; i++) {
    shiftOut(dataPin,clockPin,LSBFIRST,ledStatus[i]);  // Chúng ta dùng LSBFIRST thay cho MSBFIRST là có lý do của nó, cái này tôi không biết trình như thế nào để bạn hiểu rõ nhất
    // Tốt nhất bạn hãy thay LSBFIRST thành MSBFIRST để rõ ràng những gì tôi muốn nói.
  }
  
  digitalWrite(latchPin, HIGH);
}
 
void loop() { 
   fillValueToArray(0);
 
  for (int i = HC595_COUNT -1 ; i >=0; i--){
    for (byte j=0;j<8;j++) {
      ledStatus[i] = (ledStatus[i] >> 1) | 128;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(100);
    }    
  }
  

  for (int i = HC595_COUNT - 1 ; i >= 0; i--) {
    for (byte j=0;j<8;j++) {
      ledStatus[i] = (ledStatus[i] >> 1) ;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(100); 
    }    
  }

  fillValueToArray(0);
  
  for (int i = 0; i < HC595_COUNT; i++) {
    for (byte j=0;j<8;j++) {
      ledStatus[i] = (ledStatus[i] << 1) | 1;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(100); 
    }    
  }
  

  for (int i = 0; i < HC595_COUNT; i++) {
    for (byte j=0;j<8;j++) {
      ledStatus[i] = (ledStatus[i] << 1);
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(100); 
    }    
  }
 
}
