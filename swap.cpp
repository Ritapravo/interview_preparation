#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int x = 10, y = 20;
    //swap(x,y);
    int &z = x;
    cout<<x<<" "<<z<<endl;
    cout<<&x<<" "<<&z<<endl;
    return 0;
}

//g++ "swap.cpp" && a
//g++ "F:\interview_preparation\swap.cpp" && a 