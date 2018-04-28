#include "TxtParser.h"

#include <experimental/filesystem>


TxtParser::TxtParser(const std::string &filePath) :
	filePath(filePath),
	headerFound(false)
{
}

TxtParser::~TxtParser()
{
}


bool TxtParser::fileExists()
{
	return std::experimental::filesystem::exists(filePath);
}

/*std::string TxtParser::deleteComments(std::string line)
{
	if (line.find('#') != std::string::npos)
	{
		return line;
	}
	else
	{
		return line.substr(0, line.find('#') - 1);
	}
}*/
