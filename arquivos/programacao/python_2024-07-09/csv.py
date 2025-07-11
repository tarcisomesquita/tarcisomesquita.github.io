#!/usr/bin/python3

import csv
import array

with open('base.csv', 'rt', newline='', encoding='utf-8') as base_r:
    #teste = base_r.read(32);
    #print(teste)

    #base_r.seek(23);
    #teste = base_r.read(32);
    #print(teste)
    
    reader = csv.reader(base_r, delimiter=';', quotechar='"', quoting=csv.QUOTE_NONE, lineterminator='\n', escapechar='\\')
    buscar_matricula = "182988"
    for row in reader:
        if row[0] == buscar_matricula:
            if row[1] == "OI":
                data_inicio = row[3]
                print("data_inicio = " + data_inicio)
            print(row)
    #for row in reader: print(';'.join(row)) # print file
    #base_r.seek(0)
    #print(reader.line_num)
    #reader.__next__()
    #print(reader.line_num)
    #print(row)

tmp_list = []
tmp_list.append('007')
tmp_list.append('162439')
tmp_list.append('"2-1"')
tmp_list.append('5,0')
tmp_list.append('05/02/19 11:50')
#print(tmp_list)
#print(';'.join(tmp_list))

with open('base.csv', 'at', newline='') as base_a:
    base_writer = csv.writer(base_a,  delimiter=';', quotechar='"', quoting=csv.QUOTE_NONE, lineterminator='\n', escapechar='\\')
    
    #base_writer.writerow(tmp_list)
    #base_writer.writerow(['007', '162439', '2-1', '5,0', '05/02/19 11:50'])


