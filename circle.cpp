#include <iostream>
using namespace std;
class printer
{
public:
    string str="";
    string lookup[4] = { "· ","■ ","■ ", "# "};
    void add(short int x)
    {
        str += lookup[x];
    }
    void print()
    {
        cout << str << endl;
        str = "";
    }
};
int mian()
{
    int r,i,j;
    printer printer;
    cout << "enter R : ";
    cin >> r;
    if (r < 0||r> 8192)//r > 46340)
    {
        cout << "invalid input" << endl;
        system("cls");
        return 0;
    }
    short int** matrix = new short int* [r+1];
    for (i = 0; i < r+1; i++)
    {
        matrix[i] = new short int[r+1];
        for (j = 0; j < r+1; j++)
            matrix[i][j] = 0;
    }

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

    if (r <= 4096)
    {

    //图形
    for (i = r; i >=0; i--)
    {
        for (j = 0; j < r + 1; j++)
        {
            printer.add(matrix[i][j]);
        }
        for (j = r-1; j >= 0; j--)
        {
            printer.add(matrix[i][j]);
        }
        printer.print();
    }    
    for (i = 1; i <= r; i++)
    {
        for (j = 0; j < r+1; j++)
        {
            printer.add(matrix[i][j]);
        }
        for (j = r-1; j >=0; j--)
        {
            printer.add(matrix[i][j]);
        }
        printer.print();
    }

    }

    //sum
    long int sum = 0;
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
