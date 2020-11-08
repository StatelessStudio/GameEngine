#pragma once

#include <Poco/Runnable.h>
#include <Poco/Thread.h>

namespace SSGE
{

class Thread :
	public Poco::Runnable
{
protected:
	bool isStopped = false;
	Poco::Thread thread;

public:
	/**
	 * Start the thread
	 */
	void start();

	/**
	 * Join the thread
	 */
	void stop();

	/**
	 * Thread worker
	 */
	void run();
};

} // namespace SSGE
