#include <Arduino.h>
#include <Utilify/Logger/Logger.h>

void sendMessages();

void setup() {
  Serial.begin(9600);
  Logger.begin(&Serial);

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