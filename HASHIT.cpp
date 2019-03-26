#include <bits/stdc++.h>

using namespace std;

const int capacity = 101;

int Hash(const string& key)
{
	int h = 0;
	
	int length = key.length();
	
	for (int i = 0; i < length; ++i)
		h += ((int) key[i]) * (i + 1);
	
	return (19 * h) % capacity;
}

int FindFirst(int h, bool reserved[])
{
	int pos = -1;
	
	for (int j = 0; j <= 19; ++j)
	{
		int index = (h + j * (j + 23)) % capacity;
		
		if (!reserved[index])
		{
			pos = index;
			break;
		}
	}
	
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int ops;
	
	string s;
	
	cin >> T;
	
	while (T--)
	{
		cin >> ops;
		cin.ignore(1, '\n');
		
		map<string, int> m;
		string table[capacity];
		
		bool reserved[capacity] = {false};
		int size = 0;
		
		for (int i = 0; i < ops; ++i)
		{
			getline(cin, s);
			
			int pos = s.find(":");
			
			string op = s.substr(0, pos);
			string key = s.substr(pos + 1);
			
			if (op == "ADD" && m.find(key) == m.end())
			{
				int bucket = FindFirst(Hash(key), reserved);
				
				if (bucket != -1)
				{
					table[bucket] = key;
					reserved[bucket] = true;
					m[key] = bucket;
					++size;
				}
			}
			
			if (op == "DEL" && m.find(key) != m.end())
			{
				table[m[key]] = "";
				reserved[m[key]] = false;
				m.erase(key);
				--size;
			}
		}
		
		cout << size << "\n";
		
		for (int i = 0; i < capacity; ++i)
			if (reserved[i])
				cout << i << ":" << table[i] << "\n";
	}
	
	return 0;
}