#pragma once

#include "MainWindow.h"
#include "BookedMoviesWindow.h"
#include "source.cpp"

#include <set>

using namespace System;
using namespace System::Windows::Forms;
using namespace Проект;

static std::vector<Movie> movies;

ref struct Session_Display {
private:
	String^ my_user_friendly_view;
	String^ my_value;
public:
	Session_Display(String^ _user_friendly_view, String^ _value) {
		this->my_user_friendly_view = _user_friendly_view;
		this->my_value = _value;
	}
	property String^ user_friendly_view {
		String^ get() {
			return my_user_friendly_view;
		}
	}
	property String^ value {
		String^ get() {
			return my_value;
		}
	}
};


void MainWindow::button_saved_Click(System::Object^  sender, System::EventArgs^  e) {
	BookedMoviesWindow^ BookedMoviesWindowForm = gcnew BookedMoviesWindow();
	BookedMoviesWindowForm->Show();
	MainWindow::Hide();
}


void MainWindow::MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	movies = ReadDB("Фильмы.json");
	std::set<std::string> country_set;
	std::set<std::string> genre_set;
	for (Movie movie : movies) {
		listBox_results->Items->Add(gcnew String(movie.getName().c_str()));
		country_set.insert(movie.getCountry());
		genre_set.insert(movie.getGenre());
	}
	country_set.insert("<any>");
	genre_set.insert("<any>");

	for (std::set<std::string>::iterator it = country_set.begin(); it != country_set.end(); it++) {
		String^ converted = gcnew String((*it).c_str());
		comboBox_country->Items->Add(converted);
	}

	for (std::set<std::string>::iterator it = genre_set.begin(); it != genre_set.end(); it++) {
		String^ converted = gcnew String((*it).c_str());
		comboBox_genre->Items->Add(converted);
	}

	button_schedule->Enabled = false;
}


void MainWindow::listBox_results_Click(System::Object^  sender, System::EventArgs^  e) {
	if (listBox_results->SelectedItems->Count == 0) return;
	listBox_schedule->Enabled = true;
	button_schedule->Enabled = true;

	String^ name = listBox_results->SelectedItem->ToString(); // исходное имя
	for (Movie movie : movies) {
		String^ name1 = gcnew String(movie.getName().c_str()); // сравниваемое имя
		String^ genre = gcnew String(movie.getGenre().c_str());
		String^ country = gcnew String(movie.getCountry().c_str());
		if (name == name1) {
			// Заполнение описания
			label8->Text = name;
			String^ description = String::Format("Название: {0} \r\nЖанр: {1}\r\nВозрастное огранчение: {2}\r\nДлительность: {3}\r\nСтоимость: {4}\r\nСтрана: {5}", name, genre, movie.getAge_restriction(), movie.getDuration(), movie.getCost(), country);
			textBox_description->Text = description;

			// Заполнение сеансов.
			ArrayList^ SessionsList = gcnew ArrayList;

			for (int session : movie.getSessions()) {
				time_t session_time = session;
				struct tm *tm = localtime(&session_time);
				char date[20];
				strftime(date, sizeof(date), "%F    %R", tm);

				// [date] char* -> System::String^
				String^ date_converted = gcnew String(std::string(date).c_str());

				SessionsList->Add( gcnew Session_Display( date_converted, session.ToString() ) );
			}

			listBox_schedule->DataSource = SessionsList;
			listBox_schedule->DisplayMember = "user_friendly_view";
			listBox_schedule->ValueMember = "value";
			break;
		}
	}
}


void MainWindow::button_schedule_Click(System::Object^  sender, System::EventArgs^  e) {
	if (listBox_schedule->SelectedItems->Count == 0)
	{
		MessageBox::Show("Необходимо выбрать нужный фильм и сеанс");
		return;
	}

	int session = Convert::ToInt32(listBox_schedule->SelectedValue->ToString());
	String^ name = listBox_results->SelectedItem->ToString();

	int check = BookedMovie::WriteBookedDB("Забронировано.json", name, session);
	if (check)
		MessageBox::Show("Успешно добавлено!");
	else
		MessageBox::Show("Уже забронировано!");
}


void MainWindow::button_filter_Click(System::Object^  sender, System::EventArgs^  e) {
	int duration = (textBox_duration->Text != "") ? Convert::ToInt32(textBox_duration->Text) : 0;
	int cost = (textBox_cost->Text != "") ? Convert::ToInt32(textBox_cost->Text) : 0;
	int age = (textBox_age->Text != "") ? Convert::ToInt32(textBox_age->Text) : 0;
	String^ country = (comboBox_country->SelectedIndex != -1) ? comboBox_country->SelectedItem->ToString() : "";
	String^ genre = (comboBox_genre->SelectedIndex != -1) ? comboBox_genre->SelectedItem->ToString() : "";

	movies = Movie::Filter(duration, cost, age, country, genre);

	listBox_results->Items->Clear();
	for (Movie movie : movies) {
		listBox_results->Items->Add(gcnew String(movie.getName().c_str()));
	}
	listBox_schedule->Enabled = false;
	if (listBox_schedule->SelectedItems->Count != 0) listBox_schedule->SetSelected(0, false);
	button_schedule->Enabled = false;
	textBox_description->Text = "";
	label8->Text = "Название фильма";
}