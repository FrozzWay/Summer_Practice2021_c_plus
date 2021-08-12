#pragma once

#include "StartWindow.h"
#include "MainWindow.h"
#include "BookedMoviesWindow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Проект;


[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Проект::StartWindow form;
	Application::Run(%form);
};

void StartWindow::button_board_Click(System::Object^  sender, System::EventArgs^  e) {
	MainWindow^ MainWindowForm = gcnew MainWindow();
	MainWindowForm->Show();
	StartWindow::Hide();
}


void StartWindow::button_saved_Click(System::Object^  sender, System::EventArgs^  e) {
	BookedMoviesWindow^ BookedMoviesWindowForm = gcnew BookedMoviesWindow();
	BookedMoviesWindowForm->Show();
	StartWindow::Hide();
}