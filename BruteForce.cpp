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
  while (true) {
    // THe word from the list
    input >> word;

    // At end of list
    if (input.fail()) break;
    // cout << "Word: " << word << endl;

    // lines from plaintext
    istringstream lines(plaintext);
    string line;
    while (getline(lines, line)) {
      string delimiter = " ";
      size_t pos = 0;
      string token;
      
      
      // cout << "Plain Line: " << line << endl;
      // Lets delimit some shit
      
    }
  }

  return plaintext;
}
