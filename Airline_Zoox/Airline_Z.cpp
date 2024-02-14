// Airline_Zoox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct operatingCostParam 
{
    double baseOperatingCost;
    double perMileCost;
};
struct operatingCost 
{
    unordered_map<string, operatingCostParam> opCostVals;
    operatingCost(vector < vector<string>> operatingCostInitData) 
    {
        for (auto costdata : operatingCostInitData) 
        {
            string ticketClass = costdata[0];
            string basecost = costdata[1];
            string perMileCost = costdata[2];
            opCostVals[ticketClass] = { stod(basecost), stod(perMileCost) };
        }
    }
    double getCost(double mileage, string ticketClass) 
    {
        return opCostVals[ticketClass].baseOperatingCost
            + opCostVals[ticketClass].perMileCost * mileage;
    }
};
struct Ticket 
{
    string ticketclass;
    operatingCost ocost;
    Ticket(string ticketclass, operatingCost ocost) : ticketclass(ticketclass), ocost(ocost) {}
    virtual double getTicketPrice() = 0;
};
struct AmericanAirlinesTicket :Ticket 
{
    string ticketClass;
    double mileage;
    AmericanAirlinesTicket(string ticketClass, string mileage, operatingCost ocost) :
        ticketClass(ticketClass), mileage(stod(mileage)), Ticket(ticketClass, ocost) {}
    double getTicketPrice() 
    {
        double operatingCost = ocost.getCost(mileage, ticketClass);
        return mileage + operatingCost;
    }
};
struct RyanAirTicket :Ticket 
{
    string ticketClass;
    double mileage;
    RyanAirTicket(string ticketClass, string mileage, operatingCost ocost) :
        ticketClass(ticketClass), mileage(stod(mileage)), Ticket(ticketClass, ocost) {}
    double getTicketPrice() 
    {
        double operatingCost = ocost.getCost(mileage, ticketClass);
        return max(1.5 * mileage, 2 * operatingCost);
    }
};

struct TicketFactory 
{
    operatingCost ocost;
    TicketFactory(vector < vector<string>> operatingCostInitData) : ocost(operatingCostInitData) {}
    Ticket* createTicket(string airline, string ticketClass, string mileage) 
    {
        if (airline == "RyanAir") {
            return new RyanAirTicket(ticketClass, mileage, ocost);
        }
        else if (airline == "American") {
            return new AmericanAirlinesTicket(ticketClass, mileage, ocost);
        }
    }
};
int main()
{
    vector <vector<string>> operatingCostInitData = {   {"Economy", "50.0", ".05"},
                                                        {"Business", "100.0", ".15"}, 
                                                        {"FirstClass", "150.0", ".25"} };
    vector<vector<string>> tickets = {  {"American", "Economy", "120.0"}, 
                                        {"RyanAir", "Business", "100.0"} };
    TicketFactory ticketFactory(operatingCostInitData);
    for (auto ticket : tickets) 
    {
        string airlineName = ticket[0];
        string ticketClass = ticket[1];
        string mileage = ticket[2];

        cout << airlineName << " " << ticketClass << " " << ticketFactory.createTicket(airlineName, ticketClass, mileage)->getTicketPrice() << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
