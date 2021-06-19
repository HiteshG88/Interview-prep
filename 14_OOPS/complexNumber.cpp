#include <iostream>
using namespace std;

class Complex{
    int r;
    int img;

public:
    // constructors:
    // copy constructor is inbuilt
    Complex(): r(0), img(0) {};
    Complex(int real, int imginary): r(real), img(imginary) {};

    // setters and getters
    void setReal(const int real){
        r = real;
    }
    void setImg(const int imaginary){
        img = imaginary;
    }
    int getReal() const {
        return r;
    }
    int getImg() const {
        return img;
    }

    void add(const Complex &x){
        r += x.r;
        img += x.img;
    }

    // operator overloading
    void operator + (const Complex &x){
        r += x.r;
        img += x.img;
    }

    void print(){
        if(img > 0)
            cout << r << " + " << img << "i" << endl;
        else
             cout << r << " - " << -img << "i" << endl;
    }
};

// void operator >> (istream &is, Complex &x){
//     int r1, img1;
//     is >> r1 >> img1;
//     x.setReal(r1);
//     x.setImg(img1);
// }

// void operator << (ostream &os, Complex &x){
//     x.print();
// }

// cascading of operators:
// return the cin object with refrence as we dont want to make copies of it. same in cout.
istream& operator >> (istream &is, Complex &x){
    int r1, img1;
    is >> r1 >> img1;
    x.setReal(r1);
    x.setImg(img1);
    return is;
}

ostream& operator << (ostream &os, Complex &x){
    x.print();
    return os;
}

int main(){
    // Complex n1(5,3);
    // Complex n2;

    // n2.setReal(4);
    // n2.setImg(2);

    // n1.print();
    // n2.print();

    // // n1.add(n2);
    // n1+n2;
    // n1.print();

    // using overloaded << , >> .
    Complex d1, d2;
    cin >> d1 >> d2;
    cout << d1 << d2;

    return 0;
}
