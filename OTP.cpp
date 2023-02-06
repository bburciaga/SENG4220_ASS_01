#include <iostream>
#include <string>

using namespace std;

string otpEncryption(string plaintext, int key[80]) {
  // Used od /dev/random to get these numbers
  // Chose 80 random values due to the server and client
  // using char[80] messages
  string ciphertext = "";
  string lowerPlain = "";

  for (int i = 0; i < plaintext.length(); i++)
    lowerPlain += tolower(plaintext[i]);

  for (int i = 0; i < lowerPlain.length(); i++) {
    if (isalpha(lowerPlain[i])) {
      int num = lowerPlain[i];
      if (num + key[i] > 122) ciphertext += lowerPlain[i] - 26 + key[i];
      else if (num + key[i] < 97) ciphertext += lowerPlain[i] + 26 + key[i];
      else ciphertext += lowerPlain[i] + key[i];
    }
    else ciphertext += lowerPlain[i];
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
