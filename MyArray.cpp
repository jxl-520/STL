#include <iostream>
#include "MyArray.hpp"
#include "string"

using namespace std;

void printIntArray(MyArray<int> &arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

//测试内置数据类型
void test1() {
    MyArray<int> array1(10);
    for (int i = 0; i < 10; i++) {
        array1.Push_back(i);
    }
    cout << "array1打印输出：" << endl;
    printIntArray(array1);
    cout << "array1的大小：" << array1.getSize() << endl;
    cout << "array1的容量：" << array1.getCapacity() << endl;

    cout << "--------------------------" << endl;
//    MyArray<int> array2(array1);
    MyArray<int> array2(10);
    array2 = array1;
    array2.Pop_back();
    array2.Push_back(100);
    cout << "array2打印输出：" << endl;
    printIntArray(array2);
    cout << "array2的大小：" << array2.getSize() << endl;
    cout << "array2的容量：" << array2.getCapacity() << endl;
}

//测试自定义类型
class Person {
public:
    Person(){

    }

    Person(string name, int age):name(name),age(age) {

    }

public:
    string name;
    int age;
};

void printPerson(MyArray<Person> &persons) {
    for (int i = 0; i < persons.getSize(); ++i) {
        cout << "姓名:" << persons[i].name << " 年龄：" << persons[i].age << endl;
    }
}

void test2() {
    MyArray<Person> array(10);
    Person p1("孙悟空", 30);
    Person p2("韩信", 20);
    Person p3("妲己", 18);
    Person p4("王昭君", 15);
    Person p5("赵云", 24);

    array.Push_back(p1);
    array.Push_back(p2);
    array.Push_back(p4);
    array.Push_back(p5);
    printPerson(array);
    cout << "pArray的大小：" << array.getSize() << endl;
    cout << "pArray的容量：" << array.getCapacity() << endl;


}

int main() {
    test2();
    return 0;
}