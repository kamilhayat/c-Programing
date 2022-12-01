#include <iostream>
using namespace std;
class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }
    virtual void display() = 0; //  do  nothing function---> pure virtual function
};
// if u make a pure virtual function , then it is neccesary to
// define that function in derived class otherweise it wll give an error.
// if u didnot make that same function in derived claass and also that function
// is not a pure virtual function, then the virtual one
// will be exceuted on the  behlaf that undefined fucntion.
class CWHvid : public CWH
{
protected:
    float viedolength;

public:
    CWHvid(string s, float r, float vl) : CWH(s, r)
    {
        viedolength = vl;
    }
    virtual void display()
    {
        cout << "The title of this viedo is " << title << endl
             << "and the rating is " << rating << " out of 5" << endl
             << "with viedo length " << viedolength << endl;
    }
};
class CWHtxt : public CWH
{
protected:
    float txtcount;

public:
    CWHtxt(string s, float r, int t) : CWH(s, r)
    {
        txtcount = t;
    }
    void display()
    {
        cout << "The title of this tutorial viedo is " << title << endl
             << "and the rating of this txt is " << rating << " out of 5 " << endl
             << "with txt word  of " << txtcount << endl;
    }
};
int main()
{
    string title = "FUCK OFF";
    float rating = 4.54;
    float viedolength = 20;
    int txtcount = 500;
    CWHvid v(title, rating, viedolength);
    // v.display();
    CWHtxt t(title, rating, txtcount);
    // t.display();
    CWH *ptr[2];

    ptr[0] = &v;
    ptr[1] = &t;

    ptr[0]->display();
    ptr[1]->display();

    return 0;
}