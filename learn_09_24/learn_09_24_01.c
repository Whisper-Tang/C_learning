#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "http://10.255.0.19/drcom/login"

int main() {
    CURL* curl;
    CURLcode res;

    // ��¼��Ϣ
    char* username = "2021300027@unicom";
    char* password = "APTX-4869";
    char* callback = "dr1003";
    char* r1 = "0";
    char* r3 = "0";
    char* r6 = "0";
    char* para = "00";
    char* v = "2172";

    // ������������� URL
    char post_data[512];
    snprintf(post_data, sizeof(post_data),
        "callback=%s&DDDDD=%s&upass=%s&0MKKey=123456&R1=%s&R3=%s&R6=%s&para=%s&v6ip=&v=%s",
        callback, username, password, r1, r3, r6, para, v);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

        // ���ͷ����Ϣ
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // ִ������
        res = curl_easy_perform(curl);

        // ��������Ƿ�ɹ�
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // ����
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}