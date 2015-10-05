#include <iostream>
#include <sstream>
#include <map>
#include "Template.h"

using namespace std;

Template::Template()
{

}

string Template::render(Template temp, map<TKey key, Entity obj>)
{
	std::string str = std::to_string(obj.User.property);

	return str;
}
