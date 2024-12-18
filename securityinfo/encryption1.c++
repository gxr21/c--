#include <iostream>
#include <string>
using namespace std;

// تشفير باستخدام Shift
string encryiptionPassword(string password, int shift) {
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

// توسيع المفتاح ليطابق طول كلمة المرور
string expandKey(string pass, string key) {
    int passLength = pass.size();
    int keyLength = key.size();
    string expanded = key;
    for (int i = 0; expanded.size() < passLength; i++) {
        expanded += key[i % keyLength];
    }
    return expanded.substr(0, passLength);
}

// تشفير باستخدام المفتاح
string encryiptionPasswordKey(string password, string key) {
    string encrypted = "";
    key = expandKey(password, key);
    for (int i = 0; i < password.size(); i++) {
        if (islower(password[i])) {
            encrypted += char((password[i] + key[i] - 2 * 'a') % 26 + 'a');
        } else if (isupper(password[i])) {
            encrypted += char((password[i] + key[i] - 2 * 'A') % 26 + 'A');
        } else {
            encrypted += password[i];
        }
    }
    return encrypted;
}

// اختيار نوع التشفير
void ChoiceEncrypt(string password, int shift, string key) {
    cout << "Enter number you choose:" << endl;
    cout << "1. Shift Encryption" << endl;
    cout << "2. Key Encryption" << endl;
    int X;
    cin >> X;
    cin.ignore(); // لتجنب مشاكل قراءة النصوص
    switch (X) {
        case 1: {
            cout << "Enter the password: ";
            cin >> password;
            cout << "Enter the value of shift: ";
            cin >> shift;
            string result = encryiptionPassword(password, shift);
            cout << "Encrypted Password (Shift): " << result << endl;
            break;
        }
        case 2: {
            cout << "Enter the password: ";
            cin >> password;
            cout << "Enter the key: ";
            cin >> key;
            string result = encryiptionPasswordKey(password, key);
            cout << "Encrypted Password (Key): " << result << endl;
            break;
        }
        default:
            cout << "Error: Invalid choice" << endl;
            break;
    }
}

// الدالة الرئيسية
int main() {
    string password;
    string key;
    int shift;
    ChoiceEncrypt(password, shift, key);
    return 0;
}
