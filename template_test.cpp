#include <iostream>

using namespace std;

/*!
 * 交换整数类型
 * @param a
 * @param b
 */
void swapInt(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

/*!
 * 交换浮点型函数
 * @param a
 * @param b
 */
void swapDouble(double &a, double &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

/*!
 * 使用模板提供通用的交换函数
 * @tparam T
 * @param a
 * @param b
 */
template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}


void test1() {
    int a = 2, b = 3;
    cout << "before swap:" << "a=" << a << " b=" << b << endl;
    swapInt(a, b);
    cout << "after  swap:" << "a=" << a << " b=" << b << endl;

    double c = 3.234, d = 6.24322;
    cout << "before swap:" << "c=" << c << " d=" << d << endl;
    swapDouble(c, d);
    cout << "before swap:" << "c=" << c << " d=" << d << endl;


    cout << "before swap:" << "a=" << a << " b=" << b << endl;
    mySwap(a, b);
    cout << "after  swap:" << "a=" << a << " b=" << b << endl;


    cout << "before swap:" << "c=" << c << " d=" << d << endl;
    mySwap(c, d);
    cout << "after  swap:" << "c=" << c << " d=" << d << endl;

    char *str1 = "abcds";
    char *str2 = "a";
    cout << "before swap:" << "str1=" << str1 << " str2=" << str2 << endl;
    mySwap(str1, str2);
    cout << "after  swap:" << "str1=" << str1 << " str2=" << str2 << endl;
}

//模板必须要确定出T的数据类型，才可以使用
template<typename T>
void func() {
    cout << "func 调用" << endl;
}

void test2() {
    func<int>(); //利用显示指定的类型的方式，给T一个类型，才可以使用该模板
    //func(); 错误，模板不能独立使用，必须确当出T的类型
}

template<class T>
int Partition(T arr[], int left, int right) {
    T temp = arr[left];
    while (left < right) {
        while (arr[right] < temp && left < right)
            right--;
        arr[left] = arr[right];

        while (arr[left] >= temp && left < right)
            left++;
        arr[right] = arr[left];

    }
    arr[left] = temp;
    return left;
}

/*!
 * 利用模板进行排序（从大到小），排序方法快速排序
 * @tparam T
 * @param arr
 * @param len
 */
template<class T>
//class也可以换成typename
void mySort(T arr[], int left, int right) {
    if (left < right) {
        int pos = Partition(arr, left, right);
        mySort(arr, left, pos - 1);
        mySort(arr, pos + 1, right);
    }
}

template<typename T>
void printArray(T arr[], int size) {
    //int len = sizeof(arr)/sizeof(arr[0]);//错误'sizeof (arr)'将返回指针的大小，而不是数组本身
    for (int i = 0; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test3() {
    //整形数组
    int intArr[] = {7, 3, 4, 6, 1, 8, 10};
    int left = 0;
    int right = (sizeof(intArr) / sizeof(intArr[0])) - 1;
    mySort<int>(intArr, left, right);
    printArray(intArr, right);
    //char数组
    char charArray[] = "sjnfgajskd";
    left = 0;
    right = (sizeof(charArray) / sizeof(charArray[0])) - 1;
    mySort<char>(charArray, left, right);
    printArray(charArray, right);
}

//1. 如果函数模板和普通函数都可以实现，优先调用普通函数
//2. 可以通过空模板参数列表来强制调用函数模板
//3. 函数模板也可以发生重载
//4. 如果函数模板可以产生更好的匹配,优先调用函数模板
//普通函数与模板函数的调用规则
void myPrint(int a, int b) {
    cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b) {
    cout << "调用模板函数" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) {
    cout << "调用重载模板函数" << endl;
}

void test4() {
    int a = 10, b = 20;
    myPrint(a, b);//优先调用普通函数

    myPrint<>(a, b);//使用空模板强制调用模板函数

    int c = 30;
    myPrint(a, b, c);//模板函数也可以重载

    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);//如果普通函数不能匹配，则有限匹配模板函数
}

//模板的局限性
class Person {
public:
    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    char *name;
    int age;
};

//普通函数模板
template<typename T>
bool myCompare(T &a, T &b) {
    return a == b;
}

//具体化Person模板函数
template<>
bool myCompare(Person &a, Person &b) {
    if (a.name == b.name && a.age == b.age) {
        return true;
    }
    return false;
}

void test5() {
    int a = 10, b = 20;
    bool ret = myCompare(a, b);//内置数据类型可以直接调用通用的函数模板
    ret > 0 ? cout << "a==b" << endl : cout << "a!=b" << endl;

    Person Person1("张三", 10);
    Person Person2("张", 10);
    ret = myCompare(Person1, Person2);//无法调用通用模板函数，可以创建具体化的Person数据类型的模板
    ret > 0 ? cout << "Person1==Person2" << endl : cout << "Person1!=Person2" << endl;

}


int main() {
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
    return 0;
}


