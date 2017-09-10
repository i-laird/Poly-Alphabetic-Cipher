//
//Ian Laird
//
// This program encrypts of decrypts a message using a poly-alphabetic cypher.
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
    //Data Abstraction
    char encryptStatus, yesNo;
    string encryptionKey, message;
    cout << "Encrypt or Decrypt?\nEnter E for encryption or D for decryption.\n";
    cin >> encryptStatus;

    //Reads in until the correct key is read in
    do{
        cout << "Please enter the " << encryptStatus << "ncryption key:\n";
        cout << "It should be only alphabetic characters.\n ";
        cin >> encryptionKey;

        if(encryptionKey.length() > 0) {
            cout << "Is " << encryptionKey << " the correct key  ( Y/N )\n";
            cin >> yesNo;
        }
        else
            cout << "ERROR invalid key.\n";
    }while((yesNo != 'y' && yesNo != 'Y') || encryptionKey.length() == 0);

    cout << "Please Enter the message to be decrypted without any newlines.\n";
    cin.ignore(1, '\n');
    getline(cin, message);

    //This makes sure that the entire key is lowercase
    bool correctInput = true;
    for(int i =0; i < encryptionKey.length(); i++){
        encryptionKey[i] = tolower(encryptionKey[i]);
        if(!isalpha(encryptionKey[i]))
            correctInput = false;
    }

    if(!correctInput){
        cerr << "ERROR: a non alphabetic character was detected in the key!";
        assert(correctInput);
    }

    //This is for encryption
    if(encryptStatus == 'e' || encryptStatus == 'E') {
        for (int i = 0; i < message.length(); i++) {
            message[i] = message[i] + (encryptionKey[(i % encryptionKey.length())] - '`');
        }
    }

        //This is for decryption
    else if(encryptStatus == 'd' || encryptStatus == 'D') {
        for (int i = 0; i < message.length(); i++) {
            message[i] = message[i] - (encryptionKey[(i % encryptionKey.length())] - '`');
        }
    }
    else{
        cerr << "It appears that that the encryption Key entered was not valid";
        assert(0);
    }

    cout << "Here is the " << encryptStatus << "ncrypted message:\n" << message << endl;
    return 0;
}