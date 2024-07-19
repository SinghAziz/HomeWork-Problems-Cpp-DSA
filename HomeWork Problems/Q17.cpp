/* Problem Statement
Number of 100,50,20,1 notes in the given amount
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the amount: ";
    cin>>n;

    switch (n%100){
        case 0:cout<<"Number of 100 Notes are: "<<n/100;
                exit(0);

        }
                cout<<"Number of 100 Notes are: "<<n/100<<endl; 
                switch (n%50){
                    case 0: 
                        cout<<"Number of 50 Notes are: "<<(n-((n/100) *100))/50<<endl;
                }
                     cout<<"Number of 50 Notes are: "<<(n-((n/100) *100))/50<<endl;
                        switch (n%20){
                            case 0:
                                cout<<"Number of 20 Notes are: "<<(n-((n/50) *50))/20<<endl;
                                }

                                switch (n%1){
                                    cout<<"Number of 20 Notes are: "<<(n-((n/50) *50))/20<<endl;
                                    cout<<"Number of 1 Notes are: "<<(n-((n/20) *20))/1<<endl;
                                }
                        }


