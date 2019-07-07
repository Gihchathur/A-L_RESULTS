
#include <iostream>
#include <iomanip>
#include <fstream>//including header files
#include <sstream>
#include <vector>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include<time.h>
using namespace std;

int row = 0, indexrow;

using vec = vector<string>;//create 2d vector array
using matrix = vector<vec>;

void setCursorPosition(int x, int y);//initialise setcursor function



void setCursorPosition(int x, int y)//this function is used to bring necessary cursor position
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

class readcsv
{
public:

	matrix readCSV(string filename)//this is read my csv files
	{
		char separator = ',';
		matrix result;
		string rows, item;//row by row enter read the data's
		ifstream in(filename);

		while (getline(in, rows))
		{
			int big = 0;
			row++;//using vectors to read that data
			vec R;
			stringstream ss(rows);

			while (getline(ss, item, separator)) {//row by row enter read the data's
				R.push_back(item);
				big++;//for count to get array row and column sizes

			}

			result.push_back(R);//array push back and oad another line
		}
		in.close();

		return result;
	}

};



class indexnum
{
public:
	void printindex(const matrix& details, int indexrow)
	{
		cout << "\nINDEX :- " << details[indexrow][0];
	}
};

class name
{
public:
	void printname(const matrix& details, int indexrow)
	{
		cout << "\nNAME :- " << details[indexrow][1];
	}
};

class zscore {

public:
	void printzscore(const matrix& details, int indexrow)
	{
		cout << "\nZ-SCORE :- " << details[indexrow][2];
	}
};

class drank
{
public:
	void printdrank(const matrix& details, int indexrow)
	{
		cout << "\nDISTRICT RANK :- " << details[indexrow][3];
	}

};

class irank
{
public:
	void printisrank(const matrix& details, int indexrow)
	{
		cout << "\nISLAND RANK :- " << details[indexrow][4];
	}
};

class stream
{
public:
	void printstream(const matrix& details, int indexrow)
	{
		cout << "\nSTREAM :- " << details[indexrow][5];
	}

};

class subjectdetails
{
public:
	void printsub(const matrix& details, int indexrow)
	{
		cout << "\nSUBJECTS :- " << "\n\t" << details[indexrow][6] << "\n\t" << details[indexrow][7] << "\n\t" << details[indexrow][8];
	}

};



class findindex
{
public:
	findindex(const matrix& details, string index)
	{
		for (int x = 1; x < row; x++)
		{
			if (details[x][0] == index)
			{
				indexrow = x;
			}
		}
	}
};


int main()
{

	readcsv newclz;//create new class variable
				   //---------file including---------------------
	matrix details = newclz.readCSV("details.csv");

	int nn;
	cout << "1.ONE INDEX \n2.MANY INDEX WITH SORT : ";
	cin >> nn;

	//---------------------------------------------------------------------------------------
	if (nn == 1) {
		string index;
		cout << "Enter the index : ";
		cin >> index;

		system("cls");

		findindex find(details, index);

		indexnum varindex; varindex.printindex(details, indexrow);
		name varname;  varname.printname(details, indexrow);
		zscore varzscore; varzscore.printzscore(details, indexrow);
		drank vardrank; vardrank.printdrank(details, indexrow);
		irank varirank; varirank.printisrank(details, indexrow);
		stream varstream; varstream.printstream(details, indexrow);
		subjectdetails varsub; varsub.printsub(details, indexrow);

		system("pause");

	}
	//-------------------------------------------------------------------------------
	else if (nn == 2) {
		int n;
		cout << "\n\nEnter How Many Num index : "; cin >> n;

		string* list;
		list = new string[n];
		int* listnum = new int[n];

		for (int i = 0; i < n; i++)
		{

			cin >> list[i];
			findindex find(details, list[i]);
			listnum[i] = indexrow;

		}

		for (int i = 0; i < n - 1; i++)
		{
			if (stof(details[listnum[i]][2]) < stof(details[listnum[i + 1]][2]))
			{
				int temp = listnum[i];
				listnum[i] = listnum[i + 1];
				listnum[i + 1] = temp;
				i = -1;
				cout << "aa";
			}
		}
		system("cls");


		for (int i = 0; i < n; i++)
		{
			
			indexrow = listnum[i];
			cout << endl << endl << endl;
			indexnum varindex; varindex.printindex(details, indexrow);
			name varname;  varname.printname(details, indexrow);
			zscore varzscore; varzscore.printzscore(details, indexrow);
			drank vardrank; vardrank.printdrank(details, indexrow);
			irank varirank; varirank.printisrank(details, indexrow);
			stream varstream; varstream.printstream(details, indexrow);
			subjectdetails varsub; varsub.printsub(details, indexrow);




		}
		system("pause");

	}

	else
		cout << "\n\twrong input";

	return 0;

}