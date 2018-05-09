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


bool TxtParser::checkIfFileExists()
{
	if (!std::experimental::filesystem::exists(filePath))
	{
		LOG_ERROR("No file found under given directory: " + filePath);
		return false;
	}
	return true;
}

std::string TxtParser::toUpper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](char c) {
		return std::toupper<unsigned char>(c, std::locale::classic());
	});
	return str;
}

std::string TxtParser::deleteComments(std::string line)
{
	std::size_t commentPosition = line.find('#');
	if (commentPosition != std::string::npos)
	{
		line = line.substr(0, commentPosition);
	}
	return line;
}

std::string TxtParser::deleteSpaces(std::string line)
{
	line.erase(std::remove_if(line.begin(), line.end(), [](char c)
	{
		return std::isspace<char>(c, std::locale::classic());
	}));

	return line;
}
