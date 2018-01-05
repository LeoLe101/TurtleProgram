// Comment here!
#include <iostream>
#include <stdio.h>
#include "TurtleProgram.hpp"
using namespace std;

int main()
{
    TurtleProgram tp1;
    cout << "tp1: " << tp1 << endl;
    TurtleProgram tp2("F", "10");
    cout << "tp2: " << tp2 << endl;
    TurtleProgram tp3("R", "90");
    tp1 = tp2 + tp3;
    cout << "tp1 now as tp2+tp3: " << tp1 << endl;
    tp1 = tp2 * 3;
    cout << "tp1 now as tp2 * 3: " << tp1 << endl;
    TurtleProgram tp4(tp1);
    cout << "tp4 is a copy of tp1: " << tp4 << endl;
    TurtleProgram tp5("F", "10");
    cout << "tp5: " << tp5 << endl;
    cout << boolalpha;
    cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
    cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
    cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
    tp2.setIndex(0, "R");
    tp2.setIndex(1, "90");
    cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
    cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
    //additional tests
    tp1 *= 4;
    cout << "tp1 *= 4: " << tp1 << endl;
    tp1 += tp2;
    cout << "tp1 += tp2: " << tp1 << endl;
    
    cout << "Done." << endl;
    
    //reallocate the array of each instructions program
    tp1.~TurtleProgram();
    tp2.~TurtleProgram();
    tp3.~TurtleProgram();
    tp4.~TurtleProgram();
    tp5.~TurtleProgram();
    
    return 0;
}
