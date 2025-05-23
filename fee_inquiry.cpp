#include <iostream>
#include <vector>
class Student
{
    private:
        std::string name;
        int rollNo;
        int fee;

    public: 
        Student(std::string n, int r, int f)
            : name(n), rollNo(r), fee(f){}
        
        
        std::string getName()
        {
            return name;
        }
        int getRollNo()
        {
            return rollNo;
        }
        int getFee()
        {
            return fee;
        }
       
};

class FeeInq
{
    private:
        std::vector<Student> studentList;
    public: 
        void addStudent()
        {
            std::string n;
            int r, f;
            std::cout<<"Enter Student's Name : ";
            std::cin>>n;
            std::cout<<"Enter Student's Roll Number : ";
            std::cin>>r;
            std::cout<<"Enter Student's Fee : ";
            std::cin>>f;
            Student student(n, r, f);
            studentList.push_back(student);
        }
        void listStudentList()
        {
            for(int i = 0; i < studentList.size(); i++)
            {
                std::cout<<"Name : "<<studentList[i].getName()<<", Rollnumber : "<<studentList[i].getRollNo()<<std::endl;
            }
        }
        void studentStatus()
        {
            int rollNoForSearch;
            listStudentList();  // 因為一個函式只做一個工作，所以打印 list 交給其他函式
            std::cout<<std::endl<<"Enter the Roll Number : ";
            std::cin>>rollNoForSearch;
            for(int i = 0; i < studentList.size(); i++)
            {
                if(rollNoForSearch == studentList[i].getRollNo())
                    std::cout<<"Student's Fee : "<<studentList[i].getFee()<<std::endl<<std::endl;
            }

        }
};

int main()
{
    FeeInq fee;
    while(true)
    {
        int choice;
        std::cout<<"*****Fee Inquiry*****"<<std::endl;
        std::cout<<"1. Add Student"<<std::endl;
        std::cout<<"2. Search Student Fee"<<std::endl;
        std::cout<<"3. List All Student"<<std::endl;
        std::cout<<"4. Exit"<<std::endl;
        std::cout<<"Enter the Number : ";
        std::cin>>choice;
        if(choice == 1)
            fee.addStudent();
        else if(choice == 2)
            fee.studentStatus();
        else if(choice == 3)
            fee.listStudentList();    
        else if(choice == 4)
            exit(0);
        else
            std::cout<<"Invalid Number, Please Enter Again"<<std::endl<<std::endl;  
        
    }
    
   
    return 0;
}