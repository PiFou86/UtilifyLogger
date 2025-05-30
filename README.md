# UtilifyLogger

**UtilifyLogger** is a lightweight and efficient logging library designed for embedded systems, including ESP32 and Arduino Uno. It provides configurable log levels, making it easier to monitor and debug embedded applications.

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
00:00:00.000 - Setting logger level to ERROR and printing tests...
00:00:00.005 - ERROR: Hello World!
00:00:00.043 - Setting logger level to WARNING and printing tests...
00:00:00.115 - ERROR: Hello World!
00:00:00.152 - WARNING: Hello World!
00:00:00.192 - Setting logger level to INFO and printing tests...
00:00:00.262 - ERROR: Hello World!
00:00:00.299 - WARNING: Hello World!
00:00:00.338 - INFO: Hello World!
00:00:00.375 - Setting logger level to VERBOSE and printing tests...
00:00:00.448 - ERROR: Hello World!
00:00:00.485 - WARNING: Hello World!
00:00:00.525 - INFO: Hello World!
00:00:00.561 - VERBOSE: Hello World!
00:00:00.601 - VERBOSE: src/main.cpp - setup: @35 - a = 42
00:00:00.663 - VERBOSE: src/main.cpp - setup: @36 - b = Hello World!
00:00:00.736 - VERBOSE: src/main.cpp - setup: end
```

## Dependencies

The library depends on the following:

- Utilify: Core utilities for string manipulation and device-specific operations.

## Author

**Pierre-François Léon**  
🔗 [Linkedin](https://www.linkedin.com/in/pierrefrancoisleon/)  
🔗 [GitHub Profile](https://github.com/PiFou86)
