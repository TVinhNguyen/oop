#include "ppl2.h"
#include "graphics.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream> 
#include <string> 
#include <atomic>
#define ROWS 11 
#define COLS 10
#define width  215 
#define height  60 
atomic<bool> stopFlag ;
int xfile = 0  ;
using namespace std;
string   data[100][6] ;
GRAPHIC::GRAPHIC(){};
char information[6][10] = {"ID","Name","Category","Special","Quantity","Price"};
int col , row  = 0 ; 
int first_row = 0 ; 
void GRAPHIC::bgr(){
	initwindow(1400, 800);
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextjustify(1,1);
	settextstyle(4,0,4); 
	setcolor(11);
}
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        if (wParam == WM_MOUSEWHEEL) {
            MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
            short wheelDelta = HIWORD(pMouseStruct->mouseData);
            
            if (wheelDelta > 0 && first_row > 0) {
                first_row--;
            }
            else if (wheelDelta < 0 && first_row < row - 10) {
                first_row++;
            }
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void docfile(){
	int x= 0 , y = 0;
	string line,res =  "",token;
	ifstream myfile ("Cty_Hung_Anh.inp");
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			stringstream ss(line);
			while (ss >> token) {
				if(token != ";")  {
					res += token;
					res += " ";
				}
				 else {
				 	data[x][y] = res;
					res ="";
					y += 1;
				} 
 			}
 			x += 1; y= 0 ;
		}
	}

	xfile = x ;
}

void GRAPHIC::draw_scrollbar(int first_row) {
	setcolor(BLACK);
    float  max_pos = row - 10;
    int pos = first_row;
    float length =  height*ROWS +20;
    float thumb_size = length / (max_pos + 1);
    float thumb_pos = pos * thumb_size;
    rectangle(width*col+ 70  , 30, width*col + 100 , 30 + height*ROWS + 20); 
    rectangle(width*col + 74, thumb_pos + 32, width*col + 96 , thumb_pos + thumb_size  + 28  );
}
void GRAPHIC::draw_table(char name[50]) {
	int x = 30, y = 30;
//	int width = 260  , height = 60;
	moveto(x,y);
	rectangle(x,y,x + width*col + 20 , y + height*ROWS +20 );
	x+=10; y+=10;
	moveto(x,y);
	for(int j = 0 ; j < col ; j++) {
		rectangle(x,y,width+x,height+y);
		outtextxy((x+width+x)/2 , (y+height+y)/2 ,information[j]);
		x+=width;
	}
	y+=height; x -= width*col;
	settextstyle(3,0,1);
	const char* cstr; char *bth;
	for (int i = first_row ; i < row && i < first_row+10 ; i++) {
		for(int j = 0; j<col ;j++) {
			rectangle(x,y,width+x,height+y);
			cstr = data[i][j].c_str();
			bth = const_cast<char*>(cstr); 
			outtextxy((x+width+x)/2 , (y+height+y)/2 ,bth	);
			x+= width;

		}
		y+=height; x -= width*col;

	}
	settextstyle(4,0,3);
	setcolor(BLUE);
	outtextxy(700,y+40,name);
} 
void muahang(promise<void>&& promise,Warehouse warehouse,CustomerManager customerList) {
	while(!stopFlag) {
	if(kbhit()) {
		int ch = getch();
		if(ch == 27) {
            setbkcolor(BLACK);
            cleardevice();
            stopFlag = true;
		}
	else {
	string id,phone;
	int quantity;
	int n;
	cout << "MOI BAN NHAP SO SAN PHAM MUON MUA : "; cin >> n;
	vector<Product*> productList;
	Product* pr1;
	for(int i = 0 ; i < n ; i++){
	cout << "MOI NHAP MA SAN PHAM : " ; cin >> id ;  
	cout << "MOI NHAP SO LUONG : " ; cin >> quantity;
	if(warehouse.findID(id)->getID() == "0") cout << "KO CO SAN PHAM" << endl;
	else {
		pr1 = warehouse.findID(id) ;
		pr1->setQuantity(quantity);
		productList.push_back(pr1);
	}
	}
	cout << "MOI NHAP SO DIEN THOAI KHACH HANG : ";
	cin >> phone; string name ; string address;
	Customer customer1 = customerList.getCustomer(phone);
	if(customer1.getId() == -1) 
	{
		cout << "MOI NHAP TEN : " ;
		cin >> name;
		cout << "MOI NHAP DIA CHI : ";
		cin >> address;
		customer1.setName(name); customer1.setAddress(address);	
	} 
	Order order1(customer1,productList,"2023-10-14","2023-10-19");
	cout << fixed << setprecision(0)<< order1.getTotalAmount();
	setbkcolor(BLACK);
	cleardevice();
	stopFlag = true; 

	
}
	}
}
	promise.set_value();
	
}
void GRAPHIC::inbang(char name[50],int choose,Warehouse warehouse , CustomerManager  customerList) {
	HHOOK hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, NULL, 0);
	if(choose == 2) {
	
	while (1) {
        cleardevice();
        settextstyle(4,0,1); 
		setcolor(BLACK);
        draw_table(name);
        draw_scrollbar(first_row);
		
        if (kbhit()) {
            int ch = getch();
            if (ch == 72 && first_row > 0) {
                first_row--;
            } else if (ch == 80 && first_row < row - 10) {
                first_row++;
            } 
            if(ch == 27) {
            	setbkcolor(BLACK);
            	cleardevice();
            	break;
			}
        } 
     delay(150);
    } }
    
    stopFlag = false;

    if (choose == 1)
    {
	
    promise<void>promise;
    future<void> future = promise.get_future();
    thread t2(muahang,move(promise),warehouse,customerList);
    while(future.wait_for(chrono::milliseconds(1)) != future_status::ready) {
		
        cleardevice();
        settextstyle(4,0,1); 
		setcolor(BLACK);
        draw_table(name);
        draw_scrollbar(first_row);
//        if (kbhit()) {
//            int ch = getch();
//            if (ch == 72 && first_row > 0) {
//                first_row--;
//            } else if (ch == 80 && first_row < row - 10) {
//                first_row++;
//            } 
//            if(ch == 27) {
//            	setbkcolor(BLACK);
//            	cleardevice();
//            	stopFlag = true;
//			}
//        } 
		delay(150);
    }
    t2.join();
	}

	UnhookWindowsHookEx(hMouseHook);
} 
//void GRAPHIC::menufeature(){
//	tt:
//	int rec1[]= {500,150,900,210};
//	int rec2[] = {500,220,900,280};
//	int rec3[] = {500,290,900,350}; 
//	int rec4[] = {500,360,900,420}; 
//
//	settextstyle(4,0,5);
//	setcolor(WHITE);
//	outtextxy(700 ,100,"CHON TINH NANG");
//	setcolor(11);
//	settextstyle(4,0,2);
//
//	rectangle(rec1[0],rec1[1],rec1[2],rec1[3]);
//	outtextxy((rec1[0]+rec1[2])/2,(rec1[1]+rec1[3])/2+10,"XEM");
//	rectangle(rec2[0],rec2[1],rec2[2],rec2[3]);
//	outtextxy((rec2[0]+rec2[2])/2,(rec2[1]+rec2[3])/2+10,"THEM");
//	rectangle(rec3[0],rec3[1],rec3[2],rec3[3]);
//	outtextxy((rec3[0]+rec3[2])/2,(rec3[1]+rec3[3])/2+10,"SUA");
//	rectangle(rec4[0],rec4[1],rec4[2],rec4[3]);
//	outtextxy((rec4[0]+rec4[2])/2,(rec4[1]+rec4[3])/2+10,"XOA");
//	setfillstyle(1,MAGENTA);
//	
//	int tri1[] = {rec1[0]-10,rec1[1],rec1[0]-10,rec1[3],rec1[0]-60,(rec1[1]+rec1[3])/2,rec1[0]-10,rec1[1]};
//	int tri2[] = {rec1[2]+10,rec1[1],rec1[2]+10,rec1[3],rec1[2]+60,(rec1[1]+rec1[3])/2,rec1[2]+10,rec1[1]};
//	
//	int tri3[] = {rec2[0]-10,rec2[1],rec2[0]-10,rec2[3],rec2[0]-60,(rec2[1]+rec2[3])/2,rec2[0]-10,rec2[1]};
//	int tri4[] = {rec2[2]+10,rec2[1],rec2[2]+10,rec2[3],rec2[2]+60,(rec2[1]+rec2[3])/2,rec2[2]+10,rec2[1]};
//	
//	int tri5[] = {rec3[0]-10,rec3[1],rec3[0]-10,rec3[3],rec3[0]-60,(rec3[1]+rec3[3])/2,rec3[0]-10,rec3[1]};
//	int tri6[] = {rec3[2]+10,rec3[1],rec3[2]+10,rec3[3],rec3[2]+60,(rec3[1]+rec3[3])/2,rec3[2]+10,rec3[1]};
//	
//	int tri7[] = {rec4[0]-10,rec4[1],rec4[0]-10,rec4[3],rec4[0]-60,(rec4[1]+rec4[3])/2,rec4[0]-10,rec4[1]};
//	int tri8[] = {rec4[2]+10,rec4[1],rec4[2]+10,rec4[3],rec4[2]+60,(rec4[1]+rec4[3])/2,rec4[2]+10,rec4[1]};
//	//esc = 27; 80 ,72;
//	int tri[] = {1,2,3,4,5,6,7,8};
//	int position = 1 ;
//	setcolor(MAGENTA);
//	fillpoly(4,tri1); 	fillpoly(4,tri2);
//	while(1){
//		int h = getch();
//		// esc : 
//		if (h == 27) {
//			cleardevice();
//			break;
//		}
//		if(h == 72 || h == 80 ){
//			setfillstyle(1,BLACK); setcolor(BLACK);
//			switch(position) {
//				case 1 : 
//				fillpoly(4,tri1) ; fillpoly(4,tri2);
//				break;
//				case 2 :
//				fillpoly(4,tri3) ; fillpoly(4,tri4);
//				break;
//				case 3 :
//				fillpoly(4,tri5) ; fillpoly(4,tri6);
//				break;
//				case 4 :
//				fillpoly(4,tri7) ; fillpoly(4,tri8);
//				break;
//			}
//			setfillstyle(1,MAGENTA); setcolor(MAGENTA);
//			if(h==72) {
//				if(position == 1) position = 4; else position-=1;
//			}
//			if(h==80) {
//				if(position == 4) position = 1; else position+=1;
//			}
//			switch(position) {
//				case 1 : 
//				fillpoly(4,tri1) ; fillpoly(4,tri2);
//				break;
//				case 2 :
//				fillpoly(4,tri3) ; fillpoly(4,tri4);
//				break;
//				case 3 :
//				fillpoly(4,tri5) ; fillpoly(4,tri6);
//				break;
//				case 4 :
//				fillpoly(4,tri7) ; fillpoly(4,tri8);
//				break;
//			}
//		}
////		if (h==13) {
////			if(position == 1){
////				setbkcolor(15);
////				cleardevice(); 
////				if (xfile > 10) row  = xfile ;else row = 10  ;  col = 6;
////				inbang("BANG GIA XI MANG");
////				goto tt;
////			}
////		}
////	}
//}
//}
void GRAPHIC::manager() {
	bgr();
	tt:
	int rec1[]= {500,150,900,210};
	int rec2[] = {500,220,900,280};
	int rec3[] = {500,290,900,350}; 
	int rec4[] = {500,360,900,420}; 

	settextstyle(4,0,5);
	setcolor(WHITE);
	char text[] = "CHON LOAI MAT HANG"; 
	outtextxy(700 ,100,text);
	setcolor(11);
	settextstyle(4,0,2);

	rectangle(rec1[0],rec1[1],rec1[2],rec1[3]);
	char text1[] = "KHO";
	outtextxy((rec1[0]+rec1[2])/2,(rec1[1]+rec1[3])/2+10,text1);
	rectangle(rec2[0],rec2[1],rec2[2],rec2[3]);
	char text2[]= "KHACH HANG";
	outtextxy((rec2[0]+rec2[2])/2,(rec2[1]+rec2[3])/2+10,text2);
	rectangle(rec3[0],rec3[1],rec3[2],rec3[3]);
	char text3[] = "BAN HANG";
	outtextxy((rec3[0]+rec3[2])/2,(rec3[1]+rec3[3])/2+10,text3);
	rectangle(rec4[0],rec4[1],rec4[2],rec4[3]);
	char text4[] = "TAI CHINH";
	outtextxy((rec4[0]+rec4[2])/2,(rec4[1]+rec4[3])/2+10,text4);
	setfillstyle(1,MAGENTA);
	
	int tri1[] = {rec1[0]-10,rec1[1],rec1[0]-10,rec1[3],rec1[0]-60,(rec1[1]+rec1[3])/2,rec1[0]-10,rec1[1]};
	int tri2[] = {rec1[2]+10,rec1[1],rec1[2]+10,rec1[3],rec1[2]+60,(rec1[1]+rec1[3])/2,rec1[2]+10,rec1[1]};
	
	int tri3[] = {rec2[0]-10,rec2[1],rec2[0]-10,rec2[3],rec2[0]-60,(rec2[1]+rec2[3])/2,rec2[0]-10,rec2[1]};
	int tri4[] = {rec2[2]+10,rec2[1],rec2[2]+10,rec2[3],rec2[2]+60,(rec2[1]+rec2[3])/2,rec2[2]+10,rec2[1]};
	
	int tri5[] = {rec3[0]-10,rec3[1],rec3[0]-10,rec3[3],rec3[0]-60,(rec3[1]+rec3[3])/2,rec3[0]-10,rec3[1]};
	int tri6[] = {rec3[2]+10,rec3[1],rec3[2]+10,rec3[3],rec3[2]+60,(rec3[1]+rec3[3])/2,rec3[2]+10,rec3[1]};
	
	int tri7[] = {rec4[0]-10,rec4[1],rec4[0]-10,rec4[3],rec4[0]-60,(rec4[1]+rec4[3])/2,rec4[0]-10,rec4[1]};
	int tri8[] = {rec4[2]+10,rec4[1],rec4[2]+10,rec4[3],rec4[2]+60,(rec4[1]+rec4[3])/2,rec4[2]+10,rec4[1]};
	//esc = 27; 80 ,72;
	int tri[] = {1,2,3,4,5,6,7,8};
	int position = 1 ;
	setcolor(MAGENTA);
	fillpoly(4,tri1); 	fillpoly(4,tri2);
	while(1){
		int h = getch();
		// esc : 
		if (h == 27) {
			cleardevice();
			break;
		}
		if(h == 72 || h == 80 ){
			setfillstyle(1,BLACK); setcolor(BLACK);
			switch(position) {
				case 1 : 
				fillpoly(4,tri1) ; fillpoly(4,tri2);
				break;
				case 2 :
				fillpoly(4,tri3) ; fillpoly(4,tri4);
				break;
				case 3 :
				fillpoly(4,tri5) ; fillpoly(4,tri6);
				break;
				case 4 :
				fillpoly(4,tri7) ; fillpoly(4,tri8);
				break;
			}
			setfillstyle(1,MAGENTA); setcolor(MAGENTA);
			if(h==72) {
				if(position == 1) position = 4; else position-=1;
			}
			if(h==80) {
				if(position == 4) position = 1; else position+=1;
			}
			switch(position) {
				case 1 : 
				fillpoly(4,tri1) ; fillpoly(4,tri2);
				break;
				case 2 :
				fillpoly(4,tri3) ; fillpoly(4,tri4);
				break;
				case 3 :
				fillpoly(4,tri5) ; fillpoly(4,tri6);
				break;
				case 4 :
				fillpoly(4,tri7) ; fillpoly(4,tri8);
				break;
			}
		}
		if (h==13) {
			if(position == 1){
				setbkcolor(15);
				cleardevice(); 
				if (xfile > 10) row  = xfile ;else row = 10  ;  col = 6;
				char text5[] ="BANG GIA SAN PHAM";
//				inbang(text5,2);
				goto tt;
			}
		}
	}
	closegraph();
}

void GRAPHIC::purchase(Warehouse warehouse , CustomerManager customerList) {
		bgr();
		setbkcolor(15);
		cleardevice(); 
		if (xfile > 10) row  = xfile ;else row = 10  ;  col = 6;
		char text[]  = "BANG GIA SAN PHAM";
		inbang(text,1,warehouse , customerList);
//		cleardevice();
		closegraph();
} 
int GRAPHIC::menu() {
	bgr();

	int rec1[]= {500,100,900,160};
	int rec2[] = {500,170,900,230};
//	int rec3[] = {500,240,900,300}; 
	
	setcolor(11); 
	settextstyle(4,0,4);
	rectangle(rec1[0],rec1[1],rec1[2],rec1[3]);

	char text1[] = "MUA HANG";
	outtextxy((rec1[0]+rec1[2])/2,(rec1[1]+rec1[3])/2+10,text1);
	rectangle(rec2[0],rec2[1],rec2[2],rec2[3]);
	char text2[] = "QUAN LY";
	outtextxy((rec2[0]+rec2[2])/2,(rec2[1]+rec2[3])/2+10,text2);
//	rectangle(rec3[0],rec3[1],rec3[2],rec3[3]);
//	outtextxy((rec3[0]+rec3[2])/2,(rec3[1]+rec3[3])/2+10,"QUAN LY NHAN VIEN");
	setfillstyle(1,MAGENTA);
	
	int tri1[] = {rec1[0]-10,rec1[1],rec1[0]-10,rec1[3],rec1[0]-60,(rec1[1]+rec1[3])/2,rec1[0]-10,rec1[1]};
	int tri2[] = {rec1[2]+10,rec1[1],rec1[2]+10,rec1[3],rec1[2]+60,(rec1[1]+rec1[3])/2,rec1[2]+10,rec1[1]};
	
	int tri3[] = {rec2[0]-10,rec2[1],rec2[0]-10,rec2[3],rec2[0]-60,(rec2[1]+rec2[3])/2,rec2[0]-10,rec2[1]};
	int tri4[] = {rec2[2]+10,rec2[1],rec2[2]+10,rec2[3],rec2[2]+60,(rec2[1]+rec2[3])/2,rec2[2]+10,rec2[1]};
	
//	int tri5[] = {rec3[0]-10,rec3[1],rec3[0]-10,rec3[3],rec3[0]-60,(rec3[1]+rec3[3])/2,rec3[0]-10,rec3[1]};
//	int tri6[] = {rec3[2]+10,rec3[1],rec3[2]+10,rec3[3],rec3[2]+60,(rec3[1]+rec3[3])/2,rec3[2]+10,rec3[1]};
	//esc = 27; 80 ,72;
	int tri[] = {1,2,3,4};
	int position = 1 ;
	setcolor(MAGENTA);
	fillpoly(4,tri1); 	fillpoly(4,tri2);
	while(1){
		int h = getch();
		if (h == 27) return 0;
		if(h == 72 || h == 80 ){
			setfillstyle(1,BLACK); setcolor(BLACK);
			switch(position) {
				case 1 : 
				fillpoly(4,tri1) ; fillpoly(4,tri2);
				break;
				case 2 :
				fillpoly(4,tri3) ; fillpoly(4,tri4);
				break;
//				case 3 :
//				fillpoly(4,tri5) ; fillpoly(4,tri6);
//				break;
			}
			setfillstyle(1,MAGENTA); setcolor(MAGENTA);
			if(h==72) {
				if(position == 1) position = 2; else position-=1;
			}
			if(h==80) {
				if(position == 2) position = 1; else position+=1;
			}
			switch(position) {
				case 1 : 
				fillpoly(4,tri1) ; fillpoly(4,tri2);
				break;
				case 2 :
				fillpoly(4,tri3) ; fillpoly(4,tri4);
				break;
//				case 3 :
//				fillpoly(4,tri5) ; fillpoly(4,tri6);
//				break;
			}
		}
		if(h == 13) 
		{
			docfile();
//			cleardevice();
			if(position == 1) 
			{
				closegraph();
				return 1;
//				purchase();
//				goto tt;
			} else 
			if(position == 2) 
			{
				closegraph();
				return 2;
//				manager();
//				goto tt ;
			}  
			
		}
	}

}

void GRAPHIC::main(){
	bgr();
	char text[] = "Quan Ly cua hang Vat Lieu";
	outtextxy(700,100,text);
	settextstyle(4,0,7);
	char text1[] = "START";
	outtextxy(700 ,300,text1);
	settextstyle(4,0,2);
	getch();
	cleardevice();
	moveto(0,0);
//	menu();
	closegraph();
}
