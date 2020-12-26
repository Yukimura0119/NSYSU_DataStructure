import tkinter as tk
import subprocess

window = tk.Tk()
window.title("HuffZip")
window.geometry("400x200")

Choose = tk.Label(window, bg='#D3A4FF',
                  text='Choose Zip or Unzip', font=('Arial', 14))
Choose.place(x=100, y=10)
var = tk.StringVar()
var.set('Zip')
B1 = tk.Radiobutton(window, text='Zip', variable=var,
                    value='Zip', font=('Arial', 12))
B1.place(x=150, y=40)
B2 = tk.Radiobutton(window, text='Unzip', variable=var,
                    value='Unzip', font=('Arial', 12))
B2.place(x=150, y=65)

tk.Label(window, text='InputFile Site :',
         font=('Arial', 14)).place(x=19, y=100)
tk.Label(window, text='OutputFile Site:',
         font=('Arial', 14)).place(x=10, y=130)

AimSite = tk.StringVar()
EnterAimSite = tk.Entry(window, textvariable=AimSite, font=('Arial', 14))
EnterAimSite.place(x=150, y=100)
ResultName = tk.StringVar()
EnterResultName = tk.Entry(window, textvariable=ResultName, font=('Arial', 14))
EnterResultName.place(x=150, y=130)


def Run():
    if var.get() == 'Zip':
        subprocess.run(["hw8-b093040044.exe", "-z",
                        AimSite.get(), ResultName.get()])
    else:
        subprocess.run(["hw8-b093040044.exe", "-u",
                        AimSite.get(), ResultName.get()])


Start = tk.Button(window, width=15, text='Run!', command=Run)
Start.place(x=150, y=160)

window.mainloop()
