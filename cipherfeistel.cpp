#include "cipherfeistel.h"
#include <vector>
//Незабыть изменить ключ шифрования при каждой итерации
/*
Create method Decription when decript massage. Input parametr exit string strENCODE
*/

int CipherFeistel::F(int sublock, int key){
    return sublock + key;
}

string CipherFeistel::ModifiCipherKey(string CIPHER_KEY){
    while(CIPHER_KEY.size()-2 != i)
   {
       char temp =CIPHER_KEY[i];
       CIPHER_KEY[i] = CIPHER_KEY[CIPHER_KEY.size()-i-1];
       CIPHER_KEY[CIPHER_KEY.size()-i-1] = temp;
       i++;
   }
    return CIPHER_KEY;
}

string CipherFeistel::Encode(string str){
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
        for( int i = 1; i <= round; i++ ){
            ModifiCipherKey(CIPHER_KEY_INT);// ДОРАБОТАТЬ ФУНКЦИЮ ИЗМЕНЕНИЯ КЛЮЧА
            for (int j = 0; j < 8; j++)
            {
                int temp = right[j] ^ F( left[j], CIPHER_KEY_INT[j] );
                right[j] = left[j];
                left[j] = temp;
                cout<<right[j]<<" "<<left[j]<<endl;
            }
        }
        cout<<"End encode"<<endl;

        //Convert Vector to string for output
        string rightString,leftString;
        leftString = ConvertToStringVector(leftString, left);
        rightString = ConvertToStringVector(rightString, right);
        strENCODE = leftString + rightString;
        cout<<"Convert string: "<<strENCODE<<endl;
        i+=16;
    }
        return strENCODE;
};


string CipherFeistel::Decode(string strEncode){
    strEncode = Check32Block(strEncode);
    int i = 0;

    vector<int> strASCI(strEncode.size());
    vector<int> left(8);
    vector<int> right(8);
    vector<int> CIPHER_KEY_INT(CIPHER_KEY.size());

    //Convert to Bite string str
    strASCI.assign(&strEncode[0], &strEncode[0] + strEncode.size());

    //Covert String Key to int Key
    CIPHER_KEY_INT.assign(&CIPHER_KEY[0], &CIPHER_KEY[0] + CIPHER_KEY.size());


    string strDECODE;
    while(strASCI.size() != i){
        for(int j = 0; j < 8; j++){
            left[j]= strASCI[j];
        }

        for(int j = 0; j < 8; j++){
            right[j] = strASCI[j+8];
        }

        //Decode
        for ( i = round; i >= 1; i-- )
            for (int j = 0; j < 8; j++)
            {
                int temp = left[j] ^ F( right[j], CIPHER_KEY_INT[j] );
                left[j] = right[j];
                right[j] = temp;
                cout<<right[j]<<" "<<left[j]<<endl;
            }
        cout<<"End decode"<<endl;

        //Convert Vector to string for output
        string rightString,leftString;
        leftString = ConvertToStringVector(leftString, left);
        rightString = ConvertToStringVector(rightString, right);
        strDECODE = leftString + rightString;
        cout<<"Convert string: "<<strDECODE<<endl;

        i+=16;
    }
    return strDECODE;
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
