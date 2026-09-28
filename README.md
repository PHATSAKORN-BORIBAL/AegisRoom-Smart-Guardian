# AegisRoom — Smart Room Guardian

ESP32-based IoT prototype for room monitoring and energy-management automation.

## Features
- Temperature & humidity monitoring
- Motion detection
- Light-level detection
- Automatic relay control
- MQTT-ready telemetry
- Dashboard-ready architecture
- Python sensor simulator for demonstrations

## Architecture
```text
Sensors → ESP32 → MQTT Broker → Dashboard
              ↓
            Relay
```

## Suggested Hardware
ESP32, DHT22, PIR sensor, LDR/light sensor, relay module, optional current/energy sensor.

## Automation
1. Motion + dark room → relay ON
2. No motion for timeout → relay OFF
3. High temperature → alert
4. High humidity → alert
5. Manual override → suspend automatic relay decisions

## Repository
```text
firmware/     ESP32 prototype
simulator/    Hardware-free demo
dashboard/    Dashboard plan
hardware/     BOM and safety notes
config/       MQTT topic design
docs/         Architecture, rules and test plan
```

## Run simulator
```bash
python simulator/sensor_simulator.py
```

## Project status
Prototype / academic portfolio project. Hardware-specific results should only be reported after real testing.

## Future
Mobile dashboard, historical graphs, OTA updates, notifications, energy measurement and multi-room support.
