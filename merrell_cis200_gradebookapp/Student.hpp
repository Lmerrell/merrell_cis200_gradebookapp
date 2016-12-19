#pragma once
#include <vector>
#include "Category.hpp"

using namespace std;

class Student
{
private:
	string name;
	vector<int> scores;

public:
	Student(string n)
	{
		name = n;
	}
	Student() {};
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void addScore(int v)
	{
		scores.push_back(v);
		
	}
	int getScore(int n)
	{
		return scores.at(n);
	}
	
};