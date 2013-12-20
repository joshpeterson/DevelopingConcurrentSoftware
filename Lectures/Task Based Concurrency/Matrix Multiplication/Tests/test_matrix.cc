#include <stdexcept>
#include <iostream>
#include "test.h"
#include "../Library/matrix.h"

matrix<double> test_move();

Define(Matrix)
{
    It("Can be created with and initializer list")
    {
        matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9 } };

        AssertEqual<size_t>(2, test_matrix.rows());
        AssertEqual<size_t>(2, test_matrix.columns());
    } Done

    It("Can be created with and initializer list and dimensions that are not the same")
    {
        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };

        AssertEqual<size_t>(2, test_matrix.rows());
        AssertEqual<size_t>(3, test_matrix.columns());
    } Done

    It("Throws an exception when created with invalid dimensions")
    {
        bool exception_occurred = false;
        try
        {
            matrix<double> test_matrix = { { 3.14, 1.0 }, { 2.72, 8.9, 5.42} };
        }
        catch (const std::invalid_argument&)
        {
            exception_occurred = true;
        }
        
        AssertTrue(exception_occurred);
    } Done

    It("Can be indexed")
    {
        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
        AssertEqual(3.14, test_matrix(1,1));
    } Done

    It("Can be indexed with different row and column indexes")
    {
        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
        AssertEqual(5.42, test_matrix(2,3));
    } Done

    It("Throws an exception for a large column index")
    {
        bool exception_occurred = false;
        try
        {
            matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
            test_matrix(1,4);
        }
        catch (const std::invalid_argument&)
        {
            exception_occurred = true;
        }
        AssertTrue(exception_occurred);
    } Done

    It("Throws an exception for a large row index")
    {
        bool exception_occurred = false;
        try
        {
            matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
            test_matrix(5,3);
        }
        catch (const std::invalid_argument&)
        {
            exception_occurred = true;
        }
        AssertTrue(exception_occurred);
    } Done

    It("Throws an exception for a zero column index")
    {
        bool exception_occurred = false;
        try
        {
            matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
            test_matrix(1,0);
        }
        catch (const std::invalid_argument&)
        {
            exception_occurred = true;
        }
        AssertTrue(exception_occurred);
    } Done

    It("Throws an exception for a zero row index")
    {
        bool exception_occurred = false;
        try
        {
            matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
            test_matrix(0,2);
        }
        catch (const std::invalid_argument&)
        {
            exception_occurred = true;
        }
        AssertTrue(exception_occurred);
    } Done

    It("Provides a starting iterator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
        auto it = test_matrix.begin();

        AssertEqual(3.14, *it);
    } Done

    It("Provides an ending iterator")
    {
        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
        auto it = test_matrix.end();
    } Done

    It("Can be iterated")
    {
        std::vector<double> expected = { 3.14, 1.0, 3.19, 2.72, 8.9, 5.42 };
        std::vector<double> actual;

        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };

        std::copy(test_matrix.begin(), test_matrix.end(), std::back_inserter(actual));

        AssertElementsEqual(expected, actual);
    } Done

    It("Has a move constructor")
    {
        matrix<double> expected = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
        matrix<double> actual = test_move();
        AssertElementsEqual(expected, actual);
    } Done

    It("Can be constructed with a given size")
    {
        matrix<double> test_matrix(3,4);
        AssertEqual<size_t>(3, test_matrix.rows());
        AssertEqual<size_t>(4, test_matrix.columns());
    } Done

    It("Allows elements to be modified")
    {
        matrix<double> test_matrix(3,4);
        test_matrix(1,1) = 1;
    } Done

    It("Can be iterated by row")
    {
        std::vector<double> expected_row_0 = { 3.14, 1.0, 3.19 };
        std::vector<double> expected_row_1 = { 2.72, 8.9, 5.42};

        std::vector<std::vector<double>> actual_rows;

        matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
        for (auto it = test_matrix.row_begin(); it != test_matrix.row_end(); ++it)
        {
            actual_rows.push_back(*it);
        }

        AssertElementsEqual(expected_row_0, actual_rows[0]);
        AssertElementsEqual(expected_row_1, actual_rows[1]);
    } Done

    It("Can be iterated by column")
    {
        std::vector<double> expected_column_0 = { 3.14, 2.72, 12.04 };
        std::vector<double> expected_column_1 = { 1.0, 8.9, 23.5 };
        std::vector<double> expected_column_2 = { 3.19, 5.42, 287 };
        std::vector<double> expected_column_3 = { 3.17, 2.13, 9.7 };

        std::vector<std::vector<double>> actual_columns;

        matrix<double> test_matrix = { { 3.14, 1.0, 3.19, 3.17 }, { 2.72, 8.9, 5.42, 2.13 }, { 12.04, 23.5, 287, 9.7 }  };
        for (auto it = test_matrix.column_begin(); it != test_matrix.column_end(); ++it)
        {
            actual_columns.push_back(*it);
        }

        AssertElementsEqual(expected_column_0, actual_columns[0]);
        AssertElementsEqual(expected_column_1, actual_columns[1]);
        AssertElementsEqual(expected_column_2, actual_columns[2]);
        AssertElementsEqual(expected_column_3, actual_columns[3]);
    } Done
}

matrix<double> test_move()
{
    matrix<double> test_matrix = { { 3.14, 1.0, 3.19 }, { 2.72, 8.9, 5.42} };
    return test_matrix;
}
