#include <Adafruit_HMC5883_U.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>
#include <Wire.h>



//pinOuts
#define turretPin 9
#define gunPin 10
#define leftTrackA 2
#define leftTrackB 3
#define leftSpeed 5
#define rightTrackA 4
#define rightTrackB 7
#define rightSpeed 6
#define homePin 2








//constants
 int maxElevation = 20;
 int minElevation = -20;





//Objects
Servo turret;
Servo gun;




//global variables
int currentAngle;



/*************************************************************************************
 * Name: M1 animation base code v1.0
 * author: @tlia
**************************************************************************************/
 void setup() {
  // put your setup code here, to run once:
  reSetGun();
  turretRotateRight();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //delay(1000);
}


//turret rotation code
void turretRotateLeft(int ms){
  turret.attach(turretPin);
  turret.write(180);
  delay(ms);
  turret.detach();
  setCurrentAngle();
}

//rotates until stop
void turretRotateLeft(){
  turret.attach(turretPin);
  turret.write(180);
}

void turretRotateRight(int ms){
  turret.attach(turretPin);
  turret.write(0);
  delay(ms);
  turret.detach();
  setCurrentAngle();
}

void turretRotateRight(){
  turret.attach(turretPin);
  turret.write(0);
}

void turretRotateStop(){
  turret.detach();
  setCurrentAngle();
}

void turretHome(){
 
}

void turretKeepAngle(){
  //keep turret facing 
}

void setCurrentAngle(){
  
}

void reSetGun(){
  gun.attach(gunPin);
  gun.write(90);
}
/** 
 * degrees: 0 = horizontal
 * pew pew!
 */
void setGunElevation(int gunDegrees){
  //elevation limits
  
  if(gunDegrees > maxElevation){
    gunDegrees = maxElevation;
  }else if(gunDegrees < minElevation){
    gunDegrees = minElevation;
  }
  gunDegrees = gunDegrees + 90;
  gun.write(gunDegrees);
}
