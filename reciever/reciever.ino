/* Reciever - Directly controls the ROBOTIC hand gets its inputs from the Sender microcontroller which is on the human worn glove */

#include "../utils/structures.hpp"

StructMessage my_data;

void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int data_len) {
  memcpy(&my_data, data, sizeof(my_data));
  Serial.print("Bytes received: ");
  Serial.println(data_len);
  Serial.print("Char: ");
  Serial.println(my_data.a);
  Serial.println();
}

void setup() {
  Serial.begin(74880);
  
  initalizeRecv(onDataRecv);
}

void loop() {}
