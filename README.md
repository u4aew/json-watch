# JsonWatch

A custom watch face for the [Watchy](https://watchy.sqfmi.com/) open-source e-paper smartwatch that displays time and status information in a JSON-like format.

## Preview

```
┌──────────────────────┐
│ {                    │
│   "time":            │
│   13:45              │
│──────────────────────│
│ "day":  "Mon",       │
│ "date": "04.03.2026",│
│ "bat":  "87% (4.10v)"│
│ }                    │
│                      │
│ // watchy v2.0       │
└──────────────────────┘
```

## Hardware

- [Watchy v2.0](https://watchy.sqfmi.com/) — ESP32-based e-paper smartwatch
- 200×200 px e-ink display

## Setup

1. Install the [Watchy library](https://github.com/sqfmi/Watchy) in Arduino IDE
2. Clone this repo and open `JsonWatch/JsonWatch.ino`
3. Edit `JsonWatch/settings.h`:
   - Set your city ID from [OpenWeatherMap](https://openweathermap.org/current#cityid) or use lat/lon
   - Set your OpenWeatherMap API key
   - Set your GMT offset (`GMT_OFFSET_SEC`)
4. Flash to your Watchy via Arduino IDE or use the prebuilt `JsonWatch/JsonWatch.bin`

## Configuration (`settings.h`)

| Setting | Description |
|---|---|
| `CITY_ID` | OpenWeatherMap city ID (default: New York) |
| `OPENWEATHERMAP_APIKEY` | Your API key |
| `TEMP_UNIT` | `metric` (°C) or `imperial` (°F) |
| `WEATHER_UPDATE_INTERVAL` | Minutes between weather fetches (min 5) |
| `NTP_SERVER` | Time sync server |
| `GMT_OFFSET_SEC` | UTC offset in seconds |

## Project Structure

```
JsonWatch/
├── JsonWatch.ino       # Entry point
├── MyWatchFace.h   # Watch face rendering logic
├── settings.h      # Configuration
└── JsonWatch.bin       # Prebuilt firmware
```
