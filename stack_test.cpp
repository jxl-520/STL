#include <iostream>
#include <stack>

using namespace std;

void test1(){
    stack<int> stk1;

    //入栈
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);

    stack<int> stk2(stk1); //拷贝构造

    while(!stk2.empty()){
        cout<<stk2.top()<<" ";  //输出栈顶元素
        stk2.pop();//出栈
    }
    cout<<endl;

    cout<<"size of str1 is :"<<stk1.size()<<endl;
    cout<<"size of str2 is :"<<stk2.size()<<endl;

    stk1.swap(stk2);
    cout<<"size of str1 is :"<<stk1.size()<<endl;
    cout<<"size of str2 is :"<<stk2.size()<<endl;
}
int main(){
    test1();

    return 0;
}
