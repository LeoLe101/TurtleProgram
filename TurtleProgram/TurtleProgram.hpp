

#ifndef TurtleProgram_hpp
#define TurtleProgram_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class TurtleProgram
{
public:
    //constructor & destructor
    TurtleProgram();
    TurtleProgram(const TurtleProgram& turtle);
    TurtleProgram(string str1, string str2);
    ~TurtleProgram();

    //getter & setter
    string getIndex(int index) const;
    int getLength() const;
    void setIndex(int index, string str);
    
    //overloading operators
    bool operator==(const TurtleProgram& turtle) const;
    bool operator!=(const TurtleProgram& turtle) const;
    TurtleProgram& operator=(const TurtleProgram& turtle);
    TurtleProgram& operator*=(const int amount);
    TurtleProgram& operator+=(const TurtleProgram& turtle);
    TurtleProgram operator+(const TurtleProgram& turtle) const;
    TurtleProgram operator*(const int amount) const;
    friend ostream& operator<<(ostream& outStream, const TurtleProgram& turtle);

private:
    string* arr;
    int size;
};
#endif /* TurtleProgram_hpp */
