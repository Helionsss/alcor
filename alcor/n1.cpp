
#include<iostream>
#include<string>

using namespace std;

char* reverse(char * str, int delta) {
	int i, len = 0, n;
	char temp;
	len = strlen(str);
	n = len - 1;
	for (i = 0; i <= (len / 2); i++)
	{
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
		n--;
		cout << str;
	}
	return str;
}



int main()
{
	string str;
	int delta;
	cin >> delta;
	cin >> str;

	reverse(str.begin(), str.end());
	cout << str;
	return 0;
}