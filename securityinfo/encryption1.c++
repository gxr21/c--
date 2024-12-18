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
            encryptpassword += ch; // الاحتفاظ بالحروف الخاصة والفراغات بدون تغيير
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
            encrypted += password[i]; // الاحتفاظ بالحروف الخاصة والفراغات بدون تغيير
        }
    }
    return encrypted;
}

// اختيار نوع التشفير
void ChoiceEncrypt() {
    cout << "Enter number you choose:" << endl;
    cout << "1. Shift Encryption" << endl;
    cout << "2. Key Encryption" << endl;
    int X;
    cin >> X;
    cin.ignore(); // لتجنب مشاكل قراءة النصوص

    string password;
    string key;
    int shift;

    switch (X) {
        case 1: {
            cout << "Enter the password: ";
            getline(cin, password); // قراءة كلمة المرور مع دعم الفراغات
            cout << "Enter the value of shift: ";
            cin >> shift;
            string result = encryiptionPassword(password, shift);
            cout << "Encrypted Password (Shift): " << result << endl;
            break;
        }
        case 2: {
            cout << "Enter the password: ";
            getline(cin, password); // قراءة كلمة المرور مع دعم الفراغات
            cout << "Enter the key: ";
            getline(cin, key); // قراءة المفتاح مع دعم الفراغات
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
    ChoiceEncrypt();
    return 0;
}
