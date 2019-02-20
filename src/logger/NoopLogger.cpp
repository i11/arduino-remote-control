#include "logger/NoopLogger.h"

NoopLogger::NoopLogger(const char *name) : Logger(name)
{
}

void NoopLogger::log(const char *msg) const
{
  printf("%s\n", msg);
}

void NoopLogger::assign(const NoopLogger &logger)
{
  Logger::assign(logger); // Let A's assign() copy members of A from b to this
  // copy members of B from b to this
}

unsigned char NoopLogger::classType() const {
  return CLASS_NOOP_LOGGER;
}