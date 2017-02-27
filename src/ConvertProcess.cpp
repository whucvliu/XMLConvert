#include "ConvertProcess.h"
#include "tinystr.h"
#include "tinyxml.h"

int ConvertProcess(const string sXMLFile)
{

	//open the xml file and conduct the read process
	TiXmlDocument XMLDoc(sXMLFile.c_str());
	bool loadOk = XMLDoc.LoadFile();
	if (!loadOk)
		cout << "could load:" << XMLDoc.ErrorDesc() << endl;

	//the tool class, to output the XML data in required format
	TiXmlPrinter printer;
	XMLDoc.Accept(&printer);
	cout << printer.CStr() << endl;



	int liu = 1;
	return 1;
}


