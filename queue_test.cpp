#include <iostream>
#include <queue>
using namespace std;

void test1(){
    queue<int> q1;

    //队尾入队
    q1.push(1);
    q1.push(2);
    q1.push(3);

    queue<int> q2 = q1;//重载=赋值

    while (!q1.empty()){
        cout<<q1.front()<<" ";//队头元素
        q1.pop();
    }

    cout<<"size of q1:"<<q1.size()<<endl;
    cout<<"size of q2:"<<q2.size()<<endl;
    //输出q2的队头队尾
    cout<<"front of q2:"<<q2.front()<<endl;
    cout<<"back of q2:"<<q2.back()<<endl;


}


int main(){
    test1();

    return 0;
}