#include <iostream>
#include "Point.h"
#include "util.h"

using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    p1.print();
    p2.print();
    pp1->print();
    pp2->print();
    cout << "Tavolsag: " << distance(p1, p2) << endl;
    delete pp1;
    delete pp2;
    Point a = {0,0};
    Point b = {2, 0};
    Point c = {2, 2};
    Point d = {0, 2};
    if(isSquare(a, b, c, d))
        cout << "A megadott pontok negyzetet alkotnak!";
    else
        cout << "A megadott pontok nem alkotnak negyzetet!";
    return 0;
}
