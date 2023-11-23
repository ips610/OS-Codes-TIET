#include <iostream>
using namespace std;

int findMinimum(int MemoryBlocks[][6], int rows)
{
    int Minimum;
    int NoOfMemoryBlocks = rows;

    for (int i = 0; i < 6; i++)
    {
        
    }

    return Minimum;
}
int main()
{
    int ProcessSize[] = {3, 25, 15, 30};
    int MemoryBlocks[][6] = {{10, 30, 5, 40, 20, 8}, {1, 1, 1, 1, 1, 1}};

    int Ans[] = {};
    int NoOfProcesses = 4;
    int NoOfMemoryBlocks = 6;

    for (int i = 0; i < NoOfProcesses; i++)
    {
        // for (int j = 0, k = 0; j < NoOfMemoryBlocks, k < 2; j++){

        // }

        int MinimumElement = findMinimum(MemoryBlocks, NoOfMemoryBlocks);
    }
}