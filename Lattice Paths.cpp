#include <iostream>
#include <vector>
using namespace std;

int num = 0;
int counter = 0;

// Check if (i, j) is valid matrix coordinate
bool isValid(int i, int j, int M, int N)
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}

// Print the route token
void printPath(vector<int> const &path, int last)
{
    for (int i : path)
    {
        cout << i << ", ";        
    }
    
    cout << last << endl;
   
}

void findPath(vector<vector<int>> const &mat, vector<int> &path, int i, int j)
{

    // base case
    if (mat.size() == 0)
    {
        return;
    }

    // "M x N" matrix
    int M = mat.size();
    int N = mat[0].size();

    // if the last cell is reached, print the route
    if (i == M - 1 && j == N - 1)
    {
        counter ++;

        if (num < counter){
            num = counter;
        }

        //printPath(path, mat[i][j]);
        return;
    }

    // include the current cell in the path
    path.push_back(mat[i][j]);

    // move right
    if (isValid(i, j + 1, M, N))
    {
        findPath(mat, path, i, j + 1);
    }

    // move down
    if (isValid(i + 1, j, M, N))
    {
        findPath(mat, path, i + 1, j);
    }

    // remove the current cell from the path
    path.pop_back();
}

int main()
{
    vector<vector<int>> mat =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    int x = 0, y = 0;

    vector<int> path;

    findPath(mat, path, x, y);

    cout << num << endl;

    return 0;
}
