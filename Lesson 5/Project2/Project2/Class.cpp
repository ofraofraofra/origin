#include "Class.h"

	Counter::Counter(int count) {
		this->count = count;
	}
	Counter::Counter() {
		this->count = 1;
	}
	void Counter::increase()
	{
		++count;
	}
	void Counter::decrease()
	{
		--count;
	}
	int Counter::get_count()
	{
		return count;
	}
	int Counter::set_count(int count)
	{
		return this->count = count;
	}

