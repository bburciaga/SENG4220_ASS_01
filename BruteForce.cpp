#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

string bruteForce (string ciphertext) {
  string plaintext = "";
 
  for (int key = 0; key <= 26; key++) {
    // Add key column and
    //plaintext += to_string(key) + ',';
    for (int index = 0; index <= ciphertext.length(); index++) {
      // Check if char at j is string
      if (isalpha(ciphertext[index])) {
        // Get character number
        int num = ciphertext[index];
        if (num + key > 122) plaintext += ciphertext[index] - 26 + key;
        else if (num - key > 122) plaintext += ciphertext[index] - 26 + key;
        else plaintext += ciphertext[index] + key;
      }
      // Add to string if it's not alphabetical
      else plaintext += ciphertext[index];
    }
    // Print a new line
    plaintext += '\n';
  }

  istringstream lines(plaintext);
  string line;
  string hackedText = "";
  string dupLine;
  //================PlainText Loop================//
  while (getline(lines, line)) {
    dupLine = line;
    string delimiter = " ";
    size_t pos = 0;
    int counter = 0;
    int wordCounter = 0;
    string token;

    //cout << "Line: " << line << endl;

    //=================Line Loop=================//
    while ((pos = line.find(delimiter)) != string::npos) {
      ifstream input("wordlist.txt");
      string word;
      // Create subword from pos to delimiter " "
      token = line.substr(0, pos);
      
      //cout << "Token: " << token << endl;
      wordCounter++;

      while (true) {
        // THe word from the list
        input >> word;

        // At end of the word list
        if (input.fail()) break;

        if (word == token) {
          //cout << "Token: " << token << endl;
          //cout << "Word: " << word << endl;
          counter++;
        }
      }
      // Erase word from 0 to delimiter " "
      line.erase(0, pos + delimiter.length());
    }
    //cout << "Counter: " << counter << endl;
    if (counter >= wordCounter - 1) {
      hackedText += dupLine + "\n"; 
    }
  }

  return hackedText;
}
