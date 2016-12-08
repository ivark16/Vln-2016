#include "connection.h"

connection::connection()
{

}

connection::connection(int scientistId, int computersId)
{
    _scientistId = scientistId;
    _computersId = computersId;
}

int connection::getScientistId()
{
    return _scientistId;
}

int connection::getComputersId()
{
    return _computersId;
}
