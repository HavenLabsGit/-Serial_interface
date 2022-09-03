/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18877
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc.h"
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
    

#include <stdio.h>
#include "../../../Programming/PIC16F18877/libs/i2c_drivers.h"
#include "../../../Programming/PIC16F18877/libs/eeprom.h"



#define READ 0xA1
#define WRITE 0xA0


uint8_t data, data1, data2;
uint8_t addr1;
uint8_t addr2;
uint8_t rx_data, hex, hex2, count;
char test[10];
uint8_t test2[10];
char letter, str[3];
int count2, x = 0;

void send_string(const char *x)
{
    while (*x)
    {
        EUSART_Write(*x++);
    }
}

uint8_t get_hex(uint8_t c);
uint8_t create_hex(int c);

uint8_t get_hex(uint8_t letter){
    
    switch(letter){
        
        case 0x30:
            letter = 0x00;
            return letter;
        case 0x31:
            letter = 0x01;
            return letter;
        case 0x32:
            letter = 0x02;
            return letter;
        case 0x33:
            letter = 0x03;
            return letter;
        case 0x34:
            letter = 0x04;
            return letter;
        case 0x35:
            letter = 0x05;
            return letter;
        case 0x36:
            letter = 0x06;
            return letter;
        case 0x37:
            letter = 0x07;
            return letter;
        case 0x38:
            letter = 0x08;
            return letter;
        case 0x39:
            letter = 0x09;
            return letter;
        case 0x41:
        case 0x61:
            letter = 0x0A;
            return letter;
        case 0x42:
        case 0x62:
            letter = 0x0B;
            return letter;
        case 0x43:
        case 0x63:
            letter = 0x0C;
            return letter;
        case 0x44:
        case 0x64:
            letter = 0x0D;
            return letter;
        case 0x45:
        case 0x65:
            letter = 0x0E;
            return letter;
        case 0x46:
        case 0x66:
            letter = 0x0F;
            return letter;

    }          
    return 0;
}

 uint8_t create_hex(int c){
 while(1){
    if(c == 0 || c == 2 || c == 4 || c == 6){
        hex = test2[c];
        hex <<= 4;
        hex2 = hex;
        
        break;
    }
    else if(c == 1){
        hex = test2[c];
        hex2 |= hex;
        addr1 = hex2;
        
        break;
    }
    else if( c == 3){
        hex = test2[c];
        hex2 |= hex;               
        addr2 = hex2;
       
        break;
    }

    else if(c == 5){
        hex = test2[c];
        hex2 |= hex;
        data = hex2;
        
        break;
    }
    
    else if(c == 7){
        hex = test2[c];
        hex2 |= hex;
        count = hex2;
        
        break;
    }


    else{
        break;
    }
 }
 return 0;
 }
           
   
     

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    I2C_Init();
             
   
    letter = getch();
    
    
    
    
    
    switch(letter){
   
        case '1':
        {
        for(int i = 0; i < 6; i++){
            letter = getch();
            test[i] = letter;
            
       }
       
         for(int i = 0; i < 6; i++){
            test2[i] = get_hex(test[i]);
            
         }
        
        for(int i = 0; i < 6; i++){
            create_hex(i);

        }
            byte_write(addr1, addr2, data);
            
           
            break;
        }
        case '2': 
        {
            
        for(int i = 0; i < 6; i++){
            letter = getch();
            
            test[i] = letter;
           
       }
        
        for(int i = 0; i < 3; i++){
             str[i] = getch();
             count2  = atoi(str);
        }
        
         for(int i = 0; i < 6; i++){
            test2[i] = get_hex(test[i]);
            
         }
        
        for(int i = 0; i < 6; i++){
            
            create_hex(i);

        } 
        
        
            page_write(addr1, addr2, data, count2);
            break;
        }
        case '3':
        {
         for(int i = 0; i < 4; i++){
            letter = getch();
            test[i] = letter;
            
       }
         for(int i = 0; i < 3; i++){
             str[i] = getch();
             count2  = atoi(str);

         }
        
         for(int i = 0; i < 4; i++){
            
            test2[i] = get_hex(test[i]);

         }
        
        for(int i = 0; i < 4; i++){
            create_hex(i);

        }
        
            sequential_read(addr1, addr2, count2);
            break;
        }
        case '4':
        {
               for(int i = 0; i < 4; i++){
            letter = getch();
            test[i] = letter;
            
       }
        
         for(int i = 0; i < 4; i++){
            test2[i] = get_hex(test[i]);
            
         }
        
        for(int i = 0; i < 4; i++){
            create_hex(i);

        }
            data = random_read(addr1, addr2);
            printf("%X\n", data);
            break;
        }

    }
        
    }
 

/**
 End of File
*/