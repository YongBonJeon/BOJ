#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int num = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			num++;
	}

	if (str[0] == ' ') 
		num--;
	if (str[str.length() - 1] == ' ') 
		num--;
	
	printf("%d", num);
}