#include "stack.h"
#include <string>
#include <iostream>

/* Tester for Lab 5  */

bool bracketCheck(const std::string& s);

int main(void) {

	std::string tests[6] = {

		"a(b)c[d]ef{g}",

		"a[(a[bcd(efg{h[i]j}k{[(l)m]}n{}o)p])[q]]rs",

		"a(b)c]d",

		"[[]",

		"aa(bb{cc)dd}ee",
		"ywxzopqr@*"

	};



	for (int i = 0;i<6;i++) {

		if (bracketCheck(tests[i])) {

			std::cout << "Test " << i + 1 << " passed" << std::endl;

		}

		else {

			std::cout << "Test " << i + 1 << " error" << std::endl;

		}

	}

	return 0;

}

bool bracketCheck(const std::string& s) {
         bool result=false;
	if (!s.empty()) {
		Stack<char> store;
		for (unsigned int i = 0;i < s.length();i++) {
			if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
				store.push(s[i]);  //{,[,( can go in
			}
			else if ((store.top() == '{' && s[i] == '}') ||
				(store.top() == '(' && s[i] == ')') ||
				(store.top() == '[' && s[i] == ']')) {
				store.pop();  //find pair, remove pair
			}
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
				return result;  //no pair, not left brace, for sure false
			}
		}
		
                if(store.isEmpty()){ //if empty no left brace left, all match pair
                   result= true;
                  } 
	}
        return result;
}