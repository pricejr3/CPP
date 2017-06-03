

#include <map>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>



class zpm
{
	private:		

		std::string LHS;
		std::string MIDDLE;
		std::string RHS;

		std::map<std::string, std::string> mapping;
		
	
		void raiseError();
		

	
	public:

		const int max_line_len = 512;
		int lineCounter = 0;
		std::vector<std::string> toks = {};
		int numTokens;
		
		
		int lineNum;

		
	
		
		zpm();
		
		~zpm();
		
	
		void readFile(char *fileName);
		void createNewTokens(std::string currentLine);
		void usetoks(std::string currentLine);
		void loops(std::string currentLine);
		void print();
		void assignment();
		char const* parsingVars(std::string input);
};