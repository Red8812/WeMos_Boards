#!/usr/bin/python
#coding:utf-8
import sys
import os
import hashlib

file=sys.argv[1]

f = open(file,'rb')
sh = hashlib.sha256()
sh.update(f.read())
sha = sh.hexdigest()
print sha
f.close()

size = os.path.getsize(file)
print size

f = open("hash256.txt",'w')
f.write(sha+'\r\n')
f.write(str(size))
f.close()