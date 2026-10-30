#include <esp_now.h>
#include <WiFi.h>

typedef struct StructMessage {
  char a[32];
} StructMessage;

export void initalizeESPNOW() {
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
}

export void initalizeSend(uint8_t broadcast_address[], esp_now_peer_info &peer_info, esp_now_send_cb_t cb) {
  initalizeESPNOW();
  
  esp_now_register_send_cb(cb);

  memcpy(peer_info.peer_addr, broadcast_address, 6);
  peer_info.channel = 0;  
  peer_info.encrypt = false;

  if (esp_now_add_peer(&peer_info) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

export void initalizeRecv(esp_now_recv_cb_t cb) {
  initalizeESPNOW();

  esp_now_register_recv_cb(cb);
}

export void sendESPNOW(uint8_t broadcast_address[], StructMessage &data) {
  esp_err_t result = esp_now_send(broadcast_address, (uint8_t *) &data, sizeof(data));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
}