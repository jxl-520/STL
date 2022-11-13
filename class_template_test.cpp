#include <iostream>
#include <string>

using namespace std;


//类模板与函数模板的区别
//1.类模板没有自动类型推到的使用方式
//2.类模板在模板参数列表中可以有默认参数
//类模板
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
    //指定NameType为string类型，AgeType为int类型
    Person<string, int> P1("孙悟空", 999); //必须使用显示指定类型的方式，使用类模板
    P1.showPerson();

//    Person P2("张三",50);//错误，类模板不能自动推到类型
    Person<string> P2("猪八戒", 987);//类模板中的模板参数列表，可以指定默认参数
    P2.showPerson();
}

//类模板中成员函数和普通类中的成员函数创建时机是有区别的：
//1.普通类中的成员函数一开始就创建
//2.类模板中的成员函数在调用的时候创建
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

    //类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
    void fun1() { obj.showPerson1(); }

    void fun2() { obj.showPerson2(); }
};

void test2() {
    MyClass<Person1> m;
    m.fun1();
    //m.fun2();//编译错误，说明函数调用才回去创建成员函数
}

//类模板实例化出的对象，向函数传参有三种方式：
//1.指定传入方式  --直接显示对象的数据类型
//2.参数模板化   --将对象中的参数变成模板进行传递
//3.整个类模板化  --将这个对象类型模板化进行传递

//1.指定传入方式（常用）
void printPerson1(Person<string, int> &p) {
    p.showPerson();
}

//2.参数模板化
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
    cout << "T1的类型为" << typeid(T1).name() << endl;
    cout << "T2的类型为" << typeid(T2).name() << endl;
}

//3.整个类模板化
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T的类型为" << typeid(T).name() << endl;
}

void test3() {
    Person<string, int> P1("孙悟空", 100);
    printPerson1(P1);
    printPerson2(P1);
    printPerson3(P1);
}

//当类模板碰到继承时，需要注意
//1.当子类继承的父类是一个类模板时，子类在声明的同时要指定父类T的类型
//2.如果不指定，编译器无法给子类分配内存
//3.如果想灵活指定父类中T的类型，子类也需要变为类模板

//父类是模板类
template<class T>
class Base {
    T m;
};

template<class T>
class Base2 {
    T m;
};


//class Son:public Base   //错误，C++编译器需要给子类分配内存，必须知道父类中T的类型才可以向下继承
//必须指定一个类型
class Son1 : public Base<int> {

};

//类模板继承类模板，可以用T2指定父类的T类型
template<class T1, class T2>
class Son2 : public Base<T1>, public Base2<T2>{
public:
    Son2() {
        cout << "T1的类型为" << typeid(T1).name() << endl;
        cout << "T2的类型为" << typeid(T2).name() << endl;
//        cout << "T3的类型为" << typeid(T3).name() << endl;
    }
};

void test4() {
    Son1 c;
    Son2<int, char> S;
}

//类模板配合友元函数的类内和类外实现
//全局函数类内实现：直接在类内声明有元即可
//全局函数类外实现：需要提前让编译器知道全局函数的存在
template<class T1,class T2> class School_report;

template<class T1,class T2>
void print_report2(School_report<T1,T2> &r){
    cout<<"科目："<<r.subject<<" 分数："<<r.score<<endl;
}

template<class T1,class T2>
class School_report{
    // 类内实现
    friend void print_report1(School_report<T1,T2> &r){
        cout<<"科目："<<r.subject<<" 分数："<<r.score<<endl;
    }
    //类外实现
    friend void print_report2<>(School_report<T1,T2> &r);
public:
    School_report(T1 subject,T2 score){
        this->subject = subject;
        this->score = score;
    }
    void print_report3(School_report<T1,T2> &r){
        cout<<"科目："<<r.subject<<" 分数："<<r.score<<endl;
    }
private:
    T1 subject;
    T2 score;
};



void test5(){
    School_report<string,int> R1("数学",83);
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

