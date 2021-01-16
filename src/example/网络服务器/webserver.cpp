// #include <Arduino.h>

// /**********************************************************************
//  * 按flash键读取 D3
//  * http://www.taichi-maker.com/homepage/-nodemcu-iot/iot-c/-nodemcu-web-server/pin-state/
// 项目名称/Project          : 零基础入门学用物联网
// 程序名称/Program name     : 3_2_3_Pin_State_Display
// 团队/Team                : 太极创客团队 / Taichi-Maker (www.taichi-maker.com)
// 作者/Author              : CYNO朔
// 日期/Date（YYYYMMDD）     : 20191107
// 程序目的/Purpose          : 使用NodeMCU建立基本服务器。该页面将会自动刷新并且显示NodeMCU
//                            的D3引脚状态。NodeMCU开发板上的FLASH按键可以控制D3引脚的电平。
//                            没有按下该按键时D3引脚将会保持高电平状态。当按下该按键后，
//                            D3引脚会变为低电平。
// -----------------------------------------------------------------------
// 修订历史/Revision History  
// 日期/Date    作者/Author      参考号/Ref    修订说明/Revision Description
// ***********************************************************************/
 
// #include <WiFi.h>        // 本程序使用 WiFi库
// #include <WiFiMulti.h>   //  WiFiMulti库
// #include <WebServer.h>   //  WebServer库
 
// #define buttonPin 0            // flash按钮
 
// WiFiMulti wifiMulti;     // 建立WiFiMulti对象,对象名称是'wifiMulti'
 
// WebServer _server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
 
// bool pinState;  // 存储引脚状态用变量

// /*
// 建立用于发送给客户端浏览器的HTML代码。此代码将会每隔5秒刷新页面。
// 通过页面刷新，引脚的最新状态也会显示于页面中
// */
// String sendHTML(bool buttonState){
  
//   String htmlCode = "<!DOCTYPE html> <html>\n";
//   htmlCode +="<head><meta http-equiv='refresh' content='5'/>\n";
//   htmlCode +="<title>ESP8266 Butoon State</title>\n";
//   htmlCode +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
//   htmlCode +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
//   htmlCode +="</style>\n";
//   htmlCode +="</head>\n";
//   htmlCode +="<body>\n";
//   htmlCode +="<h1>ESP8266 BUTTON STATE</h1>\n";
  
//   if(buttonState)
//     {htmlCode +="<p>Button Status: HIGH</p>\n";}
//   else
//     {htmlCode +="<p>Button Status: LOW</p>\n";}
    
//   htmlCode +="</body>\n";
//   htmlCode +="</html>\n";
  
//   return htmlCode;
// }

// /* 以下函数处理网站首页的访问请求。此函数为本示例程序重点1
// 详细讲解请参见太极创客网站《零基础入门学用物联网》
// 第3章-第2节“通过网络服务将开发板引脚状态显示在网页中”的说明讲解。*/    
// void handleRoot() {   //处理网站目录“/”的访问请求 
//   _server.send(200, "text/html", sendHTML(pinState));  
// }
 

 
// // 设置处理404情况的函数'handleNotFound'
// void handleNotFound(){                                        // 当浏览器请求的网络资源无法在服务器找到时，
//   _server.send(404, "text/plain", "404: Not found");   // NodeMCU将调用此函数。
// }
 
// void setup(){
//   Serial.begin(9600);   // 启动串口通讯
//   pinMode(buttonPin, INPUT_PULLUP); // 将按键引脚设置为输入上拉模式
 
  
// //   //通过addAp函数存储  WiFi名称       WiFi密码
// wifiMulti.addAP("TP-LINK_yangyi", "acwkxq9k");  // 这三条语句通过调用函数addAP来记录3个不同的WiFi网络信息。
// wifiMulti.addAP("TP-LINK_yangyi_5G", "acwkxq9k"); // 这3个WiFi网络名称分别是taichi-maker, taichi-maker2, taichi-maker3。
   
//   Serial.println("Connecting ...");                            // 则尝试使用此处存储的密码进行连接。
  
//   int i = 0;                                 
//   while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
//     delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
//     Serial.print(i++); Serial.print(' ');    // 将会连接信号最强的那一个WiFi信号。
//   }                                          // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
//                                              // 此处while循环判断是否跳出循环的条件。
//   // WiFi连接成功后将通过串口监视器输出连接成功信息 
//   Serial.println('\n');                     // WiFi连接成功后
//   Serial.print("Connected to ");            // NodeMCU将通过串口监视器输出。
//   Serial.println(WiFi.SSID());              // 连接的WiFI名称
//   Serial.print("IP address:\t");            // 以及
//   Serial.println(WiFi.localIP());           // NodeMCU的IP地址
  
//   _server.begin();                   // 启动网站服务                
//   _server.on("/", handleRoot);       // 设置服务器根目录即'/'的函数'handleRoot'
//   _server.onNotFound(handleNotFound);// 设置处理404情况的函数'handleNotFound'        
 
//   Serial.println("HTTP _server started");//  告知用户网络服务功能已经启动
// }
 
// void loop(){
//   _server.handleClient();     // 处理http服务器访问
//   pinState = digitalRead(buttonPin); // 获取引脚状态
// }
 
