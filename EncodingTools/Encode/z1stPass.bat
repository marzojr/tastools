start /wait x264 "mixed.avi" --deldup 40:-1:0:0:-1 --pass 1 --bitrate 165 --keyint 300 --ref 15 --no-fast-pskip --bframes 6 --b-adapt 2 --b-pyramid --weightb --direct auto --subme 10 --trellis 2 --partitions all --me umh --merange 64 --threads 1 --8x8dct --no-dct-decimate --output "encoded.mp4" 