#include "test.h"
#include "../Library/matrix.h"
#include "../Library/matrix_element_iterator.h"

Define(MatrixElementIterator)
{
    It ("Can be dreferenced")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        AssertEqual(3.14, *it);
    } Done

    It ("Can be post incremented")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        it++;
        AssertEqual(1.0, *it);
    } Done

    It ("Can be post incremented to the second row")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        it++;
        it++;
        AssertEqual(2.72, *it);
    } Done

    It ("Returns the previous value for post increment")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        AssertEqual(3.14, *(it++));
    } Done

    It ("Can be pre incremented")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        ++it;
        AssertEqual(1.0, *it);
    } Done

    It ("Can be pre incremented to the second row")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        ++it;
        ++it;
        AssertEqual(2.72, *it);
    } Done

    It ("Returns the new value for pre increment")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        AssertEqual(1.0, *(++it));
    } Done

    It ("Can be default constructed")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        matrix_element_iterator<double> it;
    } Done

    It ("Can be compared to another matrix_element_iterator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        auto it2 = matrix_element_iterator<double>(&test_matrix);

        AssertTrue(it.equal(it2));
    } Done

    It ("Can be compared to a different matrix_element_iterator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        auto it2 = matrix_element_iterator<double>(&test_matrix);

        ++it2;

        AssertFalse(it.equal(it2));
    } Done

    It ("Can be compared to a default constructed matrix_element_iterator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        matrix_element_iterator<double> it; 
        matrix_element_iterator<double> it2; 

        AssertTrue(it.equal(it2));
    } Done

    It ("Is not equal to a default constructed matrix_element_iterator when it is not default constructed")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        matrix_element_iterator<double> it2; 

        AssertFalse(it.equal(it2));
    } Done

    It ("Can be compared to another matrix_element_iterator with the equality operator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        auto it2 = matrix_element_iterator<double>(&test_matrix);

        AssertTrue(it == it2);
    } Done

    It ("Can be iterated to the end matrix_element_iterator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_element_iterator<double>(&test_matrix);
        matrix_element_iterator<double> end;

        ++it;
        ++it;
        ++it;
        ++it;

        AssertTrue(it == end);
    } Done
}
