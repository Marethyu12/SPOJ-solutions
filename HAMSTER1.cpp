#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const double g = -10.0;

double score(double angle, double V0, double K1, double K2)
{
	double vx = V0 * cos(angle);
	double vy = V0 * sin(angle);
	
	double Y = (0.0 - pow(vy, 2.0)) / (2.0 * g); /* derived from formula: vf^2 = vi^2 + 2ad */
	double T = (-2.0 * vy) / g; /* derived from formula: d = vt + (1/2)a(t^2) */
	double X = vx * T; /* derived from formula: v = d/t */
	
	return K1 * X + K2 * Y;
}

pair<double, double> ternary_search(double low, double high, double V0, double K1, double K2)
{
	while (high - low > eps)
	{
		double m1 = low + (high - low) / 3.0;
		double m2 = high - (high - low) / 3.0;
		
		double f1 = score(m1, V0, K1, K2);
		double f2 = score(m2, V0, K1, K2);
		
		if (f1 < f2)
			low = m1;
		else
			high = m2;
	}
	
	return make_pair(low, score(low, V0, K1, K2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed;
	cout << setprecision(3);
	
	int T;
	int V0, K1, K2;
	
	double low = 0.0;
	double high = M_PI / 2.0;
	
	cin >> T;
	
	while (T--)
	{
		cin >> V0 >> K1 >> K2;
		
		pair<double, double> result = ternary_search(low, high, V0, K1, K2);
		
		cout << result.first << " " << result.second << "\n";
	}
	
	return 0;
}