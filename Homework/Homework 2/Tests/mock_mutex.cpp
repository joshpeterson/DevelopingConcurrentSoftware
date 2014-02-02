// This file was copied from the example code QueueExample

#include "mock_mutex.h"

bool mock_mutex::lock_called_ = false;
bool mock_mutex::unlock_called_ = false;