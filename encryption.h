#include <fstream>
#include <cctype>

using namespace std;
/*
Common ceaser cipher technique for file encryption- Shifts each letter in the plaintext by a fixed number of positions in the alphabet.
Example: A shift of 3 turns A into D, B into E, Z into C, etc...
 */
//////////////////////
void logicForCiper(string & content,bool encrypt){
    int shift = encrypt? 2 : -2 ; // key to manipulate characters. 
    for(char& ch:content){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';  //ASCI value of 'A' is 65 and 97 for 'a'.
            
            ch = static_cast<char>((ch-base+shift+26)%26 + base);

        }
    }
}
////////////////////////
bool encryptFile(const string &filename,bool encrypt){
    ifstream inFile(filename);
    if(!inFile){
        return false;
    }

    string content((istreambuf_iterator<char>(inFile)),{});
    inFile.close();

    logicForCiper(content,encrypt);
    ofstream outFile(encrypt ? "en_" + filename : "de_" + filename);
    if(!outFile){
        return false;
    }
    outFile << content;
    outFile.close();    
    return true;
}