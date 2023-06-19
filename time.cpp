/*
Author: Darren Moy
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 10

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Time
{ // storing 24H format HH:MM
public:
    int h;
    int m;
};

enum Genre
{
    ACTION,
    COMEDY,
    DRAMA,
    ROMANCE,
    THRILLER
};

class Movie
{
public:
    string title;
    Genre genre;  // only one genre per movie
    int duration; // in minutes
};

class TimeSlot
{
public:
    Movie movie;    // what movie (also includes title, genre and duration)
    Time startTime; // when it starts (hh:mm)
};

int minutesSinceMidnight(Time time)         //since midnight is 0h,0m you can just multiply hours by 60 minutes and add minutes 
{
    return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later)      //take the greater number of minutesSinceMidnight and subtract the earlier time otherwise it will be negative 
{
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min)        //add minutes to a given time 
{
    int hours = time0.h + min / 60;         //original time hours + new minutes / 60, results in new hours 
    int thours = min % 60;                  //remainder of minutes 
    min = time0.m + thours;                 //original time minutes + remainder minutes after new hours have been set 
    if (min >= 60)
    {
        hours += (min / 60);                //if there are more than 60 mins, add more hours    
        min = min - 60;                     //subtract an hour from the minutes 
    }
    if (hours == 24)
    {
        hours = 0;                          //set hours to 0 if equals 24, new day 
    }
    time0.h = hours;                        //new hours set 
    time0.m = min;                          //new mins set 
    return time0;                           //return new time 
}

void printTimeSlot(TimeSlot ts)                                 //takes in input of type TimeSlot 
{
    Movie movi = ts.movie;                                      //sets var movi of type Movie to ts.movie, holds movie associated with time slot 
    Time whenstart = ts.startTime;                              //sets whenstart equal to when the movie starts 
    Time whenend = addMinutes(whenstart, movi.duration);        //sets whenend to the time that the movie ends (calculated by adding movie duration to when the movie starts)
    string g;       
    switch (movi.genre)                                         //based on the genre of the movie, returns out what genre it is 
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }

    cout << movi.title << " " << g << " (" << movi.duration << " min) "<< "[starts at " << whenstart.h << ":" << whenstart.m << ", ends by " << whenend.h << ":" << whenend.m << "]\n";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){                           //takes in timeslot and the next movie 
    TimeSlot newTs;                                                             //newTimeSlot variable for new movie 
    Movie oldmovie = ts.movie;                                                  //new var old movie (of Movie type) set to the movie associated with given time slot
    Time whenend = addMinutes(ts.startTime, oldmovie.duration);                 //finding out when the old movie ends
    newTs.movie = nextMovie;                                                    //setting new timeslot movie to the given next movie 
    newTs.startTime = whenend;                                                  //new movie start time is when old movie ends
    return newTs;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){                                   //takes 2 timeslots 
    TimeSlot earlier, later;                                         

    if (0 < minutesUntil(ts1.startTime, ts2.startTime)){                        //determines which movie is later (early, later), 
        earlier = ts1;                                                          
        later = ts2;
    }
    else{
        earlier = ts2;
        later = ts1;
    }

    Movie earlymov = earlier.movie;                                             //set early mov to the movie that corresponds to the early timeslot 
    Movie latermov = later.movie;

    if (earlymov.duration > minutesUntil(earlier.startTime, later.startTime)){      //if the duration of the early movie is greater than the time between duration
        return true;                                                                //between the earlier movie startTime and the later movie startTime then 
    }                                                                               //the movies do overlap 

    else{
        return false;
    }

}
