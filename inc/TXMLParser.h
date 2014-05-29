#ifndef TXMLPARSER_H
#define TXMLPARSER_H

// ROOT headers
#include <TROOT.h>
#include <TXMLEngine.h>

// system headers
#include <vector>
using namespace std;

class TXMLParser : public TXMLEngine {

    public:

        TXMLParser(TString filename);
        ~TXMLParser(){};

        void                selectMainNode();
        XMLNodePointer_t    selectNode(TString node_name);
        void                selectNextNode(TString node_name);
        XMLNodePointer_t    getNode(TString node_name);
        TString             getNodeContent(TString node_name);

        XMLNodePointer_t    getCurrentNode() {return fCurrentNode;}

        XMLNodePointer_t    getDocument() { return fXmldoc; }

    private:

        XMLDocPointer_t     fXmldoc;
        XMLNodePointer_t    fMainNode;
        XMLNodePointer_t    fCurrentNode;
};

#endif
