#include "graphics.h"
#include "file.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <future>
class GRAPHIC {
	public : 
		GRAPHIC();
		void bgr();
		void main();
		int menu();
		void manager();
		void purchase(Warehouse warehouse, CustomerManager customerList );
//		void menufeature(); 
		void draw_scrollbar(int first_row);
		void draw_table(char name[50]);
		void inbang(char name[50],int choose,Warehouse warehouse, CustomerManager customerList );
};

