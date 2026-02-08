#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool duplicate(string username){
    ifstream fin;
fin.open("credentials.txt");
    string u,p;
    while(fin>>u>>p){ 
        if(username==u){
        cout<<"Username is already taken"<<endl;
        fin.close();
         return true;
         
    }
    
   
    fin.close();

}
    
}
bool Register(string username,string passcode){
    ofstream fout;
    fout.open("credentials.txt",ios::app);
    if(username.empty()) {
    cout<<"Username cannot be empty"<<endl;
    return false;
    }
    if(passcode.empty()){ 
    cout<<"password cannot be empty"<<endl;
    return false;
    }
    if(passcode.length()<6){ 
    cout<<"password is too short"<<endl;
    return false;
    }
    if(duplicate(username)){ 
        return false;
    }
     
      fout<<username<<" "<<passcode<<endl;
      cout<<"Registered succcessfully!"<<endl;
      fout.close();
    return true ;  
    
}
bool Login(string new_username,string new_passcode){ 
ifstream fin;
fin.open("credentials.txt");
    string u,p;
    while(fin>>u>>p){ 
        if(new_username==u && new_passcode==p){
        fin.close();
         return true;
         }
    }
    fin.close();
    return false;
}
int main(){
    string name,code;
    string new_name,new_code;
    int choice;
    cout<<"Enter your Choice"<<endl<<"1.(Registration)"<<endl<<"2.(Login)"<<endl;
    cin>>choice;
    if(choice==1){ 
    cout<<"======Registration====="<<endl;
    cout<<"Enter Username: ";
    cin>>name;
    cout<<endl;
    cout<<"Enter Password: ";
    cin>>code;
    (Register(name,code));
}
    if (choice==2) { 
    cout<<"======Login======"<<endl;
    cout<<"Enter Username: ";
    cin>>new_name;
    cout<<endl;
    cout<<"Enter Password: ";
    cin>>new_code;
    Login(new_name,new_code);
    if(Login(new_name,new_code))
    cout<<"Login Successfull!"<<endl;
    else
    cout<<"Invalid login Credentials"<<endl;
    }
    return 0;
}