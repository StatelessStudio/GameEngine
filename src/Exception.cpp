#pragma once

#include "Exception.h"

namespace SSGE
{


Exception::Exception(const char* _message) : message(_message)
{}

Exception::~Exception() {}


const char* Exception::what()
{
	return message;
}

} // namespace SSGE
