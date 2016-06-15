//Tyler Kowalczik, Kyle Graham 
#include "MovieStore.h"
//---------------------------------------------------------------------------
// MovieStore()
// creates the moviestore object
// Preconditions: moviestore object does not exist
// Postconditions: moviestore object created
// --------------------------------------------------------------------------
MovieStore::MovieStore()
{
	this->numCustomers = 0;
}
//---------------------------------------------------------------------------
// ~MovieStore()
// deletes the moviestore object
// Preconditions: moviestore object exist
// Postconditions: moviestore object deleted
// --------------------------------------------------------------------------
MovieStore::~MovieStore()
{
	
	delete this;
}
//---------------------------------------------------------------------------
// initRentals()
// reads in the movies from the text file and inserts them into the 
// corresponding skip list based on genre
// Preconditions: NONE
// Postconditions: full skip list of customers
// --------------------------------------------------------------------------
void MovieStore::initRentals(ifstream& input)
{
	string title, director;
	char commaEater, type;
	int stock;
	string badInput;

	for(;;)
	{
		//comma eater is used to take the commas out of char input areas
		input >> type >> commaEater >> stock >> commaEater;
		getline(input, director, ',');
		getline(input, title, ',');
		if (input.eof())
			break;
		if(type == 'C')
		{
			string majorFirst;
			string majorLast;
			int releaseMonth;
			int releaseYear;

			input >> majorFirst >> majorLast >> releaseMonth >> releaseYear;
			//movie created as corresponding genre and added to list
			Movie *r = new ClassicMovie(stock, title, director, majorFirst,
				majorLast, releaseMonth, releaseYear);
			ClassicList.insert(r);
			//put r into hashtable
			
		}
		else if (type == 'F') 
		{
			int releaseYear;
			input >> releaseYear;
			//movie created as corresponding genre and added to list
			Movie *r = new ComedyMovie(stock, title, director, releaseYear);
			ComedyList.insert(r);
			//put r into hashtable
		}
		else if (type == 'D')
		{
			int releaseYear;
			input >> releaseYear;
			//movie created as corresponding genre and added to list
			Movie *m = new DramaMovie(stock, title, director, releaseYear);
			DramaList.insert(m);
			//put r into hashtable
		}
		//not correct genre type, input is ignored and user notified
		else
		{
			getline(input, badInput, '\n'); 
			
			cout << "Bad movie Input" << endl  << type << ", "  << stock << ", " << title 
				<< ",  " << director << ", " << badInput << endl;
		}
		//variables reset
		type = ' ';
		stock = 0;
		director = "";
		title = "";
		badInput = "";
	}
}
//---------------------------------------------------------------------------
// initCustomers()
// reads in the customers from the text file and inserts them into the 
// hash table
// Preconditions: NONE
// Postconditions: full hash table of customers
// --------------------------------------------------------------------------
void MovieStore::initCustomers(ifstream& input)
{
	string firstName, lastName;
	int customerID;

	int i = 0;
	for (;;)
	{
		input >> customerID >> firstName >> lastName;
		//ignores any other input
		input.ignore(144, '\n');
		Customer *c = new Customer(customerID, firstName, lastName);
		
		this->numCustomers++;
		//customer object added to hashtable
		customers.insert(c);

		if (input.eof())
			break;
		i++;
	}
}

//---------------------------------------------------------------------------
// initCommands()
// reads in the commands from the text file and executes them
// Preconditions: customer hash table and movie slists full
// Postconditions: NONE
// --------------------------------------------------------------------------

void MovieStore::initCommands(ifstream & input)
{
	bool badInput = false;
	char action, media, movieType;
	string title, director, majorFirst, majorLast;
	//used to keep hold all the info of the transaction
	stringstream history;
	int customerID, releaseYear, releaseMonth;
	//loops until end of file is found
	for (;;)
	{
		input >> action;
		switch (action)
		{
			//case for borrowing movies
		case 'B':
		{
			history << action;
			input >> customerID >> media >> movieType;
			history << WHITE_SPACE << customerID << WHITE_SPACE << media 
				<< WHITE_SPACE << movieType << WHITE_SPACE;
			//check if customer ID is valid
			Customer *f = NULL;
			if (!customers.searchCustomer(customerID, f))
			{ 
				badInput = true;
				cout << "Customer ID not valid" << endl;
				input.ignore(144, '\n');
				break;
			}
			
			if(!badInput)
			{
				switch (movieType)
				{
					case 'C':
					{
						input >> releaseMonth >> releaseYear >> majorFirst >> majorLast;
						history << releaseMonth << WHITE_SPACE << releaseYear << WHITE_SPACE 
							<< majorFirst << WHITE_SPACE << majorLast << WHITE_SPACE ;
						ClassicMovie *tmpClassic = NULL;
						if (ClassicList.searchClassic(media, releaseMonth, 
							releaseYear, majorFirst, majorLast, tmpClassic))
						{
							//borrow movie
							tmpClassic->borrow(media);
							//add transaction to customer history
							f->addHistory(history.str());
						}
						else
						{
							cout << "Movie not found: " << media << WHITE_SPACE << movieType << WHITE_SPACE << releaseMonth
						<< WHITE_SPACE << releaseYear << WHITE_SPACE << majorFirst 
						<< WHITE_SPACE << majorLast << endl;
							//clears history stringstream
							history.str("");
							break;
						}
					}
						break;
					case 'F':
					{
						getline(input, title, ',');
						input >> releaseYear;
						history << title << WHITE_SPACE << releaseYear << WHITE_SPACE;
						ComedyMovie *tmpComdey = NULL;
						if (ComedyList.searchComedy(media, title, releaseYear, tmpComdey))
						{
							//borrow movie
							tmpComdey->borrow(media);
							//add transaction to customer history
							f->addHistory(history.str());
						}
						else
						{
							cout << "Movie not found: " << media << WHITE_SPACE << title
						<< WHITE_SPACE << releaseYear << WHITE_SPACE << endl;
							history.str("");
							break;
						}
					}
						break;
					case 'D':
					{
						getline(input, director, ',');
						getline(input, title, ',');
						history << director << WHITE_SPACE << title << WHITE_SPACE;
						DramaMovie *tmpDrama = NULL;
						if (DramaList.searchDrama(media, director, title, tmpDrama))
						{
							//borrow movie
							tmpDrama->borrow(media);
							//add transaction to history
							f->addHistory(history.str());
						}
						else
						{
							cout << "Movie not found: " << media << WHITE_SPACE << director
						<< WHITE_SPACE << title << WHITE_SPACE << endl;
							history.str("");
							break;
						}
					}
						break;
					default:
						cout << "Invalid category of movie for borrow." << endl;
						string badInput;
						getline(input, badInput, '\n');
						cout << action << WHITE_SPACE << customerID << WHITE_SPACE << media 
						<< WHITE_SPACE << movieType << WHITE_SPACE << badInput << endl;
						break;
				}
			}
		}
		break;
		//case for return of rental objects
		case 'R':
		{
			history << action;
			input >> customerID >> media >> movieType;
			//check if customer ID is valid
			history << WHITE_SPACE << customerID << WHITE_SPACE << media 
				<< WHITE_SPACE << movieType << WHITE_SPACE;
			Customer *f = NULL;
			if (!customers.searchCustomer(customerID, f))
			{
				badInput = true;
				cout << "Customer ID not valid" << endl;
				input.ignore(144, '\n');
				break;
			}
			switch (movieType)
			{
			case 'C':
			{
				input >> releaseMonth >> releaseYear >> majorFirst >> majorLast;
				history << releaseMonth << WHITE_SPACE << releaseYear << WHITE_SPACE 
					<< majorFirst << WHITE_SPACE << majorLast << WHITE_SPACE;
				ClassicMovie *tmpClassic = NULL;
				if (ClassicList.searchClassic(media, releaseMonth, releaseYear, 
					majorFirst, majorLast, tmpClassic))
				{
					//borrow movie
					tmpClassic->returnRental(media);
					//add transaction to customer history
					f->addHistory(history.str());
				}
				else
				{
					cout << "Movie not found: " << media << WHITE_SPACE << movieType << 
						WHITE_SPACE << releaseMonth << WHITE_SPACE << releaseYear << 
						WHITE_SPACE << majorFirst << endl;
					history.str("");
				}
			}
			break;
			case 'F':
			{
				getline(input, title, ',');
				input >> releaseYear;
				history << title << WHITE_SPACE << releaseYear << WHITE_SPACE;
				ComedyMovie *tmpComedey = NULL;
				if (ComedyList.searchComedy(media, title, releaseYear, tmpComedey))
				{
					//borrow movie
					tmpComedey->borrow(media);
					//add transaction to customer history
					f->addHistory(history.str());
				}
				else
				{
					cout << "Movie not found: " << media << WHITE_SPACE << title
						<< WHITE_SPACE << releaseYear << WHITE_SPACE << endl;
					history.str("");
				}
			}
			break;
			case 'D':
			{
				getline(input, director, ',');
				getline(input, title, ',');
				history << director << WHITE_SPACE << title << WHITE_SPACE;
				DramaMovie *tmpDrama = NULL;
				if (DramaList.searchDrama(media, director, title, tmpDrama))
				{
					//borrow movie
					tmpDrama->borrow(media);
					//add transaction to history
					f->addHistory(history.str());
				}
				else
				{
					cout << "Movie not found: " << media << WHITE_SPACE << director
						<< WHITE_SPACE << title << WHITE_SPACE << endl;
					history.str("");
				}
			}
			break;
			default:
				cout << "Invalid category of movie for return." << endl;
				string badInput;
				getline(input, badInput, '\n');
				cout << action << WHITE_SPACE << customerID << WHITE_SPACE << media 
					<< WHITE_SPACE << movieType << WHITE_SPACE << badInput << endl;
				break;

			}
			break;
		}
		//case for printing out inventory
		case 'I':
			//prints out the lists in order of comedy, drama, then classics
			ComedyList.print('F');
			DramaList.print('D');
			ClassicList.print('C');
			break;
		//case for printing out customer inventory
		case 'H':
		{
			input >> customerID;
			Customer *f = NULL;
			//customer exists, print out history
			if(customers.searchCustomer(customerID, f))
				f->printHistory();
			//customer does not exist
			else
			{
				input.ignore(144, '\n');
				delete f;
			}
			break;
		}
		//command not correct, ignores the line and alerts user
		default:
			cout << "bad command" << endl;
			input.ignore(144, '\n');
			break;
	}
		//ends infinite loop at end of file
		if (input.eof())
		{
			break;
		}
	//reset variables for next round
	history.str("");
	media = ' ';
	movieType = ' ';
	badInput = false;
	title = "";
	director = "";
	majorFirst = "";
	majorLast = "";
	customerID = 0;
	releaseYear = 0;
	releaseMonth = 0;
	
	action = ' ';
	}
}


