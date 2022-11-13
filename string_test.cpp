#include <iostream>
#include <string>

using namespace std;

/*!
 * string的构造
 */
void test1() {
    string str1;//创建一个空字符串
    str1 = "aabbcc";
    cout << "str1:" << str1 << endl;

    const char *s = "hello C++";
    string str2(s); //使用字符串s初始化
    cout << "str2:" << str2 << endl;

    string str3(str1);//拷贝构造
    cout << "str3:" << str3 << endl;

    string str4(10, 'a');//使用n个字符初始化
    cout << "str4:" << str4 << endl;
}

/*!
 * 赋值操作
 * */
void test2() {
    string str1;
    str1 = "Hello World";
    cout << "str1:" << str1 << endl;

    string str2 = str1;
    cout << "str2:" << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3:" << str3 << endl;

    string str4;
    str4.assign("Hello C++!!!");
    cout << "str4:" << str4 << endl;

    string str5;
    str5.assign("Hello World!!!", 7);//把前7个字符赋给字符串str5
    cout << "str5:" << str5 << endl;

    string str6;
    str6.assign(str4);
    cout << "str6:" << str6 << endl;

    string str7;
    str7.assign(10, 'b');
    cout << "str7:" << str7 << endl;


}

/*!
 * 字符串拼接
 */
void test3() {
    string str1 = "我";
    cout << "str1:" << str1 << endl;


    str1 += "爱我的家乡";
    cout << "str1:" << str1 << endl;

    string str2;
    str2 += 'c';
    cout << "str2:" << str2 << endl;

    string str3;
    str3 = str1 + str2;
    cout << "str3:" << str3 << endl;

    string str4;
    str4 = str1.append(",哈哈哈");
    cout << "str4:" << str4 << endl;
    cout << "str1:" << str1 << endl;

    string str5;
    str5 = str1.append("哈哈哈哈哈哈哈", 2);
    cout << "str5:" << str5 << endl;

    string str6;
    str6 = str1.append("abcdefg", 3, 3);
    cout << "str6:" << str6 << endl;


};

/*!
 * 查找和替换
 */
void test4() {
    string str1 = "abcdefgdegdeg";

    int ret = str1.find("de");
    if (ret == -1) {
        cout << "未找到" << endl;
    } else {
        cout << "位置为：" << ret << endl;
    }
    //rfind
    ret = str1.rfind("de");
    if (ret == -1) {
        cout << "未找到" << endl;
    } else {
        cout << "最后一个位置为：" << ret << endl;
    }

    //replace
    str1.replace(3, 3, "11111");
    cout << "after replace:" << str1 << endl;

};

//字符串比较
void test5() {
    string str1 = "哈哈";
    string str2 = "哈";

    int ret = str1.compare(str2);
    if (ret == 0) {
        cout << "一样" << endl;
    } else {
        cout << ret;
        cout << "不一样" << endl;
    }
}

//string字符存取
void test6() {
    string str1("hello world!!");
    //通过[]取单个数据
    for (int i = 0; i < str1.size(); ++i) {
        cout << str1[i] << " ";
    }
    cout << endl;


    //通过at方法获取字符
    for (int i = 0; i < str1.size(); ++i) {
        cout << str1.at(i) << " ";
    }
    cout << endl;

    string str2;
    str2 = str1;

    //通过[]方式修改字符
    str2[7] = 'k';
    cout << str2 << endl;
    //通过at方法修改字符
    str2.at(6) = 'a';
    cout << str2 << endl;

}

//string插入和删除
void test7(){
    string str1 = "innovation";

    //在0位置插入hello
    str1.insert(0,"hello");
    cout<<str1<<endl;

    //在5位置插入2个空格
    str1.insert(5,2,' ');
    cout<<str1<<endl;

    //删除从0开始的7个字符
    str1.erase(0,7);
    cout<<str1<<endl;
}

//string 子串
void test8(){
    string str1 = "pleasant";

    //返回从1号位置开始的3个字符串lea
    string substr = str1.substr(1,3);
    cout<<substr<<endl;

    //小案例：返回电子邮箱的用户名
    string str2 = "manifestation@sina.com";
    int pos = str2.find('@');
    string username = str2.substr(0,pos);
    cout<<"username:"<<username<<endl;
}


int main() {
//    cout<<"*********"<<"test1"<<"**********"<<endl;
//    test1();
//    cout<<"*********"<<"test2"<<"**********"<<endl;
//    test2();
//    cout<<"*********"<<"test3"<<"**********"<<endl;
//    test3();
//    cout<<"*********"<<"test4"<<"**********"<<endl;
//    test4();
//    cout<<"*********"<<"test5"<<"**********"<<endl;
//    test5();
//    test6();
//    test7();
    test8();
    return 0;
}