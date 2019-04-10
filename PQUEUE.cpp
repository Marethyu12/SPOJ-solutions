#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	int n, m;
	int priority;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n >> m;
		
		deque<int> dq;
		deque<int> pos;
		
		priority_queue<int> pq;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> priority;
			
			dq.push_back(priority);
			pos.push_back(i);
			
			pq.push(priority);
		}
		
		int wait = 0;
		
		while (true)
		{
			int print = dq.front();
			dq.pop_front();
			
			int cur = pos.front();
			pos.pop_front();
			
			if (!pq.empty() && print == pq.top())//if found a job with highest priority
			{
				wait++;//print it
				
				if (cur == m)//if the current job's my job
					break;
				
				pq.pop();//remove job with highest priority
			}
			else
			{
				dq.push_back(print);
				pos.push_back(cur);
			}
		}
		
		cout << wait << "\n";
	}
	
	return 0;
}