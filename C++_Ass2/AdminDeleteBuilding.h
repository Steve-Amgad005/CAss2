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
	/// Summary for AdminDeleteBuilding
	/// </summary>
	public ref class AdminDeleteBuilding : public System::Windows::Forms::Form
	{
	public:
		AdminDeleteBuilding(void)
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
		~AdminDeleteBuilding()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtBuildingId;

	private: System::Windows::Forms::Button^ button2;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtBuildingId = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(125, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(264, 39);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Delete Building";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->txtBuildingId);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(46, 109);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(442, 180);
			this->panel1->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(25, 29);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(100, 24);
			this->label8->TabIndex = 29;
			this->label8->Text = L"Building ID";
			this->label8->Click += gcnew System::EventHandler(this, &AdminDeleteBuilding::label8_Click);
			// 
			// txtBuildingId
			// 
			this->txtBuildingId->Location = System::Drawing::Point(192, 26);
			this->txtBuildingId->Multiline = true;
			this->txtBuildingId->Name = L"txtBuildingId";
			this->txtBuildingId->Size = System::Drawing::Size(214, 33);
			this->txtBuildingId->TabIndex = 30;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(112, 103);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminDeleteBuilding::button2_Click);
			// 
			// AdminDeleteBuilding
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(535, 335);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminDeleteBuilding";
			this->Text = L"AdminDeleteBuilding";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int buildingId = 0;

	// ==========================
	// 🔍 Validation
	// ==========================
	if (!Int32::TryParse(txtBuildingId->Text, buildingId))
	{
		MessageBox::Show("Please enter valid Building ID", "Validation Error");
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

		// ==========================
		// 1️⃣ Check if building exists
		// ==========================
		SqlCommand^ cmdCheck = gcnew SqlCommand(
			"SELECT COUNT(*) FROM Buildings WHERE id = @id",
			conn);

		cmdCheck->Parameters->AddWithValue("@id", buildingId);

		int exists = Convert::ToInt32(cmdCheck->ExecuteScalar());

		if (exists == 0)
		{
			MessageBox::Show("Building not found", "Error");
			conn->Close();
			return;
		}

		// ==========================
		// 2️⃣ Confirm delete
		// ==========================
	

		if (MessageBox::Show(
			"Are you sure you want to delete this building?",
			"Confirm Delete",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::Yes)
		{
			conn->Close();
			return;
		}

		// ==========================
		// 3️⃣ Delete Floors first
		// ==========================
		SqlCommand^ cmdDeleteFloors = gcnew SqlCommand(
			"DELETE FROM Floors WHERE building_id = @id",
			conn);

		cmdDeleteFloors->Parameters->AddWithValue("@id", buildingId);
		cmdDeleteFloors->ExecuteNonQuery();

		// ==========================
		// 4️⃣ Delete Building
		// ==========================
		SqlCommand^ cmdDeleteBuilding = gcnew SqlCommand(
			"DELETE FROM Buildings WHERE id = @id",
			conn);

		cmdDeleteBuilding->Parameters->AddWithValue("@id", buildingId);
		cmdDeleteBuilding->ExecuteNonQuery();

		MessageBox::Show("Building deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		// ==========================
		// 5️⃣ Clear fields
		// ==========================
		txtBuildingId->Clear();

		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
}
};
}
