
game = {'nome': 'Super Mário', 'desenvolvedor': 'Nintendo', 'ano': 1990}
print(game['nome'])

print(game.values())
for value in game.values():
	print(value)

print(game.keys())
for key in game.keys():
	print(key)

print(game.items())
for item in game.items():
	print(item)

for key, value in game.items():
	print('A chave "{}" tem o valor "{}"'.format(key, value))

print("\n", " = =" * 25, "\n")

a = dict(one=1, two=2, three=3)
b = {'one': 1, 'two': 2, 'three': 3}
c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
d = dict([('two', 2), ('one', 1), ('three', 3)])
e = dict({'three': 3, 'one': 1, 'two': 2})
print(a == b == c == d == e)

print("\n", " = =" * 25, "\n")

"""
key = "one"
value = "um"
d[key] = value
key in d
key not in d
del d[key]

iter(d)
Return an iterator over the keys of the dictionary. This is a shortcut for iter(d.keys()).

clear()¶
Remove all items from the dictionary.

copy()¶
Return a shallow copy of the dictionary.

classmethod fromkeys(seq[, value])¶
Create a new dictionary with keys from seq and values set to value.

fromkeys() is a class method that returns a new dictionary. value defaults to None.

get(key[, default])¶
Return the value for key if key is in the dictionary, else default. If default is not given, it defaults to None, so that this method never raises a KeyError.

items()¶
Return a new view of the dictionary’s items ((key, value) pairs). See the documentation of view objects.

keys()¶
Return a new view of the dictionary’s keys. See the documentation of view objects.

pop(key[, default])¶
If key is in the dictionary, remove it and return its value, else return default. If default is not given and key is not in the dictionary, a KeyError is raised.

popitem()¶
Remove and return an arbitrary (key, value) pair from the dictionary.

popitem() is useful to destructively iterate over a dictionary, as often used in set algorithms. If the dictionary is empty, calling popitem() raises a KeyError.

setdefault(key[, default])¶
If key is in the dictionary, return its value. If not, insert key with a value of default and return default. default defaults to None.

update([other])¶
Update the dictionary with the key/value pairs from other, overwriting existing keys. Return None.

update() accepts either another dictionary object or an iterable of key/value pairs (as tuples or other iterables of length two). If keyword arguments are specified, the dictionary is then updated with those key/value pairs: d.update(red=1, blue=2).

values()¶
Return a new view of the dictionary’s values. See the documentation of view objects.

Dictionaries compare equal if and only if they have the same (key, value) pairs. Order comparisons (‘<’, ‘<=’, ‘>=’, ‘>’) raise TypeError.
"""

"""
>>> dishes = {'eggs': 2, 'sausage': 1, 'bacon': 1, 'spam': 500}
>>> keys = dishes.keys()
>>> values = dishes.values()

>>> # iteration
>>> n = 0
>>> for val in values:
...     n += val
>>> print(n)
504

>>> # keys and values are iterated over in the same order
>>> list(keys)
['eggs', 'bacon', 'sausage', 'spam']
>>> list(values)
[2, 1, 1, 500]

>>> # view objects are dynamic and reflect dict changes
>>> del dishes['eggs']
>>> del dishes['sausage']
>>> list(keys)
['spam', 'bacon']

>>> # set operations
>>> keys & {'eggs', 'bacon', 'salad'}
{'bacon'}
>>> keys ^ {'sausage', 'juice'}
{'juice', 'sausage', 'bacon', 'spam'}
"""
