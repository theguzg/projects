#include "stdafx.h"
#include "Tests.h"
#include "UI.h"
#include "FileWatchList.h"
#include "HTMLWatchList.h"
#include "CSVWatchList.h"


int main()
{
	Repository repo{ "movies.txt" };
	FileWatchList* p;
	cout << "Choose the type of the exported file:\n";
	cout << "\t0.HTML\n";
	cout << "\t1.CSV\n";
	bool opt;
	cin >> opt;
	if (opt)
		p = new CSVWatchList{};
	else
		p = new HTMLWatchList{};
	Controller ctrl{ repo, p };

	UI ui{ ctrl };
	ui.run();

	return 0;
}

