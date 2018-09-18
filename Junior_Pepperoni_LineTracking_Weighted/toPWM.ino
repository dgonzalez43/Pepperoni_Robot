void toPWM(int y)
{
  if (y<0) // The track is on the left side, negative value
  Serial.println("y<0");
  {
    if (abs(y)<=maxSpeed) // left forward
    {
      int mappedSpeed=map((maxSpeed-abs(y)),0,255,70,255); // mapped speed always greater than max speed
      Serial.print("mappedSpeed: ");
      Serial.println(mappedSpeed);
      //Left side motor spin faster than right side motor, all motor spin forward
       digitalWrite(M1_DIR1,LOW); // Left Motor moving forward
       digitalWrite(M1_DIR2,HIGH); 
       analogWrite(M1_PWM,mappedSpeed);
       digitalWrite(M2_DIR1,LOW);
       digitalWrite(M2_DIR2,HIGH);
       analogWrite(M2_PWM,mappedSpeed);

        digitalWrite(M3_DIR1,LOW);
        digitalWrite(M3_DIR2,HIGH);
        analogWrite(M3_PWM,maxSpeed);
    //Motor 4 run forward: HIGH;
       digitalWrite(M4_DIR1,LOW);
       digitalWrite(M4_DIR2,HIGH);
       analogWrite(M4_PWM,maxSpeed);
    
      }
      if (abs(y)>=maxSpeed)
      {
        int mappedSpeed=map((abs(y)-maxSpeed),0,255,70,255);
        //Left side motor spin faster than right side motor, right motor spin backward
       digitalWrite(M1_DIR1,LOW); // Left Motor moving forward
       digitalWrite(M1_DIR2,HIGH); 
       analogWrite(M1_PWM,mappedSpeed);
       digitalWrite(M2_DIR1,LOW);
       digitalWrite(M2_DIR2,HIGH);
       analogWrite(M2_PWM,mappedSpeed);

        digitalWrite(M3_DIR1,HIGH);
        digitalWrite(M3_DIR2,LOW);
        analogWrite(M3_PWM,maxSpeed);
    //Motor 4 run forward: HIGH;
       digitalWrite(M4_DIR1,HIGH);
       digitalWrite(M4_DIR2,LOW);
       analogWrite(M4_PWM,maxSpeed);
       
        }
    }
    if (y>=0) // The line is on the right side of the robot
    Serial.println("y>0");
    {
      if (y<=maxSpeed)
      {
       digitalWrite(M1_DIR1,LOW); // Left Motor moving forward
       digitalWrite(M1_DIR2,HIGH); 
       analogWrite(M1_PWM,maxSpeed);
       digitalWrite(M2_DIR1,LOW);
       digitalWrite(M2_DIR2,HIGH);
       analogWrite(M2_PWM,maxSpeed);

       int mappedSpeed=map((maxSpeed-y),0,255,70,255);
       digitalWrite(M3_DIR1,LOW);
        digitalWrite(M3_DIR2,HIGH);
        analogWrite(M3_PWM,mappedSpeed);
    //Motor 4 run forward: HIGH;
       digitalWrite(M4_DIR1,LOW);
       digitalWrite(M4_DIR2,HIGH);
       analogWrite(M4_PWM,mappedSpeed);
        }
      if (y>maxSpeed)
      {
        digitalWrite(M1_DIR1,LOW); // Left Motor moving forward
       digitalWrite(M1_DIR2,HIGH); 
       analogWrite(M1_PWM,maxSpeed);
       digitalWrite(M2_DIR1,LOW);
       digitalWrite(M2_DIR2,HIGH);
       analogWrite(M2_PWM,maxSpeed);

        int mappedSpeed=map((y-maxSpeed),0,255,70,255);
        digitalWrite(M3_DIR1,HIGH);
        digitalWrite(M3_DIR2,LOW);
        analogWrite(M3_PWM,mappedSpeed);
    //Motor 4 run forward: HIGH;
       digitalWrite(M4_DIR1,HIGH);
       digitalWrite(M4_DIR2,LOW);
       analogWrite(M4_PWM,mappedSpeed);
      }
      }
  }
