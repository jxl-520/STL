#include <iostream>

using namespace std;

/*!
 * ������������
 * @param a
 * @param b
 */
void swapInt(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

/*!
 * ���������ͺ���
 * @param a
 * @param b
 */
void swapDouble(double &a, double &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

/*!
 * ʹ��ģ���ṩͨ�õĽ�������
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

//ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<typename T>
void func() {
    cout << "func ����" << endl;
}

void test2() {
    func<int>(); //������ʾָ�������͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
    //func(); ����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
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
 * ����ģ��������򣨴Ӵ�С�������򷽷���������
 * @tparam T
 * @param arr
 * @param len
 */
template<class T>
//classҲ���Ի���typename
void mySort(T arr[], int left, int right) {
    if (left < right) {
        int pos = Partition(arr, left, right);
        mySort(arr, left, pos - 1);
        mySort(arr, pos + 1, right);
    }
}

template<typename T>
void printArray(T arr[], int size) {
    //int len = sizeof(arr)/sizeof(arr[0]);//����'sizeof (arr)'������ָ��Ĵ�С�����������鱾��
    for (int i = 0; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test3() {
    //��������
    int intArr[] = {7, 3, 4, 6, 1, 8, 10};
    int left = 0;
    int right = (sizeof(intArr) / sizeof(intArr[0])) - 1;
    mySort<int>(intArr, left, right);
    printArray(intArr, right);
    //char����
    char charArray[] = "sjnfgajskd";
    left = 0;
    right = (sizeof(charArray) / sizeof(charArray[0])) - 1;
    mySort<char>(charArray, left, right);
    printArray(charArray, right);
}

//1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3. ����ģ��Ҳ���Է�������
//4. �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
//��ͨ������ģ�庯���ĵ��ù���
void myPrint(int a, int b) {
    cout << "������ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b) {
    cout << "����ģ�庯��" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) {
    cout << "��������ģ�庯��" << endl;
}

void test4() {
    int a = 10, b = 20;
    myPrint(a, b);//���ȵ�����ͨ����

    myPrint<>(a, b);//ʹ�ÿ�ģ��ǿ�Ƶ���ģ�庯��

    int c = 30;
    myPrint(a, b, c);//ģ�庯��Ҳ��������

    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);//�����ͨ��������ƥ�䣬������ƥ��ģ�庯��
}

//ģ��ľ�����
class Person {
public:
    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    char *name;
    int age;
};

//��ͨ����ģ��
template<typename T>
bool myCompare(T &a, T &b) {
    return a == b;
}

//���廯Personģ�庯��
template<>
bool myCompare(Person &a, Person &b) {
    if (a.name == b.name && a.age == b.age) {
        return true;
    }
    return false;
}

void test5() {
    int a = 10, b = 20;
    bool ret = myCompare(a, b);//�����������Ϳ���ֱ�ӵ���ͨ�õĺ���ģ��
    ret > 0 ? cout << "a==b" << endl : cout << "a!=b" << endl;

    Person Person1("����", 10);
    Person Person2("��", 10);
    ret = myCompare(Person1, Person2);//�޷�����ͨ��ģ�庯�������Դ������廯��Person�������͵�ģ��
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


