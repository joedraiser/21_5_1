#include <iostream>
#include <fstream>

struct manNsalary
{
    std::string name;
    int salary;
    std::string date;
};

int main()
{
    std::fstream payroll;

    std::cout << "list or add? ";
    std::string input;

    std::cin >> input;

    if(input == "list")
    {
        char buffer[1000];
        payroll.open("payroll.txt", std::ios::in | std::ios::binary);
        if(!payroll.is_open())
        {
            std::cout << "File is not opened.";
            exit(EXIT_FAILURE);
        }
        do
        {
            payroll.read(buffer, sizeof(buffer)-1);
            buffer[payroll.gcount()]=0;

            std::cout << buffer;
        }
        while(!payroll.eof());
    }
    else if(input == "add")
    {
        payroll.open("payroll.txt", std::ios::out | std::ios::app);

        std::string name, surname;
        manNsalary man2add;

        std::cout << "Input name, surname, date and salary: ";
        std::cin >> name >> surname >> man2add.date >> man2add.salary;
        man2add.name = name + " " + surname;
        payroll << man2add.name << " " << man2add.date << " " << man2add.salary << std::endl;
    }

    payroll.close();

    return 0;
}
