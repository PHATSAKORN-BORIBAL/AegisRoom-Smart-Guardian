# Test Plan

| Test | Input | Expected |
|---|---|---|
| T01 | Motion + low light | Relay ON |
| T02 | No motion | Relay OFF after timeout |
| T03 | High temperature | Alert |
| T04 | High humidity | Alert |
| T05 | Manual override | Automation does not change relay |
| T06 | Simulator | Telemetry is generated |
