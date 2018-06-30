


const byte LeftEncoder = 2;
const byte RigthEncoder = 3;
volatile int N_L_ticks = 0;
volatile int N_R_ticks = 0;
#define ticks_per_revolution 20
#define robot_base 13
#define wheel_radious 3
#define KP 1
#define KI 0.0001
#define KD 0.1
#define pi (22/7)
#define LeftMotor 5
#define RightMotor 6


#define velocity 255 // max for PWM


///////////////
  int x_g = 60;
  int y_g = 60;
  int w=0;
	double Dl = 0;
	double Dr = 0;
	int old_r_ticks = 0;
	int old_l_ticks = 0;
	double x_old = 0;
	double y_old = 0;
	int theta_old = 0;
	double x=0,y=0,theta=0,error=0,old_error=0,acumelator_error = 0;
	int vr,vl;
	double error_i=0,error_d=0;
	int theta_g = atan2(y_g , x_g)*180/pi;//to ensure that the angle between[-pi,pi]

///////////////


void setup()
{


  Serial.begin(9600);
  pinMode(LeftMotor,OUTPUT);
  pinMode(RightMotor,OUTPUT);
  

  
  pinMode(LeftEncoder, INPUT_PULLUP);
  pinMode(RigthEncoder, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LeftEncoder), leftEnc, FALLING);
  attachInterrupt(digitalPinToInterrupt(RigthEncoder), rigthEnc, FALLING);

}

void loop() 
{

  if ( abs(x_g - x) < 5 && abs(y_g -y) < 5 )
		{
		vl = 0;
		vr = 0;
    analogWrite(LeftMotor,0);
    analogWrite(RightMotor,0);
    delay(50000);
		}
   Serial.print("x = ");
   Serial.print(x);
   Serial.print("y = ");
   Serial.println(y);
    Dl = 2*pi*(N_L_ticks - old_l_ticks)/ticks_per_revolution; // calculation rotating distance of left wheel
	  Dr = 2*pi*(N_R_ticks - old_r_ticks)/ticks_per_revolution; // calculation rotating distance of right wheel 
	theta = theta_old + ( (Dr - Dl)/ticks_per_revolution ); 
	theta_old = theta;
	x = x_old + ( (Dl + Dr)*cos(theta)/2 );
	x_old = x;
	y = y_old + ( (Dl + Dr)*sin(theta)/2 );
	y_old = y;
	theta_g = atan2((y_g-y),(x_g-x))*180/pi;
	error = (theta_g - theta) ;///////////////////////////////////
	
	
	error_i = error + acumelator_error;
	acumelator_error = error_i;
	error_d = error - old_error;
	w = KP*error + KI*error_i + KD*error_d;
	
	old_error = error;
	
	vr = ( (2*velocity) + (w*robot_base) ) /(2*wheel_radious);
	vl = ( (2*velocity) - (w*robot_base) ) /(2*wheel_radious);

        analogWrite(LeftMotor,vl);
        analogWrite(RightMotor,vr);
delay(30);
	 
}

void rigthEnc() {
  N_R_ticks += 1;
 
}
void leftEnc() {
  N_L_ticks += 1;
  

}
