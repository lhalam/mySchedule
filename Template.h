#pragma once
#include <iostream>
#include <map>

using namespace std;

class Template
{
private:

public:
	Template();

	string render(Template, map<TKey, Entity>);

};
