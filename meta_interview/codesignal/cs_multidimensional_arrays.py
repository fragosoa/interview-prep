apartmentBuilding = [
    ["Apt 101", "Apt 102", "Apt 103"], 
    ["Apt 201", "Apt 202", "Apt 203"], 
    ["Apt 301", "Apt 302", "Apt 303"]
]

# TODO: Update "Apt 202" to "Renovated Apt 202" in `apartmentBuilding`
apartmentBuilding[1][1] = "Renovated Apt 202"
# Print all the apartments after the renovation update
for floor in apartmentBuilding:
    for unit in floor:
        print(unit + ", ", end='')
    print()  # Move to the next floor