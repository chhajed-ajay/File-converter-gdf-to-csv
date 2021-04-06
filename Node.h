#ifndef NODE_H
#define  NODE_H

#include <string>

using namespace std;

class Node
{

    private:

    // private data members
    int number;
    string label;


    public:

    // static variable to store total number of nodes
    static int numNodes;    

    // constructors and destructors
    Node(int n, string lab);                 // default constructor
    ~Node();                                 // destructor
    Node(const Node &node);                  // copy constructor
    
    // getters
    int getNumber();
    string getLabel();  

    // setters
    void setNumber(int n);
    void setLabel(string s);

};
#endif
