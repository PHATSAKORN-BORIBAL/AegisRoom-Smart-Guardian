#include <Arduino.h>
#include "config.h"

unsigned long lastMotionMs=0;
bool relayState=false;
bool manualOverride=false;

struct SensorData {
  float temperatureC;
  float humidity;
  int lightLevel;
  bool motion;
};

SensorData readSensors() {
  SensorData d{};
  // Replace prototype values with readings from your chosen sensors.
  d.temperatureC=25.0;
  d.humidity=55.0;
  d.lightLevel=analogRead(PIN_LDR);
  d.motion=digitalRead(PIN_PIR);
  return d;
}

void setRelay(bool on) {
  relayState=on;
  digitalWrite(PIN_RELAY,on?HIGH:LOW);
}

void publishTelemetry(const SensorData& d) {
  // Replace with PubSubClient MQTT publishing for deployment.
  Serial.printf("temp=%.1fC humidity=%.1f%% light=%d motion=%s relay=%s\n",
    d.temperatureC,d.humidity,d.lightLevel,d.motion?"true":"false",
    relayState?"ON":"OFF");
}

void applyAutomation(const SensorData& d) {
  if(d.motion) {
    lastMotionMs=millis();
    if(!manualOverride && d.lightLevel<DARK_THRESHOLD) setRelay(true);
  }
  if(!manualOverride && millis()-lastMotionMs>NO_MOTION_TIMEOUT_MS) setRelay(false);
  if(d.temperatureC>=TEMP_ALERT_C) Serial.println("ALERT: High temperature");
  if(d.humidity>=HUMIDITY_ALERT) Serial.println("ALERT: High humidity");
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_PIR,INPUT);
  pinMode(PIN_RELAY,OUTPUT);
  pinMode(PIN_LDR,INPUT);
  setRelay(false);
  Serial.println("AegisRoom starting...");
}

void loop() {
  SensorData d=readSensors();
  applyAutomation(d);
  publishTelemetry(d);
  delay(2000);
}
