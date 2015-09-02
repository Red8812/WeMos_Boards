#!/usr/bin/python
#coding:utf-8
import sys
import os
import hashlib

text1= '''{
  "packages": [ {
    "name":"wemos",
    "maintainer":"wemos.cc",
    "websiteURL":"http://wemos.cc",
    "email":"support@wemos.cc",
    "help":{
      "online":"http://wemos.cc"
    },

    "platforms": [ {
      "name":"WeMos WiFi Boards",
      "architecture":"esp8266",
      "version":"'''
text2= '''",
      "category":"wemos",
      "url":"http://www.wemos.cc/tools/'''
text3= '''",
      "archiveFileName":"'''

text4='''",
      "checksum":"SHA-256:'''
text5='''",
      "size":"'''
text6='''",
      "help":{
        "online":"http://wemos.cc"
      },
      "boards":[
        {
          "name":"WeMos D1"
        },
        {
          "name":"lolin(nodemcu V3)"
        }
      ],
      "toolsDependencies":[ {
        "packager":"wemos",
        "name":"esptool",
        "version":"0.4.5"
      },
      {
        "packager":"wemos",
        "name":"xtensa-lx106-elf-gcc",
        "version":"1.20.0-26-gb404fb9"
      } ]
    } ],

    "tools": [ {
      "name":"esptool",
      "version":"0.4.5",
      "systems": [
        {
            "host":"i686-mingw32",
            "url":"http://www.wemos.cc/tools/esptool/esptool-0.4.5-win32.zip",
            "archiveFileName":"esptool-0.4.5-win32.zip",
            "checksum":"SHA-256:1b0a7d254e74942d820a09281aa5dc2af1c8314ae5ee1a5abb0653d0580e531b",
            "size":"17408"
        },
        {
            "host":"x86_64-apple-darwin",
            "url":"http://www.wemos.cc/tools/esptool/esptool-0.4.5-osx.tar.gz",
            "archiveFileName":"esptool-0.4.5-osx.tar.gz",
            "checksum":"SHA-256:924d31c64f4bb9f748e70806dafbabb15e5eb80afcdde33715f3ec884be1652d",
            "size":"11359"
        },
        {
            "host":"i386-apple-darwin",
            "url":"http://www.wemos.cc/tools/esptool/esptool-0.4.5-1-gfaa5794-osx.tar.gz",
            "archiveFileName":"esptool-0.4.5-1-gfaa5794-osx.tar.gz",
            "checksum":"SHA-256:722142071f6cf4d8c02dea42497a747e06abf583d86137a6a256b7db71dc61f6",
            "size":"20751"
        },
        {
            "host":"x86_64-pc-linux-gnu",
            "url":"http://www.wemos.cc/tools/esptool/esptool-0.4.5-linux64.tar.gz",
            "archiveFileName":"esptool-0.4.5-linux64.tar.gz",
            "checksum":"SHA-256:4ce799e13fbd89f8a8f08a08db77dc3b1362c4486306fe1b3801dee80cfa3203",
            "size":"12789"
        },
        {
            "host":"i686-pc-linux-gnu",
            "url":"http://www.wemos.cc/tools/esptool/esptool-0.4.5-linux32.tar.gz",
            "archiveFileName":"esptool-0.4.5-linux32.tar.gz",
            "checksum":"SHA-256:4aa81b97a470641771cf371e5d470ac92d3b177adbe8263c4aae66e607b67755",
            "size":"12044"
        }
      ]
    },
    {
      "name":"xtensa-lx106-elf-gcc",
      "version":"1.20.0-26-gb404fb9",
      "systems": [
        {
           "host":"i686-mingw32",
           "url":"http://www.wemos.cc/tools/gcc/win32-xtensa-lx106-elf-gb404fb9.tar.gz",
           "archiveFileName":"win32-xtensa-lx106-elf-gb404fb9.tar.gz",
           "checksum":"SHA-256:1561ec85cc58cab35cc48bfdb0d0087809f89c043112a2c36b54251a13bf781f",
           "size":"153807368"
        },
        {
           "host":"x86_64-apple-darwin",
           "url":"http://www.wemos.cc/tools/gcc/osx-xtensa-lx106-elf-gb404fb9-2.tar.gz",
           "archiveFileName":"osx-xtensa-lx106-elf-gb404fb9-2.tar.gz",
           "checksum":"SHA-256:0cf150193997bd1355e0f49d3d49711730035257bc1aee1eaaad619e56b9e4e6",
           "size":"35385382"
        },
        {
           "host":"i386-apple-darwin",
           "url":"http://www.wemos.cc/tools/gcc/osx-xtensa-lx106-elf-gb404fb9-2.tar.gz",
           "archiveFileName":"osx-xtensa-lx106-elf-gb404fb9-2.tar.gz",
           "checksum":"SHA-256:0cf150193997bd1355e0f49d3d49711730035257bc1aee1eaaad619e56b9e4e6",
           "size":"35385382"
        },
        {
           "host":"x86_64-pc-linux-gnu",
           "url":"http://www.wemos.cc/tools/gcc/linux64-xtensa-lx106-elf-gb404fb9.tar.gz",
           "archiveFileName":"linux64-xtensa-lx106-elf-gb404fb9.tar.gz",
           "checksum":"SHA-256:46f057fbd8b320889a26167daf325038912096d09940b2a95489db92431473b7",
           "size":"30262903"
        },
        {
           "host":"i686-pc-linux-gnu",
           "url":"http://www.wemos.cc/tools/gcc/linux32-xtensa-lx106-elf.tar.gz",
           "archiveFileName":"linux32-xtensa-lx106-elf.tar.gz",
           "checksum":"SHA-256:b24817819f0078fb05895a640e806e0aca9aa96b47b80d2390ac8e2d9ddc955a",
           "size":"32734156"
        }
      ]
    } ]
  } ]
}
'''
#print "%s" % (sys.argv[1])
gz_filename=sys.argv[1][3:]
#print gz_filename

#ver=gz_filename[:len(gz_filename)-7]
ver=sys.argv[2]
print ver

f = open(sys.argv[1],'rb')
sh = hashlib.sha256()
sh.update(f.read())
sha = sh.hexdigest()
print sha
f.close()

size = os.path.getsize(sys.argv[1])
print size

f = open('package_wemos.cc_index.json', 'w')
str1=text1+ver+text2+gz_filename+text3+gz_filename+text4+sha+text5+bytes(size)+text6
f.write(str1)
f.close()

