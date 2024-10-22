#include <iostream>
#include <iomanip>
#include <time.h>
 
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** a, const int rowCount, const int colCount);
int FindMaxSum(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));  
    int Low = -100;
    int High = 100;
    int rowCount = 7;
    int colCount = 6;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    Create(a, rowCount, colCount, Low, High);
    cout << "Massive: " << endl;
    Print(a, rowCount, colCount);
    int maxSum = FindMaxSum(a, rowCount, colCount);
    cout << "Sum: " << maxSum << endl;


    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindMaxSum(int** a, const int rowCount, const int colCount)
{
    int maxSum = 0;

    for (int j = 0; j < colCount; j++)
    {
        if (j % 2 != 0)
        {
            int maxInColumn = a[0][j];

            for (int i = 1; i < rowCount; ++i)
            {
                if (a[i][j] > maxInColumn)
                {
                    maxInColumn = a[i][j];
                }
            }

            maxSum += maxInColumn;
        }
    }

    return maxSum;
}
