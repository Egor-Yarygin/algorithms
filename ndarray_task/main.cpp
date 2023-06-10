#include "ndarray.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    cout<<endl<<"Integer Arrays"<<endl;
    NDArray<int> mas_1(3, 2);
    NDArray<int> mas_2(2, 3);
    NDArray<int> mas_3(3, 3);
    mas_3.fill_with_zeros();
    mas_1.fill_with_ones();  
    mas_1.fill_with_rand_numb();
    mas_3.wait(2);
    mas_2.fill_with_rand_numb();
    mas_3.matrix_mult(mas_1, mas_2);
    mas_1.matrix_trans();
    mas_1.matrix_trans();
    mas_1.fill_with_rand_numb();
    mas_1.reduction("");
    mas_1.reduction("0");
    mas_1.reduction("1");
    mas_2[0][0] = 30;
    mas_2[0][1] += 1;
    mas_2[1][0] /= 2;
    mas_2[1][1] *= 3;
    mas_2[1][2] -= 4;
    mas_2.print_array();

    cout<<endl<<endl<<endl<<"Float Arrays"<<endl;
    NDArray<float> mas_4(2, 3);
    NDArray<float> mas_5(3, 2);
    NDArray<float> mas_6(2, 2);
    mas_6.fill_with_zeros();
    mas_4.fill_with_ones();  
    mas_4.fill_with_rand_numb();
    mas_6.wait(2);
    mas_5.fill_with_rand_numb();
    mas_6.matrix_mult(mas_4, mas_5);
    mas_4.matrix_trans();
    mas_4.reduction("");
    mas_4.reduction("0");
    mas_4.reduction("1");
    mas_5[0][0] = 30;
    mas_5[0][1] += 1;
    mas_5[1][0] /= 2;
    mas_5[1][1] *= 3;
    mas_5[2][1] -= 4.5;
    mas_5.print_array();
    cout<<endl;
    return 0;
}