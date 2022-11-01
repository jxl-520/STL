#include <iostream>
#include <string>

using namespace std;

/*!
 * string�Ĺ���
 */
void test1() {
    string str1;//����һ�����ַ���
    str1 = "aabbcc";
    cout << "str1:" << str1 << endl;

    const char *s = "hello C++";
    string str2(s); //ʹ���ַ���s��ʼ��
    cout << "str2:" << str2 << endl;

    string str3(str1);//��������
    cout << "str3:" << str3 << endl;

    string str4(10, 'a');//ʹ��n���ַ���ʼ��
    cout << "str4:" << str4 << endl;
}
/*!
 * ��ֵ����
 * */
void test2(){
    string str1;
    str1="Hello World";
    cout<<"str1:"<<str1<<endl;

    string str2 = str1;
    cout<<"str2:"<<str2<<endl;

    string str3;
    str3='a';
    cout<<"str3:"<<str3<<endl;

    string str4;
    str4.assign("Hello C++!!!");
    cout<<"str4:"<<str4<<endl;

    string str5;
    str5.assign("Hello World!!!",7);//��ǰ7���ַ������ַ���str5
    cout<<"str5:"<<str5<<endl;

    string str6;
    str6.assign(str4);
    cout<<"str6:"<<str6<<endl;

    string str7;
    str7.assign(10,'b');
    cout<<"str7:"<<str7<<endl;





}
/*!
 * �ַ���ƴ��
 */
void test3(){
    string str1="��";
    cout<<"str1:"<<str1<<endl;


    str1+="���ҵļ���";
    cout<<"str1:"<<str1<<endl;

    string str2;
    str2+='c';
    cout<<"str2:"<<str2<<endl;

    string str3;
    str3=str1+str2;
    cout<<"str3:"<<str3<<endl;

    string str4;
    str4=str1.append(",������");
    cout<<"str4:"<<str4<<endl;
    cout<<"str1:"<<str1<<endl;

    string str5;
    str5=str1.append("��������������",2);
    cout<<"str5:"<<str5<<endl;

    string str6;
    str6 = str1.append("abcdefg",3,3);
    cout<<"str6:"<<str6<<endl;


};
/*!
 * ���Һ��滻
 */
void test4(){
    string str1="abcdefgdegdeg";

    int ret = str1.find("de");
    if(ret == -1){
        cout<<"δ�ҵ�"<<endl;
    }else{
        cout<<"λ��Ϊ��"<<ret<<endl;
    }
    //rfind
    ret = str1.rfind("de");
    if(ret == -1){
        cout<<"δ�ҵ�"<<endl;
    }else{
        cout<<"���һ��λ��Ϊ��"<<ret<<endl;
    }

    //replace
    str1.replace(3,3,"11111");
    cout<<"after replace:"<<str1<<endl;

};

void test5(){
    string str1="����";
    string str2="��";

    int ret = str1.compare(str2);
    if(ret == 0){
        cout<<"һ��"<<endl;
    }
    else{
        cout<<ret;
        cout<<"��һ��"<<endl;
    }
}


int main() {
    cout<<"*********"<<"test1"<<"**********"<<endl;
    test1();
    cout<<"*********"<<"test2"<<"**********"<<endl;
    test2();
    cout<<"*********"<<"test3"<<"**********"<<endl;
    test3();
    cout<<"*********"<<"test4"<<"**********"<<endl;
    test4();
    cout<<"*********"<<"test5"<<"**********"<<endl;
    test5();
    return 0;
}