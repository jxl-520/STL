#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MyPrint(int a){
    cout<<a<<endl;
}
/*!
 * ��vector��������������Ͳ��ұ���
 */
void test1(){
    vector<int> v;

    //β������
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //��������
    vector<int>::iterator it_begin = v.begin();
    vector<int>::iterator it_end = v.end();
//    while(it_begin!=it_end){
//        cout<<*it_begin<<endl;
//        it_begin++;
//    }

//    for (vector<int>::iterator it_begin = v.begin(); it_begin!=v.end(); it_begin++){
//        cout<<*it_begin<<endl;
//    }

    for_each(it_begin,it_end,MyPrint);
}
class student{
public:
    student(char* name,int age){
        my_name = name;
        my_age =age;
    }
private:
    char* my_name;
    int my_age;
public:
    char *getMyName() const {
        return my_name;
    }

    int getMyAge() const {
        return my_age;
    }
};
/*!
 * ��vector����Զ����������Ͳ��ұ���
 */
void test2(){
    vector<student> students;

    student student1("����",12);
    student student2("����",76);
    student student3("����",55);
    student student4("����",40);


    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);


    for(vector<student>::iterator it_begin = students.begin(); it_begin !=students.end(); it_begin++){
        cout<<"name:"<<(*it_begin).getMyName()<<" age:"<<(*it_begin).getMyAge()<<endl;
    }
}
/*!
 * ��vector����Զ�������ָ�����Ͳ��ұ���
 */
void test3(){
    vector<student*> students;

    student student1("����",12);
    student student2("����",76);
    student student3("����",55);
    student student4("����",40);


    students.push_back(&student1);
    students.push_back(&student2);
    students.push_back(&student3);
    students.push_back(&student4);


    for(vector<student*>::iterator it_begin = students.begin(); it_begin !=students.end(); it_begin++){
        cout<<"name:"<<(*it_begin)->getMyName()<<" age:"<<(*it_begin)->getMyAge()<<endl;
    }
}
/*!
 * vectorǶ��vector
 */
void test4(){
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    vector<int> row4;

    vector<vector<int>> column;

    //��С�����������
    for(int i=0;i<4;i++){
        row1.push_back(i);
        row2.push_back(i+4);
        row3.push_back(i+8);
        row4.push_back(i+12);
    }

    //��������������
    column.push_back(row1);
    column.push_back(row2);
    column.push_back(row3);
    column.push_back(row4);

    for(vector<vector<int>>::iterator cit = column.begin(); cit!=column.end();cit++) {
        for (vector<int>::iterator rit = (*cit).begin(); rit != (*cit).end(); rit++){
            cout << (*rit) << "\t";
        }
        cout << endl;
    }
}

int main(){
    cout<<"*********"<<"test1"<<"**********"<<endl;
    test1();
    cout<<"*********"<<"test2"<<"**********"<<endl;
    test2();
    cout<<"*********"<<"test3"<<"**********"<<endl;
    test3();
    cout<<"*********"<<"test4"<<"**********"<<endl;
    test4();
    cout<<"*********"<<"test1"<<"**********"<<endl;
    test1();
    cout<<"*********"<<"test2"<<"**********"<<endl;
    test2();
    cout<<"*********"<<"test3"<<"**********"<<endl;
    test3();
    cout<<"*********"<<"test4"<<"**********"<<endl;
    test4();



    return 0;
}
