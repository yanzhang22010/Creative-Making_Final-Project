# Creative-Making_Final-Project
22/23 Creative Making: Advanced Physical Computing_Final Project_22010384-YanZhang

## Week4
The first week we had a meeting to choose a project theme. Each of us thought of a few themes before the meeting, and finally we chose the withering flowers in my home as the theme of the project. We decided to work together to create a mechanical plant that wouldn't die, instead of a traditional plant. 

<img width="1000" alt="截屏2022-12-09 下午1 46 37" src="https://user-images.githubusercontent.com/119860662/206747283-08d4ff65-c52f-4337-8361-3f2e163ac4e4.png">

Then I did some research and searched for some examples of plant and machine combinations.we imagined all kinds of possibilities for its future, such as having heartbeat, play with me, feeling the environment.

<img width="1000" alt="截屏2022-12-09 下午2 58 43" src="https://user-images.githubusercontent.com/119860662/206730458-be62f44d-8112-47f4-ae6b-b454709cf03f.png">

We plan to have input : heart rate sensor; Infrared sensor; pressure; distencer;  sound;
out put : LED; Sound; motor; servoo motor.
The plant can burst into color with just a touch of the heart rate sensor. light will change with your heart rate. Its petals will open and light up,  dancing. And play some sound.

<img width="1000" alt="截屏2022-12-09 下午2 56 39" src="https://user-images.githubusercontent.com/119860662/206730034-5c9bd2d7-c4ea-47f3-9b49-ae3c6d719ebf.png">


## Week5
The next week I bought materials with Liang Jiaxin and made simple models to test. We made a demo out of wire. The process of making the demo was very difficult. For the first time, we only used wire winding to fix the shape of the flower, but it would affect the opening and closing of the petals. Then we tried wire, rubber band and copper pipe. Finally, we choose to use copper tube and copper wire to make the main body of flowers.

![IMG_3195](https://user-images.githubusercontent.com/119860662/206733818-e1a95679-6c9b-4950-b029-dc6803330fe1.jpg)


## Week6
We bought copper wire and pipes together and made flower skeletons. We have tested 0.8 mm copper wire and 1.5 mm copper tube, 1mm copper wire and 2mm copper tube, 1.5 mm copper wire and 2.5 mm copper tube. Finally, the sizes of 1mm and 2mm, 1.5 mm and 2.5 mm were selected. Then we cut and weld the material.
#### There are some difficulties
There are many difficulties in actual manufacture. Firstly, the copper pipe is easy to be deformed. How to cut the copper pipe without affecting the shape of the copper pipe becomes the first problem, after many attempts we finally chose to cut with a saw.

![IMG_3198](https://user-images.githubusercontent.com/119860662/206733836-3b87afde-1356-4eb0-94f8-1843fd18a39b.jpg)

The second problem is that the copper pipe is very smooth so it is very difficult to weld. It took us a long time to weld the copper pipe with the iron wire.

![IMG_3199](https://user-images.githubusercontent.com/119860662/206736589-76886eab-a26e-48cd-b152-6ad3ff025cf3.jpg)

Very difficult welding process. We all hurt our hands in the process.

![IMG_2857](https://user-images.githubusercontent.com/119860662/206741434-fe647a7d-9670-485d-822a-a64b8e4f7fc1.JPG)

Finally the flower skeleton is finished.

![IMG_2922 2](https://user-images.githubusercontent.com/119860662/206750429-83bdd15f-d878-4485-9e21-d95a1017be0e.jpg)


## Week7
This week I first spent a lot of time repairing the welding part of the flower frame, then I started to make the petals, I chose to use the traditional Chinese hot stamping technology to make the petals. I wash the organza with glue and water to make it easy to shape while keeping it transparent and light. After the team had cut and dyed the petals, I heated the spoon with a candle to create a crease in the petals. Finally, stick the petals on the flowers with the team and trim them.

![IMG_3452](https://user-images.githubusercontent.com/119860662/206739189-639e8d62-b1ff-4035-a2b3-96dacdfbf4d7.jpg)

We finished making the flowers.

![IMG_3207](https://user-images.githubusercontent.com/119860662/206739715-04fa48d9-1ba5-4afc-87fc-118ac1674df5.jpg)


## Week8
I wrote the code for the heart rate sensor and I debugged it.

#### There are some difficulties in this week.
I first used the MAX30102 heart-ratesensor from Amazon, but couldn't use it. After testing, I found that the sensor was not in good contact because of welding. In order to ensure the completion and stability of the work, i chose PulseSensor over MAX30102 heart-ratesensor.

```
//  Variables
int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED
int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore.
// The SetUp Function:
void setup() {
  pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(9600);         // Set's up Serial Communication at certain speed.
}
// The Main Loop Function
void loop() {
  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.
   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.
   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED13,HIGH);
   } else {
     digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }
delay(10);
```

![IMG_8908](https://user-images.githubusercontent.com/119860662/206742530-82b1c055-8480-468b-9f21-e8fe11699c49.jpg)


## Week9
This week we started the final production.
First I soldered the circuit board, the lamp belt and the wire.

![IMG_0142](https://user-images.githubusercontent.com/119860662/206747607-1f5c4d84-22b1-4ce3-8b04-93465e977242.JPG)

Then paste all the components into the vase.

<img width="700" alt="截屏2022下午1 46 37" src="https://user-images.githubusercontent.com/119860662/206746014-60c80480-5e1d-4185-a56d-c6cf936365db.jpg">



Finally,We took the flowers home and put them together, and I shot the video, and it turned out really well.

![IMG_3456](https://user-images.githubusercontent.com/119860662/206752452-9e3e4fda-79f9-4ba6-a633-2d014748ca1e.jpg)

The final shot

![IMG_012](https://user-images.githubusercontent.com/119860662/206747939-dd4f997f-1448-4940-8272-b88c11dff945.png)





