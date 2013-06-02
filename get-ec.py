import email, getpass, imaplib, os

detach_dir = './ec-discuss'   #directory where to save attachments (default: current)
user = raw_input("your email (without the @...): ")
pwd = raw_input("password: ")
filename = raw_input("output file name: ")
fetch = raw_input("number of emails to fetch, 0 for all: ")

# connecting to the gmail imap server
m = imaplib.IMAP4_SSL("imap.gmail.com")
m.login(user+str("@gmail.com"),pwd)
m.select("INBOX") # here you a can choose a mail box like INBOX instead
# use m.list() to get all the mailboxes

resp, items = m.search(None, '(TO "ec-discuss@mit.edu")') # you could filter using the IMAP rules here (check http://www.example-code.com/csharp/imap-search-critera.asp)
items = items[0].split() # getting the mails id

f=open(filename,'w')

if (fetch>0):
    sublist=items[0:int(fetch)]
else:
    sublist=items

for emailid in sublist:
    resp, data = m.fetch(emailid, "(RFC822)") # fetching the mail, "`(RFC822)`" means "get the whole stuff", but you can ask for headers only, etc
    email_body = data[0][1] # getting the mail content
    mail = email.message_from_string(email_body) # parsing the mail content to get a mail object

    print "["+mail["From"]+"] :" + mail["Subject"]

    # we use walk to create a generator so we can iterate on the parts and forget about the recursive headach
    for part in mail.walk():
        if part.get_content_type() == 'text/plain':
            body = part.get_payload(decode=True)
            f.write(body)
        else:
            continue
f.close()
