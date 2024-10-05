#include <Arduino.h>

#include "device.h"

#include "./wifi/Ditel_Easy_WiFi.hpp"

Ditel_Easy_WiFi::Network network;  // ネットワーク設定用の構造体
Ditel_Easy_WiFi wifi;              // WiFi通信用のクラス

int x = 0;
int y = 0;

bool bldcStatus = 0;
bool pushStatus = 0;

void init_udp() {
START:
    Serial.println("aaa");
    rpc_wifi_set_power_mode(
        WIFI_PS_NONE, WIFI_PS_NONE);  // Wio Terminalの省電力モードの無効化

    // 接続先のルータについての設定
    strcpy(network.SSID, "GifuRoboken_Ateam_5G");
    strcpy(network.Password, "gifuroboken2024");
    if (wifi.connectToNetwork(network, 3000) == DWIFI_OK)
        Serial.println("接続成功");
    else {
        Serial.println("接続失敗");
        goto START;
    }

    wifi.UDP.close(1);  // 全てのUDP通信を停止

    // delay(250);

    if (wifi.UDP.begin(8890) == DWIFI_OK)  // 通信用のポート8890を開放
        Serial.println("UDP通信開始成功");
    else
        Serial.println("UDP通信開始失敗");

    // /*
    // 無くてもよい
    char myIPAdd[32];

    wifi.getMyIpAddress(myIPAdd);

    Serial.printf("My IP Address : %s\r\n", myIPAdd);

    // */
}

void setup() {
    Serial.begin(115200);
    Serial.println("[INFO] LaunchPack - Start");

    initDevice();

    init_udp();
}

void udp() {
    static bool lastForward = 1;
    String serverIpAddress = "192.168.0.110";  // サーバのIPアドレスを設定

    uint8_t sendDataToServer[66] = {0};
    uint8_t reciveDataFromServer[66] = {0};

    wifi.UDP.setServerInfo(serverIpAddress, 8890);  // サーバの情報を設定
    // ↑注：通信を行う際は毎回実行する

    sendDataToServer[0] = 0x01;  // 通信目的をデータの読み込みに設定
    sendDataToServer[1] = 0x10;  // 読み込むデータのアドレスを0x0Aに設定
    // ↑読み込むアドレスに応じて値は変える

    wifi.UDP.send(sendDataToServer, 66);

    delay(5);

    uint16_t _timeoutCount = 0;

    delay(30);

    while (_timeoutCount < 50) {
        if (wifi.UDP.avaiable() > 0)  // サーバからの返答があるかを確認
            break;

        wifi.UDP.send(sendDataToServer, 66);

        delay(10);
        _timeoutCount++;
    }

    if (_timeoutCount >= 50) {
        Serial.println("データ受信失敗(タイムアウト)");
        x = 0;
        y = 0;
        init_udp();
        delay(1);

    } else {
        Serial.print("データ受信成功");
        wifi.UDP.read(reciveDataFromServer, 66);

        for (int i = 0; i < 15; i++) {
            Serial.print(reciveDataFromServer[i], HEX);
            Serial.print(" ");
        }
        // Serial.println("");

        int deg = reciveDataFromServer[2] << 8 | reciveDataFromServer[3];
        deg += 360;
        deg %= 360;

        int speed = reciveDataFromServer[4] << 8 | reciveDataFromServer[5];
        // x = (float)0.4 * speed * sin(deg * PI / 180);
        // y = (float)0.4 * speed * cos(deg * PI / 180);

        if (deg < 45 || deg > 315) {
            x = 0;
            y = speed / 2;
            lastForward = 1;
        } else if (deg < 135) {
            if (lastForward) {
                x = speed / 3;
            } else {
                x = -speed / 3;
            }
            y = 0;
        } else if (deg < 225) {
            x = 0;
            y = -speed / 2;
        } else {
            // x = -speed / 3;
            if (lastForward) {
                x = -speed / 3;
            } else {
                x = speed / 3;
            }
            y = 0;
            lastForward = 0;
        }

        Serial.print("\tdeg: ");
        Serial.print(deg);
        Serial.print("\tspeed: ");
        Serial.print(speed);
        Serial.print("\tx: ");
        Serial.print(x);

        Serial.print("\ty:");
        Serial.println(y);

        if (reciveDataFromServer[6] == 0x00) {
            subMcu.pushBall();
        }
        bldcStatus = !reciveDataFromServer[8];
    }
}

void loop() {
    udp();

    wheelMotor[0] = y - x;
    wheelMotor[1] = y + x;

    subMcu.setBldcRotation(bldcStatus);
}