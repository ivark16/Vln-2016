#ifndef LIST_H
#define LIST_H
<<<<<<< HEAD

using namespace std;

=======
#include <string>
#include <fstream>
using namespace std;
>>>>>>> 6ccc14fae7c5db06ed5cd8ce6e3b9028e1af5f48


class list
{
private:
    string _name;
    int _birthYear;
    int _deathYear;
    char _sex;
    int _TuringAwards;

public:
    string name;
    char sex;
    int birthYear;
    int deathYear;
    int TuringAwards;

    list();
    bool readFile ();
    void getScientist ();

};

#endif // LIST_H
