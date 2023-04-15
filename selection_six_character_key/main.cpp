#include <iostream>
#include <string>
#define LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define FULL_TABL                                                              \
  " !\"#$%&'()*+,-./"                                                          \
  "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`"                         \
  "abcdefghijklmnopqrstuvwxyz{|}~"
using namespace std;

char full(char inp, char out);
char brute_force_of_letters(char inp, char out);
void output(string str);

int main() {
  string letters_big = LETTERS;
  cout << "Enter string: ";
  string input_str;
  getline(cin, input_str);
  int len = input_str.length(), word_flag;
  string out_str;
  out_str.append(len, '0');
  for (int i = 0; i < len; i++) {
    out_str[i] = full(input_str[i], out_str[i]);
    if ((out_str[i] >= 'A' && out_str[i] <= 'Z') ||
        (out_str[i] >= 'a' && out_str[i] <= 'z')) {
      word_flag = i + 1;
      for (int j = word_flag; j < word_flag + 2; j++)
        out_str[j] = brute_force_of_letters(input_str[j], out_str[j]);
      i += 2;
    }
  }
  cout << "your output: ";
  output(out_str);
  return 0;
}

char full(char inp, char out) {
  string full_tabl = FULL_TABL;
  for (int j = 0; j < full_tabl.length(); j++) {
    if (inp != out) {
      out = full_tabl[j];
    } else {
      break;
    }
  }
  return out;
}

char brute_force_of_letters(char inp, char out) {
  string letters = LETTERS;
  for (int j = 0; j < letters.length(); j++) {
    if (inp != out) {
      out = letters[j];
    } else {
      break;
    }
  }
  return out;
}

void output(string str) {
  int len = str.length();
  for (int i = 0; i < len; i++)
    cout << str[i];
}
