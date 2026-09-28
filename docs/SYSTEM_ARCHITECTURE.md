# System Architecture

```text
[DHT22] ─┐
[PIR] ───┼→ [ESP32] → MQTT → [Broker] → [Dashboard]
[LDR] ───┘      │
                └→ [Relay]
```

ESP32 handles sensor acquisition, automation and relay control. MQTT decouples the device from the dashboard.
