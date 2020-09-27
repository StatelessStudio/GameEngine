#include "Engine.h"

#include <chrono>
#include <iostream>

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

namespace SSGE
{

Engine::Engine()
{
	std::cout << "Engine Started!" << std::endl;
	shouldRun = true;
}

Engine::~Engine()
{
	std::cout << "Engine Teardown!" << std::endl;
}

unsigned __int64 Engine::getTime()
{
	return duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()
	).count();
}

} // namespace SSGE
