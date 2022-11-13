#include <iostream>
#include <list>

using namespace std;
//list:˫��ѭ������

void printList(list<int> &L) {
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//list���캯��
void test1() {
    list<int> L1;//Ĭ�Ϲ���

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

    list<int> L2(L1.cbegin(), L1.cend());//���俽��

    //400 300 200 100 10 20 30 40
    printList(L2);

    list<int> L3(10, 100);//10��100
    printList(L3);

    list<int> L4(L2);//��������
    printList(L4);
}

//list��ֵ�ͽ���
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

//list��С����
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

//list�����ɾ��
void test4() {
    list<int> L1;
    //β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);

    //ͷ��
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);

    printList(L1);

    //βɾ��ͷɾ
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

//list ���ݴ洢
void test5() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //cout << L1.at(0) << endl;//���� ��֧��at��������
    //cout << L1[0] << endl; //���� ��֧��[]��ʽ��������
    cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;
    cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;
    //list�����ĵ�������˫�����������֧���������
    list<int>::iterator it = L1.begin();
    //it = it + 1;//���󣬲�������Ծ���ʣ���ʹ��+1
}

bool myCompare(int &a, int &b) {
    return a > b;
}

//list ��ת������
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

//������������Person�Զ����������ͽ�������Person�����������������䡢���
//������򣺰�����������������������ͬ������߽��н���
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
        cout << "������" << (*it).getMName() << " ���䣺" << (*it).getMAge() << " ��ߣ�" << (*it).getMHeight() << endl;
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

    Person P1("����", 20, 40);
    Person P2("����", 16, 50);
    Person P3("����", 18, 50);
    Person P4("�", 19, 60);
    Person P5("��ΰ", 22, 60);
    Person P6("����", 20, 54);
    Person P7("����", 20, 50);
    Person P8("���", 22, 59);

    persons.push_back(P1);
    persons.push_back(P2);
    persons.push_back(P3);
    persons.push_back(P4);
    persons.push_back(P5);
    persons.push_back(P6);
    persons.push_back(P7);
    persons.push_back(P8);

    cout << "����ǰ��" << endl;

    printPerson(persons);

    persons.sort(ComparePerson);
    cout << "�����" << endl;
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