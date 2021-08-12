#pragma once

namespace Проект {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для BookedMoviesWindow
	/// </summary>
	public ref class BookedMoviesWindow : public System::Windows::Forms::Form
	{
	public:
		BookedMoviesWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BookedMoviesWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  button_board;
	private: System::Windows::Forms::ListBox^  listBox_bookedInf;
	private: System::Windows::Forms::Button^  button_delete;
	private: System::Windows::Forms::Button^  button_sort;
	private: System::Windows::Forms::Button^  button_refresh;





	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_board = (gcnew System::Windows::Forms::Button());
			this->listBox_bookedInf = (gcnew System::Windows::Forms::ListBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_sort = (gcnew System::Windows::Forms::Button());
			this->button_refresh = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(113, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(312, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Сеансы, которые вы отметили";
			// 
			// button_board
			// 
			this->button_board->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_board->Location = System::Drawing::Point(390, 426);
			this->button_board->Name = L"button_board";
			this->button_board->Size = System::Drawing::Size(128, 35);
			this->button_board->TabIndex = 18;
			this->button_board->Text = L"Смотреть афишу";
			this->button_board->UseVisualStyleBackColor = true;
			this->button_board->Click += gcnew System::EventHandler(this, &BookedMoviesWindow::button_board_Click);
			// 
			// listBox_bookedInf
			// 
			this->listBox_bookedInf->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->listBox_bookedInf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->listBox_bookedInf->FormattingEnabled = true;
			this->listBox_bookedInf->ItemHeight = 18;
			this->listBox_bookedInf->Location = System::Drawing::Point(69, 80);
			this->listBox_bookedInf->Name = L"listBox_bookedInf";
			this->listBox_bookedInf->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox_bookedInf->Size = System::Drawing::Size(420, 256);
			this->listBox_bookedInf->TabIndex = 19;
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(361, 342);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(128, 35);
			this->button_delete->TabIndex = 20;
			this->button_delete->Text = L"Удалить запись";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &BookedMoviesWindow::button_delete_Click);
			// 
			// button_sort
			// 
			this->button_sort->Location = System::Drawing::Point(69, 377);
			this->button_sort->Name = L"button_sort";
			this->button_sort->Size = System::Drawing::Size(142, 29);
			this->button_sort->TabIndex = 21;
			this->button_sort->Text = L"Отсортировать по дате";
			this->button_sort->UseVisualStyleBackColor = true;
			this->button_sort->Click += gcnew System::EventHandler(this, &BookedMoviesWindow::button_sort_Click);
			// 
			// button_refresh
			// 
			this->button_refresh->Location = System::Drawing::Point(69, 342);
			this->button_refresh->Name = L"button_refresh";
			this->button_refresh->Size = System::Drawing::Size(175, 29);
			this->button_refresh->TabIndex = 22;
			this->button_refresh->Text = L"Отсортировать по добавлению";
			this->button_refresh->UseVisualStyleBackColor = true;
			this->button_refresh->Click += gcnew System::EventHandler(this, &BookedMoviesWindow::button_refresh_Click);
			// 
			// BookedMoviesWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(555, 487);
			this->Controls->Add(this->button_refresh);
			this->Controls->Add(this->button_sort);
			this->Controls->Add(this->button_delete);
			this->Controls->Add(this->listBox_bookedInf);
			this->Controls->Add(this->button_board);
			this->Controls->Add(this->label1);
			this->Name = L"BookedMoviesWindow";
			this->Text = L"Cinema";
			this->Load += gcnew System::EventHandler(this, &BookedMoviesWindow::BookedMoviesWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_board_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void BookedMoviesWindow_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_delete_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_sort_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_refresh_Click(System::Object^  sender, System::EventArgs^  e);
};
}
