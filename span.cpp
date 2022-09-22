/*
  span.cpp
  Grace Nguyen
  09/20/22
*/
 

#include "span.h"


// constructors
Span::Span() {
  std::cout << "Input an integer for the dataset size (must be greater/equal to than 0): ";
  std::cin >> this->n;
  
  std::cout << std::endl; // formatting
  
  this->withStack = true;
} // end null constructor

Span::Span(bool withStack) {
  std::cout << "Input an integer for the dataset size (must be greater/equal to than 0): ";
  std::cin >> this->n;
  
  std::cout << std::endl; // formatting

  this->withStack = withStack;
} // end constructor


// getters and setters
int Span::getN() {
  return(this->n);
} // end getN

void Span::setN(int n) {
  this->n = n;
} // end setN

void Span::setWithStack(bool withStack) {
  this->withStack = withStack;
} // end setWithStack

bool Span::getWithStack() {
  return(this->withStack);
} // end bool


// start method
void Span::start() {
  // ask user for max value for data set
  int maxValue = 9999;
  std::cout << "Input a maximum integer value (must be greater than 0): ";
  std::cin >> maxValue;
  std::cout << std::endl; // formatting

  // create an array of n size using n as the seed
  srand(this->n);
  int dataSet[this->n];

  for(int i = 0; i < this->n; i++) {
    dataSet[i] = rand()%maxValue;

    // run non-stack implementation if applicable
    if(this->withStack == false) {
      int span = this->calculateSpan(&dataSet[0], i);
      this->printSpan(i, dataSet[i], span);
    } // end if
  } // end for

  // run the stack implementation if applicable
  if(this->withStack == true) {
    this->calculateSpanStack(&dataSet[0]);
  } // end if
} // end start


// printing method
void Span::printSpan(int index, int value, int span) {
  std::cout << (index+1) << ")	|VALUE: " << value << "		|SPAN: " << span << std::endl;
} // end print


// non-stack methods
int Span::calculateSpan(int *dataSet, int index) {
  // calculates the span by backwards from the index,
  // stopping when getting a value higher than the passed indices' value
  // returns the span length
  int span = 1; 
  int rootValue = *(dataSet + index);
  bool keepGoing = true;

  while(keepGoing == true) {
    // start at the index, and compare values going backwards
    index--;

    // only continue comparing if within bounds!!
    if(index < 0) {
      keepGoing = false;
    }else{
      int currentValue = *(dataSet + index);

      // comparisons
      if(currentValue > rootValue) {
	keepGoing = false;
      }else{
	span++;
      } // end if-else

    } // end if-else
  } // end while

  return(span);

} // end calculate Span


// stack calculation methods
void Span::calculateSpanStack(int *dataSet) {
  // calculate the span using the stack implementation
  // returns nothing, but prints the span of each dataset
  int currentIndex = 0;

  while(currentIndex < this->n) {
    int currentValue = *(dataSet + currentIndex);
    int span;

    // check the size of the stack
    if(this->highestIndex.size() == 0) {
      // an empty stack implies that the current value is the highest value so far
      // therefore the span must be the index
      span = currentIndex + 1; 
      this->printSpan(currentIndex, currentValue, span);
      this->highestIndex.push(currentIndex);
      currentIndex++;
    }else{
      int topIndex = this->highestIndex.top();
      int topValue = *(dataSet + topIndex);

      // if the top value is greater than the current value, push the current index to the stack
      // else, the current value is greater/equal to the stack top value: push to top of stack
      if(topValue > currentValue) {
	span = currentIndex - topIndex;

	this->printSpan(currentIndex, currentValue, span);
        this->highestIndex.push(currentIndex);
        currentIndex++;
      }else{ 
        // does not increment currentIndex because will
	// keep comparing highestIndex with the top of the stack until 
	// top of stack is greater, or stack is empty
	this->highestIndex.pop(); 
      } // end if-else
    } // end if-else  
  } // end while

} // end calculateSpanStack
