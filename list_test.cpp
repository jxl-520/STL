#include <iostream>
#include <list>

using namespace std;
//list:双向循环链表

void printList(list<int> &L) {
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//list构造函数
void test1() {
    list<int> L1;//默认构造

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);
    L1.push_front(400);
    //400 300 200 100 10 20 30 40
    printList(L1);

    list<int> L2(L1.cbegin(), L1.cend());//区间拷贝

    //400 300 200 100 10 20 30 40
    printList(L2);

    list<int> L3(10, 100);//10个100
    printList(L3);

    list<int> L4(L2);//拷贝构造
    printList(L4);
}

//list赋值和交换
void test2() {
    list<int> L1;
    L1.push_front(10);
    L1.push_front(20);
    L1.push_front(30);
    L1.push_front(40);

    printList(L1);
    //assign
    list<int> L2;
    L2.assign(L1.cbegin(), L1.cend());
    printList(L2);

    list<int> L3;
    L3.assign(10, 100);
    printList(L3);
    //=
    list<int> L4;
    L4 = L1;
    printList(L4);

    //swap
    L4.swap(L3);
    printList(L3);
    printList(L4);

}

//list大小操作
void test3() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    if (!L1.empty()) {
        cout << "L1 is not empty!" << endl;
        cout << "Size of L1 is:" << L1.size() << endl;
    } else {
        cout << "L1 is empty!" << endl;
    }

    L1.resize(10, 100);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

//list插入和删除
void test4() {
    list<int> L1;
    //尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);

    //头插
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);

    printList(L1);

    //尾删，头删
    L1.pop_back();
    L1.pop_front();
    printList(L1);

    L1.insert(L1.cbegin(), 300);
    printList(L1);

    L1.insert(L1.cend(), 10, 100);
    printList(L1);

    L1.erase(L1.cbegin());
    printList(L1);

    L1.remove(100);
    printList(L1);

    L1.clear();
    printList(L1);
}

//list 数据存储
void test5() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //cout << L1.at(0) << endl;//错误 不支持at访问数据
    //cout << L1[0] << endl; //错误 不支持[]方式访问数据
    cout << "第一个元素为： " << L1.front() << endl;
    cout << "最后一个元素为： " << L1.back() << endl;
    //list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = L1.begin();
    //it = it + 1;//错误，不可以跳跃访问，即使是+1
}

bool myCompare(int &a, int &b) {
    return a > b;
}

//list 反转和排序
void test6() {
    list<int> L1;

    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(20);
    L1.push_back(40);
    L1.push_back(30);

    printList(L1);

    L1.reverse();
    printList(L1);

    L1.sort();
    printList(L1);

    L1.sort(myCompare);
    printList(L1);
}

//案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
//排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
class Person {
public:
    Person(string name, int age, int height) : m_Name(name), m_Age(age), m_Height(height) {}

    const string &getMName() const {
        return m_Name;
    }

    int getMAge() const {
        return m_Age;
    }

    int getMHeight() const {
        return m_Height;
    }

private:
    string m_Name;
    int m_Age;
    int m_Height;
};

void printPerson(list<Person> &P) {
    for (list<Person>::iterator it = P.begin(); it != P.end(); it++) {
        cout << "姓名：" << (*it).getMName() << " 年龄：" << (*it).getMAge() << " 身高：" << (*it).getMHeight() << endl;
    }
    cout << endl;
}

bool ComparePerson(Person &p1, Person &p2) {
    if (p1.getMAge() != p2.getMAge())
        return p1.getMAge() < p2.getMAge();
    else
        return p1.getMHeight()>p2.getMHeight();
}

void test7() {
    list<Person> persons;

    Person P1("张三", 20, 40);
    Person P2("李四", 16, 50);
    Person P3("李明", 18, 50);
    Person P4("李华", 19, 60);
    Person P5("张伟", 22, 60);
    Person P6("王伍", 20, 54);
    Person P7("赵明", 20, 50);
    Person P8("李白", 22, 59);

    persons.push_back(P1);
    persons.push_back(P2);
    persons.push_back(P3);
    persons.push_back(P4);
    persons.push_back(P5);
    persons.push_back(P6);
    persons.push_back(P7);
    persons.push_back(P8);

    cout << "排序前：" << endl;

    printPerson(persons);

    persons.sort(ComparePerson);
    cout << "排序后：" << endl;
    printPerson(persons);


}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();

    test7();
    return 0;

}