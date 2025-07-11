from breezypythongui import EasyFrame

class TextFieldDemo(EasyFrame):
  """Converts an input string to uppercase and displays the result."""
  
  def __init__(self):
    """Sets up the window and widgets."""
    EasyFrame.__init__(self, title = "Text Field Demo")
    
    # Label and field for the input
    self.addLabel(text = "Input", row = 0, column = 0)
    self.inputField = self.addTextField(text = "", row = 0, column = 1)
    
    # Label and field for the output
    self.addLabel(text = "Output", row = 1, column = 0)
    self.outputField = self.addTextField(text = "", row = 1,  column = 1, state = "readonly")
    
    # The command button
    self.addButton(text = "Convert", row = 2, column = 0, columnspan = 2, command = self.convert)
  
  # The event handling method for the button
  def convert(self):
    """Inputs the string, converts it to uppercase, and outputs the result."""
    text = self.inputField.getText()
    result = text.upper()
    self.outputField.setText(result)


  def main():
    """Instantiates and pops up the window."""
    TextFieldDemo().mainloop()

if __name__ == "__main__":
  main()


"""
 = = =
"""

class NumberFieldDemo(EasyFrame):
  """Computes and displays the square root of an input number."""
  def __init__(self):
    """Sets up the window and widgets."""
    EasyFrame.__init__(self, title = "Number Field Demo")
    
    # Label and field for the input
    self.addLabel(text = "An integer", row = 0, column = 0)
    self.inputField = self.addIntegerField(value = 0, row = 0, column = 1, width = 10)
    
    # Label and field for the output
    self.addLabel(text = "Square root", row = 1, column = 0)
    self.outputField = self.addFloatField(value = 0.0, row = 1, column = 1, width = 8, precision = 2, state = "readonly")
    
    # The command button
    self.addButton(text = "Compute", row = 2, column = 0, columnspan = 2, command = self.computeSqrt)
    
  # The event handling method for the button
  def computeSqrt(self):
    """Inputs the integer, computes the square root, and outputs the result."""
    number = self.inputField.getNumber()
    result = math.sqrt(number)
    self.outputField.setNumber(result)


"""
 = = =
"""

# The event handling method for the button
def computeSqrt(self):
  """Inputs the integer, computes the square root,
  and outputs the result. Handles input errors
  by displaying a message box."""
  try:
    number = self.inputField.getNumber()
    result = math.sqrt(number)
    self.outputField.setNumber(result)
  except ValueError:
    self.messageBox(title = "ERROR", message = "Input must be an integer >= 0")


# self.label["text"] = my_str
# self.nextButton["state"] = "disabled"
# self.nextButton["state"] = "normal"
# dataPanel = self.addPanel(row = 0, column = 0, background = "gray")
# dataPanel.addTextField(text = "Text1", row = 0, column = 1)
# self.outputArea = self.addTextArea("", row = 4, column = 0, columnspan = 2, width = 50, height = 15)
# self.outputArea.setText(result)


