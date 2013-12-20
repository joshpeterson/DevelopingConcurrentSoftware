#ifndef __TEST_H
#define __TEST_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "../Library/matrix.h"
#include "../Library/utility.h"

class test_assertion_failed_exception__ : public std::exception
{
public:
    test_assertion_failed_exception__(const char* message) : message_(message) {}

    ~test_assertion_failed_exception__() throw() {}

    const char* what() const throw()
    {
        return message_.c_str();
    }

private:
    std::string message_;
};

#define RUN_TEST_FIXTURE(test_fixture_name__) \
    std::cout << #test_fixture_name__ << ":" << std::endl;\
    void test_fixture_name__(bool& all_tests_passed__, int& number_of_tests_run);\
    test_fixture_name__(all_tests_passed__, number_of_tests_run);

#define Define(test_fixture_name__) void test_fixture_name__(bool& all_tests_passed__, int& number_of_tests_run)

#define It(test_name__) \
    number_of_tests_run++;\
    std::cout << "\t - " << test_name__ << std::endl;\
    try\

#define Done \
    catch(test_assertion_failed_exception__ &e)\
    {\
        std::cout << "\t\tFailed:" << std::endl;\
        std::cout << e.what() << std::endl;\
        all_tests_passed__ = false;\
    }

void AssertEqual(std::string expected, std::string actual);
void AssertTrue(bool value);
void AssertFalse(bool value);

template <typename ComparisonType>
void AssertEqual(ComparisonType expected, ComparisonType actual)
{
    if (expected != actual)
    {
        std::stringstream message;
        message << "\t\t\tExpected: " << expected << std::endl;
        message << "\t\t\tActual:   " << actual << std::endl;
        throw test_assertion_failed_exception__(message.str().c_str());
    }
}

template <typename ContainerType>
void AssertElementsEqual(ContainerType expected, ContainerType actual)
{
    std::stringstream message;
    if (expected.size() != actual.size())
    {
        message << "\t\t\tVectors differ in length, expected: " << expected.size() << " actual: " << actual.size() << std::endl;

        throw test_assertion_failed_exception__(message.str().c_str());
    }
    else
    {
        for (size_t i = 0; i != expected.size(); ++i)
        {
            if (expected[i] != actual[i])
            {
                message << "\t\t\tVectors differ at index " << i << std::endl;
                message << "\t\t\tExpected: " << expected[i] << std::endl;
                message << "\t\t\tActual:   " << actual[i] << std::endl;

                throw test_assertion_failed_exception__(message.str().c_str());
            }
        }
    }
}

inline void AssertElementsEqual(const matrix<double>& expected, const matrix<double>& actual)
{
    std::stringstream message;
    if (expected.rows() != actual.rows())
    {
        message << "\t\t\tMatrices differ in number of rows, expected: " << expected.rows() << " actual: " << actual.rows() << std::endl;

        throw test_assertion_failed_exception__(message.str().c_str());
    }
    else if (expected.columns() != actual.columns())
    {
        message << "\t\t\tMatrices differ in number of columns, expected: " << expected.columns() << " actual: " << actual.columns() << std::endl;

        throw test_assertion_failed_exception__(message.str().c_str());
    }
    else
    {
        for (size_t i = 1; i <= expected.rows(); ++i)
        {
            for (size_t j = 1; j <= expected.columns(); ++j)
            {
                if (!osoasso::double_equal(expected(i,j), actual(i,j)))
                {
                    osoasso::double_bytes converter;
                    converter.double_value = expected(i,j);
                    message << "\t\t\tMatrices differ at index " << i << "," << j << std::endl;
                    message << "\t\t\tExpected: " << expected(i,j) << " (" << converter.int_value
                            << ")"<< std::endl;
                    converter.double_value = actual(i,j);
                    message << "\t\t\tActual:   " << actual(i,j) << " (" << converter.int_value
                            << ")" << std::endl;

                    throw test_assertion_failed_exception__(message.str().c_str());
                }
            }
        }
    }
}

#endif // __TEST_H

