/**
 * An example of how not to compute the average of a set of numbers.
 * Presented as a solution to a programming problem here on campus.
 *
 * How many design problems does this program have?
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int number;          // number of values in the set
  double value;        // value entered at keyboard
  double average;	     // average value
  double total;		     // sum of all values
  char again = 'y';    // repeat running the program
  char validElement;   // consider sentinel value -1 is valid

  while ( toupper(again) == 'Y' ) // loop to run again with another set
  {
    average = 0;
    total = 0;
    value = 0;
    number = 0;
    cout << "The program figures out the average value \n"
      << "of a set of numbers entered at keyboard.\n\n"
      << "NOTE: input validation was included, but not covered all.\n"
      << "      all characters entered for numeric values will be rejected.\n\n";

    fflush(stdin); // empty input buffer

    while (value != -1)  // continue reading in a value until -1 
    {
      cout << "Enter a number or -1 to end: ";
      while ( !(cin >> value) )  // reject if character(s) entered first
      {
        cout << "\nERROR! Invalid entry!\n"
          << "Reenter a number or -1 to end: ";	
        cin.clear();   // reset all bits of I/O stream
        fflush(stdin); // empty input buffer
      }
      if (value != -1)   
      {
        number++;
        total += value;  // add in the accumulator
      }
      else
      {
        cout << "The value -1 is used to end the input.\n"
          << "Is it an element of the set (y/n)? ";
        cin >> validElement;

        while (toupper(validElement) != 'Y' && toupper(validElement) != 'N')
        {
          fflush(stdin);
          cout << "Please enter \'y\' for Yes, or \'n\' for No: ";
          cin >> validElement;			
        }

        if (toupper(validElement) == 'Y')
        {
          number++;
          total += value;  // add in the accumulator
        }
      }
    }

    if (total != 0)
      average = total / number;  // calculate the average value

    // Display the average value.
    cout << fixed << showpoint << setprecision(2);
    cout<< "\nThe average value of the set is: " << average << endl;

    cout << "\nRun again for another set (y/n)? ";
    fflush(stdin); // empty input buffer
    cin >> again;
    while (toupper(again) != 'Y' && toupper(again) != 'N')
    {
      fflush(stdin);
      cout << "Please enter \'y\' for Yes, or \'n\' for No: ";
      cin >> again;			
    }
    cout << "___________________________________________\n\n";
  }

  cout << "\nPress [Enter] key to end ... ";
  fflush(stdin); // empty input buffer
  cin.get();     // read in a character

  return 0;
}
