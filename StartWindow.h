#pragma once

namespace Проект {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для StartWindow
	/// </summary>
	public ref class StartWindow : public System::Windows::Forms::Form
	{
	public:
		StartWindow(void)
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
		~StartWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_board;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button_saved;


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
			this->button_board = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_saved = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_board
			// 
			this->button_board->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_board->Location = System::Drawing::Point(118, 115);
			this->button_board->Name = L"button_board";
			this->button_board->Size = System::Drawing::Size(136, 39);
			this->button_board->TabIndex = 0;
			this->button_board->Text = L"смотреть афишу";
			this->button_board->UseVisualStyleBackColor = true;
			this->button_board->Click += gcnew System::EventHandler(this, &StartWindow::button_board_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(94, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 33);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Cinema View";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 348);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 26);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Разработал:      Окунев А.Д\r\nСтудент:             КЭ-204";
			// 
			// button_saved
			// 
			this->button_saved->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_saved->Location = System::Drawing::Point(118, 170);
			this->button_saved->Name = L"button_saved";
			this->button_saved->Size = System::Drawing::Size(136, 39);
			this->button_saved->TabIndex = 3;
			this->button_saved->Text = L"мои сеансы";
			this->button_saved->UseVisualStyleBackColor = true;
			this->button_saved->Click += gcnew System::EventHandler(this, &StartWindow::button_saved_Click);
			// 
			// StartWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 383);
			this->Controls->Add(this->button_saved);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_board);
			this->Name = L"StartWindow";
			this->Text = L"Cinema";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_board_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_saved_Click(System::Object^  sender, System::EventArgs^  e);

};
}
