#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;

struct student
{
	string name, gender, score;
	double sco;
	bool sex;
	student() {};
	student(string n, string g, string s, double sc) :name(n), gender(g), score(s), sco(sc) {};
	void dissex()
	{
		sex = (gender == "Female");
	}
};

bool cmp(student a, student b)
{
	if (a.sco == b.sco)
		return a.name < b.name;
	return a.sco > b.sco;
}

vector<student> all, male, female;

double average(const vector<student>& stu)
{
	double sum = 0;
	for (auto a : stu)
		sum += a.sco;
	return sum / double(stu.size());
}

int main()
{
	ifstream fin("score.csv", ios_base::in);
	string line;
	getline(fin, line);
	string name, gender, score;

	while (getline(fin, line))
	{
		stringstream sin(line);
		getline(sin, name, ',');
		getline(sin, gender, ',');
		getline(sin, score, ',');
		gender.erase(0, 1);
		score.erase(0, 1);
		double sco = stod(score);
		student tmp(name, gender, score, sco);
		tmp.dissex();
		if (tmp.sex)
			female.push_back(tmp);
		else
			male.push_back(tmp);
		all.push_back(tmp);
	}
	cout << "Average of all students: " << fixed << setprecision(1) << average(all) << endl
		<< "Average of male students: " << average(male) << endl << "Average of female students: " << average(female) << endl;

	sort(all.begin(), all.end(), cmp);
	for (auto a : all)
	{
		cout << a.name << " " << a.gender << " " << a.score << endl;
	}
	return 0;
}
