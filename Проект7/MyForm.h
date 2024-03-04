#pragma once

namespace SecondTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int started;
		array<PointF>^ points;
		Bitmap^ bmp;
		PointF^ xy1;
		PointF^ xy2;
		PointF^ xy3;
		PointF^ xy4;
		PointF^ pnull;
		Double alpha;
		int index;
		int movement;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			started = 0;
			xy1 = gcnew PointF;
			xy2 = gcnew PointF;
			xy3 = gcnew PointF;
			xy4 = gcnew PointF;
			pnull = gcnew PointF;
			alpha = 0;
			index = 1;
			movement = 0;
		}


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ onoff;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->onoff = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->pictureBox1->InitialImage = nullptr;
			this->pictureBox1->Location = System::Drawing::Point(16, 15);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(812, 559);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// onoff
			// 
			this->onoff->BackColor = System::Drawing::Color::MintCream;
			this->onoff->Location = System::Drawing::Point(836, 469);
			this->onoff->Margin = System::Windows::Forms::Padding(4);
			this->onoff->Name = L"onoff";
			this->onoff->Size = System::Drawing::Size(100, 84);
			this->onoff->TabIndex = 1;
			this->onoff->Text = L"On/Off";
			this->onoff->UseVisualStyleBackColor = false;
			this->onoff->Click += gcnew System::EventHandler(this, &MyForm::onoff_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MintCream;
			this->button1->Location = System::Drawing::Point(836, 75);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 83);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(952, 587);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->onoff);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void onoff_Click(System::Object^ sender, System::EventArgs^ e) {
		if (started) {
			if (timer1->Enabled == true)
				timer1->Enabled = false;
			else timer1->Enabled = true;
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		xy1->X = 0;
		xy2->X = 60;
		xy3->X = 60;
		xy4->X = 0;
		xy1->Y = 0;
		xy2->Y = 0;
		xy3->Y = 60;
		xy4->Y = 60;
		pnull->X = 0;
		pnull->Y = 0;
		if (index == 198)
			movement++;
		else if (index == 0)
			movement--;

		if (!movement) {
			index++;
			alpha += 0.1;
		}
		else {
			index--;
			alpha += 0.1;
		}


		PointF p1 = getPoint(xy1);

		PointF p2 = getPoint(xy2);

		PointF p3 = getPoint(xy3);

		PointF p4 = getPoint(xy4);

		this->pictureBox1->Image = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
		Graphics^ gr = Graphics::FromImage(this->pictureBox1->Image);

		Pen^ p = gcnew Pen(Color::LawnGreen, 2);

		bitmapToPicture(this->pictureBox1, *pnull, bmp);
		gr->DrawLine(p, p1, p2);
		gr->DrawLine(p, p2, p3);
		gr->DrawLine(p, p3, p4);
		gr->DrawLine(p, p1, p4);

	}

	private: PointF getPoint(PointF^ p) {
		PointF newP;

		newP.X = p->X*Math::Cos(alpha) - p->Y*Math::Sin(alpha);
		newP.Y = p->X*Math::Sin(alpha) + p->Y*Math::Cos(alpha);
		newP.X += points[index].X;
		newP.Y += points[index].Y;
		return newP;
		;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!started) {
			started++;
			this->pictureBox1->Image = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
			Graphics^ g = Graphics::FromImage(this->pictureBox1->Image);
			Pen^ p = gcnew Pen(Color::Black);
			drawLC(g, p);
			p->Color = Color::RoyalBlue;
			points = mathgraph();
			g->DrawLines(p, points);
			pictureBox1->Invalidate();
			bmp = pictureToBitmap(this->pictureBox1, this->pictureBox1->Width, this->pictureBox1->Height);
			timer1->Enabled = true;
		}
	}
			 array<PointF>^ mathgraph() {
				 int count = 200;
				 array<PointF>^ arr = gcnew array<PointF>(count);
				 Double x1 = -10;
				 Double x2 = 10;
				 Double y = 0.0;
				 Double x = 0.0;
				 Double xstep = (pictureBox1->Width) / count;
				 Double step = (x2 - x1) / count;
				 for (int i = 0; i < 200; i++) {
					 y = -Math::Sin(x1)*pictureBox1->Width / 20 + pictureBox1->Height / 2;
					 arr[i] = PointF(x, y);
					 x1 += step;
					 x += xstep;
				 }
				 return arr;
			 }
			 Bitmap^ pictureToBitmap(PictureBox^ pBox, double Width, double Height)
			 {
				 Bitmap^ Bmp = gcnew Bitmap(Width, Height);
				 Graphics^ gr = Graphics::FromImage(Bmp);
				 gr->DrawImage(pBox->Image, 0, 0, Width, Height);

				 return Bmp;
			 }
			 void bitmapToPicture(PictureBox^ pBox, PointF P, Bitmap^ Bmp)
			 {
				 Graphics^ gr = Graphics::FromImage(pBox->Image);
				 gr->CompositingMode = Drawing2D::CompositingMode::SourceCopy;
				 gr->DrawImage(Bmp, P);
				 pBox->Invalidate();
			 }

			 void drawLC(Graphics^ g, Pen^ p) {
				 p->Width = 2;
				 g->DrawLine(p, pictureBox1->Width / 2 - 3, 0, pictureBox1->Width / 2 - 3, pictureBox1->Height);
				 g->DrawLine(p, 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			 }
	};
}