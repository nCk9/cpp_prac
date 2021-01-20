import requests
url = "https://www.metaweather.com/api/location/2295420/"
response = requests.get(url)
print(response.json().consolidated_weather)