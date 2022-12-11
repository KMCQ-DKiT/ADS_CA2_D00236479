#pragma once
#include <ostream>
#include <string>
#include "Date.h"
using namespace std;

/// <summary>
/// Represents a row of data in a CSV file of Car records
/// </summary>
class KeyData {
#pragma region Fields
private:
	Date date_of_birth;
	string email;
	string address;

#pragma endregion

public:

#pragma region Constructors
	KeyData( Date date_of_birth, string email, string address)
		:  date_of_birth(date_of_birth), email(email), address(address)
	{
	}
#pragma endregion

#pragma region Get/Set
	Date getDOB() const { return this->date_of_birth; }
	string getEmail() const { return this->email; }
	string getAddress() const { return this->address; }
	
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const KeyData& user)
	{
		return this->date_of_birth == user.date_of_birth
			&& this->email == user.email
			&& this->address == user.address;

	}

	friend ostream& operator<<(ostream& output, KeyData& user) {
		
		output << user.date_of_birth << ",";
		output << user.email << ",";
		output << user.address << ",";

		return output;
	}

	friend istream& operator>>(istream& input, KeyData& user) {
		string studentAsStr;
		input >> studentAsStr;

		return input;
	}

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<string>()(this->address)
			+ 57 * std::hash<string>()(this->email)
			+ 349 * date_of_birth.hash();
	}

#pragma endregion
};