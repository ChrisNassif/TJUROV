import requests
import time

# HOW TO USE:
# 1. Start the ESP32 script
# 2. Connect to ESP32's wifi signal through the ground station
# 3. Get the ESP32's IP Address and write it down in ESP32_IPADDRESS
# 4. (optional) Make sure you can access the ESP32's signal by typing in [ESP32_IPADDRESS]/UTC_Time into google
# 5. Run this script
 
ESP32_IPADDRESS = "192.168.1.184"

def main():

    while True:
        # I am pretty sure that it needs the https out front but not certain
        result = requests.get(f'https://{ESP32_IPADDRESS}/UTC_Time')
        print(result)
        time.sleep(500)

if __name__ == "__main__": main()
    