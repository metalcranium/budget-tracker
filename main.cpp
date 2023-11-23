#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int choice;
double dollars;
std::string confirm;
std::string bill;

std::vector<std::pair<std::string, double>> bills{};

void editBudget();
void total();
void balance();
void income();
void menu();
int exit();

int main(){
    std::string start;

    std::cout << "Welcome to the Budget Tracker\n\n";
    std::cout << "If you do not have a budget created then...\n";
    std::cout << "type (new) to creat a new budget.\n";
    std::cout << "Otherwise enter any key to continue\n";
    std::cin >> start;
    if (start == "new"){
        std::ofstream file("Budget");
        file.close();
    }
    else{
        menu();
    }
    return 0;
}
void menu(){
    std::cout << "\nMain menu" << std::endl;
    std::cout << "\n(1) Edit budget\n";
    std::cout << "(2) Enter income\n";
    std::cout << "(3) Balance\n";
    std::cout << "(4) total budget\n";
    std::cout << "(0) to exit\n";
    std::cin >> choice;

        if (choice == 1){
            editBudget();
        }
        if (choice == 2){
            income();
        }
        if (choice == 3){
            balance();
	    }
        if (choice == 4){
            total();
        }	
        else{
            exit();
        }
}
void editBudget(){ // every time you run this function it will replace the old budget data.
    while (bill != "done"){
        std::cout << "Bill name: ";
        std::cin >> bill;
            if(bill != "done"){
                std::cout << "Bill amount: ";
                std::cin >> dollars;
                bills.push_back(std::make_pair(bill,dollars));
        }
    }
    std::ofstream file;
    file.open("Budget");

    for (auto writeBills : bills){
	    file << writeBills.first << " " << writeBills.second << std::endl;
	}
	file.close();
    menu();
}
void total(){ 
	std::ifstream read("Budget");  
	std::string billText;
	double dollarText;
    double total;
	
    while (!read.eof()){
        read >> billText >> dollarText;
        if (read.eof()){
            continue;
        }
        else{
        std::cout << billText << ": " << dollarText << std::endl;
        total += dollarText;
        }
    }
    std::cout << "Total Bills: " << total << std::endl;
    read.close();
    menu();
}
void income(){ 
    std::string answer;
    std::ifstream read("Income");
    double income; 
    read >> income;
    if (read){
        std::cout << "Your monthly income is: " << income;
        std::cout << "\nDo you want to change it?\n ";
        std::cout << "Type (yes) or (no)\n";
        std::cin >> answer;
        if (answer != "yes"){
            read.close();
            menu();
        }
        if (answer == "yes"){
            read.close();
            std::cout << "What is your new income?\n";
            std::cout << "Income: ";
            std::cin >> dollars;
            std::ofstream file("Income");
	        file << dollars;
	        file.close();
            menu();
        }
        
    }
    else{
	    std::cout << "\nHow much is your Income\n";
	    std::cout << "Income: ";
	    std::cin >> dollars;
        std::ofstream file("Income");
	    file << dollars;
	    file.close();
        menu();
    }
}
void balance(){
	double income;
	double total;
	double balance;
	double amounts;
    std::string billNames;
	std::ifstream inc("Income");
	inc >> income;
    inc.close();
	std::ifstream read("Budget");
    
	while (read){
        read >> billNames >> amounts;
        if (read.eof()){
            continue;
        }
        else{
        total += amounts;
        }
    }
    read.close();
	balance = income - total;
	std::cout << "\nBalance: " << balance << std::endl;	

    menu();
}

int exit(){
    return 0;
}


