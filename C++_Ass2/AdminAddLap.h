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
	/// Summary for AdminAddLap
	/// </summary>
	public ref class AdminAddLap : public System::Windows::Forms::Form
	{
		void LoadFloorsByBuilding(int buildingId)
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

				SqlCommand^ cmd = gcnew SqlCommand(
					"SELECT id, floor_number FROM Floors "
					"WHERE building_id = @bid "
					"ORDER BY floor_number", conn);

				cmd->Parameters->AddWithValue("@bid", buildingId);

				SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				cmbFloor->DataSource = dt;
				cmbFloor->DisplayMember = "floor_number";
				cmbFloor->ValueMember = "id";
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
		AdminAddLap(void)
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
		~AdminAddLap()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtCapacity;
	protected:

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtACs;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtPCs;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtLabName;

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ chkProjector;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::ComboBox^ cmbBuilding;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::ComboBox^ cmbFloor;








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
			this->chkProjector = (gcnew System::Windows::Forms::CheckBox());
			this->txtCapacity = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtACs = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPCs = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtLabName = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->cmbBuilding = (gcnew System::Windows::Forms::ComboBox());
			this->cmbFloor = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->cmbBuilding);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->cmbFloor);
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
			this->panel1->Location = System::Drawing::Point(40, 93);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 488);
			this->panel1->TabIndex = 4;
			// 
			// chkProjector
			// 
			this->chkProjector->AutoSize = true;
			this->chkProjector->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chkProjector->ForeColor = System::Drawing::Color::White;
			this->chkProjector->Location = System::Drawing::Point(31, 373);
			this->chkProjector->Name = L"chkProjector";
			this->chkProjector->Size = System::Drawing::Size(108, 29);
			this->chkProjector->TabIndex = 34;
			this->chkProjector->Text = L"Projector";
			this->chkProjector->UseVisualStyleBackColor = true;
			// 
			// txtCapacity
			// 
			this->txtCapacity->Location = System::Drawing::Point(194, 317);
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
			this->label4->Location = System::Drawing::Point(27, 326);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 24);
			this->label4->TabIndex = 32;
			this->label4->Text = L"Capacity";
			// 
			// txtACs
			// 
			this->txtACs->Location = System::Drawing::Point(194, 263);
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
			this->label1->Location = System::Drawing::Point(27, 272);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 24);
			this->label1->TabIndex = 30;
			this->label1->Text = L"No. Of ACs";
			// 
			// txtPCs
			// 
			this->txtPCs->Location = System::Drawing::Point(194, 211);
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
			this->label3->Location = System::Drawing::Point(24, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Lap Name";
			// 
			// txtLabName
			// 
			this->txtLabName->Location = System::Drawing::Point(191, 38);
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
			this->label5->Location = System::Drawing::Point(27, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"No. Of PCs";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(176, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 39);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Add Lap";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(104, 426);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminAddLap::button2_Click);
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
			this->cmbBuilding->Location = System::Drawing::Point(191, 101);
			this->cmbBuilding->Name = L"cmbBuilding";
			this->cmbBuilding->Size = System::Drawing::Size(214, 33);
			this->cmbBuilding->TabIndex = 37;
			this->cmbBuilding->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminAddLap::cmbBuilding_SelectedIndexChanged);
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
			this->cmbFloor->Location = System::Drawing::Point(191, 156);
			this->cmbFloor->Name = L"cmbFloor";
			this->cmbFloor->Size = System::Drawing::Size(214, 33);
			this->cmbFloor->TabIndex = 35;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(27, 105);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(78, 24);
			this->label7->TabIndex = 38;
			this->label7->Text = L"Building";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(27, 160);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 24);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Floor";
			// 
			// AdminAddLap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 619);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminAddLap";
			this->Text = L"AdminAddLap";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// ================= Validation =================
		if (String::IsNullOrWhiteSpace(txtLabName->Text))
		{
			MessageBox::Show("Enter lab name");
			return;
		}

		int pcs, acs, capacity;

		if (!Int32::TryParse(txtPCs->Text, pcs) || pcs < 0)
		{
			MessageBox::Show("Enter valid number of PCs");
			return;
		}

		if (!Int32::TryParse(txtACs->Text, acs) || acs < 0)
		{
			MessageBox::Show("Enter valid number of ACs");
			return;
		}

		if (!Int32::TryParse(txtCapacity->Text, capacity) || capacity <= 0)
		{
			MessageBox::Show("Enter valid capacity");
			return;
		}

		if (cmbFloor->SelectedIndex == -1)
		{
			MessageBox::Show("Select floor");
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

			String^ query =
				"INSERT INTO Labs "
				"(name, floor_id, capacity, computers_count, ac_count, has_projector, has_air_condition) "
				"VALUES "
				"(@name, @floor, @capacity, @pcs, @acs, @projector, @acFlag)";

			SqlCommand^ cmd = gcnew SqlCommand(query, conn);

			cmd->Parameters->AddWithValue("@name", txtLabName->Text);
			cmd->Parameters->AddWithValue("@floor", cmbFloor->SelectedValue);
			cmd->Parameters->AddWithValue("@capacity", capacity);
			cmd->Parameters->AddWithValue("@pcs", pcs);
			cmd->Parameters->AddWithValue("@acs", acs);
			cmd->Parameters->AddWithValue("@projector", hasProjector);
			cmd->Parameters->AddWithValue("@acFlag", acs > 0 ? 1 : 0);

			cmd->ExecuteNonQuery();

			MessageBox::Show("Lab added successfully");

			// Clear
			txtLabName->Clear();
			txtPCs->Clear();
			txtACs->Clear();
			txtCapacity->Clear();
			chkProjector->Checked = false;
			cmbFloor->SelectedIndex = -1;
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
private: System::Void cmbBuilding_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (cmbBuilding->SelectedIndex == -1)
		return;

	DataRowView^ row = dynamic_cast<DataRowView^>(cmbBuilding->SelectedItem);
	if (row == nullptr)
		return;

	int buildingId = Convert::ToInt32(row["id"]);
	LoadFloorsByBuilding(buildingId);
}







};
}
