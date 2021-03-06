// 726.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	Hero has a string of lowercase English letters. Each letter that appears in the string appears exactly twice. Hero now wants to remove one half of his string. More precisely, he wants to remove one of the two copies of each letter in his string. The order of the letters he does not remove will remain unchanged. If there are multiple ways to remove the letters, Hero prefers the ones where the resulting string begins with a smaller letter (i.e., a letter that is earlier in the alphabet). You are given the string s containing Hero's string. Find the smallest letter that can appear at the beginning of the string after Hero removes half of the letters. Return a string with a single character: that letter.
	Definition
	    
		Class:
		StringHalving
		Method:
		lexsmallest
		Parameters:
		string
		Returns:
		string
		Method signature:
		string lexsmallest(string s)
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
			s will contain between 2 and 50 characters, inclusive.
			-
			Each character in s will be between 'a' and 'z', inclusive.
			-
			Each letter from 'a' to 'z' will have either zero or two occurrences in s.
			Examples
			0)

			    
				"baba"
				Returns: "a"
				Hero can remove the first 'b' and the second 'a' to obtain the string "ab".
				1)

				    
					"bbaa"
					Returns: "b"
					Regardless of which 'a' and which 'b' Hero removes, the resulting string will always be "ba".
					2)

					    
						"zyiggiyssz"
						Returns: "g"

						3)

						    
							"topcodertpcder"
							Returns: "c"

							4)

							    
								"rvofqorvfq"
								Returns: "f"

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class StringHalving
{
	size_t findposofsmallest(string s);
public:
	string lexsmallest(string s);
};


string StringHalving::lexsmallest(string s)
{
	set<char> letters;

	for (int i = 0; i < s.length(); ++i)
	{
		letters.insert(s[i]);
	}

	char sm = *letters.begin();
	bool smallest = false;
	
	for (set<char>::iterator it = letters.begin(); it != letters.end(); it++)
	{
		sm = *it;
		size_t pos = s.find(sm);

		for (set<char>::iterator it2 = letters.begin(); it2 != letters.end(); it2++)
		{
			if (it2 == it)
				continue;
			else
			{
				size_t posfirst = s.find(*it2);
				size_t posnext = s.find(*it2, posfirst + 1);
				if (posnext > pos)
					smallest = true;
				else
				{
					smallest = false;
					break;
				}
			}
		}

		if (smallest)
			break;
	}

	return string(1, sm);	
}


int main()
{
	StringHalving shv;

	string sm = shv.lexsmallest("yckhtbgxpexorqidshtfuvakabynqdpluoslmvgjcmwijfnwre");
    return 0;
}

