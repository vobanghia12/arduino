byte ledPin[] = {0,1,2,3,4,5,6,7,8}; // Mảng lưu vị trí các chân Digital mà các đèn LED sử dụng theo thứ tự từ 1->8. Bạn có thể thêm các LED bằng cách thêm các chân digital vào mảng này
byte pinCount; // Khai báo biến pinCount dùng cho việc lưu tổng số chân LED
void setup() {
  pinCount = sizeof(ledPin);  //Xem thêm thông tin về hàm sizeof tại http://arduino.vn/reference/sizeof
  for (int i= pinCount - 1 ;i >=0 ;i--) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
  }
}
void loop() {
  /*
    Bật tuần tự các đèn LED
  */
  for (int i= pinCount - 1 ; i >= 0; i--) {
    digitalWrite(ledPin[i],HIGH); //Bật đèn
    delay(500); // Dừng để các đèn LED sáng dần
  }
  
  /*
    Tắt tuần tự các đèn LED
  */
  for (int i = 0 ;i < pinCount ; i++) {
    digitalWrite(ledPin[i],LOW); // Tắt đèn
    delay(500); // Dừng để các đèn LED tắt dần
  }
   for (int i= 0 ; i < pinCount; i++) {
    digitalWrite(ledPin[i],HIGH); //Bật đèn
    delay(500); // Dừng để các đèn LED sáng dần
  }
  
  /*
    Tắt tuần tự các đèn LED
  */
  for (int i = 0 ;i < pinCount; i++) {
    digitalWrite(ledPin[i],LOW); // Tắt đèn
    delay(500); // Dừng để các đèn LED tắt dần
  }
}
