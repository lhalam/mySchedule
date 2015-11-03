#pragma once
#include <iostream>
#include <map>

using namespace std;

class Template
{
private:
	string templ;
public:
	Template();
	string load(ifstream& f);
	string render(map<TKey, Entity>);
	~Template();
};
