#include <iostream>
#include <string.h>
using namespace std; 

int main() {

	cout<<"brainfuck shell"<<endl;

	// �������� 
	string input; // �û�����
	char str;
	int i; // ѭ����
	int mem[255]; // �ڴ� 
	short needle = 0; // ָ�� 
	double If = true; // ��Ҳ��֪����ʲô��������������'['��¼״̬
	short dou; // Ҳ��֪����ʲô��������������'['��¼λ�� 

	while (true) {
		cout<<">>>";
		cin>>input;
		if (input == "exit") {
			return 0;
		} else if (input == "help") {
			cout<<"A total of 256 units are stored\n"; // һ����ṩ256���洢��Ԫ 
			cout<<"'+' : Add 1 to the cell storage pointed to by the pointer\n"; // ָ��ָ��ĵ�Ԫ��ֵ��1 
			cout<<"'-' : The cell storage pointed to by the pointer minus 1\n"; // ָ��ָ��ĵ�Ԫ��ֵ��1
			cout<<"'<' : Move the pointer one place to the left\n"; // ָ������һ�� 
			cout<<"'>' : Move the pointer one place to the right\n"; // ָ������һ�� 
			cout<<"'.' : Output the value of the pointer pointing to the cell in ASCLL code\n"; // ָ��ָ��ĵ�Ԫ��ֵ��ascll����� 
			cout<<"',' : The user requests input characters and saves them in the ASCLL code in the unit pointed to by the pointer\n"; // ���û������ַ���ͨ��ascll��洢��ָ��ָ��ĵ�Ԫ 
			cout<<"'[' : If the pointer points to a cell value of 0, jump to the nearest ']'\n"; // ���ָ��ָ��ĵ�ԪΪ�㣬��ת����һ����]���� 
			cout<<"']' : If the pointer points to a cell value other than 0, jump to the previous '['\n"; // ���ָ��ָ��ĵ�Ԫ��Ϊ�㣬��ת����һ����[���� 
			continue;
		} 

		// ��ʼ�� 
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
