import json

json_string = None

with open("Q42.json") as f:
    json_string = f.read()
try:
    parsed_json = json.loads(json_string)
    print(json.dumps(parsed_json, indent = 3,sort_keys=True))
except Exception as e:
    print(repr(e))

