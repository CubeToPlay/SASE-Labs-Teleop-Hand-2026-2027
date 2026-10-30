#include "../utils/structures.hpp"

uint8_t broadcast_address[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

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