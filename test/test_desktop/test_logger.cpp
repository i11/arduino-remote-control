#ifdef UNIT_TEST

#include <unity.h>
#include "logger/Logger.h"
#undef SERIAL_LOGGER

const Logger *logger;

void setUp(void)
{
    logger = Logger::create("test-logger");
}

void tearDown(void)
{
    logger = nullptr;
}

void test_logger_info(void)
{
    logger->info("Testing info...");
    logger->info("1");
    logger->info("2");
    logger->info("3");
}

void test_logger_debug(void)
{
    logger->debug("Testing debug...");
    logger->debug("1");
    logger->debug("2");
    logger->debug("3");
}

void test_logger_warning(void)
{
    logger->warning("Testing warning...");
    logger->warning("1");
    logger->warning("2");
    logger->warning("3");
}

void test_logger_error(void)
{
    logger->error("Testing error...");
    logger->error("1");
    logger->error("2");
    logger->error("3");
}

void process()
{
    UNITY_BEGIN();
    RUN_TEST(test_logger_info);
    RUN_TEST(test_logger_warning);
    RUN_TEST(test_logger_debug);
    RUN_TEST(test_logger_error);
    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    process();
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else

int main(int argc, char **argv)
{
    process();
    return 0;
}

#endif

#endif