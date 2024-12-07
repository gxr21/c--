#include<iostream>
#include<string>
using namespace std;
string encryiptionPassword(string password , int shift){
    
    cout << "Enter the password" << endl;
    cin >> password;
    cout << "Enter the value of shift" << endl;
    cin >> shift;
    string encryiption = encryiptionPassword(password , shift);
    string encryptpassword = "";
    for(char ch:password){
        if(islower(ch)){
            encryptpassword += char(int(ch + shift-'a')%26+'a');
        }
        else if(isupper(ch)){
            encryptpassword += char(int(ch - shift + 'A')%26+'A');
        }
        else{
            encryptpassword += ch;
        }
    }
    return encryptpassword;
}
string veginierEncryptionpassword(string password , string key){
     int PasswordLength = password.size();
     int KeyPassword = key.size();
     string extendKey = key;
     for(int i = 0 ; i < PasswordLength-KeyPassword;i++){
        extendKey += key[i%KeyPassword];
     }
 return extendKey;
}
string encryiptionPasswordKey(string password , string key){
    cout << "Enter the password";
    getline(cin,password);
    string encryptPasswod = encryiptionPasswordKey(password , key);
    string encrypted = "";
    key = veginierEncryptionpassword(password, key);
    for(int i = 0 ; i < password.size();i++){
        if(islower(password[i])){
            encrypted += char(((password[i]+key[i]-2*'a')%26)+'a');
        }
        else if(isupper(password[i])){
            encrypted += char(((password[i]+key[i]-2*'A')%26)+'A');
        }
        else{
            encrypted += password[i];
        }
    }
    return encrypted;
}
void ChoiceEncrypt(string password , int shift , string key){
    cout << "Enter number you Choice" << endl;
    cout << "1. Shift Encryption" << endl;
    cout << "2. key Encryption " <<  endl;
    int X;
    cin >> X;
    switch (X)
    {
    case 1:
       encryiptionPassword(password ,  shift);
        break;
    case 2:
     encryiptionPasswordKey( password ,  key);
    break;

    default:
    cout << "Erorr Choice" << endl;
        break;
    }
}
int main(){
 string password ;
 string key;
 int shift;
 ChoiceEncrypt(password , shift,key);



    return 0;
}