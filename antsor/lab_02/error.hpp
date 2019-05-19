#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>
#include <string>
#include <chrono>
#include <cstring>
#include <sstream>

class Error : public std::exception
{
public:
    Error(std::chrono::time_point<std::chrono::system_clock> time,
          std::string fileName, std::string className, std::string method, const std::string& msg):
            timePoint(time),
            filename(std::move(fileName)),
            classname(std::move(className)),
            method(std::move(method),
            message(std::move(msg));

    virtual const char* what() const noexcept override
    {
        return errorMsg().c_str();
    }

protected:
    std::chrono::time_point<std::chrono::system_clock> timePoint;
    std::string filename;
    std::string classname;
    std::string method;
    std::string message;

    virtual std::string errorMsg() const
    {
        auto time = std::chrono::system_clock::to_time_t(timePoint);
        std::stringstream s;
        s << time;
        return "List error!" +
               "\nTime: " + s.str() +
               "\nFile: " + fileName +
               "\nClass: " + className +
               "\nMethod: " + method +
               "\nError: " + message;
    }
};

class ErrorMemory : public Error
{
public:
    explicit ErrorMemory(std::chrono::time_point<std::chrono::system_clock> time,
                         std::string fileName, std::string className,
                         std::string method) :
                         Error(time, fileName, className, method, msg) {}
private:
    static constexpr const char* msg = "Memory allocation error";
};

class ErrorEmptyList : public Error
{
public:
    explicit ErrorMemory(std::chrono::time_point<std::chrono::system_clock> time,
                         std::string fileName, std::string className,
                         std::string method) :
                         Error(time, fileName, className, method, msg) {}
private:
    static constexpr const char* msg = "List is empty";
};

class ErrorOutOfListRange : public Error
{
public:
    explicit ErrorMemory(std::chrono::time_point<std::chrono::system_clock> time,
                         std::string fileName, std::string className,
                         std::string method) :
                         Error(time, fileName, className, method, msg) {}
private:
    static constexpr const char* msg = "Out of list range";
};

#endif //ERROR_HPP
