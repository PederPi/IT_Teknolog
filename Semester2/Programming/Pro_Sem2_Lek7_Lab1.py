import tkinter

class average_calculator:
    def __init__(self):
	    #Create the main window widget:
        self.main_window = tkinter.Tk()
        self.main_window.title("Average Calculater")
        self.main_window.geometry("500x400")

        #Create program frames:
        self.test1_frame = tkinter.Frame(self.main_window)
        self.test2_frame = tkinter.Frame(self.main_window)
        self.test3_frame = tkinter.Frame(self.main_window)
        self.avg_frame = tkinter.Frame(self.main_window)
        self.button_frame = tkinter.Frame(self.main_window)

        #Create program buttons:
        self.calc_button = tkinter.Button(self.button_frame, text = 'Average', command = self.calculateAverage)
        self.quit_button = tkinter.Button(self.button_frame, text = 'Quit', command = self.main_window.destroy)

        #Create program labels:
        self.test1_label = tkinter.Label(self.test1_frame, text = "Enter the score for test 1:")
        self.test2_label = tkinter.Label(self.test2_frame, text = "Enter the score for test 2:")
        self.test3_label = tkinter.Label(self.test3_frame, text = "Enter the score for test 3:")
        self.result_label = tkinter.Label(self.avg_frame, text = "Average:")
        self.value = tkinter.StringVar()
        self.avg_label = tkinter.Label(self.avg_frame, textvariable = self.value)

        #Create program entries:
        self.test1_entry = tkinter.Entry(self.test1_frame, width=10)
        self.test2_entry = tkinter.Entry(self.test2_frame, width=10)
        self.test3_entry = tkinter.Entry(self.test3_frame, width=10)

        # Pack the elements:
        #Pack frames:
        self.test1_frame.pack()
        self.test2_frame.pack()
        self.test3_frame.pack()
        self.avg_frame.pack()
        self.button_frame.pack()

        #Pack test1 frame elements:
        self.test1_label.pack(side = "left")
        self.test1_entry.pack(side = "right")

        #Pack test2 frame elements:
        self.test2_label.pack(side = "left")
        self.test2_entry.pack(side = "right")

        #Pack test3 frame elements:
        self.test3_label.pack(side = "left")
        self.test3_entry.pack(side = "right")

        #Pack avg frame elements:
        self.result_label.pack(side = "left")
        self.avg_label.pack(side = "right")

        #Pack Button frame elements:
        self.calc_button.pack(side = "left")
        self.quit_button.pack(side = "right")    
    
	    #Enter the tkinter main loop.
        tkinter.mainloop()

    #Function for calculating the average of the 3 test scores:
    def calculateAverage(self):
        test1 = float(self.test1_entry.get())
        test2 = float(self.test2_entry.get())
        test3 = float(self.test3_entry.get())
        average = float((test1 + test2 + test3) / 3)
        self.value.set(average)
        return

#Run the program by creating an instance of the object "average_calculator":
calculate_average = average_calculator()