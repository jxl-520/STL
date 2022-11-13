#include <iostream>
#include <map>

using namespace std;
void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"Key="<<it->first<<" value="<<(*it).second<<endl;
    }
    cout<<endl;
}
//map构造
void test1(){
    map<int,int> m1;

    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    printMap(m1);

    map<int,int> m2(m1);//拷贝构造
    printMap(m2);

    map<int,int> m3;
    m3 = m2;
    printMap(m3);
}
//map大小和交换
void test2(){
    map<int,int> m1;

    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    if(m1.empty()){
        cout<<"m1 is empty!"<<endl;
    }
    else{
        cout<<"m1 is not empty!"<<endl;
        cout<<"Size of m1:"<<m1.size()<<endl;
    }

    map<int,int> m2;

    m2.insert(pair<int,int>(1,100));
    m2.insert(pair<int,int>(2,200));

    cout<<"交换前："<<endl;
    cout<<"m1:";
    printMap(m1);
    cout<<"m2:";
    printMap(m2);

    m2.swap(m1);

    cout<<"交换后："<<endl;
    cout<<"m1:";
    printMap(m1);
    cout<<"m2:";
    printMap(m2);
}
//map插入和删除
void test3(){
    //插入
    map<int,int> m;
    //第一种插入方式
    m.insert(pair<int,int> (1,100));
    //第二种插入
    m.insert(make_pair(2,200));
    //第三种插入方式
    m.insert(map<int,int>::value_type(3,300));
    //第四种插入方式
    m[4] = 400;

    printMap(m);

    //删除
    m.erase(m.cbegin());
    printMap(m);

    m.erase(3);
    printMap(m);

    //清空
    m.clear();
    printMap(m);
}
//map查找和统计
void test4(){
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m[3] = 30;

    //查找
    map<int,int>::iterator pos = m.find(3);

    if(pos!=m.end()){
        cout<<"找到了，key = "<<(*pos).first<<" value = "<<(*pos).second<<endl;
    }
    else{
        cout<<"没有找到"<<endl;
    }

    //统计
    int num = m.count(3);
    cout << "num = " << num << endl;
}
//map排序
class MyCompare{
public:
    bool operator()(const int &m1,const int &m2){
        return m1>m2;
    }
};
void test5(){
    map<int,int,MyCompare> m;
    m.insert(make_pair(2,100));
    m.insert(pair<int,int>(1,100));
    m.insert(pair<int,int>(3,220));
    m.insert(pair<int,int>(5,20));

    for(map<int,int,MyCompare>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first<<" value = "<<(*it).second<<endl;
    }


}
int main(){
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
    return 0;
}