#pragma once
#include "Strategy.h"
#include "Validator.h"
#include <msclr\marshal_cppstd.h>
#include "String"

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
	public ref class AdminMenu2 : public System::Windows::Forms::Form
	{
	public:
		AdminMenu2(void)
		{
			InitializeComponent();
			PasswordAddTextBox->UseSystemPasswordChar = true;
			PasswordAddConfirmTextBox->UseSystemPasswordChar = true;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AdminMenu2()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private: System::Windows::Forms::Button^ Exit_button;
	private: System::Windows::Forms::Label^ AdminLabel2;

	private: System::Windows::Forms::TextBox^ LoginAddTextBox;

	private: System::Windows::Forms::Label^ LoginAdd;
	private: System::Windows::Forms::Label^ PasswordAdd;
	private: System::Windows::Forms::Label^ PasswordAddConfirm;
	private: System::Windows::Forms::TextBox^ PasswordAddTextBox;
	private: System::Windows::Forms::TextBox^ PasswordAddConfirmTextBox;
	private: System::Windows::Forms::TextBox^ StarterBalanceTextBox;






	private: System::Windows::Forms::Label^ StartingBalance;

	private: System::Windows::Forms::Button^ AcceptButtonAdm1;

	private: System::Windows::Forms::Button^ BackButtonAdm2;




























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
			this->AdminLabel2 = (gcnew System::Windows::Forms::Label());
			this->LoginAddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LoginAdd = (gcnew System::Windows::Forms::Label());
			this->PasswordAdd = (gcnew System::Windows::Forms::Label());
			this->PasswordAddConfirm = (gcnew System::Windows::Forms::Label());
			this->PasswordAddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordAddConfirmTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarterBalanceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StartingBalance = (gcnew System::Windows::Forms::Label());
			this->AcceptButtonAdm1 = (gcnew System::Windows::Forms::Button());
			this->BackButtonAdm2 = (gcnew System::Windows::Forms::Button());
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
			this->Exit_button->Click += gcnew System::EventHandler(this, &AdminMenu2::Exit_button_Click);
			// 
			// AdminLabel2
			// 
			this->AdminLabel2->AutoSize = true;
			this->AdminLabel2->Location = System::Drawing::Point(13, 12);
			this->AdminLabel2->Name = L"AdminLabel2";
			this->AdminLabel2->Size = System::Drawing::Size(289, 16);
			this->AdminLabel2->TabIndex = 2;
			this->AdminLabel2->Text = L"Введите данные для нового пользователя:";
			// 
			// LoginAddTextBox
			// 
			this->LoginAddTextBox->Location = System::Drawing::Point(15, 82);
			this->LoginAddTextBox->Name = L"LoginAddTextBox";
			this->LoginAddTextBox->Size = System::Drawing::Size(373, 22);
			this->LoginAddTextBox->TabIndex = 3;
			// 
			// LoginAdd
			// 
			this->LoginAdd->AutoSize = true;
			this->LoginAdd->Location = System::Drawing::Point(13, 63);
			this->LoginAdd->Name = L"LoginAdd";
			this->LoginAdd->Size = System::Drawing::Size(46, 16);
			this->LoginAdd->TabIndex = 4;
			this->LoginAdd->Text = L"Логин";
			// 
			// PasswordAdd
			// 
			this->PasswordAdd->AutoSize = true;
			this->PasswordAdd->Location = System::Drawing::Point(12, 113);
			this->PasswordAdd->Name = L"PasswordAdd";
			this->PasswordAdd->Size = System::Drawing::Size(56, 16);
			this->PasswordAdd->TabIndex = 5;
			this->PasswordAdd->Text = L"Пароль";
			// 
			// PasswordAddConfirm
			// 
			this->PasswordAddConfirm->AutoSize = true;
			this->PasswordAddConfirm->Location = System::Drawing::Point(12, 167);
			this->PasswordAddConfirm->Name = L"PasswordAddConfirm";
			this->PasswordAddConfirm->Size = System::Drawing::Size(163, 16);
			this->PasswordAddConfirm->TabIndex = 6;
			this->PasswordAddConfirm->Text = L"Подтверждение пароля";
			// 
			// PasswordAddTextBox
			// 
			this->PasswordAddTextBox->Location = System::Drawing::Point(12, 132);
			this->PasswordAddTextBox->Name = L"PasswordAddTextBox";
			this->PasswordAddTextBox->Size = System::Drawing::Size(376, 22);
			this->PasswordAddTextBox->TabIndex = 7;
			// 
			// PasswordAddConfirmTextBox
			// 
			this->PasswordAddConfirmTextBox->Location = System::Drawing::Point(12, 186);
			this->PasswordAddConfirmTextBox->Name = L"PasswordAddConfirmTextBox";
			this->PasswordAddConfirmTextBox->Size = System::Drawing::Size(376, 22);
			this->PasswordAddConfirmTextBox->TabIndex = 8;
			// 
			// StarterBalanceTextBox
			// 
			this->StarterBalanceTextBox->Location = System::Drawing::Point(12, 239);
			this->StarterBalanceTextBox->Name = L"StarterBalanceTextBox";
			this->StarterBalanceTextBox->Size = System::Drawing::Size(376, 22);
			this->StarterBalanceTextBox->TabIndex = 9;
			this->StarterBalanceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdminMenu2::StarterBalanceTextBox_KeyPress);
			// 
			// StartingBalance
			// 
			this->StartingBalance->AutoSize = true;
			this->StartingBalance->Location = System::Drawing::Point(12, 220);
			this->StartingBalance->Name = L"StartingBalance";
			this->StartingBalance->Size = System::Drawing::Size(131, 16);
			this->StartingBalance->TabIndex = 10;
			this->StartingBalance->Text = L"Начальный баланс";
			// 
			// AcceptButtonAdm1
			// 
			this->AcceptButtonAdm1->Location = System::Drawing::Point(257, 310);
			this->AcceptButtonAdm1->Name = L"AcceptButtonAdm1";
			this->AcceptButtonAdm1->Size = System::Drawing::Size(131, 23);
			this->AcceptButtonAdm1->TabIndex = 11;
			this->AcceptButtonAdm1->Text = L"Подтвердить";
			this->AcceptButtonAdm1->UseVisualStyleBackColor = true;
			this->AcceptButtonAdm1->Click += gcnew System::EventHandler(this, &AdminMenu2::AcceptButtonAdm1_Click);
			// 
			// BackButtonAdm2
			// 
			this->BackButtonAdm2->Location = System::Drawing::Point(12, 310);
			this->BackButtonAdm2->Name = L"BackButtonAdm2";
			this->BackButtonAdm2->Size = System::Drawing::Size(131, 23);
			this->BackButtonAdm2->TabIndex = 12;
			this->BackButtonAdm2->Text = L"Назад";
			this->BackButtonAdm2->UseVisualStyleBackColor = true;
			this->BackButtonAdm2->Click += gcnew System::EventHandler(this, &AdminMenu2::Exit_button_Click);
			// 
			// AdminMenu2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(400, 400);
			this->Controls->Add(this->BackButtonAdm2);
			this->Controls->Add(this->AcceptButtonAdm1);
			this->Controls->Add(this->StartingBalance);
			this->Controls->Add(this->StarterBalanceTextBox);
			this->Controls->Add(this->PasswordAddConfirmTextBox);
			this->Controls->Add(this->PasswordAddTextBox);
			this->Controls->Add(this->PasswordAddConfirm);
			this->Controls->Add(this->PasswordAdd);
			this->Controls->Add(this->LoginAdd);
			this->Controls->Add(this->LoginAddTextBox);
			this->Controls->Add(this->AdminLabel2);
			this->Controls->Add(this->Exit_button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AdminMenu2";
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
	
private: System::Void AcceptButtonAdm1_Click(System::Object^ sender, System::EventArgs^ e) {
	{
		
		// Преобразование System::String^ в std::string
		System::String^ nameStr = this->LoginAddTextBox->Text;
		std::string name;
		name = ConvertSystemStringToStdString(nameStr);

		// Преобразование System::String^ в double
		System::String^ balancepre = this->StarterBalanceTextBox->Text;
		double balance = System::Convert::ToDouble(balancepre);
		// Используем метод ToDouble для преобразования строки в double
	
		
		Account* newAccount = new Account(name, balance);
		DataBase::getConnection()->insertNewAccount(newAccount);
		DataBase::getConnection()->insertAllAccountsInFileAndDeleteAccountsPtrs();
		 //мб надо айди показать 
	}
}


//в балансе только цифры
private: System::Void StarterBalanceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	TextBox^ textBox = safe_cast<TextBox^>(sender);

	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '.'))
	{
		e->Handled = true;
	}

	// only allow one decimal point
	if ((e->KeyChar == '.') && (textBox->Text->IndexOf('.') != -1))
	{
		e->Handled = true;
	}
}

};
}
