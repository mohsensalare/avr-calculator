/*******************************************************
This program was created by the mohsensalare@gmail.com
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
? Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 02/04/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8/000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
#include <stdio.h>
// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

unsigned char y[16],w[16],o[16];
unsigned char read=20,sum=0,q;
unsigned int l,p,j=0,t,k;
unsigned int r;

unsigned char calculat(void){ 
    PORTD.7=0;
    delay_ms(2);
    if(PIND.0==0){
        q=21;lcd_putchar('/');
        delay_ms(300); }
    if(PIND.1==0){
        q=22;lcd_putchar('*');
        delay_ms(300);
        }
    if(PIND.2==0){
        q=23;lcd_putchar('-');
        delay_ms(300);
    }
    if(PIND.3==0){
        q=24;lcd_putchar('+');
        delay_ms(300);
        }       
    PORTD.7=1;
    return q;
}

unsigned char keyboard(void)
{
    read=20; 
    PORTD.4=0;
    delay_ms(2);
    if(PIND.0==0)
        read=7;
    if(PIND.1==0)
        read=4;
    if(PIND.2==0)
        read=1;
    if(PIND.3==0){
        lcd_clear();
        read=20;
        sum=0;
        q=0;
        l=0;
        p=0;
        j=0;
        t=0;
    }
    PORTD.4=1;

    PORTD.5=0;
    delay_ms(2);
    if(PIND.0==0)   
        read=8;
    if(PIND.1==0)
        read=5;
    if(PIND.2==0)
        read=2;
    if(PIND.3==0)
        read=0;
    PORTD.5=1;

    PORTD.6=0;
    delay_ms(2);
    if(PIND.0==0)
        read=9;
    if(PIND.1==0)
        read=6;
    if(PIND.2==0)
        read=3;
    if(PIND.3==0){
        lcd_gotoxy(t+1,0);
        lcd_putchar('=');
        delay_ms(300);
        sum=25; 
    }
    PORTD.6=1;
    return read;
}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (0<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P 
PORTD=(1<<PORTD7) | (1<<PORTD6) | (1<<PORTD5) | (1<<PORTD4) | (1<<PORTD3) | (1<<PORTD2) | (1<<PORTD1) | (1<<PORTD0);


// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);
lcd_clear();
while (1)
      {
       lcd_gotoxy(0 , 1 );
       lcd_putsf("MOHSEN SALARI");
       lcd_gotoxy(0 , 0 );
       read=keyboard();

        if((read!=20) && (read<10) && (q<=21)&&(k!=6)) {
        l=l*10+read;
        sprintf(y,"%d",read);
        lcd_gotoxy(t,0); 
        lcd_puts(y);
        delay_ms(300);
        t++;
        }

        lcd_gotoxy(t , 0 );
        calculat();

        read=keyboard();
        if((read!=20) && (read<10) && (q>=21)) {
        p=p*10+read;
        sprintf(w,"%d",read);
        lcd_gotoxy(t+1,0);
        lcd_puts(w);
        delay_ms(300);
        t++;
        k=6;
        }
         
        if(sum==25){
        lcd_gotoxy(t+2,0);
        if(q==21)  r=l/p;       //(/)
        if(q==22)  r=l*p;       //(*)
        if(q==23)  r=l-p;       //(-)
        if(q==24)  r=l+p;       //(+)
        sprintf(o, "%d",r);
        lcd_puts(o);
        delay_ms(300);
        sum=0;
}
}
}

