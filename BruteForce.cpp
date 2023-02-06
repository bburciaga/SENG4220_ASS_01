#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

string bruteForce (string ciphertext) {
  string plaintext = "key,decryptedText\n";

  // creating file name
  //ofstream MatchingWords("matching.txt");
 
  for (int key = 0; key <= 26; key++) {
    // Add key column and
    plaintext += to_string(key) + ',';
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
  /*string wordlist;
  ifstream wordfile("wordlist.txt");
  while (getline (wordfile, wordlist)) {
    //check for match
    //      if (wordlist == plaintext) MatchingWords << wordlist;
    //use to check
    cout << wordlist <<endl;
    // wordlist is printing line by line
  }
  word.close(); 
  */

  // Formatted in csv format

  return plaintext;
}
