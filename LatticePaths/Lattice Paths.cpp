#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <chrono>
using namespace std;

#define R 21
#define C 21

u_int num = 0;
u_int counter = 0;

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

// function for printing vector of vectors
auto print_vector(vector<vector<int>> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << endl;
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j];
        }
    }
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


    // initialize a vector  of vectors
    vector<vector<int>> testvec(R, vector<int>(C));

    // print vector of vectors
    //print_vector(testvec);

    auto start = chrono::system_clock::now();
    
    findPath(testvec, path, x, y);

    auto end = chrono::system_clock::now();

    cout << endl;

    cout << num << endl;

    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
