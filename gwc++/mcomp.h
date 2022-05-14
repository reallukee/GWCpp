/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md


	ATUORE:			Realluke | Aka Luca Pollicino
	DESCRIZIONE:	MCOMP (Managed Companion)
	DATA:			05/04/22
	VERSIONE:		1.1.0
*/

#pragma once
#pragma managed

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;
using namespace Microsoft::VisualBasic;

#pragma region Costanti

#define MBlack MColor(0, 0, 0)
#define MRed MColor(255, 0, 0)
#define MGreen MColor(0, 255, 0)
#define MBlue MColor(0, 0, 255)
#define MYellow MColor(255, 255, 0)
#define MMagenta MColor(255, 0, 255)
#define MCyan MColor(0, 255, 255)
#define MWhite MColor(255, 255, 255)

#pragma endregion

namespace GWCpp
{

	#pragma region Strutture

	public value struct MPoint
	{
		int X;
		int Y;

		MPoint(int X, int Y)
		{
			if (X >= 0)
			{
				this->X = X;
			}
			else
			{
				this->X = 0;
			}

			if (Y >= 0)
			{
				this->Y = Y;
			}
			else
			{
				this->Y = 0;
			}
		}
	};


	public value struct MSize
	{
		int Width;
		int Height;

		MSize(int Width, int Height)
		{
			if (Width >= 0)
			{
				this->Width = Width;
			}
			else
			{
				this->Width = 0;
			}

			if (Height >= 0)
			{
				this->Height = Height;
			}
			else
			{
				this->Height = 0;
			}
		}
	};


	public value struct MColor
	{
		int R;
		int G;
		int B;

		MColor(int R, int G, int B)
		{
			if (R >= 0 || R <= 255)
			{
				this->R = R;
			}
			else
			{
				this->R = 0;
			}

			if (G >= 0 || G <= 255)
			{
				this->G = G;
			}
			else
			{
				this->G = 0;
			}

			if (B >= 0 || B <= 255)
			{
				this->B = B;
			}
			else
			{
				this->B = 0;
			}
		}
	};

	#pragma endregion



	#pragma region Enumerazioni

	public enum class MMouseButtons
	{
		None = 0,
		Left = 1048576,
		Right = 2097152,
		Middle = 4194304
	};


	public enum class MWindowState
	{
		Normal = 0,
		Minimized = 1,
		Maximized = 2
	};


	public enum class MOutputBoxStyle
	{
		ApplicationModal = 0,
		DefaultButton1 = 0,
		OkOnly = 0,
		OkCancel = 1,
		AbortRetryIgnore = 2,
		YesNoCancel = 3,
		YesNo = 4,
		RetryCancel = 5,
		Critical = 16,
		Question = 32,
		Exclamation = 48,
		Information = 64,
		DefaultButton2 = 256,
		DefaultButton3 = 512,
		SystemModal = 4096,
		MsgBoxHelp = 16384,
		MsgBoxSetForeground = 65536,
		MsgBoxRight = 524288,
		MsgBoxRtlReading = 1048576
	};


	public enum class MOutputBoxResult
	{
		OK = 1,
		Cancel = 2,
		Abort = 3,
		Retry = 4,
		Ignore = 5,
		Yes = 6,
		No = 7
	};


	public enum class MStringAlignment
	{
		Near = 0,
		Center = 1,
		Far = 2
	};

	#pragma endregion
	
}
