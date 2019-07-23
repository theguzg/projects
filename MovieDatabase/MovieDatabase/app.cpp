#include "Movie.h"
#include "UI.h"
#include <Windows.h>
#include "Test.h"

using namespace std;

int main() 
{
	system("color f4");

	Test::testAll();

	Repository repo{};

	Movie m1{"Logan","Action",2017,500,"https://www.youtube.com/watch?v=Div0iP65aZo"};
	Movie m2{"The Pick of Destiny","Comedy", 2010, 1000, "https://www.youtube.com/watch?v=TXxQFMG86HA"};
	Movie m3{"IT","Comedy",2017,700,"https://www.youtube.com/watch?v=hAUTdjf9rko"};
	Movie m4{"Fast and Furious","Racing", 2005, 404,"de ce"};
	Movie m5{"Little Mermaid","Cartoon",2002,15,"nu vreau"};
	Movie m6{"The avengers","Action",2015,5959,"navem"};
	Movie m7{"Ice Age","Cartoon",2008,99,"nnicci aici"};
	Movie m8{"Assassins Creed","Action",2014,666,"ce"};
	Movie m9{"Prince of Persia","Fantasy",2012,442,"nana"};
	Movie m10{"Lion King","Cartoon",1997,699,"ma"};
	repo.addMovie(m1);
	repo.addMovie(m2);
	repo.addMovie(m3);
	repo.addMovie(m4);
	repo.addMovie(m5);
	repo.addMovie(m6);
	repo.addMovie(m7);
	repo.addMovie(m8);
	repo.addMovie(m9);
	repo.addMovie(m10);
	

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}