#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class election
{
protected:
	string  election_id;
	string election_name;
	string strt_date;
	string end_date;
	bool activate_1;
public:
	election()
	{
		cout << endl << "Enter Election Detail:";
		cout << endl << "Enter Election Id;";
		getline(cin, election_id);
		cout << "\nEnter Election_title:";
		getline(cin, election_name);
		cout << "\nEnter Start Date (YYYY-DD-MM):";
		getline(cin, strt_date);
		cout << "Enter end date of election (YYYY-DD-MM):";
		getline(cin, end_date);

		activate_1 = true;
	}
	virtual ~election()
	{
		cout << "ALERT:  no memory leakage";
	}

	virtual void showrules() const
	{
		cout << endl << "ELECTION RULES BY ELECTION COMMISION";
		char n;
		cout << endl << "1.Each candidate assign by Admin vote only one:";
		cout << "\n voting period start from " << strt_date << "to" << end_date;
	}
	virtual void strtvoting()
	{
		cout << "Start voting for: " << election_name << endl;
	}
	virtual void calculatevotes()
	{
		cout << "Calculate vote for:" << election_name << endl;

	}
	virtual void savedata()
	{
		ofstream outfile("Election.txt", ios::app);
		if (outfile.is_open())
		{

			outfile << "Election" << election_id << endl << election_name << endl << strt_date << endl << end_date << endl << activate_1 << endl;
			outfile.close();
			cout << "Electiion data saved successfully";

		}
		else
			cout << "Election data cant saved";
	}

	static void forloaddata()
	{
		ifstream outfile("Election.txt");
		if (!outfile)
		{
			cout << "Error to open";
		}
		else
			return;
	}

	void display()
	{

		cout << "\n\n\n\n\n Online Voting System ::\n";
		cout << "1. General Election\n";
		cout << "2. Create Local Election\n";
		cout << "3. Create National Election\n";
		cout << "4. View All Elections\n";
		cout << "5. Exit\n";
		cout << "Enter your choice (1-5): ";
	}


	int main()
	{
		int choice;
		election* newelection = nullptr;


		do
		{
			display();
			cin >> choice;
			cin.ignore();
			cout << endl;

			if (choice == 1)
			{

				newelection = new election();
				newelection->savedata();
				delete newelection;
				break;
			}
			if (choice == 2)
			{
				cout << "local\n";
			}
			if (choice == 3)
			{
				cout << "national\n";
			}
			else if (choice == 4)

				//implement class contructor with defination of  for load data() function
			{
				election::forloaddata;
			}

			else
			{
				cout << "error";
			}
		} while (choice > 5);
		return 0;
	}

};