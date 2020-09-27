#pragma once

#include <Poco/Thread.h>

namespace SSGE
{

class Engine
{
protected:
	bool isStopped = false;
	Poco::Thread thread;

public:
	bool shouldRun;
	int tickTimeMs = 30;

	Engine();
	~Engine();

	/**
	 * Get epoch time in milliseconds
	 *
	 * @return Time in milliseconds
	 */
	unsigned __int64 getTime();
};

} // namespace SSGE
