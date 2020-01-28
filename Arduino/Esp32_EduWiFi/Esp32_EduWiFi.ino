#include <WiFi.h>
#include <esp_wpa2.h>
#include <time.h>
//#include "secrets.h" //if uncommented, make sure secrets.h is updated and lines below are ignored

#ifndef SECRETS

//Register your device using MAC address in MSetup

const char *ssid = "eduroam"; // Eduroam or MWireless
#define EAP_IDENTITY "username@umich.edu" //enter full umich email address
#define EAP_PASSWORD "umich_password"     //your umich password

const char *incommon_ca =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIF+TCCA+GgAwIBAgIQRyDQ+oVGGn4XoWQCkYRjdDANBgkqhkiG9w0BAQwFADCB\n"
    "iDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCk5ldyBKZXJzZXkxFDASBgNVBAcTC0pl\n"
    "cnNleSBDaXR5MR4wHAYDVQQKExVUaGUgVVNFUlRSVVNUIE5ldHdvcmsxLjAsBgNV\n"
    "BAMTJVVTRVJUcnVzdCBSU0EgQ2VydGlmaWNhdGlvbiBBdXRob3JpdHkwHhcNMTQx\n"
    "MDA2MDAwMDAwWhcNMjQxMDA1MjM1OTU5WjB2MQswCQYDVQQGEwJVUzELMAkGA1UE\n"
    "CBMCTUkxEjAQBgNVBAcTCUFubiBBcmJvcjESMBAGA1UEChMJSW50ZXJuZXQyMREw\n"
    "DwYDVQQLEwhJbkNvbW1vbjEfMB0GA1UEAxMWSW5Db21tb24gUlNBIFNlcnZlciBD\n"
    "QTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJwb8bsvf2MYFVFRVA+e\n"
    "xU5NEFj6MJsXKZDmMwysE1N8VJG06thum4ltuzM+j9INpun5uukNDBqeso7JcC7v\n"
    "HgV9lestjaKpTbOc5/MZNrun8XzmCB5hJ0R6lvSoNNviQsil2zfVtefkQnI/tBPP\n"
    "iwckRR6MkYNGuQmm/BijBgLsNI0yZpUn6uGX6Ns1oytW61fo8BBZ321wDGZq0GTl\n"
    "qKOYMa0dYtX6kuOaQ80tNfvZnjNbRX3EhigsZhLI2w8ZMA0/6fDqSl5AB8f2IHpT\n"
    "eIFken5FahZv9JNYyWL7KSd9oX8hzudPR9aKVuDjZvjs3YncJowZaDuNi+L7RyML\n"
    "fzcCAwEAAaOCAW4wggFqMB8GA1UdIwQYMBaAFFN5v1qqK0rPVIDh2JvAnfKyA2bL\n"
    "MB0GA1UdDgQWBBQeBaN3j2yW4luHS6a0hqxxAAznODAOBgNVHQ8BAf8EBAMCAYYw\n"
    "EgYDVR0TAQH/BAgwBgEB/wIBADAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUH\n"
    "AwIwGwYDVR0gBBQwEjAGBgRVHSAAMAgGBmeBDAECAjBQBgNVHR8ESTBHMEWgQ6BB\n"
    "hj9odHRwOi8vY3JsLnVzZXJ0cnVzdC5jb20vVVNFUlRydXN0UlNBQ2VydGlmaWNh\n"
    "dGlvbkF1dGhvcml0eS5jcmwwdgYIKwYBBQUHAQEEajBoMD8GCCsGAQUFBzAChjNo\n"
    "dHRwOi8vY3J0LnVzZXJ0cnVzdC5jb20vVVNFUlRydXN0UlNBQWRkVHJ1c3RDQS5j\n"
    "cnQwJQYIKwYBBQUHMAGGGWh0dHA6Ly9vY3NwLnVzZXJ0cnVzdC5jb20wDQYJKoZI\n"
    "hvcNAQEMBQADggIBAC0RBjjW29dYaK+qOGcXjeIT16MUJNkGE+vrkS/fT2ctyNMU\n"
    "11ZlUp5uH5gIjppIG8GLWZqjV5vbhvhZQPwZsHURKsISNrqOcooGTie3jVgU0W+0\n"
    "+Wj8mN2knCVANt69F2YrA394gbGAdJ5fOrQmL2pIhDY0jqco74fzYefbZ/VS29fR\n"
    "5jBxu4uj1P+5ZImem4Gbj1e4ZEzVBhmO55GFfBjRidj26h1oFBHZ7heDH1Bjzw72\n"
    "hipu47Gkyfr2NEx3KoCGMLCj3Btx7ASn5Ji8FoU+hCazwOU1VX55mKPU1I2250Lo\n"
    "RCASN18JyfsD5PVldJbtyrmz9gn/TKbRXTr80U2q5JhyvjhLf4lOJo/UzL5WCXED\n"
    "Smyj4jWG3R7Z8TED9xNNCxGBMXnMete+3PvzdhssvbORDwBZByogQ9xL2LUZFI/i\n"
    "eoQp0UM/L8zfP527vWjEzuDN5xwxMnhi+vCToh7J159o5ah29mP+aJnvujbXEnGa\n"
    "nrNxHzu+AGOePV8hwrGGG7hOIcPDQwkuYwzN/xT29iLp/cqf9ZhEtkGcQcIImH3b\n"
    "oJ8ifsCnSbu0GB9L06Yqh7lcyvKDTEADslIaeSEINxhO2Y1fmcYFX/Fqrrp1WnhH\n"
    "OjplXuXE0OPa0utaKC25Aplgom88L2Z8mEWcyfoB7zKOfD759AN7JKZWCYwk\n"
    "-----END CERTIFICATE-----\n";

// Obtain the latest from :
// https://documentation.its.umich.edu/content/wifi-manually-configuring-wpa2-enterprise-other-wifi-enabled-devices-unsupported-devices
// Use the "Intermediate CA" file: http://www.itcom.itd.umich.edu/downloads/wifi/incommon_ras_server_ca.cer ^^^^^^^^^^^^^^^^^^^^^^^^^^^
// NO need for "Root CA: UserTrust RSA Cerification Authority" file

/////////////// Initial State Streamer Config  //////////////////
#define bucketKey "XXXXXXXXXXXX"                         // Bucket key (hidden reference to your bucket that allows appending)
#define bucketName "YYYYYYYYY"                           // Bucket name (name your data will be associated with in Initial State)
#define accessKey "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" // Access key (the one you find in your account settings)
/////////////////////////////////////////////////////////////////

#endif

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -5 * 3600;
const int daylightOffset_sec = 3600;

uint8_t counter = 0;
unsigned long previousMillisWiFi = 0;
char timeStringBuff[50];

void printLocalTime(bool printToSerial = false)
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
  strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y %H:%M:%S", &timeinfo);
  if(printToSerial) Serial.println(timeStringBuff);
}

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  WiFi.disconnect(true); //disconnect form wifi to set new wifi connection
  WiFi.mode(WIFI_STA);   //init wifi mode
  Serial.print("MAC >> ");
  Serial.println(WiFi.macAddress());
  Serial.printf("Connecting to WiFi: %s ", ssid);
  esp_wifi_sta_wpa2_ent_set_ca_cert((uint8_t *)incommon_ca, strlen(incommon_ca) + 1);
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD));
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  esp_wifi_sta_wpa2_ent_enable(&config);
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(F("."));
    counter++;
    if (counter >= 60)
    { //after 30 seconds timeout - reset board
      ESP.restart();
    }
  }
  Serial.println(F(" connected!"));
  Serial.print(F("IP address set: "));
  Serial.println(WiFi.localIP()); //print LAN IP

  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime(true);
  
}

void loop()
{
  unsigned long currentMillis = millis();

  if (WiFi.status() == WL_CONNECTED)
  {              //if we are connected to Eduroam network
    counter = 0; //reset counter
    if (currentMillis - previousMillisWiFi >= 15 * 1000)
    {
      printLocalTime(true);
      previousMillisWiFi = currentMillis;
      Serial.print(F("Wifi is still connected with IP: "));
      Serial.println(WiFi.localIP()); //inform user about his IP address
    }
  }
  else if (WiFi.status() != WL_CONNECTED)
  { //if we lost connection, retry
    WiFi.begin(ssid);

    Serial.printf("Connecting to WiFi: %s ", ssid);
    while (WiFi.status() != WL_CONNECTED)
    { //during lost connection, print dots
      delay(500);
      Serial.print(F("."));
      counter++;
      if (counter >= 60)
      { //30 seconds timeout - reset board
        ESP.restart();
      }
    }
    Serial.println(F(" connected!"));
  }
}