#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <codecvt>
#include <vector>
using namespace std;



void PrintSet(set<wstring>& set)
{
	for (auto iterator = set.begin(); iterator != set.end(); ++iterator)
		wcout << *iterator << endl;
}

void Print(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3, set<wstring>& set4)
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

/*set<wstring> Difference(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	set<wstring> SetDifference;
	set_difference(set1.cbegin(), set1.cend(), set2.cbegin(), set2.cend(), SetDifference.begin());
	set_difference(SetDifference.cbegin(), SetDifference.cend(), set3.cbegin(), set3.cend(), SetDifference.begin());
	

	return SetDifference;
}

set<wstring> SymmetricDifference(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	set<wstring> SetSymmetricDifference;
	set_symmetric_difference(set1.cbegin(), set1.cend(), set2.cbegin(), set2.cend(), SetSymmetricDifference.begin());
	set_symmetric_difference(set3.cbegin(), set3.cend(), SetSymmetricDifference.cbegin(), SetSymmetricDifference.cend(), SetSymmetricDifference.begin());
	return SetSymmetricDifference;
}

set<wstring> Union(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	set<wstring> SetUnion;
	set_union(set1.cbegin(), set1.cend(), set2.cbegin(), set2.cend(), SetUnion.begin());
	set_union(set3.cbegin(), set3.cend(), SetUnion.cbegin(), SetUnion.cend(), SetUnion.begin());
	return SetUnion;
}

set<wstring> Intersection(set<wstring>& set1, set<wstring>& set2, set<wstring>& set3)
{
	set<wstring> SetIntersection;
	set_intersection(set1.cbegin(), set1.cend(), set2.cbegin(), set2.cend(), SetIntersection.begin());
	set_intersection(set3.cbegin(), set3.cend(), SetIntersection.cbegin(), SetIntersection.cend(), SetIntersection.begin());
	return SetIntersection;
}*/

set<wstring> FillSet(wstring name)
{
	wifstream wifile;
	set<wstring> wset;
	wifile.open(name);
	wifile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	while (!wifile.eof())
	{
		    wstring string;
			getline(wifile, string);
			wset.insert(string);
	}
	return wset;
}

int main()
{
	set<wstring> Lake1 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake1.txt");
	set<wstring> Lake2 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake2.txt");
	set<wstring> Lake3 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab1_2Sem\\lake3.txt");
	set<int> SetIntersection;
	std::set<int>::iterator it;
	//set_intersection(Lake1.cbegin(), Lake1.cend(), Lake2.cbegin(), Lake2.cend(), SetIntersection.begin());

	int first[] = { 5,10,15,20,25 };
	int second[] = { 50,40,30,20,10 };

	it = std::set_symmetric_difference(first, first + 5, second, second + 5, SetIntersection.begin());
	/*set<wstring> SetUnion = Union(Lake1,Lake2,Lake3);
	set<wstring> SetIntersection = Intersection(Lake1, Lake2, Lake3);
	set<wstring> SetIndividual = SymmetricDifference(Lake1, Lake2, Lake3);
	set<wstring> SetFirst = Difference(Lake1,Lake2,Lake3);
	Print(SetUnion, SetIntersection, SetIndividual, SetFirst);*/

	system("pause");
	return 0;
}
