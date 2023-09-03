#include <iostream>
#include <string.h>
using namespace std; 

int main() {

	cout<<"brainfuck shell"<<endl;

	// 声明变量 
	string input; // 用户输入
	char str;
	int i; // 循环用
	int mem[255]; // 内存 
	short needle = 0; // 指针 
	double If = true; // 我也不知道叫什么，反正就是遇到'['记录状态
	short dou; // 也不知道叫什么，反正就是遇到'['记录位置 

	while (true) {
		cout<<">>>";
		cin>>input;
		if (input == "exit") {
			return 0;
		} else if (input == "help") {
			cout<<"A total of 256 units are stored\n"; // 一般会提供256个存储单元 
			cout<<"'+' : Add 1 to the cell storage pointed to by the pointer\n"; // 指针指向的单元的值加1 
			cout<<"'-' : The cell storage pointed to by the pointer minus 1\n"; // 指针指向的单元的值减1
			cout<<"'<' : Move the pointer one place to the left\n"; // 指针左移一格 
			cout<<"'>' : Move the pointer one place to the right\n"; // 指针右移一格 
			cout<<"'.' : Output the value of the pointer pointing to the cell in ASCLL code\n"; // 指针指向的单元的值以ascll码输出 
			cout<<"',' : The user requests input characters and saves them in the ASCLL code in the unit pointed to by the pointer\n"; // 向用户输入字符并通过ascll码存储到指针指向的单元 
			cout<<"'[' : If the pointer points to a cell value of 0, jump to the nearest ']'\n"; // 如果指针指向的单元为零，跳转到下一个‘]’处 
			cout<<"']' : If the pointer points to a cell value other than 0, jump to the previous '['\n"; // 如果指针指向的单元不为零，跳转到上一个‘[’处 
			continue;
		} 

		// 初始化 
		for (i = 0; i < 256; i++) {
			mem[i] = 0;
		}
		needle = 0;
		If = true;
		dou = -1;

		try {
			for (i = 0; i <= input.length(); i++) {
				if (If) {
					if (input[i] == '+') {
						mem[needle] += 1;
					} else if (input[i] == '-') {
						mem[needle] -= 1;
					} else if (input[i] == '>') {
						needle += 1;
					} else if (input[i] == '<') {
						needle -= 1;
					} else if (input[i] == '.') {
						str = mem[needle];
						cout<<str;
					} else if (input[i] == ',') {
						cin>>str;
						mem[needle] = str;
					} else if (input[i] == '[') {
						dou = i; 
						if (mem[needle] == 0) {
							If = false;
						}
					} else if (input[i] == ']') {
						if (mem[needle] != 0) {
							i = dou;
						}
					}
				} else if (input[i] == ']') {
					If = true;
				}
			}
		} catch (std::exception) {
			cout<<"error!!!";
		}
		cout<<endl;
	}
}
