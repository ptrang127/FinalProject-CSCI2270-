# FinalProject-CSCI2270-

/* Michael Shulkin (working alone)
  TA: Madhu, Section: 314 (Thurs. 5 pm)
*/

/*  ==HOW TO RUN==

Open the files main.cpp, calendar.h, and calendar.cpp. Activate GNU compiler with c++11. Run the program. Below is a list of functions and how to use them. For each of the functions, input the associated integer when the main menu appears to activate the function.
  1. Scheduling an event
  -Enter a 1 to schedule add an event
  -Enter a day in May by inputting an integer between 1 and 31
  -Enter a time of day in 24-hour time (e.g. 14 = 2pm) by inputting an integer between 0 and 23
  -Enter an event title by inputting a string
  -A confirmation message will appear and bring you back to the menu
  **Scheduling conflicts**
  -Follow the above instructions for entering an event
  -Create another event at the same day and time as the first one
  -An error message will occur, showing what times are taken on that specific day
  -Input either:
    a) A time that is not taken (an integer between 0 and 23)
    b) The integer -1 to cancel the process and take you back to the menu
  -Inputting a taken time or a number x outside 0<x<23 will prompt you to reinput the number
  2. Delete an event 
  *Note* An event must have been created for this to work
  -Enter the day of the event by inputting the number of the day for the event (between 1 and 31)
  -Enter the time of the event by inputting the number of the time for the event (between 0 and 23)
  -If an event is found, a confirmation message will be displayed.
  -If not, a message will tell you the "event does not exist".
  3. Check Availability
  -Enter a day in May by inputting an integer between 1 and 31
  -Enter a time of day in 24-hour time (e.g. 14 = 2pm) by inputting an integer between 0 and 23
  -If there is an event at this day and time, a message will be displayed containing the information about the event.
  -If there is no event, a message will be displayed saying "this time is free."
  4. View a certain day's schedule
  -Enter a day in May by inputting an integer between 1 and 31
  -If there are events scheduled on this day, they will be displayed in chronological order
  -If not, a message will be displayed telling you so.
  5. View all events on a certain day of the week
  -Enter a string containing exactly the day of the week wish to search for (e.g. Monday, Tuesday...)
  -If there are events, they will be displayed
  -If not, a message will be displayed telling you so
  6. Check whole month's schedule
  -This function will simply print all events in chronological order
  7. Delete whole month's schedule
  -This function will delete all events on all days.
  -It doesn't print anything, so use the previous function to check the whole month's schedule
  8. Quit
  -Ends the program

*/

/*   ==ABOUT==

  Update: 4/27/16

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
