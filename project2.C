#include <iostream>
#include <fstream>
using namespace std;

#include "myStrCharFunc.h"

const int SIZE = 26;
const int MAX = 30;
typedef char cstr[MAX];
struct word
{
  int freq;
  cstr longest;
  cstr shortest;
};

//PROTOTYPES**************************
void initArray(word ar[]);
void readFile(word ar[]);
void processWord(cstr word, word ar[]);
void printInfoOnAllLetters(word ar[]);
void printInfoOnOneLetter(word ar[]);
//************************************

int main()
{
  word ar[SIZE];
  initArray(ar);
  readFile(ar);
  //cout << ar[0].longest;
  int menu;
  do{
    
    cout << "\n1. Show information on all the letters\n2. Show the information on one letter\n3. Quit the program\nEnter your choice here: ";
    cin >> menu;
    cout << endl;
    switch(menu)
      {
      case 1 : printInfoOnAllLetters(ar);
	break;
      case 2 : printInfoOnOneLetter(ar);
	break;
      case 3 : cout << "Good Bye!" << endl; exit(0);
	break;
      default: cout << "Invalid choice. Try again.\n" << endl;
      }
  }while(!(menu == 3));
  
  return 0;
}

void initArray(word ar[])
{
  for(int i = 0; i < SIZE; i++)
    {
      ar[i].freq = 0;
      myStrcpy(ar[i].longest, "");
      myStrcpy(ar[i].shortest, "                             ");
    }
}

void readFile(word ar[])
{
  cstr word;
  ifstream inFile;

  inFile.open("wordInput.dat");

  inFile >> word;

  while(inFile)
    {
      processWord(word, ar);
      inFile >> word;
    }
}

void processWord(cstr word, word ar[])
{
  int i;
  bool found = false;
  for(i = 0; i < SIZE && !found; i++)
    {
      if(word[0] == 65+i || word[0] == 97+i)
	{
	  ar[i].freq++;
	  found = true;
	}
    }

  if(myStrLen(word) > myStrLen(ar[i].longest))
    myStrcpy(ar[i].longest, word);

  if(myStrLen(word) < myStrLen(ar[i].shortest))
    myStrcpy(ar[i].shortest, word);
}

void printInfoOnAllLetters(word ar[])
{
  for(int i = 0; i < SIZE; i++)
    {
      cout << (char)(65+i) << " " << ar[i].freq << ": ";
      for(int a = 0; a < ar[i].freq; a++)
	cout << "*";
      cout << " " << ar[i].longest << " - " << ar[i].shortest;
      cout << endl;
    }
}

void printInfoOnOneLetter(word ar[])
{
  char letter;

  cout << "Which letter are you interested in?: ";
  cin >> letter;
  letter = (int)letter - 65;
  cout << endl;

  cout << "Frequency: " << ar[letter].freq << endl;
  cout << "Longest: " << ar[letter].longest << endl;
  cout << "Shortest: " << ar[letter].shortest << endl;
  cout << endl;
}
