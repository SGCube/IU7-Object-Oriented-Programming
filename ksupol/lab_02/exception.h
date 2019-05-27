#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
#include <time.h>

class Exception : public std::exception
{
public:
    Exception(const time_t time,
              const char *className,
              const char *method,
              const char *extra_mess,
              const char *addInfo = nullptr);

    const char *what() const noexcept override;

protected:
    const time_t time;
    const char *className;
    const char *method;
    const char *extra_mess;
    const char *additionInfo;
};

class exceptOutOfRange : public Exception
{
public:
    exceptOutOfRange(const time_t time,
                 const char *className,
                 const char *method,
                 const char *addInfo = nullptr);
};

class exceptAllocationError : public Exception
{
public:
    exceptAllocationError(const time_t time,
              const char *className,
              const char *method,
              const char *addInfo = nullptr);
};

class exceptWrongSizes : public Exception
{
public:
    exceptWrongSizes(const time_t time,
                const char *className,
                const char *method,
                const char *addInfo = nullptr);
};

class exceptDamagedIterator : public Exception
{
public:
    exceptDamagedIterator(const time_t time,
                 const char *className,
                 const char *method,
                 const char *addInfo = nullptr);
};

class exceptBadPointer :public Exception
{
public:
    exceptBadPointer(const time_t time,
            const char *className,
            const char *method,
            const char *addInfo = nullptr);
};

#endif // EXCEPTION_H
