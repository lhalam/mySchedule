#pragma once
#include <string>
#include <fstream>
#include <map>

#include <iostream>
using namespace std;

class Config
{
private:
	string path;
public:
	Config(string path)
	{
		this->path = path;
	}
	map<string, map<string, string> >  getConfig()
	{
		return pars();
	}
private:
	map<string, map<string, string> > pars()
	{
		map<string, map<string, string> > res;

		cout << this->path;

		ifstream fin(this->path);

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

		return res;
	}
};