/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md


	ATUORE:			Realluke | Aka Luca Pollicino
	DESCRIZIONE:	UCOMP (Unanaged Companion)
	DATA:			05/04/22
	VERSIONE:		1.1.1
*/

#pragma once
#pragma unmanaged

namespace GWCpp
{

	#pragma region Strutture

	struct UPoint
	{
		int X;
		int Y;
	};


	struct USize
	{
		int Width;
		int Height;
	};


	struct UColor
	{
		int R;
		int G;
		int B;
	};

	#pragma endregion
	


	#pragma region Enumerazioni

	enum UMouseButtons
	{
		None = 0,
		Left = 1048576,
		Right = 2097152,
		Middle = 4194304
	};


	enum UWindowState
	{
		Normal = 0,
		Minimized = 1,
		Maximized = 2
	};


	enum UOutputBoxStyle
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


	enum UOutputBoxResult
	{
		OK = 1,
		Cancel = 2,
		Abort = 3,
		Retry = 4,
		Ignore = 5,
		Yes = 6,
		No = 7
	};


	enum UStringAlignment
	{
		Near = 0,
		Center = 1,
		Far = 2
	};

	#pragma endregion

}

#pragma region Costanti

#define UBlack UColor{ 0, 0, 0 }
#define URed UColor{ 255, 0, 0 }
#define UGreen UColor{ 0, 255, 0 }
#define UBlue UColor{ 0, 0, 255 }
#define UYellow UColor{ 255, 255, 0 }
#define UMagenta UColor{ 255, 0, 255 }
#define UCyan UColor{ 0, 255, 255 }
#define UWhite UColor{ 255, 255, 255 }

#pragma endregion
