// XMLConvert.cpp : Defines the entry point for the console application.
//
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "common.h"
#include "ConvertProcess.h"

using namespace std;

int ReadCFGFile(fstream &CFGFStream, string &sCFGFilePath);

int _tmain(int argc, _TCHAR* argv[])
{
	//conduct the experiments by changing the default list files
	string sTstListFile = "../../Script/TstList.txt";
	fstream fCFGStream;
	fCFGStream.open(sTstListFile.c_str(), std::ios_base::in);
	if (!(fCFGStream.is_open()))
	{
		cout << "Unable to find the list file for the configure files"<<endl;
		return 0;
	}

	//loop to read the configure files
	string sCFGFilePath;
	while (ReadCFGFile(fCFGStream, sCFGFilePath))
	{
		//read the xml file and conduct the convert process
		if (!ConvertProcess(sCFGFilePath))
			cout << "Error in the convert process " << endl;
	}

	cout << "The End of the Process" << endl;

	return 1;
}

int ReadCFGFile(fstream &CFGFStream, string &sCFGFilePath)
{
	char pcCharBuffer[CHAR_MAX_LEN];
	//CFGFStream.getline(pcCharBuffer, CHAR_MAX_LEN);
	//bool bJudge = CFGFStream.eof();
	while (!(CFGFStream.eof()))
	{
		CFGFStream.getline(pcCharBuffer, CHAR_MAX_LEN);
		if (*pcCharBuffer == '#' || *pcCharBuffer =='\0')
			continue;
		else
		{
			sCFGFilePath = pcCharBuffer;
			return 1;
		}
	}
	return 0;
}

