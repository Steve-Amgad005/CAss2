#include "StudetMainPage.h"
#include "Login.h"

using namespace CAss2;

// implement the back button click here to avoid circular include issues in header
System::Void StudetMainPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	CAss2::Login^ f = gcnew CAss2::Login();
	f->Show();
	this->Hide();
}

