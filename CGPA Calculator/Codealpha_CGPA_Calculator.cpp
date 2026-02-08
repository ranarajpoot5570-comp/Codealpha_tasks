#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){ 
    cout<<"====GPA/CGPA Calculator===="<<endl;
    float sem_GPA[8]={0};
    string grade[50];
    float Grade_point[50]={0};
    int credit_hrs[50]={0};
    int total_crhrs[8]={0};
    int current_hrs=0;
    float total_grpoints[8]={0};
     float gpa=0;
    float S_cgpa;
    int no_of_crs;
    
    for(int sem=0;sem<8;sem++){ 
        cout<<endl<<"--- Semester "<<(sem+1)<<" ---"<<endl;
        cout<<"Enter number of courses: ";
        cin>>no_of_crs;
        for(int i=0;i<no_of_crs;i++){ 
    cin>>grade[i]>>credit_hrs[i];
        }
        for(int i=0;i<no_of_crs;i++){ 
            cout<<"Course"<<" "<<(i+1)<<":"<<" "<<" "<<grade[i]<<endl;
        }
        for(int i=0;i<no_of_crs;i++){ 
        if(grade[i]=="A")
        Grade_point[i]=4.00;
        else if(grade[i]=="A-")
        Grade_point[i]=3.70;
        else if(grade[i]=="B+")
        Grade_point[i]=3.30;
        else if(grade[i]=="B")
        Grade_point[i]=3.00;
        else if(grade[i]=="B-")
        Grade_point[i]=2.70;
        else if(grade[i]=="C+")
        Grade_point[i]=2.30;
        else if(grade[i]=="C")
        Grade_point[i]=2.00;
        else if(grade[i]=="D")
        Grade_point[i]=1.00;
        else if(grade[i]=="F")
        Grade_point[i]=0.00;
        else{ 
            cout<<"Invalid Grade using F(0.00)"<<endl;
            Grade_point[i]=0.00;
        }
       
    }
    for(int j=0;j<no_of_crs;j++){ 
        total_crhrs[sem]+=credit_hrs[j];
        total_grpoints[sem]+=Grade_point[j] * credit_hrs[j];

    }
    if(total_crhrs[sem] > 0) {
    sem_GPA[sem]=total_grpoints[sem]/total_crhrs[sem];
     
    }
    gpa+=sem_GPA[sem]*total_crhrs[sem];
        current_hrs+=total_crhrs[sem];
        cout<<"Sem "<<(sem+1)<<": GPA="<<fixed<<setprecision(2)<<sem_GPA[sem]<<", Credits="<<total_crhrs[sem];
        if(sem>=1){ 
            S_cgpa = gpa / current_hrs;
            cout<<", CGPA: "<<fixed<<setprecision(2)<<S_cgpa<<endl;
        }
    }
    
    if(current_hrs > 0) {
        S_cgpa = gpa / current_hrs;
        cout<<endl<<"*** Total CGPA: "<<fixed<<setprecision(2)<<S_cgpa<<" ***"<<endl;
        cout<<"Total Credit Hours: "<<current_hrs<<endl;
    } else {
        cout<<"No courses entered!"<<endl;
    }
    

    return 0;
}