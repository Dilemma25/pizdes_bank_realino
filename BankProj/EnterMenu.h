#pragma once
#include "UserMenu1.h"
#include "AdminMenu1.h"




namespace BankProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class EnterMenu : public System::Windows::Forms::Form
	{

	public:
		System::String^ currentId;
	

	public:
		EnterMenu(void)
		{
			InitializeComponent();
			PasswordTextBox->UseSystemPasswordChar = true;
		}
public:
    property System::String^ CurrentId {
        System::String^ get() {
            return currentId;
        }

    }
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EnterMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ EnterLabel;
	protected:

	private: System::Windows::Forms::Button^ Exit_button;
	private: System::Windows::Forms::TextBox^ LoginTextBox;

	private: System::Windows::Forms::TextBox^ PasswordTextBox;
	private: System::Windows::Forms::Label^ PasswordLabel;

	private: System::Windows::Forms::Label^ LoginLabel;
	private: System::Windows::Forms::Button^ LogInButton;
	private: System::Windows::Forms::CheckBox^ PasswordShowCheckBox;








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
			this->EnterLabel = (gcnew System::Windows::Forms::Label());
			this->Exit_button = (gcnew System::Windows::Forms::Button());
			this->LoginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->LoginLabel = (gcnew System::Windows::Forms::Label());
			this->LogInButton = (gcnew System::Windows::Forms::Button());
			this->PasswordShowCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// EnterLabel
			// 
			this->EnterLabel->AutoSize = true;
			this->EnterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterLabel->Location = System::Drawing::Point(124, 92);
			this->EnterLabel->Name = L"EnterLabel";
			this->EnterLabel->Size = System::Drawing::Size(47, 16);
			this->EnterLabel->TabIndex = 0;
			this->EnterLabel->Text = L"ВХОД";
			// 
			// Exit_button
			// 
			this->Exit_button->BackColor = System::Drawing::Color::Red;
			this->Exit_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Exit_button->FlatAppearance->BorderSize = 0;
			this->Exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Exit_button->Location = System::Drawing::Point(263, 12);
			this->Exit_button->Name = L"Exit_button";
			this->Exit_button->Size = System::Drawing::Size(25, 25);
			this->Exit_button->TabIndex = 1;
			this->Exit_button->Text = L"x";
			this->Exit_button->UseVisualStyleBackColor = false;
			this->Exit_button->Click += gcnew System::EventHandler(this, &EnterMenu::Exit_button_Click);
			// 
			// LoginTextBox
			// 
			this->LoginTextBox->Location = System::Drawing::Point(81, 125);
			this->LoginTextBox->Name = L"LoginTextBox";
			this->LoginTextBox->Size = System::Drawing::Size(151, 22);
			this->LoginTextBox->TabIndex = 2;
			// 
			// PasswordTextBox
			// 
			this->PasswordTextBox->Location = System::Drawing::Point(81, 170);
			this->PasswordTextBox->Name = L"PasswordTextBox";
			this->PasswordTextBox->Size = System::Drawing::Size(151, 22);
			this->PasswordTextBox->TabIndex = 3;
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Location = System::Drawing::Point(12, 170);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(59, 16);
			this->PasswordLabel->TabIndex = 4;
			this->PasswordLabel->Text = L"Пароль:";
			// 
			// LoginLabel
			// 
			this->LoginLabel->AutoSize = true;
			this->LoginLabel->Location = System::Drawing::Point(12, 128);
			this->LoginLabel->Name = L"LoginLabel";
			this->LoginLabel->Size = System::Drawing::Size(49, 16);
			this->LoginLabel->TabIndex = 5;
			this->LoginLabel->Text = L"Логин:";
			// 
			// LogInButton
			// 
			this->LogInButton->BackColor = System::Drawing::SystemColors::ControlLight;
			this->LogInButton->Location = System::Drawing::Point(111, 226);
			this->LogInButton->Name = L"LogInButton";
			this->LogInButton->Size = System::Drawing::Size(75, 26);
			this->LogInButton->TabIndex = 6;
			this->LogInButton->Text = L"войти";
			this->LogInButton->UseVisualStyleBackColor = false;
			this->LogInButton->Click += gcnew System::EventHandler(this, &EnterMenu::LogInButton_Click);
			// 
			// PasswordShowCheckBox
			// 
			this->PasswordShowCheckBox->AutoSize = true;
			this->PasswordShowCheckBox->Location = System::Drawing::Point(146, 198);
			this->PasswordShowCheckBox->Name = L"PasswordShowCheckBox";
			this->PasswordShowCheckBox->Size = System::Drawing::Size(142, 20);
			this->PasswordShowCheckBox->TabIndex = 7;
			this->PasswordShowCheckBox->Text = L"Показать пароль";
			this->PasswordShowCheckBox->UseVisualStyleBackColor = true;
			this->PasswordShowCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EnterMenu::PasswordShowCheckBox_CheckedChanged);
			// 
			// EnterMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Controls->Add(this->PasswordShowCheckBox);
			this->Controls->Add(this->LogInButton);
			this->Controls->Add(this->LoginLabel);
			this->Controls->Add(this->PasswordLabel);
			this->Controls->Add(this->PasswordTextBox);
			this->Controls->Add(this->LoginTextBox);
			this->Controls->Add(this->Exit_button);
			this->Controls->Add(this->EnterLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"EnterMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		ref class UserCredentials {
		public:
			property System::String^ Id;
			property System::String^ Login;
			property System::String^ Password;

			UserCredentials() {
				Id = " ";
				Login = " ";
				Password = " ";
			}

			UserCredentials(System::String^ id, System::String^ login, System::String^ password) {
				Id = id;
				Login = login;
				Password = password;
			}
		};

	
		System::Void LogInButton_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ currentId = "0";
			//пароль админа
			UserCredentials^ admin = gcnew UserCredentials("0", "admin", "12345");
			// Предположим, что у вас есть list users с экземплярами UserCredentials
			List<UserCredentials^>^ listOfUsers = gcnew List<UserCredentials^>();

			listOfUsers->Add(gcnew UserCredentials("34344116", "testOne", "password1"));
			listOfUsers->Add(gcnew UserCredentials("34344247", "testTwo", "password2"));
			// Добавьте другие пары логин-пароль-id по мере необходимости

			// Получаем введенные логин и пароль из текстовых полей
			System::String^ enteredLogin = this->LoginTextBox->Text;
			System::String^ enteredPassword = this->PasswordTextBox->Text;

			// Проверяем, есть ли в массиве экземпляр UserCredentials с введенным логином и паролем
			bool loginSuccessful = false;
			for each (UserCredentials ^ user in listOfUsers) {
				if (user->Login == enteredLogin && user->Password == enteredPassword) {
					loginSuccessful = true;
					currentId = user->Id;
					break;
				}
				else if (admin->Login == enteredLogin && admin->Password == enteredPassword) {
					AdminMenu1^ adminMenu = gcnew AdminMenu1();
					this->Hide();
					adminMenu->ShowDialog();
					this->Close();
					
				}
				
			}

			// Если вход успешен, переходим к UserMenu1, иначе выводим сообщение об ошибке
			if (loginSuccessful) {
				UserMenu1^ userMenu = gcnew UserMenu1();
				this->Hide();
				userMenu->ShowDialog();
				this->Close();
			}
			else {
				MessageBox::Show("Неверный логин или пароль", "Ошибка входа", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

			

		private: System::Void Exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

private: System::Void PasswordShowCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (PasswordShowCheckBox->Checked)
	{
		PasswordTextBox->UseSystemPasswordChar = false;
	}
	else 
	{
		PasswordTextBox->UseSystemPasswordChar = true;
	}
}
};
}
