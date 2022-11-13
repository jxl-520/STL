#include <iostream>
#include "map"
#include "vector"

using namespace std;

#define CHEFA 0
#define MEISHU 1
#define YANFA 2

//Ա����
class Staff{
public:
    Staff(string name,int salary):name_(name),salary_(salary){}
    const string &getName() const {
        return name_;
    }

    int getSalary() const {
        return salary_;
    }

private:
    string name_;
    int salary_;
};
//����Ա��
void creatStaff(vector<Staff> & v_Staff){
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        string name = "Ա��";
        name +=nameSeed[i];

        int salary = rand()%10000+10000;

        Staff staff(name,salary);
        v_Staff.push_back(staff);
    }
}
//Ա������
void setGroup(multimap<int,Staff> &m_Group,vector<Staff> &v_Staff) {
    for (vector<Staff>::iterator it = v_Staff.begin(); it != v_Staff.end(); it++) {
        int IDseed = rand() % 3;
        m_Group.insert(make_pair(IDseed,*it));
    }
}
//������ʾԱ��
void showStaffByGroup(multimap<int,Staff> &m_Group){
    cout<<"�߻����ţ�"<<endl;
    multimap<int,Staff>::iterator pos = m_Group.find(0);
    while (pos->first == CHEFA){
//        cout<<pos->first<<endl;
        cout<<"Name:"<<pos->second.getName()<<" Salary:"<<pos->second.getSalary()<<endl;
        pos++;
    }

    cout<<"�������ţ�"<<endl;
    pos = m_Group.find(1);
    while (pos->first == MEISHU){
//        cout<<pos->first<<endl;
        cout<<"Name:"<<pos->second.getName()<<" Salary:"<<pos->second.getSalary()<<endl;
        pos++;
    }

    cout<<"�з����ţ�"<<endl;
    pos = m_Group.find(2);
    while (pos->first == YANFA){
//        cout<<pos->first<<endl;
        cout<<"Name:"<<pos->second.getName()<<" Salary:"<<pos->second.getSalary()<<endl;
        pos++;
    }
}

int main(){

    srand((unsigned int)time(NULL));
    //1.����Ա��
    vector<Staff> v_Staff;
    creatStaff(v_Staff);

//    //����
//    for(vector<Staff>::iterator it = v_Staff.begin();it!=v_Staff.end();it++){
//        cout<<"Name:"<<it->getName()<<" Salary:"<<it->getSalary()<<endl;
//    }

    //2.Ա������
    multimap<int,Staff> m_Group;
    setGroup(m_Group,v_Staff);

    //3.������ʾԱ��
    showStaffByGroup(m_Group);
    return 0;
}