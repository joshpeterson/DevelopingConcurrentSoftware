#ifndef __MOCK_CLASS_H
#define __MOCK_CLASS_H

class mock_class
{
public:
	mock_class()
	{
		clear_trackers();
		constructed_ = true;
	}

	~mock_class()
	{
		deleted_ = true;
	}

	static bool constructor_called()
	{
		return constructed_;
	}

	static bool destructor_called()
	{
		return deleted_;
	}

	static void clear_trackers()
	{
		constructed_ = false;
		deleted_ = false;
	}

private:
	static bool constructed_;
	static bool deleted_;
};

#endif __MOCK_CLASS_H