import tkinter
import tkinter.messagebox

class rate_calculator:
    def __init__(self):
	    #Create the main window widget:
        self.main_window = tkinter.Tk()
        self.main_window.title("Rate Calculator")
        self.main_window.geometry("500x400")

        #Create program frames:
        self.rate_headline_frame = tkinter.Frame(self.main_window)
        self.rate1_frame = tkinter.Frame(self.main_window)
        self.rate2_frame = tkinter.Frame(self.main_window)
        self.rate3_frame = tkinter.Frame(self.main_window)
        self.blank_frame = tkinter.Frame(self.main_window)
        self.radio_button_frame = tkinter.Frame(self.main_window)
        self.entry_frame = tkinter.Frame(self.main_window)
        self.button_frame = tkinter.Frame(self.main_window)

        # Create an IntVar object to use with the Radiobuttons.
        self.radio_var = tkinter.IntVar()
        # Set the intVar object to 1.
        self.radio_var.set(0)

        # Create the Radiobutton:
        self.rb1 = tkinter.Radiobutton(self.radio_button_frame, text = "Daytime", variable = self.radio_var, value = 1)
        self.rb2 = tkinter.Radiobutton(self.radio_button_frame, text = "Evening", variable = self.radio_var, value = 2)
        self.rb3 = tkinter.Radiobutton(self.radio_button_frame, text = "Off-Peak", variable = self.radio_var, value = 3)

        #Create program labels:
        self.rate_headline_label = tkinter.Label(self.rate1_frame, text = "Rate Category                          Rate per Minute")
        self.rate1_label = tkinter.Label(self.rate1_frame, text = "Daytime (6:00 a.m. through 5:59 p.m)    $0.07")
        self.rate2_label = tkinter.Label(self.rate2_frame, text = "Evening (6:00 p.m. through 11:59 p.m)    $0.12")
        self.rate3_label = tkinter.Label(self.rate3_frame, text = "Daytime (midgning through 5:59 a.m)    $0.05")
        self.blank_label = tkinter.Label(self.blank_frame, text = " ")
        self.minutes_label = tkinter.Label(self.entry_frame, text = "Minutes:")

        #Create program entries:
        self.minutes_entry = tkinter.Entry(self.entry_frame, width=10)

        #Create buttons:
        self.ok_button = tkinter.Button(self.button_frame, text = "OK", command = self.calculate_cost)
        self.quit_button = tkinter.Button(self.button_frame, text = "Quit", command = self.main_window.destroy)

        # Pack the elements:
        #Pack frames:
        self.rate_headline_frame.pack()
        self.rate1_frame.pack()
        self.rate2_frame.pack()
        self.rate3_frame.pack()
        self.blank_frame.pack()
        self.radio_button_frame.pack()
        self.entry_frame.pack()
        self.button_frame.pack()

        #Pack rate_headline frame elements:
        self.rate_headline_label.pack()

        #Pack rate1 frame elements:
        self.rate1_label.pack()

        #Pack rate2 frame elements:
        self.rate2_label.pack()

        #Pack rate3 frame elements:
        self.rate3_label.pack()

        #Pack blank frame elements:
        self.blank_label.pack()

        #Pack radio button frame elements:
        self.rb1.pack()
        self.rb2.pack()
        self.rb3.pack()

        #Pack entry frame elements:
        self.minutes_label.pack(side = "left")
        self.minutes_entry.pack(side = "right")

        #Pack button frame elements:
        self.ok_button.pack(side='left')
        self.quit_button.pack(side='left')

        # Start the tkinter main loop.
        tkinter.mainloop()

    #Function for calculating cost when the OK button is pressed:
    def calculate_cost(self):
        radio_button_choice = self.radio_var.get()
        if radio_button_choice == 1:
            cost = 0.07 * float(self.minutes_entry.get())
            tkinter.messagebox.showinfo(message = "Cost: $" + set(cost))
        elif radio_button_choice == 2:
            cost = 0.12 * float(self.minutes_entry.get())
            tkinter.messagebox.showinfo(message = "Cost: $" + str(cost))
        elif radio_button_choice == 3:
            cost = 0.05 * float(self.minutes_entry.get())
            tkinter.messagebox.showinfo(message = "Cost: $" + str(cost))
        else:
            tkinter.messagebox.showinfo(message = "Please select rate category")
        return
        
#Run the program by creating an instance of the object "rate_calculator":
calculate_rate = rate_calculator()
