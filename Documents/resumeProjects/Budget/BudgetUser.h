#ifndef BUDGETUSER_H
#define BUDGETUSER_H

#include <iostream>
using namespace std;

class BudgetUser {
    //Used at all times
    private:
    long income;
    long rent;
    long groceries;
    long outToEat;
    long gas;
    long flights;
    long tuition;
    long subscriptions;
    long insuranceAuto;
    long insuranceHealth;
    long insuranceLife;

    //Used when person is married
    long internet;
    long electricity;
    long hvac;
    long savings;
    
    long totalExpenses;

    public:

    BudgetUser() {
        setIncome(0);
        setTotalExpenses(0);
        setRent(0);
        setFlights(0);
        setGas(0);
        setElectricity(0);
        setGroceries(0);
        setOutToEat(0);
        setSubscriptions(0);
        setHvac(0);
        setAutoInsurance(0);
        setHealthInsurance(0);
        setLifeInsurance(0);
        setTuition(0);
        setSavings(0);
    }

    BudgetUser(long income) {
        setIncome(income);
        setTotalExpenses(0);
        setRent(0);
        setFlights(0);
        setGas(0);
        setElectricity(0);
        setGroceries(0);
        setOutToEat(0);
        setSubscriptions(0);
        setHvac(0);
        setAutoInsurance(0);
        setHealthInsurance(0);
        setLifeInsurance(0);
        setTuition(0);
        setSavings(0);
    }

    long getIncome() { return income; }

    void setIncome(long incomeX) { income = incomeX; }

    long getRent() { return rent; }

    void setRent(long rentX) { rent = rentX; }

    long getGroceries() { return groceries; }

    void setGroceries(long food) { groceries = food; }

    long getOutToEat() { return outToEat; }

    void setOutToEat(long outToEatX) { outToEat = outToEatX; }

    long getGas() { return gas; }

    void setGas(long gasX) { gas = gasX; }

    long getFlights() { return flights; }

    void setFlights(long flightsX) { flights = flightsX; }

    long getSubscriptions() { return subscriptions; }

    void setSubscriptions(long subscriptionsX) { subscriptions = subscriptionsX; }

    long getAutoInsurance() { return insuranceAuto; }

    void setAutoInsurance(long insuranceAutoX) { insuranceAuto = insuranceAutoX; }

    long getHealthInsurance() { return insuranceHealth; }

    void setHealthInsurance(long insuranceHealthX) { insuranceHealth = insuranceHealthX; }

    long getLifeInsurance() { return insuranceLife; }

    void setLifeInsurance(long insuranceLifeX) { insuranceLife = insuranceLifeX; }

    long getinternet() { return internet; }

    void setinternet(long internetX) { internet = internetX; }

    long getElectricity() { return electricity; }

    void setElectricity(long electricityX) { electricity = electricityX; }

    long getHvac() { return hvac; }

    void setHvac(long hvacX) { hvac = hvacX; }

    long getTuition() { return tuition; }

    void setTuition(long tuitionX) { tuition = tuitionX; }

    long getSavings() { return savings; }

    void setSavings(long savingsX) { savings = savingsX; }

    long getTotalExpenses() { return totalExpenses; }

    void setTotalExpenses(long totalExpensesX) { totalExpenses = totalExpensesX; }

    long addToExpenses(long rhs) { return totalExpenses += rhs; }
};

#endif
