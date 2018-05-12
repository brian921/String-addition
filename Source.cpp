#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int convertToInt(string s)
{
	
	stringstream convert(s);

	int i = 0;

	convert >> i;

	return i;

}

int addStringChar(string x, string y, int pos)
{
	int t1 = 0;
	int t2 = 0;
	//int c = 0;



	t1 = convertToInt(x.substr(pos, 1));
	t2 = convertToInt(y.substr(pos, 1));
	
	//cout << "T1:" << t1 << endl;
	//cout << "T2:" << t2 << endl; 

	//cout << t1 + t2 << endl;
	return t1 + t2;

}

string addStrings(string x, string y)
{
		//254
		// 69

	bool carryOne = false;
	string z;
	//int c = 0;
	int t = 0;

	if (x.length() >= y.length())
	{
		while (x.length() > y.length())				//pad with zeros
			y.insert(0, "0");

		//y.insert(0, "0");
		//x.insert(0, "0");

		cout << x << endl;
		cout << y << endl;

		for (int i = x.length()-1; i >= 0; i--)
		{
			t = addStringChar(x, y, i);

			if (t >= 10)
			{
				if (carryOne)
				{

					t++;
					carryOne = false;

					if (t >= 10)
						carryOne = true;

					t = t - 10;

					z.insert(0, to_string(t));
				}
				else
				{

					carryOne = true;

					t = t - 10;

					z.insert(0, to_string(t));
				}

			}
			else
			{

				if (carryOne)
				{
					t++;
					carryOne = false;
				}

				if (t >= 10)
				{
					carryOne = true;
					t = t - 10;
				}

				z.insert(0, to_string(t));
			}
		}
	}
	else
	{
		while (y.length() > x.length())				//pad with zeros
			x.insert(0, "0");


		for (int i = y.length() - 1; i >= 0; i--)
		{

			t = addStringChar(x, y, i);

			if (t >= 10)
			{
				if (carryOne)
				{
					t++;
					carryOne = false;

					if (t >= 10)
						carryOne = true;

					t = t - 10;

					z.insert(0, to_string(t));
				}
				else
				{
					carryOne = true;

					t = t - 10;

					z.insert(0, to_string(t));
				}

			}
			else
			{
				if (carryOne)
				{
					t++;
					carryOne = false;
				}

				if (t >= 10)
				{
					carryOne = true;
					t = t - 10;
				}

				z.insert(0, to_string(t));
			}
		}
	}

	if (carryOne)
		z.insert(0, "1");

	return z;
}

int main()
{
	vector <int> sum;

	string x = "1";
	string y = "999";

	//   55512
	//+    999
	//   56511 
	//cout << x << endl;

	cout << addStrings(x, y) << endl;
	
	string z;
	cin >> z;

	return 0;
}