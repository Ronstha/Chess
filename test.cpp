#include <iostream>

using namespace std;



class Complex{
    int x;
    int y;
    public:
     Complex(){}
    //  Complex(int x,int y){
    //     this->x=x;
    //     this->y=y;
    //  }
     void seter(int x, int y){
        this->x=x;
        this->y=y;

     }
     void display(){
        cout << x <<" + j"<<y<<endl;
     }

};

int main(){
    Complex c,d;
    c.seter(13,44);
    c.display();
    d.seter(12,3);
    c=d;
    c.display();
}