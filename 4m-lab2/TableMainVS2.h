#pragma once

namespace My4mlab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TableMainVS2
	/// </summary>
	public ref class TableMainVS2 : public System::Windows::Forms::Form
	{
	public:
		TableMainVS2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

        TableMainVS2(double **v, int n, int m)
        {
            InitializeComponent();

            // строим таблицу
            cli::array< DataGridViewTextBoxColumn^ >^ arr;
            arr = gcnew cli::array< DataGridViewTextBoxColumn^ >(n + 1);

            for (int i = 0; i < n + 1; i++)
            {
                arr[i] = gcnew DataGridViewTextBoxColumn();
            }

            dataGridView_mainVS2->Columns->AddRange(arr);

            for (int j = m; j >= 0; j--)
            {
                dataGridView_mainVS2->Rows->Add();
                for (int i = 0; i < n + 1; i++)
                {
                    dataGridView_mainVS2->Rows[m - j]->Cells[i]->Value = System::Convert::ToString(v[i][j]);
                }
            }

            dataGridView_mainVS2->ClearSelection();
        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TableMainVS2()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::DataGridView^  dataGridView_mainVS2;
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
            this->dataGridView_mainVS2 = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainVS2))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView_mainVS2
            // 
            this->dataGridView_mainVS2->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_mainVS2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_mainVS2->Location = System::Drawing::Point(71, 38);
            this->dataGridView_mainVS2->Name = L"dataGridView_mainVS2";
            this->dataGridView_mainVS2->RowTemplate->Height = 28;
            this->dataGridView_mainVS2->Size = System::Drawing::Size(675, 553);
            this->dataGridView_mainVS2->TabIndex = 0;
            // 
            // TableMainVS2
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(811, 625);
            this->Controls->Add(this->dataGridView_mainVS2);
            this->Name = L"TableMainVS2";
            this->Text = L"Ѕолее точное численное решение (S2)";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainVS2))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	};
}
