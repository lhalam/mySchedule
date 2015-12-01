#pragma once

#include <string>
#include <fstream>
#include <map>
#include "..\globals.h"

using std::string;
using std::ifstream;
using std::map;

class Config
{
private:
	string path;

public:
	Config(string path) :
		path(path) { }

	map<string, map<string, string>>  getConfig()
	{
		return parse();
	}
private:
	map<string, map<string, string>> parse()
	{
		map<string, map<string, string> > res;

		ifstream fin(this->path);

		if (fin.is_open())
		{
			try
			{
				while (!fin.eof())
				{
					fin.get();
					string heading;
					getline(fin, heading, ']');
					fin.get();
					while (fin.peek() != '\n' && !fin.eof())
					{
						string item;
						string value;
						getline(fin, item, ' ');
						fin.get();
						fin.get();
						getline(fin, value);

						res[heading][item] = value;
					}
					fin.get();
				}
			}
			catch (exception& exc)
			{
				ConfigLogger::Instance()->Log(LogMessage(__FILE__, __LINE__, string("Fail " + string(exc.what())), __func__));
			}
			fin.close();
			ConfigLogger::Instance()->Log(LogMessage(__FILE__, __LINE__, string("Success"), __func__));
		}
		else
		{
			ConfigLogger::Instance()->Log(LogMessage(string("Failed to read from file"), string(__func__)));
		}
		return res;
	}
};
