void main() {

     unsigned long Vin, mV;
     unsigned char op[12];
     unsigned char i,j,lcd[5];
     
     TRISC = 0;      // PORTC IS AN OUTPUT
     TRISA = 0xFF;  // PORTA IS AN INPUT
     
/*CONFIGURE LCD*/
     Lcd_Init(&PORTC);
     lcd_Cmd(LCD_CLEAR);
     Lcd_Out(1,1,"VOLTMETER");
     Delay_ms(2000);
     
/*Configure A/D*/
     ADCON1 = 0x80;
     
/*PROGRAM LOOP*/

     for (; ;){
     Lcd_Cmd(LCD_CLEAR);
     Vin = Adc_Read(0);
     Lcd_Out(1,1,"mV = ");
     mV = (Vin*5000)>>10;              // right shift 10 == (Vin*5000)/2^10
     LongToStr(mV,op);                // Stores mV as a string in op
     }
/*Remove leading blanks*/

     j = o;
     for (i=0;i<=11 ;i++){
         if (op[i] != ''){
            lcd[j]=op[i];
            j++;
         }
     }
     
/*Display result on LCD*/
      Lcd_Out(1,6,lcd);
      Delay_ms(1000);
     }
}