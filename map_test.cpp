#include <iostream>
#include <map>

using namespace std;
void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"Key="<<it->first<<" value="<<(*it).second<<endl;
    }
    cout<<endl;
}
//map����
void test1(){
    map<int,int> m1;

    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    printMap(m1);

    map<int,int> m2(m1);//��������
    printMap(m2);

    map<int,int> m3;
    m3 = m2;
    printMap(m3);
}
//map��С�ͽ���
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

    cout<<"����ǰ��"<<endl;
    cout<<"m1:";
    printMap(m1);
    cout<<"m2:";
    printMap(m2);

    m2.swap(m1);

    cout<<"������"<<endl;
    cout<<"m1:";
    printMap(m1);
    cout<<"m2:";
    printMap(m2);
}
//map�����ɾ��
void test3(){
    //����
    map<int,int> m;
    //��һ�ֲ��뷽ʽ
    m.insert(pair<int,int> (1,100));
    //�ڶ��ֲ���
    m.insert(make_pair(2,200));
    //�����ֲ��뷽ʽ
    m.insert(map<int,int>::value_type(3,300));
    //�����ֲ��뷽ʽ
    m[4] = 400;

    printMap(m);

    //ɾ��
    m.erase(m.cbegin());
    printMap(m);

    m.erase(3);
    printMap(m);

    //���
    m.clear();
    printMap(m);
}
//map���Һ�ͳ��
void test4(){
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m[3] = 30;

    //����
    map<int,int>::iterator pos = m.find(3);

    if(pos!=m.end()){
        cout<<"�ҵ��ˣ�key = "<<(*pos).first<<" value = "<<(*pos).second<<endl;
    }
    else{
        cout<<"û���ҵ�"<<endl;
    }

    //ͳ��
    int num = m.count(3);
    cout << "num = " << num << endl;
}
//map����
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