/*=====================================================================================================
Design a function that receives a string and processes the characters in that string into reverse order.
For example: change string “HOW ARE YOU TODAY?” to “?YADOT UOY ERA WOH”. Use a
main function to call this function and repeatedly ask user to input different strings until the user
responses with a CTRL-Z key to exit the program.
=====================================================================================================*/

#include <iostream>
#include <cstring>

using namespace std;

string reverseString(string sentence){
  int lenth = sentence.size();
  for(size_t i = 0; i < lenth/2; i++){
    swap(sentence[i], sentence[lenth - i - 1]);
  }
  return sentence;
}

int main(){
  string inputStuff;
  
  cout << "Please enter a sentence (CTRL-Z for Windows or CTRL-D for Unix/Linux to exit): \n";
  while (getline(cin, inputStuff)) {
    cout << "The reverse sentence: " << reverseString(inputStuff) << endl;
    cout << "Please enter another sentence (CTRL-Z for Windows or CTRL-D for Unix/Linux to exit): \n";
  }

  return 0;
}
