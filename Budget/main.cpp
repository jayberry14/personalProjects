/************************************************************************************************************
 * Name: Josh Mayberry
 * Project: Budget Calculator
 * 
 * Description: This project was a personal choice of mine for my wife and I when we got married. I knew I
 *              needed to watch my spending and she wanted to watch hers also, so I wrote this program to
 *              show us how much money we would have left over each year depending on how much we started out
 *              with. It's very interactive and has several parts that were difficult to manage and figure
 *              out, but it was altogether a fun personal project
 * 
 * Skills: Object Oriented design, passing parameters by reference, interactions between pointers and
 *         constructors, translation from Java to C++
 * 
 * *********************************************************************************************************/


#include <iostream>
#include "BudgetUser.h"

using namespace std;
long rentQuery(BudgetUser & budgetUser) {
    long monthlyRent;

    cout << ("Enter your estimated expense on rent for one month: \n");
    cin >> monthlyRent;
    long yearlyRent = monthlyRent * 12;
    budgetUser.setRent(yearlyRent);

    return yearlyRent;
}

long foodQuery(BudgetUser & budgetUser) {
    long totalFood;
    long monthlyGroceries;
    long monthlyRestaurant;

    cout << ("Enter your estimated expense on groceries for one month: \n");
    cin >> monthlyGroceries;
    long yearlyGroceries = monthlyGroceries * 12;
    budgetUser.setGroceries(yearlyGroceries);

    cout << ("Enter your estimated expense on going out to eat for one month: \n");
    cin >> monthlyRestaurant;
    long yearlyRestaurant = monthlyRestaurant * 12;
    budgetUser.setOutToEat(yearlyRestaurant);

    totalFood = yearlyRestaurant + yearlyGroceries;
    return totalFood;
}

long travelQuery(BudgetUser & budgetUser) {
    long travel;
    long monthlyGas;
    long yearlyFlights;

    cout << ("Enter your estimated expense on gas for one month: \n");
    cin >> monthlyGas;
    long yearlyGas = monthlyGas * 12;
    budgetUser.setGas(yearlyGas);

    cout << ("Enter your estimated expense on flights for the year: \n");
    cin >> yearlyFlights;
    budgetUser.setFlights(yearlyFlights);

    travel = yearlyGas + yearlyFlights;
    return travel;
}


long subscriptionQuery(BudgetUser & budgetUser) {
    long monthlySubs;

    cout << ("Enter your estimated expense for subscriptions for one month: \n");
    cin >> monthlySubs;
    long yearlySubs = monthlySubs * 12;
    budgetUser.setSubscriptions(yearlySubs);

    return yearlySubs;
}

long insuranceQuery(BudgetUser & budgetUser) {
    long insurance;
    long monthlyCar;
    long monthlyHealth;
    long monthlyLife;

    cout << ("Enter your estimated car insurance payment for one month: \n");
    cin >> monthlyCar;
    long yearlyCar = monthlyCar * 12;
    budgetUser.setAutoInsurance(yearlyCar);

    cout << ("Enter your estimated health insurance payment for one month: \n");
    cin >> monthlyHealth;
    long yearlyHealth = monthlyHealth * 12;
    budgetUser.setHealthInsurance(yearlyHealth);

    cout << ("Enter your estimated life insurance payment for the year: \n");
    cin >> monthlyLife;
    long yearlyLife = monthlyLife;
    budgetUser.setLifeInsurance(yearlyLife);

    insurance = yearlyCar + yearlyHealth + yearlyLife;
    return insurance;
}

void displayExpenses(BudgetUser budgetUser) {
    long totalExpenses = budgetUser.getTotalExpenses();
    long income = budgetUser.getIncome();
    long rentExpense = budgetUser.getRent();
    long travelExpense = budgetUser.getFlights() + budgetUser.getGas();
    long foodExpense = budgetUser.getGroceries() + budgetUser.getOutToEat();
    long subExpense = budgetUser.getSubscriptions();
    long insuranceExpense = budgetUser.getAutoInsurance() + budgetUser.getHealthInsurance() + budgetUser.getLifeInsurance();
    cout << "Your current yearly income is $" << income << endl;
    cout << "Your current rent is $" << rentExpense << endl;
    cout << "Your current travel expenses are $" << travelExpense << endl;
    cout << "Your current food expenses are $" << foodExpense << endl;
    cout << "Your current subscription expense is $" << subExpense << endl;
    cout << "Your current insurance expense is $" << insuranceExpense << endl;
    cout << "Your current expenses in total is $" << totalExpenses << endl;
    cout << "Your current funds to use is $" << income - totalExpenses << endl;
}

int main() {
    cout << "Let's make a budget!" << endl;
    cout << "Enter your estimated yearly income: " << endl;

    long income;
    cin >> income;
    BudgetUser budgetUser = BudgetUser(income);

    long rent = 0;
    long food = 0;
    long travel = 0;
    long subscriptions = 0;
    long insurance = 0;


    char input;
    bool done = false;
    while (!done){
        cout << "Options:                                    \n" <<
                "Add rent,                            << R >>\n" <<
                "Add food expenses,                   << F >>\n" <<
                "Add travel expenses,                 << T >>\n" <<
                "Add subscriptions,                   << S >>\n" <<
                "Add insurance payments,              << I >>\n" <<
                "Display current budget w/o quitting, << D >>\n" <<
                "Finish budget and show results,      << Q >>\n" << endl;
        
        cout << "So far, you've accumulated $" << budgetUser.getTotalExpenses() << " in expenses." << endl << endl;

        cin >> input;
        switch (toupper(input)){
            case 'D':
                displayExpenses(budgetUser);
                break;

            case 'F':
                food = foodQuery(budgetUser);
                budgetUser.addToExpenses(food);
                break;

            case 'I':
                insurance = insuranceQuery(budgetUser);
                budgetUser.addToExpenses(insurance);
                break;

            case 'Q':
                displayExpenses(budgetUser);
                done = true;
                break;

            case 'R':
                rent = rentQuery(budgetUser);
                budgetUser.addToExpenses(rent);
                break;

            case 'S':
                subscriptions = subscriptionQuery(budgetUser);
                budgetUser.addToExpenses(subscriptions);
                break;

            case 'T':
                travel = travelQuery(budgetUser);
                budgetUser.addToExpenses(travel);
                break;

            default:
                cout << "Please enter a valid command" << endl;
        }
    }
    return 0;
}