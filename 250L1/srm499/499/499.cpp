// 499.cpp : Defines the entry point for the console application.
//

#include <vector>
using namespace std;


class SimpleGuess
{
public:
	int getMaximum(vector <int> hints);
};


int SimpleGuess::getMaximum(vector <int> hints)
{
	int maxprd = 0;
	for (int i = 0; i < hints.size(); ++i)
	{
		int xaddy = hints[i];
		for (int j = 0; j < hints.size(); ++j)
		{		

			if (i == j)
				continue;

			int xsuby = hints[j];

			int x = (xaddy + xsuby)/2;
			int y = xaddy - x;

			if ((x + y == xaddy) && (x - y == xsuby))
			{
				if (x*y > maxprd)
					maxprd = x * y;
			}
		}
	}

	return maxprd;
}


int main()
{
	SimpleGuess sg;
	vector<int> v = { 50, 58, 47, 57, 40 };
	int maxprd = sg.getMaximum(v);
    return 0;
}

