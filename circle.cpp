#include <iostream>
using namespace std;
void print(short int x)
{
    if (x&&x<=2)
        cout << "■" << " ";
    else if (x == 3)
    {
        cout << "#" << " ";
    }
    else
    {
        cout << "·" << " ";
    }
}
int mian()
{
    int r,i,j;
    cout << "enter R : ";
    cin >> r;
    if (r < 0 || r >46340)
    {
        cout << "invalid input" << endl;
        return 0;
    }
    short int** matrix = new short int* [r+1];
    for (int i = 0; i < r+1; i++)
    {
        matrix[i] = new short int[r+1];
        for (int j = 0; j < r+1; j++)
            matrix[i][j] = 0;
    }

    float y;
    for (int x = -r; x < 1; x++)
    {
        i = round(sqrt(r * r - x * x));
        j = x + r;
        matrix[i][j] = 1;
        if (matrix[r-j][r-i] == 0)
        {
            matrix[r-j][r-i] = 2;
        }

    }

    for (i = 0; i <= r; i++)
    {
        if (matrix[i][r] == 0)
        {
            matrix[i][r] = 3;
        }
    }
    for (i = 0; i <= r; i++)
    {
        if (matrix[0][i] == 0)
        {
            matrix[0][i] = 3;
        }
    }

    //test
    /*
    cout << "DEBUG:" << endl;
    for (i = 0; i < r+1; i++)
    {
        for (j = 0; j < r+1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "" << endl;*/

    //图形
    for (i = r; i >=0; i--)
    {
        for (j = 0; j < r + 1; j++)
        {
            print(matrix[i][j]);
        }
        for (j = r-1; j >= 0; j--)
        {
            print(matrix[i][j]);
        }
        cout << endl;
    }    
    for (i = 1; i <= r; i++)
    {
        for (j = 0; j < r+1; j++)
        {
            print(matrix[i][j]);
        }
        for (j = r-1; j >=0; j--)
        {
            print(matrix[i][j]);
        }
        cout << endl;
    }


    //sum
    int sum = 0;
    int a, b;
    for (i = 0; i <= r; i++)
    {
        for (j = 0; j <= r; j++)
        {
            if (matrix[i][j] == 1 || matrix[i][j] == 2)
            {
                a = j;
                break;
            }
        }
        b = r;
        sum += b - a + 1;
        
    }
    sum = 4 * sum - 2 * (2 * r + 1) - 1;
    cout << "面积方块总数：" << sum << endl;
    cout << "~=64*" << int(sum/64)+1 << endl;
    for (int i = 0; i <= r; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
int main()
{
    while (1)
    {
        mian();
    }    
    return 0;
}
