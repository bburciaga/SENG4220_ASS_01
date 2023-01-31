#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string caesarEncryption(string plaintext, int key)
{
  string ciphertext = "";
  for (int i = 0; i < plaintext.length(); i++) {
    if (isalpha(plaintext[i])) {
      // Task 1. Remove this line and write a code to encrypt this char with key using Caesar Encryption
      int num = plaintext[i];
      if (num + key > 122) ciphertext += plaintext[i] - 26 + key;
      else if (num + key < 97) ciphertext += plaintext[i] + 26 + key;
      else ciphertext += plaintext[i] + key;
    }
    else ciphertext += plaintext[i];
  }
  return ciphertext;
}

string caesarDecryption(string ciphertext, int key)
{
  // Task 2 - Complete this function

  return caesarEncryption(ciphertext, -1 * key);
}

int main()
{
  int key;
  string plaintext;
  cout << "Enter your message: ";
  getline(cin, plaintext);
  cout << "Enter your key: ";
  cin >> key;
  string encryptedText = caesarEncryption(plaintext, key);
  string decryptedText = caesarDecryption(encryptedText, key);
  cout << "The Ciphertext is: " << encryptedText << endl;
  cout << "The Plaintext  is: " << decryptedText << endl;
  return 0;
}
