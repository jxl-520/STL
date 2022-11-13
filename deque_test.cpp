#include <iostream>
#include <algorithm>
#include "deque"

using namespace std;

void printDeque(deque<int> &d) {
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//deque构造函数
void test1() {
    deque<int> d1;//无参构造
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());//构造函数将[beg, end)区间中的元素拷贝给本身。
    printDeque(d2);

    deque<int> d3(10, 100);//构造函数将10个100拷贝给本身。
    printDeque(d3);

    deque<int> d4(d3);//拷贝构造函数
    printDeque(d4);

}

// deque赋值操作
void test2() {
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i + 1);
    }
    printDeque(d1);

    //重载等号操作符
    deque<int> d2;
    deque<int> d3;
    d3 = d2 = d1;
    printDeque(d2);
    printDeque(d3);

    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);

    deque<int> d5;
    d5.assign(d4.begin(),d4.end()-1);
    printDeque(d5);

}

//deque大小操作
void test3(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);
    if(d1.empty()){
        cout<<"d1 is empty"<<endl;
    }
    else{
        cout<<"d1 is not empty"<<endl;
        cout<<"size of d1 is:"<<d1.size()<<endl;
    }

    d1.resize(20,100);
    printDeque(d1);

}
//deque插入和删除
void test4(){
    deque<int> d1;

    //尾插
    d1.push_back(5);
    d1.push_back(6);
    d1.push_back(7);
    d1.push_back(8);
    d1.push_back(9);
    d1.push_back(10);

    printDeque(d1);
    //尾删
    d1.pop_back();

    printDeque(d1);

    //头插
    d1.push_front(4);
    d1.push_front(3);
    d1.push_front(2);
    d1.push_front(1);

    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);

    //insert
    d1.insert(d1.cbegin()+3,100);
    printDeque(d1);

    d1.insert(d1.cbegin()+2,5,10000);
    printDeque(d1);

    d1.insert(d1.cend(),d1.cbegin(),d1.cend());
    printDeque(d1);

    //erase
    d1.erase(d1.cbegin()+14,d1.cend());
    printDeque(d1);

    d1.erase(d1.cbegin()+2);
    printDeque(d1);

}
//deque数据存储
void test5(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);
    }
    printDeque(d1);
    //at取值
    for (int i = 0; i < d1.size(); ++i) {
        cout<<d1.at(i)<<" ";
    }
    cout<<endl;
    //[]取值
    for (int i = 0; i < d1.size(); ++i) {
        cout<<d1[i]<<" ";
    }
    cout<<endl;

    cout<<"front:"<<d1.front()<<endl;
    cout<<"back:"<<d1.back()<<endl;
}
//deque排序
void test6(){
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(23);
    d1.push_front(34);
    d1.push_front(12);
    d1.push_back(-5);
    d1.push_back(-100);

    printDeque(d1);
    sort(d1.begin(),d1.end());
    printDeque(d1);
}


int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
    test6();



    return 0;

}