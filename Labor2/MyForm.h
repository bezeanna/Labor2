#pragma once

namespace Labor2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 22;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Лінія", L"Прямокутник", L"Зафарбований прямокутник",
					L"Еліпс", L"Зафарбований еліпс", L"Сектор", L"Зірка"
			});
			this->listBox1->Location = System::Drawing::Point(465, 122);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(286, 158);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 388);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		array<Point>^ st;
		st = gcnew array<Point>(11);
		st[0].X = 150; st[0].Y = 60;
		st[1].X = 120; st[1].Y = 130;
		st[2].X = 50; st[2].Y = 140;
		st[3].X = 110; st[3].Y = 190;
		st[4].X = 110; st[4].Y = 260;
		st[5].X = 170; st[5].Y = 220;
		st[6].X = 240; st[6].Y = 250;
		st[7].X = 220; st[7].Y = 180;
		st[8].X = 260; st[8].Y = 130;
		st[9].X = 190; st[9].Y = 120;
		st[10].X = 150; st[10].Y = 60;
		//Створення графічного об'єкта	
		Graphics^ graf = CreateGraphics();
		//Створення пера
		Pen^ pn = gcnew System::Drawing::Pen(Color::Black, 4);
		//brush
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::Red);
		//Очистити форму
		graf->Clear(SystemColors::ControlLight);

		switch (listBox1->SelectedIndex)
		{
		case 0: graf->DrawLine(pn, 50, 200, 250, 120);
			break;
		case 1: graf->DrawRectangle(pn, 40, 100, 240, 130);
			break;
		case 2: graf->FillRectangle(Brushes::LightYellow, 40, 100, 240, 130);
			break;
		case 3: graf->DrawEllipse(pn, 40, 100, 240, 130);
			break;
		case 4: graf->FillEllipse(Brushes::LightYellow, 40, 100, 240, 130);
			break;
		case 5: graf->FillPie(Brushes::LightSalmon, 40, 100, 240, 130, 20, 330);
			break;
		case 6: graf->FillPolygon(br, st);
			break;
		default:
			break;
	}
	}
	};
}
