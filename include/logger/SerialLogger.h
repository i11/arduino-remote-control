#ifndef SerialLogger_h
#define SerialLogger_h

#ifdef __cplusplus
extern "C"
{
#endif

#include "Logger.h"
#include "types.h"
#include <stdio.h>

  class SerialLogger : public Logger
  {
  protected:
    void log(const char *) const;
    void assign(const SerialLogger &logger);

  public:
    SerialLogger(const char *);
    unsigned char classType() const;
    virtual SerialLogger &operator=(const Logger &logger)
    {
      if ((&logger)->classType() == CLASS_SERIAL_LOGGER)
      {
        const SerialLogger *serialLogger = (const SerialLogger *)&logger;
        assign(*serialLogger);
      }
      else
      {
        printf("ERROR: Failed casting given logger to SerialLogger!\n");
      }
      return *this;
    }
  };

#ifdef __cplusplus
}
#endif

#endif