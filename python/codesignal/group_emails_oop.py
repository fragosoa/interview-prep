from collections import defaultdict
from datetime import datetime
from collections import Counter

emails = "Sender Email Address1, Subject1, 09:00; Sender Email Address2, Subject2, 10:00; Sender Email Address1, Subject3, 12:00; Sender Email Address2, Subject5, 10:00"

class Email:
    def __init__(self,sender,timestamp,subject):
        self.sender = sender
        self.timestamp = timestamp
        self.subject = subject
    
    def __repr__(self):
        return f"{self.sender}"
    
    def __eq__(self,other):
        if not isinstance(other,Email):
            return NotImplemented
        return self.sender == other.sender
    
    def __hash__(self):
        return hash(self.sender)
    
    def __lt__(self,other):
        return self.sender < other.sender

class InboxParser:
    @staticmethod
    def preprocess_inbox(inbox):
        emails = inbox.split("; ")
        format = "%H:%M"
        processed_emails = []
        for email in emails:
            sender, subject, timestamp = email.split(", ")
            timestamp = datetime.strptime(timestamp,format)
            email_obj = Email(sender,timestamp,subject)
            processed_emails.append(email_obj)
        
        return processed_emails
        
def organize_inbox(inbox_string):
    processed_emails = InboxParser.preprocess_inbox(inbox_string)
    grouped_emails = defaultdict(int)

    for email in processed_emails:
        grouped_emails[email] += 1

    result = [(sender,count) for sender,count in grouped_emails.items()]

    result.sort(key=lambda x: x[0])
    result.sort(key=lambda x: x[1], reverse=True)

    return result

result = organize_inbox(emails)
print(result)