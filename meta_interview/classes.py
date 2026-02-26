class Container:
    def __init__(self):
        self.data = []
    def add(self,x):
        self.data.append(x)
    def __repr__(self):
        return f"{self.data}"
    
data = Container()
data.add(1)
data.add(2)

print(data)

# Interfaces implicitas

class Store:
    def add(self,x): pass
    def get_avg(self): pass

class LinearStore:
    def __init__(self):
        self.data = []
    def add(self, x):
        self.data.append(x)
    def get_avg(self):
        return sum(self.data)/len(self.data)
    
class SetStore:
    def __init__(self):
        self.data = set()
    def add(self, x):
        self.data.add(x)
    def get_avg(self):
        return sum(self.data)/len(self.data)
    

def process_store(store: Store):
    store.add(1)
    store.add(2)
    store.add(1)
    print(store.get_avg())


#mystore = LinearStore()
#mystore.add(1)
#mystore.add(2)
#mystore.add(3)

#print(mystore.get_avg())

linear_store = LinearStore()
set_store = SetStore()

process_store(linear_store)
print("------")
process_store(set_store)
