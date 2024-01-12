#pragma once

class Counter
{
private:

	int count;

public:

	Counter(int count);
	Counter();
	void increase();
	void decrease();
	int get_count();
	int set_count(int count);
};

