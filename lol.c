#include <stdio.h>
void print_bin(int n){
	for(int i = 0; i < sizeof(n); i++){
		print("%d", (n >> i)&1);
	}
	print("\n");
	return;
}

int main(){
	char dec = 123;
	char hex = 0x7b;
	char oct = 0173;
	char bin = 0b01111011;
	print_bin(dec);
	return 0;
}