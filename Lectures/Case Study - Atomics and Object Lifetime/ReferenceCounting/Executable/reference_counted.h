#ifndef __REFERENCE_COUNTED_H
#define __REFERENCE_COUNTED_H

#include <atomic>
#include <iostream>
#include <mutex>

class reference_counted
{
public:
	reference_counted() : count_(0) {}
	void add_reference()
	{
		++count_;
	}

	void release(int call_identifier)
	{
		--count_;
		if (count_ == 0)
		{
			std::lock_guard<std::mutex> lock(m_);
			std::cout << "Release caused zero count for call " << call_identifier << std::endl;
		}
	}
private:
	std::atomic<int> count_;
	std::mutex m_;
};

#endif // __REFERENCE_COUNTED_H