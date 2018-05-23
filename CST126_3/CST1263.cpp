// CST1263.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "word.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

bool OpenFile(ifstream& input_file);

int main()
{
	ifstream fed_file;
	cout << "Generating word count..." << endl << endl;
	if (OpenFile(fed_file))
	{
		string RawWord;
		const int allo = 999;

		WordCount *WordList = new WordCount[allo];
		while (!fed_file.eof() && fed_file>>RawWord)
		{

				int cntr = 0;
				//cout << RawWord;
				for (int i = 0; RawWord[i]; i++) RawWord[i] = tolower(RawWord[i]); //http://www.cplusplus.com/forum/beginner/25649/
				for (int i = 0, len = RawWord.size(); i < len; i++)
				{
					if (RawWord.length()!=0 && ispunct(RawWord[i]))
					{
						RawWord.erase(i--, 1);
						len = RawWord.size();
					}
				}//https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string

				//cout << RawWord << " " << endl;
				int found = 0;
				
					while (found == 0)
					{
						if (WordList[cntr].word == RawWord)
						{
							WordList[cntr].count_pp();
							//cout << WordList->count << endl;
							found++;
						}
						if (WordList[cntr].word == " ")
						{
							WordList[cntr].word = RawWord;
							found++;
							WordList[cntr].count_pp();
							//WordList[cntr].output();
						}
						cntr++;
					}
		}
		//WordList[3].output();
		int r = 0;
		int cent = 0;
		int occur = 150;
		while (occur != 0)
		{
			while (r != allo && cent < 10)
			{
				if (occur == WordList[r].count)
				{
					WordList[r].output();
					cent++;
					//r = 0;
				}
				r++;
			}
			r = 0;
			occur--;
		}
		//cout << << endl;
		delete[] WordList;
		return 0;
	}

}


bool OpenFile(ifstream& input_file)
{
	string file_name;
	cout << "What is the name of your file?" << endl;
	cin >> file_name;
	input_file.open(file_name);

	if (input_file.fail())
	{
		cout << "Failed to load file: " << file_name << endl;
		return false;
	}
	else
		return true;
}