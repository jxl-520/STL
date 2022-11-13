#include <iostream>
#include <set>
#include <string>

using namespace std;
//set: ����Ԫ���Զ������Ҳ��ظ�
//����ʽ�������ײ����ö�����ʵ��
//set��multiset����set�������ظ�Ԫ�أ�multiset�������ظ���Ԫ��


void printSet(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//set����͸�ֵ
void test1() {
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(20);
    s1.insert(10);

    //10 20 50
    printSet(s1);

    set<int> s2(s1.begin(), s1.end());
    printSet(s2);

    set<int> s3(s2);
    printSet(s3);

    set<int> s4;
    s4 = s1;
    printSet(s1);
}

//set��С�ͽ���
void test2() {
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(20);
    s1.insert(10);

    if (!s1.empty()) {
        cout << "s1 is not empty" << endl;
        cout << "size:" << s1.size() << endl;
    } else
        cout << "s1 is empty" << endl;

    set<int> s2;
    s2.insert(100);
    s2.insert(200);

    cout << "����ǰ��" << endl;
    cout << "s1:";
    printSet(s1);
    cout << "s2:";
    printSet(s2);

    s1.swap(s2);

    cout << "������" << endl;
    cout << "s1:";
    printSet(s1);
    cout << "s2:";
    printSet(s2);

}

//�����ɾ��
void test3() {
    set<int> s1;
    //����
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);
    //ɾ��
    s1.erase(s1.begin());
    printSet(s1);
    s1.erase(30);
    printSet(s1);
    //���
    //s1.erase(s1.begin(), s1.end());
    s1.clear();
    printSet(s1);
}

//set ���Һ�ͳ��
void test4() {
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(20);
    s1.insert(30);

    printSet(s1);

    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end()) {
        cout << "�ҵ��ˣ�" << *pos << endl;
    } else {
        cout << "δ�ҵ�Ԫ��" << endl;
    }
    //ͳ��
    int num = s1.count(580);
    cout << "num = " << num << endl;

}


//set��multiset����
void test5() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second) {
        cout << "��һ�β���ɹ�!" << endl;
    } else {
        cout << "��һ�β���ʧ��!" << endl;
    }
    ret = s.insert(10);
    if (ret.second) {
        cout << "�ڶ��β���ɹ�!" << endl;
    } else {
        cout << "�ڶ��β���ʧ��!" << endl;
    }
//multiset
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//pair���鴴��
void test6(){
    pair<string,int> p("Tom",20);
    cout<<"Name:"<<p.first<<" Age:"<<p.second<<endl;

    pair<string,int> p2 = make_pair("Jerry",10);
    cout<<"Name:"<<p2.first<<" Age:"<<p2.second<<endl;

}
class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1>v2;
    }
};
//set����
void test7(){
    set<int>s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    printSet(s1);

    //���÷º���ָ���������
    set<int,MyCompare> s2;//�ڴ���ʱ�����������
    s2.insert(10);
    s2.insert(50);
    s2.insert(30);
    s2.insert(20);
    s2.insert(40);

    for(set<int,MyCompare>::iterator it = s2.begin();it!=s2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//���Զ����������ͽ�������
class Person{
public:
    Person(string name,int age):Name(name),Age(age){}

    const string &getName() const {
        return Name;
    }

    int getAge() const {
        return Age;
    }

private:
    string Name;
    int Age;
};
class comparePerson{
public:
    bool operator()(const Person &p1,const Person &p2){
        return p1.getAge()>=p2.getAge();//�����併������
    }
};
void test8(){
    set<Person,comparePerson> P;

    Person P1("�ܲ�",55);
    Person P2("����",50);
    Person P3("��Ȩ",30);
    Person P4("����",45);
    Person P5("�ŷ�",30);
    Person P6("Ԭ��",60);

    P.insert(P1);
    P.insert(P2);
    P.insert(P3);
    P.insert(P4);
    P.insert(P5);
    P.insert(P6);

    for(set<Person,comparePerson>::iterator it = P.begin();it!=P.end();it++){
        cout<<"Name:"<<(*it).getName()<<" Age:"<<(*it).getAge()<<endl;
    }
    cout<<endl;
}
int main() {
//    test1();
//    test2();
//    test3();
//    test5()
//    test6();
//    test7();
    test8();
    return 0;

}