/**********************************************************
// Workshop 4: Containers
// w4.cpp
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Oct 2, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include "Message.h"
#include "Notifications.h"

const char REC_DELIMITER = '\n';

w4::Notifications collect(std::ifstream& in, char recDelim)
{
	w4::Notifications notifications;

	do
	{
		w4::Message message(in, recDelim);
		if (!message.empty())
			notifications += std::move(message);
	} while (in);

	return notifications;
}

int main(int argc, char* argv[])
{
	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1)
	{
		std::cerr << argv[0] << ": missing file operand\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << argv[0] << ": too many arguments\n";
		return 2;
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << argv[0] << "\n: Failed to open " << argv[1] << "\n";
		return 3;
	}

	std::cout << "\nNotifications\n=============\n\n";
	w4::Notifications notifications = collect(file, REC_DELIMITER);

	notifications.display(std::cout);

	return 0;
}