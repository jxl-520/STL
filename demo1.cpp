//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，去除最高和最低分
//4. deque容器遍历一遍，累加总分
//5. 获取平均分

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
        string name = "选手";
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

        //排序
        sort(s.begin(),s.end());
        //去头去尾
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
        cout<<"姓名:"<<(*it).getName()<<" ";
        cout<<"各位评委的分数：";
        for(deque<int>::iterator dit = (*it).getScore().begin();dit!=(*it).getScore().end();dit++ ){
            cout<<*dit<<" ";
        }
        cout<<"  最终分数："<<(*it).getAverage()<<endl;
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



