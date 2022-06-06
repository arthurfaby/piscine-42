cat /etc/passwd | sed '/#/d'  | sed -n 2~2p | cut -d ':' -f 1 | rev | sort -r | sed "$FT_LINE1,$FT_LINE2!d" | tr '\n' ',' | sed 's/,/, /g' | rev | cut -c3- | rev | tr '\n' '.'
