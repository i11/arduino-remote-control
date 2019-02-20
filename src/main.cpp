#ifndef UNIT_TEST // disable program main loop while unit testing in progress

#include <Arduino.h>
#include "logger/Logger.h"

const Logger* logger;

void setup() {
  Serial.begin(9600);
  logger = Logger::create("main", CLASS_SERIAL_LOGGER);
  logger->info("Logger setup complete.");
}

void loop() {
  millis();
  logger->info("Looping...");
  delay(1000);
}

#endif