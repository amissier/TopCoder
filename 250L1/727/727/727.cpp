// 727.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>

using namespace std;


class MakeTwoConsecutive
{
	bool isbeauty(string s);
public:
	string solve(string S);
};

bool MakeTwoConsecutive::isbeauty(string s)
{
	bool isbeauty = false;

	int i = 0;	

		int val = s.length() - 1;	
		for (int i = 0; i < val; ++i)
		{
			if (s[i] == s[i + 1])
				return true;
		}
	

	return isbeauty;
}

string MakeTwoConsecutive::solve(string S)
{
	string reds = "";
	int cnt = 0;
	while (cnt < S.length())
	{
		reds = "";
		for (size_t i = 0; i < S.length(); ++i)
		{
			if (cnt != i) {
				reds += S[i];
			}	
		}

		cnt++;

		if (isbeauty(reds) == true)
			return "Possible";
	}

	return "Impossible";
}

int main()
{
	MakeTwoConsecutive ms;

	string ans = ms.solve("A");
    return 0;
}

