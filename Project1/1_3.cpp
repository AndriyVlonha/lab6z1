#include <iostream>
#include <windows.h>
using namespace std;

class A {
protected:
    int a;
public:
    A() : a(1) {} 
    virtual void show() { cout << "A: " << a << endl; }
};

class B : public A {
protected:
    int b;
public:
    B() : b(2) {}
    void show() override { cout << "B: " << b << endl; }
};

class C : public A {
protected:
    int c; 
public:
    C() : c(3) {}
    void show() override { cout << "C: " << c << endl; }
};
class D : public B, public C {
protected:
    int d; 
public:
    D() : d(4) {}
    void show() {
        cout << "����� ����� ����� D (��� ����������� ������������):" << endl;
        B::show();
        C::show(); 
        cout << "D: " << d << endl;
    }
};

class A_v {
protected:
    int a;
public:
    A_v() : a(1) {}
    virtual void show() { cout << "A_v: " << a << endl; }
};

class B_v : virtual public A_v {
protected:
    int b;
public:
    B_v() : b(2) {}
    void show() override { cout << "B_v: " << b << endl; }
};

class C_v : virtual public A_v {
protected:
    int c;
    C_v() : c(3) {}
    void show() override { cout << "C_v: " << c << endl; }
};
class D_v : public B_v, public C_v {
protected:
    int d;
public:
    D_v() : d(4) {}
    void show() {
        cout << "����� ����� ����� D_v (� ���������� �������������):" << endl;
        B_v::show(); 
        C_v::show();
        cout << "D_v: " << d << endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    D objD;
    D_v objD_v;

    cout << "����� ��'���� D (��� ����������� ������������): " << sizeof(objD) << " ����" << endl;
    cout << "����� ��'���� D_v (� ���������� �������������): " << sizeof(objD_v) << " ����" << endl;
    cout << "\n������ ������ show() ��� ��'���� D:" << endl;
    objD.show();

    cout << "\n������ ������ show() ��� ��'���� D_v:" << endl;
    objD_v.show();

    return 0;
}
