#include "ProfessorPage.h"
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
	// implement the back button click to return to Login
	System::Void ProfessorPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::Login^ loginForm = gcnew CAss2::Login();
		loginForm->Show();
		this->Hide();
	}
}

