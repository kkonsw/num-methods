#pragma once

namespace My4mlab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ErrorsMain
	/// </summary>
	public ref class ErrorsMain : public System::Windows::Forms::Form
	{
	public:
		ErrorsMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

        ErrorsMain(double **v, int n, int m)
        {
            InitializeComponent();

            // строим таблицу
            cli::array< DataGridViewTextBoxColumn^ >^ arr;
            arr = gcnew cli::array< DataGridViewTextBoxColumn^ >(n + 1);

            for (int i = 0; i < n + 1; i++)
            {
                arr[i] = gcnew DataGridViewTextBoxColumn();
            }

            dataGridView_mainErrors->Columns->AddRange(arr);

            for (int j = m; j >= 0; j--)
            {
                dataGridView_mainErrors->Rows->Add();
                for (int i = 0; i < n + 1; i++)
                {
                    dataGridView_mainErrors->Rows[m - j]->Cells[i]->Value = System::Convert::ToString(v[i][j]);
                }
            }

            dataGridView_mainErrors->ClearSelection();
        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ErrorsMain()
		{
			if (components)
			{
				delete components;
			}
		}

    private: System::Windows::Forms::DataGridView^  dataGridView_mainErrors;
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
            this->dataGridView_mainErrors = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainErrors))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView_mainErrors
            // 
            this->dataGridView_mainErrors->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_mainErrors->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_mainErrors->Location = System::Drawing::Point(93, 51);
            this->dataGridView_mainErrors->Name = L"dataGridView_mainErrors";
            this->dataGridView_mainErrors->RowTemplate->Height = 28;
            this->dataGridView_mainErrors->Size = System::Drawing::Size(609, 501);
            this->dataGridView_mainErrors->TabIndex = 0;
            // 
            // ErrorsMain
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(788, 620);
            this->Controls->Add(this->dataGridView_mainErrors);
            this->Name = L"ErrorsMain";
            this->Text = L"Таблица погрешностей основной задачи";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainErrors))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	};
}
