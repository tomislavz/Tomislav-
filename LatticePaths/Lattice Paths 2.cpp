#include <iostream>

int main() {
    // Define the number of rows and columns
    const int rows = 20;
    const int cols = 20;

    // Initialize a 2D array to store the number of paths
    u_int64_t paths[rows][cols];

    // Set the base case: there is only one way to reach any cell in the first row or first column
    for (int i = 0; i < rows; ++i) {
        paths[i][0] = 1;
    }
    for (int j = 0; j < cols; ++j) {
        paths[0][j] = 1;
    }

    // Fill the rest of the array using dynamic programming
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }

    // Print 2D array
    std::cout << "2D array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << paths[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // The number of unique paths to reach the bottom-right corner
    std::cout << "Number of unique paths: " << paths[rows - 1][cols - 1] << std::endl << std::endl;

    return 0;
}
// This code calculates the number of unique paths from the top-left corner to the bottom-right corner of a grid
