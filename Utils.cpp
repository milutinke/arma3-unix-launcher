/*
 * Utils.cpp
 *
 *  Created on: 20 Oct 2016
 *      Author: muttley
 */

#include "Utils.h"

#include <cstring>
#include <algorithm>

using namespace std;

Utils::Utils()
{
}

Utils::~Utils()
{
}

vector<string> Utils::Split(std::string textToSplit, std::string delimiters)
{
	vector<string> response;
	char* text = new char[textToSplit.size() + 1];
	strcpy(text, textToSplit.c_str());
	char* strPtr = strtok(text, delimiters.c_str());
	while (strPtr != NULL)
	{
		string toAdd = strPtr;
		toAdd = Trim(toAdd);
		if (toAdd.length() > 0)
			response.push_back(strPtr);
		strPtr = strtok(NULL, delimiters.c_str());
	}
	return response;
}

bool Utils::StartsWith(string textToCheck, string textToFind)
{
	if (textToFind.size() > textToCheck.size())
		return false;
	if (strncmp(textToCheck.c_str(), textToFind.c_str(), textToFind.size()) == 0)
		return true;
	return false;
}

string Utils::Replace(string str, string from, string to)
{
	size_t start_pos = str.find(from);
	if(start_pos == std::string::npos)
		return str;;
	str.replace(start_pos, from.length(), to);
	return str;
}

string Utils::Trim(const string& s)
{
    return TrimRight(TrimLeft(s));
}

string Utils::TrimLeft(const string& s)
{
    size_t startpos = s.find_first_not_of(" \n\r\t");
    return (startpos == std::string::npos) ? "" : s.substr(startpos);
}

string Utils::TrimRight(const string& s)
{
    size_t endpos = s.find_last_not_of(" \n\r\t");
    return (endpos == std::string::npos) ? "" : s.substr(0, endpos+1);
}

string Utils::RemoveLastElement(string s, bool removeSlash)
{
	if (s.length() == 0)
		return "";
	reverse(s.begin(), s.end());

	size_t slashPos = s.find("/");

	if (removeSlash)
		slashPos++;

	s = s.substr(slashPos);
	reverse(s.begin(), s.end());

	return s;
}