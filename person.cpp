#include "iostream"
#include "string"
#include "person.hpp"
using namespace std;

void test1(){
    Person<string,int> P1("¿œ¥Û",10000);
    P1.showPerson();
}


int main(){
    test1();
    return 0;
}