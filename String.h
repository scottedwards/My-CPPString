#ifndef STRING_H
#define STRING_H

#include <iostream>

/** 
 *  My String Class.
 *  A wrapper for C style strings for use in C++.
 */
class String
{
    public:
                /**
                 *  Default Constructor.
                 *  Creates an empty string.
                 */
                String();
                /**
                 *  String Literal Constructor.
                 *  A constructor that makes a String object from a given
                 *  const char * or "xxxx".
                 */
                String(const char * s);
                /**
                 *  Copy Constructor.
                 *  Initialises the String's properties by copying data 
                 *  from another String object.
                 */
                String(const String &o);
                /**
                 *  Strng Deconstructor.
                 *  De-allocates the data pointer so no memory leakage occurs.
                 */
                ~String();

        /** 
         *  A normal member that returns an integer.
         *  @return the length of the string being held.
         */
        int     size() const;
        /**
         *  Gets the character ata given index.
         *  @param i the index you wan't to access.
         *  @return the character you want to access.
         */
        char    at(int i) const;
        /**
         *  An overload for the += operator.
         *  Allows you to concatenate another string to the current string.
         *  @param o the string you want to concatonate to this string.
         *  @return the modified string.
         */
        String  &operator+=(const String &o);
        /**
         *  An overload for the += operator.
         *  Allows you to concatenate a single character.
         *  @param o the character you want to concatonate to this string.
         *  @return the modified string.
         */
        String  &operator+=(const char &o);
        /**
         *  An overload for the assignment operator.
         *  Allows you to set/change the string being stored to the string from
         *  another String class.
         *  @param o the string you want this string to become.
         *  @return the modified string.
         */
        String  &operator=(String o);
        /**
         *  Get the substring of the held string.
         *  @param start the index you want to start copying from (0 based).
         *  @param end where you want the copy to end.
         *  @return a string that contains the substring.
         */
        String  &substr(int start, int end);

    private:
        /**
         *  The string data.
         *  A character array that stores the string (null terminated)
         */
        char *  data;
        /**
         *  The size of the string.
         *  Includes the trailing null.
         */
        int     n;

        /**
         *  An overload for the output stream operator.
         *  Needs to be a friend function defined OUTSIDE of the class as when using
         *  ostream << String you do not have access to the ostream so they can't be 
         *  member operators.
         *  @param os the ostream you're outputting the string too.
         *  @param o the string you want to output.
         *  @return the ostream with the string 'inside' so you can chain it outside 
         *  of this function.
         */
        friend std::ostream & operator<<(std::ostream &os, const String &o);
        /**
         *  A swapping function.
         *  Swaps the data from string to another and visa-versa. Uses the std::swap function.
         */
        friend void swap(String &first, String &second);

};

/**
 *  An overload for the + operator.
 *  Takes two strings and outputs a copy of the concatenation.
 *  @param lhs a copy of the left hand side of the operation.
 *  @param rhs the actual right hand side of the operation.
 *  @return the sum of lhs + rhs
 */
inline String operator+(String lhs, const String &rhs)
{
    lhs += rhs;
    return lhs;
}


/**
 *  An overload for the + operator.
 *  Takes a String and a character value, and outputs a copy of the concatenation.
 *  @param lhs a copy of the left hand side of the operation.
 *  @param rhs the character you want to add to the end of the string.
 *  @return the sum of lhs + rhs
 */
inline String operator+(String lhs, const char &rhs)
{
    lhs += rhs;
    return lhs;
}

#endif
