#include "exception.h"
#include "stdio.h"
#include <sstream>


Exception::Exception(const time_t time,
                     const char *className,
                     const char *method,
                     const char *extra_mess,
                     const char *addInfo):
    time(time),
    className(className),
    method(method),
    extra_mess(extra_mess),
    additionInfo(addInfo)
{}

const char *Exception::what() const noexcept
{
    size_t bufsize = 100;
    char *buf = new char [bufsize];

    struct tm *time_struct = localtime(&time);

    size_t row = strftime(buf, bufsize, "%d.%m.%Y\t%H:%M:%S\t", time_struct);
    snprintf(buf + row, bufsize - row, "%s\t%s\t%s\t%s\n",
             className, method, extra_mess, additionInfo);

    return buf;
}


exceptOutOfRange::exceptOutOfRange(const time_t time,
                           const char *className,
                           const char *method,
                           const char *addInfo):
    Exception (time, className, method, "out of range", addInfo){}

exceptAllocationError::exceptAllocationError(const time_t time,
                     const char *className,
                     const char *method,
                     const char *addInfo):
    Exception (time, className, method, "exceptAllocationError", addInfo){}

exceptWrongSizes::exceptWrongSizes(const time_t time,
                     const char *className,
                     const char *method,
                     const char *addInfo):
    Exception (time, className, method, "wrong sizes", addInfo){}

exceptDamagedIterator::exceptDamagedIterator(const time_t time,
                           const char *className,
                           const char *method,
                           const char *addInfo):
    Exception (time, className, method, "damaged iterator", addInfo){}

exceptBadPointer::exceptBadPointer(const time_t time,
                 const char *className,
                 const char *method,
                 const char *addInfo):
    Exception (time, className, method, "exceptBadPointer", addInfo){}
