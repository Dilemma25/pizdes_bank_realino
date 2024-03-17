#pragma once
#include "AdminMenu2.h"
#include "Singleton.h"

namespace BankProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class AdminMenu1 : public System::Windows::Forms::Form
	{
	public:
		AdminMenu1(void)
		{
			InitializeComponent();
			
			std::string line;
			std::ifstream inFile("Accounts.jsonl");
			while (std::getline(inFile, line)) {
				try {
					UsersBox->Items->Add((gcnew String(line.c_str())));
				}
				catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << '\n';
				}
			}
			inFile.close();

			std::string line1;
			std::ifstream inFile1("Transactions.txt");
			while (std::getline(inFile1, line1)) {
				try {
					TransactionsListBox2->Items->Add((gcnew String(line1.c_str())));
				}
				catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << '\n';
				}
			}
			inFile1.close();

			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AdminMenu1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ Exit_button;
	private: System::Windows::Forms::Label^ GreetingsLabelAdm;

	private: System::Windows::Forms::Label^ TransactionsLabel;
	private: System::Windows::Forms::ListBox^ TransactionsListBox2;

	private: System::Windows::Forms::Button^ NewPersonButton;
	private: System::Windows::Forms::ListBox^ UsersBox;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Exit_button = (gcnew System::Windows::Forms::Button());
			this->GreetingsLabelAdm = (gcnew System::Windows::Forms::Label());
			this->TransactionsLabel = (gcnew System::Windows::Forms::Label());
			this->TransactionsListBox2 = (gcnew System::Windows::Forms::ListBox());
			this->NewPersonButton = (gcnew System::Windows::Forms::Button());
			this->UsersBox = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// Exit_button
			// 
			this->Exit_button->BackColor = System::Drawing::Color::Red;
			this->Exit_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Exit_button->FlatAppearance->BorderSize = 0;
			this->Exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Exit_button->Location = System::Drawing::Point(572, 12);
			this->Exit_button->Name = L"Exit_button";
			this->Exit_button->Size = System::Drawing::Size(25, 25);
			this->Exit_button->TabIndex = 1;
			this->Exit_button->Text = L"x";
			this->Exit_button->UseVisualStyleBackColor = false;
			this->Exit_button->Click += gcnew System::EventHandler(this, &AdminMenu1::Exit_button_Click);
			// 
			// GreetingsLabelAdm
			// 
			this->GreetingsLabelAdm->AutoSize = true;
			this->GreetingsLabelAdm->Location = System::Drawing::Point(12, 21);
			this->GreetingsLabelAdm->Name = L"GreetingsLabelAdm";
			this->GreetingsLabelAdm->Size = System::Drawing::Size(130, 16);
			this->GreetingsLabelAdm->TabIndex = 2;
			this->GreetingsLabelAdm->Text = L"Добро пожаловать";
			// 
			// TransactionsLabel
			// 
			this->TransactionsLabel->AutoSize = true;
			this->TransactionsLabel->Location = System::Drawing::Point(12, 201);
			this->TransactionsLabel->Name = L"TransactionsLabel";
			this->TransactionsLabel->Size = System::Drawing::Size(275, 16);
			this->TransactionsLabel->TabIndex = 8;
			this->TransactionsLabel->Text = L"Список транзакций всех пользователей:";
			// 
			// TransactionsListBox2
			// 
			this->TransactionsListBox2->FormattingEnabled = true;
			this->TransactionsListBox2->ItemHeight = 16;
			this->TransactionsListBox2->Location = System::Drawing::Point(12, 220);
			this->TransactionsListBox2->Name = L"TransactionsListBox2";
			this->TransactionsListBox2->Size = System::Drawing::Size(585, 196);
			this->TransactionsListBox2->TabIndex = 7;
			// 
			// NewPersonButton
			// 
			this->NewPersonButton->Location = System::Drawing::Point(12, 175);
			this->NewPersonButton->Name = L"NewPersonButton";
			this->NewPersonButton->Size = System::Drawing::Size(247, 23);
			this->NewPersonButton->TabIndex = 6;
			this->NewPersonButton->Text = L"Добавить нового пользователя";
			this->NewPersonButton->UseVisualStyleBackColor = true;
			this->NewPersonButton->Click += gcnew System::EventHandler(this, &AdminMenu1::TransactionButton_Click);
			// 
			// UsersBox
			// 
			this->UsersBox->FormattingEnabled = true;
			this->UsersBox->ItemHeight = 16;
			this->UsersBox->Location = System::Drawing::Point(12, 40);
			this->UsersBox->Name = L"UsersBox";
			this->UsersBox->Size = System::Drawing::Size(376, 132);
			this->UsersBox->TabIndex = 9;
			// 
			// AdminMenu1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(609, 440);
			this->Controls->Add(this->UsersBox);
			this->Controls->Add(this->TransactionsLabel);
			this->Controls->Add(this->TransactionsListBox2);
			this->Controls->Add(this->NewPersonButton);
			this->Controls->Add(this->GreetingsLabelAdm);
			this->Controls->Add(this->Exit_button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AdminMenu1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void Exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}





	private: System::Void TransactionButton_Click(System::Object^ sender, System::EventArgs^ e) {
		AdminMenu2^ adminMenu = gcnew AdminMenu2();
		adminMenu->ShowDialog();
	}
};
}
