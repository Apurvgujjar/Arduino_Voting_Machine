#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Button pins
const int voteA = 2;
const int voteB = 3;
const int voteC = 4;
const int resultBtn = 5;
const int buzzer = 6;

// Vote count
int countA = 0;
int countB = 0;
int countC = 0;

void setup() {
  pinMode(voteA, INPUT_PULLUP);
  pinMode(voteB, INPUT_PULLUP);
  pinMode(voteC, INPUT_PULLUP);
  pinMode(resultBtn, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Voting Machine");
  lcd.setCursor(0, 1);
  lcd.print("Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {

  if (digitalRead(voteA) == LOW) {
    countA++;
    beep();
    lcdMsg("Vote Casted", "Candidate A");
    delay(1000);
  }

  if (digitalRead(voteB) == LOW) {
    countB++;
    beep();
    lcdMsg("Vote Casted", "Candidate B");
    delay(1000);
  }

  if (digitalRead(voteC) == LOW) {
    countC++;
    beep();
    lcdMsg("Vote Casted", "Candidate C");
    delay(1000);
  }

  if (digitalRead(resultBtn) == LOW) {
    lcd.clear();
    lcd.print("A: ");
    lcd.print(countA);
    lcd.setCursor(0, 1);
    lcd.print("B:");
    lcd.print(countB);
    lcd.print(" C:");
    lcd.print(countC);
    delay(5000);
    lcd.clear();
  }
}

void beep() {
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
}

void lcdMsg(String line1, String line2) {
  lcd.clear();
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}
