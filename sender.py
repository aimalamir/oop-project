from email import message 
import smtplib
import ssl   #Importing the libraries smtplib(Starts the email handling) and ssl(For your connection with the server)

port = 465  # For SSL
smtp_server = "smtp.gmail.com"
sender_email = "kamkaj1200@gmail.com"  # Enter your address
print("Enter you email address for password reset")
receiver_email = input("")  # Enter receiver address
password = "Kamkaj123"
text="your opt is 2000"
message =  text

context = ssl.create_default_context() #creates the connection and handles the cleanup afterward
with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
    server.login(sender_email, password) #Logs into your account using the email and password you gave
    server.sendmail(sender_email, receiver_email, message) #Sends from your email the message you've created t the email you've written out 