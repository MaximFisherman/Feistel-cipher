#include "cipherfeistel.h"
#include <vector>

void CipherFeistel::CipherAlgoritm(string str){
    str = Check32Block(str);

    int i = 0;
    vector<int> strASCI(str.size());
    vector<int> left(8);
    vector<int> right(8);

    //Convert to Bite string str
    strASCI.assign(&str[0],&str[0]+str.size());

    string strENCODE;
    while(strASCI.size() != i){
        for(int j = 0; j<8; j++){
            left[j]= strASCI[j];
        }

        for(int j = 0; j<8; j++){
            right[j] = strASCI[j+8];
        }


        //Convert Vector to string for output
        string rightString,leftString;
        leftString = ConvertToStringVector(leftString, left);
        rightString = ConvertToStringVector(rightString, right);
        strENCODE = leftString + rightString;
        cout<<"Convert string: "<<strENCODE<<endl;

        i+=16;
    }
};


string CipherFeistel::ConvertToStringVector(string str, vector<int> arrayASCI){
    char ch;
    for (int i = 0; i < arrayASCI.size(); i++) {
        ch = arrayASCI[i];
        str += ch;
    }
    return str;
};

string CipherFeistel::Check32Block(string str){
    int i = 0;
    while((str.size()%16)!=0){
        str.push_back('_');
        i++;
    }
    return str;
};
