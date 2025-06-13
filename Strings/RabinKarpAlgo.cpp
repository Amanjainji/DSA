#include <bits/stdc++.h>
using namespace std;

#define PRIME 101

long long calculateHash(const string &str, int len) {
    long long hash = 0;
    long long power = 1;
    for (int i = 0; i < len; ++i) { //similar to hash=hash+ i * pow(PRIME,power++);
        hash += str[i] * power;     
        power *= PRIME;
    }
    return hash;
}

long long updateHash(long long prevHash, char oldChar, char newChar, long long primePower) {
    prevHash -= oldChar;    // long long newHash=(prevHash-oldChar)/PRIME;
    prevHash /= PRIME;
    prevHash += newChar * primePower;   // newHash += newChar * pow(PRIME,patternLength-1);
    return prevHash;
}

int search(const string &text, const string &pattern) {
    int n = text.length(), m = pattern.length();
    if (m > n) return -1;

    long long primePower = 1;
    for (int i = 1; i < m; ++i) primePower *= PRIME;  // PRIME^(m-1)

    long long patternHash = calculateHash(pattern, m);
    long long textHash = calculateHash(text, m);

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash && text.substr(i, m) == pattern)
            return i;

        if (i < n - m) {
            textHash = updateHash(textHash, text[i], text[i + m], primePower);
        }
    }

    return -1;
}

int main() {
    string text = "bikeandCars";
    string pattern = "Aman";
    cout << search(text, pattern) << endl;
    return 0;
}
