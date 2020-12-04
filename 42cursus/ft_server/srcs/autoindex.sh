if grep -q "autoindex on;" /etc/nginx/sites-enabled/default
then
	sed -i 's/autoindex on;/autoindex off;/' /etc/nginx/sites-enabled/default
	echo "autoindex OFF"
else
	sed -i 's/autoindex off;/autoindex on;/' /etc/nginx/sites-enabled/default
	echo "autoindex ON"
fi
service nginx restart
