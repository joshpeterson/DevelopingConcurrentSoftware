#ifndef __MOCK_MUTEX_H
#define __MOCK_MUTEX_H

class mock_mutex
{
public:
    mock_mutex()
    {
        clear_lock_trackers();
    }

    void lock()
    {
        lock_called_ = true;
    }

    void unlock()
    {
        unlock_called_ = true;
    }

    bool lock_called()
    {
        return lock_called_;
    }

    bool unlock_called()
    {
        return unlock_called_;
    }

    void clear_lock_trackers()
    {
        lock_called_ = false;
        unlock_called_ = false;
    }

private:
    static bool lock_called_;
    static bool unlock_called_;
};

#endif __MOCK_MUTEX_H