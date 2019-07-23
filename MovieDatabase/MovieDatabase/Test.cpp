#include "Test.h"
#include <assert.h>
#include "Repository.h"
#include "Watchlist.h"
#include "Controller.h"

void Test::testMovie()
{
	Movie m{ "Vacanta Mare", "Comedy", 2008, 341, "Fara Trailer" };

	assert(m.getTitle() == "Vacanta Mare");
	assert(m.getGenre() == "Comedy");
	assert(m.getYearOfRelease() == 2008);
	assert(m.getLikes() == 341);
	assert(m.getTrailer() == "Fara Trailer");

	m.increaseLikes();

	assert(m.getLikes() == 342);

}

void Test::testRepository()
{
	Repository repo{};

	DynamicVector list = repo.displayByGenre("Racing");
	assert(list.getSize() == 0);

	Movie m{ "Vacanta Mare", "Comedy", 2008, 341, "Fara Trailer" };
	repo.addMovie(m);

	repo.updateMovie(0, "Fast and Furious", "Racing", 2005, 1210);
	DynamicVector movies = repo.getMovies();
	Movie* allMovies = movies.getAllElems();
	Movie m1 = allMovies[0];
	assert(m1.getTitle() == "Fast and Furious");
	assert(m1.getGenre() == "Racing");
	assert(m1.getYearOfRelease() == 2005);
	assert(m1.getLikes() == 1210);

	assert(repo.searchByTitle("Vrajeala") == false);

	list = repo.displayByGenre("Racing");
	assert(list.getSize() == 1);

	repo.addMovie(m);
	list = repo.displayByGenre("Horror");
	assert(list.getSize() == 2);

	Movie m11{ "Logan","Action",2017,500,"https://www.youtube.com/watch?v=Div0iP65aZo" };
	Movie m2{ "The Pick of Destiny","Comedy", 2010, 1000, "https://www.youtube.com/watch?v=TXxQFMG86HA" };
	Movie m3{ "IT","Comedy",2017,700,"https://www.youtube.com/watch?v=hAUTdjf9rko" };
	Movie m4{ "Fast and Furious","Racing", 2005, 404,"de ce" };
	Movie m5{ "Little Mermaid","Cartoon",2002,15,"nu vreau" };
	Movie m6{ "The avengers","Action",2015,5959,"navem" };
	Movie m7{ "Ice Age","Cartoon",2008,99,"nnicci aici" };
	Movie m8{ "Assassins Creed","Action",2014,666,"ce" };
	Movie m9{ "Prince of Persia","Fantasy",2012,442,"nana" };
	Movie m10{ "Lion King","Cartoon",1997,699,"ma" };

	repo.addMovie(m11);
	repo.addMovie(m2);
	repo.addMovie(m3);
	repo.addMovie(m4);
	repo.addMovie(m5);
	repo.addMovie(m6);
	repo.addMovie(m7);
	repo.addMovie(m8);
	repo.addMovie(m9);
	repo.addMovie(m10);

	repo.deleteMovie("Lion King");

	if (m10.getTrailer() != "")
		m10.play();



}

void Test::testWatchList()
{
	

	Watchlist watchList{};
	DynamicVector movies = watchList.getList();

	Movie m1{ "Vacanta Mare", "Comedy", 2008, 341, "Fara Trailer" };
	Movie m2{ "Fast and Furious","Racing",2005,1210,"Fara Trailer" };
	watchList.addMovieWatchList(m1);
	watchList.addMovieWatchList(m2);

	assert(watchList.isEmpty() == false);
}

void Test::testController()
{
	Repository repo{};
	Watchlist watchList{};
	Controller ctrl{ repo };

	ctrl.addMovieToRepository("Vacanta Mare", "Comedy", 2012, 341, "Fara trailer");
	ctrl.addMovieToWatchList("Fast and Furious", "Racing", 2010, 1210, "Fara trailer");
	assert(ctrl.getRepo().getMovies().getSize() == 1);
	assert(ctrl.getWatchList().getList().getSize() == 1);

	ctrl.deleteMovieFromRepository("Vacanta Mare");
	assert(ctrl.getRepo().getMovies().getSize() == 0);

	ctrl.addMovieToRepository("Vacanta Mare", "Comedy", 2012, 341, "Fara trailer");
	ctrl.updateMovieFromRepository(0, "Fast and Furious", "Racing", 2005, 1210);

	ctrl.deleteMovieFromWatchList("Fast and Furious");

	ctrl.likeMovieFromRepository("Fast and Furious");

	assert(ctrl.searchMovieByTitleInRepo("Fast and Furious") == true);

	DynamicVector list = ctrl.displaySongs("Comedy");
}

void Test::testAll()
{
	testMovie();
	testRepository();
	testWatchList();
	testController();
}
