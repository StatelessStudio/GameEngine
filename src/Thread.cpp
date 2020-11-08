#include "Thread.h"

namespace SSGE
{

void Thread::start()
{
	thread.start(this);
}

void Thread::stop()
{
	isStopped = true;
	thread.join();
}

void Thread::run()
{
	throw "Must implement run() method of thread";
}

} // namespace SSGE
