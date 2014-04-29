#include <iostream> // cin / cout
#include <clocale> // setlocale
#include <math.h> // ���������� � ��������������� ���������

using namespace std;

int main() {
    // Win1251 � � �������� ������ � � �������
    setlocale(LC_ALL, "Russian");

    cout << "������� ����������� ���������" << endl;
    cout << "ax^2 + bx + c = 0" << endl;

    // ���� ������������� ���������
    cout << "���� ������������� ���������:" << endl;
    double a, b, c;
    cout << "������� a = "; cin >> a;
    cout << "������� b = "; cin >> b;
    cout << "������� c = "; cin >> c;

    // ���������� �������������
    double D = pow(b,2) - 4*a*c;

    // ���������� � ����� ������(��) x
    const double eps = 1e-15; // 10 � ����� 15 �������
    if(D >= eps){
        cout << "��� �����: ";
        double x1 = (-b + sqrt(D)) / (2*a);
        cout << " x1 = " << x1;
        double x2 = (-b - sqrt(D)) / (2*a);
        cout << " x2 = " << x2;
        cout << endl;
        cout << "��������1: " << (fabs(a*x1*x1 + b*x1 + c) < eps) << endl;
        cout << "��������2: " << (fabs(a*x2*x2 + b*x2 + c) < eps) << endl;
    } else if(fabs(D) < eps) {
        double x = -b / (2*a);
        cout << "���� ������: x = " << x << endl;
        cout << "��������: " << (fabs(a*x*x + b*x + c) < eps) << endl;
    } else {
        cout << "��������� �� ����� ������" << endl;
    }

    return 0;
}
