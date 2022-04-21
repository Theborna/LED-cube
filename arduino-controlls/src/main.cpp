#include <Arduino.h>
#define inputPin 13
#define clock 12
#define outputPin 11
#define reset 10

void write(bool x)
{
  if (x)
    digitalWrite(clock, HIGH);
  digitalWrite(inputPin, HIGH);
  digitalWrite(inputPin, LOW);
  if (x)
    digitalWrite(clock, LOW);
}

void clear()
{
  digitalWrite(reset, LOW);
  delay(1);
  digitalWrite(reset, HIGH);
}

void display()
{
  digitalWrite(outputPin, HIGH);
  delay(1);
  digitalWrite(outputPin, LOW);
}

void write(bool arr[])
{
  int length = 8;
  for (int i = length - 1; i >= 0; i--)
    write(arr[i]);
}
void setup()
{
  pinMode(inputPin, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(reset, OUTPUT);
  digitalWrite(reset, HIGH);
  // put your setup code here, to run once:
}

void moveDown(bool arr[], int timeStep)
{
  write(arr);
  while (1)
  {
    delay(timeStep);
    clear();

    bool temp = arr[7];
    for (int i = 1; i < 8; i++)
    {
      arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    write(arr[0]);

    display();
  }
}

bool arr[8] = {0, 1, 0, 1, 1, 0, 0, 0};
void loop()
{
  digitalWrite(outputPin, LOW);
  write(1);
  delay(1000);
  digitalWrite(outputPin, HIGH);
}