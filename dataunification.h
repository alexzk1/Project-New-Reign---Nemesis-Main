#ifndef DATAUNIFICATION_H_
#define DATAUNIFICATION_H_

#include <iostream>
#include <boost\thread.hpp>
#include <boost\regex.hpp>
#include <boost\filesystem.hpp>
#include <boost\algorithm\string.hpp>
#include "functions\functionupdate.h"
#include "functions\writetextfile.h"
#include "add animation\animationdata.h"
#include "add animation\animationsetdata.h"

void behaviorJointsOutput();

bool animDataHeaderUpdate(std::string folderpath, std::string modcode, MasterAnimData& animData, std::unordered_map<std::string, std::string>& lastUpdate);
bool newAnimUpdateExt(std::string folderpath, std::string modcode, std::string behaviorfile, std::map<std::string, vecstr, alphanum_less>& newFile,
	std::map<std::string, vecstr>& newAnimAddition, std::unordered_map<std::string, std::string>& lastUpdate);
bool newAnimDataUpdateExt(std::string folderpath, std::string modcode, std::string characterfile, MasterAnimData& animData,
	std::map<std::string, vecstr>& newAnimAddition, std::unordered_map<std::string, std::string>& lastUpdate);
bool newAnimDataSetUpdateExt(std::string folderpath, std::string modcode, std::string characterfile, MasterAnimSetData& animSetData,
	std::map<std::string, vecstr>& newAnimAddition, std::unordered_map<std::string, std::string>& lastUpdate);

template<typename list>
void comparing(std::vector<list>& storeline, std::vector<list>& originallines, std::string filename, int counter);

template<typename list>
void comparing(std::vector<list>& storeline, std::vector<list>& originallines, std::string filename, int counter)
{
	vecstr combinelines;
	vecstr newlines;
	vecstr extract;
	int linecount = 0;
	bool close = false;

	for (unsigned int k = 0; k < storeline.size(); ++k)
	{
		if (storeline[k].name.find("<!-- CONDITION") != NOT_FOUND)
		{
			ErrorMessage(5004, filename, counter + k);
		}

		if (storeline[k].name.find("<!-- NEW", 0) == NOT_FOUND && !close)
		{
			if (originallines[linecount].name.find("<!-- NEW", 0) != NOT_FOUND)
			{
				extract.push_back(originallines[linecount].name);
				++linecount;
				extract.push_back(originallines[linecount].name);
				++linecount;

				while (true)
				{
					if (originallines[linecount].name.find("<!-- CLOSE -->", 0) != NOT_FOUND)
					{
						extract.push_back(originallines[linecount].name);
						++linecount;
						break;
					}
					else
					{
						extract.push_back(originallines[linecount].name);
						++linecount;
					}
				}
			}

			combinelines.push_back(originallines[linecount].name);
			++linecount;
		}
		else if (close && storeline[k].name.find("<!-- CLOSE -->", 0) != NOT_FOUND)
		{
			if (originallines[linecount].name.find("<!-- NEW", 0) != NOT_FOUND)
			{
				extract.push_back(originallines[linecount].name);
				++linecount;
				extract.push_back(originallines[linecount].name);
				++linecount;

				while (true)
				{
					if (originallines[linecount].name.find("<!-- CLOSE -->", 0) != NOT_FOUND)
					{
						extract.push_back(originallines[linecount].name);
						++linecount;
						break;
					}
					else
					{
						extract.push_back(originallines[linecount].name);
						++linecount;
					}
				}
			}

			extract.insert(extract.end(), newlines.begin(), newlines.end());
			extract.push_back(storeline[k].name);
			newlines.clear();
			close = false;
		}
		else
		{
			close = true;
		}

		if (close)
		{
			newlines.push_back(storeline[k].name);
		}
	}

	for (unsigned int j = 0; j < extract.size(); ++j)
	{
		combinelines.push_back(extract[j]);
	}
}

#endif