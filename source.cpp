#pragma once

#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <msclr\marshal_cppstd.h>

using json = nlohmann::json;

class Movie {
private:
	std::string name;
	std::string genre;
	int age_restriction;
	int duration;
	int cost;
	std::string country;
	std::vector<int> sessions;
public:
	friend static std::vector<Movie> ReadDB(const char *FileName);
	std::string getName() { return name; };
	std::string getGenre() { return genre; };
	std::string getCountry() { return country; };
	int getCost() { return cost; };
	int getDuration() { return duration; };
	int getAge_restriction() { return age_restriction; };
	std::vector<int> getSessions() { return sessions; }
	static std::vector<Movie> filter(std::vector<Movie> movies, int type, System::String^ data);
	static std::vector<Movie> filter(std::vector<Movie> movies, int type, int data);
	static std::vector<Movie> Filter(int duration, int cost, int age, System::String^ country, System::String^ genre);
};

class BookedMovie {
private:
	std::string name;
	int session;
public:
	BookedMovie(std::string _name, int _session) {
		this->name = _name;
		this->session = _session;
	}
	friend static std::vector<BookedMovie> ReadBookedDB(const char *FileName);
	static void ModifyBookedDB(const char* FileName, int item);
	static int WriteBookedDB(const char *FileName, System::String^ name, int session);
	std::string getName() { return name; };
	int getSession() { return session; };
};

// –¿¡Œ“¿ œ¿–—≈–¿ <start>
inline nlohmann::json Parse_JSON_from_file(const char* FileName) {
	std::string text;
	std::string str;
	std::ifstream in(FileName);
	if (in.is_open())
	{
		while (getline(in, str))
		{
			text += str;
			text += "\n";
		}
	}
	std::cout << text << std::endl;
	in.close();
	// œÂÂ‚Ó‰ data ËÁ string ‚ char*
	const char* char_array = text.c_str();
	// rapidjson or nlohmann œ¿–—»Õ√ 
	json document = json::parse(char_array);
	return document;
};

std::vector<Movie> ReadDB(const char* FileName)
{
	json ParsedDB = Parse_JSON_from_file(FileName);
	int amount_of_films = ParsedDB.size();
	std::vector<Movie> movies;

	for (int i = 0; i < amount_of_films; i++) {
		Movie movie = Movie();
		movie.name = ParsedDB[i]["name"].dump();
		movie.genre = ParsedDB[i]["genre"].dump();
		movie.country = ParsedDB[i]["country"].dump();
		movie.age_restriction = std::stoi(ParsedDB[i]["age_restriction"].dump());
		movie.duration = std::stoi(ParsedDB[i]["duration"].dump());
		movie.cost = std::stoi(ParsedDB[i]["cost"].dump());

		int amount_of_sessions = ParsedDB[i]["sessions"].size();
		std::vector<int> sessions;
		for (int j = 0; j < amount_of_sessions; j++) {
			sessions.push_back(std::stoi(ParsedDB[i]["sessions"][j].dump()));
		}
		movie.sessions = sessions;

		movies.push_back(movie);
	}

	return movies;

}

std::vector<BookedMovie> ReadBookedDB(const char *FileName) {
	json ParsedDB = Parse_JSON_from_file(FileName);
	int amount_of_films = ParsedDB.size();

	std::vector<BookedMovie> BookedMovies;

	for (int i = 0; i < amount_of_films; i++) {
		std::string name = ParsedDB[i]["name"].dump();
		int session = std::stoi(ParsedDB[i]["session"].dump());
		BookedMovie bookedMovie = BookedMovie(name, session);

		BookedMovies.push_back(bookedMovie);
	}

	return BookedMovies;
}

inline int BookedMovie::WriteBookedDB(const char *FileName, System::String^ name, int session) {
	// œÓ‚ÂÍ‡ Ì‡ ‚ıÓÊ‰ÂÌËÂ <start>
	std::vector<BookedMovie> BookedMovies = ReadBookedDB(FileName);
	for (BookedMovie movie : BookedMovies) {
		System::String^ name1 = gcnew System::String(movie.getName().c_str());
		int session1 = movie.getSession();
		if (name == name1 && session == session1) return 0;
	}
	// œÓ‚ÂÍ‡ Ì‡ ‚ıÓÊ‰ÂÌËÂ <end>


	name = name->Replace("\"", "");
	// [name] System::String^ -> std::string
	std::string name_converted = msclr::interop::marshal_as<std::string>(name);

	json ParsedDB = Parse_JSON_from_file(FileName);
	

	json new_record = json{
		{"name", name_converted},
		{"session", session}
	};
	
	ParsedDB.push_back(new_record);

	std::string s = ParsedDB.dump();
	std::ofstream out;
	out.open(FileName);
	if (out.is_open())
	{
		out << s << std::endl;
		out.close();
		return 1;
	}
	return -1;
}

inline void BookedMovie::ModifyBookedDB(const char* FileName, int item) {
	json ParsedDB = Parse_JSON_from_file(FileName);
	json ParsedDB_modified;

	for (int i = 0; i < ParsedDB.size(); i++) {
		if (i != item) ParsedDB_modified.push_back(ParsedDB[i]);
	}

	std::string s = ParsedDB_modified.dump();
	std::ofstream out;
	out.open(FileName);
	if (out.is_open())
	{
		out << s << std::endl;
		out.close();
	}
}
// –¿¡Œ“¿ œ¿–—≈–¿ <end>


// ‘»À‹“–¿÷»ﬂ <start>
/*
inline std::vector<Movie> _filter_by_genre(std::vector<Movie> movies, System::String^ genre) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies)
		if (gcnew System::String(movie.getGenre().c_str()) == genre) movies_filtered.push_back(movie);
	return movies_filtered;
};

inline std::vector<Movie> _filter_by_country(std::vector<Movie> movies, System::String^ country) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies)
		if (gcnew System::String(movie.getCountry().c_str()) == country) movies_filtered.push_back(movie);
	return movies_filtered;
};

inline std::vector<Movie> _filter_by_age_restriction(std::vector<Movie> movies, int age_restriction) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies)
		if (movie.getAge_restriction() <= age_restriction) movies_filtered.push_back(movie);
	return movies_filtered;
};

inline std::vector<Movie> _filter_by_duration(std::vector<Movie> movies, int duration) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies)
		if (movie.getDuration() <= duration) movies_filtered.push_back(movie);
	return movies_filtered;
};

inline std::vector<Movie> _filter_by_cost(std::vector<Movie> movies, int cost) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies)
		if (movie.getCost() <= cost) movies_filtered.push_back(movie);
	return movies_filtered;
};
*/
inline std::vector<Movie> Movie::filter(std::vector<Movie> movies, int type, System::String^ data) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies) {
		switch (type) {
		case 1:
			if (gcnew System::String(movie.getCountry().c_str()) == data) movies_filtered.push_back(movie);
			break;
		case 2:
			if (gcnew System::String(movie.getGenre().c_str()) == data) movies_filtered.push_back(movie);
			break;
		}
	}
	return movies_filtered;
}

inline std::vector<Movie> Movie::filter(std::vector<Movie> movies, int type, int data) {
	std::vector<Movie> movies_filtered;
	for (Movie movie : movies) {
		switch (type) {
		case 1:
			if (movie.getDuration() == data) movies_filtered.push_back(movie);
			break;
		case 2:
			if (movie.getCost() == data) movies_filtered.push_back(movie);
			break;
		case 3:
			if (movie.getAge_restriction() == data) movies_filtered.push_back(movie);
			break;
		}
	}
	return movies_filtered;
}

inline std::vector<Movie> Movie::Filter( int duration, int cost, int age, System::String^ country, System::String^ genre) {
	std::vector<Movie> movies = ReadDB("‘ËÎ¸Ï˚.json");

	if (duration > 0) movies = filter(movies, 1, duration);
	if (cost > 0) movies = filter(movies, 2, cost);
	if (age > 0) movies = filter(movies, 3, age);
	if (country != "" && country != "<any>") movies = filter(movies, 1, country);
	if (genre != "" && genre != "<any>") movies = filter(movies, 2, genre);

	return movies;
}
// ‘»À‹“–¿÷»ﬂ <end>

