#include "UI.h"
#include "Movie.h"
#include <string>

using namespace std;

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		
		if (command == 0)
			break;

		if (command == 1) // ADMIN MENU
		{
			while (true)
			{
				UI::printAdministratorMenu();
				int commandAdmin{ 0 };
				cout << "Input the command: ";
				cin >> commandAdmin;
				cin.ignore();

				if (commandAdmin == 0)
					break;
				switch (commandAdmin)
				{
				case 1:
					this->addMovieToRepo();
					break;
				case 2:
					this->updateMovieFromRepo();
					break;
				case 3:
					this->deleteMovieFromRepo();
					break;
				case 4:
					this->displayAllMoviesRepo();
				}

			}
		}
	
		if (command == 2) // USER MENU
		{
			while (true)
			{
				UI::printUserMenu();
				int commandUser{ 0 };
				cout << "Input the commannd: ";
				cin >> commandUser;
				cin.ignore();

				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1:
					this->diplayByGenre();
					break;

				case 2:
					this->displayAllMoviesWatchList();
					break;

				case 3:
					this->deleteMovieWatchListUI();
					break;
				}
			}
		}
	}
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode." << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;

}

void UI::printAdministratorMenu()
{
	cout << "Possible commands: " << endl;
	cout << "1 - Add movie." << endl;
	cout << "2 - Update movie." << endl;
	cout << "3 - Delete movie." << endl;
	cout << "4 - Dysplay all." << endl;
	cout << "0 - Back." << endl;

}

void UI::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "1 - Display by genre." << endl;
	cout << "2 - Display watchlist." << endl;
	cout << "3 - Delete from watchlist." << endl;
	cout << "0 - Back." << endl;

}

void UI::printCommandMenu()
{
	cout << "1 - Add to watchlist." << endl;
	cout << "2 - Next." << endl;
	cout << "0 - Return." << endl;
}

void UI::addMovieToRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	if (this->ctrl.searchMovieByTitleInRepo(title) == true)
	{
		cout << "The movie is already in the repository." << endl;
		return;
	}
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year of release: ";
	double yearOfRelease;
	cin >> yearOfRelease;
	cin.ignore();
	cout << "Enter the likes: ";
	double likes;
	cin >> likes;
	cin.ignore();
	cout << "Enter the trailer link: ";
	std::string trailer;
	getline(cin, trailer);

	this->ctrl.addMovieToRepository(title, genre, yearOfRelease, likes, trailer);
	cout << "The movie has been succesfully added to the repository." << endl;
}

void UI::updateMovieFromRepo()
{
	cout << "Enter which movie you want to update: ";
	int position;
	cin >> position;
	cin.ignore();
	cout << "Enter the new title: ";
	std::string title;
	getline(cin, title);
	if (this->ctrl.searchMovieByTitleInRepo(title) == false)
	{
		cout << "The movie doesn't exist in the repository." << endl;
		return;
	}
	cout << "Enter the new genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the new year of release: ";
	double yearOfRelease;
	cin >> yearOfRelease;
	cin.ignore();
	cout << "Enter the new likes: ";
	double likes;
	cin >> likes;
	cin.ignore();

	this->ctrl.updateMovieFromRepository(position, title, genre, yearOfRelease, likes);
	cout << "The movie has been succesfully updated." << endl;

}

void UI::deleteMovieFromRepo()
{
	DynamicVector v = this->ctrl.getRepo().getMovies();
	Movie* movies = v.getAllElems();

	cout << "Enter the name of the movie you want to delete: ";
	std::string title;
	getline(cin, title);

	if (this->ctrl.searchMovieByTitleInRepo(title) == false)
	{
		cout << "That movie does not exist in the repository. You can't delete it. Cheers." << endl;
		return;
	}

	this->ctrl.deleteMovieFromRepository(title);
	cout << "The movie has been succesfully deleted." << endl;
}

void UI::displayAllMoviesRepo()
{
	DynamicVector v = this->ctrl.getRepo().getMovies();
	Movie* movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	cout << "Title" << " - " << "Genre" << " - " << "Year of release" << " - " << "Likes" << " - " << "Trailer" << endl;

	for (int i = 0; i < v.getSize(); i++)
	{
		Movie m = movies[i];
		
		cout << m.getTitle() << " - " << m.getGenre() << " - " << m.getYearOfRelease() << " - " << m.getLikes() << " - " << m.getTrailer() << endl;
	}
}

void UI::deleteMovieWatchListUI()
{
	
	DynamicVector v = this->ctrl.getWatchList().getList();
	Movie* movies = v.getAllElems();

	if (v.getSize() == 0)
	{
		cout << "There are no movies in the watchlist." << endl;
		return;
	}

	cout << "Enter the name of the movie you want to delete: ";
	std::string title;
	getline(cin, title);


	if (this->ctrl.searchMovieByTitleInRepo(title) == false)
	{
		cout << "That movie does not exist in the watchlist. You can't delete it. Cheers." << endl;
		return;
	}

	this->ctrl.deleteMovieFromWatchList(title);

	cout << "Have you liked the movie?" << endl;
	cout << "1 - Yes." << endl;
	cout << "0 - No." << endl;
	int answer;
	cin >> answer;
	cin.ignore();

	if (answer == 1)
		this->ctrl.likeMovieFromRepository(title);
	cout << "The movie has been succesfully deleted from the watchlist." << endl;
}

void UI::displayAllMoviesWatchList()
{
	DynamicVector v = this->ctrl.getWatchList().getList();
	Movie* movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no movies in the watchlist." << endl;
		return;
	}

	cout << "Title" << " - " << "Genre" << " - " << "Year of release" << " - " << "Likes" << " - " << "Trailer" << endl;

	for (int i = 0; i < v.getSize(); i++)
	{
		Movie m = movies[i];

		cout << m.getTitle() << " - " << m.getGenre() << " - " << m.getYearOfRelease() << " - " << m.getLikes() << " - " << m.getTrailer() << endl;
	}
}

void UI::diplayByGenre()
{
	
	std::string genre;
	cout << "Input by what genre you want to search: "; 
	getline(cin, genre);

	DynamicVector v = this->ctrl.displaySongs(genre);
	Movie* movies = v.getAllElems();

	

	if (movies == NULL)
	{
		cout << "There are no movies to be shown." << endl;
		return;
	}

	int i = 0;

	Movie m = movies[i];
	cout << m.getTitle() << " - " << m.getGenre() << " - " << m.getYearOfRelease() << " - " << m.getLikes() << " - " << m.getTrailer() << endl;
	m.play();

	while (i < v.getSize())
	{
		

		if (v.getSize() > 1)
		{
			
			cout << "Next command: " << endl;
			UI::printCommandMenu();
			int command{ 0 };
			cin >> command;
			cin.ignore();

			if (command == 0)
				break;

			switch (command)
			{

			case 1:
				if (this->ctrl.searchMovieByTitleInWatchList(m.getTitle()) == true)
					cout << "We're sorry, the movie already exists in the watchlist." << endl;
				else
				{
					this->ctrl.addMovieToWatchList(m.getTitle(), m.getGenre(), m.getYearOfRelease(), m.getLikes(), m.getTrailer());
					cout << "Movie has been succesfully saved to watchlist." << endl;
				}
				
				break;
			
			case 2:
				
				i++;

				if (i == v.getSize())
					i = 0;

				m = movies[i];
				cout << m.getTitle() << " - " << m.getGenre() << " - " << m.getYearOfRelease() << " - " << m.getLikes() << " - " << m.getTrailer() << endl;

				m.play();
				break;

			}
		}
	
	


		if (v.getSize() == 1)
		{
			int alternateCommand;
			

			cout << "There is only one movie after your preference. These are your options :" << endl;
			cout << "1 - Add to watchlist." << endl;
			cout << "0 - Return." << endl;

			cin >> alternateCommand;
			cin.ignore();
			switch (alternateCommand)
			{
			case 0:
				break;

			case 1:
				this->ctrl.addMovieToWatchList(m.getTitle(), m.getGenre(), m.getYearOfRelease(), m.getLikes(), m.getTrailer());
				cout << "Movie has been succesfully saved to watchlist." << endl;
				break;


			}

			if (alternateCommand == 0)
				break;
			break;
		}


		if (i == v.getSize())
			i = 0;
		
	}



	

}
