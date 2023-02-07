#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

string bruteForce (string ciphertext) {
//  string plaintext = "key,decryptedText\n";
  string plaintext = "";

  // creating file name
//  ofstream MatchingWords("matching.txt");
 
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

  // We tried to print the filtered answer, but we suck
  // Read from the text file
/*
  string wordlist;
  ifstream wordfile("wordlist.txt");
  while (getline (wordfile, wordlist)) {
    //check for match
    //      if (wordlist == plaintext) MatchingWords << wordlist;
    cout << "Line: " << wordlist <<endl;
  }
  wordfile.close(); 
*/ 

  ifstream input("wordlist.txt");
  string word;
  string hackedText = "";
  // =============Word List loop==================//
  while (true) {
    // THe word from the list
    input >> word;

    // At end of list
    if (input.fail()) break;

    // lines from plaintext
    istringstream lines(plaintext);
    string line;
    // ==============PlainText loop=================//
    while (getline(lines, line)) {
      //cout << "Line: " << line << endl;
      // Lets delimit some shit
      string delimiter = " ";
      size_t pos = 0;
      string token;
      bool flag = false;
      string coolLine = line;
      // ===============Line Loop===================//
      while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        if (word == token) {
          cout << word.compare(token) << endl;
          cout << "Word: " << word << endl;
          cout << "Token: " << token << endl;
          flag = true;
        }
        line.erase(0, pos + delimiter.length());
      }
//      if (flag) hackedText += coolLine + "\n";
    }
  }

  return hackedText;
}
