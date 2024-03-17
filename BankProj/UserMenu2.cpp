#include "UserMenu2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int dmain(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BankProj::UserMenu2 form;
	Application::Run(% form);
	return 0;
}