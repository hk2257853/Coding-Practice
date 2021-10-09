#include <iostream>
using namespace std;

//Copy constructor: Initialize the object using other object.

//Question: There's so much to knowledge. What's the best way to go?
//options: Best: learn as I go - can be done for dev only. Interviews will ask basic stuff. Exams may also not ask that remote detail.
//Best way: Real world use, extra detail I get during offline n lab class. For video continue doing 1hr video in 10 min n make notes.

//This is final plz do not over fit like I did for friend function. Its fine if I miss a concept or 2.

class code
{
    private:
    int x;

    public:
    code(int a)
    {
    x=a;
    }

    code(code &ob)
    {
    x=ob.x;
    }

    void display()
    {
    cout<<x<<endl;
    }
};

int main()
{
    code A(10);
    code B(A);

    A.display();
    B.display();

    return 0;
}
