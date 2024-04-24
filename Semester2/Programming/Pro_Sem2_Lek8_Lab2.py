from pymongo.mongo_client import MongoClient
from pymongo.server_api import ServerApi
import random
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
col = db["temperature"]
col = db["humidity"]

def get_temperature():
    return randrange(20)
