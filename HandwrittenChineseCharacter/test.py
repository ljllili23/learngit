#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os, sys

path="/var/www/html"
dirs = os.listdir(path)

for file in dirs:
print file