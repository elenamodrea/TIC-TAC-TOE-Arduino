#include <Keypad.h>

const byte ROWS = 3; //three rows
const byte COLS = 3; //three columns
int n=-1;
//define the symbols on the buttons of the keypads
//from the custom_keypad file provided by the Arduino tools
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

int grid[] = {0,0,0,0,0,0,0,0,0,0};
bool XTurn = true;
bool XWon = false;
bool OWon = false;
bool AI= false;
int moves=0;
int moves2=0;

//Also from the custom_keypad file provided by Arduino tools
byte rowPins[ROWS] = {5,6,7}; 
byte colPins[COLS] = {2,3,4}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,INPUT_PULLUP);
  //pinMode(redPin, OUTPUT);
  //pinMode(bluePin, OUTPUT);
}
int ok=1;

void loop() { 
  if(ok==1)
   if(digitalRead(8)==0)
     {AI=true;
     }
     ok=0;
  if(AI==true)     
  { 
    if(XWon)
  {
       
  } else if(OWon) {
    
  } else {
    grid[9]=0;
    if(XTurn && moves%2==0)
     {makePlayAIComponent();
      }
     else if(!XTurn && moves%2==1)
     {arduinoMove();
      XTurn=true;
     }
     moves2++;
   checkIfWinner();
  }}
  else
  {
    if(XWon)
  {    
  } else if(OWon) {
  } else {
    grid[9]=0;
    makePlay();
    checkIfWinner();
    } 
}
moves++;
}
void printGrid(){
  for(int i=0;i<10;i++) {
      Serial.print(grid[i]);
      Serial.print(',');
  }
  Serial.println();
}
 int number(char keyn){
        if(keyn == '3')
          return 0;
        else if(keyn == '6')
          return 1;
        else if(keyn == '9')
          return 2;
        else if(keyn == '2')
          return 3;
        else if(keyn == '5')
          return 4;
        else if(keyn == '8')
          return 5;
        else if(keyn == '1')
          return 6;
        else if(keyn == '4')
          return 7;
        else if(keyn == '7')
          return 8;
        else return -1;  
    }
void makePlay(){
  char customKey = customKeypad.getKey();
  n=number(customKey);
  if(n==0){
    if(grid[0] == 0){
      if(XTurn) {
        grid[0] = 1;
      } else {
        grid[0] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==1){
    if(grid[1] == 0){
      if(XTurn) {
        grid[1] = 1;
      } else {
        grid[1] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }  
  } else if(n==2){
    if(grid[2] == 0){
      if(XTurn) {
        grid[2] = 1;
      } else {
        grid[2] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==3){
    if(grid[3] == 0){
      if(XTurn) {
        grid[3] = 1;
      } else {
        grid[3] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==4){
    if(grid[4] == 0){
      if(XTurn) {
        grid[4] = 1;
      } else {
        grid[4] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==5){
    if(grid[5] == 0){
      if(XTurn) {
        grid[5] = 1;
      } else {
        grid[5] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==6){
    if(grid[6] == 0){
      if(XTurn) {
        grid[6] = 1;
      } else {
        grid[6] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==7){
    if(grid[7] == 0){
      if(XTurn) {
        grid[7] = 1;
      } else {
        grid[7] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==8){
    if(grid[8] == 0){
      if(XTurn) {
        grid[8] = 1;
      } else {
        grid[8] = 2;
      }
      printGrid();
      XTurn = !XTurn;
    }
  }
}
void makePlayAIComponent(){
  char customKey = customKeypad.getKey();
  n=number(customKey);
  if(n==0){
    if(grid[0] == 0){
      if(XTurn) {
        grid[0] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==1){
    if(grid[1] == 0){
      if(XTurn) {
        grid[1] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }  
  } else if(n==2){
    if(grid[2] == 0){
      if(XTurn) {
        grid[2] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==3){
    if(grid[3] == 0){
      if(XTurn) {
        grid[3] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==4){
    if(grid[4] == 0){
      if(XTurn) {
        grid[4] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==5){
    if(grid[5] == 0){
      if(XTurn) {
        grid[5] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==6){
    if(grid[6] == 0){
      if(XTurn) {
        grid[6] = 1;
      } 
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==7){
    if(grid[7] == 0){
      if(XTurn) {
        grid[7] = 1;
      } 
      printGrid();
      XTurn = !XTurn;
    }
  } else if(n==8){
    if(grid[8] == 0){
      if(XTurn) {
        grid[8] = 1;
      }
      printGrid();
      XTurn = !XTurn;
    }
  }
}
int checkOpponent()
{
  if(grid[0]==1 && grid[1]==1 && grid[2]==0)
  return 2;
  else if(grid[0]==1 && grid[1]==0 && grid[2]==1)
  return 1;
  else if (grid[1]==1 && grid[2]==1 && grid[0]==0)
  return 0;
  else if (grid[3]==1 && grid[4]==1 && grid[5]==0)
  return 5;
  else if (grid[4]==1 && grid[5]==1&& grid[3]==0)
  return 3;
  else if (grid[3]==1 && grid[4]==0&& grid[5]==1)
  return 4;
  else if (grid[1]==0 && grid[4]==1&& grid[7]==1)
  return 1;
  else
  return 100;
}
int movesTTT(){
  int k=0;
  for(int i=0;i<9;i++)
     if(grid[i]!=0)
       k++;
  return k;  
  }
void arduinoMove()
{
  int b = 0;
  int counter =0;
  int movesPlayed = 0;

  int firstMoves[]={0,2,6,8};

  for(counter=0;counter<4;counter++) 
  {
    if(grid[firstMoves[counter]]!=0) 
    {
      movesPlayed++;
    }
  }  
  do{
    if(movesTTT()<=2)
    {
      int randomMove =random(4); 
      int c=firstMoves[randomMove];
      
      if (grid[c]==0)
      {  
        delay(1000);
        grid[c]=2;
        printGrid();
        b=1;
      }   
        
    }else
    {
    int nextMove = checkOpponent();
    if(nextMove == 100)
    {  
    if(movesPlayed == 4) 
    {
      int randomMove =random(9); 
      if (grid[randomMove]==0)
      {  
        grid[randomMove]=2;
        printGrid();
        b=1;
      }   
    }else
    {
      int randomMove =random(4); 
      int c=firstMoves[randomMove];
      
      if (grid[c]==0)
      {  
        grid[c]=2;
        printGrid();
        b=1;
      }   
  }
    }else
    {
       grid[nextMove]=2;
       printGrid();
       b=1;
    }
  }
  }
  while (b<1);
}

void checkIfWinner(){
  if((grid[0]==1 && grid[1]==1 && grid[2]==1) || 
     (grid[3]==1 && grid[4]==1 && grid[5]==1) || 
     (grid[6]==1 && grid[7]==1 && grid[8]==1) ||
     (grid[0]==1 && grid[3]==1 && grid[6]==1) ||
     (grid[1]==1 && grid[4]==1 && grid[7]==1) ||
     (grid[2]==1 && grid[5]==1 && grid[8]==1) ||
     (grid[0]==1 && grid[4]==1 && grid[8]==1) ||
     (grid[2]==1 && grid[4]==1 && grid[6]==1))
  {
    XWon = true;
    grid[9]=1;
    printGrid();
  } else if((grid[0]==2 && grid[1]==2 && grid[2]==2) || 
     (grid[3]==2 && grid[4]==2 && grid[5]==2) || 
     (grid[6]==2 && grid[7]==2 && grid[8]==2) ||
     (grid[0]==2 && grid[3]==2 && grid[6]==2) ||
     (grid[1]==2 && grid[4]==2 && grid[7]==2) ||
     (grid[2]==2 && grid[5]==2 && grid[8]==2) ||
     (grid[0]==2 && grid[4]==2 && grid[8]==2) ||
     (grid[2]==2 && grid[4]==2 && grid[6]==2))
  {
    OWon = true;
    grid[9]=2;
    printGrid();
  }
}
