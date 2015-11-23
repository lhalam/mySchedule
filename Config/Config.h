#pragma once

#include <string>
#include <fstream>
#include <map>

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

			fin.close();
		}

		return res;
	}
};
