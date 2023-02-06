#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string caesarEncryption(string plaintext, int key) {
  string ciphertext = "";
  string lowerPlain = "";
  
  for (int i = 0; i < plaintext.length(); i++)
    lowerPlain += tolower(plaintext[i]);

  cout << lowerPlain << endl;
  
  for (int i = 0; i < lowerPlain.length(); i++) {
    if (isalpha(lowerPlain[i])) {
      int num = lowerPlain[i];
      if (num + key > 122) ciphertext += lowerPlain[i] - 26 + key;
      else if (num + key < 97) ciphertext += lowerPlain[i] + 26 + key;
      else ciphertext += lowerPlain[i] + key;
    }
    else ciphertext += lowerPlain[i];
  }
  return ciphertext;
}

string caesarDecryption(string ciphertext, int key) {
  return caesarEncryption(ciphertext, -1 * key);
}

/*int main()
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
}*/
