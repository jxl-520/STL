#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//输出vector
void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


//vector构造函数
void test1() {
    vector<int> v1; //无参构造
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    //将v1[begin(),end())的元素拷贝给v2；
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    //构造函数将10个1拷贝给v3
    vector<int> v3(10, 1);
    printVector(v3);

    //拷贝构造函数
    vector<int> v4(v3);
    printVector(v4);
}

//vector赋值操作
void test2() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i+1);
    }
    printVector(v1);

    //等号赋值
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    //assign()
    vector<int> v3;
    v3.assign(v2.begin(),v2.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10,100);//分配10个100
    printVector(v4);
}
//vector容量和大小
void test3(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i+1);
    }
    printVector(v1);

    //empty()判断是否为空
    bool ret = v1.empty();
    (ret==1)?cout<<"vector is empty"<<endl:cout<<"vector is not empty"<<endl;

    int cap = v1.capacity(); //容量
    cout<<"capacity of vector: "<<cap<<endl;

    int size = v1.size(); //容量
    cout<<"size of vector: "<<size<<endl;

    //resize(int num, elem); 重新指定容器的长度为num，若容器变长，则以elem值填充新位置。未指定elem，则使用默认值填充
    //如果容器变短，则末尾超出容器长度的元素被删除。
    v1.resize(30,1);
    printVector(v1);
    cap = v1.capacity(); //容量
    cout<<"capacity of vector: "<<cap<<endl;

    size = v1.size(); //容量
    cout<<"size of vector: "<<size<<endl;
}
//vector插入和删除
void test4(){
    vector<int> v1;

    //尾插
    v1.push_back(6);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    printVector(v1);

    sort(v1.begin(),v1.end());
    printVector(v1);

    //尾删
    v1.pop_back();
    printVector(v1);

    //insert
    v1.insert(v1.begin()+1,0);
    printVector(v1);

    v1.insert(v1.begin()+1,10,9);
    printVector(v1);

    //erase
    v1.erase(v1.begin()+1,v1.begin()+11);
    printVector(v1);

    v1.erase(v1.cbegin()+1);
    printVector(v1);

    //清空容器
    v1.clear();
    printVector(v1);
}

//vector 数据存取
void test5(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i+1);
    }
    printVector(v1);
    //at
    for (int i = 0; i < 10; ++i) {
        cout<<v1.at(i)<<' ';
    }
    cout<<endl;
    //[]
    for (int i = 0; i < 10; ++i) {
        cout<<v1[i]<<' ';
    }
    cout<<endl;
    //[],at均可以修改vector中的元素
    v1[5]=100;
    v1.at(6) = 200;
    for (int i = 0; i < 10; ++i) {
        cout<<v1[i]<<' ';
    }
    cout<<endl;


    cout<<"front is:"<<v1.front()<<endl; //返回容器中第一个数据元素
    cout<<"front is:"<<v1.back()<<endl;//返回容器中最后一个数据元素

}
//vector容器互换
void test6(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i+1);
    }
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(i+10);
    }
    cout<<"before swap:"<<endl;
    cout<<"v1:";
    printVector(v1);
    cout<<"v2:";
    printVector(v2);

    v1.swap(v2);

    cout<<"after swap:"<<endl;
    cout<<"v1:";
    printVector(v1);
    cout<<"v2:";
    printVector(v2);

}
//使用swap()收缩内存
void test7(){
    vector<int> v;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(i);
    }
    cout << "capacity of v is:" << v.capacity() << endl;
    cout << "size of v is:" << v.size() << endl;

    v.resize(3);
    cout << "capacity of v is:" << v.capacity() << endl;
    cout << "size of v is:" << v.size() << endl;

    //收缩内存
    vector<int> (v).swap(v);//匿名对象，

    cout << "capacity of v is:" << v.capacity() << endl;
    cout << "size of v is:" << v.size() << endl;
}
//reserve()预留空间
void test8(){
    vector<int> v;

    int num = 0;//开辟新空间的次数
    int *p = NULL;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(i);
        if(p!=&v[0]){
            p=&v[0];
            num++;
        }
    }
    cout<<"before reserve() num="<<num<<endl;

    vector<int> v2;
    v2.reserve(1000000);//如果数据量较大，可以一开始利用reserve预留空间,减少开辟新空间的次数。
    num = 0;//开辟新空间的次数
    p = NULL;
    for (int i = 0; i < 1000000; ++i) {
        v2.push_back(i);
        if(p!=&v2[0]){
            p=&v2[0];
            num++;
        }
    }
    cout<<"after reserve() num="<<num<<endl;
}
int main() {
//    test1();
//    test2();
//    test3();
    test4();
//    test5();
//    test8();
    return 0;
}
