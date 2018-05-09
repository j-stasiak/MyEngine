#pragma once

#include "../Log/Log.h"
#include <cctype>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

/*!
	@class TxtParser

	Class used to parse .txt files with settings or some other files which are going to be included in project.
	Format of the file should be following: 
	[value] - For headers.
	key=value - for regular values
	# comment - for comments
	Example:
	# Window settings
	[WINDOW]
	height=1080
	width=1920
*/

// TODO: Everything here.
class TxtParser
{
public:
	TxtParser(const std::string &filePath);
	~TxtParser();

	template<typename T>
	T getProperty(const std::string &header, const std::string &key)
	{
		if (!checkIfFileExists())
		{
			return T();
		}

		std::ifstream file{ filePath };
		std::string buffer = "";
		
		while (std::getline(file,buffer))
		{
			buffer = deleteSpaces(buffer);
			buffer = deleteComments(buffer);

			if (buffer[0] == '[' && "[" + toUpper(header) + "]" == buffer)
			{
				while (std::getline(file, buffer))
				{
					if (std::isspace<char>(buffer[0], std::locale::classic()))
					{
						buffer = deleteSpaces(buffer);
						buffer = deleteComments(buffer);

						if (buffer.substr(0, buffer.find('=')) == key)
						{
							return convertStringToType<T>(buffer.substr(buffer.find('=') + 1, buffer.length() - buffer.find('=')));
						}
					}
				}
				break;
			}
		}

		LOG_ERROR("No value found for \"" + key + "\"! Returning empty string...");
		return T();
	}

private:
	// Helper methods
	bool checkIfFileExists();
	std::string toUpper(std::string str);
	std::string deleteComments(std::string line);
	std::string deleteSpaces(std::string line);

	template<typename T>
	T convertStringToType(const std::string &str)
	{
		T ret;
		std::istringstream iss(str);
		iss >> std::dec >> ret;
		return ret;
	}

	// Members
	std::string filePath;
	bool headerFound;
};