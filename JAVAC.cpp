#include <bits/stdc++.h>

using namespace std;

bool isJava(const string& s)
{
	int length = s.length();
	
	if (isupper(s[0]))
		return false;
	
	for (int i = 0; i < length; ++i)
		if (s[i] == '_')
			return false;
	
	return true;
}

bool isCpp(const string& s)
{
	int length = s.length();
	
	if (s[0] == '_'  || s[length - 1] == '_')
		return false;
	
	for (int i = 0; i < length; ++i)
		if (isupper(s[i]))
			return false;
	
	for (int i = 1; i < length; ++i)
		if (s[i - 1] == '_' && s[i] == '_')
			return false;
	
	return true;
}

string toJava(string s)
{
	string j_str = "";
	
	int length = s.length();
	
	for (int i = 0; i < length; ++i)
		if (i > 0 && s[i - 1] == '_')
			j_str += toupper(s[i]);
		else if (s[i] != '_')
			j_str += s[i];
	
	return j_str;
}

string toCpp(string s)
{
	string cpp_str = "";
	
	int length = s.length();
	
	for (int i = 0; i < length; ++i)
		if (isupper(s[i]))
		{
			cpp_str += "_";
			cpp_str += tolower(s[i]);
		}
		else
			cpp_str += s[i];
	
	return cpp_str;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	
	while (getline(cin, s))
	{
		if (isJava(s))
			cout << toCpp(s) << "\n";
		else if (isCpp(s))
			cout << toJava(s) << "\n";
		else
			cout << "Error!\n";
	}
	
	return 0;
}