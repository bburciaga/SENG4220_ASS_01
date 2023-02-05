#include <iostream>
#include <string>

using namespace std;

string otpEncryption(string plaintext, int key[80]) {
  // Used od /dev/random to get these numbers
  // Chose 80 random values due to the server and client
  // using char[80] messages
  string ciphertext = "";

  for (int i = 0; i < plaintext.length(); i++) {
    if (isalpha(plaintext[i])) {
      int num = plaintext[i];
      if (num + key[i] > 122) ciphertext += plaintext[i] - 26 + key[i];
      else if (num + key[i] > 122) ciphertext += plaintext[i] + 26 + key[i];
      else ciphertext += plaintext[i] + key[i];
    }
    else ciphertext += plaintext[i];
  }

  return ciphertext;
}

string otpDecryption(string ciphertext, int key[80]) {
  int newKey[80];
  for (int i = 0; i < 80; i++) {
    newKey[i] = key[i] * -1;
  }
  return otpEncryption(ciphertext, newKey);
}
