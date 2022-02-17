/*
Back-trackng :
  It is an algorithmic technique for solving recursive problems
  by trying to build every possible solution incrementally and
  removing those solutiona that fail to satisfy the constraints of the
  problem at any point of time
*/
// rat in maze :problem
#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}
bool ratinMaize(int **arr, int x, int y, int n, int **solArr)
{
    if (x == n - 1 && y == n - 1)
    {
        //base condition:
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (ratinMaize(arr, x + 1, y, n, solArr))
        {
            return true;
        }
        if (ratinMaize(arr, x, y + 1, n, solArr))
        {
            return true;
        }
        // backtrack
        solArr[x][y] = 0;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    //for 2 d array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratinMaize(solArr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/*
Input := 
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

 Output:=


*/
//not getting output as we want