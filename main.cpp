#include <string>
#include <cstring>
#include <iostream>
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcUserApiStruct.h"

class CTPTradingSPI : public CThostFtdcTraderSpi
{
public:
    void OnFrontConnected() override
    {
        std::cout << "OnFrontConnected" << std::endl;
    }

    void OnFrontDisconnected(int nReason) override
    {
        std::cout << "OnFrontDisconnected";
        std::cout << nReason;
    }
};

int RequestAuth(CThostFtdcTraderApi *traderApi)
{
    CThostFtdcReqAuthenticateField authField;
    memset(&authField, 0, sizeof(authField));
    strcpy(authField.BrokerID, "6666");
    strcpy(authField.UserID, "66810051");
    strcpy(authField.AppID, "client_cets_1.1.0");
    strcpy(authField.AuthCode, "N6REHP09452J3M3L");
    return traderApi->ReqAuthenticate(&authField, 0);
}

int main()
{
    CThostFtdcTraderApi *traderApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./flow/");
    CTPTradingSPI *traderSpi = new CTPTradingSPI();
    traderApi->RegisterSpi(traderSpi);

    std::string front_ip_str = "tcp://180.166.103.34:51215";
    const int length = front_ip_str.length();
    char *front_ip = new char[length + 1];
    strcpy(front_ip, front_ip_str.c_str());

    traderApi->RegisterFront(front_ip);
    traderApi->Init();

    const int result = RequestAuth(traderApi);
    std::cout << result;

    traderApi->Release();

    return 0;
}