#pragma once
#include<iostream>
using namespace std;
/**
* @author  Aiden Cornstubble
* @version 1.6
* @date last edited   10-6-2018
*/

//MoveRequest Class
class MoveRequest
{
private:
	//variable declaration for the floor and the weight integer
	int floor, people;
	//variable declaration for the pickup boolean
	bool pickup;
	//variable declaration for the time initiated
	double timeStarted = 0;
public:
	/*
	* The default constructor for the MoveRequest Class
	*/
	MoveRequest()
	{
		//sets floor to 1
		floor = 1;
		//sets the people to 1
		people = 1;
		//sets pickup to true
		pickup = true;
	}

	/*
	* The standard constructor for the MoveRequest Class
	* @param fl used to pass in the current floor
	* @param pe used to pass in the current amount of people
	* @param pi used to pass in if the move request was revieved from outside of the elevator or not
	*/
	MoveRequest(int fl, int pe, bool pi)
	{
		//sets floor to fl
		floor = fl;
		//sets the weight to we
		people = pe;
		//sets pickup to pi
		pickup = pi;
	}

	/* Floor
	* @return int
	* returns the floor variable
	*/
	int Floor()
	{
		return floor;
	}

	/* Weight
	* @return int
	* returns the people variable
	*/
	int People()
	{
		return people;
	}

	/* Pickup
	* @return bool
	* returns the pickup variable
	*/
	bool Pickup()
	{
		return pickup;
	}

	/* TimeStarted
	* @return double
	* returns the timeStarted variable
	*/
	double TimeStarted()
	{
		return timeStarted;
	}

	/* TimeStarted
	* @return void
	* @param t used to pass in the time started
	* returns the timeStarted variable
	*/
	void TimeStarted(double t)
	{
		timeStarted = t;
	}
};
