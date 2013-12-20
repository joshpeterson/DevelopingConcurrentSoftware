#include "test.h"
#include "../Library/matrix.h"
#include "../Library/matrix_row_iterator.h"

Define(MatrixRowIterator)
{
    It ("Can be dereferenced")
    {
        std::vector<double> expected_row = { 3.14, 1.0 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_row_iterator<double>(&test_matrix);

        AssertElementsEqual(expected_row, *it);
    } Done

    It ("Can be incremented")
    {
        std::vector<double> expected_row = { 2.72, 8.9 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_row_iterator<double>(&test_matrix);
        ++it;

        AssertElementsEqual(expected_row, *it);
    } Done

    It ("Can be incremented more than once")
    {
        std::vector<double> expected_row = { 1.98, 75.3 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 }, { 1.98, 75.3 } };
        auto it = matrix_row_iterator<double>(&test_matrix);
        ++it;
        it++;

        AssertElementsEqual(expected_row, *it);
    } Done

    It ("Post increment returns previous value")
    {
        std::vector<double> expected_row = { 3.14, 1.0 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_row_iterator<double>(&test_matrix);

        auto post_incremented = it++;

        AssertElementsEqual(expected_row, *post_incremented);
    } Done

    It ("Pre increment returns next value")
    {
        std::vector<double> expected_row = { 2.72, 8.9 };

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_row_iterator<double>(&test_matrix);
        auto pre_incremement = ++it;

        AssertElementsEqual(expected_row, *pre_incremement);
    } Done

    It ("Signals the end iterator")
    {
        auto end = matrix_row_iterator<double>();

        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };
        auto it = matrix_row_iterator<double>(&test_matrix);
        ++it;
        ++it;

        AssertTrue(end == it);
    } Done
}
