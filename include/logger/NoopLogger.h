#ifndef NoopLogger_h
#define NoopLogger_h

#ifdef __cplusplus
extern "C"
{
#endif

#include "Logger.h"
#include <stdio.h>

  class NoopLogger : public Logger
  {
  protected:
    void log(const char *) const;
    void assign(const NoopLogger &logger);

  public:
    NoopLogger(const char *);
    unsigned char classType() const;
    virtual NoopLogger &operator=(const Logger &logger)
    {
      if ((&logger)->classType() == CLASS_NOOP_LOGGER)
      {
        const NoopLogger *noopLogger = (const NoopLogger *)&logger;
        assign(*noopLogger);
      }
      else
      {
        printf("ERROR: Failed casting given logger to NoopLogger!\n");
      }
      return *this;
    }
  };

#ifdef __cplusplus
}
#endif

#endif