#ifndef __MOCK_TASK_H
#define __MOCK_TASK_H

#include <vector>

class MockTask
{
public:
    MockTask() : begin_value_(0), end_value_(0), reduce_input_value_(0) {}

    void map(unsigned int begin, unsigned int end)
    {
        begin_value_ = begin;
        end_value_ = end;

        latest_begin_value_from_any_instance_ = begin;
        latest_end_value_from_any_instance_ = end;
    }

    unsigned int reduce(unsigned int input)
    {
        reduce_input_value_ = input;

        latest_reduce_input_value_from_any_instance_ = input;

        return 42;
    }

    unsigned int GetBeginValue() const { return begin_value_; }
    unsigned int GetEndValue() const { return end_value_; }
    
    unsigned int GetReduceInputValue() const { return reduce_input_value_; }

    unsigned int GetLatestBeginValueFromAnyInstance() const { return latest_begin_value_from_any_instance_; }
    unsigned int GetLatestEndValueFromAnyInstance() const { return latest_end_value_from_any_instance_; }

    unsigned int GetLatestReduceInputValueFromAnyInstance() const { return latest_reduce_input_value_from_any_instance_; }

    static void ClearLatestValuesFromAnyInstance()
    {
        latest_begin_value_from_any_instance_ = 0;
        latest_end_value_from_any_instance_ = 0;

        latest_reduce_input_value_from_any_instance_ = UINT_MAX;
    }

private:
    unsigned int begin_value_;
    unsigned int end_value_;

    unsigned int reduce_input_value_;

    static unsigned int latest_begin_value_from_any_instance_;
    static unsigned int latest_end_value_from_any_instance_;

    static unsigned int latest_reduce_input_value_from_any_instance_;
};

#endif // __MOCK_TASK_H
