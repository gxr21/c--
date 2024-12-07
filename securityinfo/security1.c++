#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

class encryptionPassword {
public:
    string password;
    int shift;
    int length;

    string encryption(string password, int shift) {
        string encryptpassword = "";
        for (char ch : password) {
            if (islower(ch)) {
                encryptpassword += char((ch - 'a' + shift) % 26 + 'a');
            } else if (isupper(ch)) {
                encryptpassword += char((ch - 'A' + shift) % 26 + 'A');
            } else {
                encryptpassword += ch;
            }
        }
        return encryptpassword;
    }
    string generatePassword(int length) {
        const string charset =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789"
            "!@#$%^&*()_+";

        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> dist(0, charset.size() - 1);

        string Password;
        for (int i = 0; i < length; i++) {
            Password += charset[dist(generator)];
        }
        return Password;
    }
};

int main() {
    int length;
    int shift;
    encryptionPassword ep;

    cout << "Enter the desired length of the Password: ";
    cin >> length;

    if (length < 1) {
        cout << "Password length must be at least 1!" << endl;
        return 1;
    }

    cout << "Enter the value of shift (if needed): ";
    cin >> shift;

    string Password = ep.generatePassword(length);
    cout << "Generated Password: " << Password << endl;
    cout << "Encrypted Password: " << ep.encryption(Password, shift) << endl;

    return 0;
}
