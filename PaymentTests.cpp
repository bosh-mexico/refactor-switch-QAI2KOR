#include "PaymentSystem.h"
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

void testParsePaymentMode() {
    PaymentSystem ps;

    assert(ps.parsePaymentMode("PayPal") == PaymentSystem::PaymentMode::PayPal);
    assert(ps.parsePaymentMode("paypal") == PaymentSystem::PaymentMode::PayPal);
    assert(ps.parsePaymentMode("GOOGLEPAY") == PaymentSystem::PaymentMode::GooglePay);
    assert(ps.parsePaymentMode("creditcard") == PaymentSystem::PaymentMode::CreditCard);
    assert(ps.parsePaymentMode("invalid") == PaymentSystem::PaymentMode::Unknown);
    assert(ps.parsePaymentMode("") == PaymentSystem::PaymentMode::Unknown);
}

void testCheckout() {
    PaymentSystem ps;
    double amount = 50.0;
    
    ps.checkout(PaymentSystem::PaymentMode::PayPal, amount);
    ps.checkout(PaymentSystem::PaymentMode::GooglePay, amount);
    ps.checkout(PaymentSystem::PaymentMode::CreditCard, amount);
    ps.checkout(PaymentSystem::PaymentMode::Unknown, amount);

    cout << endl;
}

void testParsePaymentModeEdgeCases() {
    PaymentSystem ps;

    //  Leading/trailing spaces
    assert(ps.parsePaymentMode(" PayPal ") == PaymentSystem::PaymentMode::Unknown);
    assert(ps.parsePaymentMode(" GooglePay\t") == PaymentSystem::PaymentMode::Unknown);

    //  Case sensitivity
    assert(ps.parsePaymentMode("gOoGlEpAy") == PaymentSystem::PaymentMode::GooglePay);

    //  Special characters
    assert(ps.parsePaymentMode("paypal!") == PaymentSystem::PaymentMode::Unknown);
    assert(ps.parsePaymentMode("credit_card") == PaymentSystem::PaymentMode::Unknown);

    //  Extremely long string
    assert(ps.parsePaymentMode(string(1000, 'a')) == PaymentSystem::PaymentMode::Unknown);
}

void testCheckoutEdgeAmounts() {
    PaymentSystem ps;

    //  Zero amount
    ps.checkout(PaymentSystem::PaymentMode::PayPal, 0.0);

    //  Negative amount (could be used for refunds)
    ps.checkout(PaymentSystem::PaymentMode::CreditCard, -100.0);

    //  Large amount
    ps.checkout(PaymentSystem::PaymentMode::GooglePay, 1e9);
}

int main() {
    testParsePaymentMode();
    testParsePaymentModeEdgeCases();
    testCheckout();
    testCheckoutEdgeAmounts();
    return 0;
}
