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
		if (!fileExists())
		{
			LOG_ERROR("File not found in " + filePath + "!");
			return T();
		}

		std::ifstream file{ filePath };
		std::string buffer = "";
		T ret;

		LOG_DEBUG("Starting getProperty method...");
		
		while (std::getline(file,buffer))
		{

			buffer.erase(std::remove_if(buffer.begin(), buffer.end(), [](char ch)
			{
				return std::isspace<char>(ch, std::locale::classic());
			}));

			if (buffer[0] == '[' && "[" + header + "]" == buffer)
			{
				while (std::getline(file, buffer))
				{
					if (std::isspace<char>(buffer[0], std::locale::classic()))
					{
						buffer.erase(std::remove_if(buffer.begin(), buffer.end(), [](char ch)
						{
							return std::isspace<char>(ch, std::locale::classic());
						}));

						if (buffer.substr(0, buffer.find('=')) == key)
						{
							LOG_DEBUG("Returning correct value!");
							std::istringstream iss(buffer.substr(buffer.find('=') + 1, buffer.length() - buffer.find('=')));
							iss >> std::dec >> ret;
							return ret;
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
	bool fileExists();
	//std::string deleteComments(std::string line);

	// Members
	std::string filePath;
	bool headerFound;
};