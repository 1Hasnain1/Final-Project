 #include<iostream>
#include<string>
#include<fstream>
using namespace std;
class election
{
protected:
    string election_name;
    string strt_date;
    string end_date;
    bool activate_1;

    int candidate_id;
    bool candidate_status;
public:
    void details_election() {
        cout << endl << "===============Enter Election Detail:=================\n";
        cout << "Enter Start Date (YYYY-MM-DD): ";
        getline(cin, strt_date);
        cout << "Enter End Date (YYYY-MM-DD): ";
        getline(cin, end_date);

        activate_1 = true;
    }
    string getStartDate() const {
        return strt_date;
    }
    string getEndDate() const {
        return end_date;
    }

    virtual ~election()
    {

    }

    virtual void showrules() const
    {
        cout << endl << "ELECTION RULES BY ELECTION COMMISSION";
        cout << endl << "1. Each candidate is assigned by Admin and can vote only once.";
        cout << "\nVoting period starts from " << strt_date << " to " << end_date << ".\n";
    }

    virtual void startelection()
    {
        if (!activate_1)
        {
            activate_1 = true;
            cout << "Election " << election_name << " has started " << endl;
        }
        else
        {
            cout << "Election is already going on..." << endl;
        }
    }

    void endElection()
    {
        if (activate_1)
        {
            activate_1 = false;
            cout << "Election" << election_name << "has ended successfully.\n" << endl;
        }
        else {
            cout << "Election is already inactive.\n";
        }
    }

    virtual void calculatevotes()
    {
        cout << "Calculating votes for: " << election_name << endl;
    }

    virtual void savedata()
    {
        ofstream outfile("ELECTIONS.txt", ios::app);
        if (!outfile.is_open())
        {
            cout << "couldn't open file\n";
        }
        else
        {
            outfile << "Election Name: " << election_name << "|" <<
                "Start Date: " << strt_date << "|"
                << "End Date: " << end_date << "|" << endl;
            outfile.close();

        }
    }

    static void forloaddata()
    {
        ifstream infile("ELECTIONS.txt");
        if (!infile)
        {
            cout << "Error: Cannot open file.\n";

        }

        string line;
        cout << "All Elections";
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close();
    }
};

class localelection : public election
{
    string district;



public:
    //we use over ride  here which use as virtual function as use in above class election()
    void showrules() const override
    {
        cout << "Local Election Rules";
        cout << " Voting dates: " << strt_date << " to " << end_date << endl;
    }
    void savedata() override
    {
        ofstream outFile("ELECTIONS.txt", ios::app); // we  Use same file name
        if (outFile.is_open())
        {
            outFile << "Local" << "|" << election_name << "|"
                << strt_date << "|" << end_date << "|" << "\n"
                ;
            outFile.close();

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
public:
    generalelection() : election()
    {

    }

    //we use over ride  here which use as virtual function as use in above class election()
    void showrules() const override
    {
        cout << "General/National Election Rules";
        cout << "Constituency: " << constituency << endl;
        cout << " Voting dates: " << strt_date << " to " << end_date << endl;
    }

    void startelection() override
    {
        cout << "\nStarting National/General election in " << constituency << endl;
    }

    void savedata() override
    {
        ofstream outFile("ELECTIONS.txt", ios::app); // we  Use same file name
        if (outFile.is_open())
        {
            outFile << "General" << "|" << election_name << "|"
                << strt_date << "|" << end_date << "|"
                << constituency << "|" << candidate_id << endl;
            outFile.close();

        }
        else
        {
            cerr << "Error saving local election data!\n";
        }
    }

};

class Candidate {
private:
    string name;
    string Party_affiliation;
    int num_of_votes_recieved;
    int Candidate_ID;
    string constituency;
    bool profile_status;

public:

    Candidate(string n = "", string party = "", int votes = 0, int id = 0, string consti = "", bool status = true)
    {
        name = n;
        Party_affiliation = party;
        num_of_votes_recieved = votes;
        Candidate_ID = id;
        constituency = consti;
        profile_status = status;

    }

    void inputCandidateData()
    {
        cout << "Enter Candidate Name: ";
        getline(cin, name);
        cout << "Enter Party Affiliation: ";
        getline(cin, Party_affiliation);
        cout << "Enter Candidate ID: ";
        cin >> Candidate_ID;
        cin.ignore();
        cout << "Enter Constituency( e.g NA-120 or PP-120 ..) : ";
        getline(cin, constituency);
        cout << "Enter Profile Status (e.g., 1 for Active or 2 Disqualified): ";
        cin >> profile_status;
        cin.ignore();
    }

    // Getter and Setter for name

    void setName(string n) {
        name = n;
    }
    string getName() {
        return name;
    }

    // Getter and Setter for Party_affiliation

    void setPartyAffiliation(string party)
    {
        Party_affiliation = party;
    }
    string getPartyAffiliation() {
        return Party_affiliation;
    }

    // Getter and Setter for num_of_votes_recieved

    void setNumOfVotesReceived(int votes)
    {
        num_of_votes_recieved = votes;
    }
    int getNumOfVotesReceived() {
        return num_of_votes_recieved;
    }


    void setCandidateID(int id)
    {
        Candidate_ID = id;
    }
    int getCandidateID()
    {
        return Candidate_ID;
    }


    void setConstituency(string c)
    {
        constituency = c;
    }
    string getConstituency()
    {
        return constituency;
    }

    void setProfileStatus(bool status)
    {
        profile_status = status;
    }
    bool getProfileStatus()
    {
        return profile_status;
    }



    void increment_votes()
    {
        num_of_votes_recieved++;
    }

    int get_Vote_Count()
    {
        return num_of_votes_recieved;
    }


    void get_candidate_info()
    {

        cout << "-------------------------------------------\n";
        cout << "           Candidate Information            \n";
        cout << "-------------------------------------------\n";
        cout << "Name:                 " << name << endl;
        cout << "Party Affiliation:    " << Party_affiliation << endl;
        cout << "Votes Received:       " << num_of_votes_recieved << endl;
        cout << "Candidate ID:         " << Candidate_ID << endl;
        cout << "Constituency:         " << constituency << endl;
        cout << "Profile Status:       " << (profile_status ? "Active" : "Inactive") << endl;
        cout << "-------------------------------------------\n";


    }


};

class User {
protected:
    string Username, Password;
public:
    virtual bool Login() = 0;
};

class Voter : public User {
protected:
    bool Has_Voted;
    string CNIC;
    int vote_count = 0;
public:
    bool Login() override {
        cout << "Enter the username: ";
        getline(cin, Username);
        cout << "Enter the password: ";
        getline(cin, Password);
        cout << "Enter the CNIC( Without DASHES ) : ";
        getline(cin, CNIC);
        cout << "the entered  cnic : " << CNIC << endl;
        fstream Voterfile("VOTERS INFORMATION.txt", ios::in);
        if (!Voterfile.is_open()) {
            cout << "couldn't open voters file\n";
            return false;
        }
        string line;
        string Searchkey = "CNIC:" + CNIC + " Username:" + Username + " Password:" + Password;
        while (getline(Voterfile, line)) {
            if (line == Searchkey) {
                cout << "Voter logged in successfully!\n";

                Has_Voted = false;

                return true;
            }

        }
        cout << "Invalid username or password\n";
        Voterfile.close();
        return false;




    }

    void View_Elections() {
        fstream Election_file("ELECTIONS.txt", ios::in);
        string line;
        if (!Election_file.is_open()) {
            cout << "No elections available !!!\n";
        }
        else {
            cout << "========Elections =========\n";
            while (getline(Election_file, line)) {
                cout << line << endl;
            }
            Election_file.close();
        }

    }

    void Cast_Vote() {
        string Candidate_Name;
        fstream read_voters_file;
        string line;
        read_voters_file.open("VOTES.txt", ios::in);
        if (!read_voters_file.is_open()) {
            cout << "couldn't open file\n";

        }

        bool alreadyVoted = false;
        while (getline(read_voters_file, line)) {
            if (line.find(CNIC) != string::npos) {
                cout << "THIS person with username : " << Username << " has already casted the vote \n";
                Has_Voted = true;
                alreadyVoted = true;
                break;
            }
        }
        read_voters_file.close();
        if (!alreadyVoted) {
            bool found = false;
            string City_name, Election_type;
            string Party_Name;
            cout << "Enter the City Name :\n";
            getline(cin, City_name);
            fstream Election_file("ELECTIONS.txt", ios::in);
            string line;
            if (!Election_file.is_open()) {
                cout << "couldn't open file !!!\n";
            }
            else {
                cout << "Avaialable elections in your City : " << City_name << endl;
                while (getline(Election_file, line)) {
                    if (line.find(City_name) != string::npos) {
                        found = true;
                        cout << line << endl;

                        // Read and print the next line (like "General|date|date")
                        if (getline(Election_file, line)) {
                            cout << line << endl;
                        }

                        // Now read all lines until the separator
                        while (getline(Election_file, line)) {
                            if (line.find("==============================") != string::npos) {
                                break;
                            }
                            cout << line << endl;
                        }
                    }
                    if (found) {
                        cout << "Enter the Election Type ( general or Local ) :\n";
                        getline(cin, Election_type);
                        cout << "Enter the Candidate name as it showing : \n";
                        getline(cin, Candidate_Name);
                        cout << "enter the party name :\n";
                        getline(cin, Party_Name);
                        Has_Voted = true;
                        found = true;
                        cout << "you have voted successfully to " << Candidate_Name << " of Party: " << Party_Name << " in " << Election_type << endl;
                        fstream voteFile("VOTES.txt", ios::app);
                        voteFile << CNIC << " has voted to " << Candidate_Name << " of party : " << Party_Name << endl;
                        
                        voteFile.close();
                        break;

                    }
                }
            }
            if (!found) {
                cout << "the election name or candidate name not matched!!!\n";
            }
            Election_file.close();

        }


    }
    int get_casted_vote_count() {
        return vote_count;
    }


    bool Check_Vote_Status() {
        fstream check_vote_file;
        string line;
        check_vote_file.open("VOTES.txt", ios::in);
        if (!check_vote_file.is_open()) {
            cout << "coudn't open file";
            return false;
        }
        else {
            while (getline(check_vote_file, line)) {
                if (line.find(CNIC) != string::npos) {
                    cout << "you have already casted the vote with cnic : " << CNIC << endl;
                    Has_Voted = true;
                }
                else {
                    cout << "you didn't cast the vote yet \n";
                    Has_Voted = false;
                }
            }

        }

    }
};


///CANDIDATE CLASS////////////////////////////////////////////////////////////






class Admin : public User {
protected:
    string Election_Type, Start_Date, End_Date;
    Candidate* c;
    int no_of_candidates;


public:

    Admin() {
        no_of_candidates = 0;
        c = nullptr;
    }

    ~Admin() {
        delete[] c;  // Free dynamically allocated memory
    }

    bool Login() override {
        cout << "Enter the username: ";
        getline(cin, Username);
        cout << "Enter the password: ";
        getline(cin, Password);
        fstream Adminfile("ADMIN INFORMATION.txt", ios::in);
        if (!Adminfile.is_open()) {
            cout << "Couldn't open admin file\n";
            return false;
        }
        string line;
        string Searchkey = "Username:" + Username + " Password:" + Password;
        while (getline(Adminfile, line)) {
            if (line == Searchkey) {
                cout << "Admin logged in successfully!\n";
                return true;
            }
        }
        cout << "Invalid admin credentials\n";
        return false;
    }

    void Create_Elections() {
        election* e = nullptr;
        string City;
        int type;

        cout << "Choose Election Type: 1 - Local, 2 - General: ";
        cin >> type;
        cin.ignore();

        if (type == 1) {
            localelection* l = new localelection();
            l->details_election();
            cout << "Enter city NAme :";
            getline(cin, City);
            cout << "Enter the total number of candidates: ";
            cin >> no_of_candidates;
            cin.ignore();
            c = new Candidate[no_of_candidates];

            for (int i = 0; i < no_of_candidates; i++) {
                cout << "\nEnter data for Candidate " << i + 1 << ":\n";
                c[i].inputCandidateData();

            }
            //l->savedata();
            fstream Local_outfile("ELECTIONS.txt", ios::app);
            if (Local_outfile.is_open()) {
                Local_outfile << City << " : \n" << "Local|" << l->getStartDate() << "|" << l->getEndDate() << endl;
                for (int i = 0; i < no_of_candidates; i++) {
                    Local_outfile << c[i].getName() << "|" << c[i].getPartyAffiliation() << "|" << c[i].getConstituency() << endl;
                }
                Local_outfile << "==============================\n";
                Local_outfile.close();
            }
            delete l;

        }
        else if (type == 2) {
            generalelection* g = new generalelection();  
            g->details_election();
            cout << "Enter the city name: ";
            getline(cin, City);

            cout << "Enter the total number of candidates: ";
            cin >> no_of_candidates;
            cin.ignore();

            c = new Candidate[no_of_candidates];

            for (int i = 0; i < no_of_candidates; i++) {
                cout << "\nEnter data for Candidate " << i + 1 << ":\n";
                c[i].inputCandidateData();
            }

            //g->savedata();
            fstream General_outfile("ELECTIONS.txt", ios::app);
            if (General_outfile.is_open()) {
                General_outfile << City << " : \n" << "General|" << g->getStartDate() << "|" << g->getEndDate() << endl;
                for (int i = 0; i < no_of_candidates; i++) {
                    General_outfile << c[i].getName() << "|" << c[i].getPartyAffiliation() << "|" << c[i].getConstituency() << endl;
                }
                General_outfile << "==============================\n";
                General_outfile.close();
            }
            delete g;
        }
        else {
            cout << "Invalid choice.\n";
            return;
        }
    }

    void view_results() {
        int ptiVotes = 0;
        int pmlnVotes = 0;
        int pppVotes = 0;
        int indVotes = 0;

        fstream voteFile("VOTES.txt", ios::in);
        if (!voteFile.is_open()) {
            cout << "No votes recorded yet.\n";
            return;
        }

        string party;
        string winner;
        while (getline(voteFile, party)) {
            if (party.find("has voted to")) {
                if (party.find("PTI") != string::npos || party.find("pti") != string::npos) {
                    ptiVotes++;
                }
                else if (party.find("PMLN") != string::npos || party.find("pmln") != string::npos) {
                    pmlnVotes++;
                }
                else if (party.find("PPP") != string::npos || party.find("ppp") != string::npos) {
                    pppVotes++;
                }
                else if (party.find("IND") != string::npos || party.find("ind") != string::npos) {
                    indVotes++;
                }
            }
        }

        voteFile.close();

        cout << "========== ELECTION RESULTS ==========\n";
        cout << "PTI:  " << ptiVotes << " votes\n";
        cout << "PMLN: " << pmlnVotes << " votes\n";
        cout << "PPP:  " << pppVotes << " votes\n";
        cout << "IND:  " << indVotes << " votes\n";

        if (ptiVotes > pmlnVotes && ptiVotes > pppVotes && ptiVotes > indVotes) {
            winner = "PTI";
            cout << "Winner Party: " << winner << " with " << ptiVotes << " votes\n";
        }
        else if (pmlnVotes > ptiVotes && pmlnVotes > pppVotes && pmlnVotes > indVotes) {
            winner = "PMLN";
            cout << "Winner Party: " << winner << " with " << pmlnVotes << " votes\n";
        }
        else if (pppVotes > ptiVotes && pppVotes > pmlnVotes && pppVotes > indVotes) {
            winner = "PPP";
            cout << "Winner Party: " << winner << " with " << pppVotes << " votes\n";
        }
        else if (indVotes > pppVotes && indVotes > ptiVotes && indVotes > pmlnVotes) {
            winner = "IND";
            cout << "Winner Party: " << winner << " with " << indVotes << " votes\n";
        }
        else if (indVotes == pppVotes && pppVotes == ptiVotes && ptiVotes == pmlnVotes) {
            cout << "Elections are drawn or no votes are casted yet \n";
        }
        else {
            cout << "Winner is not decided yet !!!\n";
        }
    }

  


    void viewAllCandidates() {
        if (no_of_candidates == 0) {
            cout << "No candidates available. Create an election first.\n";

        }
        for (int i = 0; i < no_of_candidates; i++) {
            c[i].get_candidate_info();
        }
    }

    void searchCandidateByName()
    {
        string searchName;
        cout << "Enter candidate name to search: ";
        getline(cin, searchName);

        ifstream file("ELECTIONS.txt");
        if (!file.is_open()) {
            cout << "Could not open ELECTIONS.txt\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(file, line)) {
            if (line.find(searchName) != string::npos) {
                cout << "\nCandidate Found: " << endl;
                cout << line << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Candidate not found.\n";
        }

        file.close();
    }

};
//static Admin* getAdmin() {
//    static Admin admin;
//    return &admin;
//}
int main() {
    cout << "==================== Welcome to ONLINE VOTING SYSTEM PAKISTAN =========================\n";
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\nSelect User Role:\n";
        cout << "1. Admin\n";
        cout << "2. Voter\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Admin admin;
            if (admin.Login()) {
                bool adminLoggedIn = true;
                while (adminLoggedIn) {
                    cout << "\nAdmin Menu:\n";
                    cout << "1. Create New Election\n";
                    cout << "2. View Results\n";
                    cout << "3. Search Candidate by Name\n";
                    cout << "4. View All Candidates\n";
                    cout << "5. Logout\n";
                    cout << "Enter your choice (1-5): ";
                    int adminChoice;
                    cin >> adminChoice;
                    cin.ignore();

                    switch (adminChoice) {
                    case 1:
                        admin.Create_Elections();
                        break;
                    case 2:
                        admin.view_results();
                        break;
                    case 3:
                        admin.searchCandidateByName();
                        break;
                    case 4:
                        admin.viewAllCandidates();
                        break;
                    case 5:
                        adminLoggedIn = false;
                        cout << "Admin logged out successfully.\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                        break;
                    }
                }
            }
            else {
                cout << "Admin login failed. Returning to main menu.\n";
            }
            break;
        }

        case 2: {
            Voter voter;
            if (voter.Login()) {
                bool voterLoggedIn = true;
                while (voterLoggedIn) {
                    cout << "\nVoter Menu:\n";
                    cout << "1. View Elections\n";
                    cout << "2. Cast Vote\n";
                    cout << "3. Check Vote Status\n";
                    cout << "4. Logout\n";
                    cout << "Enter your choice (1-4): ";
                    int voterChoice;
                    cin >> voterChoice;
                    cin.ignore();

                    switch (voterChoice) {
                    case 1:
                        voter.View_Elections();
                        break;
                    case 2:
                        voter.Cast_Vote();
                        break;
                    case 3:
                        voter.Check_Vote_Status();
                        break;
                    case 4:
                        voterLoggedIn = false;
                        cout << "Voter logged out successfully.\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                        break;
                    }
                }
            }
            else {
                cout << "Voter login failed. Returning to main menu.\n";
            }
            break;
        }

        case 3: // Exit honay k liye 
            exitProgram = true;
            cout << "Exiting the program. Thank you for using the Online Voting System!\n";
            break;

        default:
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
            break;
        }
    }
}