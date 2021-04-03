from PIL import ImageGrab
import matplotlib.pyplot as plt
img=ImageGrab.grab(bbox=(344,475,558,690))#左上右下
img.save("ttm.jpg")
#plt.imshow(img)
#plt.show()
