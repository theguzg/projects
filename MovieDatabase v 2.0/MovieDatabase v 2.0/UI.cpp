#include "UI.h"
#include "stdafx.h"
#include <string>
#include "RepositoryException.h"

using namespace std;

int readInteger()
{
	int x = 0;
	while (!(cin >> x))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\t[x] Invalid input. Try again! ";
	}

	return x;
}

void UI::printMenu()
{
	cout << "-----------------------------------\n";
	cout << "\t1.Administrator\n";
	cout << "\t2.User\n";
	cout << "-----------------------------------\n";
}

void UI::printAdminMenu()
{

	cout << '\n';
	cout << "-----------------------------------\n";
	cout << "\t1.Add Movie\n";
	cout << "\t2.Remove Movie\n";
	cout << "\t3.Update Movie by name\n";
	cout << "\t4.Print all Movies\n";
	cout << "\t0.Quit Admin Mode\n";
	cout << "-----------------------------------\n";

}

void UI::printUserMenu()
{
	cout << '\n';
	cout << "-----------------------------------\n";
	cout << "\t1.See movies one by one\n";
	cout << "\t2.See all  of a breed younger than a given age\n";
	cout << "\t3.See the watchlist\n";
	cout << "\t4.Save the watchlist\n";
	cout << "\t5.See the watchlist file\n";
	cout << "\t0.Exit User Mode\n";
	cout << "-----------------------------------\n";
}

void UI::save_watchlist_to_file()
{
	std::string filename;
	cin.ignore(1000, '\n');

	cout << "Filename: ";
	getline(cin, filename);

	try
	{
		ctrl.save_WatchList(filename);
		if (ctrl.getWatchList() == nullptr)
		{
			cout << "Watchlist can't be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::administrator()
{
	int option;

	while (1)
	{
		printAdminMenu();
		option = readInteger();
		switch (option)
		{
		case 1:
			ui_add();
			break;
		case 2:
			ui_remove();
			break;
		case 3:
			ui_update();
			break;
		case 4:
			printAll();
			break;
		case 0:
			break;
		default:
			cout << "[x] Invalid command! ";
			break;
		}
		if (option == 0)
			break;
	}
}

void UI::user()
{
	int option;

	while (1)
	{
		printUserMenu();
		option = readInteger();
		switch (option)
		{
		case 1:
			printOneByOne();
			break;
		case 2:
			printByGenre();
			break;
		case 3:
			printAllWatchList();
			break;
		case 4:
			save_watchlist_to_file();
			break;
		case 5:
			ctrl.open_WatchList();
			break;
		case 0:
			break;
		default:
			cout << "Invalid command! ";
			break;
		}
	}
}

void UI::ui_add()
{
	std::string title, genre, trailer;
	double yearOfRelease, likes;
	cin.ignore(1000, '\n');

	cout << "[+] Please give a title-> ";
	getline(cin, title);
	cout << "[+] Please give the movie genre-> ";
	getline(cin, genre);
	cout << "[+] When did " << title << " appear?->";
	yearOfRelease = readInteger();
	cin.ignore(1000, '\n');
	cout << "[+] How many likes does " << title << " have?->";
	likes = readInteger();
	cin.ignore(1000, '\n');
	cout << "[+] Please give a link to the trailer of " << title << "->";
	getline(cin, trailer);

	try
	{
		ctrl.addMovieToRepo(title,genre,yearOfRelease,likes,trailer);
		cout << "[+] Movie added!";
	}
	catch (MovieException& e)
	{
		for (auto m : e.getErrors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << '\n';
	}
	catch (FileException& e)
	{
		cout << e.what() << '\n';
	}
}

void UI::printAll()
{
	if (ctrl.getRepo().getMovies().size() == 0)
	{
		cout << "\t[x] There are no movies yet!";
		return;
	}

	for (auto m : this->ctrl.getRepo().getMovies())
	{
		cout << m << '\n';
	}
}

void UI::printAllWatchList()
{
	if (ctrl.getWatchList()->isEmpty() == true)
	{
		cout << "There are no movies in the watchlist yet!";
		return;
	}
	for (auto d : this->ctrl.getWatchList()->getMovies())
	{
		cout << d << '\n';
	}
}

void UI::ui_remove()
{
	std::string title;
	cin.ignore(1000, '\n');
	cout << "[+] Give the title of the movie-> ";
	getline(cin, title);
	try
	{
		ctrl.removeMovieFromRepo(title);
		cout << "[-] Movie removed!";
	}
	catch (MovieException& e)
	{
		for (auto m : e.getErrors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << '\n';
	}
	catch (FileException& e)
	{
		cout << e.what() << '\n';
	}
}

void UI::ui_update()
{
	std::string title, genre, trailer, title1;
	double yearOfRelease, likes;
	cin.ignore(1000, '\n');

	cout << "[+] Please give a title for the movie you want updated-> ";
	getline(cin, title1);
	cout << "[+] Please give a title for the new movie-> ";
	getline(cin, title);
	cout << "[+] Please give the movie a new genre-> ";
	getline(cin, genre);
	cout << "[+] When did " << title << " appear?->";
	yearOfRelease = readInteger();
	cin.ignore(1000, '\n');
	cout << "[+] How many likes does " << title << " have?->";
	likes = readInteger();
	cin.ignore(1000, '\n');
	cout << "[+] Please give a link to the trailer of " << title << "->";
	getline(cin, trailer);

	try
	{
		ctrl.updateMovie(title1, title, genre, yearOfRelease, likes, trailer);
		cout << "[+] Movie updated!";
	}
	catch (MovieException& e)
	{
		for (auto m : e.getErrors())
			cout << m;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << '\n';
	}
	catch (FileException& e)
	{
		cout << e.what() << '\n';
	}
}

void UI::printOneByOne()
{
	if (ctrl.getRepo().getMovies().size() == 0)
	{
		cout << "[x] There are no movies yet!";
		return;
	}
	int answer = 1;
	while (answer != 0)
		for (auto m : this->ctrl.getRepo().getMovies())
			if (answer != 0)
			{
				if (ctrl.getRepo().getMovies().size() != 0)
				{
					cout << m << '\n';
					m.trailerLink();

					cout << "[?] Do you want to add this movie to the watchlist? 1.Yes 2.No 0.Exit\n";
				}
				else
					cout << "[x] We are sorry, we don't have any more movies.";
				cin >> answer;
				if (answer == 1)
				{
					ctrl.addMovieToWatchList(m);
					ctrl.removeMovieFromRepo(m.getTitle());

				}
			}
}

void UI::printByGenre()
{
	string genre;
	cin.ignore(1000, '\n');
	cout << "[+] Give the genre-> ";
	cin >> genre;
	cin.ignore(1000, '\n');
	int s = 0;
	

	if (ctrl.getRepo().getMovies().size() == 0)
	{
		cout << "[x] There are no movies yet!";
		return;
	}
	int answer = 1;
	while (answer != 0)
		for (auto m : this->ctrl.getRepo().getMovies())
		{
			if (ctrl.getRepo().getMovies().size() != 0 /*&& ctrl.checkBreedAge(d, breed, age) == true*/)
			{
				s++;
				cout << m << '\n';
				m.trailerLink();

				cout << "Do you want to add the movie to the watchlist? 1.Yes 2.No 0.Exit\n";
				cin >> answer;
				if (answer == 1)
				{
					ctrl.addMovieToWatchList(m);
					ctrl.removeMovieFromRepo(m.getTitle());


				}
				else
					if (ctrl.getRepo().getMovies().size() == 0)
						cout << "We are sorry, we don't have any more dogs to adopt.";
			}
		}
	if (s == 0)
	{
		cout << "There are no movies of with this genre : " << genre << endl;
		return;
	}
}

void UI::run()
{
	int option;
	while (1)
	{
		printMenu();
		option = readInteger();
		if (option == 1)
			administrator();
		if (option == 2)
			user();
		if (option == 0)
			return;
		else
		{
			cout << "Invalid option!\n";
		}


	}
}
