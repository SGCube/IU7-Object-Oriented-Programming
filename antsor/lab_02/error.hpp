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
		std::string fname, std::string cname, std::string mname, const std::string& msg):
		timePoint(time),
		fileName(std::move(fname)),
		className(std::move(cname)),
		method(std::move(mname)),
			message(std::move(msg)) {}

    virtual const char* what() const noexcept override
    {
        return errorMsg().c_str();
    }

private:
    std::chrono::time_point<std::chrono::system_clock> timePoint;
    std::string fileName;
    std::string className;
    std::string method;
    std::string message;

    virtual std::string errorMsg() const
    {
        auto time = std::chrono::system_clock::to_time_t(timePoint);
        std::stringstream s;
        s << time;
		std::string msg = "List error!\nTime: " + s.str() + "\nFile: " + fileName + "\nClass : " + className +
			"\nMethod: " + method +
			"\nError: " + message;
        return msg;
    }
};

class ErrorMemory : public Error
{
public:
	explicit ErrorMemory(std::chrono::time_point<std::chrono::system_clock> time,
		std::string fname, std::string cname, std::string mname) :
		Error(time, fname, cname, mname, msg) {}
private:
    static constexpr const char* msg = "Memory allocation error";
};

class ErrorEmptyList : public Error
{
public:
	explicit ErrorEmptyList(std::chrono::time_point<std::chrono::system_clock> time,
		std::string fname, std::string cname, std::string mname) :
		Error(time, fname, cname, mname, msg) {}
private:
	static constexpr const char* msg = "Memory allocation error";
};

class ErrorOutOfListRange : public Error
{
public:
	explicit ErrorOutOfListRange(std::chrono::time_point<std::chrono::system_clock> time,
		std::string fname, std::string cname, std::string mname) :
		Error(time, fname, cname, mname, msg) {}
private:
    static constexpr const char* msg = "Out of list range";
};

#endif //ERROR_HPP
