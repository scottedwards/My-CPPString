#include "String.h"
#include <iostream>

String::String()
{
    this->data = new char[1];
    *data = '\0';
    this->n = 1;
}

String::String(const char * s)
{
    //Get the size of the string passed into the class
    this->n = 0;
    while (*(s + n++) != '\0');

    this->data = new char[n];
    for (int i = 0; i < n; i++) *(this->data + i) = *(s + i);
}

String::String(const String &o)
{
    this->n = o.size() + 1;
    this->data = new char[n + 1];
    for (int i = 0; i <= n; i++) *(this->data + i) = o.at(i);
}

String::~String()
{
    delete[] data;
}

void swap(String &first, String &second)
{
    using std::swap;

    swap(first.data, second.data);
    swap(first.n, second.n);
}

int String::size() const
{
    return (this->n) - 1;
}

char String::at(int i) const
{
    return *(this->data + i);
}

String & String::operator+=(const String &o)
{
    char * newBuffer = new char[this->size() + o.size() + 1];

    //copy over 'this' string to the new buffer
    int index = 0;
    while (this->at(index) != '\0')
    {
        *(newBuffer + index) = this->at(index);
        index++;
    }

    //copy over the param string into the buffer with the offset 
    //of the length of the string that's allready in the buffer
    int secondIndex = 0;
    while (o.at(secondIndex) != '\0')
    {
        *(newBuffer + index + secondIndex) = o.at(secondIndex);
        secondIndex++;
    }

    //include the trailing null
    *(newBuffer + index + secondIndex + 1) = '\0';


    //de-allocate the current string buffer and replace it with newBuffer
    delete[] this->data;
    this->data = newBuffer;
    this->n = index + secondIndex + 1;

    return *this;
}

String & String::operator+=(const char &c)
{
    char * newBuffer = new char[this->size() + 2];

    for (int i = 0; i < this->size(); i++)
    {
        *(newBuffer + i) = this->at(i);
    }

    *(newBuffer + this->size()) = c;
    *(newBuffer + this->size() + 1) = '\0';

    //de-allocate the current string buffer and replace it with newBuffer
    delete[] this->data;
    this->data = newBuffer;
    this->n += 1; 
    return *this;
}

String & String::operator=(String o)
{
    swap(*this, o);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &o)
{
    for (int i = 0; i < o.size(); i++)
    {
        os << o.at(i);
    }
    return os;
}

String & String::substr(int start, int end)
{
    String * sub = new String(); 
    for (int i = start; i < end; i++)
    {
        *sub += *(this->data + i);
    }
    return *sub;
}

