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
	/// Summary for AdminAddBuilding
	/// </summary>
	public ref class AdminAddBuilding : public System::Windows::Forms::Form
	{
	public:
		AdminAddBuilding(void)
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
		~AdminAddBuilding()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:





	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBuildingName;


	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtFloors;


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
			this->txtFloors = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtBuildingName = (gcnew System::Windows::Forms::TextBox());
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
			this->panel1->Controls->Add(this->txtFloors);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtBuildingName);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(40, 147);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 265);
			this->panel1->TabIndex = 2;
			// 
			// txtFloors
			// 
			this->txtFloors->Location = System::Drawing::Point(191, 83);
			this->txtFloors->Multiline = true;
			this->txtFloors->Name = L"txtFloors";
			this->txtFloors->Size = System::Drawing::Size(214, 33);
			this->txtFloors->TabIndex = 29;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(24, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Building Name";
			this->label3->Click += gcnew System::EventHandler(this, &AdminAddBuilding::label3_Click);
			// 
			// txtBuildingName
			// 
			this->txtBuildingName->Location = System::Drawing::Point(191, 38);
			this->txtBuildingName->Multiline = true;
			this->txtBuildingName->Name = L"txtBuildingName";
			this->txtBuildingName->Size = System::Drawing::Size(214, 33);
			this->txtBuildingName->TabIndex = 22;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(24, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"No. Of Floors";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(103, 166);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminAddBuilding::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(146, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(222, 39);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Add Building";
			// 
			// AdminAddBuilding
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 493);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminAddBuilding";
			this->Text = L"AdminAddBuilding";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// ==========================
	// 🔍 Validation
	// ==========================
	if (String::IsNullOrWhiteSpace(txtBuildingName->Text))
	{
		MessageBox::Show("Please enter building name", "Validation Error");
		return;
	}

	int floorsCount = 0;
	if (!Int32::TryParse(txtFloors->Text, floorsCount) || floorsCount <= 0 || floorsCount > 50)
	{
		MessageBox::Show("Please enter valid number of floors (1 - 50)", "Validation Error");
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
		// 1️⃣ Insert Building
		// ==========================
		String^ insertBuilding =
			"INSERT INTO Buildings (name) "
			"OUTPUT INSERTED.id "
			"VALUES (@name)";

		SqlCommand^ cmdBuilding = gcnew SqlCommand(insertBuilding, conn);
		cmdBuilding->Parameters->AddWithValue("@name", txtBuildingName->Text);

		int buildingId = Convert::ToInt32(cmdBuilding->ExecuteScalar());

		// ==========================
		// 2️⃣ Insert Floors
		// ==========================
		for (int i = 1; i <= floorsCount; i++)
		{
			SqlCommand^ cmdFloor = gcnew SqlCommand(
				"INSERT INTO Floors (floor_number, building_id) VALUES (@floor, @bid)",
				conn);

			cmdFloor->Parameters->AddWithValue("@floor", i);
			cmdFloor->Parameters->AddWithValue("@bid", buildingId);
			cmdFloor->ExecuteNonQuery();
		}

		MessageBox::Show("Building added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);


		// تنظيف الفورم
		txtBuildingName->Clear();
		txtFloors->Clear();

		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
}
};
}
