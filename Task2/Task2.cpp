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

void PrintSet(multiset<wstring>& set)
{
	for (auto it : set)
		wcout << it << endl;
}

multiset<wstring> Union(multiset<wstring>& set1, multiset<wstring>& set2, multiset<wstring>& set3)
{
	multiset<wstring> set;
	set.insert(set1.begin(), set1.end());
	set.insert(set2.begin(), set2.end());
	set.insert(set3.begin(), set3.end());
	return set;
}

multiset<wstring> FillSet(wstring name)
{
	wifstream wifile;
	multiset<wstring> wset;
	wstring string;
	wifile.open(name);
	wifile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	while (wifile.good())
	{
		getline(wifile, string);
		if (!string.empty())
			wset.insert(string);
	}
	return wset;
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	multiset<wstring> aquarium1 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab2_2Sem\\aquarium1.txt");
	multiset<wstring> aquarium2 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab2_2Sem\\aquarium2.txt");
	multiset<wstring> aquarium3 = FillSet(L"C:\\Users\\Dell\\source\\repos\\Lab2_2Sem\\aquarium3.txt");
	multiset<wstring> set = Union(aquarium1, aquarium2, aquarium3);
	PrintSet(set);
	system("pause");
}