#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <utility>
#include <bits/stdc++.h>
#include <iomanip>
#include <string>
#include <unistd.h>
using namespace std;

// Function to display the main menu
void displayMenu()
{
    cout << "==============================\n";
    cout << "         Metro System\n";
    cout << "==============================\n";
    cout << "1. Sign Up\n";
    cout << "2. Sign In\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

// Function to sign up a new user

bool isPasswordStrong(const string &password)
{
    if (password.length() < 8)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char c : password)
    {
        if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (isdigit(c))
            hasDigit = true;
        else if (ispunct(c))
            hasSpecial = true; // Check for special characters
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

void signUp(unordered_map<string, string> &users)
{
    system("cls");
    string username, password;

    cout << "\n--- Sign Up ---\n";
    cout << "Enter a username: ";
    cin >> username;

    // Check if username already exists
    if (users.find(username) != users.end())
    {
        cout << "Username already exists! Please try again.\n\n";
        return;
    }

    while (true)
    {
        cout << "Enter a password: ";
        cin >> password;

        // Check password strength
        if (!isPasswordStrong(password))
        {
            cout << "Weak password! Ensure your password:\n"
                 << "- Has at least 8 characters\n"
                 << "- Includes at least one uppercase letter\n"
                 << "- Includes at least one lowercase letter\n"
                 << "- Includes at least one digit\n"
                 << "- Includes at least one special character (e.g., !@#$%^&*)\n\n";
        }
        else
        {
            break; // Password is strong
        }
    }

    // Store username and password in the map
    users[username] = password;
    cout << "Sign-up successful! You can now sign in.\n\n";
}

// Function to sign in an existing user
void signIn(const unordered_map<string, string> &users)
{
    system("cls");
    string username, password;
retryuser:
    cout << "\n--- Sign In ---\n";
    cout << "Enter your username: ";
    cin >> username;

    // Check if username exists
    if (users.find(username) == users.end())
    {
        cout << "Invalid username! Please sign up first.\n\n";
        sleep(1);
        system("cls");
        goto retryuser;
        return;
    }
retryPassword:
    cout << "Enter your password: ";
    getline(cin >> ws, password);

    // Verify password
    if (users.at(username) == password)
    {
        cout << "Sign-in successful! Welcome, " << username << "!\n\n";
    }
    else
    {
        cout << "Incorrect password! Please try again.\n";

        goto retryPassword;
    }
    system("cls");
}

// ANSI Escape Codes for Colors
const string RESET = "\033[0m";
const string BLUE = "\033[1;34m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string RED = "\033[1;31m";
const string CYAN = "\033[1;36m";

// Clear screen function
void clearScreen()
{
    cout << "\033[2J\033[1;1H"; // Clears the screen and moves the cursor to the top-left
}

// Function to display the welcome message
void displayWelcomeMessage()
{
    cout << CYAN;
    cout << "==========================================================" << endl;
    cout << "               WELCOME TO THE WORLD OF METRO SYSTEM       " << endl;
    cout << "==========================================================" << RESET << endl;
}

// Function to display a styled header
void displayHeader()
{
    cout << BLUE;
    cout << "==========================================================" << endl;
    cout << YELLOW << setw(40) << "METRO SYSTEM PROJECT" << endl;
    cout << BLUE;
    cout << "==========================================================" << RESET << endl;
}

// Function to display contributors with colorful output
void displayContributors()
{
    cout << GREEN << "\nContributors:" << RESET << endl;
    cout << CYAN;
    cout << "----------------------------------------------------------" << endl;
    cout << setw(25) << left << "Name" << setw(25) << left << "Role" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << RESET;
    cout << setw(25) << left << "Ishit Dev Sinha" << setw(25) << left << "Team Lead" << endl;
    cout << setw(25) << left << "Arnav Kaushik" << setw(25) << left << "Route Planner" << endl;
    cout << setw(25) << left << "Piyush Panda" << setw(25) << left << "Ticket Manager" << endl;
    cout << setw(25) << left << "Shreya Varshney" << setw(25) << left << "Database Manager" << endl;
    cout << CYAN << "----------------------------------------------------------" << RESET << endl;
}
void displayForm()
{
    cout << YELLOW << "\nPassenger Feedback Form" << RESET << endl;
    cout << GREEN << "Please fill in the details below:\n"
         << RESET;
    cout << CYAN << "----------------------------------------------------------" << RESET << endl;

    string name, email, feedback;
    cout << BLUE << "Enter your Name: " << RESET;
    getline(cin >> ws, name);
    cout << BLUE << "Enter your Email: " << RESET;
    getline(cin >> ws, email);
    cout << BLUE << "Provide your Feedback: " << RESET;
    getline(cin >> ws, feedback);

    cout << GREEN << "\nThank you for your response, " << name << "!" << RESET << endl;
}


class Graph_M
{
public:
    class Vertex
    {
    public:
        map<string, int> nbrs;
        Vertex()
        {
            this->nbrs.clear();
        }
    };
    map<string, Vertex> vtces;

    Graph_M()
    {
        this->vtces.clear();
    }
    int numVertex()
    {
        return vtces.size();
    }
    bool containsVertex(string vname)
    {
        if (vtces.find(vname) != vtces.end())
            return true;
        else
            return false; 
    }
    void addVertex(string vname)
    {
        Vertex vtx; 
        vtces[vname] = vtx;
    }
    void removeVertex(string vname)
    {
        Vertex &vtx = vtces[vname];
        vector<string> keys;
        for (auto it = vtx.nbrs.begin(); it != vtx.nbrs.end(); it++)
        {
            keys.push_back(it->first);
        }
        for (auto key : keys)
        {
            Vertex &nbrVtx = vtces[key];
            nbrVtx.nbrs.erase(vname);
        }
        vtces.erase(vname);
    }
    int numEdges() // whole map
    {
        vector<string> keys;
        for (auto it = vtces.begin(); it != vtces.end(); it++)
        {
            keys.push_back(it->first);
        }

        int count = 0;

        // for (auto key : keys)//traversing the vector
        for (auto key : keys)
        {
            auto it = vtces.find(key);
            Vertex vtx = it->second;
            count = count + vtx.nbrs.size();
        }

        return count / 2;  //becoz double counting occurs
    }
    bool containsEdge(string vname1, string vname2)
    {
        Vertex vtx1 = vtces[vname1];
        Vertex vtx2 = vtces[vname2];

        if (vtces.find(vname1) == vtces.end() || vtces.find(vname2) == vtces.end() || vtx1.nbrs.find(vname2) == vtx1.nbrs.end())
        {
            return false;
        }

        return true;
    }
    void addEdge(string vname1, string vname2, int value)
    {
        Vertex &vtx1 = vtces[vname1];
        Vertex &vtx2 = vtces[vname2];

        if (vtces.find(vname1) == vtces.end() || vtces.find(vname2) == vtces.end() || vtx1.nbrs.find(vname2) != vtx1.nbrs.end())
        {
            return;
        }

        vtx1.nbrs[vname2] = value;
        vtx2.nbrs[vname1] = value;
    }

    void removeEdge(string vname1, string vname2)
    {
        Vertex &vtx1 = vtces[vname1];
        Vertex &vtx2 = vtces[vname2];

        // check if the vertices given or the edge between these vertices exist or not
        if (vtces.find(vname1) == vtces.end() || vtces.find(vname2) == vtces.end() || vtx1.nbrs.find(vname2) == vtx1.nbrs.end())
        {
            return;
        }

        vtx1.nbrs.erase(vname2);
        vtx2.nbrs.erase(vname1);
    }
    vector<string> returnkeys() // returns list of stations
    {
        vector<string> keys;
        for (auto i : vtces)
        {
            keys.push_back(i.first);
        }
        return keys;
    }

    void display_Map()
    {
        cout << "\t Delhi Metro Map";
        cout << "\t------------------";
        cout << "----------------------------------------------------\n";

        vector<string> keys;
        for (auto it : vtces)
        {
            keys.push_back(it.first);
        }
        for (int key = 0; key < keys.size(); key++)
        {

            string str = keys[key] + " =>\n";
            Vertex vtx = vtces[keys[key]];
            vector<string> vtxnbrs;
            for (auto it : vtx.nbrs)
            {
                vtxnbrs.push_back(it.first);
            }
            for (int i = 0; i < vtxnbrs.size(); i++)
            {
                str = str + "\t" + vtxnbrs[i] + "\t";
                if (vtxnbrs[i].length() < 16)
                    str = str + "\t";
                if (vtxnbrs[i].length() < 8)
                    str = str + "\t";
                str = str + to_string(vtx.nbrs[vtxnbrs[i]]) + "\n";
            }
            cout << str << endl;
        }
        cout << "\t------------------";
        cout << "---------------------------------------------------\n";
    }
    void display_Stations()
    {
        cout << "\n*********\n";
        vector<string> keys;
        for (auto it : vtces)
        {
            keys.push_back(it.first);
        }
        int i = 1;
        for (int j = 0; j < keys.size(); j++)
        {
            cout << i << "  " << keys[j] << endl;
            i++;
        }
        cout << "\n*********\n";
    }
    bool hasPath(string vname1, string vname2, map<string, bool> &processed)
    {
        // DIR EDGE
        if (containsEdge(vname1, vname2))
        {
            return true;
        }

        // MARK AS DONE
        processed[vname1] = true;
        cout << endl;
        Vertex vtx = vtces[vname1];
        vector<string> keys;
        for (auto it = vtx.nbrs.begin(); it != vtx.nbrs.end(); it++)
        {
            keys.push_back(it->first);
        }

        // TRAVERSE THE NBRS OF THE VERTEX
        for (int i = 0; i < keys.size(); i++)
        {

            if (processed.find(keys[i]) == processed.end())
            {
                if (hasPath(keys[i], vname2, processed))
                {
                    return true;
                }
            }
        }

        return false;
    }

    struct pair
    {
        string vname;
        string psf;
        int min_dis;
        int min_time;
    };

    string get_Minimum_Distance(string src, string dst)
    {
        int min = INT_MAX;
        // int time = 0;
        string ans = "";
        map<string, bool> processed;
        vector<pair> stock;

        // create a new pair
        struct pair sp;
        sp.vname = src;
        sp.psf = src + ",";
        sp.min_dis = 0;
        sp.min_time = 0;

        stock.insert(stock.begin(), sp);

        // while stack is not empty keep on doing the work
        while (!stock.empty())
        {
            // remove a pair from stack
            pair rp = stock[0];
            stock.erase(stock.begin());

            if (processed.find(rp.vname) != processed.end())
            {
                continue;
            }

            // processed put
            processed[rp.vname] = true;

            // if there exists a direct edge b/w removed pair and destination vertex
            if (rp.vname == dst)
            {
                int temp = rp.min_dis;
                if (temp < min)
                {
                    ans = rp.psf;
                    min = temp;
                }
                continue;
            }

            Vertex rpvtx = vtces[rp.vname];
            vector<string> keys;
            for (auto i : rpvtx.nbrs)
            {
                keys.push_back(i.first);
            }
            for (auto nbr : keys)
            {
                // process only unprocessed nbrs
                if (processed.find(nbr) == processed.end()) // != ya == doubt
                {

                    // make a new pair of nbr and put in queue
                    pair np;
                    np.vname = nbr;
                    np.psf = rp.psf + nbr + ",";
                    np.min_dis = rp.min_dis + rpvtx.nbrs[nbr];

                    stock.insert(stock.begin(), np);
                }
            }
        }
        ans = ans + to_string(min);
        return ans;
    }

    string get_Minimum_Time(string src, string dst)
    {
        int min = INT_MAX;
        string ans = "";
        map<string, bool> processed;
        vector<pair> stock;

        // create a new pair
        pair sp;
        sp.vname = src;
        sp.psf = src + ",";
        sp.min_dis = 0;
        sp.min_time = 0;

        // put the new pair in queue
        stock.insert(stock.begin(), sp); // replacing addFirst

        while (!stock.empty())
        {

            pair rp = stock[0];
            stock.erase(stock.begin());

            if (processed.find(rp.vname) != processed.end())
            {
                continue;
            }

            // processed put
            processed[rp.vname] = true;

            // if there exists a direct edge b/w removed pair and destination vertex
            if (rp.vname == dst)
            {
                int temp = rp.min_time;
                if (temp < min)
                {
                    ans = rp.psf;
                    min = temp;
                }
                continue;
            }

            Vertex rpvtx = vtces[rp.vname];
            vector<string> keys;
            for (auto i : rpvtx.nbrs)
            {
                keys.push_back(i.first);
            }
            for (string nbr : keys)
            {
                // process only unprocessed nbrs
                if (processed.find(nbr) == processed.end())
                {

                    struct pair np;
                    np.vname = nbr;
                    np.psf = rp.psf + nbr + ",";
                    // np.min_dis = rp.min_dis + rpvtx.nbrs.get(nbr);
                    np.min_time = rp.min_time + (rpvtx.nbrs[nbr] * 60) / 40;
                    stock.insert(stock.begin(), np); // replacing addFirst
                }
            }
        }
        // double minutes = ceil((double)min / 60);
        ans = ans + to_string(min);
        return ans;
    }

    vector<string> printCodeList()
    {
        cout << "List of station along with their codes:\n";
        vector<string> keys;
        for (auto it : vtces)
        {
            keys.push_back(it.first);
        }

        vector<string> codes;
        for (string key : keys)
        {
            // string key =keys[3];
            cout << key << endl;
            vector<string> words;
            string word = "";
            for (int i = 0; i <= key.size(); i++)
            {
                if (key[i] == ' ' || key[i] == '\0')
                {
                    words.push_back(word);
                    word = "";
                }
                else
                {
                    word = word + key[i];
                }
            }
            if (words.size() == 1)
            {
                string code = words[0].substr(0, 2);
                for (int i = 0; i < code.size(); i++)
                {
                    if (code[i] >= 97 && code[i] <= 122)
                    {
                        code[i] = (code[i] - 32);
                    }
                }
                codes.push_back(code);
                // cout<<code<<endl;
            }
            else if (words.size() >= 2)
            {
                string code;
                for (int i = 0; i < words.size(); i++)
                {
                    code += words[i].substr(0, 1);
                }
                for (int i = 0; i < code.size(); i++)
                {
                    if (code[i] >= 97 && code[i] <= 122)
                    {
                        code[i] = (code[i] - 32);
                    }
                }
                codes.push_back(code);
                // cout<<code<<endl;
            }
        }
        int m = 0;
        for (int i = 0; i < codes.size(); i++)
        {  
            cout << i + 1 << ". " << keys[i];
            if (keys[i].size() < (26 - m))
                cout << "\t";
            if (keys[i].size() < (14 - m))
                cout << "\t";
            if (keys[i].size() < (6 - m))
                cout << "\t";
            cout << codes[i] << endl;
            if (i == pow(10, m))
                m++;
        }

        return codes;
    }

    class dijkstrapair
    {
    public:
        string vname;
        string psf;
        int cost;
    };
    int dijkstra(string src, string des)
    {
        int val = 0;
        vector<string> ans;
        map<string, dijkstrapair> m;

        for (auto i : vtces)
        {
            string key = i.first;
            dijkstrapair np;
            np.vname = key;
            np.cost = INT_MAX;

            if (key == src)
            {
                np.cost = 0;
                np.psf = key;
            }

            m[key] = np;
        }

        while (true)
        {
            int mi = INT_MAX;
            dijkstrapair rp;
            for (auto i : m)
            {
                if (i.second.cost < mi)
                {
                    mi = i.second.cost;
                    rp = i.second;
                }
            }
            if (rp.vname == des)
            {
                val = rp.cost;
                break;
            }

            m.erase(rp.vname);

            ans.push_back(rp.vname);

            Vertex v = vtces[rp.vname];

            for (auto nbr : v.nbrs)
            {
                if (m.find(nbr.first) != m.end())
                {
                    int oc = m[nbr.first].cost;

                    Vertex k = vtces[rp.vname];

                    int nc;

                    nc = rp.cost + k.nbrs[nbr.first];

                    if (nc < oc)
                    {
                        dijkstrapair &gp = m[nbr.first];
                        gp.psf = rp.psf + nbr.first;
                        gp.cost = nc;
                        m[nbr.first] = gp;
                    }
                }
            }
        }
        return val;
    }
};

vector<string> get_Interchanges(string str)
{
    vector<string> arr;
    vector<string> res;
    int f = 0, l = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',')
        {
            res.push_back(str.substr(l, i - l));
            l = i + 1;
        }
    }
    res.push_back(str.substr(l, str.length() - l));
    arr.push_back(res[0]);
    int count = 0;
    for (int i = 1; i < res.size() - 1; i++)
    {
        int index = res[i].find_first_of("-");
        string s = res[i].substr(index + 1);
        if (s.length() == 2)
        {
            string prev = res[i - 1].substr((res[i - 1].find_first_of("-")) + 1);
            string next = res[i + 1].substr((res[i + 1].find_first_of("-")) + 1);

            if (prev == next)
            {

                arr.push_back(res[i]);
            }
            else
            {

                arr.push_back(res[i] + "==>" + res[i + 1]);
                i++;
                count++;
            }
        }
        else
        {

            arr.push_back(res[i]);
        }
    }
    arr.push_back(to_string(count));
    arr.push_back(res[res.size() - 1]);
    return arr;
}

void create_metro_map(Graph_M *g)
{
    g->addVertex("Noida sector-B");
    g->addVertex("Botanical Garden-B");
    g->addVertex("Yamuna Bank-B");
    g->addVertex("Rajiv Chowk-BY");
    g->addVertex("Vaishali-B");
    g->addVertex("Moti Nagar-B");
    g->addVertex("Janak Puri West-BO");
    g->addVertex("Dwarka Sector-B");
    g->addVertex("Huda City Center-Y");
    g->addVertex("Saket-Y");
    g->addVertex("Vishwavidyalaya-Y");
    g->addVertex("Chandni Chowk-Y");
    g->addVertex("New Delhi-YO");
    g->addVertex("AIIMS-Y");
    g->addVertex("Shivaji Stadium-O");
    g->addVertex("DDS Campus-O");
    g->addVertex("IGI Airport-O");
    g->addVertex("Rajouri Garden-BP");
    g->addVertex("Netaji Subhash Place-PR");
    g->addVertex("Punjabi Bagh West-P");

    g->addEdge("Noida sector-B", "Botanical Garden-B", 8);
    g->addEdge("Botanical Garden-B", "Yamuna Bank-B", 10);
    g->addEdge("Yamuna Bank-B", "Vaishali-B", 8);
    g->addEdge("Yamuna Bank-B", "Rajiv Chowk-BY", 6);
    g->addEdge("Rajiv Chowk-BY", "Moti Nagar-B", 9);
    g->addEdge("Moti Nagar-B", "Janak Puri West-BO", 7);
    g->addEdge("Janak Puri West-BO", "Dwarka Sector-B", 6);
    g->addEdge("Huda City Center-Y", "Saket-Y", 15);
    g->addEdge("Saket-Y", "AIIMS-Y", 6);
    g->addEdge("AIIMS-Y", "Rajiv Chowk-BY", 7);
    g->addEdge("Rajiv Chowk-BY", "New Delhi-YO", 1);
    g->addEdge("New Delhi-YO", "Chandni Chowk-Y", 2);
    g->addEdge("Chandni Chowk-Y", "Vishwavidyalaya-Y", 5);
    g->addEdge("New Delhi-YO", "Shivaji Stadium-O", 2);
    g->addEdge("Shivaji Stadium-O", "DDS Campus-O", 7);
    g->addEdge("DDS Campus-O", "IGI Airport-O", 8);
    g->addEdge("Moti Nagar-B", "Rajouri Garden-BP", 2);
    g->addEdge("Punjabi Bagh West-P", "Rajouri Garden-BP", 2);
    g->addEdge("Punjabi Bagh West-P", "Netaji Subhash Place-PR", 3);
    g->addEdge("DDS Campus-O", "Chandni Chowk-Y", 1);
}

int main()
{
    Graph_M g;
    create_metro_map(&g);
    clearScreen();
    displayWelcomeMessage();
    displayHeader();
    displayContributors();

    unordered_map<string, string> users; // In-memory storage for user credentials
    int choice;
    bool temp = true;

    while (temp)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            signUp(users);
            break;
        case 2:
            signIn(users);
            temp = false;
            break;
        case 3:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n\n";
        }
    }

    while (true)
    {
        cout << "\t\t\t\t~LIST OF ACTIONS~\n\n"
             << endl;
        cout << "1. LIST ALL THE STATIONS IN THE MAP" << endl;
        cout << "2. SHOW THE METRO MAP" << endl;
        cout << "3. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "4. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "5. GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "6. GET FARE FOR JOURNEY FROM 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "7. EXIT THE MENU" << endl;
        cout << "\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 7) : ";
        int choice = -1;
        cin >> choice;
        cout << "\n*********************\n";
        system("cls");

        switch (choice)
        {
        case 1:
            g.display_Stations();
            break;

        case 2:
            g.display_Map();
            break;

        case 3:
        {
            vector<string> keys = g.returnkeys();
            vector<string> codes = g.printCodeList();
            cout << "\n1. TO ENTER SERIAL NO. OF STATIONS\n2. TO ENTER CODE OF STATIONS\n3. TO ENTER NAME OF STATIONS\n"
                 << endl;
            cout << "ENTER YOUR CHOICE:" << endl;
            int ch;
            cin >> ch;
            int j;
            system("cls");
            string st1 = "", st2 = "";
            if (ch == 1)
            {
                cout << "ENTER SERIAL NO. 1:";
                int in1;
                cin >> in1;
                cout << "ENTER SERIAL NO. 2:";
                int in2;
                cin >> in2;
                st1 = keys[in1 - 1];
                st2 = keys[in2 - 1];
            }
            else if (ch == 2)
            {
                string a, b;
                cout << "ENTER CODE 1:";
                cin >> a;
                cout << "ENTER CODE 2:";
                cin >> b;
                transform(a.begin(), a.end(), a.begin(), ::toupper);
                transform(b.begin(), b.end(), b.begin(), ::toupper);
                for (j = 0; j < codes.size(); j++)
                {
                    if (a == codes[j])
                    {
                        break;
                    }
                }
                st1 = keys[j];
                for (j = 0; j < codes.size(); j++)
                {
                    if (b == codes[j])
                    {
                        break;
                    }
                }
                st2 = keys[j];
            }
            else if (ch == 3)
            {
                cout << "ENTER THE SOURCE STATION: " << endl;
                fflush(stdin);
                getline(cin, st1);
                cout << "ENTER THE DESTINATION STATION: " << endl;
                fflush(stdin);
                getline(cin, st2);
            }
            else
            {
                cout << "INVALID CHOICE" << endl;
                exit(0);
            }
            map<string, bool> processed;
            if (!g.containsVertex(st1) || !g.containsVertex(st2) || !g.hasPath(st1, st2, processed))
            {
                cout << "THE INPUTS ARE INVALID" << endl;
            }
            else
            {
                cout << "SHORTEST DISTANCE FROM " << st1 << " TO " << st2 << " IS " << g.dijkstra(st1, st2) << "KM\n"
                     << endl;
            }
            break;
        }

        case 4:
        {
            vector<string> codes = g.printCodeList();
            cout << "ENTER THE SOURCE STATION: " << endl;
            fflush(stdin);
            string s1;
            getline(cin, s1);
            cout << "ENTER THE DESTINATION STATION: " << endl;
            fflush(stdin);
            string s2;
            getline(cin, s2);
            system("cls");
            map<string, bool> processed2;
            if (!g.containsVertex(s1) || !g.containsVertex(s2) || !g.hasPath(s1, s2, processed2))
            {
                cout << "THE INPUTS ARE INVALID" << endl;
            }
            else
            {
                vector<string> str = get_Interchanges(g.get_Minimum_Distance(s1, s2));
                int len = str.size();
                cout << "SOURCE STATION : " << s1 << endl;
                cout << "DESTINATION STATION : " << s2 << endl;
                cout << "DISTANCE : " << str[len - 1] << endl;
                cout << "NUMBER OF INTERCHANGES : " << str[len - 2] << endl;
                cout << "*****************************" << endl;
                cout << "START ==> " << str[0] << endl;
                for (int i = 1; i < len - 3; i++)
                {
                    cout << str[i] << endl;
                }
                cout << str[len - 3] << "  ==>  END" << endl;
                cout << "*****************************" << endl;
            }
            break;
        }

        case 5:
        {
            vector<string> codes = g.printCodeList();
            cout << "ENTER THE SOURCE STATION: " << endl;
            fflush(stdin);
            string ss1;
            getline(cin, ss1);
            cout << "ENTER THE DESTINATION STATION: " << endl;
            fflush(stdin);
            string ss2;
            getline(cin, ss2);
            system("cls");
            map<string, bool> processed3;
            if (!g.containsVertex(ss1) || !g.containsVertex(ss2) || !g.hasPath(ss1, ss2, processed3))
            {
                cout << "THE INPUTS ARE INVALID" << endl;
            }
            else
            {
                vector<string> str = get_Interchanges(g.get_Minimum_Time(ss1, ss2));
                int len = str.size();
                cout << "SOURCE STATION : " << ss1 << endl;
                cout << "DESTINATION STATION : " << ss2 << endl;
                cout << "TIME : " << str[len - 1] << " MINUTES" << endl;
                cout << "NUMBER OF INTERCHANGES : " << str[len - 2] << endl;
                cout << "~~~~~" << endl;
                cout << "START ==> " << str[0] << endl;
                for (int i = 1; i < len - 3; i++)
                {
                    cout << str[i] << endl;
                }
                cout << str[len - 3] << "  ==>  END" << endl;
                cout << "~~~~~" << endl;
            }
            break;
        }

        case 6:
        {
            vector<string> codes = g.printCodeList();
            cout << "ENTER THE SOURCE STATION: " << endl;
            fflush(stdin);
            string ss1;
            getline(cin, ss1);
            cout << "ENTER THE DESTINATION STATION: " << endl;
            fflush(stdin);
            string ss2;
            getline(cin, ss2);
            system("cls");
            map<string, bool> processed3;
            if (!g.containsVertex(ss1) || !g.containsVertex(ss2) || !g.hasPath(ss1, ss2, processed3))
            {
                cout << "THE INPUTS ARE INVALID" << endl;
            }
            else
            {
                // Assuming that per km the cost is fixed
                // Assuming it to be 3 rupees per km
                string str = g.get_Minimum_Distance(ss1, ss2);
                vector<string> res;
                int l = 0;
                for (int i = 0; i < str.length(); i++)
                {
                    if (str[i] == ',')
                    {
                        res.push_back(str.substr(l, i - l));
                        l = i + 1;
                    }
                }
                res.push_back(str.substr(l, str.length() - l));
                int dis = stoi(res[res.size() - 1]);
                int fare = dis * 3;
                if (fare < 20)
                {
                    fare = 20;
                }
                else if (fare > 70)
                {
                    fare = 70;
                }
                cout << "SOURCE STATION : " << ss1 << endl;
                cout << "DESTINATION STATION : " << ss2 << endl;
                cout << "FARE : " << fare << " RUPEES" << endl;
            }
            break;
        }
        case 7:
            displayForm();
            exit(0);
            break;
        default:
            cout << "Please enter a valid option! " << endl;
            cout << "The options you can choose are from 1 to 6. " << endl;
        }
    }
}