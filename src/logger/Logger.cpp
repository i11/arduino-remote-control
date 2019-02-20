#include "logger/Logger.h"
#ifdef ARDUINO
#include "logger/SerialLogger.h"
#endif
#include "logger/NoopLogger.h"
#include "asprintf.h"

Logger::Logger(const char *name)
{
    this->name = name;
}

void Logger::assign(const Logger &logger)
{
    this->name = logger.name;
}

const Logger *Logger::create(const char *name)
{
    return new NoopLogger(name);
}

const Logger *Logger::create(const char *name, unsigned char loggerType)
{
    switch(loggerType) {
        case CLASS_NOOP_LOGGER:
            return Logger::create(name);
        case CLASS_SERIAL_LOGGER:
            return new SerialLogger(name);
    }
    return nullptr;
}

const Logger *Logger::create(void *__)
{
    return Logger::create(stringify(__));
}

void Logger::info(const char *msg) const
{
    char *_msg = NULL;
    asprintf(&_msg, "%s %s - %s", "INFO", this->name, msg);
    log(_msg);
    free(_msg);
}

void Logger::debug(const char *msg) const
{
    char *_msg = NULL;
    asprintf(&_msg, "%s %s - %s", "DEBUG", this->name, msg);
    log(_msg);
    free(_msg);
}

void Logger::warning(const char *msg) const
{
    char *_msg = NULL;
    asprintf(&_msg, "%s %s - %s", "WARNING", this->name, msg);
    log(_msg);
    free(_msg);
}

void Logger::error(const char *msg) const
{
    char *_msg = NULL;
    asprintf(&_msg, "%s %s - %s", "ERROR", this->name, msg);
    log(_msg);
    free(_msg);
}