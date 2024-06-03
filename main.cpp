#include <iostream>
using namespace std;

#include <array>
#include <string>

constexpr int MAX_ARRAY_SIZE = 100; //Max array size 
constexpr char NULL_CHAR = '\0';    //Null character for readability
constexpr int INVALID_AGE = -1;     //Default/Invalid age for readability
constexpr int INVALID_ID = -1;      //Default/Invalid ID for readability

enum options
{
    ADD_RECORD,
    FETCH_RECORD,
    EXIT
};

class record
{
    public:
    std::string name;
    int age;
};

std::ostream& operator<<(std::ostream & out,const record record_out)  //Overloading <<operator to use the class directly
{
    out << "User's Name: " << record_out.name << '\n';
    out << "User's Age: " << record_out.age << '\n';
    return out;
}

std::array<record,MAX_ARRAY_SIZE> records;  //An array of records
static int input_count;                 //How many times the user entered records (Should be 100 max)

void add_record(const std::string name,const int age)
{
    if(age > INVALID_AGE)   //If age was entered correctly (> -1)
    {
        records[input_count].name = name;
        records[input_count].age = age;
        input_count++;
    }
    else
    {
        std::cout << "ERROR! Wrong age entered!\n";
    }
}

void fetch_record(const int id)
{
    if(id > INVALID_ID && id < MAX_ARRAY_SIZE)
    {
        if(records[id].age > INVALID_AGE)
        {
            std::cout << records[id] << '\n'; //Find out why this is wrong
        }
        else
        {
            std::cout << "ID not found!\n\n";
        }
    }
    else
    {
        std::cout << "ERROR! ID must be within 0 & 99!\n\n";
    }
}

void print_options(void)
{
    int option = ADD_RECORD;
    for(option;option<=options::EXIT;option++)
    {
        switch(option)
        {
            case options::ADD_RECORD:
                std::cout << '\n' <<options::ADD_RECORD << ". ADD RECORD\n";
                break;
            case options::FETCH_RECORD:
                std::cout << options::FETCH_RECORD << ". FETCH RECORD\n";
                break;
            case options::EXIT:
                std::cout << options::EXIT << ". EXIT\n Please select one of the above options: ";
                break;
            default:
                break;
        }
    }
    
}

int main(void)
{
    record default_record;              //couldn't make it constexpr :(
    default_record.name = NULL_CHAR;    //Setting the default record object with the invalid members
    default_record.age = INVALID_AGE;
    records.fill(default_record);       //Makes all records with null names & -1 age

    int selection = options::ADD_RECORD;    //User's input selection
    std::string input_name;      constexpr int MAX_ARRAY_SIZE = 100; //Max array size 
constexpr char NULL_CHAR = '\0';    //Null character for readability
constexpr int INVALID_AGE = -1;     //Default/Invalid age for readability
constexpr int INVALID_ID = -1;      //Default/Invalid ID for readability           //User's input name
    int input_age = INVALID_AGE;            //User's input age
    int input_ID = INVALID_ID;              //User's input ID (for fetching)

    while(selection <= options::EXIT && selection >= options::ADD_RECORD)
    {
        print_options();
        std::cin >> selection;
        while(selection > options::EXIT || selection < options::ADD_RECORD) //Validation case
        {
            cout << "ERROR! Re-enter your input: ";
            std::cin >> selection;
        }
        switch(selection)
        {
            case options::ADD_RECORD:
                if(input_count < MAX_ARRAY_SIZE)
                {
                    cout << "Enter your record's username: ";
                    cin >> input_name;
                    cout << "Enter your record's age: ";
                    cin >> input_age;
                    add_record(input_name,input_age);
                }
                break;
            case options::FETCH_RECORD:
                cout << "Enter your record's ID: ";
                cin >> input_ID;
                fetch_record(input_ID);
                break;
            case options::EXIT:
                return 0; //Can't use break here because it'd mean break from the switching
                break;
        }
    }

    return 0;
}