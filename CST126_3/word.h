// word.h
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <locale>
using namespace std;

class WordCount
{
public:
	WordCount();
	//string* p_word= word;
	int count_pp() { return count = count++; };
	auto output() { cout <<"\t"<< word << "\t" << count << endl; };

//private:
	int count;
	string word;
};
