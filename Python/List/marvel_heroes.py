# List of my favourite marvel heroes.

heroes = ['Spider Man', 'Thor', 'Hulk', 'Iron Man', 'Captain America']

# 1) Length of the list.
print("Length of the list is: ", len(heroes))

# 2) Adding another hero, 'Black Panther'.
heroes.append('Black Panther')
print("New list of heroes: ", heroes)

# 3) Placing 'Black Panther' after 'Hulk'.
heroes.remove('Black Panther')
heroes.insert(3, 'Black Panther')
print("After placing: ", heroes)

# 4) Removing 'Thor' and 'Hulk' from the list and adding 'Dr. Stranger'.
heroes[1:3] = ['Dr. Stranger']
print("New list after removing 'Thor' and 'Hulk' and adding 'Dr. Stranger': ", heroes)

# Sorting the heroes in alphabetical order.
heroes.sort()
print(f"After sorting the heroes names in aphabetical order: {heroes}")
