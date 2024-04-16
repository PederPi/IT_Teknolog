mailing = ['jef.saunders@gmail.com', 'bill.peeters@iou.com', 'Maria.Smith@aol.com', 'George.Williams@bkt.com', 'jef.saunders@gmail.com', 'tom.saunders@gmail.com', 'per.saunders@gmail.com', 'dan.rasmussen@gmail.com', 'Maria.Smith@aol.com']

def makeSet(mailList):
    return set([address.lower() for address in mailList])

print(makeSet(mailing))