#pragma once
#include <ostream>
#include <string>
#include "Date.h"
using namespace std;

/// <summary>
/// Represents a row of data in a CSV file of Car records
/// </summary>
class Data {
#pragma region Fields
private:
	string user_id;
	int current_ranking;
	string first_name;
	string surname;
	string gender;
	Date date_of_birth;
	string email;
	string postcode;
	string country;
	string account_credit;
	//string phone;
	//Date last_log_on_date;
	//string last_log_on_time;
	//Date joined_on;
	//string address;

#pragma endregion

public:

#pragma region Constructors
	Data(string user_id, int current_ranking, string first_name, string surname,
		string gender, Date date_of_birth, string email, string postcode, string country, string account_credit)
		: user_id(user_id), current_ranking(current_ranking), first_name(first_name), surname(surname),
		gender(gender), date_of_birth(date_of_birth), email(email), postcode(postcode), country(country), account_credit(account_credit)
	{
	}
#pragma endregion

#pragma region Get/Set
	string getUserId() const { return this->user_id; }
	int getRanking() const { return this->current_ranking; }
	string getFirstName() const { return this->first_name; }
	string getSurName() const { return this->surname; }
	string getGender() const { return this->gender; }
	Date getDOB() const { return this->date_of_birth; }
	string getEmail() const { return this->email; }
	string getPostcode() const { return this->postcode; }
	string getCountry() const { return this->country; }
	string getCredit() const { return this->account_credit; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const Data& user)
	{
		return this->user_id == user.user_id
			&& this->current_ranking == user.current_ranking
			&& this->first_name == user.first_name
			&& this->surname == user.surname
			&& this->gender == user.gender
			&& this->date_of_birth == user.date_of_birth
			&& this->email == user.email
			&& this->postcode == user.postcode
			&& this->country == user.country
			&& this->account_credit == user.account_credit;

	}

	friend ostream& operator<<(ostream& output, Data& user) {
		output << user.user_id << ",";
		output << user.current_ranking << ",";
		output << user.first_name << ",";
		output << user.surname << ",";
		output << user.gender << ",";
		output << user.date_of_birth << ",";
		output << user.email << ",";
		output << user.postcode << ",";
		output << user.country << ",";
		output << user.account_credit << ",";

		return output;
	}

	friend istream& operator>>(istream& input, Data& user) {
		string studentAsStr;
		input >> studentAsStr;

		return input;
	}

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<string>()(this->user_id)
			+ 31 * std::hash<string>()(this->first_name)
			+ 57 * std::hash<string>()(this->email)
			+ 349 * date_of_birth.hash();
	}

#pragma endregion
};