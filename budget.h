#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

    int choice;
    double dollars;
    std::string confirm;
    std::string bill;
    std::ofstream file;
    std::vector<std::pair<std::string, double>> bills{};//pairs different types of datat types together in a vector 
    std::vector<int>bill_amounts{};
    std::vector<std::string>bill_names{};

void editBudget();
void total();
void balance();
void income();
void menu();
