#include<iostream.h>
#include<graphics.h>

#define OFFSET 100
#define CIRCLE 20

void initCoordinates();
void drawBoard();
void drawX(int);
void drawO(int);

int x0, x1, x2, x3;
int y0, y1, y2, y3;

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	initCoordinates();
	drawBoard();
	initCoordinates();
	drawO(1);
	drawX(2);
	drawO(3);
	drawX(4);
	drawX(5);
	drawO(6);
	drawO(7);
	drawX(8);
	drawX(9);
	// Pause Screen
	char a;
	cin>>a;
	return 0;
}

void initCoordinates() {
	x0=OFFSET;
	y0=OFFSET;
	x3=(getmaxx()-OFFSET);
	y3=(getmaxy()-OFFSET);

	x1=(x3-x0)/3 * 1 + x0;
	x2=(x3-x0)/3 * 2 + x0;
	y1=(y3-y0)/3 * 1 + y0;
	y2=(y3-y0)/3 * 2 + y0;
}

void drawO(int block) {
	int x=0, y=0;
	switch(block) {
		case 1:
			x=(x1-x0)/2+x0;
			y=(y1-y0)/2+y0;
			break;
		case 2:
			x=(x2-x1)/2+x1;
			y=(y1-y0)/2+y0;
			break;
		case 3:
			x=(x3-x2)/2+x2;
			y=(y1-y0)/2+y0;
			break;
		case 4:
			x=(x1-x0)/2+x0;
			y=(y2-y1)/2+y1;
			break;
		case 5:
			x=(x2-x1)/2+x1;
			y=(y2-y1)/2+y1;
			break;
		case 6:
			x=(x3-x2)/2+x2;
			y=(y2-y1)/2+y1;
			break;
		case 7:
			x=(x1-x0)/2+x0;
			y=(y3-y2)/2+y2;
			break;
		case 8:
			x=(x2-x1)/2+x1;
			y=(y3-y2)/2+y2;
			break;
		case 9:
			x=(x3-x2)/2+x2;
			y=(y3-y2)/2+y2;
			break;
		default:
			break;
	}
	//cout<<"Circle::x="<<x<<" and y="<<y<<endl;
	circle(x, y, CIRCLE);
}

void drawX(int block) {
	int x=0, y=0;
	switch(block) {
		case 1:
			x=(x1-x0)/2+x0;
			y=(y1-y0)/2+y0;
			break;
		case 2:
			x=(x2-x1)/2+x1;
			y=(y1-y0)/2+y0;
			break;
		case 3:
			x=(x3-x2)/2+x2;
			y=(y1-y0)/2+y0;
			break;
		case 4:
			x=(x1-x0)/2+x0;
			y=(y2-y1)/2+y1;
			break;
		case 5:
			x=(x2-x1)/2+x1;
			y=(y2-y1)/2+y1;
			break;
		case 6:
			x=(x3-x2)/2+x2;
			y=(y2-y1)/2+y1;
			break;
		case 7:
			x=(x1-x0)/2+x0;
			y=(y3-y2)/2+y2;
			break;
		case 8:
			x=(x2-x1)/2+x1;
			y=(y3-y2)/2+y2;
			break;
		case 9:
			x=(x3-x2)/2+x2;
			y=(y3-y2)/2+y2;
			break;
		default:
			break;
	}
	line(x,y,x+10,y+10);
	line(x,y,x-10,y-10);
	line(x,y,x+10,y-10);
	line(x,y,x-10,y+10);
}

void drawBoard() {
	cout<<endl<<endl;
	cout<<"\t\t\t     Welcome To TICK TAC TOE"<<endl;
	//cout<<"X::"<<x0<<","<<x1<<","<<x2<<","<<x3<<endl;
	//cout<<"Y::"<<y0<<","<<y1<<","<<y2<<","<<y3<<endl;

	// Grid Lines
	line(x1, y0, x1, y3);
	line(x2, y0, x2, y3);
	line(x0, y1, x3, y1);
	line(x0, y2, x3, y2);

	// Borders
	for(int i=0;i<3;i++) {
		x0=x0-i;y0=y0-i;
		x3=x3+i;y3=y3+i;
		line(x0, y0, x0, y3); // Left Border
		line(x0, y3, x3, y3); // Bottom Border
		line(x3, y3, x3, y0); // Right Border
		line(x3, y0, x0, y0); // Top Border
	}
}