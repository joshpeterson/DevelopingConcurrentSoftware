#include "test.h"
#include "../Library/matrix.h"
#include "../Library/matrix_column_iterator.h"

Define(MatrixColumnIterator)
{
    It ("Can be dereferenced")
    {
        std::vector<double> expected_column = { 3.14, 2.72 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_column_iterator<double>(&test_matrix);

        AssertElementsEqual(expected_column, *it);
    } Done

    It ("Can be incremented")
    {
        std::vector<double> expected_column = { 1.0, 8.9 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_column_iterator<double>(&test_matrix);
        ++it;

        AssertElementsEqual(expected_column, *it);
    } Done

    It ("Can be incremented more than once")
    {
        std::vector<double> expected_column = { 5.2, 2.4 };

        matrix<double> test_matrix = { { 3.14, 1.0, 5.2 }, { 2.72, 8.9, 2.4 } };
        auto it = matrix_column_iterator<double>(&test_matrix);
        ++it;
        it++;

        AssertElementsEqual(expected_column, *it);
    } Done

    It ("Post increment returns previous value")
    {
        std::vector<double> expected_column = { 3.14, 2.72 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_column_iterator<double>(&test_matrix);

        auto post_incremented = it++;

        AssertElementsEqual(expected_column, *post_incremented);
    } Done

    It ("Pre increment returns next value")
    {
        std::vector<double> expected_column = { 1.0, 8.9 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_column_iterator<double>(&test_matrix);
        auto pre_incremement = ++it;

        AssertElementsEqual(expected_column, *pre_incremement);
    } Done

    It ("Signals the end iterator")
    {
        auto end = matrix_column_iterator<double>();

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_column_iterator<double>(&test_matrix);
        ++it;
        ++it;

        AssertTrue(end == it);
    } Done
}
