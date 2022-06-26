#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char valorRecebido;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("CODIFICA"); 
  Serial.println("O dispositivo já pode ser pareado!");

  pinMode(23, OUTPUT); 
}
void loop() {
    valorRecebido =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    if(valorRecebido == '1') { 
      SerialBT.println("LED ligado");
      digitalWrite(23, HIGH);
    }
    if(valorRecebido == '2') {
      SerialBT.println("LED desligado");
      digitalWrite(23, LOW);
    }  
  }
  delay(30);
}
