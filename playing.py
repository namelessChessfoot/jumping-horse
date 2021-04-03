from PIL import Image
from PIL import ImageGrab
import matplotlib.pyplot as plt
lenth=28
halflenth=14
img=ImageGrab.grab(bbox=(344,475+12,558+7,690+19))#左上右下
pix=img.load()
for i in range(8):
    for j in range(8):
        x=halflenth+i*lenth
        y=halflenth+j*lenth+3
        r,g,b=pix[x,y]
        if r<50:
            print(chr(ord('a')+i),8-j,' val=',r,"black pawn coordinate:",x,y)
        elif r<130:
            print(chr(ord('a')+i),8-j,' val=',r,"blue coordinate:",x,y)
        elif r<240:
            print(chr(ord('a')+i),8-j,' val=',r,"white knight coordinate:",x,y)
        else:
            print(chr(ord('a')+i),8-j,' val=',r,"white coordinate:",x,y)
    print()
plt.figure("ttm")
plt.imshow(img)
plt.show()
