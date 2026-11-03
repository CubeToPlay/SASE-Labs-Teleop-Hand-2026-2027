#include "../utils/structures.hpp"

// ESP 1: 48:9d:31:2f:73:b0
// ESP 2: 48:9d:31:2f:93:5c
uint8_t broadcast_address[] = {0x48, 0x9D, 0x31, 0x2F, 0x93, 0x5C};

StructMessage my_data;

esp_now_peer_info peer_info;

void onDataSent(const wifi_tx_info_t *tx_info, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);

  initalizeSend(broadcast_address, peer_info, onDataSent);

  strcpy(my_data.a, "THIS IS A CHAR.");
}

void loop() {
  sendESPNOW(broadcast_address, my_data);

  delay(2000);
}