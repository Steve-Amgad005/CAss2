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
	/// Summary for AdminDeleteLap
	/// </summary>
	public ref class AdminDeleteLap : public System::Windows::Forms::Form
	{
	public:
		AdminDeleteLap(void)
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
		~AdminDeleteLap()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtLabId;










	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtLabId = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txtLabId);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(38, 91);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 174);
			this->panel1->TabIndex = 8;
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
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(101, 92);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminDeleteLap::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(150, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 39);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Delete Lap";
			// 
			// AdminDeleteLap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 290);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminDeleteLap";
			this->Text = L"AdminDeleteLap";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtLabId->Text))
		{
			MessageBox::Show("Enter Lab ID", "Validation Error");
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

			// ===============================
			// Check if lab is used in schedule
			// ===============================
			SqlCommand^ cmdCheck = gcnew SqlCommand(
				"SELECT COUNT(*) FROM Schedule WHERE hall_id = @id",
				conn);

			cmdCheck->Parameters->AddWithValue("@id", labId);

			int used = Convert::ToInt32(cmdCheck->ExecuteScalar());

			if (used > 0)
			{
				MessageBox::Show(
					"Cannot delete lab.\nLab is already used in schedule.",
					"Delete Blocked",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return;
			}

			// ===============================
			// Confirm delete
			// ===============================
			if (MessageBox::Show(
				"Are you sure you want to delete this lab?",
				"Confirm Delete",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::No)
			{
				return;
			}

			// ===============================
			// Delete Lab
			// ===============================
			SqlCommand^ cmdDelete = gcnew SqlCommand(
				"DELETE FROM Labs WHERE id = @id",
				conn);

			cmdDelete->Parameters->AddWithValue("@id", labId);
			cmdDelete->ExecuteNonQuery();

			MessageBox::Show("Lab deleted successfully", "Success");

			txtLabId->Clear();
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
};
}
