#include "UserMenu1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int bmain(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BankProj::UserMenu1 form;
	Application::Run(% form);
	return 0;
}