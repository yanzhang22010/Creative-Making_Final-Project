# Creative-Making_Final-Project
22/23 Creative Making: Advanced Physical Computing_Final Project

## Week4
第一周我们开会选择项目主题,我们每个人在开会前都各自想了几个主题,最后在多个主题中最终选择了我家中即将枯萎的花作为项目的主题.我们决定一起创造一种不会死亡的机械植物来代替传统植物.然后进行调研搜索了一些植物和机械组合的例子.we imagined all kinds of possibilities for its future, such as having heartbeat, play with me, feeling the environment.
<img width="633" alt="截屏2022-12-09 下午1 46 37" src="https://user-images.githubusercontent.com/119860662/206747283-08d4ff65-c52f-4337-8361-3f2e163ac4e4.png">


We plan to have input : heart rate sensor; Infrared sensor; pressure; distencer;  sound;
out put : LED; Sound; motor; servoo motor.
The plant can burst into color with just a touch of the heart rate sensor. light will change with your heart rate. Its petals will open and light up,  dancing. And play some sound.
<img width="772" alt="截屏2022-12-09 下午2 58 43" src="https://user-images.githubusercontent.com/119860662/206730458-be62f44d-8112-47f4-ae6b-b454709cf03f.png">

<img width="776" alt="截屏2022-12-09 下午2 56 39" src="https://user-images.githubusercontent.com/119860662/206730034-5c9bd2d7-c4ea-47f3-9b49-ae3c6d719ebf.png">

## Week5
第二周我与梁佳欣一起买材料,制作简单的模型进行测试.我们用铁丝制作了demo.制作demo的过程非常困难,第一次我们只用铁丝缠绕固定花的造型,但是会影响花瓣的开合.之后我们分别尝试了铁丝,rubber band和铜管.最终选择用铜管与铜丝制作花的主体.
![IMG_3195](https://user-images.githubusercontent.com/119860662/206733818-e1a95679-6c9b-4950-b029-dc6803330fe1.jpg)


## Week6
我们一起去商店购买了铜丝与铜管,我们测试了0.8mm的铜丝和1.5mm的铜管,1mm的铜丝和2mm的铜管,1.5mm的铜丝和2.5mm的铜管.最终选择了1mm和2mm,1.5mm和2.5mm的两个尺寸.
#### 困难:
实际制作的时候遇到了非常多的困难,首先铜管很容易变形,如何能够在不影响铜管形状的同时切割铜管成为了第一个难题,经过多种尝试最终我们选择了用锯子切割.
![IMG_3198](https://user-images.githubusercontent.com/119860662/206733836-3b87afde-1356-4eb0-94f8-1843fd18a39b.jpg)

第二个问题就是铜管很光滑所以非常难焊接,经过我们花了很长时间才将铜管与铁丝焊接完成.
![IMG_3199](https://user-images.githubusercontent.com/119860662/206736589-76886eab-a26e-48cd-b152-6ad3ff025cf3.jpg)
非常困难的焊接过程
![IMG_2857](https://user-images.githubusercontent.com/119860662/206741434-fe647a7d-9670-485d-822a-a64b8e4f7fc1.JPG)


## Week7
我们将花的骨架做完了开始制作花瓣,我选择了用中国传统的烫花技术制作花瓣.我用胶水与水混合洗欧根纱,使欧根纱在保持透明与轻盈的同时变的容易塑形.在组员将花瓣剪裁与染色好之后我用蜡烛加热勺子做出花瓣的褶皱造型.最后和组员一起将花瓣粘在花上,并进行修剪.
![IMG_3452](https://user-images.githubusercontent.com/119860662/206739189-639e8d62-b1ff-4035-a2b3-96dacdfbf4d7.jpg)
最终花制作完成.
![IMG_3207](https://user-images.githubusercontent.com/119860662/206739715-04fa48d9-1ba5-4afc-87fc-118ac1674df5.jpg)


## Week8
我用了心率传感器的代码并进行了调试.
进过测试我在PulseSensor和max30102 heart-ratesensor中选择了PulseSensor.

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
这一周我们开始了最终的制作.
首先我焊接电路板,灯带与电线.
![IMG_0142](https://user-images.githubusercontent.com/119860662/206747607-1f5c4d84-22b1-4ce3-8b04-93465e977242.JPG)

然后将所有元件粘贴在花瓶中.
![IMG_3352](https://user-images.githubusercontent.com/119860662/206746014-60c80480-5e1d-4185-a56d-c6cf936365db.jpg)

最后进行视频拍摄.

<img width="645" alt="截屏2022-12-09 下午4 30 19" src="https://user-images.githubusercontent.com/119860662/206747939-dd4f997f-1448-4940-8272-b88c11dff945.png">




