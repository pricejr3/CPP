#include "zpm.h"
#include <fstream>
#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string.h>

using namespace std;


zpm::zpm()
{
	
}


zpm::~zpm()
{
	
}


void zpm::raiseError()
{
	std::cout << "RUNTIME ERROR on: line " << lineNum << std::endl;

	
	exit(0);
}


void zpm::readFile(char* fileName){

	
	
  ifstream input;
  input.open(fileName); // open a file

  
  // read each line of the file
  while (!input.eof())
  {
    

    // Increment lineCounter by 1.
    lineCounter++;

    char currentLine[max_line_len];
    input.getline(currentLine, max_line_len);


    // line holds the current line.

    createNewTokens(currentLine);

	

  }


} // end readFile


void zpm::createNewTokens(std::string currentLine){

	// Make the token holder empty again.
	toks = {};

    	std::istringstream buf(currentLine);
    	std::istream_iterator<std::string> beg(buf), end;

    	std::vector<std::string> tokens(beg, end); 

	// Push all tokens from the currentLine into the vector.
   	for(auto& s: tokens){
		
		toks.push_back(s);
	}

	
	usetoks(currentLine);

	
       		 
	


} // end createNewTokens


void zpm::usetoks(std::string currentLine){


	

	if( (toks[0].compare("PRINT") == 0) || (toks[0].compare("PRINT") == 0) ) {
		
		print();
		
	}

	if (std::find(toks.begin(), toks.end(), "FOR") != toks.end() ) {	
		loops(currentLine);
	}

	if (std::find(toks.begin(), toks.end(), "+=") != toks.end()
		|| std::find(toks.begin(), toks.end(), "*=") != toks.end()
		|| std::find(toks.begin(), toks.end(), "-=") != toks.end()
		|| std::find(toks.begin(), toks.end(), "=") != toks.end() ) {	

		assignment();
	}







} // end usetoks


void zpm::print(){


	
		
		std::string prefix = ""; 
		
		if(strcmp(parsingVars(toks[1]),("VARIABLE")) == 0) {
			
			if(!mapping.count(toks[1])) {
				raiseError();
			} 
				

				
			
			
		}
		
	
		if(strcmp(parsingVars(toks[1]),("CONTAINSQUOTE")) == 0) {

			std::replace( toks[1].begin(), toks[1].end(), '\"', '\0'); 

			
		}		
		
		cout << toks[1] + "=" + mapping.at(toks[1]) << endl;
	

		
} // end print


void zpm::assignment(){

	LHS = toks[0];
	MIDDLE = toks[1];
	RHS = toks[2];
	


	if(strcmp(parsingVars(RHS),("VARIABLE")) == 0) {

		// mapping.containskey(RHS)
		if(mapping.count(RHS)){
			
			RHS = mapping.at(RHS);
		}
		else{
			raiseError();

		}
	}

	std::string value = parsingVars(RHS);

	if(mapping.count(LHS)) {
			


		 if (value.compare(parsingVars(mapping.at(LHS))) != 0 && MIDDLE.compare("=") != 0){
			
			raiseError();
		}

	}	


	  if(MIDDLE.compare("-=") == 0){
			if(value.compare("CONTAINSQUOTE") == 0) {
				raiseError();
			} else {

				int i = std::stoi(mapping.at(LHS));
				int k = std::stoi(RHS);

				stringstream val2;
				val2 << i - k;
				string val  = val2.str();

				RHS = val;			

			}	
		
		}

	if(MIDDLE.compare("+=") == 0){
			if(value.compare("CONTAINSQUOTE") == 0) {
					
					std::string str1 = mapping.at(LHS).replace( str1.begin(), str1.end(), '\"', '\0');;

				 
					

					std::string str2 = RHS.replace( str2.begin(), str2.end(), '\"', '\0'); 
					

				
					RHS = "\"" + str1 + str2 + "\"";
					
				} else {
						
					int i = std::stoi(mapping.at(LHS));
					int k = std::stoi(RHS);

					stringstream value;
					value << i + k;
					string val  = value.str();
					RHS = val;

	
				}					
		}


		if(MIDDLE.compare("*=") == 0){
		
				if(value.compare("CONTAINSQUOTE") == 0) {
					raiseError();
				} else {
					int i = std::stoi(mapping.at(LHS));
					int k = std::stoi(RHS);

					stringstream value;
					value << i * k;
					string val  = value.str();

					RHS = val;
				}
		
		}


	


	// Insert the string pair into the map.
	
	mapping.insert(std::pair<std::string, string>(LHS, RHS));

	mapping[LHS] = RHS;



} // end assignment


void zpm::loops(std::string currentLine){





}



				



char const* zpm::parsingVars(std::string input){

	if(input.find("\"") != std::string::npos){

		return "CONTAINSQUOTE";
	}

  stringstream ss(input);
  int num;
 
  // If the input is not a number:
  if((ss >> num).fail())
  { 
      return "VARIABLE";
  }

  return "INTEGER";

  
	

} // end parsingVars

int main(int argc, char* argv[])
{

	

	char* sourceFileName = argv[1];
	
	zpm* zpmTest = new zpm();
	zpmTest->readFile(sourceFileName);


	
	return 0;
}