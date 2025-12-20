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
	/// Summary for AdminModifyBuilding
	/// </summary>
	public ref class AdminModifyBuilding : public System::Windows::Forms::Form
	{
	public:
		AdminModifyBuilding(void)
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
		~AdminModifyBuilding()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtNewFloors;
	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBuildingName;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtBuildingId;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtBuildingId = (gcnew System::Windows::Forms::TextBox());
			this->txtNewFloors = (gcnew System::Windows::Forms::TextBox());
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
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->txtBuildingId);
			this->panel1->Controls->Add(this->txtNewFloors);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtBuildingName);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(40, 172);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 309);
			this->panel1->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(248, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 31);
			this->button1->TabIndex = 32;
			this->button1->Text = L"Show";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminModifyBuilding::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(24, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 24);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Building ID";
			// 
			// txtBuildingId
			// 
			this->txtBuildingId->Location = System::Drawing::Point(191, 27);
			this->txtBuildingId->Multiline = true;
			this->txtBuildingId->Name = L"txtBuildingId";
			this->txtBuildingId->Size = System::Drawing::Size(214, 33);
			this->txtBuildingId->TabIndex = 31;
			// 
			// txtNewFloors
			// 
			this->txtNewFloors->Location = System::Drawing::Point(191, 161);
			this->txtNewFloors->Multiline = true;
			this->txtNewFloors->Name = L"txtNewFloors";
			this->txtNewFloors->Size = System::Drawing::Size(214, 33);
			this->txtNewFloors->TabIndex = 29;
			this->txtNewFloors->TextChanged += gcnew System::EventHandler(this, &AdminModifyBuilding::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(24, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Building Name";
			this->label3->Click += gcnew System::EventHandler(this, &AdminModifyBuilding::label3_Click);
			// 
			// txtBuildingName
			// 
			this->txtBuildingName->Location = System::Drawing::Point(191, 116);
			this->txtBuildingName->Multiline = true;
			this->txtBuildingName->Name = L"txtBuildingName";
			this->txtBuildingName->Size = System::Drawing::Size(214, 33);
			this->txtBuildingName->TabIndex = 22;
			this->txtBuildingName->TextChanged += gcnew System::EventHandler(this, &AdminModifyBuilding::textBox2_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(24, 170);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"No. Of Floors";
			this->label5->Click += gcnew System::EventHandler(this, &AdminModifyBuilding::label5_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(103, 244);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Modify";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminModifyBuilding::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(146, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(222, 39);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Add Building";
			// 
			// AdminModifyBuilding
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 553);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminModifyBuilding";
			this->Text = L"AdminModifyBuilding";
			this->Load += gcnew System::EventHandler(this, &AdminModifyBuilding::AdminModifyBuilding_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AdminModifyBuilding_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// ==========================
	   // 🔍 Validation
	   // ==========================
	int buildingId = 0;
	if (!Int32::TryParse(txtBuildingId->Text, buildingId))
	{
		MessageBox::Show("Please enter valid Building ID", "Validation Error");
		return;
	}

	if (String::IsNullOrWhiteSpace(txtBuildingName->Text))
	{
		MessageBox::Show("Please enter building name", "Validation Error");
		return;
	}

	int newFloors = 0;
	if (!Int32::TryParse(txtNewFloors->Text, newFloors) || newFloors <= 0)
	{
		MessageBox::Show("Please enter valid number of floors", "Validation Error");
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
		// 1️⃣ Get current floors count
		// ==========================
		SqlCommand^ cmdGetFloors = gcnew SqlCommand(
			"SELECT COUNT(*) FROM Floors WHERE building_id = @id",
			conn);

		cmdGetFloors->Parameters->AddWithValue("@id", buildingId);

		int currentFloors = Convert::ToInt32(cmdGetFloors->ExecuteScalar());

		// ==========================
		// ❌ ممنوع تقليل الأدوار
		// ==========================
		if (newFloors < currentFloors)
		{
			MessageBox::Show(
				"You cannot reduce number of floors.\nCurrent floors: " + currentFloors.ToString(),
				"Validation Error");
			return;
		}

		// ==========================
		// 2️⃣ Update building name
		// ==========================
		SqlCommand^ cmdUpdateBuilding = gcnew SqlCommand(
			"UPDATE Buildings SET name = @name WHERE id = @id",
			conn);

		cmdUpdateBuilding->Parameters->AddWithValue("@name", txtBuildingName->Text);
		cmdUpdateBuilding->Parameters->AddWithValue("@id", buildingId);
		cmdUpdateBuilding->ExecuteNonQuery();

		// ==========================
		// 3️⃣ Add new floors (لو زاد)
		// ==========================
		for (int i = currentFloors + 1; i <= newFloors; i++)
		{
			SqlCommand^ cmdAddFloor = gcnew SqlCommand(
				"INSERT INTO Floors (floor_number, building_id) VALUES (@floor, @bid)",
				conn);

			cmdAddFloor->Parameters->AddWithValue("@floor", i);
			cmdAddFloor->Parameters->AddWithValue("@bid", buildingId);
			cmdAddFloor->ExecuteNonQuery();
		}

		MessageBox::Show("Building updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
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
		// 1️⃣ Get Building Name
		// ==========================
		SqlCommand^ cmdBuilding = gcnew SqlCommand(
			"SELECT name FROM Buildings WHERE id = @id",
			conn);

		cmdBuilding->Parameters->AddWithValue("@id", buildingId);

		Object^ nameResult = cmdBuilding->ExecuteScalar();

		if (nameResult == nullptr)
		{
			MessageBox::Show("Building not found", "Error");
			return;
		}

		txtBuildingName->Text = nameResult->ToString();

		// ==========================
		// 2️⃣ Get Floors Count
		// ==========================
		SqlCommand^ cmdFloors = gcnew SqlCommand(
			"SELECT COUNT(*) FROM Floors WHERE building_id = @id",
			conn);

		cmdFloors->Parameters->AddWithValue("@id", buildingId);

		int floorsCount = Convert::ToInt32(cmdFloors->ExecuteScalar());

		txtNewFloors->Text = floorsCount.ToString();

		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
}
};
}
