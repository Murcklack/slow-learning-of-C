#include <stdio.h>

int route_packet(unsigned int incoming_ip, unsigned int gateway_ip, int cidr_prefix){
    if ((cidr_prefix > 32) | (cidr_prefix < 1)){
        printf("-1");
        return -1;
    }


    int temp_mask = 0;
    for(int i = 0; i < cidr_prefix; i++){
        temp_mask = (temp_mask << 1) | 1;
        printf("%.8x\n", temp_mask);
    }

    int mask = temp_mask;
    for(int i = 0; i < (32 - cidr_prefix); i++){
        mask <<=1;
        printf("%.8x\n", mask);
    }
    if ((incoming_ip & mask) == (gateway_ip & mask)){
        printf("1");
        return 1;
    }
    else{
        printf("0");
        return 0;
    }
}

int main(){
    unsigned int incoming_ip = 0x7FFFFFF;
    unsigned int gateway_ip = 0x10000000;
    int cidr_prefix = 24;

    route_packet(incoming_ip,gateway_ip,cidr_prefix);


    return 0;
}