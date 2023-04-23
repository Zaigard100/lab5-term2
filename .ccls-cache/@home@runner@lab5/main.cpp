#include <bitset>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string toBinary(unsigned int n) {
  string buf = "1";
  if (n / 2 != 0) {
    buf = toBinary(n / 2);
    buf = buf + to_string(n % 2);
  }
  return buf;
}
char num_isPolindrom(int num, unsigned len) {
  short mask = pow(2, len - 1);
  short masked = 0;
  short pol = 0;
  short old_num = num;
  unsigned i = 0;
  while (mask != 0) {
    masked = num & mask;
    if (masked / mask == 1) {
      pol += pow(2, i);
      masked = 0;
    }
    num = num & ~mask;
    mask = mask >> 1;
    i++;
  }
  if (old_num == pol) {
    return 't';
  }
  return 'n';
}

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Использование(shell): ./main <двоичное число (от 1-го до 8 байт)>" << endl;
    return 0;
  } else {
    string binary = argv[1];

    unsigned str_len = binary.length();

    int num = 0;

    for (unsigned i = 1; i <= str_len; i++) {
      if (binary[str_len - i] == '1') {
        num += pow(2, i - 1);
      }
    }

    str_len = toBinary(num).length();
    char res = num_isPolindrom(num, str_len);
    if (res == 't') {
      cout << "Число " << toBinary(num) << '(' << num << ')'
           << " является палиндромом." << '\n';
    } else if (res == 'n') {
      cout << "Число " << toBinary(num) << '(' << num << ')'
           << " не является палиндромом." << '\n';
    }
    return 0;
  }
}