#include<iostream>
#include<queue>
using namespace std;

int main(){
    //cout<< (-1)%1<<endl;
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout<< d.front()<<endl;
    cout<< d.back()<<endl;

    d.push_front(15);
    cout<<endl;
    d.pop_back();
    cout<< d.front()<<endl;
    cout<<d.back()<<endl;
    return 0;
}