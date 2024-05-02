#include <iostream>
#include <string>

using namespace std;

class Square {
    int x;

public:
    Square(int _x): x(_x) {}

    void setX(int _x) { x = _x; }
    int getX() const { return x; }
    virtual void print() const { cout << "Square!\n"; }

    virtual ~Square() {}
};

class Rectangle : public Square{
    int y;

public:
    Rectangle(int _x , int _y) : Square(_x) { y = _y; };

    int getY() const {
        return y;
    }

    void setY(int y) {
        Rectangle::y = y;
    }

    void print() const { cout << "Rectangle!\n"; }

    virtual ~Rectangle() {}
};
//is a square
class Foo : public Square {
public:
    using Square::Square;
    void print() const { cout << "FOO!\n"; }

    virtual ~Foo() {}
};

void foo(const Square& s) { // with virtual we need to use references or pointers!
    s.print();
}

int main() {
    Square s(8);
    Rectangle r(2 , 3);

    Square *sptr = &r;
    //  Rectangle *rptr = &s; // this wont work because a square is a rectangle but a rectangle is not a square
    foo(r);
    sptr->print();

//    Create array of Square pointers

    Square* squares[] = {new Square(3), new Rectangle(1, 2), new Foo(1) };

    cout << " ------------------------ \n";
    for (Square* s: squares) {
        s->print();
    }

    for (Square* s: squares) {
        delete s;
    }

    cin.ignore();
    return 0;
}
