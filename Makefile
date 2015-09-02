ver_esp8266 = 1.0.2
file_esp8266 = wemos-esp8266-$(ver_esp8266).tar.gz

ver_lgt = 1.0.0
file_lgt = wemos-lgt-$(ver_lgt).tar.gz
esp8266:
	tar -zcvf $(file_esp8266) ESP8266
lgt:
	tar -zcvf $(file_lgt) LGT

all:esp8266 lgt
	./json.py $(file_esp8266) $(ver_esp8266) $(file_lgt) $(ver_lgt)
	mv *.gz releases/
clean:
	rm -rf $(file_esp8266) $(file_lgt)
