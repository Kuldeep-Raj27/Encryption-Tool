//////// FILE ENCRYPTION & DECRYPTION //////////////

#include <iostream>
#include "encryption.h"
#include <string>

using namespace std;

int main(){

    string filename; 
    char mode; // enrypt or decrypt mode.

    cout<<"enter filename- ";
    getline(cin,filename);  // read till '/n'

    cout<<"Encrypt(e) or Decrypt(d) ? "<<endl;
    cin>>mode;
//////////////////////////////////////////////////////////////////
if(mode=='e' ||mode=='E'){
    if(encryptFile(filename,true)){
        // true in brackets for encryption and false for decryption. View in header file.
        cout<<"encryption done."<<endl;
    }
    else{
        cerr<<"encryption not done."<<endl; // when file not found or open.
    }
}

else if(mode =='d'||mode=='D'){
    if(encryptFile(filename,false)){
        cout<<"decryption done."<<endl;
    }
    else{
        cerr<<"decryption not done.!!"<<endl;
    }
    }
    
else{
        cerr<<"ERROR - INVALIDE INPUT."<<endl; // when input is differnt from char e/E or d/D.
    }


return 0;
}