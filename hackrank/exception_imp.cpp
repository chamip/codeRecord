/*
 * @Author: chamip
 * @Date: 2022-04-13 16:25:40
 * @LastEditTime: 2022-04-13 16:27:31
 * @LastEditors: chamip
 * @FilePath: /vscCpp/hackrank/exception_imp.cpp
 */
/*
* check if input string is valid, or output exception.
* impletement my own exception(line 19). 
*/
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException {
    private:
        int n;
    public:
        BadLengthException(int errornum): n(errornum){};
        int what() {
            return n;
        }
};

bool checkUsername(string username) {
	bool isValid = true;p
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