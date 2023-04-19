#include "List.h"


int main()
{
    unsigned int el = 0;
    std::string a = "";
    std::string inputData;

    List myList;
    std::ofstream ourData("data.txt");

 

    while (true) {
        std::cout << "What do u want to do? (add data; delete; view; exit): ";
        std::getline(std::cin, a);

        if (a == "add data") {
            std::cout << "Write something: ";
            std::getline(std::cin, inputData);
            myList.addNode(inputData);
        }
        else if (a == "delete"){
            std::cout << "Enter number of element you want to delete: ";
            std::cin >> el;
            std::cin.ignore(1000, '\n');
            myList.deleteNode(el);
        }
        else if(a == "view") {
            myList.printList();
        }
        else if (a == "exit") {
            myList.printToTxt();
            break;
        }
        else {
            std::cout << "Input Error" << std::endl;
        }
        
        
        

       
    }
}