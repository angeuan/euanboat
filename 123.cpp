#include<iostream>
#include<string.h>
using namespace std;
class  SavingsAccount		//创建SavingsAccount类
{
    int  Id;  //帐号
    double  balance;  //余额
    double  Rate;    //年利率
    int  lastDate; //上次变更余额的日期
    double  accumulation;  //余额按日累加之和
    double  accumulate(int date);   //获得到指定日期为止的存款金额按日累积值
public:
    SavingsAccount (int date, int id, double rate);  //构造函数
    void  deposit(int date, double amount);  //存入现金，date为日期，amount为金额
    void  withdraw(int date, double amount);  //取出现金
    void  settle(int date); //结算利息，每年1月1日调用一次该函数
    void  show();   //输出账户信息
    int getId() {return Id;}
    double  getBalance () { return balance;}
    double  getRate() {return Rate;}
};
double SavingsAccount::accumulate(int date)
{
    accumulation+=balance*(date-lastDate);
    return accumulation;
}
SavingsAccount::SavingsAccount(int date, int id, double rate)
{
    Id=id;
    balance=0;
    lastDate=date;
    accumulation=0;
    Rate=rate;
}
void  SavingsAccount::deposit(int date, double amount)  ////存入现金，date为日期，amount为金额
{
    accumulate(date);
    balance+=amount;
    lastDate=date;
}
void  SavingsAccount::withdraw(int date, double amount) ////取出现金
{
    accumulate(date);
    if(balance>=amount)
        balance-=amount;
    else
        cout<<"余额不足"<<endl;
    lastDate=date;
}
void  SavingsAccount::settle(int date)   //结算利息，每年1月1日调用一次该函数
{
    accumulate(date);
    if(date==90||date/365==0)
        balance+=accumulation/365*Rate;
    else
        cout<<"未到结算利息时间!";
    cout<<"利息:"<<accumulation/365*Rate<<endl;
}
void  SavingsAccount::show()    //输出账户信息
{
    cout<<"帐号:"<<Id<<endl<<"余额:"<<balance<<endl;
}
int main()
{
    SavingsAccount s0(1,1001,0.015);
    SavingsAccount s1(1,1002,0.015);
    s0.deposit(5,5000);
    s0.deposit(45,5500);
    s1.deposit(25,10000);
    s1.withdraw(60,4000);
    s0.settle(90);
    s1.settle(90);
    s0.show();
    s1.show();
    return 0;
}
