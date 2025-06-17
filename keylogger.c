#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <string.h>
#include "keymap.h"

int main(int argc , char **argv){
	const char *device = "/dev/input/event0";

	struct input_event ev;
	
	int fd = open(device,O_RDONLY);
	if(fd < 0) return -1;

	while(1){

		ssize_t bytes = read(fd,&ev,sizeof(ev));
		if(bytes < (ssize_t) sizeof(ev)) return -1;

		//ev.value == 0 is released 1 is pressed 2 is repeat 
		if (ev.type == EV_KEY && ev.value == 1){
			const char *key = key_code_names[ev.code];
			printf("%s",key);
			fflush(stdout);
			
			
			
		}
		
	}


	close(fd);
	return 0;
}
