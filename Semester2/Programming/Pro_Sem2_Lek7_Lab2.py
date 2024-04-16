import tkinter

class temperature_converter:
    def __init__(self):
	    #Create the main window widget:
        self.main_window = tkinter.Tk()
        self.main_window.title("Temperature Converter")
        self.main_window.geometry("500x400")

        #Create program frames:
        self.entry_frame = tkinter.Frame(self.main_window)
        self.result_frame = tkinter.Frame(self.main_window)
        self.button_frame = tkinter.Frame(self.main_window)

        #Create program buttons:
        self.convert_button = tkinter.Button(self.button_frame, text = "Convert", command = self.convert_temperature)
        self.quit_button = tkinter.Button(self.button_frame, text = "Quit", command = self.main_window.destroy)

        #Create program labels:
        self.entry_label = tkinter.Label(self.entry_frame, text = "Enter the celcius temperature to convert:")
        self.result_label = tkinter.Label(self.result_frame, text = "Temperature in fahrenheit:")
        self.value = tkinter.StringVar()
        self.convert_label = tkinter.Label(self.result_frame, textvariable = self.value)

        #Create program entries:
        self.temperature_entry = tkinter.Entry(self.entry_frame, width=10)

        # Pack the elements:
        #Pack frames:
        self.entry_frame.pack()
        self.result_frame.pack()
        self.button_frame.pack()

        #Pack entry frame elements:
        self.entry_label.pack(side = "left")
        self.temperature_entry.pack(side = "right")

        #Pack result frame elements:
        self.result_label.pack(side = "left")
        self.convert_label.pack(side = "right")

        #Pack button frame elements:
        self.convert_button.pack(side = "left")
        self.quit_button.pack(side = "right")

        #Enter the tkinter main loop.
        tkinter.mainloop()

        #Function for calculating the average of the 3 test scores:
    def convert_temperature(self):
        celcius_temperature = float(self.temperature_entry.get())
        fahrenheit_temperature = float((9 / 5) * celcius_temperature + 32)
        self.value.set(fahrenheit_temperature)
        return

#Run the program by creating an instance of the object "average_calculator":
convert_temperature = temperature_converter()