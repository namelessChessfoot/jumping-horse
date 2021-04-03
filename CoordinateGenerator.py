from PIL import Image
from PIL import ImageGrab
import matplotlib.pyplot as plt
while 1:
    img=ImageGrab.grab(bbox=(344,475,558,690))#左上右下
    #img=Image.open('ttm.jpg')
    lenth=27
    halflenth=13
    pix=img.load()
    ans=''
    for i in range(8):
        for j in range(8):
            x=halflenth+i*lenth
            y=halflenth+j*lenth
            r,g,b=pix[x,y]
            if r>230 and r<252:#黑兵或者气球
                #print(r)
                ans=ans+' '+str(i+1)
                ans=ans+' '+str(8-j)
                #print(ans,'黑兵')
    ans=ans+' '+'0'
    print(ans)
    img.save("ttm.jpg")
    z=input("continue:")
