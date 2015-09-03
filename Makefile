ver_esp8266 = 1.0.2
file_esp8266 = wemos-esp8266-$(ver_esp8266).tar.gz

ver_lgt = 1.0.0
file_lgt = wemos-lgt-$(ver_lgt).tar.gz
.PHONY: all esp8266 lgt clean
esp8266:
	tar -zcvf $(file_esp8266) ESP8266
	#7za.exe a -ttar -so wemos-esp8266-$(ver_esp8266) ESP8266/ | 7za.exe a -tgzip -si $(file_esp8266)
lgt:
	tar -zcvf $(file_lgt) LGT

all:gzesp8266 gzlgt
	python json.py $(file_esp8266) $(ver_esp8266) $(file_lgt) $(ver_lgt)
	mv *.gz releases/
clean:
	rm -rf $(file_esp8266) $(file_lgt)
