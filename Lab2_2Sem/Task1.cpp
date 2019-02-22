#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <codecvt>
#include <list>
#include <io.h>
#include <fcntl.h>

using namespace std;

void PrintSet(set<wstring>& set)
{
	for (auto it : set)
		if(!it.empty())
			wcout << it << endl;
}

void Answer(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3, set<wstring>& set4)
{
	wcout << L"1 : ";
	PrintSet(set1);
	wcout << L"2 : ";
	PrintSet(set2); 
	wcout << L"3 : ";
	PrintSet(set3);
	wcout << L"4 : ";
	PrintSet(set4);
}

set<wstring> Difference(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	list<wstring> SetDifference1(set1.size());
	list<wstring> SetDifference2(set1.size());
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), SetDifference1.begin());	
	SetDifference1.sort();
	set_difference(SetDifference1.begin(), SetDifference1.end(), set3.begin(), set3.end(), SetDifference2.begin());
	set<wstring> set(SetDifference2.begin(), SetDifference2.end());
	return set;
}

set<wstring> SymmetricDifference(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	list<wstring> SetSymmetricDifference1(set1.size() + set2.size());
	list<wstring> SetSymmetricDifference2(set1.size() + set2.size() + set3.size());
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), SetSymmetricDifference1.begin());
	SetSymmetricDifference1.sort();
	set_symmetric_difference(set3.begin(), set3.end(), SetSymmetricDifference1.begin(), SetSymmetricDifference1.end(), SetSymmetricDifference2.begin());
	set<wstring> set(SetSymmetricDifference2.begin(), SetSymmetricDifference2.end());
	return set;
}

set<wstring> Union(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	list<wstring> SetUnion1(set1.size() + set2.size() + set3.size());
	list<wstring> SetUnion2(set1.size() + set2.size() + set3.size() + 1);
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), SetUnion1.begin());
	SetUnion1.sort();
    set_union(set3.begin(), set3.end(), SetUnion1.begin(), SetUnion1.end(), SetUnion2.begin());
	set<wstring> set(SetUnion2.begin(), SetUnion2.end());
	return set;
}

set<wstring> Intersection(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	list<wstring> SetIntersection1(set1.size() + set2.size() + set3.size());
	list<wstring> SetIntersection2(set1.size() + set2.size() + set3.size());
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), SetIntersection1.begin());	
	SetIntersection1.sort();
	set_intersection(set3.begin(), set3.end(), SetIntersection1.begin(), SetIntersection1.end(), SetIntersection2.begin());
	set<wstring> set(SetIntersection2.begin(), SetIntersection2.end());
	
	return set;
}

set<wstring> FillSet(wstring name)
{
	wifstream wifile;
	set<wstring> wset;
	wstring string;
	wifile.open(name);
	wifile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	while (!wifile.eof())
	{
			getline(wifile, string);
			if(!string.empty())
			wset.insert(string);
	}
	return wset;
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
	set<wstring> Lake1 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake1.txt");
	set<wstring> Lake2 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake2.txt");
	set<wstring> Lake3 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake3.txt");
	
	set<wstring> SetUnion = Union(Lake1,Lake2,Lake3);
	set<wstring> SetFirst = Difference(Lake1, Lake2, Lake3);
	set<wstring> SetIntersection = Intersection(Lake1, Lake2, Lake3);
	set<wstring> SetIndividual = SymmetricDifference(Lake1, Lake2, Lake3);
	Answer(SetUnion, SetIntersection, SetIndividual, SetFirst);
	system("pause");
	return 0;
}
