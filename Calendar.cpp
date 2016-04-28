#include "Calendar.h"
#include <iostream>
#include <vector>

using namespace std;

Calendar::Calendar(){ // constructor
}


Calendar::~Calendar(){ // destructor
}

void Calendar::buildCalendar(){
    string names[31] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    for (int i = 0; i<31; i++){
        days[i] = new daysArr(names[i],i+1);
        linkedList *head = new linkedList("Head", -1);
        days[i]->toHead = head;
    }
}

int Calendar::recommendTime(int day){
    linkedList *current = days[day-1]->toHead->next;
    vector<int> vec;
    while (current != NULL){
        vec.push_back(current->time);
        current = current->next;
    }
    cout<<"All of the following times are taken: ";
    for (int i = 0; i<vec.size(); i++){
        if (i == vec.size()-1){
            cout<<vec[i]<<" o'clock";
            break;
        }
        cout<<vec[i]<<" o'clock, ";
    }
    cout<<endl<<"Please enter a time that is not taken, or enter -1 to cancel."<<endl;
    int t;
    while (!(cin>>t) || t < 0 || t > 23){
        cout<<"Error - Please enter an integer between 0 and 23 that is not on taken or -1 to cancel."<<endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    //cin >> t;
    //cin.ignore(100, '\n');
    for (int i = 0; i<vec.size(); i++){
        if (t == vec[i]){
            cout<<"Time already taken."<<endl;
            t = -2;
            break;
        }
    }
    while (t < 0 || t > 23){
        if (t == -1){
            return t;
        }
        cout<<"Error - Please enter an integer between 0 and 23 that is not on taken or -1 to cancel."<<endl;
        while (!(cin>>t) || t < 0 || t > 23){
            cout<<"Error - Please enter an integer between 0 and 23 that is not on taken or -1 to cancel."<<endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        for (int i = 0; i<vec.size(); i++){
            if (t == vec[i]){
                cout<<"Time already taken."<<endl;
                t = -2;
                break;
            }
        }
    }
    return t;
}

void Calendar::addEvent(std::string title, int time, int day){
    if (!checkAvailability(time, day)){
        time = recommendTime(day);
        if (time == -1){
            cout<<"Event adding canceled."<<endl;
            return;
        }
    }

    linkedList *head = days[day-1]->toHead;
    linkedList *node = new linkedList(title, time);
    linkedList *current = head;

    if (head->next == NULL){
        node->previous = head;
        head->next = node;
    }
    else{
        linkedList *temp = head;
        while (temp->next != NULL){
            if (node->time < temp->next->time){
                break;
            }
                //cout<<node->time<< "  "<<temp->next->time;
            temp = temp->next;  //going until temp is the tail of the list
        }
        if (temp->next == NULL){  // if we're at the end
            temp->next = node;
            node->previous = temp;
        }
        else{  //if we're in the middle of the list
            temp->next->previous = node;
            node->next = temp->next;
            temp->next = node;
            node->previous = temp;
        }
    }

    cout<<"Event Added: "<<endl;
    cout<<"Day: " << days[day-1]->name << " May " << day << endl;
    cout<<"Time: " << time << " o'clock" << endl;
    cout<<"Title: " <<  title << endl << endl;
}

void Calendar::printDay(int day){
    linkedList *current = days[day-1]->toHead->next;
    if (current == NULL){
        cout<<"There is nothing scheduled for today."<<endl;
    }
    else{
        cout<<"On " << days[day-1]->name << " May " << days[day-1]->num << ", the schedule is:" << endl;
        while (current != NULL){
            cout<<"Time: "<< current->time << " Title: " << current->title<<endl;
            current = current->next;
        }
    }
}

void Calendar::printCalendar(){
    bool empty = true;
    for (int i = 0; i<31; i++){
        linkedList *current = days[i]->toHead->next;
        if (current != NULL){
            empty = false;
            cout<<"On " << days[i]->name << " May " << days[i]->num << ", the schedule is:" << endl;
            while (current != NULL){
                cout<<"Time: "<< current->time << " Title: " << current->title<<endl;
                current = current->next;
            }
            cout<<endl;
        }
    }
    if (empty){ // if we found nothing
        cout<<"There is nothing scheduled this month."<<endl;
    }
}

bool Calendar::checkAvailability(int time, int day){
    linkedList *current = days[day-1]->toHead->next;
    while (current != NULL){
        if (current->time == time){
            cout<<"There is already an event scheduled at this time. The event's name is: " << current->title << endl;
            return false;
            break;
        }
        current = current->next;
    }
    cout<<"This time is free."<<endl;
    return true;
}

void Calendar::deleteEvent(int time, int day){
    bool found = false; //return if event not found
    linkedList *current = days[day-1]->toHead->next;
    while (current != NULL){
        if (current->time == time){
            if (current->next == NULL){
                current->previous->next = NULL;
                    cout<<"Event deleted: "<<endl;
                    cout<<"Day: " << days[day-1]->name << " May " << day << endl;
                    cout<<"Time: " << current->time << " o'clock" << endl;
                    cout<<"Title: " <<  current->title << endl << endl;
                return;
            }
            current->previous->next = current->next;
            current->next->previous = current->previous;
            cout<<"Event deleted: "<<endl;
            cout<<"Day: " << days[day-1]->name << " May " << day << endl;
            cout<<"Time: " << current->time << " o'clock" << endl;
            cout<<"Title: " <<  current->title << endl << endl;
            return;
        }
        current = current->next;
    }
    cout << "Event does not exist." << endl;
}

int Calendar::countEvents(int day){
    int counter = 0;
    linkedList *current = days[day]->toHead->next;
    while (current != NULL){
        counter++;
        current = current->next;
    }
    return counter;
}

void Calendar::deleteAll(){
    int numEvents;
    for (int i = 0; i<31; i++){  //for each of the days
        numEvents = countEvents(i);  //find how many days there are
        for (int j = 0; j<numEvents; j++){ //run the delete function for the amount of events in the day
            linkedList *current = days[i]->toHead->next;
            while (current != NULL){
                if (current->next == NULL){
                    current->previous->next = NULL;
                    break;
                }
                current->previous->next = current->next;
                current->next->previous = current->previous;
                break;
                current = current->next;
            }
        }
    }
}

void Calendar::certainDay(string name){
    vector<int> dayInd;
    bool empty = true;
    for (int i = 0; i<31; i++){
        if (days[i]->name == name){
            dayInd.push_back(i+1);
        }
    }
    for (int i = 0; i<dayInd.size(); i++){
        linkedList *current = days[dayInd[i]-1]->toHead->next;

        if (current != NULL){
            empty = false;
            cout<<"On " << days[dayInd[i]-1]->name << " May " << days[dayInd[i]-1]->num << ", the schedule is:" << endl;
            while (current != NULL){
                cout<<"Time: "<< current->time << " Title: " << current->title<<endl;
                current = current->next;
            }
            cout<<endl;
        }
    }
    if (empty){ // if we found nothing
        cout<<"There is nothing scheduled on "<< name << "." <<endl;
    }
}

