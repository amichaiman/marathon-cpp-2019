#include <iostream>
using namespace std;

class Based {
public:
    Based(long val, int base):val(val), base(base){
        if (base < 2) {
            throw "invalid base";
        }
    }
    int get_val() {return val;}
    int get_base() {return base;}
private:
    int val;
    int base;
};

const char e_digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";

std::ostream& operator<<(std::ostream& output, Based b) {
    const int BUF_LEN = 128;
    char buffer[BUF_LEN];
    int val = b.get_val(), base = b.get_base();
    bool negative = val < 0;

    if (negative) {
        val = -val;
    }

    buffer[BUF_LEN-1] = '\0';

    int i;
    for (i=BUF_LEN-2; val!=0; i--, val/=base) {
        buffer[i] = e_digits[val%base];
    }
    if (negative) {
        buffer[i--] = '-';
    }
    output << &buffer[++i];
    return output;
}

int main() {
    Based b(128, 16);
    cout << b;
}

