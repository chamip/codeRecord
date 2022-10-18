/*
 * @Author: chamip
 * @Date: 2022-04-13 17:25:26
 * @LastEditTime: 2022-04-13 19:07:32
 * @LastEditors: chamip
 * @FilePath: /vscCpp/hackrank/virtual_func.cpp
 */
// url: https://www.hackerrank.com/challenges/virtual-functions/problem?h_r=next-challenge&h_r=next-challenge&h_r=next-challenge&h_v=zen&h_v=zen&h_v=zen&isFullScreen=true
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    protected:
        char name[100];
        int age;
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0; 
};

class Professor: public Person {
    private:
        static int id;
        int pub;
        int cur_id;
    public:
        Professor() {cur_id = ++id;};
        void getdata() {
            cin >> name >> age >> pub;
            return ;
        }
        void putdata() {
            cout << name << " " << age << " " << pub << " " << cur_id << endl;
            return ;
        }
};
int Professor::id = 0;

class Student: public Person {
    private:
        static int id;
        int marks[6];
        int cur_id;
    public:
        Student() {cur_id = ++id;};
        void getdata() {
            cin >> name >> age;
            for (int i = 0; i < 6; ++i) {
                cin >> marks[i];
            }
            return ;
        }        
        void putdata() {
            int sum = 0;
            for (int i = 0; i < 6; ++i) {
                sum += marks[i];
            }
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
            return ;
        }
};
int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
