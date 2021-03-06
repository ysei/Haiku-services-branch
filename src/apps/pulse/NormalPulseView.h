//****************************************************************************************
//
//	File:		NormalPulseView.h
//
//	Written by:	Daniel Switkin
//
//	Copyright 1999, Be Incorporated
//
//****************************************************************************************
#ifndef NORMALPULSEVIEW_H
#define NORMALPULSEVIEW_H


#include "PulseView.h"
#include "ProgressBar.h"
#include "CPUButton.h"


class NormalPulseView : public PulseView {
	public:
		NormalPulseView(BRect rect);
		virtual ~NormalPulseView();

		virtual void Draw(BRect rect);
		virtual void Pulse();
		virtual void AttachedToWindow();

		void UpdateColors(BMessage *message);

	private:
		void DetermineVendorAndProcessor();
		void CalculateFontSizes();

		char fVendor[32], fProcessor[32];
		bigtime_t fPreviousTime;
		ProgressBar **fProgressBars;
		CPUButton **fCpuButtons;
		BBitmap *fCpuLogo;
		int32 fCpuCount;
		bool fHasBrandLogo;

		float	fVendorFontSize, fProcessorFontSize;
};

#endif
