#include <stdio.h>
#include <iostream>
class foo {
    int a;
    int b;
    int c;
    
};
int Add(int a, int b){
    return a+b;
}

int main(){
    int c;
    int (*p)(int,int);
    p = Add;
    c = (*p)(2,3);
    cout << c << endl;
}