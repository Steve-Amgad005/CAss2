#include "Forgot1.h"
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
	// implement the Back button handler: show Login form and hide this form
	System::Void Forgot::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::Login^ loginForm = gcnew CAss2::Login();
		loginForm->Show();
		this->Hide();
	}
}