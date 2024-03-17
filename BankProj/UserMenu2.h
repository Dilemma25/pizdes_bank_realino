#pragma once


namespace BankProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class UserMenu2 : public System::Windows::Forms::Form
	{
	public:
		UserMenu2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~UserMenu2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ Exit_button;
	private: System::Windows::Forms::Label^ LoginLabelUser2;

	private: System::Windows::Forms::Button^ AcceptButtonUser2;
	private: System::Windows::Forms::TextBox^ LoginTextBoxUser2;
	private: System::Windows::Forms::Label^ TransitionAmountLabelUser2;
	private: System::Windows::Forms::TextBox^ TransitionAmountTextBoxUser2;












	private: System::Windows::Forms::Button^ BackButtonUser2;










	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Exit_button = (gcnew System::Windows::Forms::Button());
			this->LoginLabelUser2 = (gcnew System::Windows::Forms::Label());
			this->AcceptButtonUser2 = (gcnew System::Windows::Forms::Button());
			this->LoginTextBoxUser2 = (gcnew System::Windows::Forms::TextBox());
			this->TransitionAmountLabelUser2 = (gcnew System::Windows::Forms::Label());
			this->TransitionAmountTextBoxUser2 = (gcnew System::Windows::Forms::TextBox());
			this->BackButtonUser2 = (gcnew System::Windows::Forms::Button());
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
			this->Exit_button->Click += gcnew System::EventHandler(this, &UserMenu2::Exit_button_Click);
			// 
			// LoginLabelUser2
			// 
			this->LoginLabelUser2->AutoSize = true;
			this->LoginLabelUser2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoginLabelUser2->Location = System::Drawing::Point(12, 67);
			this->LoginLabelUser2->Name = L"LoginLabelUser2";
			this->LoginLabelUser2->Size = System::Drawing::Size(213, 16);
			this->LoginLabelUser2->TabIndex = 2;
			this->LoginLabelUser2->Text = L"¬ведите логин получател€:";
			// 
			// AcceptButtonUser2
			// 
			this->AcceptButtonUser2->Location = System::Drawing::Point(243, 245);
			this->AcceptButtonUser2->Name = L"AcceptButtonUser2";
			this->AcceptButtonUser2->Size = System::Drawing::Size(96, 23);
			this->AcceptButtonUser2->TabIndex = 10;
			this->AcceptButtonUser2->Text = L"ѕеревести";
			this->AcceptButtonUser2->UseVisualStyleBackColor = true;
			// 
			// LoginTextBoxUser2
			// 
			this->LoginTextBoxUser2->Location = System::Drawing::Point(12, 103);
			this->LoginTextBoxUser2->Name = L"LoginTextBoxUser2";
			this->LoginTextBoxUser2->Size = System::Drawing::Size(270, 22);
			this->LoginTextBoxUser2->TabIndex = 11;
			// 
			// TransitionAmountLabelUser2
			// 
			this->TransitionAmountLabelUser2->AutoSize = true;
			this->TransitionAmountLabelUser2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->TransitionAmountLabelUser2->Location = System::Drawing::Point(9, 143);
			this->TransitionAmountLabelUser2->Name = L"TransitionAmountLabelUser2";
			this->TransitionAmountLabelUser2->Size = System::Drawing::Size(230, 16);
			this->TransitionAmountLabelUser2->TabIndex = 12;
			this->TransitionAmountLabelUser2->Text = L"¬ведите сумму дл€ перевода:";
			// 
			// TransitionAmountTextBoxUser2
			// 
			this->TransitionAmountTextBoxUser2->Location = System::Drawing::Point(12, 176);
			this->TransitionAmountTextBoxUser2->Name = L"TransitionAmountTextBoxUser2";
			this->TransitionAmountTextBoxUser2->Size = System::Drawing::Size(270, 22);
			this->TransitionAmountTextBoxUser2->TabIndex = 13;
			// 
			// BackButtonUser2
			// 
			this->BackButtonUser2->Location = System::Drawing::Point(15, 245);
			this->BackButtonUser2->Name = L"BackButtonUser2";
			this->BackButtonUser2->Size = System::Drawing::Size(96, 23);
			this->BackButtonUser2->TabIndex = 14;
			this->BackButtonUser2->Text = L"Ќазад";
			this->BackButtonUser2->UseVisualStyleBackColor = true;
			this->BackButtonUser2->Click += gcnew System::EventHandler(this, &UserMenu2::BackButtonUser2_Click);
			// 
			// UserMenu2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(400, 400);
			this->Controls->Add(this->BackButtonUser2);
			this->Controls->Add(this->TransitionAmountTextBoxUser2);
			this->Controls->Add(this->TransitionAmountLabelUser2);
			this->Controls->Add(this->LoginTextBoxUser2);
			this->Controls->Add(this->AcceptButtonUser2);
			this->Controls->Add(this->LoginLabelUser2);
			this->Controls->Add(this->Exit_button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"UserMenu2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void Exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}





	private: System::Void BackButtonUser2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
