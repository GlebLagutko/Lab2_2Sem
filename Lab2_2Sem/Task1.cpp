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

void CleanList(list<wstring>& set)
{
	for (auto it = set.begin(); it != set.end(); it++)
		if (it->empty())
		{
			set.erase(it);
			it = set.begin();
		}
}

list<wstring> Difference(list<wstring>& set1, list<wstring>& set2, list<wstring>& set3)
{
	list<wstring> SetDifference1(set1.size());
	list<wstring> SetDifference2(set1.size());
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), SetDifference1.begin());	
	SetDifference1.sort();
	set_difference(SetDifference1.begin(), SetDifference1.end(), set3.begin(), set3.end(), SetDifference2.begin());
	CleanList(SetDifference2);
	return SetDifference2;
}

list<wstring> SymmetricDifference(list<wstring>& set1, list<wstring>& set2, list<wstring>& set3)
{
	list<wstring> SetSymmetricDifference1(set1.size() + set2.size());
	list<wstring> SetSymmetricDifference2(set1.size() + set2.size() + set3.size());
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), SetSymmetricDifference1.begin());
	SetSymmetricDifference1.sort();
	set_symmetric_difference(set3.begin(), set3.end(), SetSymmetricDifference1.begin(), SetSymmetricDifference1.end(), SetSymmetricDifference2.begin());
	CleanList(SetSymmetricDifference2);
	return SetSymmetricDifference2;
}

list<wstring> Union(list<wstring>& set1, list<wstring>& set2, list<wstring>& set3)
{
	list<wstring> SetUnion1(set1.size() + set2.size() + set3.size());
	list<wstring> SetUnion2(set1.size() + set2.size() + set3.size() + 1);
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), SetUnion1.begin());
	SetUnion1.sort();
    set_union(set3.begin(), set3.end(), SetUnion1.begin(), SetUnion1.end(), SetUnion2.begin());
	CleanList(SetUnion2);
	return SetUnion2;
}

list<wstring> Intersection(list<wstring>& set1, list<wstring>& set2, list<wstring>& set3)
{
	list<wstring> SetIntersection1(set1.size() + set2.size() + set3.size());
	list<wstring> SetIntersection2(set1.size() + set2.size() + set3.size());
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), SetIntersection1.begin());	
	SetIntersection1.sort();
	set_intersection(set3.begin(), set3.end(), SetIntersection1.begin(), SetIntersection1.end(), SetIntersection2.begin());
	CleanList(SetIntersection2);
	return SetIntersection2;
}

list<wstring> FillSet(wstring name)
{
	wifstream wifile;
	list<wstring> wset;
	wstring string;
	wifile.open(name);
	wifile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	while (wifile.good())
	{
			getline(wifile, string);
			if(!string.empty())
			wset.push_back(string);
	}
	wset.sort();
	return wset;
}

int main()
{
	list<wstring> Lake1 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake1.txt");
	list<wstring> Lake2 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake2.txt");
	list<wstring> Lake3 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake3.txt");
	
	list<wstring> SetUnion = Union(Lake1,Lake2,Lake3);
	list<wstring> SetFirst = Difference(Lake1, Lake2, Lake3);
	list<wstring> SetIntersection = Intersection(Lake1, Lake2, Lake3);
	list<wstring> SetIndividual = SymmetricDifference(Lake1, Lake2, Lake3);
	system("pause");
	return 0;
}
