//��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼ��ܷ�
//5. ��ȡƽ����

#include <iostream>
#include "vector"
#include "deque"
#include "algorithm"

using namespace std;

class Competitor {
public:
    Competitor() {
    }

    Competitor(string name) {
        this->name = name;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Competitor::name = name;
    }

     deque<int> &getScore()  {
        return score;
    }

    void setScore(const deque<int> &score) {
        Competitor::score = score;
    }


    double getAverage() const {
        return average;
    }

    void setAverage(double average) {
        Competitor::average = average;
    }


private:
    string name;
    deque<int> score;
    double average;
};

void crate_Competitor(vector<Competitor> &Competitors) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        string name = "ѡ��";
        name += nameSeed[i];


        Competitor C(name);

        Competitors.push_back(C);
    }
}

void set_Score(vector<Competitor> &Competitors) {
    for (vector<Competitor>::iterator it = Competitors.begin(); it != Competitors.end(); it++) {
        deque<int> s;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; // 60 ~ 100
            s.push_back(score);
        }
        (*it).setScore(s);

        //����
        sort(s.begin(),s.end());
        //ȥͷȥβ
        s.pop_front();
        s.pop_back();

        int sum = 0;
        for (int i = 0; i <s.size(); ++i) {
            sum+= s[i];
        }
        double average = sum/s.size();

        (*it).setAverage(average);
    }
}



void show_Score(vector<Competitor> &Competitors){
    for(vector<Competitor>::iterator it = Competitors.begin();it!=Competitors.end();it++){
        cout<<"����:"<<(*it).getName()<<" ";
        cout<<"��λ��ί�ķ�����";
        for(deque<int>::iterator dit = (*it).getScore().begin();dit!=(*it).getScore().end();dit++ ){
            cout<<*dit<<" ";
        }
        cout<<"  ���շ�����"<<(*it).getAverage()<<endl;
    }
}

int main() {

    srand((unsigned int)time(NULL));

    vector<Competitor> Competitors;
    crate_Competitor(Competitors);

    set_Score(Competitors);

    show_Score(Competitors);

    return 0;
}



