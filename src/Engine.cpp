#include "Engine.h"

#include <iostream>

namespace SSGE
{

Engine::Engine()
{
	std::cout << "Engine Started!" << std::endl;
}

Engine::~Engine()
{
	std::cout << "Engine Teardown!" << std::endl;
}

} // namespace SSGE
