# UtilifyLogger

**UtilifyLogger** is a lightweight and efficient logging library designed for embedded systems, including ESP32 and Arduino Uno. It provides configurable log levels, making it easier to monitor and debug embedded applications.

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/sirdrako/library/UtilifyLogger.svg)](https://registry.platformio.org/libraries/sirdrako/UtilifyLogger)

## Features

- **Configurable Log Levels**: Supports levels such as `INFO`, `VERBOSE`, `WARNING`, `ERROR`, and more to control verbosity.
- **Lightweight Design**: Optimized for resource-constrained environments.
- **Flexible Output**: Logs messages to serial output or other configurable streams.
- **Platform Support**: Designed to work with **ESP32** and **Arduino Uno**.

## Getting Started

### Installation

Add **UtilifyLogger** to your PlatformIO project by including the following in your `platformio.ini` file:

```ini
[env:esp32dev]
platform = espressif32
framework = arduino
lib_deps =
    https://github.com/PiFou86/Utilify.git
    https://github.com/PiFou86/UtilifyLogger.git
```

### Basic Usage

Include the library and initialize the logger in your project:

```cpp
#include <Arduino.h>
#include <Utilify/Logger/Logger.h>

void sendMessages();

void setup() {
  Serial.begin(9600);
  Logger.begin(&Serial);

  while (!Serial) {
    ;
  };

  Logger.setLoggerLevel(LoggerLevel::VERBOSE);

  LOGGER_BEGIN_METHOD;

  // pour la démo seulement :
  static int i = 0;
  LOGGER_VAR(i);
  i++;

  Logger.println(F("Setting logger level to ERROR and printing tests..."));
  Logger.setLoggerLevel(LoggerLevel::ERROR);
  sendMessages();

  Logger.println(F("Setting logger level to WARNING and printing tests..."));
  Logger.setLoggerLevel(LoggerLevel::WARNING);
  sendMessages();

  Logger.println(F("Setting logger level to INFO and printing tests..."));
  Logger.setLoggerLevel(LoggerLevel::INFO);
  sendMessages();

  Logger.println(F("Setting logger level to VERBOSE and printing tests..."));
  Logger.setLoggerLevel(LoggerLevel::VERBOSE);
  sendMessages();

  int a = 42;
  String b = F("Hello World!");
  LOGGER_VAR(a);
  LOGGER_VAR(b);

  LOGGER_END_METHOD;
}

void loop() {}

void sendMessages() {
  Logger.errorln(F("Hello World!"));
  Logger.warningln(F("Hello World!"));
  Logger.infoln(F("Hello World!"));
  Logger.verboseln(F("Hello World!"));
}
```

## Log Levels

**UtilifyLogger** supports the following log levels:

- **INFO**: General information messages.
- **VERBODE**: Detailed debug messages.
- **WARNING**: Non-critical error messages.
- **ERROR**: Critical error messages.

You can adjust the log level using:

```cpp
Logger.setLoggerLevel(DEBUG);
```

---

## Example Output

Here's an example of what you might see in the serial monitor:

```
00:00:00.000 - VERBOSE: examples/general/main.cpp(16) - setup: begin
00:00:00.008 - VERBOSE: examples/general/main.cpp(20) - setup - i = 0
00:00:00.081 - Setting logger level to ERROR and printing tests...
00:00:00.152 - ERROR: Hello World!
00:00:00.190 - Setting logger level to WARNING and printing tests...
00:00:00.263 - ERROR: Hello World!
00:00:00.301 - WARNING: Hello World!
00:00:00.340 - Setting logger level to INFO and printing tests...
00:00:00.410 - ERROR: Hello World!
00:00:00.448 - WARNING: Hello World!
00:00:00.488 - INFO: Hello World!
00:00:00.524 - Setting logger level to VERBOSE and printing tests...
00:00:00.598 - ERROR: Hello World!
00:00:00.634 - WARNING: Hello World!
00:00:00.674 - INFO: Hello World!
00:00:00.711 - VERBOSE: Hello World!
00:00:00.751 - VERBOSE: examples/general/main.cpp(41) - setup - a = 42
00:00:00.827 - VERBOSE: examples/general/main.cpp(42) - setup - b = Hello World!
00:00:00.912 - VERBOSE: examples/general/main.cpp(44) - setup: end
```

## Dependencies

The library depends on the following:

- Utilify: Core utilities for string manipulation and device-specific operations.

## Author

**Pierre-François Léon**  
🔗 [Linkedin](https://www.linkedin.com/in/pierrefrancoisleon/)  
🔗 [GitHub Profile](https://github.com/PiFou86)
