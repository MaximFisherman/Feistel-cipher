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
    int round = 4;
    string CIPHER_KEY ={"alebastr"};
public:
    CipherFeistel(){};
    string ModifiCipherKey( string );
    int F(int, int);
    string Encode(string);
    string Decode(string);

    string Check32Block(string);
    string ConvertToStringVector(string, vector<int>);
    ~CipherFeistel(){};
};

#endif // CIPHERFEISTEL_H
