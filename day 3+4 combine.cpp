#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class election
{
protected:
    string election_id;
    string election_name;
    string strt_date;
    string end_date;
    bool activate_1;

    int candidate_id;
    bool candidate_status;
public:
    election()
    {
        cout << endl << "Enter Election Detail:";
        cout << endl << "Enter Election Id: ";
        getline(cin, election_id);
        cout << "Enter Election Title: ";
        getline(cin, election_name);
        cout << "Enter Start Date (YYYY-MM-DD): ";
        getline(cin, strt_date);
        cout << "Enter End Date (YYYY-MM-DD): ";
        getline(cin, end_date);

        activate_1 = true;
    }

    virtual ~election()
    {
        cout << "\nSuccessfully : No memory leakage\n";
    }

    virtual void showrules() const
    {
        cout << endl << "ELECTION RULES BY ELECTION COMMISSION";
        cout << endl << "1. Each candidate is assigned by Admin and can vote only once.";
        cout << "\nVoting period starts from " << strt_date << " to " << end_date << ".\n";
    }

    virtual void strtvoting()
    {
        cout << "Start voting for: " << election_name << endl;
    }

    virtual void calculatevotes()
    {
        cout << "Calculating votes for: " << election_name << endl;
    }

    virtual void savedata()
    {
        ofstream outfile("Election.txt", ios::app);
        if (outfile.is_open())
        {
            outfile << "Election ID: " << election_id << endl
                << "Election Name: " << election_name << endl
                << "Start Date: " << strt_date << endl
                << "End Date: " << end_date << endl
                << "Active: " << activate_1 << endl << endl;
            outfile.close();
            cout << "Election data saved successfully.\n";
        }
        else
        {
            cout << "Election data can't be saved.\n";
        }
    }

    static void forloaddata()
    {
        ifstream infile("Election.txt");
        if (!infile)
        {
            cout << "Error: Cannot open file.\n";
            return;
        }

        string line;
        cout << "All Elections";
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close();
    }
    
    static void display()
    {
        cout << "\t\t\t\tOnline Voting System ::\n";
        cout << "\t\t\t\t1. Create Local Election\n";
        cout << "\t\t\t\t2. Create General /National Election\n";
        cout << "\t\t\t\t3. View All Elections\n";
        cout << "\t\t\t\t4. Exit\n";
        cout << "\t\t\t\tEnter your choice (1-5): ";
    }
};
// 2nd day now built local election function
class localelection : public election
{
    string district;
    int maxvotes;


public:
    localelection() : election()
    {
        cout << "Enter District: ";
        getline(cin, district);

        cout << "Enter Maximum Votes Allowed: ";
        cin >> maxvotes;
        cin.ignore();
    }

    //we use over ride  here which use as virtual function as use in above class election()
    void showrules() const override 
    {
        cout << "Local Election Rules";
        cout << "District: " << district << endl;
        cout << "1. Vote for up to " << maxvotes << " candidates\n";
        cout << "2. Voting dates: " << strt_date << " to " << end_date << endl;
    }

    void strtvoting() override 
    {
        cout << "\nStarting LOCAL election in " << district << endl;
        cout << "Voters can choose " << maxvotes << " candidates\n";
    }

    void savedata() override
    {
        ofstream outFile("Election.txt", ios::app); // we  Use same file name
        if (outFile.is_open())
        {
            outFile << "Local," << election_id << "\n" << election_name << "\n"
                << strt_date << "\n" << end_date << "\n" << activate_1 << "\n"
                << district << "\n" << maxvotes << "\n";
            outFile.close();
            cout << "Local election data save successfully.\n";
        }
        else
        {
            cerr << "Error saving local election data!\n";
        }
    }

  };

//3rd day modrik + mine code

class generalelection : public election
{
    string constituency;
    int maxvotes;
    string district2;


public:
    generalelection() : election()
    {
        cout << "Enter Constituency (e.g., NA-120): ";
        getline(cin, constituency);

        cout << "Enter Maximum Votes Allowed: ";
        cin >> maxvotes;
        cin.ignore();

        cout << "Enter District: ";
        getline(cin, district2);
    }

    //we use over ride  here which use as virtual function as use in above class election()
    void showrules() const override
    {
        cout << "General/National Election Rules";
        cout << "Constituency: " << constituency << endl;
        cout << "1. Vote for up to " << maxvotes << " candidates\n";
        cout << "2. Voting dates: " << strt_date << " to " << end_date << endl;
    }

    void strtvoting() override
    {
        cout << "\nStarting National/General election in " << constituency << endl;
        cout << "Voters can choose " << maxvotes << " candidates\n";
    }

    void savedata() override
    {
        ofstream outFile("Election.txt", ios::app); // we  Use same file name
        if (outFile.is_open())
        {
            outFile << "General," << election_id << "\n" << election_name << "\n"
                << strt_date << "\n" << end_date << "\n" << activate_1 << "\n"
                << constituency << "\n" << maxvotes << "\n" << candidate_id << endl;
            outFile.close();
            cout << "National election data save successfully.\n";
        }
        else
        {
            cerr << "Error saving local election data!\n";
        }
    }

};

int main()
{
    int choice;
    election* newelection = nullptr;
    string name;
    string id;
    cout << "Enter name and id assign by admin umaid:";
	getline(cin, name);
	cout << "Enter id assign by admin umaid:";
	getline(cin, id);
	if (name == "umaid" && id == "1234")
    { 
        do
    {
        election::display();
        cin >> choice;
        cin.ignore(); // to clear newline from input buffer
        cout << endl;

        //2nd day implementation
         if (choice == 1)
        {
            cout << "Local Election creation feature.\n";
            newelection = new localelection();
            newelection->showrules();
            newelection->strtvoting();
            newelection->savedata();
            delete newelection;
        }
        else if (choice == 2)
        {
        
            cout << "Gerneal /National Election creation feature.\n";
            newelection = new generalelection();
            newelection->showrules();
            newelection->strtvoting();
            newelection->savedata();
            delete newelection;
        }
        //implement class contructor with defination of  for load data() function
        else if (choice == 3)
        {
            election::forloaddata();
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
	}
	else
	{
		cout << "Invalid name or id. Exiting...\n";
	}

    return 0;
}
