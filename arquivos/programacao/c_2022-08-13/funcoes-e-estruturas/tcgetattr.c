
// Put the state of FD into *TERMIOS_P.
// returns 0 if successful. Return -1 if error

// error
// EBADF   The filedes argument is not a valid file descriptor.
// ENOTTY  The filedes is not associated with a terminal.

//#include<bits/termios.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct termios {
   unsigned int c_iflag;     // input modes
   unsigned int c_oflag;     // output modes
   unsigned int c_cflag;     // control modes
   unsigned int c_lflag;     // local modes
   unsigned char c_line;
   unsigned char c_cc[32];   // control chars
   unsigned int c_ispeed;    // input baud rate
   unsigned int c_ospeed;    // output baud rate
};

#define CSIZE	0000060
#define   CS5	0000000
#define   CS6	0000020
#define   CS7	0000040
#define   CS8	0000060
#define CSTOPB	0000100
#define CREAD	0000200
#define PARENB	0000400
#define PARODD	0001000
#define HUPCL	0002000
#define CLOCAL	0004000

// c_iflag bits
#define IGNBRK	0000001 // Ignore BREAK condition on input.
#define BRKINT	0000002 // If IGNBRK is set, a BREAK is ignored. If it is not set but BRKINT is set, then a BREAK causes the input and output queues to be flushed, and if the terminal is the controlling terminal of a foreground process group, it will cause a SIGINT to be sent to this foreground process group. When neither IGNBRK nor BRKINT are set, a BREAK reads as a NUL character, except when PARMRK is set, in which case it reads as the sequence \377 \0 \0. 
#define IGNPAR	0000004 // Ignore framing errors and parity errors. 
#define PARMRK	0000010 // If IGNPAR is not set, prefix a character with a parity error or framing error with \377 \0. If neither IGNPAR nor PARMRK is set, read a character with a parity error or framing error as \0.
#define INPCK	0000020 // Enable input parity checking. 
#define ISTRIP	0000040 // Strip off eighth bit.
#define INLCR	0000100 // Translate NL to CR on input.
#define IGNCR	0000200 // Ignore carriage return on input.
#define ICRNL	0000400 // Translate carriage return to newline on input (unless IGNCR is set).
#define IUCLC	0001000 // (not in POSIX) Map uppercase characters to lowercase on input.
#define IXON	0002000 // Enable XON/XOFF flow control on output.
#define IXANY	0004000 // (not in POSIX.1; XSI) Enable any character to restart output.
#define IXOFF	0010000 // Enable XON/XOFF flow control on input. 
#define IMAXBEL	0020000 // (not in POSIX) Ring bell when input queue is full. Linux does not implement this bit, and acts as if it is always set.
#define IUTF8	0040000 // 

// c_lflag bits
#define ISIG	0000001
#define ICANON	0000002
#define ECHO	0000010
#define ECHOE	0000020
#define ECHOK	0000040
#define ECHONL	0000100
#define NOFLSH	0000200
#define TOSTOP	0000400

// c_oflag bits
#define OPOST	0000001
#define OLCUC	0000002
#define ONLCR	0000004
#define OCRNL	0000010
#define ONOCR	0000020
#define ONLRET	0000040
#define OFILL	0000100
#define OFDEL	0000200

#define IEXTEN	0100000


//#include<termios.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int tcgetattr(int __fd, struct termios *__termios_p);

//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);


int main() {
   int i;
   struct termios teste;
   
   tcgetattr(0, &teste);
   printf("c_iflag = 0x%08X\n", teste.c_iflag);
   printf("c_oflag = 0x%08X\n", teste.c_oflag);
   printf("c_cflag = 0x%08X\n", teste.c_cflag);
   printf("c_lflag = 0x%08X\n", teste.c_lflag);
   printf("c_line  = 0x%02X\n", (unsigned int)teste.c_line);
   printf("c_cc[i] = ");
   for(i=0; i<32 ; i++) printf("0x%02X ", (unsigned int)teste.c_cc[i]);
   printf("\n");
   printf("c_ispeed = 0x%08X\n", teste.c_ispeed);
   printf("c_ospeed = 0x%08X\n", teste.c_ospeed);
   return 0;
}



/*
O que ela faz é configurar o terminal onde o programa está sendo executado para fazer com que teclas pressionadas sejam lidas pela função getc sem a necessidade de se pressionar ENTER. Para ativar essa funcionalidade basta usar rl_ttyset(0), e para desativar rl_ttyset(1).

void rl_ttyset(int reset)
{
   static struct termios old; // Armazena as configuracoes antigas
   struct termios new;        // Recebe as novas configuracoes
   
   if(reset == 0)
   {
      (void)tcgetattr(0, &old);
      new = old;   // Copia as configuracoes antigas
      new.c_lflag &= ~(ECHO | ICANON);
      new.c_iflag &= ~(ISTRIP | INPCK);
      (void)tcsetattr(0, TCSANOW, &new); // Habilita as novas configuracoes
   }
   else
      (void)tcsetattr(0, TCSANOW, &old); // Restaura as configuracoes antigas
}



http://linux.about.com/library/cmd/blcmdl3_tcgetattr.htm

SYNOPSIS
#include <termios.h>
#include <unistd.h>



c_oflag flag constants defined in POSIX.1:

OPOST
    Enable implementation-defined output processing. 

The remaining c_oflag flag constants are defined in POSIX 1003.1-2001, unless marked otherwise.

OLCUC
    (not in POSIX) Map lowercase characters to uppercase on output. 
ONLCR
    (XSI) Map NL to CR-NL on output. 
OCRNL
    Map CR to NL on output. 
ONOCR
    Don't output CR at column 0. 
ONLRET
    Don't output CR. 
OFILL
    Send fill characters for a delay, rather than using a timed delay. 
OFDEL
    (not in POSIX) Fill character is ASCII DEL (0177). If unset, fill character is ASCII NUL. 
NLDLY
    Newline delay mask. Values are NL0 and NL1. 
CRDLY
    Carriage return delay mask. Values are CR0, CR1, CR2, or CR3. 
TABDLY
    Horizontal tab delay mask. Values are TAB0, TAB1, TAB2, TAB3 (or XTABS). A value of TAB3, that is, XTABS, expands tabs to spaces (with tab stops every eight columns). 
BSDLY
    Backspace delay mask. Values are BS0 or BS1. (Has never been implemented.) 
VTDLY
    Vertical tab delay mask. Values are VT0 or VT1. 
FFDLY
    Form feed delay mask. Values are FF0 or FF1. 

c_cflag flag constants:

CBAUD
    (not in POSIX) Baud speed mask (4+1 bits). 
CBAUDEX
    (not in POSIX) Extra baud speed mask (1 bit), included in CBAUD. 

(POSIX says that the baud speed is stored in the termios structure without specifying where precisely, and provides cfgetispeed() and cfsetispeed() for getting at it. Some systems use bits selected by CBAUD in c_cflag, other systems use separate fields, e.g. sg_ispeed and sg_ospeed.)

CSIZE
    Character size mask. Values are CS5, CS6, CS7, or CS8. 
CSTOPB
    Set two stop bits, rather than one. 
CREAD
    Enable receiver. 
PARENB
    Enable parity generation on output and parity checking for input. 
PARODD
    Parity for input and output is odd. 
HUPCL
    Lower modem control lines after last process closes the device (hang up). 
CLOCAL
    Ignore modem control lines. 
LOBLK
    (not in POSIX) Block output from a noncurrent shell layer. (For use by shl.) 
CIBAUD
    (not in POSIX) Mask for input speeds. The values for the CIBAUD bits are the same as the values for the CBAUD bits, shifted left IBSHIFT bits. 
CRTSCTS
    (not in POSIX) Enable RTS/CTS (hardware) flow control. 


c_lflag flag constants:

ISIG
    When any of the characters INTR, QUIT, SUSP, or DSUSP are received, generate the corresponding signal. 
ICANON
    Enable canonical mode. This enables the special characters EOF, EOL, EOL2, ERASE, KILL, LNEXT, REPRINT, STATUS, and WERASE, and buffers by lines. 
ECHO
    Echo input characters. 
ECHOE
    If ICANON is also set, the ERASE character erases the preceding input character, and WERASE erases the preceding word. 
ECHOK
    If ICANON is also set, the KILL character erases the current line. 
ECHONL
    If ICANON is also set, echo the NL character even if ECHO is not set. 
ECHOCTL
    (not in POSIX) If ECHO is also set, ASCII control signals other than TAB, NL, START, and STOP are echoed as ^X, where X is the character with ASCII code 0x40 greater than the control signal. For example, character 0x08 (BS) is echoed as ^H. 
ECHOPRT
    (not in POSIX) If ICANON and IECHO are also set, characters are printed as they are being erased. 
ECHOKE
    (not in POSIX) If ICANON is also set, KILL is echoed by erasing each character on the line, as specified by ECHOE and ECHOPRT. 
DEFECHO
    (not in POSIX) Echo only when a process is reading. 
FLUSHO
    (not in POSIX; not supported under Linux) Output is being flushed. This flag is toggled by typing the DISCARD character. 
NOFLSH
    Disable flushing the input and output queues when generating the SIGINT, SIGQUIT and SIGSUSP signals. 
TOSTOP
    Send the SIGTTOU signal to the process group of a background process which tries to write to its controlling terminal. 
PENDIN
    (not in POSIX; not supported under Linux) All characters in the input queue are reprinted when the next character is read. (bash handles typeahead this way.) 
IEXTEN
    Enable implementation-defined input processing. This flag, as well as ICANON must be enabled for the special characters EOL2, LNEXT, REPRINT, WERASE to be interpreted, and for the IUCLC flag to be effective. 


The c_cc array defines the special control characters. The symbolic indices (initial values) and meaning are:

VINTR
    (003, ETX, Ctrl-C, or also 0177, DEL, rubout) Interrupt character. Send a SIGINT signal. Recognized when ISIG is set, and then not passed as input. 
VQUIT
    (034, FS, Ctrl-\) Quit character. Send SIGQUIT signal. Recognized when ISIG is set, and then not passed as input. 
VERASE
    (0177, DEL, rubout, or 010, BS, Ctrl-H, or also #) Erase character. This erases the previous not-yet-erased character, but does not erase past EOF or beginning-of-line. Recognized when ICANON is set, and then not passed as input. 
VKILL
    (025, NAK, Ctrl-U, or Ctrl-X, or also @) Kill character. This erases the input since the last EOF or beginning-of-line. Recognized when ICANON is set, and then not passed as input. 
VEOF
    (004, EOT, Ctrl-D) End-of-file character. More precisely: this character causes the pending tty buffer to be sent to the waiting user program without waiting for end-of-line. If it is the first character of the line, the read() in the user program returns 0, which signifies end-of-file. Recognized when ICANON is set, and then not passed as input. 
VMIN
    Minimum number of characters for non-canonical read. 
VEOL
    (0, NUL) Additional end-of-line character. Recognized when ICANON is set. 
VTIME
    Timeout in deciseconds for non-canonical read. 
VEOL2
    (not in POSIX; 0, NUL) Yet another end-of-line character. Recognized when ICANON is set. 
VSWTCH
    (not in POSIX; not supported under Linux; 0, NUL) Switch character. (Used by shl only.) 
VSTART
    (021, DC1, Ctrl-Q) Start character. Restarts output stopped by the Stop character. Recognized when IXON is set, and then not passed as input. 
VSTOP
    (023, DC3, Ctrl-S) Stop character. Stop output until Start character typed. Recognized when IXON is set, and then not passed as input. 
VSUSP
    (032, SUB, Ctrl-Z) Suspend character. Send SIGTSTP signal. Recognized when ISIG is set, and then not passed as input. 
VDSUSP
    (not in POSIX; not supported under Linux; 031, EM, Ctrl-Y) Delayed suspend character: send SIGTSTP signal when the character is read by the user program. Recognized when IEXTEN and ISIG are set, and the system supports job control, and then not passed as input. 
VLNEXT
    (not in POSIX; 026, SYN, Ctrl-V) Literal next. Quotes the next input character, depriving it of a possible special meaning. Recognized when IEXTEN is set, and then not passed as input. 
VWERASE
    (not in POSIX; 027, ETB, Ctrl-W) Word erase. Recognized when ICANON and IEXTEN are set, and then not passed as input. 
VREPRINT
    (not in POSIX; 022, DC2, Ctrl-R) Reprint unread characters. Recognized when ICANON and IEXTEN are set, and then not passed as input. 
VDISCARD
    (not in POSIX; not supported under Linux; 017, SI, Ctrl-O) Toggle: start/stop discarding pending output. Recognized when IEXTEN is set, and then not passed as input. 
VSTATUS
    (not in POSIX; not supported under Linux; status request: 024, DC4, Ctrl-T). 

*/

