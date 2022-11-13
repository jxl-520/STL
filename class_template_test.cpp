#include <iostream>
#include <string>

using namespace std;


//��ģ���뺯��ģ�������
//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
//��ģ��
template<class NameType, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->mName = name;
        this->mAge = age;
    }

    void showPerson() {
        cout << "name:" << this->mName << " age:" << this->mAge << endl;
    }

public:
    NameType mName;
    AgeType mAge;
};

void test1() {
    //ָ��NameTypeΪstring���ͣ�AgeTypeΪint����
    Person<string, int> P1("�����", 999); //����ʹ����ʾָ�����͵ķ�ʽ��ʹ����ģ��
    P1.showPerson();

//    Person P2("����",50);//������ģ�岻���Զ��Ƶ�����
    Person<string> P2("��˽�", 987);//��ģ���е�ģ������б�����ָ��Ĭ�ϲ���
    P2.showPerson();
}

//��ģ���г�Ա��������ͨ���еĳ�Ա��������ʱ����������ģ�
//1.��ͨ���еĳ�Ա����һ��ʼ�ʹ���
//2.��ģ���еĳ�Ա�����ڵ��õ�ʱ�򴴽�
class Person1 {
public:
    void showPerson1() {
        cout << "Person1 show" << endl;
    }
};

class Person2 {
public:
    void showPerson2() {
        cout << "Person2 show" << endl;
    }
};

template<class T>
class MyClass {
public:
    T obj;

    //��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
    void fun1() { obj.showPerson1(); }

    void fun2() { obj.showPerson2(); }
};

void test2() {
    MyClass<Person1> m;
    m.fun1();
    //m.fun2();//�������˵���������òŻ�ȥ������Ա����
}

//��ģ��ʵ�������Ķ����������������ַ�ʽ��
//1.ָ�����뷽ʽ  --ֱ����ʾ�������������
//2.����ģ�廯   --�������еĲ������ģ����д���
//3.������ģ�廯  --�������������ģ�廯���д���

//1.ָ�����뷽ʽ�����ã�
void printPerson1(Person<string, int> &p) {
    p.showPerson();
}

//2.����ģ�廯
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
    cout << "T1������Ϊ" << typeid(T1).name() << endl;
    cout << "T2������Ϊ" << typeid(T2).name() << endl;
}

//3.������ģ�廯
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T������Ϊ" << typeid(T).name() << endl;
}

void test3() {
    Person<string, int> P1("�����", 100);
    printPerson1(P1);
    printPerson2(P1);
    printPerson3(P1);
}

//����ģ�������̳�ʱ����Ҫע��
//1.������̳еĸ�����һ����ģ��ʱ��������������ͬʱҪָ������T������
//2.�����ָ�����������޷�����������ڴ�
//3.��������ָ��������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��

//������ģ����
template<class T>
class Base {
    T m;
};

template<class T>
class Base2 {
    T m;
};


//class Son:public Base   //����C++��������Ҫ����������ڴ棬����֪��������T�����Ͳſ������¼̳�
//����ָ��һ������
class Son1 : public Base<int> {

};

//��ģ��̳���ģ�壬������T2ָ�������T����
template<class T1, class T2>
class Son2 : public Base<T1>, public Base2<T2>{
public:
    Son2() {
        cout << "T1������Ϊ" << typeid(T1).name() << endl;
        cout << "T2������Ϊ" << typeid(T2).name() << endl;
//        cout << "T3������Ϊ" << typeid(T3).name() << endl;
    }
};

void test4() {
    Son1 c;
    Son2<int, char> S;
}

//��ģ�������Ԫ���������ں�����ʵ��
//ȫ�ֺ�������ʵ�֣�ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
template<class T1,class T2> class School_report;

template<class T1,class T2>
void print_report2(School_report<T1,T2> &r){
    cout<<"��Ŀ��"<<r.subject<<" ������"<<r.score<<endl;
}

template<class T1,class T2>
class School_report{
    // ����ʵ��
    friend void print_report1(School_report<T1,T2> &r){
        cout<<"��Ŀ��"<<r.subject<<" ������"<<r.score<<endl;
    }
    //����ʵ��
    friend void print_report2<>(School_report<T1,T2> &r);
public:
    School_report(T1 subject,T2 score){
        this->subject = subject;
        this->score = score;
    }
    void print_report3(School_report<T1,T2> &r){
        cout<<"��Ŀ��"<<r.subject<<" ������"<<r.score<<endl;
    }
private:
    T1 subject;
    T2 score;
};



void test5(){
    School_report<string,int> R1("��ѧ",83);
    print_report1(R1);
    R1.print_report3(R1);
    print_report2(R1);

}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
    return 0;
}

