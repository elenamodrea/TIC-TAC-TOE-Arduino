import processing.serial.*;
Serial myPort;

int[] grid = {0,0,0,0,0,0,0,0,0,0};

void setup()
{
  size(400,400);
  myPort = new Serial(this, "COM11", 9600);
  myPort.bufferUntil('\n');
  
  strokeWeight(5);
  translate(10,10);

  //Draw board
  line(0,125,375,125);
  line(0,250,375,250);
  line(125,0,125,375);
  line(250,0,250,375);

}

void serialEvent(Serial myPort)
{
   String inString = myPort.readStringUntil('\n');
  println("Value Read: " + inString);
   if(inString != null)
   {
     grid = int(split(inString, ","));
     //drawShapes();
   }
}

void draw(){
  if(grid[9]==1)
      println("X won");
   else if(grid[9]==2)
       println("O Won");
else{       
  int ok=0;
for(int i=0;i<9;i++)
    if(grid[i]==0)
        ok=1;
if(ok==0)
   println("Nobody wins");
}   
if(grid[0] == 2){
  fill(204,204,204);
  ellipse(70,70,80,80);//top left
} else if(grid[0] == 1) {
   line(25,25,100,100);
   line(100,25,25,100);
}

if(grid[1] == 2){
  fill(204,204,204);
  ellipse(196,70,80,80);//top middle
} else if(grid[1] == 1) {
  line(150,25,225,100);
  line(225,25,150,100);
}

if(grid[2] == 2){
  fill(204,204,204);
  ellipse(325,70,80,80);//top right
} else if(grid[2] == 1) {
  line(275,25,350,100);
  line(350,25,275,100);
  
}

if(grid[3] == 2){
  fill(204,204,204);
  ellipse(70,196,80,80);//left middle
} else if(grid[3] == 1) {
  line(25,150,100,225);
  line(100,150,25,225);
}

if(grid[4] == 2){
  fill(204,204,204);
  ellipse(196,196,80,80);//middle
} else if(grid[4] == 1) {
  line(150,150,225,225);
  line(225,150,150,225);
}

if(grid[5] == 2){
  fill(204,204,204);
  ellipse(325,196,80,80);//right middle
} else if(grid[5] == 1) {
  line(275,150,350,225);
  line(350,150,275,225);
}

if(grid[6] == 2){
  fill(204,204,204);
  ellipse(70,325,80,80);//bottom left
} else if(grid[6] == 1) {
  line(25,275,100,350);
  line(100,275,25,350);
}

if(grid[7] == 2){
  fill(204,204,204);
  ellipse(196,325,80,80);//bottom middle
} else if(grid[7] == 1) {
  line(150,275,225,350);
  line(225,275,150,350);
 }
if(grid[8] == 2){
  fill(204,204,204);
  ellipse(325,325,80,80);//bottom right
} else if(grid[8] == 1) {
  line(275,275,350,350);
  line(350,275,275,350);
}
}
