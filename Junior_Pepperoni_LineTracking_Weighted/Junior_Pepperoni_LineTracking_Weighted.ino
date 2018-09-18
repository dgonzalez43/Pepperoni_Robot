//*************************************************************
//*****   PEPPERONI CONTROLLER                            *****
//*****   Vincent Nguyen                                  *****
//*****   Daniel A. Gonzalez                              *****
//*****   Tamucc-Fall 2018                              *****
//*************************************************************

float Kp=1,Ki=0,Kd=0; // Change this value to see the result try jp =0.1 Kd =4
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int sensorValues[8];
int normalizedValues[8];
int white[8]={};
int black[8]={};
int sensorPins[]={A0,A1,A2,A3,A4,A5,A6,A7}; 
unsigned long lastTime;
float integral,lastError;
int maxSpeed=70; // For the PWM output

//Motors Pin set up:
int M1_PWM=4, M1_DIR1=34,M1_DIR2=36; //PIN set up for Motor 1: Top Left
int M2_PWM=5, M2_DIR1=30,M2_DIR2=32; //PIN set up for Motor 2: Bot Left
int M3_PWM=3, M3_DIR1=26,M3_DIR2=28; //PIN set up for Motor 3: Top Right
int M4_PWM=2, M4_DIR1=24,M4_DIR2=22; //PIN set up for Motor 4: Bot Right
  
  
void setup()
{
  Serial.begin(115200);
 // For Motor 1 (Top Left)
 pinMode(M1_PWM,OUTPUT); //PWM Pin
 pinMode(M1_DIR1,OUTPUT);
 pinMode(M1_DIR2,OUTPUT);
//
// // For Motor 2 (Bottom Left)
 pinMode(M2_PWM,OUTPUT); //PWM PIN 5
 pinMode(M2_DIR1,OUTPUT); 
 pinMode(M2_DIR2,OUTPUT);
 
// // For Motor 3 (Top Right)
 pinMode(M3_PWM,OUTPUT); //PWM PIN 3
 pinMode(M3_DIR1,OUTPUT); 
 pinMode(M3_DIR2,OUTPUT);
//
// // For Motor 4 (Bot Right)
 pinMode(M4_PWM,OUTPUT); //PWM PIN 2
 pinMode(M4_DIR1,OUTPUT);
 pinMode(M4_DIR2,OUTPUT); 
delay(3000);
}

void loop()
{
float error;
int output=0;
readSensors();
normalizeSensors();
error=calculateError();
output=PIDController(error);
toPWM(output);
delay(500);
  // printValues();
}
