#include <iostream>

using namespace std;

int main()
{
	int input = 0;
	
	while (true)
	{
		cin >> input;
		
		if (input == 42)
			break;
		
		cout << input << "\n";
	}
	
	return 0;
}