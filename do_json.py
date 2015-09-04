#!/usr/bin/python
#coding:utf-8
import sys
import os
import hashlib
import json
from oss.oss_api import *
from oss.oss_xml_handler import *

file_esp8266=sys.argv[1]
ver_esp8266=sys.argv[2]
file_lgt=sys.argv[3]
ver_lgt=sys.argv[4]


f = open(sys.argv[1],'rb')
sh = hashlib.sha256()
sh.update(f.read())
sha = sh.hexdigest()
print sha
f.close()

size = os.path.getsize(sys.argv[1])
print size


f = open(file_lgt,'rb')
sh_lgt = hashlib.sha256()
sh_lgt.update(f.read())
sha_lgt = sh_lgt.hexdigest()
print sha_lgt
f.close()

size_lgt = os.path.getsize(file_lgt)
print size_lgt

#do temp.json
f=open('temp.json','r')
f_tmp=f.read()#get json_temp
f.close()

parsed_json = json.loads(f_tmp)
j= parsed_json['packages']
#WeMos WiFi Boards
j[0]['platforms'][0]['version']=ver_esp8266
j[0]['platforms'][0]['url']="https://raw.githubusercontent.com/wemos/WeMos_Boards/master/releases/"+file_esp8266
j[0]['platforms'][0]['archiveFileName']=file_esp8266
j[0]['platforms'][0]['checksum']="SHA-256:"+sha
j[0]['platforms'][0]['size']=str(size)
#WeMos LGT Boards
j[0]['platforms'][1]['version']=ver_lgt
j[0]['platforms'][1]['url']="https://raw.githubusercontent.com/wemos/WeMos_Boards/master/releases/"+file_lgt
j[0]['platforms'][1]['archiveFileName']=file_lgt
j[0]['platforms'][1]['checksum']="SHA-256:"+sha_lgt
j[0]['platforms'][1]['size']=str(size_lgt)


f = open('package_wemos.cc_index.json', 'w')
f.write(json.dumps(parsed_json))
f.close()
###


