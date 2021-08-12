#pragma once

#include "BookedMoviesWindow.h"
#include "MainWindow.h"
#include "source.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace System;
using namespace System::Windows::Forms;
using namespace ������;

std::vector<BookedMovie> BookedMovies;


void BookedMoviesWindow::button_board_Click(System::Object^  sender, System::EventArgs^  e) {
	MainWindow^ MainWindowForm = gcnew MainWindow();
	MainWindowForm->Show();
	BookedMoviesWindow::Hide();
}

void BookedMoviesWindow::button_delete_Click(System::Object^  sender, System::EventArgs^  e) {
	if (listBox_bookedInf->SelectedItems->Count == 0)
	{
		MessageBox::Show("�� �� ������� ������� � ��������");
		return;
	}

	int item = listBox_bookedInf->SelectedIndex;
	BookedMovie::ModifyBookedDB("�������������.json", item);
	this->BookedMoviesWindow_Load(this, EventArgs::Empty);
	MessageBox::Show("�������.");
}

void BookedMoviesWindow::button_sort_Click(System::Object^  sender, System::EventArgs^  e) {
	listBox_bookedInf->Items->Clear();


	// �������� �������� � ���������, ��������� ��� ����������
	std::vector< std::pair <int, std::string> > toSort_container;
	for (BookedMovie movie : BookedMovies) {
		toSort_container.push_back(std::make_pair(movie.getSession(), movie.getName()));
	}
	std::sort(toSort_container.begin(), toSort_container.end());
	

	// ����� (����������) ��������� � listBox
	int amount_of_records = toSort_container.size();
	for (int i = 0; i < amount_of_records; i++) {
		String^ name = gcnew String(toSort_container[i].second.c_str());
		int session = toSort_container[i].first;

		time_t session_time = session;
		struct tm *tm = localtime(&session_time);
		char date[20];
		strftime(date, sizeof(date), "%F %R", tm);
		String^ date_converted = gcnew String(std::string(date).c_str());
		String^ item = String::Format("{0}  {1}", name, date_converted);
		listBox_bookedInf->Items->Add(item);
	}
}

void BookedMoviesWindow::button_refresh_Click(System::Object^  sender, System::EventArgs^  e) {
	this->BookedMoviesWindow_Load(this, EventArgs::Empty);
}


void BookedMoviesWindow::BookedMoviesWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	BookedMovies = ReadBookedDB("�������������.json");
	listBox_bookedInf->Items->Clear();

	for (BookedMovie movie : BookedMovies) {
		String^ name = gcnew String(movie.getName().c_str());
		int session = movie.getSession();

		time_t session_time = session;
		struct tm *tm = localtime(&session_time);
		char date[20];
		strftime(date, sizeof(date), "%F %R", tm);
		String^ date_converted = gcnew String(std::string(date).c_str());
		String^ item = String::Format("{0}  {1}", name, date_converted);
		listBox_bookedInf->Items->Add(item);
	}
}