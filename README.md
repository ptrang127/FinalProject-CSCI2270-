# FinalProject-CSCI2270-

/* Michael Shulkin (working alone)
  TA: Madhu, Section: 314 (Thurs. 5 pm)
*/

/* Update: 4/27/16

  The initial code for my calendar is complete. Instead of being a yearly calendar, I implemented a calendar strictly for the month of may. The calendar no longer uses hash tables but rather arrays because the hash function was found to be irrelevant. The calendar still uses linked lists to store the meetings each day chronologically.
  
  The 10 public methods are:
1. void buildCalendar();  //initializes calendar
2. void printDay(int day);  //print single day calendar
3. void printCalendar(); //print whole month calendar
4. void addEvent(std::string title, int time, int day);  //adds events
5. void deleteEvent(int time, int day); //deletes event
6. bool checkAvailability(int time, int day); //check if event exists at certain day/time
7. void deleteAll(); //deletes entire calendar
8. int countEvents(int day); // counts events in a day
9. int recommendTime(int day); //recommends times for a meeting when attempting to schedule an already planned time
10. void certainDay(std::string name); //finds all meetings on a certain day (i.e. all meetings on Monday, etc...)

-------
Initial Post:

For my final project, I will be creating a calendar. This calendar will be for the year of 2016 and can be used to schedule meetings and events at different times throughout each day. The calendar will be made using a hash table and will use linked lists to resolve collisions. The hash function will return a specific day in the year and the linked list will store items chronologically (i.e. if on May 17 there is a meeting scheduled at 11am to 12pm, a new meeting from 9am to 10 am will be inserted before the 11am meeting in the linked list).

Other features include:
-Ability to store date, time, short description, and place of meeting
-Some major holidays will be stored (read in through a text file in the constructor) and a message will occur if a meeting is being scheduled on a holiday
-Scheduling conflicts will be notified (and maybe an alternative time will be suggested?)

Suggestions are welcome for additional ideas!

*/
