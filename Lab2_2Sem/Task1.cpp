#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <codecvt>
#include <list>

using namespace std;

void PrintSet(vector<wstring>& set)
{
	for (auto it = set.begin(); it != set.end(); ++it)
		wcout << *it << endl ;
}

void Print(vector<wstring>& set1, vector<wstring>& set2, vector<wstring>& set3, vector<wstring>& set4)
{
	wcout << L" 1 :";
	PrintSet(set1);
	wcout << L" 2 :";
	PrintSet(set2);
	wcout << L" 3 :";
	PrintSet(set3);
	wcout << L" 4 :";
	PrintSet(set4);
}

vector<wstring> Difference(vector<wstring>& set1, vector<wstring>& set2, vector<wstring>& set3)
{
	vector<wstring> SetDifference;
	SetDifference.end() = set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), SetDifference.begin());	
	SetDifference.end() = set_difference(SetDifference.begin(), SetDifference.end(), set3.begin(), set3.end(), SetDifference.begin());

	return SetDifference;
}

vector<wstring> SymmetricDifference(vector<wstring>& set1, vector<wstring>& set2, vector<wstring>& set3)
{
	vector<wstring> SetSymmetricDifference;
	SetSymmetricDifference.end() = set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), SetSymmetricDifference.begin());
	SetSymmetricDifference.end() = set_symmetric_difference(set3.begin(), set3.end(), SetSymmetricDifference.begin(), SetSymmetricDifference.end(), SetSymmetricDifference.begin());

	return SetSymmetricDifference;
}

vector<wstring> Union(vector<wstring>& set1, vector<wstring>& set2, vector<wstring>& set3)
{
	vector<wstring> SetUnion(set1.size() + set2.size() + set3.size());
	SetUnion.end() = set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), SetUnion.begin());
    SetUnion.end() = set_union(set3.begin(), set3.end(), SetUnion.begin(), SetUnion.end(), SetUnion.begin());
	return SetUnion;
}

vector<wstring> Intersection(vector<wstring>& set1, vector<wstring>& set2, vector<wstring>& set3)
{
	vector<wstring> SetIntersection;
	SetIntersection.end() = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), SetIntersection.begin());	
	SetIntersection.end() = set_intersection(set3.begin(), set3.end(), SetIntersection.begin(), SetIntersection.end(), SetIntersection.begin());
	return SetIntersection;
}

vector<wstring> FillSet(wstring name)
{
	wifstream wifile;
	vector<wstring> wset;
	wstring string;
	wifile.open(name);
	wifile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	while (wifile.good())
	{
			getline(wifile, string);
			if(!string.empty())
			wset.push_back(string);
	}
	return wset;
}

void SortVector(vector<wstring> vector)
{
	sort(vector.begin(),vector.end());
}

int main()
{
	vector<wstring> Lake1 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake1.txt");
	vector<wstring> Lake2 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake2.txt");
	vector<wstring> Lake3 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake3.txt");
	SortVector(Lake1);
	SortVector(Lake2);
	SortVector(Lake3);
	vector<wstring> SetUnion = Union(Lake1,Lake2,Lake3);
	vector<wstring> SetIntersection = Intersection(Lake1, Lake2, Lake3);
	vector<wstring> SetIndividual = SymmetricDifference(Lake1, Lake2, Lake3);
	vector<wstring> SetFirst = Difference(Lake1,Lake2,Lake3) ; 
	Print(SetUnion, SetIntersection, SetIndividual, SetFirst);

	system("pause");
	return 0;
}
