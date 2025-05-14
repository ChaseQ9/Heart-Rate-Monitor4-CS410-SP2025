# Program: server.py
# Purpose: To create a Flask server that serves a static website and provides an API endpoint to retrieve heart rate data (BPM).

from flask import Flask, jsonify, send_from_directory
from flask_cors import CORS
import random # Simulate random BPM data (Fake data for testing)
import serial
import time
import string


app = Flask(__name__, static_folder='static_website') # Create a Flask app
# CORS is for Cross-Origin Resource Sharing. We were getting issues related to this because our live server and this program 
# were running on two different "localhosts". 127.0.0.1 and localhost. 
CORS(app, supports_credentials=True)

# Serve index.html from /static_website
@app.route('/') # Serve the website
def serve_index():
    return send_from_directory(app.static_folder, 'index.html')

# Function name: get_bpm()
# Purpose: To simulate the retrieval of heart rate data (BPM) from a device or database.
@app.route('/bpm') # Serve the BPM data
def get_bpm(test=False): 
    
    test = False
    if (test):
        bpm = random.randint(60, 100)
        return jsonify({'bpm': bpm})
    
    # Connection to the specific port that the esp32 is on
    # This section (the port) may need to be configured for the users computer
    # For our usage, we used the below port on a M3 Macbook Pro 
    ser = serial.Serial('/dev/cu.usbserial-0001', 115200, timeout=1)
    time.sleep(2)
    bpm = 0
    try: 
        # Attempt to try to read the data through the esp32 connection
        line = ser.readline().decode('utf-8', errors='ignore').strip()
        print(line)
        # We are only interested in the numbers from the esp32 so strip out the ascii characters
        bpm = line.strip(string.ascii_letters)
    except KeyboardInterrupt:
        print("Exiting...")
    finally:
        if ser.is_open:
            ser.close()
    # return the bpm we calculated in a JSON format 
    return jsonify({'bpm': bpm})

if __name__ == '__main__':
    app.run(debug=True, port=5000, host='127.0.0.1')