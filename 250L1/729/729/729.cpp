// 729.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

class BrokenChessboard
{
public:
	int minimumFixes(vector <string> board);
};


int BrokenChessboard::minimumFixes(vector <string> board)
{
	int cnt1 = 0;
	char brdstart = 'B';
	for (int i = 0; i < board.size(); ++i)
	{
		if (brdstart == 'B')
			brdstart = 'W';
		else
			brdstart = 'B';

		char rosq = brdstart;
		for (int j = 0; j < board[i].length(); ++j)
		{			
			if (board[i][j] != rosq) {
				cnt1++;
			}

			if (rosq == 'B')
				rosq = 'W';
			else
				rosq = 'B';
		}
	}

	int cnt2 = 0;
	char brd2start = 'W';
	for (int i = 0; i < board.size(); ++i)
	{
		if (brd2start == 'B')
			brd2start = 'W';
		else
			brd2start = 'B';

		char ro2sq = brd2start;
		for (int j = 0; j < board[i].length(); ++j)
		{
			if (board[i][j] != ro2sq) {
				cnt2++;
			}

			if (ro2sq == 'B')
				ro2sq = 'W';
			else
				ro2sq = 'B';
		}
	}

	return min(cnt1,cnt2);
}


int main()
{
	BrokenChessboard bcb;
	vector<string> vs = { "BWB",
		"BBW",
		"BWW" };
	int minreq = bcb.minimumFixes(vs);
    return 0;
}

