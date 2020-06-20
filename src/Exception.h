#pragma once
#include <exception>

namespace SSGE
{

class Exception : public std::exception
{

protected:
	/** Error message */
	const char* message;

public:
	/**
	 * Exception
	 * @param {const char*} _message Error message
	 */
	Exception(const char* _message);

	/**
	 * Destructor
	 */
	~Exception();

	/**
	 * Get the error message
	 * 
	 * @return {const char*} Returns the error message
	 */
	const char* what();
};

} // namespace SSGE
