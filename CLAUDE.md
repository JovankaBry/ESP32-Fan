# Fan-ESP32

Two PlatformIO ESP32 projects that control a fan via IR:

- `Transmitter/Code/src/main.cpp` — sends IR codes to the fan. This is where fan-control features (e.g. new triggers like Alexa) get wired in.
- `Receiver/Code/src/main.cpp` — captures IR codes from the fan's remote.

## Documentation rule

Whenever a feature is added or changed, update the root `README.md`. Keep it short and straightforward — a couple of lines per feature, no deep implementation detail. The audience is future-you skimming to remember what the project does, not a full spec. Use the `documentation` subagent for this.
