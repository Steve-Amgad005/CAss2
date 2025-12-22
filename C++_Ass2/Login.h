#pragma once
#include "Forgot1.h"
#include "StudetMainPage.h"
#include "AdminPage.h"
#include "ProfessorPage.h"
using namespace System;
using namespace System::Data::SqlClient;
namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CAss2;
	using namespace System;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelCode;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelCode = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->labelCode);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(122, 62);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(624, 366);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Login::panel1_Paint);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Professor", L"Admin" });
			this->comboBox1->Location = System::Drawing::Point(460, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(148, 33);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Login::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(199, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(226, 48);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(443, 242);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Forgot code\?";
			this->label4->Click += gcnew System::EventHandler(this, &Login::label4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(299, 195);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(248, 33);
			this->textBox2->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(299, 126);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(248, 33);
			this->textBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(27, 195);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(234, 33);
			this->label3->TabIndex = 2;
			this->label3->Text = L"National Number";
			this->label3->Click += gcnew System::EventHandler(this, &Login::label3_Click);
			// 
			// labelCode
			// 
			this->labelCode->AutoSize = true;
			this->labelCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCode->ForeColor = System::Drawing::Color::White;
			this->labelCode->Location = System::Drawing::Point(48, 126);
			this->labelCode->Name = L"labelCode";
			this->labelCode->Size = System::Drawing::Size(191, 33);
			this->labelCode->TabIndex = 1;
			this->labelCode->Text = L"Student Code";
			this->labelCode->Click += gcnew System::EventHandler(this, &Login::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(255, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(872, 493);
			this->Controls->Add(this->panel1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	CAss2::Forgot^ forgotForm = gcnew CAss2::Forgot();
	forgotForm->Show();
	this->Hide();
}
private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	comboBox1->SelectedIndex = 0;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ role = comboBox1->SelectedItem->ToString();
	String^ v1 = textBox1->Text->Trim();
	String^ v2 = textBox2->Text->Trim();

	if (v1 == "" || v2 == "") {
		MessageBox::Show("Please enter all fields");
		return;
	}

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try {
		conn->Open();
		SqlCommand^ cmd = gcnew SqlCommand();
		cmd->Connection = conn;

		// ================= STUDENT =================
		if (role == "Student") {

			cmd->CommandText =
				"SELECT 1 FROM Students "
				"WHERE code = @v1 AND NationalNumber = @v2";

			cmd->Parameters->AddWithValue("@v1", Int32::Parse(v1));
			cmd->Parameters->AddWithValue("@v2", Int64::Parse(v2));

			if (cmd->ExecuteScalar() != nullptr) {
				MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				int codeInt = Int32::Parse(v1);
				StudetMainPage^ f = gcnew StudetMainPage(codeInt);
				f->Show();
				this->Hide();
			}
			else {
				MessageBox::Show("Invalid Code or NationalNumber", "Login failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		// ================= PROFESSOR =================
		else if (role == "Professor") {

			cmd->CommandText =
				"SELECT 1 FROM Professors "
				"WHERE code = @v1 AND NationalNumber = @v2";

			cmd->Parameters->AddWithValue("@v1", Int32::Parse(v1));
			cmd->Parameters->AddWithValue("@v2", Int64::Parse(v2));

			if (cmd->ExecuteScalar() != nullptr) {
				MessageBox::Show("Login successful!", "Success",MessageBoxButtons::OK, MessageBoxIcon::Information);
				int codeInt = Int32::Parse(v1);
				ProfessorPage^ f = gcnew ProfessorPage(codeInt);
				f->Show();
				this->Hide();
			}
			else {
				MessageBox::Show("Invalid Code or NationalNumber",
					"Login failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}


		// ================= ADMIN =================
		else if (role == "Admin") {

			cmd->CommandText =
				"SELECT 1 FROM Admins "
				"WHERE code = @v1 AND NationalNumber = @v2;";

			cmd->Parameters->AddWithValue("@v1", Int32::Parse(v1));
			cmd->Parameters->AddWithValue("@v2", Int64::Parse(v2));

			if (cmd->ExecuteScalar() != nullptr) {
				MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				int codeInt = Int32::Parse(v1);
				AdminPage^ f = gcnew AdminPage(codeInt);
				f->Show();
				this->Hide();
			}
			else {
				MessageBox::Show("Invalid Code or NationalNumber", "Login failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		conn->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->SelectedItem == nullptr)
		return;

	String^ role = comboBox1->SelectedItem->ToString();

	if (role == "Student")
	{
		labelCode->Text = "Student Code";
	}
	else if (role == "Professor")
	{
		labelCode->Text = "Professor Code";
	}
	else if (role == "Admin")
	{
		labelCode->Text = "Admin Code";
	}
}
};
}
