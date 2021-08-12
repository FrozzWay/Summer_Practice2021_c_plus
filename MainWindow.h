#pragma once

namespace Проект {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox_country;
	private: System::Windows::Forms::ComboBox^  comboBox_genre;
	private: System::Windows::Forms::TextBox^  textBox_duration;
	private: System::Windows::Forms::TextBox^  textBox_cost;
	private: System::Windows::Forms::TextBox^  textBox_age;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button_filter;
	private: System::Windows::Forms::ListBox^  listBox_results;




	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox_description;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ListBox^  listBox_schedule;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  button_schedule;
	private: System::Windows::Forms::Button^  button_saved;
	private: System::Windows::Forms::Label^  label11;







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
			this->comboBox_country = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_genre = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_duration = (gcnew System::Windows::Forms::TextBox());
			this->textBox_cost = (gcnew System::Windows::Forms::TextBox());
			this->textBox_age = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button_filter = (gcnew System::Windows::Forms::Button());
			this->listBox_results = (gcnew System::Windows::Forms::ListBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox_description = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->listBox_schedule = (gcnew System::Windows::Forms::ListBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button_schedule = (gcnew System::Windows::Forms::Button());
			this->button_saved = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(31, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Фильтры";
			// 
			// comboBox_country
			// 
			this->comboBox_country->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_country->FormattingEnabled = true;
			this->comboBox_country->Location = System::Drawing::Point(41, 93);
			this->comboBox_country->Name = L"comboBox_country";
			this->comboBox_country->Size = System::Drawing::Size(119, 21);
			this->comboBox_country->TabIndex = 1;
			// 
			// comboBox_genre
			// 
			this->comboBox_genre->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_genre->FormattingEnabled = true;
			this->comboBox_genre->Location = System::Drawing::Point(41, 147);
			this->comboBox_genre->Name = L"comboBox_genre";
			this->comboBox_genre->Size = System::Drawing::Size(119, 21);
			this->comboBox_genre->TabIndex = 2;
			// 
			// textBox_duration
			// 
			this->textBox_duration->Location = System::Drawing::Point(41, 204);
			this->textBox_duration->Name = L"textBox_duration";
			this->textBox_duration->Size = System::Drawing::Size(100, 20);
			this->textBox_duration->TabIndex = 3;
			this->textBox_duration->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::textBox_duration_KeyPress);
			// 
			// textBox_cost
			// 
			this->textBox_cost->Location = System::Drawing::Point(41, 259);
			this->textBox_cost->Name = L"textBox_cost";
			this->textBox_cost->Size = System::Drawing::Size(100, 20);
			this->textBox_cost->TabIndex = 4;
			this->textBox_cost->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::textBox_cost_KeyPress);
			// 
			// textBox_age
			// 
			this->textBox_age->Location = System::Drawing::Point(41, 312);
			this->textBox_age->Name = L"textBox_age";
			this->textBox_age->Size = System::Drawing::Size(100, 20);
			this->textBox_age->TabIndex = 5;
			this->textBox_age->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::textBox_age_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(38, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Страна:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(38, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Жанр:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(38, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Длительность до:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(38, 236);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 16);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Стоимость до:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(147, 205);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"(мин)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(38, 287);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 16);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Возраст до:";
			// 
			// button_filter
			// 
			this->button_filter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_filter->Location = System::Drawing::Point(41, 370);
			this->button_filter->Name = L"button_filter";
			this->button_filter->Size = System::Drawing::Size(126, 35);
			this->button_filter->TabIndex = 12;
			this->button_filter->Text = L"Фильтровать";
			this->button_filter->UseVisualStyleBackColor = true;
			this->button_filter->Click += gcnew System::EventHandler(this, &MainWindow::button_filter_Click);
			// 
			// listBox_results
			// 
			this->listBox_results->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->listBox_results->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox_results->FormattingEnabled = true;
			this->listBox_results->HorizontalScrollbar = true;
			this->listBox_results->ItemHeight = 16;
			this->listBox_results->Location = System::Drawing::Point(229, 65);
			this->listBox_results->Name = L"listBox_results";
			this->listBox_results->Size = System::Drawing::Size(348, 340);
			this->listBox_results->TabIndex = 13;
			this->listBox_results->Click += gcnew System::EventHandler(this, &MainWindow::listBox_results_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(631, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(165, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Название фильма";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox_description
			// 
			this->textBox_description->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_description->Location = System::Drawing::Point(634, 91);
			this->textBox_description->Multiline = true;
			this->textBox_description->Name = L"textBox_description";
			this->textBox_description->ReadOnly = true;
			this->textBox_description->Size = System::Drawing::Size(227, 128);
			this->textBox_description->TabIndex = 16;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(632, 66);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(161, 16);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Информация о фильме:";
			// 
			// listBox_schedule
			// 
			this->listBox_schedule->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->listBox_schedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->listBox_schedule->FormattingEnabled = true;
			this->listBox_schedule->HorizontalScrollbar = true;
			this->listBox_schedule->ItemHeight = 16;
			this->listBox_schedule->Location = System::Drawing::Point(634, 259);
			this->listBox_schedule->Name = L"listBox_schedule";
			this->listBox_schedule->Size = System::Drawing::Size(226, 100);
			this->listBox_schedule->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(631, 236);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(140, 16);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Расписание показа:";
			// 
			// button_schedule
			// 
			this->button_schedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_schedule->Location = System::Drawing::Point(688, 370);
			this->button_schedule->Name = L"button_schedule";
			this->button_schedule->Size = System::Drawing::Size(124, 35);
			this->button_schedule->TabIndex = 20;
			this->button_schedule->Text = L"Добавить (забронировать)";
			this->button_schedule->UseVisualStyleBackColor = true;
			this->button_schedule->Click += gcnew System::EventHandler(this, &MainWindow::button_schedule_Click);
			// 
			// button_saved
			// 
			this->button_saved->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_saved->Location = System::Drawing::Point(702, 436);
			this->button_saved->Name = L"button_saved";
			this->button_saved->Size = System::Drawing::Size(159, 42);
			this->button_saved->TabIndex = 21;
			this->button_saved->Text = L"Мои сеансы";
			this->button_saved->UseVisualStyleBackColor = true;
			this->button_saved->Click += gcnew System::EventHandler(this, &MainWindow::button_saved_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(225, 25);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(200, 24);
			this->label11->TabIndex = 22;
			this->label11->Text = L"Результаты поиска";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(896, 498);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button_saved);
			this->Controls->Add(this->button_schedule);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->listBox_schedule);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox_description);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->listBox_results);
			this->Controls->Add(this->button_filter);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_age);
			this->Controls->Add(this->textBox_cost);
			this->Controls->Add(this->textBox_duration);
			this->Controls->Add(this->comboBox_genre);
			this->Controls->Add(this->comboBox_country);
			this->Controls->Add(this->label1);
			this->Name = L"MainWindow";
			this->Text = L"Cinema";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_saved_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e);
//private: System::Void button_getDescription_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void listBox_results_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_schedule_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_filter_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void textBox_duration_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == (char)8))) {
		return;
	}
	e->Handled = true;
}
private: System::Void textBox_cost_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == (char)8))) {
		return;
	}
	e->Handled = true;
}
private: System::Void textBox_age_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == (char)8))) {
		return;
	}
	e->Handled = true;
}



};
}
