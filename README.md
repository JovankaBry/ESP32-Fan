# Fan-ESP32

Two ESP32 boards that control a **Philips RC-W02** fan by replaying its IR remote codes.

- **Transmitter** (`Transmitter/Code`) — sends IR codes to the fan (power, swing, mode, speed, timer, lock). Currently triggered over Serial by typing a command name.
- **Receiver** (`Receiver/Code`) — listens for IR signals and prints the decoded codes, used to capture new remote buttons.

Both are PlatformIO projects (`esp32dev` board, Arduino framework).

## Building / uploading

```bash
pio run -t upload -d Transmitter/Code
pio run -t upload -d Receiver/Code
```

The Transmitter also has an `esp32dev-ota` environment for updating it wirelessly over WiFi, once it's already flashed and connected:

```bash
pio run -t upload -e esp32dev-ota -d Transmitter/Code
```

## Status

- IR transmit/receive: working.
- OTA firmware updates (Transmitter): working.
- Alexa voice control: planned (not yet implemented).
