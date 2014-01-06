#ifndef __MOCK_MPI_ADAPTER_H
#define __MOCK_MPI_ADAPTER_H

#include <mpi.h>
#include "../Library/mpi_adapter_interface.h"

class MockMpiAdapter : public MpiAdapterInterface
{
public:
	MockMpiAdapter() : rank_(0), number_of_times_MpiSend_called_(0), count_in_MpiSend_(0), tag_in_MpiSend_(0), first_integer_value_in_MpiSend_(0),
		second_integer_value_in_MpiSend_(0), third_integer_value_in_MpiSend_(0), destination_(INT_MAX), MpiRecv_called_(false), count_in_MpiRecv_(0), tag_in_MpiRecv_(0)
	{}

	MockMpiAdapter(int rank) : rank_(rank), number_of_times_MpiSend_called_(0), count_in_MpiSend_(0), tag_in_MpiSend_(0), first_integer_value_in_MpiSend_(0),
		second_integer_value_in_MpiSend_(0), third_integer_value_in_MpiSend_(0), destination_(INT_MAX), MpiRecv_called_(false), count_in_MpiRecv_(0), tag_in_MpiRecv_(0)
	{}

	virtual void MpiSend(void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) const
	{
		++number_of_times_MpiSend_called_;
		count_in_MpiSend_ = count;
		tag_in_MpiSend_ = tag;

		auto iterator_values = (const unsigned int*)buf;

		first_integer_value_in_MpiSend_ = iterator_values[0];
		second_integer_value_in_MpiSend_ = iterator_values[1];

		if (count == 3)
			third_integer_value_in_MpiSend_ = iterator_values[2];

		destination_ = dest;
	}

	virtual int MpiCommRank(MPI_Comm comm) const
	{
		return rank_;
	}

	virtual void MpiRecv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status* status) const
	{
		MpiRecv_called_ = true;
		count_in_MpiRecv_ = count;
		tag_in_MpiRecv_ = tag;

		sources_.push_back(source);

		auto output_values = (unsigned int*)buf;
		output_values[0] = 67;
		output_values[1] = 92;

		if (count == 3)
			output_values[2] = 104;
	}

	int GetNumberOfTimesMpiSendCalled() const { return number_of_times_MpiSend_called_; }
	int GetCountInMpiSend() const { return count_in_MpiSend_; }
	int GetTagInMpiSend() const { return tag_in_MpiSend_; }
	unsigned int GetFirstIntegerValueInMpiSend() const { return first_integer_value_in_MpiSend_; }
	unsigned int GetSecondIntegerValueInMpiSend() const { return second_integer_value_in_MpiSend_; }
	unsigned int GetThirdIntegerValueInMpiSend() const { return third_integer_value_in_MpiSend_; }
	int GetDestinationInMpiSend() const { return destination_; }
	bool GetMpiSendCalled() const { return number_of_times_MpiSend_called_ > 0; }
	bool GetMpiRecvCalled() const { return MpiRecv_called_; }
	int GetCountInMpiRecv() const { return count_in_MpiRecv_; }
	int GetTagInMpiRecv() const { return tag_in_MpiRecv_; }
	int GetSourceInMpiRecv() const { return sources_[0]; }
	int GetNumberOfTimesMpiRecvCalled() const { return sources_.size(); }
	std::vector<int> GetSourcesInMpiRecv() const { return sources_; }

private:
	int rank_;
	mutable int number_of_times_MpiSend_called_;
	mutable int count_in_MpiSend_;
	mutable int tag_in_MpiSend_;
	mutable unsigned int first_integer_value_in_MpiSend_;
	mutable unsigned int second_integer_value_in_MpiSend_;
	mutable unsigned int third_integer_value_in_MpiSend_;
	mutable int destination_;
	mutable bool MpiRecv_called_;
	mutable int count_in_MpiRecv_;
	mutable int tag_in_MpiRecv_;
	mutable std::vector<int> sources_;
};

#endif // __MOCK_MPI_ADAPTER_H
