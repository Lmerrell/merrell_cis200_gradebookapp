#pragma once
#include <string>

using namespace std;

class Category
{
private:
	int weight;
	string category;
public:
	Category(string c, int w)
	{
		weight = w;
		category = c;
	}
	void setWeight(int n)
	{
		weight = n;
	}
	int getWeight()
	{
		return weight;
	}
	void setCategory(string s)
	{
		category = s;
	}
	string getCategory()
	{
		return category;
	}
};