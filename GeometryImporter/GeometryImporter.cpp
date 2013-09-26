/*	Author: Frank Dye
	Date: 9/25/13
	Copyright: Frank Dye, 9/25/2013
	Description: A simple RegExp tester to help with setting up the correct RegExp constants
*/

#include <iostream>
#include <regex>
#include <tchar.h>

#include "OBJRegExp.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;

	std::string s ("Ka 0.200000 0.200000 0.200000");
	std::smatch m;
	std::string s_regex("(?:Ka)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");
	std::regex e ("(?:Ka)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)\\s*([-+]?[0-9]*\\.?[0-9]+)");   

	std::cout << "Target sequence: " << s << std::endl;
	std::cout << "Regular expression: " << s_regex  << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;

	if (std::regex_match (s,m,e))
	{
		std::cout << "string object matched\n";
		std::cout << "the matches were: ";
		for (unsigned i=0; i<m.size(); ++i) {
			std::cout << " [ " << m[i] << " ] ";
		}
	}
	else 
	{
		std::cout << "string object not matched\n";
	}

	//Just here to keep the console window open. Hookey but works.
	std::cin >> a;

	return 0;
}



