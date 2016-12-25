// Copyright 2016, Jeffrey E. Bedard
#ifndef XSTATUS_BUTTON_H
#define XSTATUS_BUTTON_H
#include <xcb/xcb.h>
class XSButton {
	public:
		XSButton(xcb_connection_t * xc, const int16_t x, char * label);
		~XSButton(void);
		xcb_window_t get_window(void){return window;}
		XSButton * next;
		void (*cb)(XSButton *);
		void (*draw) (XSButton *);
		void (*enter) (XSButton *);
		void (*leave) (XSButton *);
		char * cb_data;
		xcb_connection_t * xc;
		char * label;
		uint16_t width;
	private:
		xcb_window_t window;
		int16_t x;
		xcb_rectangle_t get_geometry(void);
		void create_window(void);
};
XSButton * xstatus_create_button(xcb_connection_t * xc,
	const int16_t x, char * label);
#endif//XSTATUS_BUTTON_H
