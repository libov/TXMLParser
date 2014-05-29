//ROOT headers
#include <TMath.h>

// own headers
#include <TXMLParser.h>

// system headers
#include <iostream>
using namespace std;

TXMLParser::TXMLParser(TString filename):
TXMLEngine()
{
    fXmldoc = ParseFile(filename);
    if (fXmldoc==0) {
        cout << "ERROR: could not open XML file" << endl;
        abort();
    }

    // take access to main node
    fMainNode = DocGetRootElement(fXmldoc);
    selectMainNode();
}

void TXMLParser::selectMainNode() {
    fCurrentNode = fMainNode;
}

XMLNodePointer_t TXMLParser::selectNode(TString node_name) {
    fCurrentNode = getNode(node_name);
    return fCurrentNode;
}

void TXMLParser::selectNextNode(TString node_name) {
    XMLDocPointer_t next = GetNext(fCurrentNode);
    while (next!=0) {
        TString name = GetNodeName(next);
        if (node_name == name) {
            fCurrentNode = next;
            return;
        }
        next = GetNext(next);
    }
    fCurrentNode = 0;
}

XMLNodePointer_t   TXMLParser::getNode(TString node_name) {

    // loop over children
    XMLNodePointer_t child = GetChild(fCurrentNode);
    while (child!=0) {

        TString child_name    = GetNodeName(child);

        if ( child_name == node_name ) return child;
        child = GetNext(child);
    }

    return 0;
}

TString TXMLParser::getNodeContent(TString node_name) {

    XMLNodePointer_t child = getNode(node_name);
    TString content = "";
    if (child) content = GetNodeContent(child);

    return content;
}
