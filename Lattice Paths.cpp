#include <iostream>
#include <vector>
using namespace std;

//ceck if (i, j) is valid matrix coordinate
bool isValid(int i, int j, int M, int N){
    return(i >= 0 && i < M && j >= 0 && j < N);
}