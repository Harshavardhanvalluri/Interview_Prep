#include <iostream>

int main()
{
    int rows = 0;
    int cols = 0;
    int counter = 0;

    std::cout << "Enter rows & columns :" << std::endl;
    std::cin >> rows;
    std::cin >> cols;

    /// Creating matrix
    int** matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }


    /// Assign values to matrix
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = counter;

            if ( ++counter > 9 )
            {
                counter = 0;
            }
        }
    }

    /// print matrix
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << std::endl;
    }
    
    


    return 0;
}
