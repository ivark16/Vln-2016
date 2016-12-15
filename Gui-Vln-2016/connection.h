#ifndef CONNECTION_H
#define CONNECTION_H
#include <iostream>
#include <vector>
#include <string>

class connection
{
    int _scientistId;
    int _computersId;

public:
    connection();
    connection(int scientistId, int computersId);
    int getScientistId();
    int getComputersId();
};

#endif // CONNECTION_H
