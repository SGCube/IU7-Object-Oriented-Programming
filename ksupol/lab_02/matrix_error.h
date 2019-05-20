#ifndef __MATRIX__ERROR__H__
#define __MATRIX__ERROR__H__

#include <exception>

class col_out_of_range_exception : std::exception
{
	public:
		const char *what() const noexcept
			return "Error! Column is out of range!";
};

class row_out_of_range_exception : std::exception
{
	public:
		const char *what() const noexcept
			return "Error! Row is out of range!";
};

#endif