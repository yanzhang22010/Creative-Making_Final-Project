#include <SoftwareSerial.h>    // Add soft serial header file（Jiaxin Liang）
SoftwareSerial mySerial(2,3);  // RX, TX （Jiaxin Liang）

#include <MsTimer2.h>
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson （Jiaxin Liang）
// Released under the GPLv3 license to match the rest of the（Jiaxin Liang）
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket（Jiaxin Liang）
#endif
#define PIN 6
#define NUMPIXELS 49
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //Adafruit NeoPixel library (Yan Zhang)


bool LED_Flag=true; 
static int Count = 10;

int PulseSensorPurplePin = 0;// Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0 (Yan Zhang)
int LED13 = 13;    // LED (Yan Zhang)
int Signal;        // holds the incoming raw data. Signal value can range from 0-1024 (Yan Zhang)         
int Threshold = 550;  // Determine which Signal to "count as a beat", and which to ingore. (Yan Zhang)         

int BeatAvg;
int Beat_Rate;
int PWM = 0;
bool Flag=true;
int Step=1;

const int TrgPin = 5; // Ultrasonic sensor  (Yuwei Fei)  
const int EcoPin = 4; // Ultrasonic sensor  (Yuwei Fei)
static int dist; 
static int Dist;
static int Average[10] = {0};
static int Average_Dist = 0;
static int Count_Dist = 0;

#include <Servo.h> //Set the Servo (Yuwei Fei)
Servo myservo; 
int Pos = 0;
bool Servo_Flag=true;
void onTimer()
{
    
    if(LED_Flag==true)
    {
        Count++;
        if(Count>=PWM)
        {
            LED_Flag = false;
        }
    }else{
        Count--;
        if(Count<=10)
        {
            LED_Flag = true;
        }    
    }

}

void Open() //Adjusting the Ultrasonic Sensor (Yuwei Fei)
{
      for (Pos = 0; Pos <= 60; Pos += 1) 
      {
          myservo.write(Pos); 
          for(int i=0; i<49; i++) 
          {
              pixels.setPixelColor(i, pixels.Color(0.2*Pos, Pos*0.02, Pos*0.62));//Pixel colors parameters (Yuwei Fei)
          }
          pixels.show();      
          delay_X(20);                    
      }
}

void Close() //Adjusting the Ultrasonic Sensor (Yuwei Fei)
{
    for (Pos = 60; Pos >= 0; Pos -= 1) 
    { 
        myservo.write(Pos);  
        for(int i=0; i<49; i++) 
        {
            pixels.setPixelColor(i, pixels.Color(0.1*Pos, Pos*0.02, Pos*0.62));//Pixel colors parameters (Yuwei Fei)
        }
        pixels.show();           
        delay_X(20);                
    }
}

void setup()
{
    Serial.begin(115200);    //Serial port baud rate setting（Jiaxin Liang）
    mySerial.begin(38400);   // Start the serial port at 38.4K （Jiaxin Liang）
    mySerial.listen();    
    mySerial.print("v");   // Set volume （Jiaxin Liang） 
    mySerial.write(255);   // 0 = maximum volume, 255 = minimum volume （Jiaxin Liang）

    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
    #endif
        pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)  (Yuwei Fei)

    pinMode(TrgPin, OUTPUT);    //Set TrgPin as output state (Yuwei Fei)
    pinMode(EcoPin, INPUT);     //Set EcoPin as input state (Yuwei Fei)
    myservo.attach(7);
    /********************Initialize timer interrupt*****************************/     
    MsTimer2::set(4, onTimer);     //Set the interrupt and enter the interrupt service routine onTimer() every 4ms (Jiaxin Liang)
    MsTimer2::start();             //Start timing_Start the timer (Jiaxin Liang)
}

void loop()
{
    //Get heart rate value (Yuwei Fei)
    Beat_Rate=Beat_Runnig();
    Serial.print("Avg BPM=");
    Serial.println(Beat_Rate);
    //Get Ultrasonic Values (Yuwei Fei)
    digitalWrite(TrgPin, LOW);
    delayMicroseconds(8);
    digitalWrite(TrgPin, HIGH);// Maintain a high level for 10 milliseconds to generate a pulse(Yuwei Fei)
    delayMicroseconds(10);
    digitalWrite(TrgPin, LOW); // Read the width of the pulse and convert it to distance(Yuwei Fei)
    dist = pulseIn(EcoPin, HIGH)/58.00;
    
    if (dist<=200)            //Filtering processing (Yuwei Fei)
    {
        if (dist<=200)       //Filtering processing (Yuwei Fei)
        {
            Dist =dist;
        }
    }
    else if (dist>200)        //Filtering processing (Yuwei Fei)
    {
        if (dist>200)         //Filtering processing (Yuwei Fei)
        {
        Dist =Dist;
        }
    } 
    if(Count_Dist<10)
    {
        Average[Count_Dist++] = Dist;
    }
    else if(Count_Dist>=10)
    {       
        Average_Dist = Filter(Average,(sizeof(Average) / sizeof(Average[0])));
        Count_Dist=0;  
    }
    //Serial.print("Distance:");(Yuwei Fei)
    //Serial.print(Average_Dist);(Yuwei Fei)
    //Serial.println("cm"); (Yuwei Fei)
    if(Average_Dist<40 && Servo_Flag==true && Step==2) //Ultrasonic control steering gear (Yuwei Fei)
    {
        Play_Music(1);      //Play music1（Jiaxin Liang）
        Open();
        Servo_Flag=false;
    }
    if(Average_Dist>=40 && Servo_Flag==false && Step==2)//Ultrasonic control steering gear (Yuwei Fei)
    {
        Play_Music(2);      //Play music2 （Jiaxin Liang）
        Close();
        Servo_Flag=true;
    }


    if(Beat_Rate>0)
    {
        if(Step==1)   //First press the heart rate to start, and the light strip gradually lights up (Yan Zhang) 
        {
            for(int Light=0; Light<255; Light++)
            {
                for(int i=0; i<49; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(Light*0.52, Light*0.02, Light*0.82));//Pixel colors parameters  (Yan Zhang) 
                }
                pixels.show(); 
                delay_X(20);
            } 
            Step=2;
        }
        /*******************heart rate controlled breathing**********************/
        if(Step==2)
        {
            if(Beat_Rate<=20 && Flag==false)                 //Exception range, fast (Yan Zhang) 
            {
                PWM = 100;
                LED_ALL(Count);
            }
            if(Beat_Rate>=100 && Flag==false)                 //Exception range, fast (Yan Zhang) 
            {
                PWM = 150;
                LED_ALL(Count);
            }
            if(Beat_Rate>20 && Beat_Rate<80 && Flag==false)    //Abnormal + normal range, fast in the front and normal in the back (Yan Zhang) 
            {
                PWM = map(Beat_Rate,20,100,100,255);
                LED_ALL(Count);
            }  
            if(Beat_Rate>=80 && Beat_Rate<100 && Flag==false)  //Exception range, fast (Yan Zhang) 
            {
                PWM = map(Beat_Rate,80,100,255,150);
                LED_ALL(Count);
            }
        }  
    }else{
        LED_ALL(0);
        Count=10;
    }
    
}



int Beat_Runnig()
{
    int Signal = analogRead(PulseSensorPurplePin); 
  if(Signal<550)
  {
    BeatAvg=0;
  }
  else if(Signal>700)
  {
    BeatAvg=100;
  }else{
    BeatAvg=map(Signal,550,700,0,100);
  }
    return BeatAvg;
}

void delay_X(int X)
{
  delay(20);
}


void LED_ALL(int Light) 
{
    for(int i=0; i<49; i++) 
    {
        pixels.setPixelColor(i, pixels.Color(Light*0.2, Light*0.02, Light*0.82));//Pixel colors parameters (Yan Zhang) 
    }
    pixels.show();   // Send the updated pixel colors to the hardware.(Yan Zhang) 
}



int Filter(int *Buf,int length)
{
    int filter_sum = 0;
    for(int i = 0; i < length; i++) 
    {
        filter_sum +=Buf[i];
    }
    return (int)(filter_sum / length);
}

/* ****************************************************
--->Definition name:  Filter(uint16_t *Buf,uint16_t length)
--->Define function:中位值
--->Input:  dist  
--->Outout:  Dist 
--->(Yuwei Fei)
*******************************************************/

void Play_Music(int Song)   //1-Play 2-Stop（Jiaxin Liang）
{
    mySerial.print("p"); 
    mySerial.write(Song); 
}
