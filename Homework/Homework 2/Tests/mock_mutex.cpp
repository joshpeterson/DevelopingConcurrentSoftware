#include "mock_mutex.h"

bool mock_mutex::lock_called_ = false;
bool mock_mutex::unlock_called_ = false;