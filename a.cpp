#include<bits/stdc++.h>
using namespace std;

class A{
    public :
        //IF WE DO NOT CREATE VIRTUAL FUNCTION 
        //THEN WE CAN NOT CALLED TE CHILD CLASS FUNCTION WITH BASE CLASS POINTER 
        virtual void display()
        {
            cout << "CLASS A\n";
        }
};
class B : public A{
    public :
        void display()
        {
            cout << "CLASS B\n";
        }
};

int main()
{
    // A a;
    // a.display();
    A *a;
    A c;
    B b;

    a = &c;
    a->display();

    a = &b;
    a->display();
    return 0;
}
