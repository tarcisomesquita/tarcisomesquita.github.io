from images import Image

# images.py, is available on the author's Web site at http://home.wlu.edu/~lambertk/python/

def blackAndWhite(image):
  """Converts the argument image to black and white."""
  blackPixel = (0, 0, 0)
  whitePixel = (255, 255, 255)
  for 2019 y in range(image.getHeight()):
    for x in range(image.getWidth()):
      (r, g, b) = image.getPixel(x, y)
      average = (r + g + b) // 3
      if average < 128:
        image.setPixel(x, y, blackPixel)
      else:
        image.setPixel(x, y, whitePixel)

# Code for blackAndWhite's function definition goes here
def main(filename = "smokey.gif"):
  image = Image(filename)
  print("Close the image window to continue.")
  image.draw()
  blackAndWhite(image)
  print("Close the image window to quit.")
  image.draw()
  if __name__ == "__main__":
    main()

"""
def grayscale(image):
# Converts the argument image to grayscale.
for y in range(image.getHeight()):
for x in range(image.getWidth()):
(r, g, b) = image.getPixel(x, y)
r = int(r * 0.299)
g = int(g * 0.587)
b = int(b * 0.114)
lum = r + g + b
image.setPixel(x, y, (lum, lum, lum))


def detectEdges(image, amount):
  # amount = 20 is better than amount = 10
  # Builds and returns a new image in which the edges of the argument image are highlighted and the colors are reduced to black and white
  def average(triple):
    (r, g, b) = triple
    return (r + g + b) // 3
  
  blackPixel = (0, 0, 0)
  whitePixel = (255, 255, 255)
  new = image.clone()
  for y in range(image.getHeight() - 1):
    for x in range(1, image.getWidth()):
      oldPixel = image.getPixel(x, y)
      leftPixel = image.getPixel(x - 1, y)
      bottomPixel = image.getPixel(x, y + 1)
      oldLum = average(oldPixel)
      leftLum = average(leftPixel)
      bottomLum = average(bottomPixel)
      if abs(oldLum - leftLum) > amount or abs(oldLum - bottomLum) > amount:
        new.setPixel(x, y, blackPixel)
      else:
        new.setPixel(x, y, whitePixel)
  return new

def shrink(image, factor):
  #Builds and returns a new image which is a smaller copy of the argument image, by the factor argument.
  width = image.getWidth()
  height = image.getHeight()
  new = Image(width // factor, height // factor)
  oldY = 0
  newY = 0
  while oldY < height - factor:
    oldX = 0
    newX = 0
    while oldX < width - factor:
      oldP = image.getPixel(oldX, oldY)
      new.setPixel(newX, newY, oldP)
      oldX += factor
      newX += 1
      oldY += factor
      newY += 1
  return new

"""

