/*
 * Stepper_Motor
 * 步进电机驱动，实现正反转
 */
#define DATAIN 0

void setup() 
{
  // to define the pinMode from 2 to 5 as out put
  for (int i = 2; i < 6; i++) 
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  randomSeed(analogRead(DATAIN)); //let the random funtion start at renadom point
}

void clockwise(int num)
{
  for (int count = 0; count < num; count++)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, HIGH);
      delay(3);
      digitalWrite(i, LOW);
    }
  }
}

void anticlockwise(int num)
{
  for (int count = 0; count < num; count++)
  {
    for (int i = 5; i > 1; i--)
    {
      digitalWrite(i, HIGH);
      delay(3);
      digitalWrite(i, LOW);
    }
  }
}

void loop() 
{
  // 512 is one cycle,it is defined by stepper itself
  // actual time cycle is from 0 to 110 second, so define the range to be 2 second to 100 second
  // when the random value higher than 80 second, clockwise 2 to 3 second, then anticlockwis
  int tingzi=random(12000,100000);
  if(tingzi>80000)
  {
    clockwise(512);
    delay(tingzi);
    clockwise(512);
    delay(random(600,1200));
    anticlockwise(512);
    delay(random(2000,6000));
  }
  else
  {
    clockwise(512);
    delay(tingzi);
  }
}
