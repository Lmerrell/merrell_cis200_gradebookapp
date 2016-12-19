#include <iostream>
#include "Category.hpp"
#include "GradeBook.hpp"
#include <string>
#include <exception>
using namespace std;

int main()
{
	int categoryAnswer;
	string categoryName;
	double categoryWeight;
	int counter=0;
	GradeBook book1;
	string nameVariable;
	vector<Category> listOfCategories;
	double score;
	string studentName;

	cout << "How many categories would you like to have?: ";
	cin >> categoryAnswer;

	for (int i = 0; i < categoryAnswer; i++)
	{
		cout << "What is the name of category #" << i + 1 << " ?: ";
		cin >> categoryName;
		getline(cin, categoryName);
		cout << "What is the grade weight of category #" << i + 1 << " ?: ";
		cin >> categoryWeight;
		counter += categoryWeight;
		try
		{
			if (counter > 100)
			{
				throw 1;
			}
		}
		catch(int e)
		{

			cout << "You entered a total of more than 100% for the weight." << endl;
		}

		book1.addGrade(categoryName, categoryWeight);
		listOfCategories.push_back(Category(categoryName, categoryWeight));
	}

	do 
	{
		cout << "Please enter student name ('quit' to exit): ";
		cin >> nameVariable;
		if (nameVariable != "quit")
		{
			Student stud1(nameVariable);
			for (int i = 0; i < listOfCategories.size(); i++)
			{
				cout << listOfCategories.at(i).getCategory() << "( " << listOfCategories.at(i).getWeight() << " ): ";
				cin >> score;
				stud1.addScore(score);
			}
			book1.addStudent(stud1);
		}
	} while (nameVariable != "quit");

	int menuSelection=-1;

	while (menuSelection != 0)
	{
		cout << "Menu Options: " << endl;
		cout << "1.) Calculate the class average." << endl;
		cout << "2.) Show average score of each category." << endl;
		cout << "3.) Show individual student scores." << endl;
		cout << "0.) Exit menu." << endl;
		cin >> menuSelection;
		if (menuSelection == 1)
		{
			cout << "Class average is: " << book1.classAvg() << "." << endl;
		}
		else if (menuSelection == 2)
		{
			for (int i = 0; i < listOfCategories.size(); i++)
			{
				cout << listOfCategories.at(i).getCategory() << " : " << book1.avgForCategory(i);
				cout << " / ";
				cout << listOfCategories.at(i).getWeight();
				cout << endl;
			}
		}
		else if (menuSelection == 3)
		{
			cout << "Enter the student whose name you wish to access: ";
			cin >> studentName;
			cout << "The average for " << studentName << " is " << book1.avgForStudent(studentName) << ".";
			cout << endl;
		}
	}

	system("pause");
	return 0;
}