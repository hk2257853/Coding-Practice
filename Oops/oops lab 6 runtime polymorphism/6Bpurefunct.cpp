#include<iostream>
using namespace std;

class A
{
public:
virtual void display()=0;
};

class B: public A
{
public:
void display()
{
cout<<"Class B"<<endl;
}

};

int main()
{
B b;
b.display();
}
