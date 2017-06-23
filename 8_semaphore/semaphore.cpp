#include"semaphore.h"

void Semaphore::wait()
{
	std::unique_lock<std::mutex> lck(mtx);
	while (count == 0) {
		cv.wait(lck);
	}
	--count;
}

void Semaphore::signal()
{
	std::unique_lock<std::mutex> lck(mtx);
	++count;
	cv.notify_one();
}
