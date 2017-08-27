#include "String.h"
#include <iostream>

using namespace std;

void printStr(String s) 
{
    cout << s.size() << ": ";
    for (int i = 0; i < s.size(); i++) cout << s.at(i);
    cout << endl << "----------------------------" << endl;
}

int main() {
    cout << "----------------------------" << endl;
    cout << "Testing Default Constructor" << endl;
    String empty;
    printStr(empty);

    cout << "Testing String Literal Constructor" << endl;
    String daTruth = "Arianne is awesome!";
    printStr(daTruth);

    cout << "Testing Copy Constructor" << endl;
    String cpy(daTruth);
    printStr(cpy);

    cout << "Testing Assignment Operator" << endl;
    String test = "meemememe";
    String meh = "hmmmm";
    test = meh;
    printStr(test);

    cout << "Testing + Concatentation" << endl;
    String first = "Hello, ";
    String second = "world!";
    printStr(first + second);

    cout << "Testing += Concatenation" << endl;
    first += second;
    printStr(first);

    cout << "Testing Concatenation with Characters" << endl;
    String hop = "Hop + s = Hop";
    printStr(hop + 's');

    cout << "Testing Substring Function" << endl;
    String name = "Scott Edwards";
    printStr(name.substr(0, 5));

    return 0;
}
