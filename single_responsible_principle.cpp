#include <iostream>
#include <string>
using namespace std;

// -----------------------
// 1. User Model
// -----------------------
class User {
public:
    string name;
    string email;

    User(string name, string email) : name(name), email(email) {}
};

// -----------------------
// 2. Validator (SRP: validation only)
// -----------------------
class UserValidator {
public:
    bool isValidEmail(const string& email) {
        return email.find('@') != string::npos;
    }

    bool isValidUser(const User& user) {
        return !user.name.empty() && isValidEmail(user.email);
    }
};

// -----------------------
// 3. Repository  (SRP: DB save only)
// -----------------------
class UserRepository {
public:
    void save(const User& user) {
        cout << "User saved to database: " << user.name << endl;
    }
};

// -----------------------
// 4. Email Service (SRP: sending email only)
// -----------------------
class EmailService {
public:
    void sendWelcomeEmail(const User& user) {
        cout << "Welcome email sent to: " << user.email << endl;
    }
};

// -----------------------
// 5. User Service (SRP: coordination only)
// -----------------------
class UserService {
    UserValidator validator;
    UserRepository repository;
    EmailService emailService;

public:
    void registerUser(const User& user) {
        if (!validator.isValidUser(user)) {
            cout << "Invalid user details!" << endl;
            return;
        }

        repository.save(user);
        emailService.sendWelcomeEmail(user);
    }
};

// -----------------------
// Main
// -----------------------
int main() {
    User user("Mahadev", "mahadev@example.com");
    UserService service;
    service.registerUser(user);

    return 0;
}
