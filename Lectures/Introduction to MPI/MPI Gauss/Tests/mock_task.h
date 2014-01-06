#ifndef __MOCK_TASK_H
#define __MOCK_TASK_H

#include <vector>

class MockTask
{
public:
    MockTask() : begin_value_(0), end_value_(0), numUnique_value_(0), numNonunique_value_(0), numNo_value_(0) {}

    void map(unsigned int begin, unsigned int end)
    {
        begin_value_ = begin;
        end_value_ = end;

        latest_begin_value_from_any_instance_ = begin;
        latest_end_value_from_any_instance_ = end;
    }

    std::vector<unsigned int> reduce(const std::vector<unsigned int>& input)
    {
        numUnique_value_ = input.size() == 3 ? input[0] : 0;
        numNonunique_value_ = input.size() == 3 ? input[1] : 0;
        numNo_value_ = input.size() == 3 ? input[2] : 0;

        latest_numUnique_value_from_any_instance_ = input.size() == 3 ? input[0] : 0;
        latest_numNonunique_value_from_any_instance_ = input.size() == 3 ? input[1] : 0;
        latest_numNo_value_from_any_instance_ = input.size() == 3 ? input[2] : 0;

        std::vector<unsigned int> result;
        result.emplace_back(42);
        result.emplace_back(43);
        result.emplace_back(44);

        return result;
    }

    unsigned int GetBeginValue() const { return begin_value_; }
    unsigned int GetEndValue() const { return end_value_; }

    unsigned int GetNumUniqueValue() const { return numUnique_value_; }
    unsigned int GetNumNonuniqueValue() const { return numNonunique_value_; }
    unsigned int GetNumNoValue() const { return numNo_value_; }

    unsigned int GetLatestBeginValueFromAnyInstance() const { return latest_begin_value_from_any_instance_; }
    unsigned int GetLatestEndValueFromAnyInstance() const { return latest_end_value_from_any_instance_; }

    unsigned int GetLatestNumUniqueValueFromAnyInstance() const { return latest_numUnique_value_from_any_instance_; }
    unsigned int GetLatestNumNonuniqueValueFromAnyInstance() const { return latest_numNonunique_value_from_any_instance_; }
    unsigned int GetLatestNumNoValueFromAnyInstance() const { return latest_numNo_value_from_any_instance_; }

    static void ClearLatestValuesFromAnyInstance()
    {
        latest_begin_value_from_any_instance_ = 0;
        latest_end_value_from_any_instance_ = 0;

        latest_numUnique_value_from_any_instance_ = UINT_MAX;
        latest_numNonunique_value_from_any_instance_ = UINT_MAX;
        latest_numNo_value_from_any_instance_ = UINT_MAX;
    }

private:
    unsigned int begin_value_;
    unsigned int end_value_;

    unsigned int numUnique_value_;
    unsigned int numNonunique_value_;
    unsigned int numNo_value_;

    static unsigned int latest_begin_value_from_any_instance_;
    static unsigned int latest_end_value_from_any_instance_;

    static unsigned int latest_numUnique_value_from_any_instance_;
    static unsigned int latest_numNonunique_value_from_any_instance_;
    static unsigned int latest_numNo_value_from_any_instance_;
};

#endif // __MOCK_TASK_H
