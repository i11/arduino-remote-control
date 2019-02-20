#ifndef Logger_h
#define Logger_h

#ifdef __cplusplus
extern "C"
{
#endif

#include "stringify.h"
#define CLASS_SERIAL_LOGGER 1
#define CLASS_NOOP_LOGGER 2

  // class Level {
  //     public:
  //         enum Value : uint8_t {
  //             INFO,
  //             DEBUG,
  //             WARNING,
  //             ERROR
  //         };

  //         const char* toString() const {
  //             return stringify(value);
  //         }

  //         Level() = default;
  //         constexpr Level(Value level) : value(level) { }

  //         bool operator==(Level a) const { return value == a.value; }
  //         bool operator!=(Level a) const { return value != a.value; }

  //     private:
  //         Value value;
  // };

  class Logger
  {
  private:
    const char *name;

  protected:
    Logger(const char *);
    void assign(const Logger &a);
    virtual void log(const char *) const = 0;

  public:
    void info(const char *) const;
    void debug(const char *) const;
    void warning(const char *) const;
    void error(const char *) const;

    static const Logger *create(void *);
    static const Logger *create(const char *);
    static const Logger *create(const char *, unsigned char);

    virtual unsigned char classType() const = 0;

    virtual ~Logger() throw() {}

    virtual Logger &operator=(const Logger &logger)
    {
      assign(logger);
      return *this;
    }
  };

#ifdef __cplusplus
}
#endif

#endif