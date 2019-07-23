#include "UI.h"
#include "FileRepository.h"
#include <iostream>

using namespace std;
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "main.h"

int main() {

	{
		testCreate();
		testRepository();
		testController();
		testReteta();
		testFileRepo();

		
		cout << "Salut! Bine ai venit la aplicatia --Farmacie--" << endl << endl;
		cout << "Alegeti tipul de repository:\n\t---->memorie\n\t---->fisier\n";
		string optiune;
		while (1) {

			cout << "Optiunea dumneavoastra este: "; cin >> optiune;
			if (optiune == "memorie")
			{
				Repository repo;
				Reteta reteta;
				Controller ctrl = Controller(repo);
				ControllerReteta ctrlRet{ reteta,repo };
				Console csl{ ctrl,ctrlRet };
				csl.showOptions();
				break;
			}
			else if (optiune == "fisier")
			{
				FileRepository fileRepo("Medicamente.CVS");
				Reteta reteta;
				Controller ctrl = Controller(fileRepo);
				ControllerReteta ctrlRet{ reteta,fileRepo };
				Console csl{ ctrl,ctrlRet };
				csl.showOptions();
				break;
			}
			else
				cout << "Optiune invalida!!";
		}
	}
		_CrtDumpMemoryLeaks();
		
		return 0;
}

