#include "replace.hpp"

Replace::Replace(const char *inputFile, const char *outputFile, std::string string1, std::string string2) : inFile(inputFile), outFile(outputFile)
{
	this->s1 = string1;
	this->s2 = string2;
}

Replace::~Replace(){}

void	Replace::replaceFile(std::ifstream& inputFile, std::string line, std::string s1, std::string s2, std::ofstream& outputFile)
{
	bool firstline = true;
	while (std::getline(inputFile, line))
	{
		if(!firstline)
			outputFile << std::endl;
		else
			firstline = false;
        std::string newLine;
        size_t pos = 0;
        size_t startPos = 0;
        while ((pos = line.find(s1, startPos)) != std::string::npos)
		{
            newLine += line.substr(startPos, pos - startPos);
            newLine += s2;
            startPos = pos + s1.length();
        }
        newLine += line.substr(startPos);
		outputFile << newLine;
	}
    inputFile.close();
    outputFile.close();
}

void	Replace::setupFile()
{
    std::ifstream inputFile(inFile);
    if (!inputFile)
	{
        std::cerr << "Failed to open the input file." << std::endl;
        exit(1);
    }
	if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
        std::cerr << "The input file is empty." << std::endl;
        inputFile.close();
        exit(1);
    }
    std::ofstream outputFile(outFile);
    if (!outputFile)
	{
        std::cerr << "Failed to create the output file." << std::endl;
		inputFile.close();
        exit(1);
    }
    std::string line;
    return(replaceFile(inputFile,line, s1,s2,outputFile));
}
