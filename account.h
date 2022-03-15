#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include "date.h"
class Account
{
protected:
    int id;
    double balance;
    static double total;

public:
    Account(int id, double balance);
    const int getId() { return id; }
    const double getBalance() { return balance; }
    static void getTotal();
    void show();
};
class SavingsAccount : public Account
{
    double rate;
    Date lastDate;
    double accumulation = 0;
    const double accumulate(Date date);

public:
    SavingsAccount(int year, int month, int day, int id, double balance, double Rate);
    void deposit(Date date, double amount);
    void withdraw(Date date, double amount);
    void settle(Date date);
    const double getRate() { return rate; }
    const void show();
};
class CreditAccount : public Account //信用卡类
{
protected:
    double credit; //额度
    double rate;   //利率
    double fee;    //年费
    Date lastDate;

public:
    CreditAccount(int year, int month, int day, int id, double balance, double credit, double rate, double fee);
    double getAvailableCredit() { return credit; } //可用额度
    void deposit(Date date, double amount);
    void withdraw(Date date, double amount);
    double getDebt(Date date); //欠款额度
    void settle(Date date);
    const void show();
};
#endif // ACCOUNT_H_INCLUDED