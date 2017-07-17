#ifndef CIPHERFEISTEL_H
#define CIPHERFEISTEL_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CipherFeistel{
private:
    string cipherWord;
    string right;
    static const string CIPHER_KEY;
public:
    CipherFeistel(){};
    void CipherAlgoritm(string);
    string Check32Block(string);
    string ConvertToStringVector(string, vector<int>);
    ~CipherFeistel(){};
};

#endif // CIPHERFEISTEL_H
