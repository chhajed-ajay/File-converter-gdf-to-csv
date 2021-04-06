#include "Node.h"

// static int variable numNodes which will take a count of total number of distinct nodes.
int Node::numNodes = 0;

// n -> node number, lab -> label of given node
Node::Node(int n, string lab)
{   
    number = n;
    label = lab;
}

// destructor
Node::~Node()
{

}

// copy constructor 
Node::Node(const Node &node)
{
    // copying all the private members
    number = node.number;
    label = node.label;
}

// getter for the number
int Node::getNumber()
{
    return number;
}

// getter for the label
string Node::getLabel()
{
    return label;
}

// setter for number of a node
void Node::setNumber(int n)
{
    number = n;
}

// setter for node label
void Node::setLabel(string s)
{
    label = s;
}