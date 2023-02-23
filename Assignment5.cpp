// Marc Jacques
// Assignment 5 Part 1

//a 10 20
//b 20 10
/*c
  The swapValue method does not impact the variables 'i' or 'n' outside of the method. Because a copy of the value is passed and not the actual value this method creates a new object and stores the value in a different location in memory. The original value is unaffected.
  
The swapReference method passes a reference to the location where the actual value is stored in memory. Because of this we are actually manipulating the data that is stored in that memory location. Since the original vriable is referring to the same memory location any changes that occur in the method impacts the original variable.
*/

//Part 2
#include <iostream>
using namespace std;

bool grade(char[], char[], int&, int&);
char inputValidation(int, int&, char&);
int main()
{
  const int SIZE = 10;
  char correctAnswers[SIZE] = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D'};
  char studentAnswers[SIZE];
  int correct = 0, incorrect = 0;
  bool pass;
  
  for(int i = 0; i < 10; i++)
    {
      char answer;
      int count = 0;
      
      cout << "Enter answer for #"<< i  + 1<<": ";
      cin >> answer;
      
      studentAnswers[i] = inputValidation(i, count, answer);
    }

  pass = grade(studentAnswers, correctAnswers, correct, incorrect);
  
  if(pass == true) 
  {
    cout << "Congratulations!\nYou have passed exam.\nTotal number of correct answers: "<< correct<<"\nTotal number of incorrect answers: "<<incorrect;
  } else {
    cout << "Sorry, You have not passed the exam!\nTotal number of correct answers: "<< correct<<"\nTotal number of incorrect answers: "<<incorrect;
  }
  return 0;
}

bool grade(char studentResponse[], char answerKey[], int& correct, int& incorrect)
{

  // for loop to iterate through each array
  for(int i = 0; i < 10; i++)
    {
      // compare each corresponding value
      if(studentResponse[i] != answerKey[i])
      {
        incorrect++;        
      } else {
        correct++;
      }
    }
  return correct >= 8;
}

char inputValidation(int questionNumber, int& totalInvalidInputs, char& answer)
{
  //check totalinValid
  while(totalInvalidInputs <= 3)
    {
      if(totalInvalidInputs >= 3)
      {
        cout << "GOOD BYE"<< endl;
        abort();
      }
      if(answer < 65 || answer > 68)
      {
        totalInvalidInputs++;
        cout << "The only valid inputs are 'A', 'B', 'C', or 'D'\n";
        cout << "Enter answer for #"<< questionNumber  + 1<<": ";
        cin >> answer;
      } else {
        return answer;
      } 
    }
  
  return answer;
}