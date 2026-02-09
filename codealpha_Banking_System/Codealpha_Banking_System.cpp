#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Transaction{ 
    public: 
        string type;
        double amount;

    Transaction(double a ,string t){ 
        type=t;
        amount=a;
    }
};
class Account{ 
private:
int balance;
int accountNo;
vector <Transaction>transactions;
public:
Account(int accNo){ 
    accountNo=accNo;
    balance=0;

}
 int getAccNo(){ 
    return accountNo;
 }
 int getBalance(){ 
    return balance;
 }
    
 void withdraw(){ 
            int amount;
            cout<<"Enter the amount you want to withdraw from your account: ";
            cin>>amount;
            if(balance>=amount){ 
            balance-=amount;
            transactions.push_back(Transaction(amount,"Withdraw"));
            cout<<"Withdraw Successfully!"<<endl;
        }
        else
        cout<<"Insufficient Balance"<<endl;
    }
        void deposit(){ 
            int amount;
            cout<<"Enter the amount you want to deposit to your account: ";
            cin>>amount;
            balance+=amount;
            transactions.push_back(Transaction(amount,"Deposit"));
            cout<<"Deposit Successfully!"<<endl;
        }
        void fund_transfer(double amount,string type){ 
            
            balance+=amount;
            transactions.push_back(Transaction(amount,type));
            cout<<"Fund Transfer Succesfully!"<<endl;
        }

        void show_Transaction(){ 
            if(transactions.empty()){ 
                cout<<"No transaction record is found"<<endl;
                return ;
            }
                else{ 
                    for(auto t: transactions)
                cout<<t.type<<" "<<t.amount<<endl;
            }
            
        }
    };
    class Customer{
        private: 
        string name;
        Account account;
        public:
        Customer(string n,int accNO):
        account(accNO){ 
            name=n;
        }
        Account &getAccount(){ 
            return account;
        }
        void showdetails(){ 
            cout<<"Name: "<<name<<endl;
            cout<<"Account NO. : "<<account.getAccNo()<<endl;
            cout<<" Current Balance: "<<account.getBalance()<<endl;
        }
    };
        
    

int main(){
Customer c1("Ayeza",1001);
Customer c2("laiba",1002);
int choice;
double amount;
do{
    cout<<"=======Banking System======="<<endl;
    cout<<"1. Deposit"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3.Fund Transfer "<<endl;
    cout<<"4.Account Details "<<endl;
    cout<<"5.Transaction History "<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"============================="<<endl;
    cout<<"Enter your Choice: ";
    cin>>choice;
    switch(choice){ 
        case 1:{
            c1.getAccount().deposit();
            break;
        }
        case 2:{ 
            c1.getAccount().withdraw();
            break;
        }
        case 3:{ 
            cout<<"Enter Transfer Amount"<<endl;
            cin>>amount;
            if(amount>c1.getAccount().getBalance()){ 
                cout<<"Insufficient Balance"<<endl;
            }
            else
            c1.getAccount().fund_transfer(-amount,"Fund Send");
            c2.getAccount().fund_transfer(amount,"Fund received");
            break;
        }
      case 4:{ 
        c1.showdetails();
        break;
      }
      case 5:{ 
        c1.getAccount().show_Transaction();
        break;
      }
      case 0:{ 
      cout<<"Thank you for using Our Banking System";
      break;
      }
      default :
      cout<<"Invalid Choice"<<endl;
    }
}while(choice!=0);
    return 0;
}