#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class account
{
    protected:
    string username, password, user, pass;
    static int count;
    string uname, passw;
    string sUserID, spass, sID;
    int option;
    string uno;

public:
  string un;

public:
    void start()
    {
        cout << "1- SIGN UP" << endl;
        cout << "2- LOG IN" << endl;
        cout << "3- FORGET PASSWORD" << endl;
        cout << "enter option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            forget();
        }
    }
    void login()
    {
    x:
        cout << "enter username: ";
        cin >> username;
        cout << "enter password: ";
        cin >> password;
        ifstream myfile("userData.bin");
        while (myfile >> user >> pass)
        {
            if (user == username && pass == password)
            {
                count = 1;
                un = username;
            }
        }
        myfile.close();
        if (count == 1)
        {
            cout << "login successful" << endl;
        }
        else
        {
            cout << "try again" << endl;
            goto x;
        }
    }
    void signup()
    {
    z:
        cout << "enter username: ";
        cin >> uname;
        ifstream hello("userData.bin");
        while (hello >> uno)
        {
            if (uno == uname)
            {
                cout << "The username already exits!" << endl;
                goto z;
            }
        }
        hello.close();

        cout << "enter password: ";
        cin >> passw;
        ofstream file("userData.bin", ios::binary | ios::app);
        file << uname << " " << passw << endl;
        file.close();
        cout << "registration successful" << endl;
        ofstream files;
        files.open(uname + ".txt", ios::out);
        files.close();
        login();
    }
    void forget()
    {
        cout << "\f\fenter username: ";
        cin >> sUserID;
        ifstream f1("userData.bin");
        while (f1 >> sID >> spass)
        {
            if (sID == sUserID)
            {
                count = 1;
            }
        }
        f1.close();
        if (count == 1)
        {
            cout << "Your password is " << spass << endl;
            login();
        }
        else
        {
            cout << "Account not found";
        }
    }
};
int account::count;

class user : public account
{
    int option;
    char str[1000], ch;
    string getcontent;
    static int i;
    int choice, pr2;
    string line, pr1, gname, content, t;
    char pr[100];
    static int lineno, l, s, len, price, k;
    static float time;
    
    protected:
        static int bill;

public:
    void professions()
    {
        cout << "1- Electrician" << endl;
        cout << "2- Mechanic" << endl;
        cout << "3- Plumber" << endl;
        cout << "4- Maid" << endl;
        cout << "5- Gardening" << endl;
        cin >> option;
        if (option == 1)
        {
            l = 0;
            ifstream newfile;
            newfile.open("electrician.txt", ios::binary | ios::in);
            if (newfile.is_open())

                if (newfile.is_open())
                {
                    while (newfile >> gname, getline(newfile, getcontent))
                    {
                        cout << i << "- " << getcontent << "/hr"
                             << "\n";
                        i++;
                    }
                }
            // newfile.close();
            cout << "enter option: ";
            cin >> choice;
            ifstream elec;
            elec.open("electrician.txt", ios::binary | ios::in);
            //  elec>>line;

            //   l=stoi(line);

            for (int j = 1; j <= i; j++)
            {

                if (choice == j)
                {
                    if (elec.is_open())
                    {
                        while (elec >> gname && getline(elec, getcontent))
                        {

                            if (s == choice)
                            {
                                len = getcontent.length();

                                cout << j << " - " << getcontent << "/hr" << endl;

                                for (int j = 0; j < len; j++)
                                {

                                    str[j] = getcontent[j];
                                }

                                ch = ' ';
                                char *p = strrchr(str, ch);

                                for (int j = (p - str) + 1; j <= (len - 1); j++)
                                {

                                    pr1 += getcontent[j];

                                    k++;
                                }

                                price = stoi(pr1);

                                ofstream data;
                                data.open(gname + ".txt", ios::app);

                                cin.ignore();
                                cout << "Enter your work ";
                                getline(cin, content);

                                cout << "Enter the time in hours you want to designate to the worker: ";
                                cin >> time;

                                bill = time * price;

                                cout << "Your total bill is: " << bill << " PKR";

                                data << un << "\n"
                                     << content << "\n"
                                     << "Time: " << time << " hrs"
                                                            "\n"
                                     << "Bill: " << bill << " PKR"
                                     << "\n";

                                data.close();

                                break;
                            }
                            else
                            {
                                cout << "\n";
                                s++;
                            }
                        }
                    }
                }
            }

            //// case 1 ends
        }
        else if (option == 2)
        {
            ifstream newfile;
            newfile.open("mechanic.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (newfile >> gname, getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "/hr"
                         << "\n";
                    i++;
                }
            }
            newfile.close();
            cout << "enter option: ";
            cin >> choice;

            ifstream mec("mechanic.txt", ios::binary | ios::in);

            for (int j = 1; j <= i; j++)
            {

                if (choice == j)
                {
                    if (mec.is_open())
                    {
                        while (mec >> gname && getline(mec, getcontent))
                        {
                            if (s == choice)
                            {

                                len = getcontent.length();

                                cout << j << " - " << getcontent << "/hr" << endl;

                                for (int j = 0; j < len; j++)
                                {

                                    str[j] = getcontent[j];
                                }

                                ch = ' ';
                                char *p = strrchr(str, ch);

                                for (int j = (p - str) + 1; j <= (len - 1); j++)
                                {

                                    pr1 += getcontent[j];

                                    k++;
                                }

                                price = stoi(pr1);

                                ofstream data;
                                data.open(gname + ".txt", ios::app);

                                cin.ignore();
                                cout << "Enter your work ";
                                getline(cin, content);

                                cout << "Enter the time in hours you want to designate to the worker: ";
                                cin >> time;

                                bill = time * price;

                                cout << "Your total bill is: " << bill << " PKR";

                                data << "Customer name: " << un << "\n"
                                     << content << "\n"
                                     << "Time: " << time << " hrs"
                                     << "\n"
                                     << "Bill: " << bill << " PKR"
                                     << "\n";

                                data.close();

                                break;
                            }
                            else
                            {
                                cout << "\n";
                                s++;
                            }
                        }
                    }
                }
            }

            //// case 2 ends
        }
        else if (option == 3)
        {
            ifstream newfile;
            newfile.open("plumber.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (newfile >> gname, getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "/hr"
                         << "\n";
                    i++;
                }
            }
            newfile.close();
            cout << "enter option: ";
            cin >> choice;

            ifstream plu("plumber.txt", ios::binary | ios::in);

            for (int j = 1; j <= i; j++)
            {

                if (choice == j)
                {
                    if (plu.is_open())
                    {
                        while (plu >> gname && getline(plu, getcontent))
                        {
                            if (s == choice)

                            {

                                len = getcontent.length();
                                cout << j << " - " << getcontent << "/hr" << endl;

                                for (int j = 0; j < len; j++)
                                {

                                    str[j] = getcontent[j];
                                }

                                ch = ' ';
                                char *p = strrchr(str, ch);

                                for (int j = (p - str) + 1; j <= (len - 1); j++)
                                {

                                    pr1 += getcontent[j];

                                    k++;
                                }

                                price = stoi(pr1);

                                ofstream data;
                                data.open(gname + ".txt", ios::app);

                                cin.ignore();
                                cout << "Enter your work ";
                                getline(cin, content);

                                cout << "Enter the time in hours you want to designate to the worker: ";
                                cin >> time;

                                bill = time * price;

                                cout << "Your total bill is: " << bill << " PKR";

                                data << "Customer name: " << un << "\n"
                                     << content << "\n"
                                     << "Time: " << time << " hrs"
                                     << "\n"
                                     << "Bill: " << bill << " PKR"
                                     << "\n";

                                data.close();

                                break;
                            }
                            else
                            {
                                cout << "\n";
                                s++;
                            }
                        }
                    }
                }
            }

            ///// case 3 ends
        }
        else if (option == 4)
        {
            ifstream newfile;
            newfile.open("maid.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (newfile >> gname, getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "/hr"
                         << "\n";
                    i++;
                }
            }
            newfile.close();

            cout << "enter option: ";
            cin >> choice;

            ifstream mai("maid.txt", ios::binary | ios::in);

            for (int j = 1; j <= i; j++)
            {

                if (choice == j)
                {
                    if (mai.is_open())
                    {
                        while (mai >> gname && getline(mai, getcontent))
                        {
                            if (s == choice)
                            {

                                len = getcontent.length();
                                cout << j << " - " << getcontent << "/hr" << endl;

                                for (int j = 0; j < len; j++)
                                {

                                    str[j] = getcontent[j];
                                }

                                ch = ' ';
                                char *p = strrchr(str, ch);

                                for (int j = (p - str) + 1; j <= (len - 1); j++)
                                {

                                    pr1 += getcontent[j];

                                    k++;
                                }

                                price = stoi(pr1);

                                ofstream data;
                                data.open(gname + ".txt", ios::app);

                                cin.ignore();
                                cout << "Enter your work ";
                                getline(cin, content);

                                cout << "Enter the time in hours you want to designate to the worker: ";
                                cin >> time;

                                bill = time * price;

                                cout << "Your total bill is: " << bill << " PKR";

                                data << "Customer name: " << un << "\n"
                                     << content << "\n"
                                     << "Time: " << time << " hrs"
                                     << "\n"
                                     << "Bill: " << bill << " PKR"
                                     << "\n";

                                data.close();

                                break;
                            }
                            else
                            {
                                cout << "\n";
                                s++;
                            }
                        }
                    }
                }
            }

            /////// case 4 ends
        }
        else if (option == 5)
        {
            ifstream newfile;
            newfile.open("gardenar.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (newfile >> gname, getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "/hr"
                         << "\n";
                    i++;
                }
            }
            newfile.close();

            cout << "enter option: ";
            cin >> choice;

            ifstream gar("gardenar.txt", ios::binary | ios::in);

            for (int j = 1; j <= i; j++)
            {

                if (choice == j)
                {
                    if (gar.is_open())
                    {
                        while (gar >> gname && getline(gar, getcontent))
                        {
                            if (s == choice)
                            {

                                len = getcontent.length();

                                cout << j << " - " << getcontent << "/hr" << endl;

                                for (int j = 0; j < len; j++)
                                {

                                    str[j] = getcontent[j];
                                }

                                ch = ' ';
                                char *p = strrchr(str, ch);

                                for (int j = (p - str) + 1; j <= (len - 1); j++)
                                {

                                    pr1 += getcontent[j];

                                    k++;
                                }

                                price = stoi(pr1);

                                ofstream data;
                                data.open(gname + ".txt", ios::app);

                                cin.ignore();
                                cout << "Enter your work ";
                                getline(cin, content);

                                ab:
                                cout << "Enter the time in hours you want to designate to the worker: ";
                                cin >> time;
                                if (time<=0) {
                                    cout<<"Enter valid time";
                                    goto ab;
                                }

                                bill = time * price;

                                cout << "Your total bill is: " << bill << " PKR";

                                data << "Customer name: " << un << "\n"
                                     << content << "\n"
                                     << "Time: " << time << " hrs"
                                     << "\n"
                                     << "Bill:s " << bill << " PKR"
                                     << "\n";

                                data.close();

                                break;
                            }
                            else
                            {
                                cout << "\n";
                                s++;
                            }
                        }
                    }
                }
            }

            ////// case 5 ends
        }
    }
};
int user::i = 1;
int user::lineno;
int user::l;
int user::s = 1;
int user::len;
int user::price;
int user::k;
int user::bill;
float user::time;


///// worker account class

class workerAccount : public user
{
    string username, password, user, pass, unos;
    static int count;
    static int i;
    string uname, passw, firstname, lastname, myText, pr1;
    string sUserID, spass, sID;
    int option, ch, select, sop;
    float rate;
    char str[1000];
    static int len;
    int k;
    static int co;

public:
    string un2;

public:
    void start()
    {
        cout << "1- SIGN UP" << endl;
        cout << "2- LOG IN" << endl;
        cout << "3- FORGET PASSWORD" << endl;
        cout << "enter option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            forget();
        }
    }

    void signup()
    {
        ut:
        cout << "enter username (only enter letters): ";
        cin >> uname;
        ifstream adios("workerData.txt");
        while (adios >> unos)
        {
            if (unos == uname)
            {
                cout << "The username already exits!" << endl;
                goto ut;
            }
        }
        adios.close();

        cout << "enter password: ";
        cin >> passw;
        ofstream file("workerData.txt", ios::binary | ios::app);
        file << uname << " " << passw << endl;
        file.close();

        //////// generate file of worker with its username
        ofstream data;
        data.open(uname + ".txt", ios::out);
        data.close();

        ofstream earning;
        earning.open(uname+"earn.txt", ios::out);
        earning.close();

        cout << "1- Electrician" << endl;
        cout << "2- Mechanic" << endl;
        cout << "3- Plumber" << endl;
        cout << "4- Maid" << endl;
        cout << "5- Gardening" << endl;

        cout << "Enter your profession: ";
        cin >> ch;
        /////////
        if (ch == 1)
        {
            cout << "enter Full Name: ";
            cin >> firstname >> lastname;
            cin.ignore();
            fflush(stdin);
            a:
            cout << "enter your hourly rate: ";
            cin >> rate;
            if (rate<1) {
                cout<<"Invalid rate";
                goto a;
            }
            ofstream file1("electrician.txt", ios::app);
            file1 << uname << " " << firstname << " " << lastname << " " << rate << endl;
            file1.close();
        }
        else if (ch == 2)
        {
            ///////////
            cout << "enter Full Name: ";
            cin >> firstname >> lastname;

            cin.ignore();
            fflush(stdin);
            b:
            cout << "enter your hourly rate: ";
            cin >> rate;
            if (rate<1) {
                cout<<"Invalid rate";
                goto b;
            }
            ofstream file1("mechanic.txt", ios::app);
            file1 << uname << " " << firstname << " " << lastname << " " << rate << endl;
            file1.close();
        }
        else if (ch == 3)
        {
            cout << "enter Full Name: ";
            cin >> firstname >> lastname;

            cin.ignore();
            fflush(stdin);
            c:
            cout << "enter your hourly rate: ";
            cin >> rate;
            if (rate<1) {
                cout<<"Invalid rate";
                goto c;
            }
            ofstream file1("plumber.txt", ios::app);
            file1 << uname << " " << firstname << " " << lastname << " " << rate << endl;
            file1.close();
        }
        else if (ch == 4)
        {

            cout << "enter Full Name: ";
            cin >> firstname >> lastname;

            cin.ignore();
            fflush(stdin);
            d:
            cout << "enter your hourly rate: ";
            cin >> rate;
            if (rate<1) {
                cout<<"Invalid rate";
                goto d;
            }
            ofstream file1("maid.txt", ios::app);
            file1 << uname << " " << firstname << " " << lastname << " " << rate << endl;
            file1.close();
        }
        else if (ch == 5)
        {

            cout << "enter Full Name: ";
            cin >> firstname >> lastname;

            cin.ignore();
            fflush(stdin);
            e:
            cout << "enter your hourly rate: ";
            cin >> rate;
            if (rate<1) {
                cout<<"Invalid rate";
                goto e;
            }
            ofstream file1("gardenar.txt", ios::app);
            file1 << firstname << " " << lastname << " " << rate << endl;
            file1.close();
        }

        cout << "registration successful" << endl;
    }

    void login()
    {
        int len = 0, l = 0, n = 0;
        string gname, content;
    z:
        cout << "enter username: ";
        cin >> username;
        cout << "enter password: ";
        cin >> password;
        ifstream myfile3("workerData.txt");
        while (myfile3 >> user >> pass)
        {
            if (user == username && pass == password)
            {
                i = 1;
                un = username;
            }
        }
        myfile3.close();
        if (i == 1)
        {
            cout << "login successful" << endl;
        }
        else
        {
            cout << "try again" << endl;
            goto z;
        }
    label:
        cout << "1- Orders" << endl;
        cout << "2- Earning" << endl;
        cout << "Any key- Exit" << endl;
        cin >> select;

        if (select == 1)
        {

            ifstream myReadFile(username + ".txt");
            myReadFile.seekg(0, ios::end);
            int length = myReadFile.tellg();

            if (length == 0)
            {
                cout << "no orders";
                myReadFile.close();
            }
            else if (length > 0)
            {
                ifstream work(username + ".txt");
                while (getline(work, myText))

                {

                    len = myText.find("PKR");

                    if (len > 0)
                    {
                        n++;
                    }
                }

                if (length > 0)
                {
                    ifstream work(username + ".txt");

                    cout << "No of orders " << n << endl;
                    cout << "Customer Name ";
                    work >> gname;
                    cout << gname;
                    while (getline(work, myText))

                    {

                        cout << myText << endl;

                        len = myText.find("PKR");

                        if (len > 0)
                        {
                            l++;

                            cout << "Press '1' to accept and any key to reject " << endl;
                            cout << "1- Accept" << endl;
                            cout << "2- Reject" << endl;
                            len = 0;

                            cin >> sop;

                            if (sop == 1)
                            {

                                ofstream data;
                                data.open(gname + ".txt", ios::app);
                                cin.ignore();
                                cout << "Enter your reply ";
                                getline(cin, content);
                                data << content << "\n";
                                work.close();

                                data.close();
                              

                            }

                            else if (l == n)
                            {

                                goto label;
                            }
                            else
                            {

                                work >> gname;
                                cout << "Customer Name ";
                                cout << gname;
                            }
                        }
                    }
                }
            }
        }
////////// earning
        else if (select == 2)
        {
            int sum=0;
            sum = sum + bill;
            cout << bill;
            ofstream a;
            a.open(uname+"earn.txt", ios::out);
            a << sum;
            a.close();  
        }

        /* while (getline(myReadFile,myText)) {
             cout << myText << endl;
         }
         cout<<"1- Accept" << endl;
             cout<<"2- Reject" << endl;
             cin>>sop;
         myReadFile.close();
         } else if (select == 2) {
             cout<<"orive";
         }*/

        /* int length;
    ifstream filestr;

    filestr.open("fileYouWantToTest.txt", ios::binary); // open your file
    filestr.seekg(0, ios::end); // put the "cursor" at the end of the file
    length = filestr.tellg(); // find the position of the cursor
    filestr.close(); // close your file

    if ( length == 0 ){...}
    else {...} */
    }
};
int workerAccount::i;
int workerAccount::co;
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////

/*class worker : public user
{
};*/

int main()
{
    user obj;
    workerAccount obj1;
    int choice;
    cout << "1- Customer" << endl;
    cout << "2- Worker" << endl;
    cout << "3- Admin" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        obj.start();
        obj.professions();
        break;
    case 2:
        obj1.start();
        break;
    case 3:
        obj1.start();
    }
}