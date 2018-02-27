#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import xml.etree.ElementTree as ET

def rowcoltocoords(element, row, col):
  topleft = element.find('{http://www.opengis.net/wmts/1.0}TopLeftCorner').text
  top, left = tuple([float(x) for x in topleft.split(' ')])
  print(top)
  print(left)

  sd = float(element.find('{http://www.opengis.net/wmts/1.0}ScaleDenominator').text)
  print(sd)

  screenresolution = 0.00028 # 0.28 mm / pixel

  resolution = screenresolution * sd

  print("Resolution: %f units/pixel" % resolution)

def main(argv=None):
  if argv is None:
    argv = sys.argv

  if len(argv) < 5:
    print("Käyttö: %s <capabilities.xml> <TileMatrixIdentifier> <row> <col>" % argv[0])
    print("Esim: ./wmts.py ../../wmts-getcapabilities.xml EPSG:3395_FTA:8 193 109")
    exit()

  row = int(argv[3])
  col = int(argv[4])

  tree = ET.parse(argv[1])
  root = tree.getroot()

  elms = root.findall("./{http://www.opengis.net/wmts/1.0}Contents/{http://www.opengis.net/wmts/1.0}TileMatrixSet/{http://www.opengis.net/wmts/1.0}TileMatrix/[{http://www.opengis.net/ows/1.1}Identifier='%s']" % argv[2])
  for e in elms:
    rowcoltocoords(e, row, col)


if __name__ == "__main__":
  main()
