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
	/// Summary for AdminModifyLap
	/// </summary>
	public ref class AdminModifyLap : public System::Windows::Forms::Form
	{
		int currentLabId = -1;

	public:
		AdminModifyLap(void)
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
		~AdminModifyLap()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckBox^ chkProjector;
	private: System::Windows::Forms::TextBox^ txtCapacity;
	protected:


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtACs;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtPCs;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtLabName;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtLabId;

	private: System::Windows::Forms::Button^ button1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtLabId = (gcnew System::Windows::Forms::TextBox());
			this->chkProjector = (gcnew System::Windows::Forms::CheckBox());
			this->txtCapacity = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtACs = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPCs = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtLabName = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txtLabId);
			this->panel1->Controls->Add(this->chkProjector);
			this->panel1->Controls->Add(this->txtCapacity);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtACs);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->txtPCs);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtLabName);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(40, 90);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 444);
			this->panel1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(143, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 30);
			this->button1->TabIndex = 37;
			this->button1->Text = L"Show";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminModifyLap::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(43, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 24);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Lap ID";
			// 
			// txtLabId
			// 
			this->txtLabId->Location = System::Drawing::Point(192, 25);
			this->txtLabId->Multiline = true;
			this->txtLabId->Name = L"txtLabId";
			this->txtLabId->Size = System::Drawing::Size(214, 33);
			this->txtLabId->TabIndex = 36;
			this->txtLabId->TextChanged += gcnew System::EventHandler(this, &AdminModifyLap::textBox5_TextChanged);
			// 
			// chkProjector
			// 
			this->chkProjector->AutoSize = true;
			this->chkProjector->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chkProjector->ForeColor = System::Drawing::Color::White;
			this->chkProjector->Location = System::Drawing::Point(29, 321);
			this->chkProjector->Name = L"chkProjector";
			this->chkProjector->Size = System::Drawing::Size(108, 29);
			this->chkProjector->TabIndex = 34;
			this->chkProjector->Text = L"Projector";
			this->chkProjector->UseVisualStyleBackColor = true;
			// 
			// txtCapacity
			// 
			this->txtCapacity->Location = System::Drawing::Point(192, 265);
			this->txtCapacity->Multiline = true;
			this->txtCapacity->Name = L"txtCapacity";
			this->txtCapacity->Size = System::Drawing::Size(214, 33);
			this->txtCapacity->TabIndex = 33;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(25, 274);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 24);
			this->label4->TabIndex = 32;
			this->label4->Text = L"Capacity";
			// 
			// txtACs
			// 
			this->txtACs->Location = System::Drawing::Point(192, 211);
			this->txtACs->Multiline = true;
			this->txtACs->Name = L"txtACs";
			this->txtACs->Size = System::Drawing::Size(214, 33);
			this->txtACs->TabIndex = 31;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(25, 220);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 24);
			this->label1->TabIndex = 30;
			this->label1->Text = L"No. Of ACs";
			// 
			// txtPCs
			// 
			this->txtPCs->Location = System::Drawing::Point(192, 159);
			this->txtPCs->Multiline = true;
			this->txtPCs->Name = L"txtPCs";
			this->txtPCs->Size = System::Drawing::Size(214, 33);
			this->txtPCs->TabIndex = 29;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(25, 123);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Lap Name";
			// 
			// txtLabName
			// 
			this->txtLabName->Location = System::Drawing::Point(192, 114);
			this->txtLabName->Multiline = true;
			this->txtLabName->Name = L"txtLabName";
			this->txtLabName->Size = System::Drawing::Size(214, 33);
			this->txtLabName->TabIndex = 22;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(25, 168);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"No. Of PCs";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(102, 374);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Modify";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminModifyLap::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(151, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 39);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Modify Lap";
			// 
			// AdminModifyLap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 546);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminModifyLap";
			this->Text = L"AdminModifyLap";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtLabId->Text))
		{
			MessageBox::Show("Enter Lab ID");
			return;
		}

		int labId = Convert::ToInt32(txtLabId->Text);

		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		try
		{
			conn->Open();

			SqlCommand^ cmd = gcnew SqlCommand(
				"SELECT name, capacity, computers_count, ac_count, has_projector "
				"FROM Labs WHERE id = @id",
				conn);

			cmd->Parameters->AddWithValue("@id", labId);

			SqlDataReader^ dr = cmd->ExecuteReader();

			if (!dr->Read())
			{
				MessageBox::Show("Lab not found");
				dr->Close();
				return;
			}

			// ✔ خزّن الـ ID
			currentLabId = labId;

			// ✔ عبّي البيانات
			txtLabName->Text = dr["name"]->ToString();
			txtCapacity->Text = dr["capacity"]->ToString();
			txtPCs->Text = dr["computers_count"]->ToString();
			txtACs->Text = dr["ac_count"]->ToString();
			chkProjector->Checked = Convert::ToBoolean(dr["has_projector"]);

			dr->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		finally
		{
			conn->Close();
		}
	}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	// =============================
	// Check Show First
	// =============================
	if (currentLabId == -1)
	{
		MessageBox::Show("Please click Show first");
		return;
	}

	// =============================
	// Validation
	// =============================
	if (String::IsNullOrWhiteSpace(txtLabName->Text))
	{
		MessageBox::Show("Enter lab name");
		return;
	}

	int capacity, pcs, acs;

	if (!Int32::TryParse(txtCapacity->Text, capacity) || capacity <= 0)
	{
		MessageBox::Show("Invalid capacity");
		return;
	}

	if (!Int32::TryParse(txtPCs->Text, pcs) || pcs < 0)
	{
		MessageBox::Show("Invalid PCs count");
		return;
	}

	if (!Int32::TryParse(txtACs->Text, acs) || acs < 0)
	{
		MessageBox::Show("Invalid ACs count");
		return;
	}

	bool hasProjector = chkProjector->Checked;

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try
	{
		conn->Open();

		SqlCommand^ cmd = gcnew SqlCommand(
			"UPDATE Labs SET "
			"name = @name, "
			"capacity = @capacity, "
			"computers_count = @pcs, "
			"ac_count = @acs, "
			"has_projector = @proj "
			"WHERE id = @id",
			conn);

		cmd->Parameters->AddWithValue("@name", txtLabName->Text);
		cmd->Parameters->AddWithValue("@capacity", capacity);
		cmd->Parameters->AddWithValue("@pcs", pcs);
		cmd->Parameters->AddWithValue("@acs", acs);
		cmd->Parameters->AddWithValue("@proj", hasProjector);
		cmd->Parameters->AddWithValue("@id", currentLabId);

		cmd->ExecuteNonQuery();

		MessageBox::Show("Lab updated successfully");

		// =============================
		// Reset
		// =============================
		currentLabId = -1;
		txtLabId->Clear();
		txtLabName->Clear();
		txtCapacity->Clear();
		txtPCs->Clear();
		txtACs->Clear();
		chkProjector->Checked = false;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
	finally
	{
		conn->Close();
	}
}
};
}
