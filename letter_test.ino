
#define Clock 8
#define Latch 9 
#define Data 10
#define row1 3
#define row2 4
#define row3 5
#define row4 6 
#define row5 7
#define row6 2
#define num 1<<2
char msg[] = "RAHUL SHAH   ";

bool inLoop = false;
const uint16_t t1_comp = 5000;
unsigned long int r_1 = 0xFFFF00 , r_2 = 0xFFFF00 , r_3 = 0xFFFF00 , r_4 = 0xFFFF00 , r_5 =  0xFFFF00 , r_6 = 0xFFFF00;
unsigned long int reg = 0xFF0000 , reg_1 = 0x00FF00;
long int indexOfLetter=0 , leterNum , bitShifted = 0;
void latch(){
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
}
byte letters[27][6] = {
{0b111111 , 0b111111 , 0b111111 , 0b111111 , 0b111111 , 0b111111} , // space
{0b100011 , 0b011101 , 0b000001 , 0b011101 , 0b011101 , 0b011101} , // A
{0b000011 , 0b011101 , 0b000011 , 0b000011 , 0b011101 , 0b000011} , // B
{0b000011 , 0b011111 , 0b011111 , 0b011111 , 0b011111 , 0b000011} , // C
{0b000111 , 0b011011 , 0b011101 , 0b011101 , 0b011011 , 0b000111} , // D
{0b000011 , 0b011111 , 0b000011 , 0b000011 , 0b011111 , 0b000011} , // E
{0b000011 , 0b011111 , 0b000011 , 0b011111 , 0b011111 , 0b011111} , // F
{0b000011 , 0b011111 , 0b011111 , 0b010011 , 0b011011 , 0b000011} , // G
{0b011101 , 0b011101 , 0b000001 , 0b000001 , 0b011101 , 0b011101} , // H
{0b000001 , 0b110111 , 0b110111 , 0b110111 , 0b110111 , 0b000001} , // I
{0b000001 , 0b110111 , 0b110111 , 0b110111 , 0b010111 , 0b000111} , // J
{0b011011 , 0b010111 , 0b001111 , 0b001111 , 0b010111 , 0b011011} , // K
{0b011111 , 0b011111 , 0b011111 , 0b011111 , 0b011111 , 0b000011} , // L
{0b011101 , 0b001001 , 0b010101 , 0b011101 , 0b011101 , 0b011101} , // M
{0b011101 , 0b001101 , 0b000101 , 0b010001 , 0b011001 , 0b011101} , // N
{0b100111 , 0b011011 , 0b011011 , 0b011011 , 0b011011 , 0b100111} , // O
{0b000011 , 0b011011 , 0b000011 , 0b011111 , 0b011111 , 0b011111} , // P
{0b011011 , 0b011011 , 0b000011 , 0b111011 , 0b111001 , 0b111011} , // Q
{0b000011 , 0b011101 , 0b000011 , 0b001111 , 0b010111 , 0b011011} , // R
{0b100011 , 0b011101 , 0b100111 , 0b110011 , 0b011101 , 0b100011} , // S
{0b000001 , 0b110111 , 0b110111 , 0b110111 , 0b110111 , 0b110111} , // T
{0b011101 , 0b011101 , 0b011101 , 0b011101 , 0b000001 , 0b100011} , // U
{0b111111 , 0b011101 , 0b011101 , 0b101011 , 0b110111 , 0b111111} , // V
{0b011101 , 0b011101 , 0b011101 , 0b010101 , 0b001001 , 0b011101} , // W
{0b011101 , 0b101011 , 0b110111 , 0b101011 , 0b011101 , 0b111111} , // X
{0b011101 , 0b101011 , 0b110111 , 0b101111 , 0b011111 , 0b111111} , // Y
{0b000000 , 0b111101 , 0b111011 , 0b110111 , 0b101111 , 0b000000}   // Z
};

//void num_0(){
//  _1 = ((_1<<4) | (0b0000));
//  _2 = ((_2<<4) | (0b0110));
//  _3 = ((_3<<4) | (0b0110));
//  _4 = ((_4<<4) | (0b0110));
//  _5 = ((_5<<4) | (0b0110));
//  _6 = ((_6<<4) | (0b0000));
//  i = i + 4;
//}
//void num_1(){
//  _1 = ((_1<<3) | (0b101));
//  _2 = ((_2<<3) | (0b101));
//  _3 = ((_3<<3) | (0b101));
//  _4 = ((_4<<3) | (0b101));
//  _5 = ((_5<<3) | (0b101));
//  _6 = ((_6<<3) | (0b101));
//  i = i + 3;
//}
//void num_2(){
//  _1 = ((_1<<4) | (0b1001));
//  _2 = ((_2<<4) | (0b0110));
//  _3 = ((_3<<4) | (0b1101));
//  _4 = ((_4<<4) | (0b1011));
//  _5 = ((_5<<4) | (0b0111));
//  _6 = ((_6<<4) | (0b0000));
//  i = i + 4;
//}
//void num_3(){
//  _1 = ((_1<<5) | (0b00001));
//  _2 = ((_2<<5) | (0b11110));
//  _3 = ((_3<<5) | (0b00000));
//  _4 = ((_4<<5) | (0b11110));
//  _5 = ((_5<<5) | (0b00001));
//  _6 = ((_6<<5) | (0b11111));
//  i = i + 5;
//}
//void num_4(){
//  _1 = ((_1<<4) | (0b0110));
//  _2 = ((_2<<4) | (0b0110));
//  _3 = ((_3<<4) | (0b0000));
//  _4 = ((_4<<4) | (0b1111));
//  _5 = ((_5<<4) | (0b1111));
//  _6 = ((_6<<4) | (0b1111));
//  i = i + 4;
//}
//void num_5(){
//  _1 = ((_1<<4) | (0b0000));
//  _2 = ((_2<<4) | (0b0111));
//  _3 = ((_3<<4) | (0b0000));
//  _4 = ((_4<<4) | (0b1110));
//  _5 = ((_5<<4) | (0b0000));
//  _6 = ((_6<<4) | (0b1111));
//  i = i + 4;
//}
//void num_6(){
//  _1 = ((_1<<4) | (0b0000));
//  _2 = ((_2<<4) | (0b0111));
//  _3 = ((_3<<4) | (0b0111));
//  _4 = ((_4<<4) | (0b0000));
//  _5 = ((_5<<4) | (0b0110));
//  _6 = ((_6<<4) | (0b0000));
//  i = i + 4;
//}
//void num_7(){
//  _1 = ((_1<<5) | (0b00000));
//  _2 = ((_2<<5) | (0b11110));
//  _3 = ((_3<<5) | (0b11101));
//  _4 = ((_4<<5) | (0b11011));
//  _5 = ((_5<<5) | (0b10111));
//  _6 = ((_6<<5) | (0b01111));
//  i = i + 5;
//}
//void num_8(){
//  _1 = ((_1<<4) | (0b1001));
//  _2 = ((_2<<4) | (0b0110));
//  _3 = ((_3<<4) | (0b1001));
//  _4 = ((_4<<4) | (0b1001));
//  _5 = ((_5<<4) | (0b0110));
//  _6 = ((_6<<4) | (0b1001));
//  i = i + 4;
//}
//void num_9(){
//  _1 = ((_1<<4) | (0b0000));
//  _2 = ((_2<<4) | (0b0110));
//  _3 = ((_3<<4) | (0b0000));
//  _4 = ((_4<<4) | (0b1110));
//  _5 = ((_5<<4) | (0b1110));
//  _6 = ((_6<<4) | (0b1110));
//  i = i + 4;
//}
//void space_1(){
//  _1 = ((_1<<1) | (0b1));
//  _2 = ((_2<<1) | (0b1));
//  _3 = ((_3<<1) | (0b1));
//  _4 = ((_4<<1) | (0b1));
//  _5 = ((_5<<1) | (0b1));
//  _6 = ((_6<<1) | (0b1));
//  i = i + 1;
//}
//
//void space_2(){
//  _1 = ((_1<<2) | (0b11));
//  _2 = ((_2<<2) | (0b11));
//  _3 = ((_3<<2) | (0b11));
//  _4 = ((_4<<2) | (0b11));
//  _5 = ((_5<<2) | (0b11));
//  _6 = ((_6<<2) | (0b11));
//  i = i + 2;
//}
void setup() {
  
  pinMode(Clock , OUTPUT);
  pinMode(Latch , OUTPUT);
  pinMode(Data , OUTPUT);
  pinMode(row1 , OUTPUT);  
  pinMode(row2 , OUTPUT);
  pinMode(row3 , OUTPUT);
  pinMode(row4 , OUTPUT);
  pinMode(row5 , OUTPUT);
  pinMode(row6 , OUTPUT);
  digitalWrite(Clock , LOW);
  digitalWrite(Latch , LOW);
  digitalWrite(Data , LOW);
  digitalWrite(row1 , LOW);
  digitalWrite(row2 , LOW);
  digitalWrite(row3 , LOW);
  digitalWrite(row4 , LOW);
  digitalWrite(row5 , LOW);
  digitalWrite(row6 , LOW);
  TCCR1A = 0;
  TCCR1B &= ~(1<<WGM13);
  TCCR1B |= (1<<WGM12);
  TCCR1B |= (1<<CS12);  
  TCCR1B &= ~(1<<CS11);
  TCCR1B &= ~(1<<CS10);
  TCNT1 = 0;
  OCR1A = t1_comp;
  TIMSK1 = (1<<OCIE1A);
  sei();

}

void loop() {


  while(1){
  shiftOut(Data , Clock , MSBFIRST , (r_1&reg)>>16);
  shiftOut(Data , Clock , MSBFIRST , (r_1&reg_1)>>8);
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
  digitalWrite(row1 , HIGH);
  delayMicroseconds(5);
  digitalWrite(row1 , LOW);
  shiftOut(Data , Clock , MSBFIRST , (r_2&reg)>>16);
  shiftOut(Data , Clock , MSBFIRST , (r_2&reg_1)>>8);
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
  digitalWrite(row2 , HIGH);
  delayMicroseconds(5);
  digitalWrite(row2 , LOW);
  shiftOut(Data , Clock , MSBFIRST , (r_3&reg)>>16);
  shiftOut(Data , Clock , MSBFIRST , (r_3&reg_1)>>8);
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
  digitalWrite(row3 , HIGH);
  delayMicroseconds(5);
  digitalWrite(row3 , LOW);
  shiftOut(Data , Clock , MSBFIRST , (r_4&reg)>>16);
  shiftOut(Data , Clock , MSBFIRST , (r_4&reg_1)>>8);
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
  digitalWrite(row4 , HIGH);
  delayMicroseconds(5);
  digitalWrite(row4 , LOW);
  shiftOut(Data , Clock , MSBFIRST , (r_5&reg)>>16);
  shiftOut(Data , Clock , MSBFIRST , (r_5&reg_1)>>8);
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
  digitalWrite(row5 , HIGH);
  delayMicroseconds(5);
  digitalWrite(row5 , LOW);
  shiftOut(Data , Clock , MSBFIRST , (r_6&reg)>>16);
  shiftOut(Data , Clock , MSBFIRST , (r_6&reg_1)>>8);
  digitalWrite(Latch , HIGH);
  digitalWrite(Latch , LOW);
  digitalWrite(row6 , HIGH);
  delayMicroseconds(5);
  digitalWrite(row6 , LOW);
  }
}

ISR(TIMER1_COMPA_vect)
{
  if(inLoop){
    r_1 = r_1 << 1;
    r_2 = r_2 << 1;
    r_3 = r_3 << 1;
    r_4 = r_4 << 1;
    r_5 = r_5 << 1;
    r_6 = r_6 << 1;
    bitShifted++;
    if(bitShifted == 6){
      bitShifted = 0;
      inLoop = false;
    }
    
  }
  else{
   leterNum = msg[indexOfLetter] - '@' ;
   if(leterNum<0)
   leterNum = 0;
   r_1 = r_1 | (letters[leterNum][0]<<2);
   r_2 = r_2 | (letters[leterNum][1]<<2);
   r_3 = r_3 | (letters[leterNum][2]<<2);
   r_4 = r_4 | (letters[leterNum][3]<<2);
   r_5 = r_5 | (letters[leterNum][4]<<2);
   r_6 = r_6 | (letters[leterNum][5]<<2);
   indexOfLetter++;
   inLoop = true;
   if(indexOfLetter == (sizeof(msg) - 1))
   indexOfLetter = 0;
   
  }
}
