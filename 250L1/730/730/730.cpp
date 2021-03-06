// 730.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	For any x ≤ y the interval [x,y] contains all real numbers between x and y, inclusive. The length of the interval [x,y] is y-x. Two intervals intersect if they have at least one number in common.

	You are given the ints x1, y1, x2, and y2. These are the endpoints of two intervals: [x1,y1] and [x2,y2]. We are looking for an interval [a,b] that intersects both given intervals. Return the smallest possible length of the interval [a,b].
	Definition
	    
		Class:
		IntervalIntersections
		Method:
		minLength
		Parameters:
		int, int, int, int
		Returns:
		int
		Method signature:
		int minLength(int x1, int y1, int x2, int y2)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			256
			Stack limit (MB):
			256
			Constraints
			-
			x1,y1,x2,y2 will be between 1 and 10^6, inclusive.
			-
			x1 will be less than or equal to y1.
			-
			x2 will be less than or equal to y2.
			Examples
			0)

			    
				3
				6
				1
				2
				Returns: 1
				The two given intervals are [3,6] and [1,2]. The unique shortest interval that intersects both of them is the interval [2,3]. Its length is 3-2 = 1.
				1)

				    
					1
					2
					3
					6
					Returns: 1
					The same two intervals as in Example 0, only in different order. The correct return value is the same.
					2)

					    
						1
						10
						2
						5
						Returns: 0
						In this test case the optimal length of the interval [a,b] is 0. Examples of such intervals include [2,2] and [4,4].
						3)

						    
							4
							5
							1
							4
							Returns: 0

							4)

							    
								1
								1
								1000000
								1000000
								Returns: 999999

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class IntervalIntersections
{
public:
	int minLength(int x1, int y1, int x2, int y2);
};


int IntervalIntersections::minLength(int x1, int y1, int x2, int y2)
{	
	int interval = 0;

	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	if (y1 < x2)
		interval = x2 - y1;

	if (x2 <= y1)
		interval = 0;

	return interval;
}


int main()
{
	IntervalIntersections iit;
	int out = iit.minLength(1, 1, 100000, 100000);
    return 0;
}

