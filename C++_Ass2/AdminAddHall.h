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
	/// Summary for AdminAddHall
	/// </summary>
	public ref class AdminAddHall : public System::Windows::Forms::Form
	{
		void LoadBuildings()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				conn->Open();

				SqlDataAdapter^ da = gcnew SqlDataAdapter(
					"SELECT id, name FROM Buildings",
					conn);

				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				cmbBuilding->DataSource = dt;
				cmbBuilding->DisplayMember = "name";
				cmbBuilding->ValueMember = "id";
				cmbBuilding->SelectedIndex = -1;
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

	public:
		AdminAddHall(void)
		{
			InitializeComponent();
			LoadBuildings();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminAddHall()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckBox^ chkProjector;
	protected:

	private: System::Windows::Forms::TextBox^ txtCapacity;

	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtHallName;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ cmbBuilding;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ cmbFloor;
	private: System::Windows::Forms::CheckBox^ chkAC;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cmbBuilding = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cmbFloor = (gcnew System::Windows::Forms::ComboBox());
			this->chkProjector = (gcnew System::Windows::Forms::CheckBox());
			this->txtCapacity = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtHallName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chkAC = (gcnew System::Windows::Forms::CheckBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->chkAC);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->cmbBuilding);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->cmbFloor);
			this->panel1->Controls->Add(this->chkProjector);
			this->panel1->Controls->Add(this->txtCapacity);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtHallName);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(40, 90);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 486);
			this->panel1->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(27, 82);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(78, 24);
			this->label7->TabIndex = 42;
			this->label7->Text = L"Building";
			// 
			// cmbBuilding
			// 
			this->cmbBuilding->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBuilding->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbBuilding->FormattingEnabled = true;
			this->cmbBuilding->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ICT", L"Petrol", L"Mechatronics", L"Autotronics",
					L"Renewable Energy"
			});
			this->cmbBuilding->Location = System::Drawing::Point(191, 78);
			this->cmbBuilding->Name = L"cmbBuilding";
			this->cmbBuilding->Size = System::Drawing::Size(214, 33);
			this->cmbBuilding->TabIndex = 41;
			this->cmbBuilding->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminAddHall::cmbBuilding_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(27, 137);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 24);
			this->label6->TabIndex = 40;
			this->label6->Text = L"Floor";
			// 
			// cmbFloor
			// 
			this->cmbFloor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbFloor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbFloor->FormattingEnabled = true;
			this->cmbFloor->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ICT", L"Petrol", L"Mechatronics", L"Autotronics",
					L"Renewable Energy"
			});
			this->cmbFloor->Location = System::Drawing::Point(191, 133);
			this->cmbFloor->Name = L"cmbFloor";
			this->cmbFloor->Size = System::Drawing::Size(214, 33);
			this->cmbFloor->TabIndex = 39;
			// 
			// chkProjector
			// 
			this->chkProjector->AutoSize = true;
			this->chkProjector->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chkProjector->ForeColor = System::Drawing::Color::White;
			this->chkProjector->Location = System::Drawing::Point(28, 355);
			this->chkProjector->Name = L"chkProjector";
			this->chkProjector->Size = System::Drawing::Size(108, 29);
			this->chkProjector->TabIndex = 34;
			this->chkProjector->Text = L"Projector";
			this->chkProjector->UseVisualStyleBackColor = true;
			// 
			// txtCapacity
			// 
			this->txtCapacity->Location = System::Drawing::Point(191, 249);
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
			this->label4->Location = System::Drawing::Point(24, 258);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 24);
			this->label4->TabIndex = 32;
			this->label4->Text = L"Capacity";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(24, 200);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Hall Name";
			// 
			// txtHallName
			// 
			this->txtHallName->Location = System::Drawing::Point(191, 191);
			this->txtHallName->Multiline = true;
			this->txtHallName->Name = L"txtHallName";
			this->txtHallName->Size = System::Drawing::Size(214, 33);
			this->txtHallName->TabIndex = 22;
			this->txtHallName->TextChanged += gcnew System::EventHandler(this, &AdminAddHall::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(176, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 39);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Add Hall";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(101, 408);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminAddHall::button2_Click);
			// 
			// chkAC
			// 
			this->chkAC->AutoSize = true;
			this->chkAC->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chkAC->ForeColor = System::Drawing::Color::White;
			this->chkAC->Location = System::Drawing::Point(28, 306);
			this->chkAC->Name = L"chkAC";
			this->chkAC->Size = System::Drawing::Size(52, 29);
			this->chkAC->TabIndex = 43;
			this->chkAC->Text = L"Ac";
			this->chkAC->UseVisualStyleBackColor = true;
			// 
			// AdminAddHall
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 627);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminAddHall";
			this->Text = L"AdminAddHall";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cmbBuilding_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cmbBuilding->SelectedIndex == -1 || cmbBuilding->SelectedValue == nullptr)
			return;

		// لازم نتأكد إن SelectedValue مش DataRowView
		if (cmbBuilding->SelectedValue == nullptr)
			return;

		if (cmbBuilding->SelectedValue->GetType() == DataRowView::typeid)
			return;

		int buildingId = safe_cast<int>(cmbBuilding->SelectedValue);


		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		try
		{
			conn->Open();

			SqlDataAdapter^ da = gcnew SqlDataAdapter(
				"SELECT id, floor_number FROM Floors WHERE building_id = @bid",
				conn);

			da->SelectCommand->Parameters->AddWithValue("@bid", buildingId);

			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);

			cmbFloor->DataSource = dt;
			cmbFloor->DisplayMember = "floor_number";
			cmbFloor->ValueMember = "id";
			cmbFloor->SelectedIndex = -1;
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
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// ========== Validation ==========
	if (String::IsNullOrWhiteSpace(txtHallName->Text))
	{
		MessageBox::Show("Enter hall name");
		return;
	}

	if (cmbFloor->SelectedIndex == -1)
	{
		MessageBox::Show("Select floor");
		return;
	}

	int capacity;
	if (!Int32::TryParse(txtCapacity->Text, capacity) || capacity <= 0)
	{
		MessageBox::Show("Invalid capacity");
		return;
	}

	int floorId = Convert::ToInt32(cmbFloor->SelectedValue);
	bool hasAC = chkAC->Checked;
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
			"INSERT INTO LectureHalls "
			"(name, floor_id, capacity, has_air_condition, has_projector) "
			"VALUES (@name, @floor, @cap, @ac, @proj)",
			conn);

		cmd->Parameters->AddWithValue("@name", txtHallName->Text);
		cmd->Parameters->AddWithValue("@floor", floorId);
		cmd->Parameters->AddWithValue("@cap", capacity);
		cmd->Parameters->AddWithValue("@ac", hasAC);
		cmd->Parameters->AddWithValue("@proj", hasProjector);

		cmd->ExecuteNonQuery();

		MessageBox::Show("Lecture Hall added successfully");

		txtHallName->Clear();
		txtCapacity->Clear();
		cmbBuilding->SelectedIndex = -1;
		cmbFloor->DataSource = nullptr;
		chkAC->Checked = false;
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
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
