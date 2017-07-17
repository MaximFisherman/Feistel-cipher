#include "cipherfeistel.h"
#include <vector>

void CipherFeistel::CipherAlgoritm(string str){
    str = Check32Block(str);
    int i = 0;

    //Convert to Bite string str
    vector<int> strASCI(str.size());
    strASCI.assign(&str[0],&str[0]+str.size());

    /*while(strASCI.size != i){
        for(int j = 0; j<4; j++){
            left = strASCI
        }
        i+=16;r
    }*/

    std::cout<<"I'm work "<<str<<endl;
};

string CipherFeistel::Check32Block(string str){
    int i = 0;
    while((str.size()%16)!=0){
        str.push_back('_');
        i++;
        cout<<str<<endl;
    }
    return str;
};
