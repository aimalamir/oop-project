#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
class account
{
    string username, password, user, pass;
    static int count;
    string uname, passw;
    string sUserID, spass, sID;
    int option;
    string uno;
    int count2 = 0;

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

            count2++;
            if (count2 == 3)
            {
                forget();
            }
            else
            {
                cout << "try again" << endl;
                goto x;
            }
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
        int code;
        cout << "You will be directed to forget password domain:" << endl;
        system("start sender.py");
        cout << "Enter code that is sent on your email address:" << endl;
        cin >> code;

        if (code == 2000)
        {
            cout << "\f\fenter username: ";
            cin >> sUserID;
            ifstream f1("userData.bin", ios::app);
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

        else
        {
            cout << "Cannot change your password code doesn't match " << endl;
            exit(0);
        }
    }
};
int account::count;

///// worker account class

class workerAccount : public account
{
    string username, password, user, pass, unos, bill2;
    static int count;
    static int i, bill;
    string uname, passw, firstname, lastname, myText, pr1, myText2, myText3, myText4, myText5, myText6, myText7;
    string sUserID, spass, sID;
    int option, ch, select, sop;
    float rate;
    char str[1000];
    static int len;
    int k;
    int h = 0;
    string *myT = new string;
    int count2 = 0;

public:
    string un2;
    void forgett()
    {
        int cod;
        cout << "You will be directed to forget password domain:" << endl;
        system("start sender.py");
        cout << "Enter code that is sent on your email address:" << endl;
        cin >> cod;
        if (cod == 2000)
        {
            cout << "\f\fenter username: ";
            cin >> sUserID;
            ifstream f9("workerData.txt", ios::app);
            while (f9 >> sID >> spass)
            {
                if (sID == sUserID)
                {
                    count = 1;
                }
            }

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
        else
        {
            cout << "code doesn't match" << endl;
        }
    }

public:
    void start1()
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
            login1();
            break;
        case 3:
            forgett();
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
            cout << "enter your hourly rate: ";
            cin >> rate;
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
            cout << "enter your hourly rate: ";
            cin >> rate;
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
            cout << "enter your hourly rate: ";
            cin >> rate;
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
            cout << "enter your hourly rate: ";
            cin >> rate;
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
            cout << "enter your hourly rate: ";
            cin >> rate;
            ofstream file1("gardenar.txt", ios::app);
            file1 << firstname << " " << lastname << " " << rate << endl;
            file1.close();
        }

        cout << "registration successful" << endl;
    }

    void login1()
    {
        int len = 0, l = 0, n = 0, len2 = 0, sum2 = 0;
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

            count2++;
            if (count2 == 3)
            {
                forget();
            }
            else
            {
                cout << "try again" << endl;
                goto z;
            }
        }
    label:
        n = 0;
        l = 0;
        cout << "1- Orders" << endl;
        cout << "2- Earning" << endl;
        cout << "Any key- Exit" << endl;
        cin >> select;
        string w = "\n";
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
                ofstream ac(username + "accept" + ".txt", ios::app);
                ofstream rc(username + "reject" + ".txt", ios::app);
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
                    h = n;
                    work >> gname;
                    cout << gname;
                    myText3.append(gname);

                    while (getline(work, myText))

                    {

                        cout << myText << endl;

                        myText3.append(myText);
                        myText3.append(w);
                        len = myText.find("PKR");

                        if (len > 0)
                        {
                            l++;

                            cout << "Press '1' to accept and any key to reject " << endl;
                            cout << "1- Accept" << endl;
                            cout << "2- Reject" << endl;
                            cout << "3- Ignore" << endl;
                            len = 0;

                            cin >> sop;

                            if (sop == 1)
                            {
                                cout << myText3 << endl;
                                int len2 = 0;

                                ifstream acc(username + "accept" + ".txt");

                                // while (acc)

                                // {
                                //     acc >> myText5;
                                //     cout << myText5 << endl;

                                //     if (gname == myText5)
                                //     {

                                //         cout << "Already accepted!" << endl;

                                //         goto topi;
                                //     }
                                //     else
                                //     {
                                //     }
                                // }

                                // ifstream bcc(username + "reject" + ".txt");

                                // while (bcc)

                                // {
                                //     bcc >> myText7;
                                //     if (gname == myText7)
                                //     {

                                //         cout << "Already rejected!" << endl;

                                //         goto topi;
                                //     }
                                // }

                                ifstream w(username + ".txt");

                                while (w >> myText2)
                                {

                                    if (myText2 == gname)
                                    {
                                        while (getline(w, myText2))
                                        {
                                            w >> myText2;
                                            if (myText2 == "Time:")
                                            {
                                                ofstream p("tem.txt");
                                                string b, b2;
                                                while (getline(w, b))
                                                {

                                                    p << b;
                                                }
                                            }
                                        }
                                    }
                                }
                                string b2;
                                ifstream p2("tem.txt");

                                while (p2)
                                {
                                    p2 >> b2;

                                    if (b2 == "hrsBill:")
                                    {

                                        p2 >> bill2;

                                        break;
                                    }
                                }

                                ofstream earn(username + "earning" + ".txt", ios::app);

                                earn << bill2 << "  ";
                                // bill = stoi(bill2);
                                // cout << bill << endl;
                                earn.close();
                                ofstream data;
                                data.open(gname + ".txt", ios::app);
                                cin.ignore();
                                // cout << "Enter your reply ";
                                // getline(cin, content);
                                // data << content << "\n";
                                data << "From " << username << "\n Your work has been completed!\n";
                                ac << myText3 << endl;
                                myText3.clear();

                                ofstream o(username + ".txt");
                                o << "";
                                string bb;
                                int de;
                                int sum = 0;

                                ifstream earning(username + "earning" + ".txt");

                                while (earning)
                                {

                                    earning >> bb;
                                    bill = stoi(bb);
                                    sum = sum + bill;
                                }
                                de = stoi(bb);
                                cout<<de<<endl;
                                earning.close();
                                
                                ofstream over("overallrevenue.txt", ios::app);

                                over << de << " ";

                                over.close();
                                o.close();
                                work.close();

                                data.close();
                            }
                            else if (sop == 2)
                            {

                                // ifstream acc(username + "accept" + ".txt");

                                // while (acc)

                                // {
                                //     acc >> myText5;
                                //     cout << myText5 << endl;

                                //     if (gname == myText5)
                                //     {

                                //         cout << "Already accepted!" << endl;

                                //         goto topi;
                                //     }
                                //     else
                                //     {
                                //     }
                                // }

                                // ifstream bcc(username + "reject" + ".txt");

                                // while (bcc)

                                // {
                                //     bcc >> myText7;
                                //     if (gname == myText7)
                                //     {

                                //         cout << "Already rejected!" << endl;

                                //         goto topi;
                                //     }
                                // }

                                h--;
                                rc << myText3 << endl;
                                myText3.clear();
                                ofstream data;
                                // data.open(gname + "rejectorhold" + ".txt", ios::app);
                                // cin.ignore();
                                // data << "Rejected"
                                //      << "\n";
                                data.open(gname + ".txt", ios::app);
                                cin.ignore();
                                data << "From " << username << "\n Your work has been rejected!\n";

                                if (h == 0)
                                {

                                    ofstream i(username + ".txt");

                                    i << "";

                                    cout << "No order remains!" << endl;
                                    i.close();
                                }
                                data.close();
                            }
                            else if (sop == 3)
                            {

                                // ofstream data;
                                // data.open(gname + "rejectorhold" + ".txt", ios::app);
                                // cin.ignore();
                                // data << "Hold"
                                //      << "\n";
                                // data.close();

                                ofstream o("tem2.txt", ios::app);

                                o << myText3 << endl;
                            }
                            if (l == n)
                            {
                                string s;
                                ofstream o(username + ".txt");
                                o << "";
                                ifstream i("tem2.txt");
                                while (getline(i, s))
                                {

                                    o << s << endl;
                                }
                                ofstream oo("tem2.txt");
                                oo << "";

                                oo.close();
                                i.close();

                                o.close();
                                goto label;
                            }
                            else
                            {

                            topi:
                                myText3.clear();
                                work >> gname;
                                cout << "Customer Name ";
                                cout << gname;
                                myText3.append(gname);
                            }
                        }
                    }
                }
            }
        }

        else if (select == 2)
        {
            string bb;
            int de;
            int sum = 0;

            ifstream earning(username + "earning" + ".txt");

            while (earning)
            {

                earning >> bb;
                bill = stoi(bb);
                sum = sum + bill;
            }
            de = stoi(bb);
            sum = sum - de;
            cout << "Rs " << sum << endl;
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
int workerAccount::bill;
int workerAccount::count;
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
///////////////////////////////
class user : public workerAccount
{
    int option;
    char str[1000], ch;
    string getcontent;
    static int i;
    int choice, pr2;
    string line, pr1, gname, content, t;
    char pr[100];
    static int lineno, l, s, len, price, k;
    static float bill, time;

public:
    string ac;
    void info()
    {
        cout << "1- Find Services" << endl;
        cout << "2- Orders" << endl;
        cout << "enter option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            professions();
            break;
        case 2:
            orders();
            break;
        }
    }

    void orders()
    {

        cout << "1- Accepted" << endl;
        cout << "2- Rejected/Hold" << endl;
        cout << "enter option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            accepted();
            break;
        case 2:
            rejhol();
            break;
        }
    }
    void accepted()
    {

        ifstream acc(un + ".txt");

        while (getline(acc, ac))
        {

            cout << ac << endl;
        }
    }

    void rejhol()
    {

        ifstream rh(un + "rejectorhold" + ".txt");

        while (getline(rh, ac))
        {

            cout << ac << endl;
        }
    }

    void professions()
    {
    top:
        i = 1;
        s = 1;
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
                        cout << i << endl;
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
                                // ifstream al(un + "already" + ".txt");

                                // string a;

                                // while (al >> a)
                                // {

                                //     if (a == gname)
                                //     {

                                //         cout << "Can only place one order to a particular worker!" << endl;
                                //         goto top;
                                //     }
                                // }
                                // ofstream all(un + "already" + ".txt", ios::app);
                                // all << gname << "\n";
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
        top1:
            i = 1;
            s = 1;
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

                                // ifstream al(un + "already" + ".txt");

                                // string a;

                                // while (al >> a)
                                // {

                                //     if (a == gname)
                                //     {

                                //         cout << "Can only place one order to a particular worker!" << endl;
                                //         goto top1;
                                //     }
                                // }
                                // ofstream all(un + "already" + ".txt", ios::app);
                                // all << gname << "\n";
                                len = getcontent.length();
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
        top2:
            i = 1;
            s = 1;
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

                                // ifstream al(un + "already" + ".txt");

                                // string a;

                                // while (al >> a)
                                // {

                                //     if (a == gname)
                                //     {

                                //         cout << "Can only place one order to a particular worker!" << endl;
                                //         goto top2;
                                //     }
                                // }
                                // ofstream all(un + "already" + ".txt", ios::app);
                                // all << gname << "\n";
                                len = getcontent.length();

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
        top3:
            i = 1;
            s = 1;
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

                                // ifstream al(un + "already" + ".txt");

                                // string a;

                                // while (al >> a)
                                // {

                                //     if (a == gname)
                                //     {

                                //         cout << "Can only place one order to a particular worker!" << endl;
                                //         goto top3;
                                //     }
                                // }
                                // ofstream all(un + "already" + ".txt", ios::app);
                                // all << gname << "\n";
                                len = getcontent.length();
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
        top4:
            i = 1;
            s = 1;
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

                                // ifstream al(un + "already" + ".txt");

                                // string a;

                                // while (al >> a)
                                // {

                                //     if (a == gname)
                                //     {

                                //         cout << "Can only place one order to a particular worker!" << endl;
                                //         goto top4;
                                //     }
                                // }
                                // ofstream all(un + "already" + ".txt", ios::app);
                                // all << gname << "\n";
                                len = getcontent.length();

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
float user::bill;
float user::time;

class admin
{

    string adminname, wno, pssw, adminu, password, adminuser, adminpass;
    string sid, suser, spass;
    int count = 0;
    int count2 = 0;
    int option;
    public:
    void startadmin()
    {
        cout << "1- admin login" << endl;
        cout << "2- admin sign up" << endl;
        cout << "3- forget admin pass" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            adminlogin();
            break;
        case 2:
            adminsignup();

        case 3:
            forgettt();

        default:
            cout << "Invalid selection" << endl;
            break;
        }
    }
    void adminlogin()
    {
    x:
        cout << "enter username: ";
        cin >> adminu;
        cout << "enter password: ";
        cin >> password;
        ifstream myfile("admin.txt");
        while (myfile >> adminuser >> adminpass)
        {
            if (adminu == adminuser && adminpass == password)
            {
                count = 1;
                adminu = adminuser;
            }
        }
        myfile.close();
        if (count == 1)
        {
            cout << "login successful" << endl;

            cout<<"Want to check overall earning of the workers?"<<endl;
            int op;

             cout<<"'1' for yes and any key for no"<<endl;
             cin>>op;

               if(op==1){
                     
                     revenue();

               }
        }

        else
        {

            count2++;
            if (count2 == 3)
            {
                forgettt();
            }
            else
            {
                cout << "try again" << endl;
                goto x;
            }
        }
    }

    void adminsignup()
    {
    k:
        cout << "enter username: ";
        cin >> adminname;
        ifstream hello("admin.txt");
        while (hello >> wno)
        {
            if (wno == adminname)
            {
                cout << "The username already exits!" << endl;
                goto k;
            }
        }
        hello.close();

        cout << "enter password: ";
        cin >> pssw;
        ofstream file("admin.txt", ios::binary | ios::app);
        file << adminname << " " << pssw << endl;
        file.close();
        cout << "registration successful" << endl;
        ofstream files;
        files.open(adminname + ".txt", ios::out);
        files.close();
        adminlogin();
    }
    void forgettt()
    {
        int code;
        cout << "You will be directed to forget password domain:" << endl;
        system("start sender.py");
        cout << "Enter code that is sent on your email address:" << endl;
        cin >> code;

        if (code == 2000)
        {
            cout << "\f\fenter username: ";
            cin >> suser;
            ifstream f1("admin.txt", ios::app);
            while (f1 >> sid >> spass)
            {
                if (sid == suser)
                {
                    count = 1;
                }
            }
            f1.close();
            if (count == 1)
            {
                cout << "Your password is " << spass << endl;
                adminlogin();
            }
            else
            {
                cout << "Account not found";
            }
        }

        else
        {
            cout << "Cannot change your password code doesn't match " << endl;
        }
    }

    void revenue(){

        int sum=0,b;
              ifstream i("overallrevenue.txt");

              while(i){

                  i>>b;
                    sum=sum+b;
              }

              sum=sum-b;

            

              cout<<"Overall earning of workers  is Rs"<<sum;
              exit(0);
    }
};

int main()
{
    user obj;
    workerAccount obj1;
    admin obj2;
    int choice;
    system("cls");
    system("color 90");
    cout << endl
         << "\t\t\t-----------------------------------------------------";
    cout << endl
         << "\t\t\t\t           WELCOME TO KAMKAAJ";
    cout << endl
         << "\t\t\t-----------------------------------------------------";
    system("pause");

    cout << "1- Customer" << endl;
    cout << "2- Worker" << endl;
    cout << "3- Admin" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        obj.start();
        obj.info();
        break;
    case 2:
        obj1.start1();
        break;
    case 3:
        obj2.startadmin();
    }
}