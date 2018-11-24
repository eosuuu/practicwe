# -*- coding: utf-8 -*-
from urllib.request import urlopen, Request
import urllib
import bs4

location = '제주'
enc_location = urllib.parse.quote(location + '+날씨')

url = 'https://search.naver.com/search.naver?ie=utf8&query='+ enc_location


req = urllib.request.Request(url, headers={'User-Agent': 'Mozilla/5.0'})
#req = Request(url)
page = urlopen(req)
html = page.read()
soup = bs4.BeautifulSoup(html,'html5lib')
temperature = soup.find('p', class_='info_temperature').find('span', class_='todaytemp').text
weather = soup.find('ul', class_='info_list').find('p', class_='cast_txt').text
weather = weather.split(',')
# print(weather[0])
# weather_list = list(weather)
# weather_list = weather_list.split(',')
# print(weather_list)
#
# print(weather)
print('현재' + location + '날씨:' + temperature + '도' + weather[0])
