#include "GDF.h" // including header file GDF.h

using namespace std;

// Filename -> name of the file 
GDF::GDF(string Filename)          // default constructor 
{
    fileName = Filename;
}

// copy constructor 
GDF::GDF(const GDF &gdfObj)
{
    // copying all the private members
    dataGDF = gdfObj.dataGDF;
    numEdges = gdfObj.numEdges;
    numLines = gdfObj.numLines;
}

// destructor
GDF::~GDF() {}

// overriding method "readInputFile" which will read the input file (.gdf in my case)   
void GDF::readInputFile()
{
    // opening file in read format
    ifstream file(fileName); 

    string tempString;
    numLines = 0;

    while (getline(file, tempString))
    {
        // storing all the data of the file in this vector dataGDF
        dataGDF.push_back(tempString);
        numLines++;
    }

    readNodes();

}

// read nodes mrthod will read all nodes present 
void GDF::readNodes()
{
    int i = 1;

    if (dataGDF[0].substr(0, 7) != "nodedef")
        return;

    // taking account of all the nodes in the graph
    while (dataGDF[i].size() >= 6 && dataGDF[i].substr(0, 7) != "edgedef")
    {
        string subStr[10];
        Stringsplit(dataGDF[i], subStr, ',');

        // node with number and label as an attributes
        Node n(subStr[0][1] - 48, subStr[1]);
        nodes.push_back(n);

        // increment number of nodes
        Node::numNodes += 1;
        i++;

    }
}

// process service will compute weighted adjacency matrix 
void GDF::process()
{
    int i;

    if (dataGDF[Node::numNodes + 1].substr(0, 7) != "edgedef")
        return;

    // from this position, file will have edges
    i = Node::numNodes + 2;

    while (i < numLines)
    {
        string subStr[10];
        Stringsplit(dataGDF[i], subStr, ',');

        int node1 = (subStr[0][1] - 48);
        int node2 = (subStr[1][1] - 48);

        // updating AM_edge, as now they have edge b/w them 
        AM_edge[node1 - 1][node2 - 1] = 1;

        // substring at index 2 will contain edge weight
        AM_weight[node1 - 1][node2 - 1] = stod(subStr[2]);

        // substring at index 3 will tell you if the edge is uni/bi directional.
        // if "true" --> bidirectional, else unidirectional
        if (subStr[3] == "true")
        {
            // bidirectional edge
            // so update AM_edge and AM_weight for reverse edge also
            AM_edge[node2 - 1][node1 - 1] = 1;
            AM_weight[node2 - 1][node1 - 1] = stod(subStr[2]);
        }
        i++;
    }
}

// overriden method "writeOutput" will write adjacency matrix in .csv file
void GDF::writeOutput()
{
    int i, j;

    // file opened in write format
    ofstream output("OUTPUT.csv");
    
    // if output is null, print error statement
    if (!output)
    {
        // printing error statement
        cerr << "Error : not opening\n";
        exit(0);
    }

    for (i = 0; i < Node::numNodes; i++)
    {
        output << ",s" << i + 1;
    }

    output << "\n";

    for (i = 0; i < Node::numNodes; i++)
    {
        output << "s" << i + 1 << ",";
        for (j = 0; j < Node::numNodes - 1; j++)
        {
            if (AM_edge[i][j] == 1)
            {
                output << AM_weight[i][j] << ",";
            }
            else
                output << "-1,";
        }

        if (AM_edge[i][j] == 1)
            output << AM_weight[i][j];
        else
            output << "-1";
        output << "\n";
    }
}