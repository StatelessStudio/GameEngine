#pragma once

namespace SSGE
{

class Engine
{
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
