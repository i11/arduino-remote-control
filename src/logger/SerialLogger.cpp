#ifdef ARDUINO

#include "logger/SerialLogger.h"
#include <Arduino.h>

SerialLogger::SerialLogger(const char *name) : Logger(name)
{
}

void SerialLogger::log(const char *msg) const
{
    Serial.println(msg);
}

void SerialLogger::assign(const SerialLogger &logger)
{
    Logger::assign(logger); // Let A's assign() copy members of A from b to this
                            // copy members of B from b to this
}

unsigned char SerialLogger::classType() const
{
    return CLASS_SERIAL_LOGGER;
}

#endif