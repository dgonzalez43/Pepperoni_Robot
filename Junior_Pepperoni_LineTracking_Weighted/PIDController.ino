int PIDController(float error)
{
//Calculate delta t*
unsigned long now = micros();
float timeChange=(float)(now-lastTime);

//Calculation of integral
integral=integral+(Ki*error*(timeChange/1000000.0));
constrain(integral,-2*maxSpeed,2*maxSpeed);

//Calculation of derivative
float derivative=(error-lastError)/(timeChange/1000000.0);

//Compute PID Output
float y=Kp*error+integral+Kd*derivative;

//Remember some variable for the next time
lastError=error;
lastTime=now;

int output=constrain(y,-1.5*maxSpeed,1.5*maxSpeed);
Serial.print("PID output value:");
Serial.println(output);
return output;
}
