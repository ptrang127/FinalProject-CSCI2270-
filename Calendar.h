#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>
#include <vector>

struct linkedList{
	std::string title;
	int time;
	linkedList *next;
    linkedList *previous;

	linkedList(){};
	linkedList(std::string in_title, int in_time)  //this is a function that initializes things for you
	{
		title = in_title;
		time = in_time;
		next = NULL;
		previous = NULL;
	}

};

struct daysArr{
    int num;  //what day it is
    std::string name; //Monday, Tuesday...
    linkedList *toHead; //head of the linked list

    daysArr(){};
    daysArr(std::string n, int x){
        name = n;
        num = x;
    }
};

class Calendar
{
	public:
		Calendar();
		~Calendar();
		void buildCalendar();  //initializes calendar
		void printDay(int day);  //print single day calendar
		void printCalendar(); //print whole month calendar
		void addEvent(std::string title, int time, int day);  //adds events
		void deleteEvent(int time, int day); //deletes event
		bool checkAvailability(int time, int day); //check if event exists at certain day/time
		void deleteAll(); //deletes entire calendar
		int countEvents(int day); // counts events in a day
		int recommendTime(int day);
		void certainDay(std::string name);
	private:
		daysArr* days[31];
};

#endif

