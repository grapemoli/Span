/*
  main.cpp
  Grace Nguyen
  09/20/22
  
  solve the span algorithm: for a n-sized data set, return the number of preceeding values that
  are less than the current value
*/


#include <iostream>
#include "span.h"


int main() {
  Span span;

  // get stack/no stack implementation
  bool keepGoing = true;
  bool withStack = false;
  std::string userInput = "";

  while(keepGoing == true) {
    std::cout << "Would you like to get span with the stack implementation? " << std::endl;
    std::cin >> userInput;

    if(userInput != "yes") {
      if(userInput != "no") {
	std::cout << "Please input 'yes' or 'no.'" << std::endl;
      }else{
	withStack = false;
	keepGoing = false;
      } // end if
    }else{
      withStack = true;
      keepGoing = false;
    } // end if

    std::cout << std::endl; // formatting
  } // end while

  // set to stack/without stack implemenation
  span.setWithStack(withStack);

  // get the span
  span.start();
} // end main
