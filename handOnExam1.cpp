/*=====================================================================================================
Design a program to calculate the parking fee based on the parking time (in minutes) input by the
user. The rate of parking fee is 20 NT dollars per 30 minutes. One minute to 30 minutes are
considered as a 30-minute unit for 20 NT dollars. Parking time no more than 30 minute is free of
charge. The maximum parking fee for a whole day is 240 NT dollars. The input of this program is
the parking time in minutes from 1 to 2000 minutes. The output of the program is the parking fee.
For example: parking time of 20 minutes is free; 30 minutes is free; 31 minutes is 40 NT dollars;
90 minutes is 60 NT dollars; 1440 minutes is 240 NT dollars; 1441 minutes is 260 NT dollars.
=====================================================================================================*/
#include <iostream>

using namespace std;

int main(){
    int parkingTime;
    int parkingFee = 0;
    cout << "Please enter the parking time : ";
    cin >> parkingTime;
    if(parkingTime > 30){
        if(parkingTime <= 1440){
            parkingTime = (parkingTime - 31)/30;
            parkingFee = parkingTime * 20 + 40;
            if(parkingFee >= 240) parkingFee = 240;
        }
        if(parkingTime > 1440){
            parkingTime = (parkingTime - 1441)/30;
            parkingFee = parkingTime * 20 + 260;
            if(parkingFee >= 480) parkingFee = 480;
        }
    }
    cout << "The Parking Fee is : " << parkingFee << endl;

    return 0;
}