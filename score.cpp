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
	string name, gender, sco;
	double score;
	bool sex;
	student() {};
	student(string n, string g, string s, double ss) :name(n), gender(g), sco(s), score(ss) {};
	void dissex()
	{
		sex = (gender == "Female");
	}
};

bool cmp(student a, student b)
{
	if (a.score == b.score)
		return a.name < b.name;
	return a.score > b.score;
}

vector<student> all, male, female;

double average(const vector<student>& stu)
{
	double sum = 0;
	for (auto a : stu)
		sum += a.score;
	return sum / double(stu.size());
}

int main()
{
	ifstream fin("score.csv", ios_base::in);
	string line;
	getline(fin, line);
	string name, gender, sco;

	while (getline(fin, line))
	{
		stringstream sin(line);
		getline(sin, name, ',');
		getline(sin, gender, ',');
		getline(sin, sco, ',');
		gender.erase(0, 1);
		sco.erase(0, 1);
		double sc = stod(sco);
		student tmp(name, gender, sco, sc);
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
		cout << a.name << " " << a.gender << " " << a.sco << endl;
	}
	return 0;
}
