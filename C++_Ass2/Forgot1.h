#pragma once

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Forgot
	/// </summary>
	public ref class Forgot : public System::Windows::Forms::Form
	{
	public:
		Forgot(void)
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
		~Forgot()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtNID;



	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ txtCode;
	private: System::Windows::Forms::ComboBox^ cmbUserType;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cmbUserType = (gcnew System::Windows::Forms::ComboBox());
			this->txtCode = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtNID = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->cmbUserType);
			this->panel1->Controls->Add(this->txtCode);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->txtNID);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(124, 63);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(624, 366);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Forgot::panel1_Paint);
			// 
			// cmbUserType
			// 
			this->cmbUserType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbUserType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbUserType->FormattingEnabled = true;
			this->cmbUserType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Professor", L"Admin" });
			this->cmbUserType->Location = System::Drawing::Point(464, 14);
			this->cmbUserType->Name = L"cmbUserType";
			this->cmbUserType->Size = System::Drawing::Size(148, 33);
			this->cmbUserType->TabIndex = 11;
			// 
			// txtCode
			// 
			this->txtCode->AutoSize = true;
			this->txtCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCode->ForeColor = System::Drawing::Color::White;
			this->txtCode->Location = System::Drawing::Point(262, 269);
			this->txtCode->Name = L"txtCode";
			this->txtCode->Size = System::Drawing::Size(0, 33);
			this->txtCode->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(251, 165);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 34);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Show";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Forgot::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(223, 221);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(178, 33);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Your code is";
			this->label2->Click += gcnew System::EventHandler(this, &Forgot::label2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(199, 305);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(226, 48);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Forgot::button1_Click);
			// 
			// txtNID
			// 
			this->txtNID->Location = System::Drawing::Point(302, 103);
			this->txtNID->Multiline = true;
			this->txtNID->Name = L"txtNID";
			this->txtNID->Size = System::Drawing::Size(248, 33);
			this->txtNID->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(40, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(234, 33);
			this->label3->TabIndex = 2;
			this->label3->Text = L"National Number";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(206, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Forgot Code";
			this->label1->Click += gcnew System::EventHandler(this, &Forgot::label1_Click);
			// 
			// Forgot
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(872, 493);
			this->Controls->Add(this->panel1);
			this->Name = L"Forgot";
			this->Text = L"Forgot";
			this->Load += gcnew System::EventHandler(this, &Forgot::Forgot_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Forgot_Load(System::Object^ sender, System::EventArgs^ e) {
		}

	// declaration only — implementation in Forgot1.cpp to avoid circular include
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtNID->Text))
		{
			MessageBox::Show("Please enter National ID", "Try Again", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		if (cmbUserType->SelectedIndex == -1)
		{
			MessageBox::Show("Please select user type");
			return;
		}

		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		try
		{
			conn->Open();

			String^ query;
			SqlCommand^ cmd;

			// ================= Student =================
			if (cmbUserType->Text == "Student")
			{
				query = "SELECT code FROM Students WHERE NationalNumber = @nid";
				cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@nid", txtNID->Text);
			}
			// ================= Professor =================
			else if (cmbUserType->Text == "Professor")
			{
				query = "SELECT code FROM Professors WHERE NationalNumber = @nid";
				cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@nid", txtNID->Text);
			}
			else
			{
				MessageBox::Show("Forgot Code not available for Admin", "Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				return;
			}

			Object^ result = cmd->ExecuteScalar();

			if (result == nullptr)
			{
				MessageBox::Show("No user found with this National ID", "Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			txtCode->Text = result->ToString();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error");
		}
		finally
		{
			conn->Close();
		}
	}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}