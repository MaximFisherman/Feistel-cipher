#include "cipherfeistel.h"
#include <vector>
//Незабыть изменить ключ шифрования при каждой итерации
/*
Create method Decription when decript massage. Input parametr exit string strENCODE
*/
void CipherFeistel::CipherAlgoritm(string str){
    str = Check32Block(str);

    int i = 0;
    vector<int> strASCI(str.size());
    vector<int> left(8);
    vector<int> right(8);
    vector<int> CIPHER_KEY_INT(CIPHER_KEY.size());
    //Convert to Bite string str
    strASCI.assign(&str[0], &str[0] + str.size());

    //Covert String Key to int Key
    CIPHER_KEY_INT.assign(&CIPHER_KEY[0], &CIPHER_KEY[0] + CIPHER_KEY.size());


    string strENCODE;
    while(strASCI.size() != i){
        for(int j = 0; j < 8; j++){
            left[j]= strASCI[j];
        }

        for(int j = 0; j < 8; j++){
            right[j] = strASCI[j+8];
        }

        //Encode
        for(int j = 1; j <= 4; j++){
            for(int j = 0; j < 8; j++){
                cout<<"Right = "<<right[j]<<endl;
                cout<<"Left = "<<left[j]<<endl;
                vector<int> temp_left(&left[0], &left[0] + left.size());
                temp_left[j] += CIPHER_KEY_INT[j];
                cout<<"temp_left = "<<temp_left[j]<<endl;
                right[j] ^= temp_left[j];
                cout<<"right ^ temp left = "<<right[j]<<endl;
                left[j] = right[j];
                cout<<"left = right = "<<left[j]<<endl;
                right[j] = temp_left[j];
                cout<<right[j]<<" ";
            }
            cout<<endl;
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
