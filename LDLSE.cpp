//===
// Libraries
//===

#include <iostream>

//==
//  Definitions depending on OS
//===

#ifdef _WIN32
    #define PAUSE() system("pause")
    #define CLEAR() system("cls")
#else
    #define PAUSE() do { \
        std::cout << "Press Enter to continue..."; \
        std::cin.get(); \
    } while(0)
    #define CLEAR() system("clear");
#endif

//==
// Definitions depending on OS
//===

#ifdef _WIN32
    #define PAUSE() system("pause")
#define CLEAR() system("cls")
#else
    #define PAUSE() do { \
        std::cout << "Press Enter to continue..."; \
        std::cin.get(); \
    } while(0)
    #define CLEAR() system("clear");
#endif

//===
// Classes
//===

class Node
{
public:
    Node(int element); // Constructor.
    const int getElement()const; // Getter, constant nont mutable value.
    Node *next; // A pointer to another node, this is just an address (8 bytes).
    Node *prev; //  A pointer that indicates previous node.

private:
    int element; // The "container" area of this object.
};

class List
{
public:
    List(); // Default constructor.
    ~List(); // Deconstructor, it makes the object destroy itself if allocated dinamicaly.
    bool empty(); // Check it's content.
    void insertStart(int element); // Adds another element.
    void insertEnd(int element);
    void show(); // Shoes the list of elements.
    void eraseStart(); // Deletes data.
    void eraseEnd();
    void eraseValue(int element);
    Node *start; // Pointer to the "first" element of the list.
};

//===
// Prototyping
//===

bool isValidInt(const std::string& input);

//===
// Start o program
//===

int main()
{
    CLEAR();
    List list; // Designation of list, empty of course, just a pointer to it's first element.

    std::string userInput;
    int opt, element;

    do
    {
    std::cout << "LDLSE\n"
              << "1) INSERT_START\n2) INSERT_END\n3) SHOW\n4) DELETE_START\n"
              << "5) DELETE_END\n6) DELETE VALUE\n7) EXIT\nOPTION:\t";

        // Valid input checker.
        if(!(std::cin >> opt))
        {
            std::cin.clear(); // reset error flags
            std::cin.ignore(1000, '\n'); // discard bad input
            std::cout << "\nInvalid input. Enter a number.\n\n";
        }else if(opt < 1 || opt > 7)
        {
        std::cout << "\nSelection out of range."
                  << " Enter a number from 1 to 7.\n\n";
        }
        std::cin.ignore();
        // End of Valid input checker.

        std::string elementToInsert;
        int theElement;

        switch(opt)
        {
        case 1:
            std::cout << "Please enter int value for the element:\n";
            while(true)
            {
                std::getline(std::cin, elementToInsert);
                if(isValidInt(elementToInsert))
                {
                    theElement = std::stoi(elementToInsert);
                    break;
                }
                std::cout << "Invalid value:\n";
            }
            list.insertStart(theElement);
            PAUSE();
            CLEAR();
            break;
        case 2:
            std::cout << "Please enter int value for the element:\n";
            while(true)
            {
                std::getline(std::cin, elementToInsert);
                if(isValidInt(elementToInsert))
                {
                    theElement = std::stoi(elementToInsert);
                    break;
                }
                std::cout << "Invalid value:\n";
            }
            list.insertEnd(theElement);
            PAUSE();
            CLEAR();
            break;
        case 3:
            list.show();
            PAUSE();
            CLEAR();
            break;  
        case 4:
            list.eraseStart();
            PAUSE();
            CLEAR();
            break;
        case 5:
            list.eraseEnd();
            PAUSE();
            CLEAR();
            break;
        case 6:
            std::cout << "Please enter int value for the value to erase:\n";
            while(true)
            {
                std::getline(std::cin, elementToInsert);
                if(isValidInt(elementToInsert))
                {
                    theElement = std::stoi(elementToInsert);
                    break;
                }
                std::cout << "Invalid value:\n";
            }
            list.eraseValue(theElement);
            PAUSE();
            CLEAR();
            break;
        }
    }while(opt != 7);
    std::cout << "\nEnding Program\n";
}

//===
// Classes Methos
//===

    // Constructor
Node::Node(int element_)
{
    element = element_; // Surely works when it's new.
    next = NULL;
}

    // Getter
const int Node::getElement()const{return element;}

    // Boolean Empty returner.
bool List::empty()
{
    return (start == NULL);
}

    // InsertS
void List::insertStart(int element)
{
    Node* create = new Node(element);

    if(empty())
    {
        start = create;
        create->next = create;
        create->prev = create;
    }else
    {
        Node *aux = start;
        create->next = start;
        while(aux->next != start)
        {
            aux = aux->next;
        }
        aux->next = create;
        create->prev = aux;
        start->prev = create;
        start = create;
    }  
}

    //  InsertE
void List::insertEnd(int element)
{
    Node* create = new Node(element);

    if(empty())
    {
        start = create;
        start->next = start;
        create->prev = create;
    }else
    {
        Node *aux = start;
        while(aux->next != start)
        {
            aux = aux->next;
        }
        create->next = start;
        start->prev = create;
        aux->next = create;
        create->prev = aux;
    }
}

    //  DeleteS
void List::eraseStart()
{
    if(empty())
    {
        std::cout << "\nThe list is empty.\n";
    }else
    {
        Node *aux = start;
        if(start->next == start)
        {
            start = NULL;
        }else
        {
            while(aux->next != start)
            {
                aux = aux->next;
            }
            aux->next = start->next;
            start->next->prev = aux;  //
            aux = start;
            start = start->next;
        }
        
        delete aux;
    }
}

    //  erase End
void List::eraseEnd()
{
    if(empty())
    {
        std::cout << "\nThe list is empty.\n";
    }else
    {
        Node *aux = start;
        if(start->next == start)
        {
            start = NULL;
        }else
        {
            while(aux->next->next != start)
            {
                aux = aux->next;
            }
        }

        delete aux->next;
        aux->next = start;
        start->prev = aux;
    }
}

    //  Erase Value
void List::eraseValue(int element)
{
    Node *aux = start;
    if(empty())
    {
        std::cout << "\nThe list is empty\n";
    }else if(start->next == start && start->getElement() == element)
    {
        start = NULL;
    }else
    {
        while(aux->next != start)
        {
            if(aux->getElement() == element)    //  Found
            {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                delete aux;
                return;
            }
            aux = aux->next;
        }
        //  Not found
        std::cout << "\nThe element "<< element <<" is not on the list\n";
    }
}

    //  Show
void List::show()
{
    if(empty())
    {
        std::cout << "\nThe list is empty\n";
    }else
    {
        std::cout << "\n-----------\n";
        Node *aux = start;
        while(aux->next != start)
        {
            std::cout << aux->getElement() << '\n';
            aux = aux->next;
        }
        std::cout << aux->getElement() << '\n';
    }
}

    //  Constructor
List::List(){start = NULL;} //  When created, it points to NULL as a start. 

    //  Deconstructor
List::~List(){}

//===
//  Function
//===

    //  int Validation
bool isValidInt(const std::string& input)
{
    if(input.empty()) return false;

    int start = 0;

    if(input[0] == '-' || input[0] == '+')
        start = 1;

    for(int i = start; i < input.size(); i ++)
    {
        if(!isdigit(input[i]))
        {
            return false;
        }
    }

    return true;
}