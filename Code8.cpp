#include <iostream>
#include <string>
using namespace std;

class Performance 
{
private:
    string time;
    int totalSeats;
    int bookedSeats;

public:
    Performance(string showTime, int seats = 50) 
{
        time = showTime;
        totalSeats = seats;
        bookedSeats = 0;
    }

    bool bookSeats(int seats) 
{
        if (bookedSeats + seats <= totalSeats) 
        {
            bookedSeats += seats;
            return true;
        } 
        else 
        {
            return false;
        }
    }

    int getAvailableSeats() const 
{
        return totalSeats - bookedSeats;
    }

    string getTime() const 
{
        return time;
    }

    void displayStatus() const 
{
        cout << "Performance at " << time << " - Available seats: " << getAvailableSeats() << endl;
    }
};

int main() 
{
    // Initialize performances
    Performance afternoon("1:00 PM");
    Performance evening("5:00 PM");
    Performance mainShow("8:30 PM");

    int choice, seats;

    while (true) 
    {
        cout << "\n--- Cinema Booking System ---\n";
        cout << "1. Book seats for 1:00 PM\n";
        cout << "2. Book seats for 5:00 PM\n";
        cout << "3. Book seats for 8:30 PM\n";
        cout << "4. Check available seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
        case 2:
        case 3: {
            cout << "Enter number of seats to book: ";
            cin >> seats;
            Performance* selectedShow;
            if (choice == 1) selectedShow = &afternoon;
            else if (choice == 2) selectedShow = &evening;
            else selectedShow = &mainShow;

            if (selectedShow->bookSeats(seats)) 
            {
                cout << "Booking successful for " << selectedShow->getTime() << "!\n";
            } 
            else 
            {
                cout << "Not enough seats available for " << selectedShow->getTime() << ".\n";
            }
            break;
        }
        case 4:
            cout << "\n--- Available Seats ---\n";
            afternoon.displayStatus();
            evening.displayStatus();
            mainShow.displayStatus();
            break;
        case 5:
            cout << "Thank you for using the Cinema Booking System. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
