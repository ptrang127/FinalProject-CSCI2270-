#include <iostream>
#include <string>
#include "Calendar.h"

using namespace std;

int main()
{
    //Building calendar
    Calendar c;
    c.buildCalendar();

    //Menu variables
    bool Menu = true;
    int choice;


    while(Menu){
            cout << "======Main Menu======" << endl;
            cout << "1. Schedule an event" << endl;
            cout << "2. Delete an event" << endl;
            cout << "3. Check availability" << endl;
            cout << "4. View a certain day's schedule" << endl;  //pick a certain day, then see schedule for that
            cout << "5. View all events on a certain day of the week" << endl;
            cout << "6. Check whole month's schedule" << endl; //print all events
            cout << "7. Delete whole month's schedule" << endl;
            cout << "8. Edit an event" << endl;
            cout << "9. Quit" << endl;
            //cin>>choice;
            while (!(cin>>choice) || choice < 1 || choice > 8){
                cout << "Please choose one of the options listed: " << endl;
                cin.clear();
                cin.ignore(100,'\n');
            }
            //cin.ignore(100, '\n');
            switch(choice){
                case 1:  //add event
                    {
                    string title;
                    int time, day;

                    cout<< "When would you like your event?"<<endl;

                    cout << "Enter day (integer between 1 and 31): ";
                    while (!(cin>>day) || day < 1 || day > 31){
                        cout<<"Error - Please enter an integer between 1 and 31: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }

                    cout << "Enter time (integer between 0 and 23): ";
                    while (!(cin>>time) || time < 0 || time > 23){
                        cout<<"Error - Please enter an integer between 0 and 23: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    cin.ignore(100,'\n');

                    cout <<"What would you like your event to be called?"<<endl;
                    cout << "Enter title: ";
                    getline(cin,title);
                    cout<<endl;

                    c.addEvent(title, time, day);
                    }
                    break;
                case 2:  //delete event
                    {
                    int time, day;
                    cout << "Enter day (integer between 1 and 31): ";
                    while (!(cin>>day) || day < 1 || day > 31){
                        cout<<"Error - Please enter an integer between 1 and 31: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }

                    cout << "Enter time (integer between 0 and 23): ";
                    while (!(cin>>time) || time < 0 || time > 23){
                        cout<<"Error - Please enter an integer between 0 and 23: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }

                    c.deleteEvent(time,day);
                    }
                    break;
                case 3:  //find movie
                    {
                    int time, day;
                    cout << "Enter day (integer between 1 and 31): ";
                    while (!(cin>>day) || day < 1 || day > 31){
                        cout<<"Error - Please enter an integer between 1 and 31: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }

                    cout << "Enter time (integer between 0 and 23): ";
                    while (!(cin>>time) || time < 0 || time > 23){
                        cout<<"Error - Please enter an integer between 0 and 23: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }

                    c.checkAvailability(time, day);
                    }
                    break;
                case 4:  //print schedule for day
                    {
                    int day;
                    cout << "Enter day (integer between 1 and 31): ";
                    while (!(cin>>day) || day < 1 || day > 31){
                        cout<<"Error - Please enter an integer between 1 and 31: ";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    c.printDay(day);
                    }
                    break;
                case 5:
                    {
                        string name;
                        cout << "Enter day of the week (e.g. Monday, Tuesday...): ";
                        cin>>name;
                        while (name != "Monday" && name != "Tuesday" && name != "Wedneday" && name != "Thursday" && name != "Friday" && name != "Saturday" && name != "Sunday"){
                            cin.clear();
                            cin.ignore(100, '\n');
                            cout<<"Error - Please enter a day of the week: ";
                            cin>>name;
                        }
                        c.certainDay(name);
                    }
                    break;
                case 6: // print entire month schedule
                    c.printCalendar();
                    break;
                case 7:
                    c.deleteAll();
                    break;
                case 8:
                    int day;
                    int time;
                    cout << "Enter the day of the event you want to edit:" << endl;
                    cin >> day;
                    cout << "Enter the time of the event you want to edit:" << endl;
                    cin >> time;
                    c.editEventName(day, time);
                    break;
                case 9:  //quit
                    Menu = false;
                    cout<<"Goodbye!"<<endl;
                    break;
                default:
                    cout<<"Please choose one of the options listed."<<endl;
                    break;
            }
        }
    return 0;
}
