#ifndef GDF_H // defining the histogram.h if not included
#define GDF_H

// including libraries and header files
#include <iosfwd>
#include <fstream>
#include <string>
#include<iostream>
#include <vector>
#include "Base.h"
#include "Node.h"

using namespace std;

class GDF : public Base
{
private:
    // private data members and functions

    // input .gdf file will get stored in this string vector dataGDF
    vector<string> dataGDF;
     
    string fileName;          // file name
    int numEdges;             // number of edges  
    int numLines;             // number of lines
    vector<Node> nodes;       // it will store node with their names (label)


    // AM_weight[i][j] will contain the weight of edge between node i and node j
    double AM_weight[100][100] = {0.0};      

    // AM_edge[i][j] will tells us that whether there is a edge between node i and node j
    // if AM_edge[i][j] = 0, then no edge
    // else AM_edge[i][j] = 1, there exists edge
    int AM_edge[100][100] = {0};


    // method to split string
    void Stringsplit(string s, string subStrings[], char ch)
    {
        // sentence intitally empty
        string Sentence = "";
        int i = 0;

        for (auto c : s)
        {
            if (c != ch)
            {
                Sentence = Sentence + c;
            }
            else
            {
                subStrings[i++] = Sentence;
                Sentence = "";
            }
        }

        // making substrings
        subStrings[i] = Sentence;
    }


public:
    // function definition
    // prototypes


    // constructors and destructors
    GDF(string Filename);                     // default constructor with parameters
    ~GDF();                                   // destructor
    GDF(const GDF &gdfObject);                // copy constructor

    // method to read .gdf (graph definition file) file 
    void readInputFile();

    // method to read nodes (with label)
    void readNodes();


    // method to write in a .csv (comma separated values) file 
    void writeOutput();

    // will create Adjacency matrix
    void process();


    // getters for number nodes 
    int getNumNodes()
    {   
        return Node::numNodes;
    }

    // getters for number edges
    int getNumEdges()
    {
        return numEdges;
    }

    // getter for number of lines
    int getNumLines()
    {
        return numLines;
    }

    // getter for file name 
    string getFileName()
    {
        return fileName;
    }

    // getter for data of gdf file
    vector<string> getDataGDF()
    {
        return dataGDF;
    }


    // setters for all data members
    void setDataGDF(vector<string> v)
    {
        dataGDF =  v;
    }

    void setFileName(string p)
    {
        fileName = p;
    }

    void setNumLines(int n0)
    {
        numLines = n0;
    }

    void setNumEdges(int n0)
    {
        numEdges = n0;
    }


};
#endif