#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int getLargestSetSize(vector<int> v);

template <typename T>
void printVector(vector<T> v);

int main()
{
	ifstream fin("input.txt");
	int n;
	int val;
	vector<int> v;

	if (fin.fail())
	{
		cerr << "File doesn't exist." << endl;
		exit(100);
	}

	fin >> n;
	while (!fin.eof())
	{
		fin >> val;
		v.push_back(val);
	}
	//printVector<int>(v);
	cout << getLargestSetSize(v) << endl;

	fin.close();
	return 0;
}

int getLargestSetSize(vector<int> v)
{
	if (v.size() == 1) return 1;
	
	int largest_size = -1;
	bool changed = false;

	map<int, int> m;
	sort(v.begin(), v.end());

	for (auto it = v.begin(); it != v.end(); it++)
	{
		changed = false;
		for (auto mit = m.begin(); mit != m.end(); mit++)
		{
			if (pow(mit->first, 1 << mit->second) == *it)
			{
				mit->second += 1;
				if (mit->second > largest_size) largest_size = mit->second;
				changed = true;
				break;
			}
		}
		if (!changed) m.insert({ *it, 1 });
	}

	return largest_size;
}

template <typename T>
void printVector(vector<T> v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}