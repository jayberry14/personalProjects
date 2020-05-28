#include <iostream>
using namespace std;

class BudgetUser {
    //Used at all times
    private:
    long income;
    int rent;
    int groceries;
    int outToEat;
    int gas;
    int flights;
    int tuition;
    int subscriptions;
    int insuranceAuto;
    int insuranceHealth;
    int insuranceLife;

    //Used when person is married
    int internet;
    int electricity;
    int hvac;
    int savings;
    
    int totalExpenses;

    public:

    BudgetUser(long income) {
        setIncome(income);
    }

    long getIncome() {
        return income;
    }

    void setIncome(long incomeX) {
        income = incomeX;
    }

    int getRent() { return rent; }

    void setRent(int rentX) {
        rent = rentX;
    }

    int getGroceries() {
        return groceries;
    }

    void setGroceries(int food) {
        groceries = food;
    }

    int getOutToEat() {
        return outToEat;
    }

    void setOutToEat(int outToEatX) {
        outToEat = outToEatX;
    }

    int getGas() {
        return gas;
    }

    void setGas(int gasX) {
        gas = gasX;
    }

    int getFlights() {
        return flights;
    }

    void setFlights(int flightsX) {
        flights = flightsX;
    }

    int getSubscriptions() { return subscriptions; }

    void setSubscriptions(int subscriptionsX) { subscriptions = subscriptionsX; }

    int getAutoInsurance() { return insuranceAuto; }

    void setAutoInsurance(int insuranceAutoX) { insuranceAuto = insuranceAutoX; }

    int getHealthInsurance() { return insuranceHealth; }

    void setHealthInsurance(int insuranceHealthX) { insuranceHealth = insuranceHealthX; }

    int getLifeInsurance() { return insuranceLife; }

    void setLifeInsurance(int insuranceLifeX) { insuranceLife = insuranceLifeX; }

    int getInternet() { return internet; }

    void setInternet(int internetX) { internet = internetX; }

    int getElectricity() { return electricity; }

    void setElectricity(int electricityX) { electricity = electricityX; }

    int getHvac() { return hvac; }

    void setHvac(int hvacX) { hvac = hvacX; }

    int getTuition() { return tuition; }

    void setTuition(int tuitionX) { tuition = tuitionX; }

    int getSavings() { return savings; }

    void setSavings(int savingsX) { savings = savingsX; }

    int getTotalExpenses() {
        return totalExpenses;
    }

    void setTotalExpenses(int totalExpensesX) {
        totalExpenses = totalExpensesX;
    }

    long addToExpenses(int rhs) {
        return totalExpenses += rhs;
    }
};
