from collections import Counter 

class InboxParser:
    @staticmethod
    def parse(inbox):
        entries = inbox.split("; ")
        for entry in entries:
            sender, subject, timestamp = entry.split(", ")
            yield sender,subject,timestamp

def organize_inbox(inbox_string):
    senders = []

    for sender,_,_ in InboxParser.parse(inbox=inbox_string):
        senders.append(sender)

    counts= Counter(senders)
    result = sorted(counts.items(),key=lambda x: (-x[1], x[0]))
    return result