// rm showkey showkey.o; gcc -Wall -c -o showkey.o showkey.c && gcc -static -g -O2 -Wall -o showkey showkey.o && sudo ./showkey
// sudo strace -f -i -X verbose ./showkey

// sudo cat /dev/tty0 | hexdump -C # mostra scancodes. simple keylogger
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <signal.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <linux/keyboard.h>

int fd;
struct termios old;

static void __attribute__((noreturn)) watch_dog(int x __attribute__((unused))) {
	if (tcsetattr(fd, 0, &old) == -1) printf("tcsetattr\n");
	close(fd);
	exit(EXIT_SUCCESS);
}

int main() {
	struct termios new;
	unsigned char buf[18]; // divisible by 3
	int i, n;
    
    fd = open("/dev/tty0", O_RDONLY);
	if (fd < 0) { printf("Couldn't get a file descriptor referring to the console\n"); return 1;}

	signal(SIGALRM, watch_dog); // the program terminates when there is no input for n secs

	if (tcgetattr(fd, &old) == -1) printf("tcgetattr old\n");
	if (tcgetattr(fd, &new) == -1) printf("tcgetattr new\n");
    
	new.c_lflag &= ~(ICANON | ECHO | ISIG);
	new.c_iflag     = 0;
	new.c_cc[VMIN]  = sizeof(buf);
	new.c_cc[VTIME] = 1; // 0.1 sec intercharacter timeout

	if (tcsetattr(fd, TCSAFLUSH, &new) == -1) printf("tcsetattr\n");
	if (ioctl(fd, KDSKBMODE, K_MEDIUMRAW)) { printf("ioctl KDSKBMODE\n"); return 1;}

	printf("press any key (program terminates 4s after last keypress)...\n");

	while (1) {
		alarm(4);
		n = read(fd, buf, sizeof(buf));
		for (i = 0; i < n; i++) printf("0x%02x ", buf[i]); // (buf[i] & 0x80) ? "release" : "press";
		printf("\n");
	}

	if (tcsetattr(fd, 0, &old) == -1) printf("tcsetattr\n");
	close(fd);
	return 0;
}
