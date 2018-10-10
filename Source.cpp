/**
* @author Aiden Cornstubble & Alexa Summers
* @version 1.5
* @date last edited  10-9-2018
*/

#include<iostream>
#include"Header.h"
#include <cstdlib>
using namespace std;

void MultipleElevators(int eleNum, int numRuns, int eleMaxCap, int startFloor, int highestFloor, bool goingUp) //the function to have multiple elevators
{
    Elevator ele[5]; //creating an elevator array to determine how many elevators there are
    if (eleNum > 5 || eleNum <= 20) //if the number of elevators is greater than 5 or less than/equal to 20
        ele[20]; //make the elevator array size 20
    else //if the number of elevators is anything else
        ele[100]; //make the elevator array size 100
    for (int i = 0; i < eleNum; i++) //for whatever number of elevators from ele[] to i
    {
        ele[i] = Elevator(startFloor, goingUp, highestFloor, 0, eleMaxCap); //tells howeveer many elevators there are what to do
    }
    srand(NULL); //random generator at null
    for (int x = 0; x < numRuns; x++) //for the number of runs less than x
    {
        int rd = rand() % 6; //random number of drop requests
        for (int y = 0; y < rd; y++) //For the random number of drop requests, generate random floor information and height information.
        {
            int rf = (rand() % highestFloor) + 1; //random number of floors
            int rh = rand() % 2; //random height number
            bool up; //boolean true if up, false if down
            if (rh == 0) //if the height is not getting bigger, the elevator is not moving up
                up = false; //the elevator is not moving up
            else //if the height is getting bigger
                up = true; //the elevator is going up
            MoveRequest mov(rf, 1, true); //putting in a move request to the randomly generated floor
            int ind = 0, dist = highestFloor * 3, tempDist = 0; //gathering information about how far the elevator is travelling
            for (int z = 0; z < eleNum; z++) //for the elevator number being less than z
            {
                if (ele[z].GoingUp() == up) //if the elevator is moving up
                {
                    if (up) //if the elevator going up is true
                    {
                        if (ele[z].CurrFloor() <= rf) //if the current floor is less than or equal to the randomly generated floor
                            tempDist = rf - ele[z].CurrFloor(); //the distance for the elevator at the current index is equal the randomly generated floor - the current floor
                        else
                            tempDist = (highestFloor - ele[z].CurrFloor()) + highestFloor + rf; //else, the distance of the elevator at the current index is the highest floor of the building - the current floor + the highest floor + the randomly generated floor
                    }
                    else //if the elevator going up is false
                    {
                        tempDist = ele[z].CurrFloor() + rf; //else, the distance of the elevator at the current index is equal to the current floor + the randomly generated floor
                    }
                }
                else //if the elevator is not going up
                {
                    if (up) // if the elevator is moving up
                    {
                        tempDist = (highestFloor - ele[z].CurrFloor()) + (highestFloor - rf); //the distance of the elevator at the current index is equal the highest floor - the current floor + (the highest floor - the randomly generated floor)
                    }
                    else //if the elevator is going down
                    {
                        if (ele[z].CurrFloor() >= rf) //if the current floor is greater than or equal to the random floor,
                            tempDist = ele[z].CurrFloor() - rf; //the distance of the elevator at the current index is equal to the current floor - the random floor
                        else
                            tempDist = ele[z].CurrFloor() + highestFloor + rf; //else, the distance of the elevator at the current index will be the current floor + the highest floor + the randomly generated floor
                    }
                }
                
                if (tempDist < dist)     //if the distance of the elevator at the current index is less than the shortest distance recorded so far
                {
                    dist = tempDist; //replace the shortest recorded distance with the distance of the elevator at the current index
                    ind = z; //replace the index z with the index for the elevator with the shortest distance
                }
            }
            ele[ind].NewRequest(mov, rh); //sending the elevator closest to the new request to process the new request
            cout << "request given to elevator " << ind << endl; //outputting the closest elevator to the request that will be handling the request
        }
        for (int y = 0; y < eleNum; y++) //for the elevator number being less than y,
        {
            ele[y].UpdatePos(); //update the elevator's position
            if (ele[y].GoingUp()) //if the elevator is going up
                cout << "elevator at index " << y << " is at floor " << ele[y].CurrFloor() << " and is going up." << endl; //state the elevator is going up to whatever floor
            else //if the elevator is going down
                cout << "elevator at index " << y << " is at floor " << ele[y].CurrFloor() << " and is going down." << endl; //state the elevator is going down to whatever floor
            int temp = ele[y].NumDrops();
            for (int z = 0; z < temp; z++) //for as long as the number of drops is less than variable z
            {
                if (ele[y].GoingUp()) //if the elevator is going up
                {
                    int rf = (rand() % (highestFloor - ele[y].CurrFloor()) + 1 + ele[y].CurrFloor()); //generate a random floor above the current floor
                    ele[y].NewRequest(MoveRequest(rf, ele[y].CurrFloor(), false), true); //modify the new request with the going up movement information
                }
                else //if the elevator is going down
                {
                    int rf = rand() % ele[y].CurrFloor(); //generate a random number below the current floor
                    ele[y].NewRequest(MoveRequest(rf, ele[y].CurrFloor(), false), true); //modify the new request with the drop movement information
                }
            }
        }
    }
    for (int x = 0; x < eleNum; x++) //for as long as there are elevators still running
    {
        cout << "The average wait time for elevator " << x << " is " << ele[x].AveWaitTime() << " seconds" << endl; //display that information
    }
}void MultipleElevators(int eleNum, int numRuns, int eleMaxCap, int startFloor, int highestFloor, bool goingUp) //the function to have multiple elevators
{
    Elevator ele[5]; //creating an elevator array to determine how many elevators there are
    if (eleNum > 5 || eleNum <= 20) //if the number of elevators is greater than 5 or less than/equal to 20
        ele[20]; //make the elevator array size 20
    else //if the number of elevators is anything else
        ele[100]; //make the elevator array size 100
    for (int i = 0; i < eleNum; i++) //for whatever number of elevators from ele[] to i
    {
        ele[i] = Elevator(startFloor, goingUp, highestFloor, 0, eleMaxCap); //tells howeveer many elevators there are what to do
    }
    srand(NULL); //random generator at null
    for (int x = 0; x < numRuns; x++) //for the number of runs less than x
    {
        int rd = rand() % 6; //random number of drop requests
        for (int y = 0; y < rd; y++) //For the random number of drop requests, generate random floor information and height information.
        {
            int rf = (rand() % highestFloor) + 1; //random number of floors
            int rh = rand() % 2; //random height number
            bool up; //boolean true if up, false if down
            if (rh == 0) //if the height is not getting bigger, the elevator is not moving up
                up = false; //the elevator is not moving up
            else //if the height is getting bigger
                up = true; //the elevator is going up
            MoveRequest mov(rf, 1, true); //putting in a move request to the randomly generated floor
            int ind = 0, dist = highestFloor * 3, tempDist = 0; //gathering information about how far the elevator is travelling
            for (int z = 0; z < eleNum; z++) //for the elevator number being less than z
            {
                if (ele[z].GoingUp() == up) //if the elevator is moving up
                {
                    if (up) //if the elevator going up is true
                    {
                        if (ele[z].CurrFloor() <= rf) //if the current floor is less than or equal to the randomly generated floor
                            tempDist = rf - ele[z].CurrFloor(); //the distance for the elevator at the current index is equal the randomly generated floor - the current floor
                        else
                            tempDist = (highestFloor - ele[z].CurrFloor()) + highestFloor + rf; //else, the distance of the elevator at the current index is the highest floor of the building - the current floor + the highest floor + the randomly generated floor
                    }
                    else //if the elevator going up is false
                    {
                        tempDist = ele[z].CurrFloor() + rf; //else, the distance of the elevator at the current index is equal to the current floor + the randomly generated floor
                    }
                }
                else //if the elevator is not going up
                {
                    if (up) // if the elevator is moving up
                    {
                        tempDist = (highestFloor - ele[z].CurrFloor()) + (highestFloor - rf); //the distance of the elevator at the current index is equal the highest floor - the current floor + (the highest floor - the randomly generated floor)
                    }
                    else //if the elevator is going down
                    {
                        if (ele[z].CurrFloor() >= rf) //if the current floor is greater than or equal to the random floor,
                            tempDist = ele[z].CurrFloor() - rf; //the distance of the elevator at the current index is equal to the current floor - the random floor
                        else
                            tempDist = ele[z].CurrFloor() + highestFloor + rf; //else, the distance of the elevator at the current index will be the current floor + the highest floor + the randomly generated floor
                    }
                }
                
                if (tempDist < dist)     //if the distance of the elevator at the current index is less than the shortest distance recorded so far
                {
                    dist = tempDist; //replace the shortest recorded distance with the distance of the elevator at the current index
                    ind = z; //replace the index z with the index for the elevator with the shortest distance
                }
            }
            ele[ind].NewRequest(mov, rh); //sending the elevator closest to the new request to process the new request
            cout << "request given to elevator " << ind << endl; //outputting the closest elevator to the request that will be handling the request
        }
        for (int y = 0; y < eleNum; y++) //for the elevator number being less than y,
        {
            ele[y].UpdatePos(); //update the elevator's position
            if (ele[y].GoingUp()) //if the elevator is going up
                cout << "elevator at index " << y << " is at floor " << ele[y].CurrFloor() << " and is going up." << endl; //state the elevator is going up to whatever floor
            else //if the elevator is going down
                cout << "elevator at index " << y << " is at floor " << ele[y].CurrFloor() << " and is going down." << endl; //state the elevator is going down to whatever floor
            int temp = ele[y].NumDrops();
            for (int z = 0; z < temp; z++) //for as long as the number of drops is less than variable z
            {
                if (ele[y].GoingUp()) //if the elevator is going up
                {
                    int rf = (rand() % (highestFloor - ele[y].CurrFloor()) + 1 + ele[y].CurrFloor()); //generate a random floor above the current floor
                    ele[y].NewRequest(MoveRequest(rf, ele[y].CurrFloor(), false), true); //modify the new request with the going up movement information
                }
                else //if the elevator is going down
                {
                    int rf = rand() % ele[y].CurrFloor(); //generate a random number below the current floor
                    ele[y].NewRequest(MoveRequest(rf, ele[y].CurrFloor(), false), true); //modify the new request with the drop movement information
                }
            }
        }
    }
    for (int x = 0; x < eleNum; x++) //for as long as there are elevators still running
    {
        cout << "The average wait time for elevator " << x << " is " << ele[x].AveWaitTime() << " seconds" << endl; //display that information
    }
}

int main()
{
	//user input for testing purposes
	/*int elevatorNumber, runNumber, elevatorCapacity, startingFloor, highestFloor, up;
	bool goingUp;
	cout << "please enter the number of elevators, there cannot be more than 100 elevators: " << endl;
	cin >> elevatorNumber;
	cout << "please enter the number of times to run the simulation: " << endl;
	cin >> runNumber;
	cout << "please enter the maximum capacity of every elevator: " << endl;
	cin >> elevatorCapacity;
	cout << "please enter the starting floor for every elevator: " << endl;
	cin >> startingFloor;
	cout << "please enter the maximum floor for the elevators: " << endl;
	cin >> highestFloor;
	cout << "if the elevator is going up please enter one, otherwise, please enter 0: " << endl;
	cin >> up;
	if (up == 0)
		goingUp = false;
	else
		goingUp = true;
	MultipleElevators(elevatorNumber, runNumber, elevatorCapacity, startingFloor, highestFloor, goingUp);*/


	MultipleElevators(3, 20, 20, 1, 10, true); //running the function for multiple elevators (this can be changed based on how many elevators you want)
	cout << "Press 'enter' to exit. " << endl; //tells the user how to end the program
	cin.get(); //ends program upon pressing "enter"
}
