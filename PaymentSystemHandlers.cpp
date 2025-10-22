#include "PaymentSystem.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

void PaymentSystem::processPayPal(double amount) {
    cout << "[PayPal] Processing payment of $" << amount << endl;
    // Placeholder for PayPal API
}

void PaymentSystem::processGooglePay(double amount) {
    cout << "[GooglePay] Processing payment of $" << amount << endl;
    // Placeholder for GooglePay API
}

void PaymentSystem::processCreditCard(double amount) {
    cout << "[CreditCard] Processing payment of $" << amount << endl;
    // Placeholder for Credit Card API
}

void PaymentSystem::processUnknown(double amount) {
    cout << "[Error] Invalid or unsupported payment mode!" << endl;
}
