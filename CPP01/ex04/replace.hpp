#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


class Replace {
	public:
		Replace(const char* inputFile, const char* outputFile,
		std::string string1, std::string string2);
		~Replace();
		void	setupFile();
		void	replaceFile(std::ifstream& inputFile, std::string line, 
			std::string s1, std::string s2, std::ofstream& outputFile);
		
	private:
		const char* inFile;
		const char* outFile;
		std::string s1;
		std::string s2;
};


#endif