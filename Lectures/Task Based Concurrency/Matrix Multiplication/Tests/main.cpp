#include <iostream>
#include <ctime>
#include "test.h"

int main(int argc, char** argv)
{
    bool all_tests_passed__ = true;
    int number_of_tests_run = 0;

    // Add RUN_TEST_FIXTURE statements here to run tests.
    RUN_TEST_FIXTURE(Matrix)
    RUN_TEST_FIXTURE(MatrixElementIterator)
    RUN_TEST_FIXTURE(MatrixRowIterator)
    RUN_TEST_FIXTURE(MatrixColumnIterator)
    RUN_TEST_FIXTURE(ParallelTask)

	if (all_tests_passed__)
	{
		std::cout << "All tests passed\n";
	}

	std::cout << "Press any key to continue...\n";
	std::getchar();

    return all_tests_passed__ ? 0 : 1;
}

void AssertEqual(std::string expected, std::string actual)
{
    if (expected != actual)
    {
        std::stringstream message;
        message << "\t\t\tExpected: " << expected << std::endl;
        message << "\t\t\tActual:   " << actual << std::endl;

        if (expected.size() != actual.size())
        {
            message << "\t\t\tStrings differ in length, expected: " << expected.size() << " actual: " << actual.size() << std::endl;
        }
        else
        {
            message << "\t\t\t          ";
            for (size_t i = 0; i < expected.size(); ++i)
            {
                if (expected[i] != actual[i])
                {
                    message << "^" << std::endl;
                    message << "\t\t\tStrings differ at index " << i << std::endl;
                    break;
                }
                message << " ";
            }
        }

        throw test_assertion_failed_exception__(message.str().c_str());
    }
}

void AssertTrue(bool value)
{
    if (!value)
    {
        std::stringstream message;
        message << "\t\t\tExpected true, but was false" << std::endl;

        throw test_assertion_failed_exception__(message.str().c_str());
    }
}

void AssertFalse(bool value)
{
    if (value)
    {
        std::stringstream message;
        message << "\t\t\tExpected false, but was true" << std::endl;

        throw test_assertion_failed_exception__(message.str().c_str());
    }
}

