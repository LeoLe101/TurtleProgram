

#include "TurtleProgram.hpp"

//constructors, copy constructor & destructor
TurtleProgram::TurtleProgram()
{
    arr = NULL;
    size = 0;
}

TurtleProgram::TurtleProgram(const TurtleProgram& turtle)
{
    size = turtle.size;
    arr = new string[size];     //set arr size
    arr = turtle.arr;           //copy instructions
}

TurtleProgram::TurtleProgram(string str1, string str2)
{
    size = 2;
    arr = new string[size];
    arr[0] = str1;
    arr[1] = str2;
}

TurtleProgram::~TurtleProgram()
{
    if (size != 0 || arr != NULL) {
        delete[] arr;               //free memory pointed to by arr
        arr = NULL;                 //prevent invalid memory reference
        size = 0;
    }
}

//getter & setter
string TurtleProgram::getIndex(int index) const
{
    string result;
    //check invalid index
    if (index > size || index < 0)
    {
        result = "Invalid index!";
    }
    else
    {
        result = arr[index];
    }
    return result;
}

int TurtleProgram::getLength() const
{
    return size;
}

void TurtleProgram::setIndex(int index, string str)
{
    //check invalid index
    if (index > size || index < 0)
    {
        cout << "Invalid index!";
    }
    else
    {
        arr[index] = str;
    }
}


//overloading operators
bool TurtleProgram::operator==(const TurtleProgram& turtle) const
{
    bool result = true;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != turtle.arr[i]) {
            result = false;
            return result;
        }
    }
    return result;
}


bool TurtleProgram::operator!=(const TurtleProgram& turtle) const
{
    bool result = true;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == turtle.arr[i]) {
            result = false;
            return result;
        }
    }
    return result;
}

//overloading operator = for the program.
//The param required another program 
TurtleProgram& TurtleProgram::operator=(const TurtleProgram& turtle)
{
    size = turtle.size;
    if (arr != NULL) {
        delete[] arr;
    }
    arr = new string[size];
    for (int i = 0; i < size; i++) {
        arr[i] = turtle.arr[i];
    }
    return *this;
}

//overloading operator *= for the program.
//The param required a certain amount of time
//to be multiplied.
TurtleProgram& TurtleProgram::operator*=(const int amount)
{
    int check = 0;
    int growSize = 0;
    int cpySize = size * amount;
    string* cpyArr = new string[cpySize];
    //check invalid amount
    if (amount == 0 || amount < 0) {
        cout << "Invalid amount! Please enter another number." << endl;
        return *this;
    }
    //copy all data from old arr to new arr
    while (check != amount)
    {
        for (int i = 0; i < size; i++)
        {
            if (growSize < cpySize)
            {
                cpyArr[growSize] = arr[i];
                growSize++;
            }
        }
        check++;
    }
    if (arr != NULL)
    {
        delete[] arr;
    }
    arr = cpyArr;
    size = cpySize;
    return *this;
}

//overloading the operator += for the program.
//The param required another program in order
//to increment current program's instructions
TurtleProgram& TurtleProgram::operator+=(const TurtleProgram& turtle)
{
    int cpySize = size + turtle.size;
    string* cpyArr = new string[cpySize];
    //copy all data from old arr to new arr
    for (int i = 0; i < size; i++) {
        cpyArr[i] = arr[i];
    }
    //add the data from another instruction program to current program
    for (int i = size - 1; i < cpySize; i++) {
        cpyArr[i] = turtle.arr[i];
    }
    if (arr != NULL) {
        delete[] arr;
    }
    arr = cpyArr;
    size = cpySize;
    return *this; //return the current program
}

//overloading the operator + by utilizing the
//operator += coded above.
//The param required another program for implementation
TurtleProgram TurtleProgram::operator+(const TurtleProgram& turtle) const
{
    TurtleProgram result = *this;
    result += turtle;
    return result;
}

//overloading the operator * by utilizing the
//operator *= coded above.
//The param required an amount of time to be
//multiply for implementation
TurtleProgram TurtleProgram::operator*(const int amount) const
{
    TurtleProgram result = *this;
    result *= amount;
    return result;
}

//overloading operator << to fit the output
//of current program. This function will
//put all the element of the program to the screen
ostream& operator<<(ostream& outStream, const TurtleProgram& turtle)
{
    outStream << "[ ";
    for (int i = 0; i < turtle.size; i++)
    {
        outStream << turtle.arr[i] << " ";
    }
    outStream << "]";
    return outStream;
}
