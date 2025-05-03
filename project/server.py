from flask import Flask, jsonify, send_from_directory
from flask_cors import CORS
import random # Simulate random BPM data (Fake data for testing)
import serial
import time
import string


app = Flask(__name__, static_folder='static_website') # Create a Flask app
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
    
    ser = serial.Serial('/dev/cu.usbserial-0001', 115200, timeout=1)
    time.sleep(2)
    bpm = 0
    try:
        line = ser.readline().decode('utf-8', errors='ignore').strip()
        print(line)
        bpm = line.strip(string.ascii_letters)
    except KeyboardInterrupt:
        print("Exiting...")
    finally:
        if ser.is_open:
            ser.close()
    return jsonify({'bpm': bpm})

if __name__ == '__main__':
    app.run(debug=True, port=5000, host='localhost')