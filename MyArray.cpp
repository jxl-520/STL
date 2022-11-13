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

//����������������
void test1() {
    MyArray<int> array1(10);
    for (int i = 0; i < 10; i++) {
        array1.Push_back(i);
    }
    cout << "array1��ӡ�����" << endl;
    printIntArray(array1);
    cout << "array1�Ĵ�С��" << array1.getSize() << endl;
    cout << "array1��������" << array1.getCapacity() << endl;

    cout << "--------------------------" << endl;
//    MyArray<int> array2(array1);
    MyArray<int> array2(10);
    array2 = array1;
    array2.Pop_back();
    array2.Push_back(100);
    cout << "array2��ӡ�����" << endl;
    printIntArray(array2);
    cout << "array2�Ĵ�С��" << array2.getSize() << endl;
    cout << "array2��������" << array2.getCapacity() << endl;
}

//�����Զ�������
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
        cout << "����:" << persons[i].name << " ���䣺" << persons[i].age << endl;
    }
}

void test2() {
    MyArray<Person> array(10);
    Person p1("�����", 30);
    Person p2("����", 20);
    Person p3("槼�", 18);
    Person p4("���Ѿ�", 15);
    Person p5("����", 24);

    array.Push_back(p1);
    array.Push_back(p2);
    array.Push_back(p4);
    array.Push_back(p5);
    printPerson(array);
    cout << "pArray�Ĵ�С��" << array.getSize() << endl;
    cout << "pArray��������" << array.getCapacity() << endl;


}

int main() {
    test2();
    return 0;
}