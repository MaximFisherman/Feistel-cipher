#ifndef CIPHERFEISTEL_H
#define CIPHERFEISTEL_H
#include <iostream>
#include <string>
using namespace std;

class CipherFeistel{
private:
    string cipherWord;
    string left;
    string right;
    static const string CIPHER_KEY;
public:
    CipherFeistel(){};
    void CipherAlgoritm(string);
    ~CipherFeistel(){};
};

#endif // CIPHERFEISTEL_H
