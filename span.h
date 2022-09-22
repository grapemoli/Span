/*
  span.h
  Grace Nguyen
  09/20/2022
*/


#ifndef SPAN_H_EXISTS
#define SPAN_H_EXISTS

#include <iostream>
#include <stack>

class Span {
  private:
    int n;
    std::stack<int> highestIndex;
    bool withStack;
  
  public:
    Span();
    Span(bool withStack);


    // getters and setters 
    void setN(int n);
    int getN();
    void setWithStack(bool withStack);
    bool getWithStack();


    // stack methods for span
    void calculateSpanStack(int* dataSet);
    

    // non-stack methods for span
    int calculateSpan(int* dataSet, int index);


    // printing method
    void printSpan(int index, int value, int span);


    // other methods
    void start();
}; // end class def

#endif
