#include<iostream>
#include<string.h>
using namespace std;
class  SavingsAccount		//����SavingsAccount��
{
    int  Id;  //�ʺ�
    double  balance;  //���
    double  Rate;    //������
    int  lastDate; //�ϴα����������
    double  accumulation;  //�����ۼ�֮��
    double  accumulate(int date);   //��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
public:
    SavingsAccount (int date, int id, double rate);  //���캯��
    void  deposit(indouble amount);  //�����ֽ�dateΪ���ڣ�amountΪ���
    void  witht date, draw(int date, double amount);  //ȡ���ֽ�
    void  settle(int date); //������Ϣ��ÿ��1��1�յ���һ�θú���
    void  show();   //����˻���Ϣ
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
void  SavingsAccount::deposit(int date, double amount)  ////�����ֽ�dateΪ���ڣ�amountΪ���
{
    accumulate(date);
    balance+=amount;
    lastDate=date;
}
void  SavingsAccount::withdraw(int date, double amount) ////ȡ���ֽ�
{
    accumulate(date);
    if(balance>=amount)
        balance-=amount;
    else
        cout<<"����"<<endl;
    lastDate=date;
}
void  SavingsAccount::settle(int date)   //������Ϣ��ÿ��1��1�յ���һ�θú���
{
    accumulate(date);
    if(date==90||date/365==0)
        balance+=accumulation/365*Rate;
    else
        cout<<"δ��������Ϣʱ��!";
    cout<<"��Ϣ:"<<accumulation/365*Rate<<endl;
}
void  SavingsAccount::show()    //����˻���Ϣ
{
    cout<<"�ʺ�:"<<Id<<endl<<"���:"<<balance<<endl;
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