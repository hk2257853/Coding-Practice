//create n destrop 5 objects to under stand the concept and the order in which objects r destroyed

#include <iostream>
using namespace std;

int check;

//Yeah this gets destroyed in reverse order.

class code
{
int value;
public:
    code()
    {
    value=check;
    cout<<"Hi there! "<<value<<endl;
    check++;
    }

    ~code()
    {
    cout<<"Bye "<<value<<endl;
    }
};

int main()
{
    code a,b,c,d; //if I make array of objects will all get called at once? If yes DMA will be better to make objects.
    cout<<"Hello there. There's no code after this so program will exit"<<endl;
}

//Even if I dont make the des, compiler autometically makes it. Then when actually I need des in real life.
// This is the only ques. Don't search anything else.
