#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException : public std::exception {
private:
    int n;
public:
    // Constructor that takes an int
    BadLengthException(int n) : n(n) {}

    // Override the what() method to return a string
    const char* what() const noexcept override {
        static std::string msg; // Static to ensure it outlives the method call
        std::stringstream ss;
        ss << n; // Customize your error message here
        msg = ss.str();
        return msg.c_str();
    }
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}