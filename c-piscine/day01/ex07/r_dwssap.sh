cat /etc/passwd | sed -e 's/:.*//g;s/#.*//g;/^$/d;n;d' | rev | sort -r | sed -n $FT_LINE1,$FT_LINE2\p | xargs | sed 's/ /, /g;s/$/./'
