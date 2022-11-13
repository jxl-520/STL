#include <iostream>
#include "map"
#include "vector"

using namespace std;

#define CHEFA 0
#define MEISHU 1
#define YANFA 2

//员工类
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
//创建员工
void creatStaff(vector<Staff> & v_Staff){
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        string name = "员工";
        name +=nameSeed[i];

        int salary = rand()%10000+10000;

        Staff staff(name,salary);
        v_Staff.push_back(staff);
    }
}
//员工分组
void setGroup(multimap<int,Staff> &m_Group,vector<Staff> &v_Staff) {
    for (vector<Staff>::iterator it = v_Staff.begin(); it != v_Staff.end(); it++) {
        int IDseed = rand() % 3;
        m_Group.insert(make_pair(IDseed,*it));
    }
}
//分组显示员工
void showStaffByGroup(multimap<int,Staff> &m_Group){
    cout<<"策划部门："<<endl;
    multimap<int,Staff>::iterator pos = m_Group.find(0);
    while (pos->first == CHEFA){
//        cout<<pos->first<<endl;
        cout<<"Name:"<<pos->second.getName()<<" Salary:"<<pos->second.getSalary()<<endl;
        pos++;
    }

    cout<<"美术部门："<<endl;
    pos = m_Group.find(1);
    while (pos->first == MEISHU){
//        cout<<pos->first<<endl;
        cout<<"Name:"<<pos->second.getName()<<" Salary:"<<pos->second.getSalary()<<endl;
        pos++;
    }

    cout<<"研发部门："<<endl;
    pos = m_Group.find(2);
    while (pos->first == YANFA){
//        cout<<pos->first<<endl;
        cout<<"Name:"<<pos->second.getName()<<" Salary:"<<pos->second.getSalary()<<endl;
        pos++;
    }
}

int main(){

    srand((unsigned int)time(NULL));
    //1.创建员工
    vector<Staff> v_Staff;
    creatStaff(v_Staff);

//    //测试
//    for(vector<Staff>::iterator it = v_Staff.begin();it!=v_Staff.end();it++){
//        cout<<"Name:"<<it->getName()<<" Salary:"<<it->getSalary()<<endl;
//    }

    //2.员工分组
    multimap<int,Staff> m_Group;
    setGroup(m_Group,v_Staff);

    //3.分组显示员工
    showStaffByGroup(m_Group);
    return 0;
}