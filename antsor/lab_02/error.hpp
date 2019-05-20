#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>
#include <string>

class Error : public std::exception
{
public:
    Error(std::string fname, std::string cname, std::string mname, const std::string& msg):
		fileName(std::move(fname)),
		className(std::move(cname)),
		method(std::move(mname)),
			message(std::move(msg)) {}

    virtual const char* what() const noexcept override
    {
		std::string msg = "List error!\n\nFile: " + fileName +
			"\nClass: " + className +
			"\nMethod: " + method +
			"\nError: " + message;

		char *err = new char[msg.size() + 1];
		strcpy_s(err, msg.size() + 1, msg.c_str());
        return err;
    }

private:
    std::string fileName;
    std::string className;
    std::string method;
    std::string message;
};

class ErrorMemory : public Error
{
public:
	explicit ErrorMemory(std::string fname, std::string cname, std::string mname) :
		Error(fname, cname, mname, msg) {}
private:
	static constexpr const char* msg = "Memory allocation error";
};

class ErrorEmptyList : public Error
{
public:
	explicit ErrorEmptyList(std::string fname, std::string cname, std::string mname) :
		Error(fname, cname, mname, msg) {}
	static constexpr const char* msg = "List is empty";
};

class ErrorOutOfListRange : public Error
{
public:
	explicit ErrorOutOfListRange(std::string fname, std::string cname, std::string mname) :
		Error(fname, cname, mname, msg) {}
	static constexpr const char* msg = "Out of list range";
};

#endif //ERROR_HPP
