import serial
import requests
import socket

url = "https://us-central1-tempsense-b3bc5.cloudfunctions.net/addTemp"

def test_internet():
    try:
        socket.create_connection(('Google.com', 80))
        return True
    except OSError:
        return False


if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
    ser.flush()
    while True:        
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            if float(line) >= 95:
                if test_internet():
                    reading = {'temp' : line}
                    r = requests.post(url, data = reading)
                    print(r.text)
                    ser.write(b"sent\n")
                    print("Sent")
                else:
                    ser.write(b"sent_offline\n")
                    print("Saved offline")
            
                
