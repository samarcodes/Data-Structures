#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isBalanced(string s) {
	int len = s.length();
	stack <char> st;
	cout << len << endl;
	//base case
	if (s[0] == ')' || s[0] == '}' || s[0] == ']') {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			if (st.empty()) {
				return false;
			}
			else if (s[i] == ')' && st.top() == '(') {
				st.pop();
			}
			else if (s[i] == '}' && st.top() == '{') {
				st.pop();
			}
			else if (s[i] == ']' && st.top() == '[') {
				st.pop();
			}
			else {
				return false;
			}
		}
	}
	if (st.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	string s;
	cin >> s;

	isBalanced(s) ? cout << "Balanced" << endl : cout << "Not Balanced" << endl;
	return 0;
}