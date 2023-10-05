#include<iostream>
#include<vector>
#include<string>
#include <functional>
using namespace std;

 struct Test
 {

    string Str; 
    Test(const string s) :Str(s)
    { 
         cout<<Str<<" Test1() "<<this<<endl;
    }
    
    Test(const Test &obj)
    { 
        cout<<obj.Str<<" Test2() "<<this<<endl;
        Str = obj.Str;
    }

    ~Test()
    { 
         cout<<Str<<" ~Test() "<<this<<endl; 
    }
 };

 struct TestWrapper
 {
    vector<Test> vObj;
    TestWrapper(const string s)
    {
       cout<<"TestWrapper() "<<this<<endl;
       vObj.push_back(Test(s));
    }

    ~TestWrapper() 
    { 
       cout<<"~TestWrapper() "<<this<<endl;
    }
 };

int main ()
{
   TestWrapper obj("ABC");
}