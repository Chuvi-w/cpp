#include <iostream>

// ���: using namespace std;

long long factorial(int N){
    if(N <= 1)
        return 1;
    return N * factorial(N-1);
}

int main(int argc, char *argv[])
{
    // Win1251 � � �������� ������ � � �������
    setlocale(LC_ALL, "Russian");

    for(int N = 1; N < 25; N++)
      std::cout << N << "! = " << factorial(N) << std::endl;

    return 0;
}
