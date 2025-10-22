#pragma once
#include <string>
#include <unordered_map>
#include <functional>

class PaymentSystem {
public:
    enum class PaymentMode {
        PayPal,
        GooglePay,
        CreditCard,
        Unknown
    };

    PaymentSystem(); // Constructor
    PaymentMode parsePaymentMode(const std::string& input);
    void checkout(PaymentMode mode, double amount);

private:
    std::unordered_map<PaymentMode, std::function<void(double)>> handlers;

    void processPayPal(double amount);
    void processGooglePay(double amount);
    void processCreditCard(double amount);
    void processUnknown(double amount);
};
