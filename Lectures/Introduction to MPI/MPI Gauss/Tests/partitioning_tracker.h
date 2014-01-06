#ifndef __PARTITIONING_TRACKER_H
#define __PARTITIONING_TRACKER_H

class PartitioningTracker
{
public:
    PartitioningTracker() : partitioning_method_called_(false)
    {
    }

    std::vector<std::pair<unsigned int, unsigned int>> partition(unsigned int begin, unsigned int end, int number_of_partitions)
    {
        partitioning_method_called_ = true;
        begin_integer_ = begin;
        end_integer_ = end;
        number_of_partitions_ = number_of_partitions;
        return std::vector<std::pair<unsigned int, unsigned int>>();
    }

    bool GetPartitioningMethodCalled() const
    {
        return partitioning_method_called_;
    }

    int GetBeginInteger() const
    {
        return begin_integer_;
    }

    int GetEndInteger() const
    {
        return end_integer_;
    }

    int GetNumberOfPartitions() const
    {
        return number_of_partitions_;
    }

private:
    bool partitioning_method_called_;
    int begin_integer_;
    int end_integer_;
    int number_of_partitions_;
};

#endif // __PARTITIONING_TRACKER_H
