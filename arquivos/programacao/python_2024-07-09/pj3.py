import json
import pprint

with open('Q42.json', 'r') as f:
    data = f.read()
    json_data = json.loads(data)

pprint.pprint(json_data)
