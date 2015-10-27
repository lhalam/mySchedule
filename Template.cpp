#include <iostream>
#include <sstream>
#include <map>
#include "Template.h"

using namespace std;

Template::Template(): templ("none")
{

}

string Template::load(char const * filepath)
{
    std::ifstream src(filepath);
    std::ostringstream buf;
    buf << src.rdbuf();
    return buf.str();
}

string Template::render(map<TKey key, Entity obj> mp)
{
	std::string str = std::to_string(mp.find(key));
	templ = str;
	return str;
}
