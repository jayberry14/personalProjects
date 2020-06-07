#include <iostream>

using namespace std;

int main ()
{
    long long numShares; // The number of shares that a company has
    long long currentPrice; // The cost of buying 1 share of 1 stock
    long long earningsPerShare; // The amount of money generated by a company per share that it has
    long long bookValue; // The value of each share of a company from an accounting point of view
    long long dividend; // A share of profit paid out to shareholders
    long long standardDeviation; // A standard for measuring fluxuating stock currentPrices over time
    long long volatility; // A standard for measuring fluxuating stock currentPrices over time
    long long currentPriceToEarnings = currentPrice / earningsPerShare; // The ratio of the current currentPrice in the stock market to the company's earnings per share
    long long currentPriceToBook = currentPrice / bookValue; // The ratio of the current currentPrice in the stock market to the company's book value from an accounting point of view

    /* The Greeks */
    long long alpha; // Excess on return

    long long bid; // The most that someone would be willing to pay for a stock
    long long ask; // The least that someone would be willing to sell a stock
    long long bidAskSpread = bid - ask; // The difference between a bid and an ask which determines whether or not a trade happens

    long long openPrice; // The price that any stock has when the market opens on any given day
    long long highPrice; // The highest price that the stock will trade for on one day
    long long lowPrice; // The lowwest price that the stock will trade for on one day
    long long adjClosePrice; // The price that a stock reached when the market closed after all dividends were paid out

    cout << "Enter the number of shares for company x: " << endl;
    cin >> numShares;

    cout << "Enter the current strike currentPrice for the shares of company x: " << endl;
    cin >> currentPrice;
    
    long long marketCap = currentPrice * numShares; // Market Capitalizaion, the currentPrice * the number of shares a company has
    cout << "The Market Cap today is: " << marketCap << endl; 
    return 0;
}