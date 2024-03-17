#pragma once
#include "UserMenu2.h"
#include "Singleton.h"
#include "Strategy.h"
#include "EnterMenu.h"
#include <vector>
#include "AdminMenu2.h"

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
	public ref class UserMenu1 : public System::Windows::Forms::Form
	{
	public:
		EnterMenu^ enterForm;
		std::string ConvertSystemStringToStdString(System::String^ systemString);
	public:
		UserMenu1(EnterMenu^ enterForm)
		{
			InitializeComponent();
			this->enterForm = enterForm;
			std::vector<Account*> UserAccounts = DataBase::getConnection()->getAllAccounts();
			SetUserAccountStrategy;
			System::String^ id = enterForm->CurrentId;

			std::string currenIdNow = ConvertSystemStringToStdString(id);
			Account* userAccount = DataBase::getConnection()->findAccount(currenIdNow);

			if (!userAccount) {
				throw std::exception("Cant set user account");
			}

			DataBase::getConnection()->linkTransacionsWithUserAccount(userAccount);

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~UserMenu1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ Exit_button;
	private: System::Windows::Forms::Label^ GreetingsLabel;
	private: System::Windows::Forms::Label^ UserMoneyLabel;
	private: System::Windows::Forms::Button^ AddMoneyButton;
	private: System::Windows::Forms::Button^ RemoveMoneyButton;
	private: System::Windows::Forms::Button^ TransactionButton;
	private: System::Windows::Forms::ListBox^ TransactionsListBox;

	private: System::Windows::Forms::Label^ TransactionsLabel;

	private: System::Windows::Forms::Button^ AcceptButton;
	private: System::Windows::Forms::Label^ DatesLabel;


	private: System::Windows::Forms::Label^ betweendates;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;




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
			this->GreetingsLabel = (gcnew System::Windows::Forms::Label());
			this->UserMoneyLabel = (gcnew System::Windows::Forms::Label());
			this->AddMoneyButton = (gcnew System::Windows::Forms::Button());
			this->RemoveMoneyButton = (gcnew System::Windows::Forms::Button());
			this->TransactionButton = (gcnew System::Windows::Forms::Button());
			this->TransactionsListBox = (gcnew System::Windows::Forms::ListBox());
			this->TransactionsLabel = (gcnew System::Windows::Forms::Label());
			this->AcceptButton = (gcnew System::Windows::Forms::Button());
			this->DatesLabel = (gcnew System::Windows::Forms::Label());
			this->betweendates = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// Exit_button
			// 
			this->Exit_button->BackColor = System::Drawing::Color::Red;
			this->Exit_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Exit_button->FlatAppearance->BorderSize = 0;
			this->Exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Exit_button->Location = System::Drawing::Point(363, 12);
			this->Exit_button->Name = L"Exit_button";
			this->Exit_button->Size = System::Drawing::Size(25, 25);
			this->Exit_button->TabIndex = 1;
			this->Exit_button->Text = L"x";
			this->Exit_button->UseVisualStyleBackColor = false;
			this->Exit_button->Click += gcnew System::EventHandler(this, &UserMenu1::Exit_button_Click);
			// 
			// GreetingsLabel
			// 
			this->GreetingsLabel->AutoSize = true;
			this->GreetingsLabel->Location = System::Drawing::Point(12, 21);
			this->GreetingsLabel->Name = L"GreetingsLabel";
			this->GreetingsLabel->Size = System::Drawing::Size(130, 16);
			this->GreetingsLabel->TabIndex = 2;
			this->GreetingsLabel->Text = L"Добро пожаловать";
			// 
			// UserMoneyLabel
			// 
			this->UserMoneyLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->UserMoneyLabel->Location = System::Drawing::Point(55, 54);
			this->UserMoneyLabel->Name = L"UserMoneyLabel";
			this->UserMoneyLabel->Size = System::Drawing::Size(250, 23);
			this->UserMoneyLabel->TabIndex = 3;
			this->UserMoneyLabel->Text = L"0";
			// 
			// AddMoneyButton
			// 
			this->AddMoneyButton->Location = System::Drawing::Point(55, 80);
			this->AddMoneyButton->Name = L"AddMoneyButton";
			this->AddMoneyButton->Size = System::Drawing::Size(75, 23);
			this->AddMoneyButton->TabIndex = 4;
			this->AddMoneyButton->Text = L"Внести";
			this->AddMoneyButton->UseVisualStyleBackColor = true;
			// 
			// RemoveMoneyButton
			// 
			this->RemoveMoneyButton->Location = System::Drawing::Point(230, 80);
			this->RemoveMoneyButton->Name = L"RemoveMoneyButton";
			this->RemoveMoneyButton->Size = System::Drawing::Size(75, 23);
			this->RemoveMoneyButton->TabIndex = 5;
			this->RemoveMoneyButton->Text = L"Снять";
			this->RemoveMoneyButton->UseVisualStyleBackColor = true;
			// 
			// TransactionButton
			// 
			this->TransactionButton->Location = System::Drawing::Point(127, 109);
			this->TransactionButton->Name = L"TransactionButton";
			this->TransactionButton->Size = System::Drawing::Size(101, 23);
			this->TransactionButton->TabIndex = 6;
			this->TransactionButton->Text = L"Перевести";
			this->TransactionButton->UseVisualStyleBackColor = true;
			this->TransactionButton->Click += gcnew System::EventHandler(this, &UserMenu1::TransactionButton_Click);
			// 
			// TransactionsListBox
			// 
			this->TransactionsListBox->FormattingEnabled = true;
			this->TransactionsListBox->ItemHeight = 16;
			this->TransactionsListBox->Location = System::Drawing::Point(12, 227);
			this->TransactionsListBox->Name = L"TransactionsListBox";
			this->TransactionsListBox->Size = System::Drawing::Size(376, 164);
			this->TransactionsListBox->TabIndex = 7;
			// 
			// TransactionsLabel
			// 
			this->TransactionsLabel->AutoSize = true;
			this->TransactionsLabel->Location = System::Drawing::Point(12, 208);
			this->TransactionsLabel->Name = L"TransactionsLabel";
			this->TransactionsLabel->Size = System::Drawing::Size(138, 16);
			this->TransactionsLabel->TabIndex = 8;
			this->TransactionsLabel->Text = L"Список транзакций:";
			// 
			// AcceptButton
			// 
			this->AcceptButton->Location = System::Drawing::Point(342, 198);
			this->AcceptButton->Name = L"AcceptButton";
			this->AcceptButton->Size = System::Drawing::Size(46, 23);
			this->AcceptButton->TabIndex = 10;
			this->AcceptButton->Text = L"ok";
			this->AcceptButton->UseVisualStyleBackColor = true;
			// 
			// DatesLabel
			// 
			this->DatesLabel->AutoSize = true;
			this->DatesLabel->Location = System::Drawing::Point(12, 144);
			this->DatesLabel->Name = L"DatesLabel";
			this->DatesLabel->Size = System::Drawing::Size(185, 16);
			this->DatesLabel->TabIndex = 11;
			this->DatesLabel->Text = L"Введите сроки транзакций";
			// 
			// betweendates
			// 
			this->betweendates->AutoSize = true;
			this->betweendates->Location = System::Drawing::Point(186, 171);
			this->betweendates->Name = L"betweendates";
			this->betweendates->Size = System::Drawing::Size(11, 16);
			this->betweendates->TabIndex = 13;
			this->betweendates->Text = L"-";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(12, 171);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(166, 22);
			this->dateTimePicker1->TabIndex = 14;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(207, 171);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(166, 22);
			this->dateTimePicker2->TabIndex = 15;
			// 
			// UserMenu1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(400, 400);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->betweendates);
			this->Controls->Add(this->DatesLabel);
			this->Controls->Add(this->AcceptButton);
			this->Controls->Add(this->TransactionsLabel);
			this->Controls->Add(this->TransactionsListBox);
			this->Controls->Add(this->TransactionButton);
			this->Controls->Add(this->RemoveMoneyButton);
			this->Controls->Add(this->AddMoneyButton);
			this->Controls->Add(this->UserMoneyLabel);
			this->Controls->Add(this->GreetingsLabel);
			this->Controls->Add(this->Exit_button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"UserMenu1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
std::string ConvertSystemStringToStdString(System::String^ systemString) {
			// Получаем указатель на начало строки .NET
			const wchar_t* chars = (const wchar_t*)(System::Runtime::InteropServices::Marshal::StringToHGlobalUni(systemString)).ToPointer();

			// Инициализируем std::wstring с помощью указателя на строку .NET
			std::wstring ws(chars);

			// Освобождаем память, выделенную для строки .NET
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));

			// Используем конструктор std::string, принимающий std::wstring
			return std::string(ws.begin(), ws.end());
}
		
	private: System::Void Exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}


private: System::Void TransactionButton_Click(System::Object^ sender, System::EventArgs^ e) {
		UserMenu2^ UserMenu = gcnew UserMenu2();
		UserMenu->ShowDialog();
}
};
}
