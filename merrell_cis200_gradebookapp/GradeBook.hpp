#pragma once
#include "Student.hpp"
#include <vector>

using namespace std;

class GradeBook
{
private:
	vector<Category> grades;
	vector<Student> students;
public:
	GradeBook()
	{

	};
	void addGrade(string s, int v)
	{
		grades.push_back(Category(s, v));
	}
	bool containsStudent(string searchName)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if(students.at(i).getName() == searchName)
			{
				return true;
			}
		}
		return false;
	}
	void addStudent(Student s)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students.at(i).getName() == s.getName())
			{
				students[i] = s;
				return;
			}
		}
		students.push_back(s);
		
	}
	double classAvg()
	{
		int sum=0;
		for (int i = 0; i < students.size(); i++)
		{
			for (int j = 0; j < grades.size(); j++)
			{
				sum += students.at(i).getScore(j);
			}
		}
		return sum / students.size();
	}
	double avgForCategory(int n)
	{
		double sum=0;
		for (int i = 0; i < students.size(); i++)
		{
			sum += students.at(i).getScore(n);
		}
		return sum / students.size();
	}
	double avgForStudent(string n)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students.at(i).getName() == n)
			{
				double sum=0;
				for (int j = 0; j < grades.size(); j++)
				{
					sum += students.at(i).getScore(j);
				}
				return sum;
			}
		}
		return -1;
		
	}


};