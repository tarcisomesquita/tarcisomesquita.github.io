#!/usr/bin/bash

# 86400 s = 1 dia
if [ $(($(date +%s) - $(date +%s --date="$(cat last.txt)"))) -lt 86400 ]; then
  echo "Tem menos de um dia deste a última checagem!";
  exit 1
fi

echo '' > diff.txt

for FILE in $(ls old/); do
  NAME=${FILE/%.html/}; # remove .html do final do nome
  
  echo "Baixando https://developer.mozilla.org/en-US/docs/${NAME//\%//}";
  
  wget -q -O - "https://developer.mozilla.org/en-US/docs/${NAME//\%//}" | \
  sed 's/\(<article[^>]*>\)/\n\1\n/; s|\(</article>\)|\n\1\n|;' | sed -n '/<article/,/article>/{p}' > new/${NAME}.html;
  sleep 0.3;
  if diff -q old/$FILE new/$FILE; then rm new/$FILE; fi | sed 's/^Files /diff /; s/ and / /; s/ differ//' >> diff.txt
done

date +'%Y-%m-%d %H:%M:%S %z' > last.txt

for FILE in $(ls new/); do
  echo -e "\n = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n"
  echo $FILE;
  diff old/$FILE new/$FILE;
done
