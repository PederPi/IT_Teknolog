from pymongo.mongo_client import MongoClient
from pymongo.server_api import ServerApi
from random import random
import threading
import time

uri = "mongodb+srv://admin:Kode1234!@cluster0.88pdw6d.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

# Create a new client and connect to the server
client = MongoClient(uri, server_api=ServerApi('1'))

# Send a ping to confirm a successful connection
try:
    client.admin.command('ping')
    print("Pinged your deployment. You successfully connected to MongoDB!")
except Exception as e:
    print(e)

#Database name:
db = client["weather_data"]

#Collection name:
col = db["weather_data"]

def get_temperature():
    return random() * 20

def get_humidity():
    return random() * 100

def get_time():
    return time()

def timing_function():
    thread = threading.Timer(60.0, upload_data)
    thread.start()
    upload_data()
    return

def upload_data():
    weather_data = ["time": get_time()]
    return

##################################################################################################
#       Main        
##################################################################################################
while(1):
    timing_function()