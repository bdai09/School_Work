/**********************************************************
// Workshop 9: Multi-Threading
/SecureData.cpp
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Nov 11, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO: rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		
		//std::thread t1(std::bind(converter, text, key, nbytes / 3, Cryptor()));	t1.join();...
		//this way only fit 921/threadnum remain 0, if threadnum=2, error
		
		const int threadnum = 2; //this method, no matter threadnum=2 or 3, will work
		Cryptor cryptor[threadnum];
		thread thr[threadnum];
		for (int i = 0;i < threadnum;i++) {
			thr[i] = std::thread(std::bind(converter, text + i * (nbytes / threadnum), key, i + 1 < threadnum ? (nbytes / threadnum) : (nbytes - i * nbytes / threadnum), cryptor[i]));
		    //if 921/2, 2nd thread not missing 1 byte and work
		}
		for (int i = 0;i < threadnum;i++) {
			thr[i].join();
		}
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream f(file, std::ios::out | std::ios::binary | std::ios::trunc); //open from the end
			if (!f.is_open()) {
				throw std::string("File open failed");
			}
			else {
				// opened successfully
			// TODO: write data into the binary file
			//         and close the file
				f.write(text, nbytes);
				f.close();
			}
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream f(file, std::ios::in | std::ios::binary|std::ios::ate);
		if (!f.is_open()) {
			throw string("File open failed");
		}
		else {
			// TODO: - allocate memory here for the file content
			nbytes=(int)f.tellg();
			delete[] text;
			text = new char[nbytes];
			f.seekg(0, std::ios::beg);//go to begining, 2nd way, while loop >> byte
		// TODO: - read the content of the binary file
			f.read(text, nbytes);
		}
		f.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}