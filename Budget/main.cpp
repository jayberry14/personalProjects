#include <iostream>
#include <string>
#include <BudgetUser.h>

using namespace std;

int foodQuery(BudgetUser budgetUser) {
    int food;
    int groceries;
    int monthlyFood;
    int restaraunt;
    int monthlyRestaurant;

    cout << ("Enter your estimated expense on groceries for one month: \n");
    cin >> monthlyFood;
    budgetUser.setGroceries(monthlyFood);
    int yearlyFood = budgetUser.getGroceries() * 12;
    budgetUser.setGroceries(yearlyFood);
    groceries = (int) budgetUser.addToExpenses(yearlyFood);

    cout << ("Enter your estimated expense on going out to eat for one month: \n");
    cin >> monthlyRestaurant;
    budgetUser.setOutToEat(monthlyRestaurant);
    int yearlyRestaurant = budgetUser.getOutToEat() * 12;
    budgetUser.setOutToEat(yearlyRestaurant);
    restaraunt = (int) budgetUser.addToExpenses(yearlyRestaurant);

    food = groceries + restaraunt;
    return food;
}

int travelQuery(BudgetUser budgetUser) {
    int travel;
    int gas;
    int monthlyGas;
    int flights;
    int monthlyFlights;

    cout << ("Enter your estimated expense on gas for one month: \n");
    cin >> monthlyGas;
    budgetUser.setGas(monthlyGas);
    int yearlyGas = budgetUser.getGas() * 12;
    gas = (int) budgetUser.addToExpenses(yearlyGas);

    cout << ("Enter your estimated expense on flights for the year: \n");
    cin >> monthlyFlights;
    budgetUser.setFlights(monthlyFlights);
    int yearlyFlights = budgetUser.getFlights();
    flights = (int) budgetUser.addToExpenses(yearlyFlights);

    travel = gas + flights;
    return travel;
}

int rentQuery(BudgetUser budgetUser) {
    int rent;
    int monthlyRent;

    cout << ("Enter your estimated expense on rent for one month: \n");
    cin >> monthlyRent;
    budgetUser.setRent(monthlyRent);
    int yearlyRent = budgetUser.getRent() * 12;
    budgetUser.setRent(yearlyRent);

    rent = (int) budgetUser.addToExpenses(yearlyRent);
    return rent;
}

int subscriptionQuery(BudgetUser budgetUser) {
    int subscriptions;
    int monthlySubs;

    cout << ("Enter your estimated expense for subscriptions for one month: \n");
    cin >> monthlySubs;
    budgetUser.setSubscriptions(monthlySubs);
    int yearlySubs = budgetUser.getSubscriptions() * 12;
    budgetUser.setSubscriptions(yearlySubs);

    subscriptions = (int) budgetUser.addToExpenses(yearlySubs);
    return subscriptions;
}

int insuranceQuery(BudgetUser budgetUser) {
    int insurance;
    int carInsurance;
    int monthlyCar;
    int healthInsurance;
    int monthlyHealth;
    int lifeInsurance;
    int monthlyLife;

    cout << ("Enter your estimated car insurance payment for one month: \n");
    cin >> monthlyCar;
    budgetUser.setAutoInsurance(monthlyCar);
    int yearlyCar = budgetUser.getAutoInsurance() * 12;
    carInsurance = (int) budgetUser.addToExpenses(yearlyCar);

    cout << ("Enter your estimated health insurance payment for one month: \n");
    cin >> monthlyHealth;
    budgetUser.setHealthInsurance(monthlyHealth);
    int yearlyHealth = budgetUser.getHealthInsurance() * 12;
    healthInsurance = (int) budgetUser.addToExpenses(yearlyHealth);

    cout << ("Enter your estimated life insurance payment for the year: \n");
    cin >> monthlyLife;
    budgetUser.setLifeInsurance(monthlyLife);
    int yearlyLife = budgetUser.getLifeInsurance();
    lifeInsurance = (int) budgetUser.addToExpenses(yearlyLife);

    insurance = carInsurance + healthInsurance + lifeInsurance;
    return insurance;
}

void displayExpenses(BudgetUser budgetUser) {
    int totalExpenses = budgetUser.getTotalExpenses();
    int rentExpense = budgetUser.getRent();
    int travelExpense = budgetUser.getFlights() + budgetUser.getGas();
    int foodExpense = budgetUser.getGroceries() + budgetUser.getOutToEat();
    int subExpense = budgetUser.getSubscriptions();
    int insuranceExpense = budgetUser.getAutoInsurance() + budgetUser.getHealthInsurance() + budgetUser.getLifeInsurance();
    cout << ("Your current rent is $" + rentExpense);
    cout << ("Your current travel expenses are $" + travelExpense);
    cout << ("Your current food expenses are $" + foodExpense);
    cout << ("Your current subscription expense is $" + subExpense);
    cout << ("Your current insurance expense is $" + insuranceExpense);
    cout << ("Your current expenses in total is $" + totalExpenses);
    cout << ("Your current funds to use is $" + (budgetUser.getIncome() - totalExpenses)) << endl;
}

int main() {
    cout << "Let's make a budget!" << endl;
    cout << "Enter your estimated yearly income: " << endl;

    long income;
    cin >> income;
    BudgetUser *budgetUser = new BudgetUser(income);

    char input = ' ';
    bool done = false;
    while (!done){
        cout << "Options:                                      " <<
                "Add rent,                            << R >>\n" <<
                "Add food expenses,                   << F >>\n" <<
                "Add travel expenses,                 << T >>\n" <<
                "Add subscriptions,                   << S >>\n" <<
                "Add insurance payments,              << I >>\n" <<
                "Display current budget w/o quitting, << D >>\n" <<
                "Finish budget and show results,      << Q >>\n" << endl;

        switch (input){
            case 'D':
                displayExpenses(*budgetUser);
                break;

            case 'F':
                foodQuery(*budgetUser);
                break;

            case 'I':
                insuranceQuery(*budgetUser);
                break;

            case 'Q':
                displayExpenses(*budgetUser);
                done = true;
                break;

            case 'R':
                rentQuery(*budgetUser);
                break;

            case 'S':
                subscriptionQuery(*budgetUser);
                break;

            case 'T':
                travelQuery(*budgetUser);
                break;

            default:
                cout << "Please enter a valid command" << endl;
        }
    }
}