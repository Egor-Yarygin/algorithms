#include <iostream>
#include <ctime>
#include <random>
#include <typeinfo>
#include <iomanip>
#include <time.h> 
using namespace std;

template <typename T>
class NDArray
{
public:
    int x, y;
    T **arr;

    void wait (int seconds){
        clock_t endwait;
        endwait = clock () + seconds * CLOCKS_PER_SEC ;
        while (clock() < endwait) {}
    }

    ~NDArray()
    {
        delete_array(arr, x);
    }

    void delete_array(T **array, int a)
    {
        for (int i = 0; i < a; i++)
        {
            delete[] array[i];
        }
        delete[] array;
    }

    NDArray(int a, int b)
    {
        x = a;
        y = b;
        arr = create_array(x, y);
    }

    T **create_array(int a, int b)
    {
        T **array = new T *[a];
        for (int i = 0; i < a; i++)
        {
            array[i] = new T[b];
        }
        return array;
    }

    void fill_with_zeros()
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = 0;
            }
        }
        print_array();
        cout << "fill_with_zeros" << endl;
    }

    void fill_with_ones()
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = 1;
            }
        }
        print_array();
        cout << "fill_with_ones" << endl;
    }

    void fill_with_rand_numb()
    {
        srand((unsigned)time(0));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = 0 + ((rand() % (int)pow(10, 2)) / pow(10, 2)) * (10 - 0);
            }
        }
        print_array();
        cout << "fill_with_random_numbers" << endl;
    }
    T *operator[](const int &i)
    {
        return arr[i];
    }
    NDArray &operator=(T &num)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] = num;
            }
        }
        return *this;
    }
    NDArray &operator+=(T &num)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] += num;
            }
        }
        return *this;
    }
    NDArray &operator-=(T &num)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] -= num;
            }
        }
        return *this;
    }
    NDArray &operator/=(T &num)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] /= num;
            }
        }
        return *this;
    }
    NDArray &operator*=(T &num)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                arr[i][j] *= num;
            }
        }
        return *this;
    }
    void print_array()
    {
        for (int i = 0; i < x; i++)
        {
            cout << endl;
            for (int j = 0; j < y; j++)
            {
                cout << arr[i][j] << "\t";
            }
        }
        cout << endl;
    }
    void matrix_mult(NDArray &A, NDArray &B)
    {
        if (A.y != B.x)
        {
            cout << endl
                 << "These matrices cannot be multiplied" << endl;
        }
        else
        {
            if (x != A.x or y != B.y)
            {
                cout << endl
                     << "Incorrect dimension of the matrix" << endl;
            }
            else if (x == A.x and y == B.y)
            {
                for (int i = 0; i < A.x; i++)
                {
                    for (int j = 0; j < B.y; j++)
                    {
                        for (int k = 0; k < A.y; k++)
                        {
                            arr[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
                print_array();
                cout << "matrix_multiplication" << endl;
            }
        }
    }
    void matrix_trans()
    {
        T **transposed_arr = create_array(y, x);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                transposed_arr[j][i] = arr[i][j];
            }
        }
        delete_array(arr, x);
        int temp = x;
        x = y;
        y = temp;
        arr = transposed_arr;
        print_array();
        cout << "matrix transposition" << endl;
    }
    void reduction(string numb)
    {

        if (numb == "0")
        {
            NDArray<float> mas(1, y);
            float sum = 0;
            for (int i = 0; i < y; i++)
            {
                sum = 0;
                for (int j = 0; j < x; j++)
                {
                    sum = sum + arr[j][i];
                }
                mas[0][i] = sum / x;
            }
            mas.print_array();
            cout << "reduction by columns" << endl;
        }

        if (numb == "1")
        {
            NDArray<float> mas(1, x);
            float sum = 0;
            for (int i = 0; i < x; i++)
            {
                sum = 0;
                for (int j = 0; j < y; j++)
                {
                    sum = sum + arr[i][j];
                }
                mas[0][i] = sum / y;
            }
            mas.print_array();
            cout << "reduction by lines" << endl;
        }

        if (numb == "")
        {
            NDArray<float> mas(1, 1);
            float sum = 0;
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    sum = sum + arr[i][j];
                }
            }
            mas[0][0] = sum / (x * y);
            mas.print_array();
            cout << "reduction of the entire array" << endl;
        }
    }
};