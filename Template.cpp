#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "Template.h"

using namespace std;

Template::Template() : templ("none")
{

}

string Template::load(ifstream& InputFile)
{
	string str;
	InputFile >> str;
	templ = str;
	return str;
}

string Template::render(map<TKey key, Entity obj> mp)
{
	string str = to_string(mp.find(key));
	templ = str;
	return str;
}

Template::~Template()
{
}
