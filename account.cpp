#include <iostream>
#include "account.h"
using namespace std;
//Account基类成员函数
Account::Account(int Id, double Balance)
{
    id = Id;
    balance = Balance;
}
void Account::show()
{
    cout << "账号:" << getId() << "  余额:" << getBalance() << endl;
}
void Account::getTotal()
{
    cout << "各账户总额:" << total << endl;
}
SavingsAccount::SavingsAccount(int year, int month, int day, int id, double balance, double Rate) : Account(id, balance), lastDate(year, month, day)
{
    rate = Rate;
    cout << year << "/" << month << "/" << day << "\t";
    cout << "账号" << id << "创建成功!" << endl;
}
const double SavingsAccount::accumulate(Date date)
{
    return lastDate.distance(date) * balance;
}
void SavingsAccount::deposit(Date date, double amount)
{
    accumulation += accumulate(date);
    balance += amount;
    lastDate = date;
    total += amount;
    cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << "\t";
    cout << id << "存入:" << amount << "\t\t" << id << "余额:" << balance << endl;
}
void SavingsAccount::withdraw(Date date, double amount)
{
    accumulation += accumulate(date);
    balance -= amount;
    lastDate = date;
    total -= amount;
    cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << "\t";
    cout << id << "取出:" << amount << "\t\t" << id << "余额:" << balance << endl;
}
void SavingsAccount::settle(Date date)
{
    double settle = 0;
    accumulation += accumulate(date);
    settle = accumulation / 356 * rate;
    cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << "\t";
    cout << id << "结算利息:" << settle << endl;
    deposit(date, settle);
}
const void SavingsAccount::show()
{
    Account::show();
}
CreditAccount::CreditAccount(int year, int month, int day, int id, double balance, double Credit, double Rate, double Fee) : Account(id, balance), lastDate(year, month, day)
{
    credit = Credit;
    fee = Fee;
    rate = Rate;
    cout << year << "/" << month << "/" << day << "\t";
    cout << "账号" << id << "创建成功!" << endl;
}
double CreditAccount::getDebt(Date date)
{
    settle(date);
    return balance;
}
void CreditAccount::deposit(Date date, double amount)
{
    settle(date);
    if (credit <= 0 || amount > credit)
    {
        date.show();
        cout << id << "\t信用卡可用额度不足!" << endl;
    }
    else
    {
        balance -= amount;
        credit -= amount;
        date.show();
        cout << id << "\t信用卡借款:" << amount << "\t\t还可用额度:" << credit << endl;
        total -= amount;
    }
}
void CreditAccount::withdraw(Date date, double amount)
{
    settle(date);
    balance += amount;
    if ((credit + amount) <= 10000)
    {
        credit = credit + amount;
    }
    else
    {
        credit = 10000;
    }
    total += amount;
    date.show();
    cout << id << "\t信用卡还款:" << amount << "\t\t还可用额度:" << credit << endl;
}
void CreditAccount::settle(Date date)
{
    double settle = 0;
    if ((date.getMonth() < lastDate.getMonth()) || (date.getYear() > lastDate.getYear()))
    {
        for (int i = 1; i <= date.getYear() - lastDate.getYear(); i++)
        {
            settle += fee; //年费
        }
    }
    if (date.getDay() == 1 || date.getMonth() > lastDate.getMonth() || date.getYear() > lastDate.getYear())
    {
        if (date.getYear() == lastDate.getYear())
        {
            for (int j = 1; j <= (date.getMonth() - lastDate.getMonth()); j++)
            {
                for (int m = 1; m <= lastDate.distance(date); m++)
                {
                    settle -= balance * rate;
                }
            }
        }
        else
        {
            for (int j = 1; j <= (date.getMonth() - lastDate.getMonth()) + 12; j++)
            {
                for (int m = 1; m <= lastDate.distance(date); m++)
                {
                    settle -= balance * rate;
                }
            }
        }
    }
    else
    {
        settle -= 0;
    }
    balance -= settle;
    total -= settle;
    lastDate = date;
}
const void CreditAccount::show()
{
    Account::show();
}